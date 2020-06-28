//
//  LEAFPointHelper.h
//  LingKing
//
//  Created by leoan on 2020/3/21.
//  Copyright © 2020 MrDML. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LEAFPointHelper : NSObject
+ (instancetype)instance;
///追踪应用内事件
- (void)trackInAppEvents:(NSString *)trackEvent withValues:(NSDictionary *)dictionary;

// 追踪卸载事件
- (void)registDefaultNotificationsApplication;
- (void)registerUninstall:(NSData *_Nullable)deviceToken;

// 匿名⚠️
- (void)deviceTrackingDisabled;

//// 激活打点
//- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
//// URL 处理
//- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;
//
//// 标准打点
//- (void)standardLogEventName:(NSString *)eventName withParameters:(NSDictionary *)params;
//- (void)standardLogEventName:(NSString *)eventName;
//- (void)standardLogEventName:(NSString *)eventName valueToSum:(double)valueToSum withParameters:(NSDictionary *)params;
//
//// 自定义打点
//- (void)customeLogEventName:(NSString *)eventName withParameters:(NSDictionary *)params;
//- (void)customeLogEventName:(NSString *)eventName;
//- (void)customeLogEventName:(NSString *)eventName valueToSum:(double)valueToSum withParameters:(NSDictionary *)params;



@end

NS_ASSUME_NONNULL_END
