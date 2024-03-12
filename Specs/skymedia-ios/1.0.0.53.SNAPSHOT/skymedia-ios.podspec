#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint skymedia.podspec' to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'skymedia-ios'
  s.version          = '1.0.0.53.SNAPSHOT'
  s.summary          = 'SkyMedia SDK.'
  s.description      = <<-DESC
skymedia flutter plugin.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :http => 'file:///Users/pengjun/Documents/money/ios_sdk/skymedia-ios_62.zip' }

  # s.source_files = ['skymedia-ios/objc/**/*.{h,mm,m,c,cc,cpp}', 'mediafilter/**/*.{h,mm,m,c,cc,cpp}', 'core/**/*.{h,mm,m,c,cc,cpp}']
  s.source_files = ['skymedia-ios/objc/**/*.{h,mm,m,c,cc,cpp}', 'core/**/*.{h,mm,m,c,cc,cpp}']
  s.exclude_files = ['core/3rd/rapidjson/msinttypes/*.{h}', 'skymedia-ios/objc/codec/videotoolboxdec.{h,c}', "core/codec/encode/MediacodecEncoder.{h,cpp}"]

  s.public_header_files = 'skymedia-ios/objc/Sky{*}.h'

  # s.library = 'c++', 'venus_static',"vn_asr_static" ,"vn_audiodenoise_static" ,"vn_bodylandmark_static" ,"vn_clothesseg_static" ,"vn_cnn_static" ,"vn_core_static" ,"vn_face_static" ,"vn_gesture_static" ,"vn_hairseg_static" ,"vn_headseg_static" ,"vn_kits_static" ,"vn_new_gesture_static" ,"vn_palm_static" ,"vn_resources_static" ,"vn_sbseg_static" ,"vn_seg_static" ,"vn_segment_static" ,"vn_singodenoise_static" ,"vn_skyseg_static","yyaudiodsp"
  s.library = 'c++'
  s.header_dir = 'SkyMediaSDK'
  

  s.platform = :ios, '9.0'

  s.dependency 'ffmpeg/ffmpeg-332-ios'#, :path => '/Users/pengjun/Documents/money/ios_sdk/ffmpeg.podspec'
  s.dependency 'orangefilter/orangefilter-all_no_ar'#, :path => '/Users/pengjun/Documents/money/ios_sdk/orangefilter.podspec'
  # s.dependency 'ffmpegframework/ffmpegframework'#, :path => '/Users/pengjun/Documents/money/ios_sdk/*****.zip'
  # s.dependency 'orangefilter/orangefilter-all'#, :path => '/Users/pengjun/Documents/money/ios_sdk/*****.zip'
  # s.dependency 'yyaudiodsp'#, :path => '/Users/pengjun/Documents/money/ios_sdk/*****.zip'
  # s.dependency 'venus/venus-all-static2'#, :path => '/Users/pengjun/Documents/money/ios_sdk/*****.zip'

  s.ios.vendored_framework = "SkyMediaSDK.framework"

  # $dir = File.dirname(__FILE__)

  # Flutter.framework does not contain a i386 slice. Only x86_64 simulators are supported.
  # s.pod_target_xcconfig = { "HEADER_SEARCH_PATHS" => [$dir + "/core", $dir + "/core/cmdline/apple_include", $dir + "/core/cmdline/apple_include/config", $dir + "/core/cmdline/apple_include/libavutil", $dir + "/core/cmdline/apple_include/libavcodec",
  #   $dir + "/mediafilter", "${PODS_ROOT}/ffmpegframework/include", "${PODS_ROOT}/orangefilter/include", "${PODS_ROOT}/yyaudiodsp/include", $dir + "/core/3rd/libyuv/include"], 
  # 'VALID_ARCHS[sdk=iphonesimulator*]' => 'x86_64', 
  # 'LIBRARY_SEARCH_PATHS' => ["${PODS_ROOT}/venus/libs", "${PODS_ROOT}/yyaudiodsp/libs"],

#   s.pod_target_xcconfig = { "HEADER_SEARCH_PATHS" => [$dir + "/core", $dir + "/core/cmdline/apple_include", $dir + "/core/cmdline/apple_include/config", $dir + "/core/cmdline/apple_include/libavutil", $dir + "/core/cmdline/apple_include/libavcodec",
#      $dir + "/core/3rd/libyuv/include"], 
#   'VALID_ARCHS[sdk=iphonesimulator*]' => 'x86_64'],
# 'ENABLE_BITCODE' => 'NO','DEFINES_MODULE' => 'NO', 'GCC_PREPROCESSOR_DEFINITIONS' => ['$(inherited)', "SKY_SUPPORT_FFMPEG_CMDLINE=1"]}

end
