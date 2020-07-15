//
//  MFDImage.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/10.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDImage_h
#define MFDImage_h

@class MFDImageInfo;

@interface MFDImage : NSObject

@property (nonatomic, copy, readonly) NSString *filePath;
@property (nonatomic, strong, readonly) MFDImageInfo *info;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFile:(NSString *)filePath;
- (instancetype)initWithImage:(UIImage *)image;
- (instancetype)initWithImage:(UIImage *)image scale:(CGFloat)scale;

@end

#endif /* MFDImage_h */
