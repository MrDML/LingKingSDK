//
//  LESDKConf.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/11.
//  Copyright © 2020 leaon jason All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LESDKConf : NSObject<NSCoding>
- (instancetype)initWithDictonary:(NSDictionary *)dict;
@property(nonatomic, copy) NSString        *pay_type;
@property(nonatomic, copy) NSString        *ready_type;
@property(nonatomic, copy) NSString        *mode_debug;
@property(nonatomic, strong) NSDictionary  *sdk_config;
@property(nonatomic, strong) NSDictionary  *auth_config;
@property(nonatomic, strong) NSDictionary  *point_config;
@property(nonatomic, strong) NSDictionary  *ad_config_ios;
@property(nonatomic, strong) NSDictionary  *pay_config;
@property(nonatomic, strong) NSDictionary  *share_info;
//@property(nonatomic, copy)NSString         *BASE_SER_URL;
//@property(nonatomic, copy)NSString         *APPID_URL;
//@property(nonatomic, copy) NSString        *APP_ID;
//@property(nonatomic, copy) NSString        *APP_RELEASE_CHANNEL;
//@property(nonatomic, copy) NSString        *APP_PACKAGE_NAME;
//@property(nonatomic, copy) NSString        *APP_CLASS_NAME;
//@property(nonatomic, strong) NSArray       *APP_CURRENCIES;
//@property(nonatomic, copy) NSString        *APP_CDN_PATH;
//@property(nonatomic, copy) NSString        *AUTH_GUEST_URI;
//@property(nonatomic, copy) NSString        *AUTH_FB_URI;
//@property(nonatomic, copy) NSString        *AUTH_FB_LINK;
//@property(nonatomic, copy) NSString        *AUTH_THIRD_URL;
//@property(nonatomic, copy) NSString        *BASE_URI;
//@property(nonatomic, copy) NSString        *MODE_DEBUG;
//@property(nonatomic, copy) NSString        *AUTH_BASE_URI;
//@property(nonatomic, copy) NSString        *BILL_BASE_URI;
//@property(nonatomic, copy) NSString        *CMSP_BASE_URI;
//@property(nonatomic, copy) NSString        *LOG_BASE_URI;
//@property(nonatomic, copy) NSString        *NOTICE_URI;
//@property(nonatomic, copy) NSString        *VERSION_URI;
//@property(nonatomic, copy) NSString        *WEB_BILL_URI;
//@property(nonatomic, copy) NSString        *TALKINGDATA_APPID;
//@property(nonatomic, copy) NSString        *TALKINGDATA_CHANNEL;
//@property(nonatomic, copy) NSString        *APPLE_APPID;
//@property(nonatomic, copy) NSString        *APPSFLYER_DEV_KEY;
//@property(nonatomic, strong) NSDictionary  *AD_CONFIG;
//@property(nonatomic, strong) NSDictionary  *AUTH_CONFIG;
//@property(nonatomic, copy) NSString  *AUTH_GG_URI;

+ (LESDKConf *)getSDKConf;
+(void)clearSDKConf;
@property (strong, nonatomic) NSBundle *languageBundle;
@end

NS_ASSUME_NONNULL_END
