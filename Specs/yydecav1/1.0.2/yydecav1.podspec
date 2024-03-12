Pod::Spec.new do |s|

	s.name         = "yydecav1"
	s.version      = "1.0.2"
	s.summary      = "YY av1 decoder"
	s.license      = {:type => 'Apache License, version 2.0'}
	s.author       = { 'Your Company' => 'email@example.com' }
	s.homepage         = 'http://example.com'
	s.source       = {:http => "file://https://p-template-hk.oss-cn-hongkong.aliyuncs.com/ios_sdk/decav1.zip"}
  	
  	# s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
	# s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  	s.platform  = :ios
  
	s.xcconfig = { 'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/yydecav1/include', 'LIBRARY_SEARCH_PATHS' => '"${PODS_ROOT}/yydecav1/libs"' }

	s.source_files		= 'include/**/*.h','include/*.h'
	s.header_mappings_dir = 'include'
	s.vendored_library = 'libs/libyydecav1.a'
	s.library = 'yydecav1'
end
