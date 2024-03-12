Pod::Spec.new do |s|
  s.name         = "openssl"
  s.version      = "1.0.2"
  s.summary      = "openssl library"
  s.homepage     = "https://www.openssl.org"
  s.license      = "OpenSSL License"
  s.author       = "The OpenSSL Project"
  s.source       = {:http => "https://p-template-hk.oss-cn-hongkong.aliyuncs.com/ios_sdk/openssl-dynamic.zip"}

  # s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  # s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.platform     = :ios, '4.3'
  s.ios.deployment_target = '4.3'
  s.requires_arc = true
  s.source_files = 'include/**/*.h'
  s.header_mappings_dir = './include'
  s.preserve_paths = 'lib/*.a'

  s.libraries = 'crypto', 'ssl'
  s.vendored_libraries = 'lib/libcrypto.a', 'lib/libssl.a'
  
  $dir = File.dirname(__FILE__)
  s.xcconfig = { 'LIBRARY_SEARCH_PATHS' => '"${PODS_ROOT}/openssl/lib"'}
  
end
