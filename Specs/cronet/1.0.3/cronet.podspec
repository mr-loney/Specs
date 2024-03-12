# zipfile = "#{__dir__}/framework/Cronet.zip"

Pod::Spec.new do |spec|

  spec.name         = "cronet"
  spec.version      = "1.0.3"
  spec.summary      = "chrome network lib"

  spec.license = {:type => 'MIT-licensed'} 
  spec.homepage         = 'http://example.com'
  spec.description  = "chrome network lib" 
  spec.author       = { 'Your Company' => 'email@example.com' }
  spec.ios.deployment_target = "9.0"

  spec.source       = { :http => "ftp:///Users/pengjun/Documents/money/ios_sdk/Cronet.zip"}
  # spec.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 x86_64' }
  # spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 x86_64' }
  # system("echo cronet")
  # system("rm -rf #{__dir__}/Cronet && unzip -o #{zipfile} > /dev/null")  

  spec.vendored_frameworks = "Cronet.framework"
  spec.requires_arc = true
  spec.source_files = 'Cronet.framework/Headers/*.h'

end
