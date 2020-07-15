//
//  MFDCameraSettings.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/30.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDCameraSettings_h
#define MFDCameraSettings_h

@class MFDCameraFormat;
@class MFDRecordSettings;

/**
 拍摄模式
 
 - `MFDCameraMode_Default` 普通拍摄
 - `MFDCameraMode_AR` AR拍摄，需要iPhone6s及以上，且iOS11.0及以上
 - `MFDCameraMode_Dual` 前后双摄，需要iPhoneXS及以上，且iOS13.0及以上
 */
typedef NS_ENUM(NSInteger, MFDCameraMode) {
    MFDCameraMode_Default = 0,
    MFDCameraMode_AR = 1,
    MFDCameraMode_Dual = 2,
};

/**
 画幅（宽 / 高）
 
 - `MFDAspectRatio_Default` 原始比例
 - `MFDAspectRatio_9_16` 9:16，一般用于竖屏拍摄
 - `MFDAspectRatio_3_4` 3:4，一般用于竖屏拍摄
 - `MFDAspectRatio_16_9` 16:9，一般用于横屏拍摄
 - `MFDAspectRatio_4_3` 4:3，一般用于横屏拍摄
 - `MFDAspectRatio_1_1` 1:1
 */
typedef NS_ENUM(NSInteger, MFDAspectRatio) {
    MFDAspectRatio_Default = 0,
    MFDAspectRatio_9_16 = 1,
    MFDAspectRatio_3_4 = 2,
    MFDAspectRatio_16_9 = 3,
    MFDAspectRatio_4_3 = 4,
    MFDAspectRatio_1_1 = 5,
};

/**
 拍摄配置。
 
 包括拍摄模式、前/后置、拍摄方向、画幅、前/后置摄像头格式、录制配置。
 
 此配置仅用于 `MFDCamera` 的初始化，后续可通过 `MFDCamera` 相关接口进行更新：
 
 - 采集模式： `switchMode:`
 - 前/后置： `switchCamera`
 - 拍摄方向：初始化后不可更改
 - 画幅： `switchAspectRatio:`
 - 前/后置摄像头格式： 初始化后不可更改
 - 录制配置： 初始化后不可更改
 */
@interface MFDCameraSettings : NSObject

/**
 拍摄模式，默认 `MFDCameraMode_Default`
 
 @note 后续可通过 `MFDCamera` 的 `switchMode:` 方法进行切换
 */
@property (nonatomic, assign) MFDCameraMode mode;

/**
 前/后置，默认 `AVCaptureDevicePositionFront`
 
 @note 后续可通过 `MFDCamera` 的 `switchCamera` 方法进行切换
 */
@property (nonatomic, assign) AVCaptureDevicePosition cameraPosition;

/**
 拍摄方向，默认 `AVCaptureVideoOrientationPortrait`
 
 - `AVCaptureVideoOrientationPortrait` home键朝下时采集的图像为正向（竖屏拍摄）
 - `AVCaptureVideoOrientationPortraitUpsideDown` home键朝上时采集的图像为正向（竖屏拍摄）
 - `AVCaptureVideoOrientationLandscapeRight` home键朝右时采集的图像为正向（横屏拍摄）
 - `AVCaptureVideoOrientationLandscapeLeft` home键朝下时采集的图像为正向（横屏拍摄）
 */
@property (nonatomic, assign) AVCaptureVideoOrientation captureOrientation;

/**
 画幅，默认 `MFDAspectRatio_Default`
 
 @note 后续可通过 `MFDCamera` 的 `switchAspectRatio:` 方法进行切换
 */
@property (nonatomic, assign) MFDAspectRatio aspectRatio;

/**
 前置摄像头格式，将根据机型提供最佳默认配置
 
 @note 也可通过 `MFDCameraFormat` 的 `supportedFormatsForPosition:` 选择非默认配置。`MFDCamera` 初始化后无法更改
 */
@property (nonatomic, strong) MFDCameraFormat *frontCameraFormat;

/**
 后置摄像头格式，将根据机型提供最佳默认配置
 
 @note 也可通过 `MFDCameraFormat` 的 `supportedFormatsForPosition:` 选择非默认配置。`MFDCamera` 初始化后无法更改
 */
@property (nonatomic, strong) MFDCameraFormat *backCameraFormat;

/**
 是否采集音频，默认NO
 
 @note 如果不需要录音则设置为YES，此时则不需要申请麦克风权限
 */
@property (nonatomic, assign, getter=isMute) BOOL mute;

/**
 录制配置
 
 @note `MFDCamera` 初始化后无法更改
 */
@property (nonatomic, strong, readonly) MFDRecordSettings *recordSettings;

@end

#endif /* MFDCameraSettings_h */
