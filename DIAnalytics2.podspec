Pod::Spec.new do |s|
  s.name = "DIAnalytics2"
  s.version = "0.1.20"
  s.summary = "DIAnalytics2 for iOS"
  s.license = {"type"=>"Commercial", "file"=>"LICENSE.txt"}
  s.authors = {"Dialog Insight"=>"info@dialoginsight.com"}
  s.homepage = "https://www.dialoginsight.com"
  s.description = "DIAnalytics makes it easy to integrate Dialog Insight push system in your application."
  s.source = { :git => 'https://github.com/DialogInsight/DIAnalytics2_iOS.git', :tag => s.version.to_s }

  s.requires_arc     = true
  s.platform = :ios, "9.0"
  s.ios.deployment_target    = '9.0'
  s.ios.vendored_framework   = 'ios/DIAnalytics2.framework'

  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

  s.static_framework = true
  s.frameworks = 'Foundation', 'CoreGraphics', 'UIKit', 'StoreKit', 'WebKit', 'MobileCoreServices', 'CoreServices'

  s.dependency 'AFNetworking', '~> 4.0'
  s.dependency 'Firebase/Core', '~> 6.0'
  s.dependency 'Firebase/Messaging', '~> 6.0'
end
