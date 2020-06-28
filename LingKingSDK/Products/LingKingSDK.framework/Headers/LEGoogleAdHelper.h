//
//  LEGoogleAdHelper.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/13.
//  Copyright © 2020 leaon jason All rights reserved.
//



// google 应用 id  配置到plist 文件中
//key:GADApplicationIdentifier  value:ca-app-pub-4062190346456155~3795746689
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@class GADBannerView;


// 横屏广告事件
typedef NS_ENUM(NSInteger,LEGOOGLE_BANNERAD_EVENT){
    LEGOOGLE_BANNERAD_EVENT_DidReceiveAd, //  广告加载完成，可在此事件中显示广告
    LEGOOGLE_BANNERAD_EVENT_Error, // 加载失败
    LEGOOGLE_BANNERAD_EVENT_WillPresentScreen, // 生命周期：广告将要弹起
    LEGOOGLE_BANNERAD_EVENT_WillDismissScreen, // 生命周期：广告将要消失
    LEGOOGLE_BANNERAD_EVENT_DidDismissScreen, // 生命周期：广告已经消失
    LEGOOGLE_BANNERAD_EVENT_WillLeaveApplication // 生命周期：将要离开应用
};

// 插屏广告事件
typedef NS_ENUM(NSInteger,LEGOOGLE_INTERSTITIAL_EVENT){
       LEGOOGLE_INTERSTITIAL_EVENT_DidReceiveAd, //  广告加载完成，可在此事件中显示广告
       LEGOOGLE_INTERSTITIAL_EVENT_Error, // 加载失败
       LEGOOGLE_INTERSTITIAL_EVENT_WillPresentScreen, // 生命周期：广告将要弹起
       LEGOOGLE_INTERSTITIAL_EVENT_WillDismissScreen, // 生命周期：广告将要消失
       LEGOOGLE_INTERSTITIAL_EVENT_DidDismissScreen, // 生命周期：广告已经消失
       LEGOOGLE_INTERSTITIAL_EVENT_WillLeaveApplication // 生命周期：将要离开应用
};

////   激励广告事件
// rewardedAd
typedef NS_ENUM(NSInteger,LEGOOGLE_REWAARDEDAD_EVENT){
       LEGOOGLE_REWAARDEDAD_EVENT_Error, // 加载失败
       LEGOOGLE_REWAARDEDAD_EVENT_Success, // 加载成功
       LEGOOGLE_REWAARDEDAD_EVENT_EarnReward, //  用户赢得了激励广告
       LEGOOGLE_REWAARDEDAD_EVENT_RewardedAdDisplay, // 奖励广告已被展示
       LEGOOGLE_REWAARDEDAD_EVENT_RewardedAdNODisplay, // 激励广告未能展示
       LEGOOGLE_REWAARDEDAD_EVENT_DidDismissScreen, // 激励广告已经消失
};


// 横屏广告回调 _Nonnull _Nullable
typedef void(^LEGOOGLEBANNERAD)(LEGOOGLE_BANNERAD_EVENT event,NSError * _Nullable error);

// 插屏广告回调 _Nonnull _Nullable
typedef void(^LEGOOGLEINTERSTITIALAD)(LEGOOGLE_INTERSTITIAL_EVENT event,NSError * _Nullable error);

// 激励广告回调 _Nonnull _Nullable
typedef void(^LEGOOGLEREWAARDEDADAD)(LEGOOGLE_REWAARDEDAD_EVENT event,NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface LEGoogleAdHelper : NSObject

// 横屏广告回调
@property (nonatomic, copy)LEGOOGLEBANNERAD googleBannerAD;

// 插屏广告回调
@property (nonatomic, copy)LEGOOGLEINTERSTITIALAD googleInterstitialAD;

// 激励广告回调
@property (nonatomic, copy)LEGOOGLEREWAARDEDADAD googleRewardedAD;
@property (nonatomic, assign) BOOL isInitialize_InterstitialAD;
@property (nonatomic, assign) BOOL preloading_InterstitialAD;

@property (nonatomic, assign) BOOL isInitialize_RewardedVideoAdAD;
@property (nonatomic, assign) BOOL preloading_RewardedVideoAdAD;

+ (instancetype)instance;
// 初始化参数
- (void)initGoogleParames;
// - 移除横屏广告
- (void)removeBannerSuperView;

// 展示横屏广告
- (void)showGoogleBannerAdViewController:(UIViewController *)viewController superView:(UIView *)superView frame:(CGRect)frame;
// 初始化横屏广告
- (void)initializationGoogleBannerRootViewController:(UIViewController *)viewController superView:(UIView *)superView frame:(CGRect)frame;


- (void)showGoogleInterstitialAd:(UIViewController *)viewController;
- (void)initializationGoogleInterstitialAd:(UIViewController *)viewController;

- (void)showGoogleRewardedVideoAd:(UIViewController *)viewController;
- (void)initializationGoogleRewardedAdRootViewController:(UIViewController *)viewController;



//  加载横屏广告 size 默认
//- (void)showGoogleBannerAd:(UIViewController *)rootViewController superview:(UIView *)superview frame:(CGRect)frame;
//// 加载横屏广告 size 自定义
//- (void)showGoogleBannerAdCustomeSize:(CGSize)size rootController:(UIViewController *)rootViewController superview:(UIView *)superview frame:(CGRect)frame;

//// 初始化插屏广告
//- (void)initializationGoogleInterstitialAd;
//// 初始化完成后加载插屏广告
//- (void)showGoogleInterstitialAd:(UIViewController *)viewController;
//// 主动调用广告
//// 插页式广告应在应用流程的自然停顿期间进行展示，例如游戏的不同关卡之间或用户完成一项任务之后，都是非常不错的展示时机。
//- (void)initiativeGoogleInterstitialAd:(UIViewController *)viewController;
///  - 激励广告
//- (void)showGooggleRewardedAd:(UIViewController *)viewController;
//// 主动调用激励广告
//
///*
// 在向用户展示激励广告之前，必须为用户提供明确的选项，让用户可以自行选择是否通过观看激励广告内容来换取奖励。激励广告必须始终是一项可由用户自行选择的体验。
// */
//- (void)initiativeGoogleRewardedAdRootViewController:(UIViewController *)rootViewController;

@end

NS_ASSUME_NONNULL_END
