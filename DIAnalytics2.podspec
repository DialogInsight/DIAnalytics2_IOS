Pod::Spec.new do |s|
  s.name             = 'DIAnalytics2'
  s.version          = '0.1.14'
  s.summary          = 'DIAnalytics2 for iOS'
  s.license          = { :type => 'Commercial', :file => 'LICENSE.txt' }
  s.description      = 'DIAnalytics2 makes it easy to integrate Dialog Insight push system in your application.'
  s.homepage         = 'http://www.dialoginsight.com'
  s.author           = { 'Dialog Insight' => 'info@dialoginsight.com' }
  s.source           = { :git => 'https://github.com/DialogInsight/DIAnalytics2_iOS.git', :tag => s.version.to_s }
  s.requires_arc     = true

  s.platform   = :ios, '9.0'
  s.ios.deployment_target = '9.0'
  # s.frameworks = 'Foundation','CoreTelephony', 'SystemConfiguration', 'UIKit', 'Security', 'StoreKit'
  s.vendored_framework = "DIAnalytics2.Framework"

  s.dependency 'AFNetworking', '~> 4.0'
  s.dependency 'Firebase/Core'
  s.dependency 'Firebase/Messaging'
end
