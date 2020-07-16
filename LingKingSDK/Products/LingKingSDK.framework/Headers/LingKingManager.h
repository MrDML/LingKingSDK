//
//  LingKingManager.h
//  LingKing_Example
//
//  Created by leoan on 2020/3/20.
//  Copyright © 2020 MrDML. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "LEShareManager.h"
#import "LEPointManager.h"
#import "LEOauthManager.h"
#import "LEAdManager.h"
#import "LEStorePay.h"
#import "LEAdverManager.h"
// 广告类型
typedef NS_ENUM(NSInteger,LINGKINGADSTYLE) {
    LINGKINGADSTYLE_Banner,       // 横屏广告
    LINGKINGADSTYLE_Interstitial, // 插屏广告
    LINGKINGADSTYLE_RewardedVideo // 激励广告
};
// 打点平台
typedef NS_ENUM(NSInteger,LINGKINGPOINTPLATFORM) {
    LINGKINGPOINTPLATFORM_LK,
    LINGKINGPOINTPLATFORM_AF,
    LINGKINGPOINTPLATFORM_FB
};


@class LEUser;
@protocol LingKingManagerDelegate <NSObject>
/// sdk 管理对象初始化成功
- (void)lingkingManagerInitComplete:(NSError * _Nullable)error;

@optional


// 自动登录回调
- (void)lingKingAutoLogin:(LEUser *_Nullable)user WithError:(NSError *_Nullable)error;
// 游戏自主登录
- (void)lingKingGameLogin:(LEUser *_Nullable)user WithError:(NSError *_Nullable)error;

// 游客登录回调
- (void)lingKingGuestLogin:(LEUser *_Nullable)user WithError:(NSError *_Nullable)error;

// FaceBook 登录回调
- (void)lingKingFacebookLogin:(LEUser *_Nullable)user WithIsCancel:(BOOL)cancel WithError:(NSError *_Nullable)error;

// 绑定账号 回调
- (void)lingKingLinkFacebook:(LEUser *_Nullable)user WithIsLinkSuccess:(BOOL)isSuccess WithError:(NSError *_Nullable)error;

// Google 登录回调
- (void)lingKingGoogleLogin:(LEUser *_Nullable)user WithIsCancel:(BOOL)cancel WithError:(NSError *_Nullable)error;

// 绑定账号 回调
- (void)lingKingLinkGoogle:(LEUser *_Nullable)user WithIsLinkSuccess:(BOOL)isSuccess WithError:(NSError *_Nullable)error;

// 广告是否初始化成功
- (void)adInitIsSuccess:(BOOL)isSuccess;
// banner
- (void)bannerAdViewDidLoad;
- (void)bannerAdViewDidFailWithError:(NSError *_Nullable)error;
- (void)bannerAdViewDidClick;
- (void)bannerAdViewDidDisplay;
// 插屏
- (void)interstitialAdDidLoad;
- (void)interstitialAdDidFailWithError:(NSError *_Nullable)error;
- (void)interstitialAdDidDisplay;
- (void)interstitialAdClick;
- (void)interstitialAdClose;
// 激励视频
- (void)rewardedVideoAdDidLoad;
- (void)rewardedVideoAdDidFailWithError:(NSError *_Nullable)error;
- (void)rewardedVideoAdClick;
- (void)rewardedVideoAdClose;
- (void)rewardedVideoAdDidDisplay;
- (void)rewardedVideoAdEarnReward; // 用户赢得激励广告
// 全屏视频
- (void)fullscreenVideoDidLoad;
- (void)fullscreenVideoCacheDidLoad;
- (void)fullscreenVideoDidFailWithError:(NSError *_Nullable)error;
- (void)fullscreenVideoDidClickSkip;
- (void)fullscreenVideoDidClick;
- (void)fullscreenVideoDidClose;
// 事件追踪回调
- (void)lingKingPointIsSuccess:(BOOL)isSuccess withError:(NSError *_Nullable)error;


@end

NS_ASSUME_NONNULL_BEGIN

@interface LingKingManager : NSObject

// 分享管理类
@property (nonatomic, strong) LEShareManager *shareManager;
// 打点管理类
@property (nonatomic, strong) LEPointManager *pointManager;
// 授权登录管理类
@property (nonatomic, strong) LEOauthManager *oauthManager;
// 广告管理类
@property (nonatomic, strong) LEAdverManager *adManager;
// 内购
@property (nonatomic, strong) LEStorePay *storePay;

/// 实例化管理对象
+ (instancetype _Nullable )instance;


// =========================== 以下将会废除 ===================================

@property(nonatomic, weak) id <LingKingManagerDelegate> _Nullable delegate;

/// 指定打点平台
@property (nonatomic, assign) LINGKINGPOINTPLATFORM pointPlatform;

@end

NS_ASSUME_NONNULL_END
