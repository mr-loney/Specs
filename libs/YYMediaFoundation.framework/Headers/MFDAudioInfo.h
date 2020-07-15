//
//  MFDAudioInfo.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/12/5.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDAudioInfo_h
#define MFDAudioInfo_h

@interface MFDAudioInfo : NSObject <NSCopying>

@property (nonatomic, assign, readonly) CGFloat startTime;
@property (nonatomic, assign, readonly) CGFloat duration;
@property (nonatomic, assign, readonly) CGFloat endTime;
@property (nonatomic, assign, readonly) NSUInteger channels;
@property (nonatomic, assign, readonly) NSUInteger sampleRate;

@end

#endif /* MFDAudioInfo_h */
