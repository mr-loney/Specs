//
//  MFDAudio.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/10.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDAudio_h
#define MFDAudio_h

@class MFDAudioInfo;

@interface MFDAudio : NSObject <NSCopying>

@property (nonatomic, copy, readonly) NSString *filePath;
@property (nonatomic, strong, readonly) NSURL *fileURL;
@property (nonatomic, assign, readonly) BOOL isNetworkFile;
@property (nonatomic, strong, readonly) MFDAudioInfo *audioInfo;
@property (nonatomic, assign) CGFloat startTime;
@property (nonatomic, assign) CGFloat duration;
@property (nonatomic, assign, readonly) CGFloat endTime;
@property (nonatomic, assign) CGFloat displayTime;
@property (nonatomic, assign, readonly) CGFloat endDisplayTime;
@property (nonatomic, assign) CGFloat volume;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFile:(NSString *)filePath;

@end

#endif /* MFDAudio_h */
