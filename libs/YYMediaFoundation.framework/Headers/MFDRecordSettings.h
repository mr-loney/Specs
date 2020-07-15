//
//  MFDRecordSettings.h
//  YYMediaFoundation
//
//  Created by 陈俊明 on 2020/1/3.
//  Copyright © 2020 JOYY Inc. All rights reserved.
//

#ifndef MFDRecordSettings_h
#define MFDRecordSettings_h

/**
 录制文件格式
 */
typedef NS_ENUM(NSInteger, MFDRecordFileType) {
    MFDRecordFileType_MP4 = 0,
    MFDRecordFileType_MOV = 1,
};

/**
 录制编码格式
 
 - `MFDRecordCodecType_H264` H264编码
 - `MFDRecordCodecType_HEVC` H265编码，需为iPhone7及以上，且iOS11及以上
 */
typedef NS_ENUM(NSInteger, MFDRecordCodecType) {
    MFDRecordCodecType_H264 = 0,
    MFDRecordCodecType_HEVC = 1,
};

/**
 录制配置
 
 包括文件存放目录、文件格式、视频编码格式、视频分辨率、视频码率、视频关键帧间隔。
 */
@interface MFDRecordSettings : NSObject

/**
 文件存放目录，默认 cache目录
 
 @note 具体的文件路径通过 `MFDCameraDelegate` 相关回调获取
*/
@property (nonatomic, copy) NSString *outputDir;

/**
 文件格式，默认 `MFDRecordFileType_MP4`
 */
@property (nonatomic, assign) MFDRecordFileType fileType;

/**
 视频编码格式，默认 `MFDRecordCodecType_H264`
 
 @note `MFDRecordCodecType_HEVC` 需iPhone7及以上，且iOS11及以上，否则仍按h264进行编码
 */
@property (nonatomic, assign) MFDRecordCodecType codecType;

/**
 视频分辨率，默认 540x960
*/
@property (nonatomic, assign) CGSize size;

/**
 视频码率，单位：kbps，默认 8192（8M）
 */
@property (nonatomic, assign) NSUInteger bitrate;

/**
 视频关键帧间隔，默认6
 */
@property (nonatomic, assign) NSUInteger gop;

@end

#endif /* MFDRecordSettings_h */
