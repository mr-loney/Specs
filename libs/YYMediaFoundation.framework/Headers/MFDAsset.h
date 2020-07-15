//
//  MFDAsset.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/10.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDAsset_h
#define MFDAsset_h

@class MFDVideo;
@class MFDAudio;
@class MFDAssetEffect;

/**
 资源类型
 
 - MFDAssetType_Default: 默认类型，当传入多个videos将依次做前后拼接处理
 
 - MFDAssetType_Transition: 转场类型，需配置 `MFDAssetEffect`
 
 - MFDAssetType_Template: 模版视频，需配置 `MFDAssetEffect`
 */
typedef NS_ENUM(NSInteger, MFDAssetType) {
    MFDAssetType_Default = 0,
    MFDAssetType_Transition = 1,
    MFDAssetType_Template = 5,
};

/**
 音视频资源类
 */
@interface MFDAsset : NSObject

/**
 `initWithVideos:audios:` 传入的videos
 */
@property (nonatomic, strong, readonly) NSArray<MFDVideo *> *videos;

/**
 `initWithVideos:audios:` 传入的audios
 */
@property (nonatomic, strong, readonly) NSArray<MFDAudio *> *audios;

/**
 资源类型，默认为 `MFDAssetType_Default`
 */
@property (nonatomic, assign) MFDAssetType assetType;

/**
 渲染尺寸，默认为第一个video的previewSize，一般在传入多个不同分辨率视频时指定
 */
@property (nonatomic, assign) CGSize renderSize;

/**
 资源特效信息
 
 当assetType为MFDAssetType_Transition、MFDAssetType_Template时，需要设置相应的资源特效信息。
 */
@property (nonatomic, strong) NSArray<MFDAssetEffect *> *effects;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 在这里传入的audios将当作视频原声处理，其音量需通过player.volume更新
 */
- (instancetype)initWithVideos:(NSArray<MFDVideo *> *)videos audios:(NSArray<MFDAudio *> *)audios;

@end

#endif /* MFDAsset_h */
