//
//  LEPointManager.h
//  LingKing
//
//  Created by leoan on 2020/3/21.
//  Copyright © 2020 MrDML. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger,LEPOINTPLATFORM) {
    LEPOINTPLATFORM_LK,
    LEPOINTPLATFORM_AF,
    LEPOINTPLATFORM_FB
};


typedef void(^LEPOINTCOMPLETE)(BOOL isSucccess,LEPOINTPLATFORM platform,NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@protocol LEPointManagerDelegate <NSObject>

// 事件追踪回调
- (void)lingKingPointIsSuccess:(BOOL)isSuccess withError:(NSError *_Nullable)error;


@end

/// Description
@interface LEPointManager : NSObject

@property (nonatomic, copy) LEPOINTCOMPLETE pointComplete;
@property (nonatomic,weak) id<LEPointManagerDelegate> delegate;
+ (instancetype)instane;

/// 平台
@property (nonatomic, assign) LEPOINTPLATFORM platform;

// 激活打点
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
// URL 处理
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

// FB 仅有
- (void)setAutoLogAppEventsEnabled:(BOOL)autoLogAppEventsEnabled;
- (void)setAdvertiserIDCollectionEnabled:(BOOL)advertiserIDCollectionEnabled;

// 标准打点
- (void)standardLogEventName:(NSString *)eventName withParameters:(NSDictionary *)params;
- (void)standardLogEventName:(NSString *)eventName;
- (void)standardLogEventName:(NSString *)eventName valueToSum:(double)valueToSum withParameters:(NSDictionary *)params;

// 自定义打点
- (void)customeLogEventName:(NSString *)eventName withParameters:(NSDictionary *)params;
- (void)customeLogEventName:(NSString *)eventName;
- (void)customeLogEventName:(NSString *)eventName valueToSum:(double)valueToSum withParameters:(NSDictionary *)params;


/// 平台统一打点
/// @param eventName 事件名
/// @param params 自定义事件
- (void)logEventName:(NSString *)eventName withParameters:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
