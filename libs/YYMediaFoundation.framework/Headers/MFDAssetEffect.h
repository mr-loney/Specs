//
//  MFDAssetEffect.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2020/3/4.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDAssetEffect_h
#define MFDAssetEffect_h

typedef void (^MFDAssetEffectEventCallback)(NSDictionary *event);

/**
 资源特效类
 */
@interface MFDAssetEffect : NSObject

/**
 特效素材的.ofeffect路径
 */
@property (nonatomic, copy, readonly) NSString *effectFile;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 使用特效素材包里的.ofeffect文件路径初始化
 */
- (instancetype)initWithEffectFile:(NSString *)effectFile;

/**
 重新加载特效素材，在更新了orangefilter内部使用的资源如图片等之后需调用
 */
- (void)reset;

/**
 更新用于模板渲染的一些帧数据，目前仅用于传递人脸数据：
 
 OF_FaceFrameDataArr faceDataArr;
     
 [effect updateFrameData:@{
     @(MFDRequiredData_Face):[NSValue valueWithPointer:&faceDataArr],
 }];
 */
- (void)updateFrameData:(NSDictionary *)frameData;

/**
 更新.ofeffect中特定参数的值

 ```
 [effect updateEffectInfo:@{
    @"0:Text":@"xxx",
    @"2:RandomNum":@(0.3),
 }];
 ```
 
 可以一次更新多个参数，其中key的含义是：
 比如@"0:Text":@"xxx"表示更新.ofeffect的filterList的第1个filter的Text参数为xxx（索引从0开始）
*/
- (void)updateEffectInfo:(NSDictionary *)effectInfo;

/**
 向模版发送消息，消息协议由客户端和素材制作者自行确定
 */
- (void)updateEvent:(NSDictionary *)event;

/**
 接收模版消息，消息协议由客户端和素材制作者自行确定
 */
- (void)updateEventCallback:(MFDAssetEffectEventCallback)callback;

@end

/**
 转场特效
 */
@interface MFDAssetTransitionEffect : MFDAssetEffect

/**
 转场时长，单位：秒
 */
@property (nonatomic, assign) CGFloat duration;

/**
 序号，即在第几个间隔添加此转场，索引从1开始，如1表示第1个间隔（第1～2个视频间）
 */
@property (nonatomic, assign) NSUInteger index;

@end

#endif /* MFDAssetEffect_h */
