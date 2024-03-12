Pod::Spec.new do |s|

	s.name         = "libyuv"
	s.version      = "1.0.2"
	s.summary      = "Open libyuv library for sdk."
	s.homepage     = "http://libyuv.googlecode.com/svn/trunk/"
	s.license      = {:type => 'BSD'}
    s.author       = { 'Your Company' => 'email@example.com'}
	s.source       = {:http => "ftp:///Users/pengjun/Documents/money/ios_sdk/libyuv.zip"}
    # s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 x86_64' }
    # s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 x86_64' }
	s.xcconfig = { 'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/libyuv/include', 'LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/libyuv/libs" }

    s.source_files      = 'include/**/*.h','include/*.h'
    s.header_mappings_dir = 'include'
    s.vendored_library = 'libs/libyuv.a'
    s.library = 'yuv'
    s.default_subspec = 'libyuv-common'

    s.platform  = :ios

    s.subspec 'libyuv-common' do |sc|
                sc.source_files        = 'include/libyuv/*.h','include/*.h'
                sc.public_header_files = 'include/libyuv/*.h','include/*.h'
                sc.header_mappings_dir = 'include'
                sc.vendored_libraries = 'libs/libyuv.a'
                sc.libraries = 'yuv'
    end

    s.subspec 'libyuv-bd' do |sbd|
            sbd.source_files        = 'include/libyuv_disable_bitcode/include/libyuv/*.h', 'include/libyuv_disable_bitcode/include/*.h'
            sbd.public_header_files = 'include/libyuv_disable_bitcode/include/libyuv/*.h', 'include/libyuv_disable_bitcode/include/*.h'
            sbd.header_mappings_dir = 'include'
            sbd.vendored_libraries = 'libs/libyuv_neon.a','libs/libyuv_internal.a'
            sbd.libraries = 'yuv_neon','yuv_internal'
    end
end
