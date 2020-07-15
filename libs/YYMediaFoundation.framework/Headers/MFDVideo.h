//
//  MFDVideo.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/10.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDVideo_h
#define MFDVideo_h

@class MFDVideoInfo;
@class MFDAudioInfo;

@interface MFDVideo : NSObject <NSCopying>

@property (nonatomic, copy, readonly) NSString *filePath;
@property (nonatomic, strong, readonly) NSURL *fileURL;
@property (nonatomic, strong, readonly) MFDVideoInfo *videoInfo;
@property (nonatomic, strong, readonly) MFDAudioInfo *audioInfo;
@property (nonatomic, assign, readonly) CGSize previewSize;
@property (nonatomic, assign) CGFloat startTime;
@property (nonatomic, assign) CGFloat duration;
@property (nonatomic, assign, readonly) CGFloat endTime;
@property (nonatomic, assign) CGFloat displayTime;
@property (nonatomic, assign, readonly) CGFloat endDisplayTime;
@property (nonatomic, assign) NSInteger rotation;
@property (nonatomic, assign) CGFloat volume;
@property (nonatomic, strong) NSArray *viewports; // CGRect

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFile:(NSString *)filePath;

@end

@interface MFDPhotoVideo : MFDVideo

@end

#endif /* MFDVideo_h */
