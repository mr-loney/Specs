//
//  MFDGallery.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/10.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDGallery_h
#define MFDGallery_h

@class MFDImage;
@class MFDEffect;

/**
 图片编辑类
 */
@interface MFDGallery : NSObject

/**
 特效操作类
 */
@property (nonatomic, strong, readonly) MFDEffect *effect;

/**
 更新用于编辑的图像
 */
- (void)reset:(MFDImage *)image;

/**
 设置用于预览编辑图像的view，若无需预览则不设置
 */
- (void)setPreview:(UIView *)preview;

/**
 重新渲染，更新编辑效果
 
 @note 当需要预览（调用了 `setPreview:` 设置了view），且通过 `effect` 属性进行了特效操作后，需调用此方法更新效果
 */
- (void)render;

/**
 导出编辑后的图像
 
 @note 若出错返回的image将为nil
 */
- (void)exportImage:(void (^)(UIImage *image))block;

@end

#endif /* MFDGallery_h */
