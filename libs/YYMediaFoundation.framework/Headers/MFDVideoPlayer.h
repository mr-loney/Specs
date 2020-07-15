//
//  MFDVideoPlayer.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/10.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDVideoPlayer_h
#define MFDVideoPlayer_h

@protocol MFDVideoPlayerDelegate;
@class MFDEffect;
@class MFDAudio;
@class MFDAsset;

@interface MFDVideoPlayer : NSObject

/**
 在`initWithSettings:`后设置
 */
@property (nonatomic, weak) id<MFDVideoPlayerDelegate> delegate;

/**
 播放速率，一般使用的值为0.5、1、2.0
 */
@property (nonatomic, assign) CGFloat rate;

/**
 视频原声音量，0-1，默认1
 */
@property (nonatomic, assign) CGFloat volume;

/**
 背景音乐（通过`updateBGM:`设置的音乐）音量，0.0-1.0
 */
@property (nonatomic, assign) CGFloat bgmVolume;

/**
 当前播放时刻，单位：秒
 */
@property (nonatomic, assign, readonly) CGFloat currentTime;

/**
 视频资源时长，单位：秒
 
 @note 注意区分该值与`playAtTime:duration:`设置的时长，该值表示原始时长
 */
@property (nonatomic, assign, readonly) CGFloat duration;

/**
 是否正在播放
 */
@property (nonatomic, assign, readonly, getter=isPlaying) BOOL playing;

/**
 循环播放标志，默认NO
 
 若为YES，在触发`videoPlayerDidPlayToEnd`回调后将会自动从头开始播放，默认从第0秒开始，若通过`playAtTime:duration:`指定了区间，则从区间起始处开始。
 */
@property (nonatomic, assign, getter=isLoop) BOOL loop;

/**
 特效操作类
 */
@property (nonatomic, strong, readonly) MFDEffect *effect;

/**
 播放器处于暂停状态时是否重复渲染最后一帧，默认为NO。
 
 重复渲染适用于视频画面不变，但是需要更新特效动画的场景，除此之外不推荐使用，以减少功耗
 */
@property (nonatomic, assign, getter=isRepeatRenderEnabled) BOOL repeatRenderEnabled;

/**
 获取当前使用的所有资源，后续在截图或者导出使用
 */
@property (nonatomic, strong, readonly) MFDAsset *activeAsset;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithAsset:(MFDAsset *)asset;

#pragma mark -

/**
 更换播放器播放的资源
 
 更换后会重新触发`videoPlayerDidReady`回调
 
 如果asset为nil表示移除当前播放的资源
 */
- (void)reset:(MFDAsset *)asset;

/**
 设置预览用的view，渲染view将作为该view的subview
 */
- (void)setPreview:(UIView *)view;

/**
 设置背景音乐，如参数为nil表示移除背景音乐
 
 后续音量通过player.bgmVolume调节
 */
- (void)updateBGM:(MFDAudio *)bgm;

/**
 指定播放区间，比如视频有10s，现需要播放1-4秒，则startTime=1.0f，duration=3.0f。
 
 若区间超出资源时长，则 duration = player.duration - startTime
 
 如果当前时刻不在指定的播放区间内，将会seek至区间起始或末尾

 @param startTime 起始时刻，单位：秒
 @param duration 时长，单位：秒
 */
- (void)playAtTime:(CGFloat)startTime duration:(CGFloat)duration;

/**
 播放
 
 需在`videoPlayerDidReady`回调后调用才生效
 */
- (void)play;

/**
 暂停
 
 需在`videoPlayerDidReady`回调后调用才生效
 */
- (void)pause;

/**
 指定播放时刻，单位：秒
 
 需在`videoPlayerDidReady`回调后调用才生效

 @param time 播放时刻
 */
- (void)seek:(CGFloat)time;

@end

#pragma mark -

/**
 播放回调
 */
@protocol MFDVideoPlayerDelegate <NSObject>

@optional

/**
 player已就绪的回调，可以调用play开始播放
 
 一些player的接口需要在该回调后调用才生效，在这些接口的注释中已说明
 */
- (void)videoPlayerDidReady;

/**
 末尾回调
 
 默认播放区间为[0, player.duration)。如果通过`playAtTime:duration:`指定了区间，则播至该区间末尾时触发回调。
 */
- (void)videoPlayerDidPlayToEnd;

/**
 进度回调

 @param currentTime 当前播放时刻，单位：秒
 */
- (void)videoPlayerDidPlay:(CGFloat)currentTime;

@end

#endif /* MFDVideoPlayer_h */
