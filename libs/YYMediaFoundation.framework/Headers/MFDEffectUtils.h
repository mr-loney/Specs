//
//  MFDEffectUtils.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/4/10.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDEffectUtils_h
#define MFDEffectUtils_h

typedef NS_ENUM(NSUInteger, MFDGLExtension) {
    MFDGLExtension_PVRTC = 1 << 0,
    MFDGLExtension_ETC2 = 1 << 1,
};

@interface MFDEffectUtils : NSObject

/**
 获取当前设备支持的gl扩展格式，用于配合后台下发不同版本的特效素材
 */
+ (NSUInteger)fetchGLExtensions;

/**
 校验特效资源是否合法（完整性）
 
 同步操作，在渲染队列执行。可能会较耗时
 */
+ (BOOL)validateEffect:(NSString *)effectFile;

@end

#endif /* MFDEffectUtils_h */
