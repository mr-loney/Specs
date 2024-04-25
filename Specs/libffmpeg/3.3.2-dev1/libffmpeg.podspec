Pod::Spec.new do |s|

	s.name         = "libffmpeg"
	s.version      = "3.3.2-dev1"
	s.summary      = "A iOS perbuilt lib for ffmpeg."
	s.license      = {:type => 'LGPL v2.1+'}
	s.homepage     = "http://www.ffmpeg.org/"

	s.author       = { 'Your Company' => 'email@example.com'}

	s.source       = {:http =>"https://p-template-hk.oss-cn-hongkong.aliyuncs.com/macos_sdk/libffmpeg.zip"}

	ios_frameworks		=	'CoreMedia','CoreVideo','VideoToolbox'
	macos_frameworks 	=	'CoreMedia','CoreVideo','VideoToolbox'
	s.default_subspec = 'ffmpeg-static-macOS'

	s.subspec 'ffmpeg-static-macOS' do |sp|
		sp.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/libffmpeg/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/libffmpeg/libs" }
		sp.frameworks     = 'VideoToolbox'
		sp.source_files   = 'include/**/*.h'
		sp.header_mappings_dir = 'include'
		sp.vendored_libraries = 'libs/*.a'
		sp.preserve_paths = 'libs/*.a'
		sp.libraries = 'avcodec', 'avdevice', 'avfilter', 'avformat', 'avresample', 'avutil', 'postproc', 'swresample', 'swscale', 'x264'
	end

end
