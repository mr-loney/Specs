Pod::Spec.new do |s|
    s.version = '1.0.0'
    s.authors = { 'Your Company' => 'email@example.com' }
    s.license  = {:type => 'BSD-licensed'}
    s.summary = 'A media library for iOS'
   
    s.platform = :ios
    s.ios.deployment_target = '9.0'
    s.requires_arc = true
    s.homepage         = 'http://example.com'
    s.frameworks = 'AVFoundation', 'Foundation', 'CoreMotion', 'Accelerate', 'CoreMedia'
    s.libraries = 'c++', 'objc'
    
    s.name = 'camerasdk'
    # s.prefix_header_file = "#{s.name}/#{s.name}.pch"
    # s.source_files = "#{s.name}/#{s.name}.pch", "#{s.name}/#{s.name}-Info.plist", "#{s.name}/**/*.{h,m,mm,c}"
    # s.public_header_files = "#{s.name}/*.h", "#{s.name}/**/*.h"
    s.xcconfig = { 'OTHER_LDFLAGS' => "-force_load $(BUILT_PRODUCTS_DIR)/#{s.name}/lib#{s.name}.a" }
    s.source_files   = 'include/**/*.h'
    s.ios.vendored_libraries = 'libs/*.a'

    s.script_phase = {
      :execution_position => :before_compile,
      :name => 'clang-format',
      :script => <<-CLANG
      
      cd ${PODS_TARGET_SRCROOT}

      if [ ! -f ./_clang-format ];then
          echo "skip clang-format"
          exit 0
      fi

      ./clang-format -version >/dev/null 2>&1

      if [ $? != 0 ]; then
          echo "clang-format not found"
          exit 0
      fi


      PROJECT_PREFIX="MFD"



      find . -name "${PROJECT_PREFIX}*.h" | xargs ./clang-format -i -style=file
      find . -name "${PROJECT_PREFIX}*.m" | xargs ./clang-format -i -style=file
      find . -name "${PROJECT_PREFIX}*.mm" | xargs ./clang-format -i -style=file


      PROJECT_PREFIX="ATH"
      find . -name "${PROJECT_PREFIX}*.h" | xargs ./clang-format -i -style=file
      find . -name "${PROJECT_PREFIX}*.m" | xargs ./clang-format -i -style=file
      find . -name "${PROJECT_PREFIX}*.mm" | xargs ./clang-format -i -style=file
      
      CLANG
    }
    

    s.source = { :http => "ftp:///Users/pengjun/Documents/money/ios_sdk/camerasdk.zip" }
    

    # s.dependency 'audioenginesdk/yyaudiodynamicsdk'#, :path => '/Users/pengjun/Documents/money/ios_sdk/*****.zip'
    s.dependency 'avtoolkit/avtoolkitStatic'#, :path => '/Users/pengjun/Documents/money/ios_sdk/avtoolkit.podspec'
    s.dependency 'orangefilter/orangefilter_static-all_no_ar'#, :path => '/Users/pengjun/Documents/money/ios_sdk/orangefilter.podspec'
    s.dependency 'venus/venus-all-static'#, :path => '/Users/pengjun/Documents/money/ios_sdk/VNN.podspec'
    # s.dependency 'athvideosourceprotocol'#, :path => '/Users/pengjun/Documents/money/ios_sdk/*****.zip'
end
