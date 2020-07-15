//
//  MFDCamera.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/10.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDCamera_h
#define MFDCamera_h

#import "MFDCameraSettings.h"

@protocol MFDCameraDelegate;
@class MFDVideoDevice;
@class MFDEffect;
@class MFDVideo;
@class MFDVideoSampleInfo;

/**
 `MFDCamera`是拍摄业务的总接口，主要用于提供预览、录制、拍照相关功能。
 
 相关接口按照使用顺序，功能简介如下：
 
 - **拍摄配置**  `MFDCameraSettings`
 
 指定初始化时使用的拍摄模式、前/后置、拍摄方向、画幅、前/后置摄像头格式、录制配置等
 
 - **摄像头格式**  `MFDCameraFormat`
 
 从支持的所有采集格式中选择需要的采集格式
 
 - **录制配置**  `MFDRecordSettings`
 
 指定录制文件存放目录、文件格式、视频编码格式、视频分辨率、视频码率、视频关键帧间隔等

 - **拍摄回调**  `MFDCameraDelegate`
 
 包括预览期间和录制期间的回调
 
 - **摄像头设备**  `MFDVideoDevice`
 
 用于更新当前使用的摄像头的参数，如曝光对焦等
 
 - **特效**  `MFDEffect`
 
 用于进行视频特效相关操作
 */
@interface MFDCamera : NSObject

/**
 在 `initWithSettings:` 后立即设置
 */
@property (nonatomic, weak) id<MFDCameraDelegate> delegate;

/**
 特效操作类
 */
@property (nonatomic, strong, readonly) MFDEffect *effect;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 初始化失败返回nil
 */
- (instancetype)initWithSettings:(MFDCameraSettings *)settings;

#pragma mark - 画幅

/**
 当前画幅
 */
@property (nonatomic, assign, readonly) MFDAspectRatio aspectRatio;

/**
 切换到指定画幅
 
 @note 会同时影响预览和录制的图像
 */
- (void)switchAspectRatio:(MFDAspectRatio)aspectRatio;

#pragma mark - 模式

/**
 当前拍摄模式
*/
@property (nonatomic, assign, readonly) MFDCameraMode mode;

/**
 切换到指定拍摄模式，切换成功返回YES，失败返回NO
*/
- (BOOL)switchMode:(MFDCameraMode)mode;

#pragma mark - 前后置

/**
 主摄像头设备，通过此实例进行摄像头参数设置
 
 @note 在 `cameraDidStartPreview` 之前获取将返回nil
*/
@property (nonatomic, strong, readonly) MFDVideoDevice *device;

/**
 切换主摄像头（前后置）
 
 @note 需在 `cameraDidStartPreview` 回调后设置
*/
- (void)switchCamera;

#pragma mark - 预览

/**
 设置预览用的view，SDK将添加子view进行预览
 */
- (void)setPreview:(UIView *)preview;

/**
 开始预览，与 `stopPreview` 搭配使用
 
 @note 开启摄像头
 */
- (void)startPreview;

/**
 停止预览，与 `startPreview` 搭配使用
 
 @note 关闭摄像头
 */
- (void)stopPreview;

/**
 恢复预览，与 `pausePreview` 搭配使用
 
 @note 恢复摄像头的采集，需要在 `cameraDidStartPreview` 后才生效
 */
- (void)resumePreview;

/**
 暂停预览，与 `resumePreview` 搭配使用
 
 @note 未关闭摄像头，仅暂停摄像头的采集。需要在 `cameraDidStartPreview` 后才生效
 */
- (void)pausePreview;

#pragma mark - 录制

/**
 是否正在录制
 */
@property (nonatomic, assign, readonly) BOOL isRecording;

/**
 开始录制，相关回调见 `MFDCameraDelegate`
 */
- (void)startRecord;

/**
 停止录制，相关回调见 `MFDCameraDelegate`
 */
- (void)stopRecord;

/**
 是否录入音频，默认YES
 */
@property (nonatomic, assign, getter=shouldRecordAudio) BOOL recordAudio;

/**
 录制速度模式
 */
