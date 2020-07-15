//
//  MFDVideoDevice.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2019/1/30.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDVideoDevice_h
#define MFDVideoDevice_h

@interface MFDVideoDevice : NSObject

@property (nonatomic, assign, readonly) AVCaptureDevicePosition position;
@property (nonatomic, assign) CGFloat zoom;
@property (nonatomic, assign, readonly) CGFloat maxZoom;
@property (nonatomic, assign, readonly) BOOL isFlashAvailable;
@property (nonatomic, assign) AVCaptureFlashMode flashMode;
@property (nonatomic, assign) AVCaptureTorchMode torchMode;
@property (nonatomic, assign) CGFloat ISO;
@property (nonatomic, assign, readonly) CGFloat minISO;
@property (nonatomic, assign, readonly) CGFloat maxISO;
@property (nonatomic, assign) AVCaptureVideoStabilizationMode stabilizationMode;
@property (nonatomic, assign) CGPoint focusPoint;
@property (nonatomic, assign) AVCaptureFocusMode focusMode;
@property (nonatomic, assign) CGPoint exposurePoint;
@property (nonatomic, assign) AVCaptureExposureMode exposureMode;
@property (nonatomic, assign) CGFloat exposureBias;
@property (nonatomic, assign) AVCaptureWhiteBalanceMode whiteBalanceMode;
@property (nonatomic, assign) CGFloat fps;

- (void)update:(dispatch_block_t)block;

@end

#endif /* MFDVideoDevice_h */
