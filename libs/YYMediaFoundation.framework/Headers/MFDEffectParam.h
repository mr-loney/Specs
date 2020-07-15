//
//  MFDEffectParam.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/26.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDEffectParam_h
#define MFDEffectParam_h

typedef NS_OPTIONS(NSUInteger, MFDRequiredData) {
    MFDRequiredData_None = 0,
    MFDRequiredData_Face = (1 << 0),
    MFDRequiredData_Gesture = (1 << 1),
    MFDRequiredData_Body = (1 << 2),
    MFDRequiredData_AudioBeat = (1 << 3),
    MFDRequiredData_AR = (1 << 4),
    MFDRequiredData_Background = (1 << 5),
    MFDRequiredData_Avatar = (1 << 6),
    MFDRequiredData_Hair = (1 << 7),
};

/**
 视频帧信息，各业务模块的`***WillProcessVideoSample:`回调中返回
 */
@interface MFDVideoSampleInfo : NSObject

/**
 帧的原始图像，跟最终显示的一般不一致
 */
@property (nonatomic, assign) CVPixelBufferRef buffer;

/**
 帧的pts，单位：秒
 */
@property (nonatomic, assign) CGFloat pts;

/**
 该帧渲染所需的额外数据类型
 */
@property (nonatomic, assign) MFDRequiredData requiredData;

/**
 该帧图像的人脸数
 
 当该帧添加了需要人脸数据的特效，且检测到人脸时才会大于0
 */
@property (nonatomic, assign) NSUInteger faceCount;

/**
 该帧图像的人脸框，数量等于faceCount
 */
@property (nonatomic, strong) NSArray *faceRects;

@end

/**
 视频帧业务侧扩展数据，用于在各业务模块的`***WillProcessVideoSample:`回调中，
 调用MFDEffect的`setExtFrameData:`方法传入该帧需要的业务侧扩展数据
 */
@interface MFDExtFrameData : NSObject

// 以下5个为旧Noizz中的频谱业务数据
@property (nonatomic, assign) float beat;
@property (nonatomic, assign) float loudness;
@property (nonatomic, assign) float loudnessSmooth;
@property (nonatomic, assign) unsigned int frequencyDataCount;
@property (nonatomic, assign) void *frequencyData;

@end

#pragma mark -

typedef NS_ENUM(NSInteger, MFDEffectType) {
    MFDEffectType_Default = 0,
    MFDEffectType_DoubleLut = 1,
    MFDEffectType_Video = 2,
    MFDEffectType_DualCamera = 3,
};

typedef NS_ENUM(NSInteger, MFDEffectState) {
    MFDEffectState_Play = 0,
    MFDEffectState_Pause = 1,
    MFDEffectState_Restart = 2,
};

typedef void (^MFDEffectEventCallback)(NSDictionary *event);

@interface MFDEffectParam : NSObject

/**
 特效类型，参考`initWithType:`的注释
 */
@property (nonatomic, assign, readonly) MFDEffectType effectType;

/**
 指定是否可见
 
 当visible为NO时，特效不会渲染，但是特效还是存在的。
 如Noizz的编辑页，在特效编辑时回删上一个添加的特效会把它设置为NO不再显示，如果用户接着点了确认，那么就调用removeEffect:删除掉，如果用户点了撤销，就把visible设为YES恢复显示。
 */
@property (nonatomic, assign, getter=isVisible) BOOL visible;

/**
 向特效发送消息，消息协议由客户端与of制定
 */
@property (nonatomic, strong) NSDictionary *event;

/**
 接收特效的回调消息，消息协议由客户端与of制定
 */
@property (nonatomic, copy) MFDEffectEventCallback callback;

/**
 指定显示开始时刻，和duration一起设置，单位：秒
 */
@property (nonatomic, assign) CGFloat startTime;

/**
 指定显示时长，和startTime一起设置，单位：秒
 
 编辑页添加特效场景，用户按住开始添加时指定startTime为当前pts，duration为剩余时长。用户松手后指定startTime为当前pts，duration为按住时长
 */
@property (nonatomic, assign) CGFloat duration;

/**
 指定渲染尺寸
 
 如旧版Noizz在发布到insgram时用的毛玻璃特效，其将输出图像的宽高比设置为1:1。
 */
@property (nonatomic, assign) CGSize renderSize;

