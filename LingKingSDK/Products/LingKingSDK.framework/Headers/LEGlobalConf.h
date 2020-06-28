//
//  LEGlobalConf.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/11.
//  Copyright © 2020 leaon jason All rights reserved.
//

#ifndef LEGlobalConf_h
#define LEGlobalConf_h

// https://jsonconfig.chiji-h5.com/json/QMSCSAPP/config.json
// SDK 启动配置类 https://jsonconfig.chiji-h5.com/json/qddshell/iosTestSdk.json
// https://jsonconfig.chiji-h5.com/json/QMSCSAPP/iosconfig.json
//http://lk-hkres.chiji-h5.com/tech/qmscsapp/iosconfig.json
// http://lk-hkres.oss-cn-hongkong.aliyuncs.com/tech/qmscsapp/ios/matrix_config_zh.json
//#define SDKConfBaseURL  @"http://lk-hkres.chiji-h5.com"
//#define SDKConfApi @"/tech/qmscsapp/iosconfig.json"
//#define SDKConfMatrix @"/tech/qmscsapp/ios/matrix_config_zh.json"

#define SDKConfBaseURL  @"http://lk-hkres.oss-cn-hongkong.aliyuncs.com"
#define SDKConfPrefix @"/bgsys/matrix"
#define SDKConfApi @"/tech/qmscsapp/iosconfig.json"
#define SDKConfMatrix @"/tech/qmscsapp/ios/matrix_config_zh.json"
// 数据存入沙盒的key
#define SDKCONFKEY @"SDKCONF"
#define SYSTEMSDKKEY  @"SYSTEMSDK"
#define USERKEY    @"USER"

////屏宽
//#define kScreen_LE_Width \
//([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.width)
////屏高
//#define kScreen_LE_Height \
//([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.height)
////屏的size(宽、高)
//#define kScreen_LE_Size \
//([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale) : [UIScreen mainScreen].bounds.size)

//#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000 // 当前Xcode支持iOS8及以上
//#define kScreen_LE_Width ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.width)
//#define kScreen_LE_Height ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.height)
//#define kScreen_LE_Size ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale):[UIScreen mainScreen].bounds.size)
//#else
//#define kScreen_LE_Width [UIScreen mainScreen].bounds.size.width
//#define kScreen_LE_Height [UIScreen mainScreen].bounds.size.height
//#define kScreen_LE_Size [UIScreen mainScreen].bounds.size
//#endif
#define kScreen_LE_Width [UIScreen mainScreen].bounds.size.width
#define kScreen_LE_Height [UIScreen mainScreen].bounds.size.height
#define kScreen_LE_Size [UIScreen mainScreen].bounds.size



// 屏幕分辨率 resolution
#define kScreen_Resolution (SCREEN_WIDTH * SCREEN_HEIGHT * ([UIScreen mainScreen].scale))

// iPhone X系列判断
#define  kIS_iPhoneX (CGSizeEqualToSize(CGSizeMake(375.f, 812.f), [UIScreen mainScreen].bounds.size) || CGSizeEqualToSize(CGSizeMake(812.f, 375.f), [UIScreen mainScreen].bounds.size)  || CGSizeEqualToSize(CGSizeMake(414.f, 896.f), [UIScreen mainScreen].bounds.size) || CGSizeEqualToSize(CGSizeMake(896.f, 414.f), [UIScreen mainScreen].bounds.size))
// 状态栏高度
#define kStatusBarHeight (kIS_iPhoneX ? 44.f : 20.f)
// 导航栏高度
#define kNavBarHeight (44.f+StatusBarHeight)
// 底部标签栏高度
#define kTabBarHeight (kIS_iPhoneX ? (49.f+34.f) : 49.f)
// 安全区域高度
#define kTabbarSafeBottomMargin (kIS_iPhoneX ? 34.f : 0.f)

#endif /* LEGlobalConf_h */
