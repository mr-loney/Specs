//
//  MFDCameraFormat.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/12/30.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDCameraFormat_h
#define MFDCameraFormat_h

/**
 摄像头格式
 
 通过 `supportedFormatsForPosition:` 获取指定摄像头支持的所有格式，并根据其中某些参数筛选出所需实例，设置到 `MFDCameraSettings` 里
 */
@interface MFDCameraFormat : NSObject

/**
 摄像头位置，表示该格式属于前置还是后置
 */
@property (nonatomic, assign, readonly) AVCaptureDevicePosition position;

/**
 预览分辨率
 
 @note 此分辨率固定宽大于高，后续将按照 `MFDCameraSettings` 的 `captureOrientation` 进行相应变换。
 */
@property (nonatomic, assign, readonly) CGSize previewSize;

/**
 拍照分辨率，即通过 `MFDCamera` 的 `capturePhoto:` 获取的图像分辨率
 
 @note 此分辨率固定宽大于高，后续将按照 `MFDCameraSettings` 的 `captureOrientation` 进行相应变换。
 */
@property (nonatomic, assign, readonly) CGSize photoSize;

/**
 最小采集帧率

 @note 即预览最小帧率，预览帧率通过 `MFDCamera` 的 `device` 更新
*/
@property (nonatomic, assign, readonly) NSUInteger minFPS;

/**
 最大采集帧率

 @note 即预览最大帧率，预览帧率通过 `MFDCamera` 的 `device` 更新
*/
@property (nonatomic, assign, readonly) NSUInteger maxFPS;

/**
 是否支持Binned，binned模式会降低画质以提升性能
 */
@property (nonatomic, assign, readonly) BOOL isBinned;

/**
 是否支持HDR
 */
@property (nonatomic, assign, readonly) BOOL isHDRSupported;

/**
 是否支持双摄
 
 @note 见 `MFDCameraMode`
 */
@property (nonatomic, assign, readonly) BOOL isDualSupported;

@property (nonatomic, assign, readonly) BOOL isWideColorSupported;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/**
 指定摄像头支持的所有格式
 */
+ (NSArray<MFDCameraFormat *> *)supportedFormatsForPosition:(AVCaptureDevicePosition)position;

@end

#endif /* MFDCameraFormat_h */
