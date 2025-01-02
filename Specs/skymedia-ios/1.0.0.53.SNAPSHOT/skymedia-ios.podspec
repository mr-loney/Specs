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
  s.source           = { :http => 'https://p-template-hk.oss-cn-hongkong.aliyuncs.com/ios_sdk/skymedia-ios_62.zip' }

  # s.source_files = ['skymedia-ios/objc/**/*.{h,mm,m,c,cc,cpp}', 'mediafilter/**/*.{h,mm,m,c,cc,cpp}', 'core/**/*.{h,mm,m,c,cc,cpp}']
  s.source_files = ['skymedia-ios/objc/**/*.{h,mm,m,c,cc,cpp}', 'core/**/*.{h,mm,m,c,cc,cpp}']
  s.exclude_files = ['core/3rd/rapidjson/msinttypes/*.{h}', 'skymedia-ios/objc/codec/videotoolboxdec.{h,c}', "core/codec/encode/MediacodecEncoder.{h,cpp}"]

  s.public_header_files = 'skymedia-ios/objc/Sky{*}.h'

  s.library = 'c++'
  s.header_dir = 'SkyMediaSDK'

  s.platform = :ios, '9.0'

  s.dependency 'ffmpeg/ffmpeg-332-ios'#, :path => 'https://p-template-hk.oss-cn-hongkong.aliyuncs.com/ios_sdk/ffmpeg.podspec'
  s.dependency 'orangefilter/orangefilter-all_no_ar'#, :path => 'https://p-template-hk.oss-cn-hongkong.aliyuncs.com/ios_sdk/orangefilter.podspec'

  s.default_subspec = 'default'
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
  s.subspec 'default' do |sdc|
      sdc.frameworks     = ios_frameworks
      sdc.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/skymedia-ios/include','LD_RUNPATH_SEARCH_PATHS' => '@loader_path/../Frameworks'}
      sdc.source_files   = '**/*.h'
      sdc.preserve_paths = '*.framework'
      sdc.ios.vendored_frameworks = "SkyMediaSDK.framework"
  end

end
