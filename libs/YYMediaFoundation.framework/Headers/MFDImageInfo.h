//
//  MFDImageInfo.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/12/5.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDImageInfo_h
#define MFDImageInfo_h

typedef NS_ENUM(NSInteger, MFDOrientation) {
    MFDOrientation_Up = 0,
    MFDOrientation_Down = 1,
    MFDOrientation_Left = 2,
    MFDOrientation_Right = 3,
    MFDOrientation_UpMirrored = 4,
    MFDOrientation_DownMirrored = 5,
    MFDOrientation_LeftMirrored = 6,
    MFDOrientation_RightMirrored = 7,
};

@interface MFDImageInfo : NSObject

@property (nonatomic, assign, readonly) CGSize size;
@property (nonatomic, assign, readonly) MFDOrientation orientation;
@property (nonatomic, assign, readonly) CGSize previewSize;

@end

#endif /* MFDImageInfo_h */
