#
#  Be sure to run `pod spec lint GravityEngineSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|
  spec.name         = "GravityEngineSDK"
  spec.version      = "5.0.12"
  spec.summary      = "用于用户行为分析和广告效果归因的一站式SDK。"
  spec.description  = <<-DESC
  引力引擎 SDK 支持代码埋点以及全埋点（无埋点）两种埋点方式来收集广告主App内的各种事件，进而完成广告效果归因和用户行为分析，助力广告主准确做出商业决策。
                   DESC
  spec.homepage     = "https://github.com/GravityInfinite/ios-sdk-release"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author             = { "GravityEngine" => "pony@gravity-engine.com" }
  spec.source       = { :git => "https://github.com/GravityInfinite/ios-sdk-release.git", :tag => spec.version.to_s }

  spec.platform     = :ios, "11.0"
  spec.swift_version = "5.0"
  spec.vendored_frameworks = "GravityEngineSDK.xcframework"
  spec.frameworks = 'AppTrackingTransparency', 'SystemConfiguration', 'AdServices', 'Security', 'AdSupport', "iAd", "CoreTelephony"
  spec.libraries = "sqlite3", "z"
  spec.requires_arc  = true
end
