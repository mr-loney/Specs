Pod::Spec.new do |s|

	s.name         = "ffmpeg"
	s.version      = "1.0.2"
	s.summary      = "A iOS perbuilt lib for ffmpeg."
	s.license      = {:type => 'LGPL v2.1+'}
	s.homepage     = "http://www.ffmpeg.org/"

	s.author       = { 'Your Company' => 'email@example.com'}

	# s.source       = {:http =>"file://https://p-template-hk.oss-cn-hongkong.aliyuncs.com/ios_sdk/ffmpeg-neon.zip"}
	s.source       = {:http =>"https://p-template-hk.oss-cn-hongkong.aliyuncs.com/ios_sdk/ffmpeg-neon.zip"}

	# s.default_subspec = 'ffmpeg-0.8.7'
  
  	# s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
	# s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
	# s.default_subspec = 'ffmpeg-0.8.7'
  	s.platform  = :ios

  $dir = File.dirname(__FILE__)
  
	# s.subspec 'ffmpeg-0.8.7' do |ss|
 	# 	ss.source_files = 'include/**/*.h'
    # 		ss.preserve_paths = 'libs/**/*.a'
	#   	ss.libraries = 'x264', 'avcodec',  'avformat', 'avutil', 'swscale'
	# end

	# s.subspec 'ffmpeg-ac' do |ss|
	# 	ss.source_files		= 'include/**/*.h'
	# 	ss.public_header_files = 'include/**/*.h'
	# 	ss.header_mappings_dir = 'include'
	# 	ss.vendored_libraries = 'libs/**/*.a'
	# 	ss.libraries = 'avcodec', 'avdevice', 'avfilter', 'avformat', 'avutil', 'swresample', 'swscale'
	# end
	# s.subspec 'ffmpeg-271-ios' do |ss|
	# 	ss.source_files		= 'include/**/*.h','include/*.h'
	# 	ss.public_header_files = 'include/libyympeg_x264_version.h'
	# 	ss.header_mappings_dir = 'include'
	# 	ss.vendored_libraries = 'libs/**/*.a'
	# 	ss.libraries = 'x264', 'yympeg'
	# end
	# s.subspec 'ffmpeg-271-x264optim' do |ss|
	# 	ss.source_files		= 'include/**/*.h','include/*.h'
	# 	ss.public_header_files = 'include/libyympeg_x264_version.h'
	# 	ss.header_mappings_dir = 'include'
	# 	ss.vendored_libraries = 'libs/**/*.a'
	# 	ss.libraries = 'x264', 'yympeg'
	# end
	s.subspec 'ffmpeg-332-ios' do |ss|
    ss.xcconfig = { 'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/ffmpeg/include', 'LIBRARY_SEARCH_PATHS' => '"${PODS_ROOT}/ffmpeg/libs"' }
		ss.source_files		= 'include/**/*.h','include/*.h'
#		ss.public_header_files = 'include/**/*.h','include/*.h' #'include/libyympeg_x264_version.h'
		ss.header_mappings_dir = 'include'
		ss.vendored_libraries = 'libs/**/libx264.a','libs/**/libyympeg.a'
		ss.libraries = 'x264', 'yympeg'
	end
end
