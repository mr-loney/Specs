# -*- coding: utf-8 -*-

Pod::Spec.new do |s|
    s.name = 'avtoolkit'
    s.version = "1.0.3"
    s.authors = { 'Your Company' => 'email@example.com' }
    s.license = { :type => 'BSD', :text => <<-LICENSE
        Copyright  2020 JOYY Inc. All rights reserved.
        LICENSE
    }
    s.homepage         = 'http://example.com'
    s.source = { :http => "https://p-template-hk.oss-cn-hongkong.aliyuncs.com/ios_sdk/avtoolkit.zip" }
    s.summary = 'A codec library for iOS'

    s.platform = :ios
    s.ios.deployment_target = '9.0'
    s.requires_arc = true

    s.default_subspec = 'avtoolkit'
    s.frameworks = 'AVFoundation', 'Foundation', 'VideoToolBox'

    s.subspec 'avtoolkit' do |s1|
        s1.dependency 'ffmpeg/ffmpeg-332-ios', '1.0.2'
s1.dependency 'libyuv', '1.0.2'
        s1.vendored_frameworks = 'libs/avtoolkit.framework'
        s1.xcconfig = { 'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/avtoolkit/libs/avtoolkit.framework/Headers"', 'LD_RUNPATH_SEARCH_PATHS' => '@loader_path/../Frameworks' }
    end
    
    s.subspec 'avtoolkitStatic' do |s2|
        s2.dependency 'ffmpeg/ffmpeg-332-ios', '1.0.2'
s2.dependency 'libyuv', '1.0.2'
        s2.libraries = 'z', 'bz2'
        s2.source_files = 'include/avtoolkitStatic/*.h'
        s2.vendored_library = 'libs/libavtoolkitStatic.a'
        s2.xcconfig = { 'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/avtoolkit/include"', 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/avtoolkit/libs"' }
    end
end