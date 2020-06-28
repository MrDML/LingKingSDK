//
//  LEFBPointHelper.h
//  LingKing
//
//  Created by leoan on 2020/4/3.
//  Copyright © 2020 MrDML. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LEFBPointHelper : NSObject

+ (instancetype)instance;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

/// 禁用自动记录事件
- (void)setAutoLogAppEventsEnabled:(BOOL)autoLogAppEventsEnabled;
/// 禁用广告主编号收集功能
- (void)setAdvertiserIDCollectionEnabled:(BOOL)advertiserIDCollectionEnabled;
/// 标准事件
- (void)standardLogEventName:(NSString *)eventName withParameters:(NSDictionary *)params;
- (void)standardLogEventName:(NSString *)eventName;
- (void)standardLogEventName:(NSString *)eventName valueToSum:(double)valueToSum withParameters:(NSDictionary *)params;
/// 自定义事件
- (void)customeLogEventName:(NSString *)eventName withParameters:(NSDictionary *)params;
- (void)customeLogEventName:(NSString *)eventName;
- (void)customeLogEventName:(NSString *)eventName valueToSum:(double)valueToSum withParameters:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
