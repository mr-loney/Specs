//
//  MFDVideoInfo.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/12/5.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDVideoInfo_h
#define MFDVideoInfo_h

@interface MFDVideoInfo : NSObject <NSCopying>

@property (nonatomic, assign, readonly) CGSize size;
@property (nonatomic, assign, readonly) CGSize previewSize;
@property (nonatomic, assign, readonly) CGFloat startTime;
@property (nonatomic, assign, readonly) CGFloat duration;
@property (nonatomic, assign, readonly) CGFloat endTime;
@property (nonatomic, assign, readonly) NSUInteger bitrate;
@property (nonatomic, assign, readonly) NSInteger rotation;
@property (nonatomic, assign, readonly) CGFloat fps;
@property (nonatomic, assign, readonly) NSUInteger frames;

@end

#endif /* MFDVideoInfo_h */
