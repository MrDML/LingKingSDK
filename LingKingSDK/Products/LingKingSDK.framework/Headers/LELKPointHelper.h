//
//  LELKPointHelper.h
//  LingKing
//
//  Created by leoan on 2020/3/21.
//  Copyright © 2020 MrDML. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

// Activation
typedef NS_ENUM(NSInteger,LETRACKEVENTS) {
    LETRACK_NONE, // 没有任何事件
    LETRACK_ACTIVATION, // 激活事件
    LETRACK_CUSTOME,// 自定义打点事件
    LETRACK_AD // 广告打点事件
};

//  _Nonnull _Nullable
typedef void(^LELKPOINTCOMPLETE)(BOOL isSucccess,NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface LELKPointHelper : NSObject

@property (nonatomic, assign) LETRACKEVENTS trackEvent;

@property (nonatomic, copy) LELKPOINTCOMPLETE pointComplete;
/// 登录后设置是否是新用户
/// @param isNewUser 是否是新用户
- (void)setIsNewUser:(NSString *)isNewUser;







+ (instancetype)instance;

// 激活打点 -
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/// 标准事件 -
- (void)standardLogEventName:(NSString *)eventName withParameters:(NSDictionary *)params;

/// 自定义事件 -
- (void)customeLogEventName:(NSString *)eventName withParameters:(NSDictionary *)params;


// ============== 以下接口废弃


//
///// 激活打点事件
//- (void)activationPotintEvent;
//
///// 自定义打点事件
///// @param evnet 事件名
//- (void)customePotintEvent:(NSString *)evnet;
//
///// 自定义打点
///// @param evnet 事件
///// @param jsonStr json 字符串
//- (void)customePotintEvent:(NSString *)evnet withJsonString:(NSString * _Nullable)jsonStr;
//
///// 广告打点事件
///// @param evnet evnet 事件名 show 展示成功|show_fail 展示失败|click 点击|pull_up 拉起|complete 看完|look_fail 看广告失败|cancel 用户取消看广告
///// @param channel 广告渠道
//- (void)adPotintEvent:(NSString *)evnet adChannel:(NSString *)channel;
//
///// 打点事件
///// @param interfaceName 接口名
///// @param dictionary 事件信息
//- (void)trackInAppInterfaceName:(NSString *)interfaceName withValue:(NSDictionary *)dictionary;
//
//




@end

NS_ASSUME_NONNULL_END
