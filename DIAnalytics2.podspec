Pod::Spec.new do |s|
  s.name = "DIAnalytics2"
  s.version = "0.1.14"
  s.summary = "DIAnalytics2 for iOS"
  s.license = {"type"=>"Commercial", "file"=>"LICENSE.txt"}
  s.authors = {"Dialog Insight"=>"info@dialoginsight.com"}
  s.homepage = "https://www.dialoginsight.com"
  s.description = "DIAnalytics makes it easy to integrate Dialog Insight push system in your application."
  s.source = { :path => '.' }

  s.ios.deployment_target    = '9.0'
  s.ios.vendored_framework   = 'ios/DIAnalytics2.framework'
end