/**
 动态更新特效的ofeffect参数
 
 该字典的格式为：
 
  @{
    @"0:Text":@"this is text1",
    @"1:Text":@"this is text2",
  }
 
 其中0代表更新.ofeffect的filterList里的第一个filter，Text表示更新这个filter的Text参数。特效支持更新的参数一般都在特效素材的uiinfo.conf里有注明

 若需同时更新多个参数，则同时设置多个key-value。需要更新特效参数的时候，请优先考虑此方式。
 */
@property (nonatomic, strong) NSDictionary *effectInfo;

/**
 指定显示位置。画面中心为(0,0)，x、y范围值为0-1

 兼容接口，格式为CGPoint，请优先尝试用effectInfo更新，如果effectInfo不支持才使用该方式
 */
@property (nonatomic, assign) CGPoint track;

/**
 指定旋转角度

 兼容接口，请优先尝试用effectInfo更新，如果effectInfo不支持才使用该方式
 */
@property (nonatomic, assign) CGFloat rotation;

/**
 指定缩放比例

 兼容接口，请优先尝试用effectInfo更新，如果effectInfo不支持才使用该方式
 */
@property (nonatomic, assign) CGFloat scale;

/**
 指定文字

 兼容接口，多行文字传多个NSString。请优先尝试用effectInfo更新，如果effectInfo不支持才使用该方式
 */
@property (nonatomic, strong) NSArray<NSString *> *texts;

/**
 指定颜色
 
 兼容接口，请优先尝试用effectInfo更新，如果effectInfo不支持才使用该方式
 */
@property (nonatomic, strong) UIColor *color;

/**
 指定互斥标签

 有一些特效在同一时刻是可以共存的，有一些是互斥的（后加的覆盖前加的）
 相同mutexTag的特效互斥，不同mutexTag的共存，mutexTag为nil共存。
 */
@property (nonatomic, copy) NSString *mutexTag;

/**
 指定特效资源
 
 素材目录下的.ofeffect路径。

 在addEffect的param里指定以正常加载特效，update:param:时指定则是替换资源，effectID保持不变
 */
@property (nonatomic, copy) NSString *effectFile;

/**
 指定播放时刻，单位：秒
 
 一般每个特效内有一个动画周期，通过设置seekTime可以指定特效从指定时刻开始播放。
 */
@property (nonatomic, assign) CGFloat seekTime;

/**
 指定播放状态
 */
@property (nonatomic, assign) MFDEffectState state;

/**
 指定是否缓存帧数据
 
 目前帧数据包括：`effectInfo`和`track`两个属性。如果设置为NO，则不缓存当前帧使用的数据，而是全部帧使用最后一次更新的数据
 */
@property (nonatomic, assign) BOOL cacheEnabled;

/**
 指定第2个effect
 
 用于特效类型为`MFDEffectType_DoubleLut`的滤镜特效，
 */
@property (nonatomic, copy) NSString *effectFile2;

/**
 指定2个effect之间的渲染比例（左右）

 用于特效类型为`MFDEffectType_DoubleLut`的滤镜特效，如ratio=0.5表示左边一半显示第1个effect，右边一半显示第2个effect
 */
@property (nonatomic, assign) CGFloat ratio;

/**
 创建不同type的param实例
 
 调用`addEffect:`用的param，需要按需调用`initWithType:`创建不同类型的param：
 
 MFDEffectType_Default：默认类型，编辑页贴纸或录制页普通表情动画，用`init`创建即可
 MFDEffectType_DoubleLut：滤镜类型，支持左右滑过程有两个滤镜效果共存的特殊业务逻辑
 MFDEffectType_Video：带视频类型，支持加载特效资源中的mp4，仅录制页表情会出现
 MFDEffectType_DualCamera：双摄像头类型，使用两个摄像头的图像输入，仅用于录制页表情
 
 调用`updateEffect:param`用的param，用`init`创建即可
 */
- (instancetype)initWithType:(MFDEffectType)type;

@end

#pragma mark -

/**
 `fetchEffectInfo:`返回的特效信息
 */
@interface MFDEffectInfo : NSObject

/**
 显示起始时刻，单位：秒
 */
@property (nonatomic, assign) CGFloat startTime;

/**
 显示时长，单位：秒
 */
@property (nonatomic, assign) CGFloat duration;

/**
 互斥标签
 */
@property (nonatomic, copy) NSString *mutexTag;

/**
 .ofeffect里的数据，key名请自行查阅相应.ofeffect
 */
@property (nonatomic, strong) NSDictionary *ofInfo;

/**
 渲染所需的额外信息类型
 */
@property (nonatomic, assign) MFDRequiredData requiredData;

/**
 是否可见
 */
@property (nonatomic, assign) BOOL isVisible;

@end

#endif /* MFDEffectParam_h */
