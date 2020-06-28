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




// =========================== 以下将会废除 ===================================

///  广告回调
/* 测试先暂用此标志
 顺序 1.穿山甲
 顺序 2.facebook
 顺序 3.google
 顺序 4.IronSrc
 
 **/
@property (nonatomic,assign) int flagPlatform;

@property(nonatomic, weak) id <LingKingManagerDelegate> _Nullable delegate;

///  仅仅是保留传入的游客token 进行账号绑定
//@property (nonatomic, copy,readonly)NSString * _Nullable tokenString;
/// 实例化管理对象
+ (instancetype _Nullable )instance;
//
//// 账号登录
//- (void)autoLogin;
///// 授权
///// @param viewController viewController description
//- (void)doAuth:(UIViewController *_Nullable)viewController;
//
///// 账号绑定
///// @param viewController viewController description
///// @param tokenString tokenString description
//- (void)linkAccount:(UIViewController *_Nullable)viewController WithUserToken:(NSString *_Nullable)tokenString;
//
///// 账号绑定
///// @param viewController <#viewController description#>
///// @param user <#user description#>
//- (void)linkAccount:(UIViewController *_Nullable)viewController WithUser:(LEUser *_Nullable)user;
//
///// game游戏登录
///// @param accountId accountId
//- (void)gameLoginAccountId:(NSString *)accountId;
//
//
///// 谷歌授权登录
///// @param rootViewController <#rootViewController description#>
//- (void)loginGoogleRootViewController:(UIViewController *)rootViewController;
///// 推出谷歌登录
//- (void)logoutGoogle;
//
//
//
//
/// 指定打点平台
@property (nonatomic, assign) LINGKINGPOINTPLATFORM pointPlatform;
//
//// FB 打点仅有
//- (void)setAutoLogAppEventsEnabled:(BOOL)autoLogAppEventsEnabled;
//- (void)setAdvertiserIDCollectionEnabled:(BOOL)advertiserIDCollectionEnabled;
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
//
//
//// =================== 广告
///// 初始化广告
///// @param viewController viewController description
///// @param superView superView description
//- (void)initializationRootViewController:(UIViewController *_Nullable)viewController superView:(UIView *_Nullable)superView;
//// 指定具体的广告类型
//
//
///// 展示广告
///// @param viewController viewController description 控制器
///// @param frame frame description 位置（banner）
///// @param superView superView description 广告父视图
///// @param style style description 广告类型， 横屏广告 插屏广告 激励视频广告 全屏广告
//- (void)showRandomADRootViewController:(UIViewController *_Nullable)viewController adViewFrame:(CGRect)frame superView:(UIView *_Nullable)superView adStyle:(LINGKINGADSTYLE)style;
//
///// 从将Banner父视图上移除广告视图
//- (void)removeBannerFromSuperViewAd;
//
//
//// ============ 无效发布时删除 =====================
//
//// 需要将四个广告合并成一个，定义一套返回接口
//// 定义统一接口对外暴露
//// 随机选一种广告平台（具体什么广告类型还未知）在100 以内随机一个数
//- (void)showRandomADRootViewController:(UIViewController *_Nullable)viewController adViewFrame:(CGRect)frame superView:(UIView *_Nullable)superView;
//// 以下指定具体的广告类型
//// 横屏广告
//- (void)showAdBannerAdRootViewController:(UIViewController * _Nullable)viewController adViewFrame:(CGRect)frame superView:(UIView *_Nullable)superView;
//// 插页广告
//- (void)showInterstitialAd:(UIViewController *_Nullable)viewController;
//// 加载激励视频广告
//- (void)showRewardedVideoAd:(UIViewController *_Nullable)viewController;
//// 展示全屏视频广告
//- (void)showFullScreenVideoAd:(UIViewController *_Nullable)viewController;
//// ============ 无效发布时删除 =====================
@end

NS_ASSUME_NONNULL_END
