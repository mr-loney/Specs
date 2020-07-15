//
//  MFDEffect.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/14.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDEffect_h
#define MFDEffect_h

@class MFDExtFrameData;
@class MFDEffectParam;
@class MFDEffectInfo;

@interface MFDEffect : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

#pragma mark - 帧数据

/**
 使用`fetchFrameData`获取的数据信息进行恢复
 */
- (void)resetFrameData:(NSDictionary *)frameData;

/**
 获取当前添加的所有特效的帧检测数据（如有），用于配合`resetFrameData:`进行数据恢复
 
 此NSDictionary支持序列化，方便业务侧进行持久化处理
 */
- (NSDictionary *)fetchFrameData;

/**
 设置当前帧所需的业务侧扩展数据，在各业务模块的`***WillProcessVideoSample:`中使用
 */
- (void)setExtFrameData:(MFDExtFrameData *)extFrameData;

#pragma mark - 特效数据

/**
 使用`fetchEffectData`获取的特效信息进行特效恢复
 
 恢复后可通过之前的effectID继续进行特效操作
 */
- (void)resetEffect:(NSDictionary *)effectData;

/**
 获取当前添加的所有特效的信息，用于配合`resetEffect:`进行特效恢复
 
 此NSDictionary支持序列化，方便业务侧进行持久化处理
 */
- (NSDictionary *)fetchEffectData;

#pragma mark - 特效操作

/**
 添加特效
 
 根据param.effectType来创建业务逻辑不同的特效，同时指定特效参数为param相应的设置过的属性，没有调用过setter的属性不会更新
 
 添加失败返回nil
 */
- (NSString *)addEffect:(MFDEffectParam *)param;

/**
 更新指定的特效参数为paramn相应的设置过的属性，没有调用过setter的属性不会更新
 */
- (void)updateEffect:(NSString *)effectID param:(MFDEffectParam *)param;

/**
 移除指定特效
 */
- (void)removeEffect:(NSString *)effectID;

/**
 移除全部特效
 */
- (void)removeAllEffects;

/**
 获取指定特效的部分信息
 
 同步操作，在渲染队列执行，故可能会比较耗时。
 
 尽量避免调用，或者按照相关的使用说明在渲染队列的回调中使用
 */
- (MFDEffectInfo *)fetchEffectInfo:(NSString *)effectID;

@end

#endif /* MFDEffect_h */
