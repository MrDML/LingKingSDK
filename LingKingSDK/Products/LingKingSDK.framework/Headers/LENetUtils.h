//
//  LENetUtils.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/11.
//  Copyright © 2020 leaon jason All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LENetUtils : NSObject
+ (NSString *)getConfURLStr:(NSString *)api;
+ (NSString *)getSDKConf;
+ (NSString *)getSDKMatrixConf;
+ (NSString *)getSDKPayConf;
//+ (NSString *)getURLStr:(NSString *)api;
+ (NSString *)randomString;
+ (NSString*)md5Str:(NSString *)str;
+ (NSString *)getSignData:(NSDictionary *)parameters;
+(NSString*)dictionaryToJson:(NSDictionary *)dic;
+ (NSString *)deviceInfo;
@end

NS_ASSUME_NONNULL_END
