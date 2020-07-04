#
# Be sure to run `pod lib lint LingKingSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'LingKingSDK'
  s.version          = '0.1.40'
  s.summary          = 'A short description of LingKingSDK.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: LingKingSDK is Overseas SDK Quick Integration Solution.
                       DESC

  s.homepage         = 'https://github.com/MrDML/LingKingSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'leaon' => 'leaon' }
  s.source           = { :git => 'https://github.com/MrDML/LingKingSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
  
  s.static_framework = true


  s.vendored_frameworks = "LingKingSDK/Products/LingKingSDK.framework"
  s.resources = "LingKingSDK/Assets/*.*"
  s.dependency 'GoogleSignIn', '~> 5.0.2'
  s.dependency 'Firebase/Auth'
  s.dependency 'FBSDKLoginKit', '~> 6.3.0'
  s.dependency 'FBSDKShareKit', '~> 6.3.0'
  s.dependency 'AppsFlyerFramework', '~> 5.2.0'
  s.dependency 'FBAudienceNetwork', '~> 5.7.1' # 需要ios9.0 以上
  s.dependency 'Google-Mobile-Ads-SDK', '~> 7.56.0'
  s.dependency 'IronSourceSDK', '~> 6.16.1.0'
  s.dependency 'Bytedance-UnionAD', '~> 2.9.5.8'
  s.dependency 'Bugly', '~> 2.5.2'
  s.dependency 'SDWebImage', '>= 5.0.0'
  s.xcconfig = {
      'VALID_ARCHS' =>  'arm64 x86_64 armv7',
  }
  # s.resource_bundles = {
  #   'LingKingSDK' => ['LingKingSDK/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
