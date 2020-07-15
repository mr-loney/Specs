//
//  MFDTranscoder.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/10.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDTranscoder_h
#define MFDTranscoder_h

@class MFDVideoSampleInfo;
@class MFDAsset;
@class MFDCodecSettings;
@class MFDTranscoderSettings;
@class MFDEffect;

@protocol MFDTranscoderDelegate <NSObject>

@optional

/**
 对视频帧进行特效处理前的回调
 
 有一些特效渲染前需要业务侧提供特定数据，sdk通过info告知业务侧需要什么数据，然后业务侧通过transcoder.effect的 `setExtFrameData:` 方法传入该帧渲染需要的特定数据，也可以在此回调进行一些自定义的帧相关的业务逻辑。
 
 详细用法见 `MFDVideoSampleInfo` 和 `MFDEffect` 的 `setExtFrameData:` 注释。
 
 通常需要同步编辑的 `videoPlayerWillProcessVideoSample:` 里的逻辑。
 
 @note 此回调在渲染队列调用，请不要有耗时操作。
 
 @param info 特效处理的一些信息
 */
- (void)transcoderWillProcessVideoSample:(MFDVideoSampleInfo *)info;

/**
 进度回调

 @param progress 进度，0.0-1.0
 */
- (void)transcoderDidProgress:(CGFloat)progress;

/**
 失败回调

 @param error 错误类型
 */
- (void)transcoderDidFail:(NSError *)error;

/**
 完成回调

 @param outputPath 输出文件路径，用于判断是哪一次转码完成了
 */
- (void)transcoderDidComplete:(NSString *)outputPath;

/**
 取消回调

 @param outputPath 输出文件路径，用于判断是取消了哪一次转码
 */
- (void)transcoderDidCancel:(NSString *)outputPath;

@end

#pragma mark -

/**
 视频转码类
 */
@interface MFDTranscoder : NSObject

/**
 在 `transcode` 之前设置
 */
@property (nonatomic, weak) id<MFDTranscoderDelegate> delegate;

/**
 特效操作类
 */
@property (nonatomic, strong, readonly) MFDEffect *effect;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithSettings:(MFDTranscoderSettings *)settings;

/**
 开始转码
 
 @note 异步操作，转码过程会有相应回调事件
 */
- (void)transcode;

/**
 取消转码
 
 @note 异步操作，取消后会有取消回调
 */
- (void)cancel;

@end

#pragma mark -

/**
 转码配置类
 */
@interface MFDTranscoderSettings : NSObject

/**
 用于转码的源视频资源
 */
@property (nonatomic, strong, readonly) MFDAsset *asset;

/**
 输出路径
 
 @note 必须设置，且必须为mp4的路径
 */
@property (nonatomic, copy) NSString *outputPath;

/**
 需要写入视频的元数据
 */
@property (nonatomic, copy) NSString *metadata;

/**
 编码参数，将根据asset确定默认值
 */
@property (nonatomic, strong, readonly) MFDCodecSettings *codecSettings;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 构造所需的MFDAsset进行初始化，可自行创建或从一些接口类中获取，如 `MFDVideoPlayer` 的 `activeAsset`
 */
- (instancetype)initWithVideoAsset:(MFDAsset *)asset;

@end

#pragma mark -

/**
 编码参数类
 */
@interface MFDCodecSettings : NSObject

/**
 输出视频尺寸
 */
@property (nonatomic, assign) CGSize size;

/**
 输出视频码率
 */
@property (nonatomic, assign) NSUInteger bitrate;

/**
 是否使用硬编码，默认NO
 */
@property (nonatomic, assign, getter=isHardwareEncoderEnabled) BOOL hardwareEncoderEnabled;

@end

#endif /* MFDTranscoder_h */
