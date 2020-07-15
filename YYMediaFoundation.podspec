Pod::Spec.new do |s|
    s.name = 'YYMediaFoundation'
    s.version = '1.8.2'
    s.authors = { 'Chen JunMing' => 'chenjunming@yy.com' }
    s.license = { :type => 'BSD', :text => <<-LICENSE
        Copyright © 2020 JOYY Inc. All rights reserved.
        LICENSE
    }
    s.homepage = 'http://www.yy.com/'
    s.source   = { :path => 'src/' }
    s.summary = 'A media library for iOS'
   
    s.platform = :ios
    s.ios.deployment_target = '8.0'
    s.requires_arc = true

    s.default_subspec = 'YYMediaFoundation'
    s.frameworks = 'AVFoundation', 'Foundation', 'CoreMotion', 'Accelerate'

    s.subspec 'YYMediaFoundation' do |s1|
        s1.dependency 'audioenginesdk/yyaudiodynamicsdk', '2.8.105'
s1.dependency 'avtoolkit/avtoolkitStatic', '1.2.0'
s1.dependency 'orangefilter/orangefilter-all_no_ar', '4.5.4'
s1.dependency 'venus/venus-all-ncv', '1.8.7'
        s1.vendored_frameworks = 'libs/YYMediaFoundation.framework'
        s1.xcconfig = { 'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/YYMediaFoundation/libs/YYMediaFoundation.framework/Headers', 'LD_RUNPATH_SEARCH_PATHS' => '@loader_path/../Frameworks' }
    end

    s.subspec 'YYMediaFoundationStatic' do |s2|
        s2.dependency 'audioenginesdk/yyaudiodynamicsdk', '2.8.105'
s2.dependency 'avtoolkit/avtoolkitStatic', '1.2.0'
s2.dependency 'orangefilter/orangefilter_static-all_no_ar', '4.5.4'
s2.dependency 'venus/venus-all-ncv', '1.8.7'
        s2.libraries = 'c++', 'objc'
        s2.source_files = 'include/YYMediaFoundationStatic/*.h'
        s2.vendored_library = 'libs/libYYMediaFoundationStatic.a'
        s2.xcconfig = { 'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/YYMediaFoundation/include', 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/YYMediaFoundation/libs"' }
    end
end