typedef NS_ENUM(NSInteger, MFDSpeedMode) {
    MFDSpeedMode_Default = 0,
    MFDSpeedMode_SlowX2 = 1,
    MFDSpeedMode_SlowX3 = 2,
    MFDSpeedMode_SlowX4 = 3,
    MFDSpeedMode_FastX2 = 4,
    MFDSpeedMode_FastX3 = 5,
    MFDSpeedMode_FastX4 = 6,
};

/**
 录制速度模式，影响录制视频的播放速率，默认 `MFDSpeedMode_Default`
 */
@property (nonatomic, assign) MFDSpeedMode speedMode;

/**
 是否在开始录制后回调首帧图像，若为YES则有 `cameraDidRecord:firstFrame:` 回调
 
 @note 该值每次录制完会重置为NO，如需连续多次录制均回调需要在每次 `startRecord` 前设置
 */
@property (nonatomic, assign, getter=isFirstFrameCallBackEnabled) BOOL firstFrameCallBackEnabled;

/**
 是否在开始录制后回调尾帧图像，若为YES则有 `cameraDidRecord:lastFrame:` 回调
 
 @note 该值每次录制完会重置为NO，如需连续多次录制均回调需要在每次 `startRecord` 前设置
 */
@property (nonatomic, assign, getter=isLastFrameCallBackEnabled) BOOL lastFrameCallBackEnabled;

#pragma mark - 拍照

/**
 截帧，图像分辨率等于预览分辨率，速度较快，对照片画质要求不高时优先使用
 
 预览分辨率是用于初始化的MFDCameraSettings.*CameraFormat.previewSize
 */
- (void)captureFrame:(void (^)(UIImage *image))block;

/**
 拍照，图像分辨率等于拍照分辨率，速度较慢，用于获取超清照片
 
 拍照分辨率是用于初始化的MFDCameraSettings.*CameraFormat.photoSize
 
 @note 仅 `MFDCameraMode_Default` 支持此功能
 */
- (void)capturePhoto:(void (^)(UIImage *image))block;

@end

#pragma mark -

/**
 拍摄回调
 */
@protocol MFDCameraDelegate <NSObject>

@optional

/**
 调用 `startPreview` 后，预览开始后回调
 */
- (void)cameraDidStartPreview;

/**
 调用 `startPreview` 后，预览出错时回调
 */
- (void)cameraDidFailPreview:(NSError *)error;

/**
 对视频帧进行特效处理前的回调
 
 有一些特效渲染前需要业务侧提供特定数据，sdk通过info告知业务侧需要什么数据，然后业务侧通过camera.effect的 `setExtFrameData:` 方法传入该帧渲染需要的特定数据，也可以在此回调进行一些自定义的帧相关的业务逻辑。
 
 详细用法见 `MFDVideoSampleInfo` 和 `MFDEffect` 的 `setExtFrameData:` 注释。
 
 @note 此回调在渲染队列调用，请不要有耗时操作。

 @param info 特效处理的一些信息
 */
- (void)cameraWillProcessVideoSample:(MFDVideoSampleInfo *)info;

/**
 录制开始时回调
 */
- (void)cameraDidStartRecord;

/**
 录制时长回调，时长为当前录制视频的写入时长，单位：秒
 */
- (void)cameraDidRecordTime:(CGFloat)recordTime;

/**
 当前录制首帧回调，当 `firstFrameCallBackEnabled` 为YES才会触发
 */
- (void)cameraDidRecord:(NSString *)filePath firstFrame:(UIImage *)firstFrame;

/**
 当前录制尾帧回调，当 `lastFrameCallBackEnabled` 为YES才会触发
 */
- (void)cameraDidRecord:(NSString *)filePath lastFrame:(UIImage *)lastFrame;

/**
 当前录制即将完成时回调，recordTime为录制时长，单位：秒。
 
 @note 此时文件仍在写入，请勿操作文件。此回调只用于提前拿文件时长
 */
- (void)cameraWillStopRecord:(NSString *)filePath recordTime:(CGFloat)recordTime;

/**
 当前录制完成时回调，文件已写完可以进行操作
 */
- (void)cameraDidStopRecord:(MFDVideo *)video;

/**
 当前录制失败时回调
 
 @note 此时应丢弃该录制的相关数据
 */
- (void)cameraDidFailRecord:(NSString *)filePath error:(NSError *)error;

@end

#endif /* MFDCamera_h */
