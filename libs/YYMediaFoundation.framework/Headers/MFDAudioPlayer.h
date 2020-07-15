//
//  MFDAudioPlayer.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/10.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDAudioPlayer_h
#define MFDAudioPlayer_h

@class MFDAudio;

@protocol MFDAudioPlayerDelegate <NSObject>

@optional

/**
 当播放网络音乐时才有的回调，表示数据不足，开始缓冲，一般此时业务显示等待图标
 */
- (void)audioPlayerWillStartBuffer;

/**
 当播放网络音乐时才有的回调，表示缓冲完成，一般此时业务隐藏等待图标继续播放
 */
- (void)audioPlayerDidStopBuffer;

/**
 完成回调，表示已播放到指定区间，如果设置了loop，将会自动循环播放
 */
- (void)audioPlayerDidPlayToEnd;

/**
 当前播放时刻回调，单位：秒
 */
- (void)audioPlayerDidPlay:(CGFloat)currentTime;

@end

/**
 音频播放器
 */
@interface MFDAudioPlayer : NSObject

/**
 初始化后设置
 */
@property (nonatomic, weak) id<MFDAudioPlayerDelegate> delegate;

/**
 播放速度，用于变速，默认常速1.0f
 */
@property (nonatomic, assign) CGFloat rate;

/**
 音量，0-1，默认1.0f
 */
@property (nonatomic, assign) CGFloat volume;

/**
 当前播放时刻，单位：秒
 */
@property (nonatomic, assign, readonly) CGFloat currentTime;

/**
 资源时长，如果是网络音频，则duration将从0逐渐增加到完整时长，单位：秒
 */
@property (nonatomic, assign, readonly) CGFloat duration;

/**
 是否正在播放
 */
@property (nonatomic, assign, readonly, getter=isPlaying) BOOL playing;

/**
 循环标志，若为YES，则播放到音频末尾时将循环播放，若调用 `playAtTime:duration:` 设置了区间，则播到区间末尾将循环播放。默认NO
 */
@property (nonatomic, assign, getter=isLoop) BOOL loop;

/**
 重置播放器，之后需要重新 `update:` 资源并调用 `play` 播放
 */
- (void)reset;

/**
 更新音频资源
 */
- (void)update:(MFDAudio *)audio;

/**
 指定播放区间，比如音频有10s，现需要播放1-4秒，则startTime=1.0f，duration=3.0f
 
 @note 不会改变播放状态，如当前是暂停状态，指定后仍是暂停状态
 */
- (void)playAtTime:(CGFloat)startTime duration:(CGFloat)duration;

/**
 播放
 */
- (void)play;

/**
 暂停
 */
- (void)pause;

/**
 指定播放时刻，单位：秒
 
 @note 网络音频不支持seek
 */
- (void)seek:(CGFloat)time;

@end

#endif /* MFDAudioPlayer_h */
