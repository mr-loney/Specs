//
//  MFDSnapshot.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/10.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDSnapshot_h
#define MFDSnapshot_h

@class MFDSnapshotSettings;
@class MFDEffect;
@class MFDVideo;
@class MFDAsset;
@class MFDVideoSampleInfo;

@protocol MFDSnapshotDelegate <NSObject>

@optional

/**
 对视频帧进行特效处理前的回调
 
 有一些特效渲染前需要业务侧提供特定数据，sdk通过info告知业务侧需要什么数据，然后业务侧通过 snapshot.effect 的 `setExtFrameData:` 方法传入该帧渲染需要的特定数据，也可以在此回调进行一些自定义的帧相关的业务逻辑。
 
 详细用法见 `MFDVideoSampleInfo` 和 `MFDEffect` 的`setExtFrameData:`注释。
 
 通常需要同步编辑的 `videoPlayerWillProcessVideoSample:` 里的逻辑，不会单独截图使用。
 
 @note 此回调在渲染队列调用，请不要有耗时操作。
 
 @param info 特效处理的一些信息
 */
- (void)snapshotWillProcessSample:(MFDVideoSampleInfo *)info;

/**
 截图逐帧回调

 @param snapshot 截图图像
 */
- (void)snapshotDidOutput:(UIImage *)snapshot;

/**
 完成回调
 
 @note 若截图失败，snapshotCount为0
 
 @param snapshotCount 截图数
 */
- (void)snapshotDidComplete:(NSUInteger)snapshotCount;

/**
 取消回调
 
 @param snapshotCount 取消前的截图数
 */
- (void)snapshotDidCancel:(NSUInteger)snapshotCount;

@end

#pragma mark -

/**
 视频截图类
 */
@interface MFDSnapshot : NSObject

/**
 在 `snapshot` 后设置
 */
@property (nonatomic, weak) id<MFDSnapshotDelegate> delegate;

/**
 特效操作类
 */
@property (nonatomic, strong, readonly) MFDEffect *effect;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithSettings:(MFDSnapshotSettings *)settings;

/**
 开始截图
 
 @note 异步操作，截图过程会有相应回调事件
 */
- (void)snapshot;

/**
 取消截图
 
 @note 异步操作，取消后会有取消回调
 */
- (void)cancel;

@end

#pragma mark -

/**
 截图配置类
 */
@interface MFDSnapshotSettings : NSObject

/**
 用于截图的源视频资源
 */
@property (nonatomic, strong, readonly) MFDAsset *asset;

/**
 截图区间起始时刻，单位：秒，默认为0.0f
 */
@property (nonatomic, assign) CGFloat startTime;

/**
 截图区间时长，单位：秒，默认为0.0f，此时表示只截取时间戳为startTime的那一帧图像
 */
@property (nonatomic, assign) CGFloat duration;

/**
 在截图区间中等间隔截图的张数，间隔为：duration / snapshotCount，默认1
 
 @note 至少设置为1
 */
@property (nonatomic, assign) NSUInteger snapshotCount;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 构造所需的MFDAsset进行初始化，可自行创建或从一些接口类中获取，如 `MFDVideoPlayer` 的 `activeAsset`
 */
- (instancetype)initWithVideoAsset:(MFDAsset *)asset;

@end

#endif /* MFDSnapshot_h */
