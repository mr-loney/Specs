//
//  MFDPreference.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/10.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDPreference_h
#define MFDPreference_h

typedef NS_ENUM(NSInteger, MFDLogLevel) {
    MFDLogLevel_Debug,
    MFDLogLevel_Info,
    MFDLogLevel_Warn,
    MFDLogLevel_Error,
};

@interface MFDPreference : NSObject

/**
 sdk的日志默认是通过NSLog打印，请在使用sdk任何功能前设置好此日志回调，使sdk的日志能接入到app的日志系统并上报，用于排查线上问题。
 */
@property (nonatomic, copy) void (^logCallback)(MFDLogLevel level, NSString *logString);

/**
 商汤的许可证文件对应的bundleID（正式版bundleID）
*/
@property (nonatomic, copy) NSString *appID;

/**
 传入商汤的激活许可证文件
 */
@property (nonatomic, copy) NSString *stLicense;

/**
 是否使用hook方式替换为正式bundleID从而成功激活许可证文件，默认NO
 
 由于商汤的许可证是与app正式发布的bundleID绑定的，所以在本地调试或内部构建包时id可能不为正式id，此时需要开启hook方式才可成功激活商汤库功能。
 
 注意正式对外发布的包请设置为NO，避免非正规方式使用导致的法律风险
 */
@property (nonatomic, assign) BOOL stHookEnabled;

/**
 传入商汤的人脸识别模型
*/
@property (nonatomic, copy) NSString *stFaceModel;

/**
 传入商汤的肢体识别模型
*/
@property (nonatomic, copy) NSString *stBodyModel;

/**
 传入商汤的手势识别模型
*/
@property (nonatomic, copy) NSString *stGestureModel;

/**
 传入公司的venus库人脸识别模型文件，文件可能有多个，请按其指定顺序构造
 */
@property (nonatomic, strong) NSArray<NSString *> *faceModels;

/**
 传入公司的venus库手势识别模型文件，文件可能有多个，请按其指定顺序构造
*/
@property (nonatomic, strong) NSArray<NSString *> *gestureModels;

/**
 传入公司的venus库肢体识别模型文件，文件可能有多个，请按其指定顺序构造
*/
@property (nonatomic, strong) NSArray<NSString *> *bodyModels;

/**
 传入公司的venus库背景分割模型文件，文件可能有多个，请按其指定顺序构造
*/
@property (nonatomic, strong) NSArray<NSString *> *backgroundModels;

/**
 传入公司的venus库头发分割模型文件，文件可能有多个，请按其指定顺序构造
*/
@property (nonatomic, strong) NSArray<NSString *> *hairModels;

/**
 传入公司的venus库天空分割模型文件，文件可能有多个，请按其指定顺序构造
*/
@property (nonatomic, strong) NSArray<NSString *> *skyModels;

+ (instancetype)sharedInstance;

@end

#endif /* MFDPreference_h */
