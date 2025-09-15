Pod::Spec.new do |s|
        s.name     = "orangefilter_macos"
        s.version  = "1.0-20250915-031744"
        s.summary  = "A iOS and macOS perbuilt lib for orangefilter."
        s.license  = {:type => 'BSD-licensed'}
        s.homepage = "http://www.sunsetlakesoftware.com"
        s.author   = { 'Your Company' => 'email@example.com' }

        s.source   = {:http =>"https://p-template-hk.oss-cn-hongkong.aliyuncs.com/macos_sdk/orangefilter/orangefilter_1.0_20250915_031744.zip"}

        ios_frameworks   = 'CoreMedia','CoreVideo','OpenGLES','QuartzCore','AVFoundation','UIKit','Foundation','CoreGraphics','CoreImage','GLKit'
        macos_frameworks = 'CoreMedia','CoreVideo','QuartzCore','AVFoundation','Foundation','CoreGraphics','CoreImage','OpenGL','GLUT'
        
        s.default_subspec = 'orangefilter-all-revision'

        s.subspec 'orangefilter-core' do |sdc|
                sdc.frameworks     = ios_frameworks
                sdc.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LD_RUNPATH_SEARCH_PATHS' => '@loader_path/../Frameworks'}
                sdc.source_files   = 'include/**/*.h'
                sdc.preserve_paths = 'libs/**/*.framework'
                sdc.ios.vendored_frameworks = 'libs/zlib.framework', 'libs/libpng.framework', 'libs/opencv.framework', 'libs/of_effect.framework', 'libs/of_pose.framework', 'libs/of_core.framework'
        end
        
        s.subspec 'orangefilter-core-revision' do |sdcr|
                sdcr.frameworks     = ios_frameworks
                sdcr.libraries      = 'z.1.2.5'
                sdcr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LD_RUNPATH_SEARCH_PATHS' => '@loader_path/../Frameworks'}
                sdcr.source_files   = 'include/**/*.h'
                sdcr.preserve_paths = 'libs/**/*.framework'
                sdcr.ios.vendored_frameworks = 'libs/zlib.framework', 'libs/opencv.framework', 'libs/of_effect.framework', 'libs/of_pose.framework', 'libs/of_core.framework'
        end

        s.subspec 'orangefilter-all_no_ar' do |sdan|
                sdan.frameworks     = ios_frameworks
                sdan.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LD_RUNPATH_SEARCH_PATHS' => '@loader_path/../Frameworks'}
                sdan.source_files   = 'include/**/*.h'
                sdan.preserve_paths = 'libs/**/*.framework'
                sdan.ios.vendored_frameworks = 'libs/zlib.framework', 'libs/libpng.framework', 'libs/opencv.framework', 'libs/of_effect.framework', 'libs/of_pose.framework', 'libs/of_core.framework', 'libs/facedancegame.framework', 'libs/ardancegame.framework', 'libs/of_avatar.framework' 
        end
        
        s.subspec 'orangefilter-all_no_ar-revision' do |sdanr|
                sdanr.frameworks     = ios_frameworks
                sdanr.libraries      = 'z.1.2.5'
                sdanr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LD_RUNPATH_SEARCH_PATHS' => '@loader_path/../Frameworks'}
                sdanr.source_files   = 'include/**/*.h'
                sdanr.preserve_paths = 'libs/**/*.framework'
                sdanr.ios.vendored_frameworks = 'libs/zlib.framework', 'libs/opencv.framework', 'libs/of_effect.framework', 'libs/of_pose.framework', 'libs/of_core.framework', 'libs/facedancegame.framework', 'libs/ardancegame.framework', 'libs/of_avatar.framework' 
        end

        s.subspec 'orangefilter-all' do |sda|
                sda.frameworks     = ios_frameworks
                sda.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LD_RUNPATH_SEARCH_PATHS' => '@loader_path/../Frameworks'}
                sda.source_files   = 'include/**/*.h'
                sda.exclude_files  = 'libs/**/*_macOS.framework'
                sda.preserve_paths = 'libs/**/*.framework'
                sda.ios.vendored_frameworks = 'libs/*.framework'
        end
        
        s.subspec 'orangefilter-all-revision' do |sdar|
                sdar.frameworks     = ios_frameworks
                sdar.libraries      = 'z.1.2.5'
                sdar.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LD_RUNPATH_SEARCH_PATHS' => '@loader_path/../Frameworks'}
                sdar.source_files   = 'include/**/*.h'
                sdar.exclude_files  = 'libs/**/*_macOS.framework'
                sdar.preserve_paths = 'libs/**/*.framework'
                sdar.ios.vendored_frameworks = 'libs/*.framework'
        end
		
		s.subspec 'orangefilter_static-core-lite' do |sscl|
                sscl.frameworks     = ios_frameworks
                sscl.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                sscl.source_files   = 'include/**/*.h'
                sscl.preserve_paths = 'libs/**/*.a'
                sscl.ios.vendored_libraries = 'libs/libof_core_static.a', 'libs/libpng_static.a', 'libs/libzlib_static.a', 'libs/libopencv_static.a', 'libs/libof_effect_static.a', 'libs/libof_pose_static.a'
        end
        
        s.subspec 'orangefilter_static-core-lite-revision' do |ssclr|
                ssclr.frameworks     = ios_frameworks
                ssclr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssclr.source_files   = 'include/**/*.h'
                ssclr.preserve_paths = 'libs/**/*.a'
                ssclr.libraries = 'z.1.2.5'
                ssclr.ios.vendored_libraries = 'libs/libof_core_static.a', 'libs/libzlib_static.a', 'libs/libopencv_static.a', 'libs/libof_effect_static.a', 'libs/libof_pose_static.a'
        end
        
        s.subspec 'orangefilter_static-core' do |ssc|
                ssc.frameworks     = ios_frameworks
                ssc.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssc.source_files   = 'include/**/*.h'
                ssc.preserve_paths = 'libs/**/*.a'
                ssc.ios.vendored_libraries = 'libs/libof_core_static.a', 'libs/libpng_static.a', 'libs/libzlib_static.a', 'libs/libopencv_static.a', 'libs/libof_effect_static.a', 'libs/libof_pose_static.a', 'libs/libbullet.a', 'libs/liblua.a', 'libs/libvpx.a', 'libs/libfreetype.a'
        end
        
        s.subspec 'orangefilter_static-core-revision' do |sscr|
                sscr.frameworks     = ios_frameworks
                sscr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                sscr.source_files   = 'include/**/*.h'
                sscr.preserve_paths = 'libs/**/*.a'
                sscr.libraries = 'z.1.2.5'
                sscr.ios.vendored_libraries = 'libs/libof_core_static.a', 'libs/libzlib_static.a', 'libs/libopencv_static.a', 'libs/libof_effect_static.a', 'libs/libof_pose_static.a', 'libs/libbullet.a', 'libs/liblua.a', 'libs/libfreetype.a'
        end
        
        s.subspec 'orangefilter_static-meipai-core' do |ssmc|
                ssmc.frameworks     = ios_frameworks
                ssmc.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssmc.source_files   = 'include/**/*.h'
                ssmc.preserve_paths = 'libs/**/*.a'
                ssmc.ios.vendored_libraries = 'libs/libof_core_static.a', 'libs/libpng_static.a', 'libs/libzlib_static.a', 'libs/libopencv_static.a', 'libs/libof_effect_static.a', 'libs/libof_pose_static.a', 'libs/liblua.a'
        end
        
        s.subspec 'orangefilter_static-meipai-core-revision' do |ssmcr|
                ssmcr.frameworks     = ios_frameworks
                ssmcr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssmcr.source_files   = 'include/**/*.h'
                ssmcr.preserve_paths = 'libs/**/*.a'
                ssmcr.libraries = 'z.1.2.5'
                ssmcr.ios.vendored_libraries = 'libs/libof_core_static.a', 'libs/libzlib_static.a', 'libs/libopencv_static.a', 'libs/libof_effect_static.a', 'libs/libof_pose_static.a', 'libs/liblua.a'
        end

        s.subspec 'orangefilter_static-baidu-core-revision' do |ssmcr|
                ssmcr.frameworks     = ios_frameworks
                ssmcr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssmcr.source_files   = 'include/**/*.h'
                ssmcr.preserve_paths = 'libs/**/*.a'
                ssmcr.libraries = 'z.1.2.5'
                ssmcr.ios.vendored_libraries = 'libs/libof_core_static.a', 'libs/libzlib_static.a', 'libs/libopencv_static.a', 'libs/libof_effect_static.a', 'libs/libof_pose_static.a', 'libs/liblua.a'
        end

        s.subspec 'orangefilter_static-baidu-revision' do |ssmcr|
                ssmcr.frameworks     = ios_frameworks
                ssmcr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssmcr.source_files   = 'include/**/*.h'
                ssmcr.preserve_paths = 'libs/**/*.a'
                ssmcr.libraries = 'z.1.2.5'
                ssmcr.ios.vendored_libraries = 'libs/liborangefilter.a'
        end

        s.subspec 'orangefilter_static-baidu-cv-revision' do |ssmcr|
                ssmcr.frameworks     = ios_frameworks
                ssmcr.dependency  'baiduopencv'
                ssmcr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssmcr.source_files   = 'include/**/*.h'
                ssmcr.preserve_paths = 'libs/**/*.a'
                ssmcr.libraries = 'z.1.2.5'
                ssmcr.ios.vendored_libraries = 'libs/liborangefilter.a'
        end

        s.subspec 'orangefilter_static-yy-revision' do |ssmcr|
                ssmcr.frameworks     = ios_frameworks
                ssmcr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssmcr.source_files   = 'include/**/*.h'
                ssmcr.preserve_paths = 'libs/**/*.a'
                ssmcr.libraries = 'z.1.2.5'
                ssmcr.ios.vendored_libraries = 'libs/liborangefilter.a'
        end
        
        s.subspec 'orangefilter_static-all_no_ar' do |ssan|
                ssan.frameworks     = ios_frameworks
                ssan.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssan.source_files   = 'include/**/*.h'
                ssan.preserve_paths = 'libs/**/*.a'
                ssan.ios.vendored_libraries = 'libs/libof_core_static.a', 'libs/libpng_static.a', 'libs/libzlib_static.a', 'libs/libopencv_static.a', 'libs/libof_effect_static.a', 'libs/libof_pose_static.a', 'libs/libbullet.a', 'libs/liblua.a', 'libs/libvpx.a', 'libs/libfacedancegame_static.a', 'libs/libardancegame_static.a', 'libs/libfreetype.a', 'libs/libof_avatar_static.a'
        end
        
        s.subspec 'orangefilter_static-all_no_ar-revision' do |ssanr|
                ssanr.frameworks     = ios_frameworks
                ssanr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssanr.source_files   = 'include/**/*.h'
                ssanr.preserve_paths = 'libs/**/*.a'
                ssanr.libraries = 'z.1.2.5'
                ssanr.ios.vendored_libraries = 'libs/libof_core_static.a', 'libs/libzlib_static.a', 'libs/libopencv_static.a', 'libs/libof_effect_static.a', 'libs/libof_pose_static.a', 'libs/libbullet.a', 'libs/liblua.a', 'libs/libfacedancegame_static.a', 'libs/libardancegame_static.a', 'libs/libfreetype.a', 'libs/libof_avatar_static.a'
        end
        
        s.subspec 'orangefilter_static-all_no_ar_no_webp' do |ssnanw|
                ssnanw.frameworks     = ios_frameworks
                ssnanw.dependency  'Webp-YY'
                ssnanw.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssnanw.source_files   = 'include/**/*.h'
                ssnanw.preserve_paths = 'libs/**/*.a'
                ssnanw.ios.vendored_libraries = 'libs/libof_core_static.a', 'libs/libpng_static.a', 'libs/libzlib_static.a', 'libs/libopencv_static.a', 'libs/libof_effect_static.a', 'libs/libof_pose_static.a', 'libs/libbullet.a', 'libs/liblua.a', 'libs/libvpx.a', 'libs/libfacedancegame_static.a', 'libs/libardancegame_static.a', 'libs/libfreetype.a'
        end
        
        s.subspec 'orangefilter_static-all_no_ar_no_webp-revision' do |ssnanwr|
                ssnanwr.frameworks     = ios_frameworks
                ssnanwr.dependency  'Webp-YY'
                ssnanwr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssnanwr.source_files   = 'include/**/*.h'
                ssnanwr.preserve_paths = 'libs/**/*.a'
                ssnanwr.libraries = 'z.1.2.5'
                ssnanwr.ios.vendored_libraries = 'libs/libof_core_static.a', 'libs/libzlib_static.a', 'libs/libopencv_static.a', 'libs/libof_effect_static.a', 'libs/libof_pose_static.a', 'libs/libbullet.a', 'libs/liblua.a', 'libs/libfacedancegame_static.a', 'libs/libardancegame_static.a', 'libs/libfreetype.a'
        end

        s.subspec 'orangefilter_static-all' do |ssa|
                ssa.frameworks     = ios_frameworks
                ssa.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssa.source_files   = 'include/**/*.h'
                ssa.exclude_files  = 'libs/**/*_macOS.a'
                ssa.preserve_paths = 'libs/**/*.a'
                ssa.ios.vendored_libraries = 'libs/*.a'
        end
        
        s.subspec 'orangefilter_static-all-revision' do |ssar|
                ssar.frameworks     = ios_frameworks
                ssar.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs" }
                ssar.source_files   = 'include/**/*.h'
                ssar.exclude_files  = 'libs/**/*_macOS.a'
                ssar.preserve_paths = 'libs/**/*.a'
                ssar.libraries = 'z.1.2.5'
                ssar.ios.vendored_libraries = 'libs/*.a'
        end

        s.subspec 'orangefilter-all-macOS' do |oam|
                oam.frameworks     = macos_frameworks
                oam.platform       = :osx, '10.9'
                oam.osx.deployment_target = '10.9'
                oam.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LD_RUNPATH_SEARCH_PATHS' => '@loader_path/../Frameworks'}
                oam.source_files   = 'include/**/*.h'
                oam.preserve_paths = 'libs/**/*_macOS.framework'
                oam.osx.vendored_frameworks = 'libs/*_macOS.framework'
        end
        
        s.subspec 'orangefilter-all-macOS-revision' do |oamr|
                oamr.frameworks     = macos_frameworks
                oamr.libraries      = 'z.1.2.5'
                oamr.platform       = :osx, '10.9'
                oamr.osx.deployment_target = '10.9'
                oamr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LD_RUNPATH_SEARCH_PATHS' => '@loader_path/../Frameworks'}
                oamr.source_files   = 'include/**/*.h'
                oamr.preserve_paths = 'libs/**/*_macOS.framework'
                oamr.osx.vendored_frameworks = 'libs/*_macOS.framework'
        end

        s.subspec 'orangefilter_static-all-macOS' do |osam|
                osam.frameworks     = macos_frameworks
                osam.platform       = :osx, '10.9'
                osam.osx.deployment_target = '10.9'
                osam.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs"}
                osam.source_files   = 'include/**/*.h'
                osam.preserve_paths = 'libs/**/*_macOS.a'
                osam.osx.vendored_libraries = 'libs/*_macOS.a'
        end
        
        s.subspec 'orangefilter_static-all-macOS-revision' do |osamr|
                osamr.frameworks     = macos_frameworks
                osamr.platform       = :osx, '10.9'
                osamr.osx.deployment_target = '10.9'
                osamr.xcconfig       = {'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/orangefilter/include','LIBRARY_SEARCH_PATHS' => "${PODS_ROOT}/orangefilter/libs"}
                osamr.source_files   = 'include/**/*.h'
                osamr.preserve_paths = 'libs/**/*_macOS.a'
                osamr.libraries = 'z.1.2.5'
                osamr.osx.vendored_libraries = 'libs/*_macOS.a'
        end
end
