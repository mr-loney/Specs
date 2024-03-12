Pod::Spec.new do |s|
    s.version = '1.0.0-snapshot7'
    s.authors = { 'Your Company' => 'email@example.com' }
    s.license  = {:type => 'BSD-licensed'}
    
    s.summary = 'A media player for iOS'
    s.homepage         = 'http://example.com'
    s.platform = :ios
    s.ios.deployment_target = '9.0'
    s.requires_arc = true
    s.source = {:http => "file:///Users/pengjun/Documents/money/ios_sdk/transvod.zip"}
    s.frameworks = 'AVFoundation', 'Foundation', 'CoreMedia', 'VideoToolBox', 'UIKit', 'SystemConfiguration', 'CoreTelephony'
    s.libraries = 'c++', 'objc', 'bz2', 'z', 'resolv'
    s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    # s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    s.name = 'transvod'

    s.dependency 'ffmpeg/ffmpeg-332-ios'#, :path => '/Users/pengjun/Documents/money/ios_sdk/ffmpeg.podspec'

    s.dependency 'yydec265'#, :path => '/Users/pengjun/Documents/money/ios_sdk/yydec265.podspec'
    s.dependency 'libyuv'#, :path => '/Users/pengjun/Documents/money/ios_sdk/libyuv.podspec'
    s.dependency 'openssl'#, :path => '/Users/pengjun/Documents/money/ios_sdk/openssl.podspec'
    s.dependency 'yydecav1'#, :path => '/Users/pengjun/Documents/money/ios_sdk/yydecav1.podspec'
    s.dependency 'cronet'#, :path => '/Users/pengjun/Documents/money/ios_sdk/cronet.podspec'
    
    $dir = File.dirname(__FILE__)
    s.subspec 'transvodstatic' do |s1|
      s1.source_files = "include/*.h"
      s1.xcconfig = { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/transvod"' }
      s1.vendored_libraries = 'libtransvodstatic.a'
    end
end
