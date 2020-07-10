//
//  LEAdverManager.h
//  LingKingSDK
//
//  Created by leoan on 2020/4/10.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
// 广告类型
typedef NS_ENUM(NSInteger,LINGKINGADVSTYLE) {
    LINGKINGADVSTYLE_Banner,       // 横屏广告
    LINGKINGADVSTYLE_Interstitial, // 插屏广告
    LINGKINGADVSTYLE_RewardedVideo // 激励广告
};

typedef NS_ENUM(NSInteger,LKPLATFORM) {
    LKPLATFORM_NONE = 0,
    LKPLATFORM_TITOK,     //1.穿山甲
    LKPLATFORM_FACEBOOK,  //2.facebook
    LKPLATFORM_GOOGLE,    //3.google
    LKPLATFORM_IRONSRC    //4.IronSrc
};

NS_ASSUME_NONNULL_BEGIN

@protocol LEAdverManagerDelegate <NSObject>


@optional
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
- (void)rewardedVideoAdEarnReward; // 用户赢得激励广告, 视频播放完成赢得奖励

// 全屏视频
- (void)fullscreenVideoDidLoad;
- (void)fullscreenVideoCacheDidLoad;
- (void)fullscreenVideoDidFailWithError:(NSError *_Nullable)error;
- (void)fullscreenVideoDidClickSkip;
- (void)fullscreenVideoDidClick;
- (void)fullscreenVideoDidClose;
- (void)fullscreenVideoAdEarnReward; // 用户赢得激励广告, 视频播放完成赢得奖励


/// 矩阵初始化
/// @param result <#result description#>
/// @param error <#error description#>
- (void)initMatrixConfigResult:(NSDictionary *)result withError:(NSError *)error;

@end

@interface LEAdverManager : NSObject


@property (nonatomic,weak) id <LEAdverManagerDelegate>delegate;

@property (nonatomic,assign) LKPLATFORM platform;

+ (instancetype)instance;


/// 展示矩阵
/// @param viewController 控制器
/// @param group 分组序号
/// @param frame 矩阵展示位置
- (void)showMatrixWithViewController:(UIViewController *)viewController withGroup:(NSInteger)group withFrame:(CGRect)frame;

/// 隐藏矩阵
- (void)hiddenMatrixView;

/// 初始化广告
/// @param viewController viewController description
/// @param superView superView description
- (void)initializationRootViewController:(UIViewController *_Nullable)viewController superView:(UIView *_Nullable)superView;


/// 从将Banner父视图上移除广告视图
- (void)removeBannerFromSuperViewAd;


// 横屏广告
- (void)showAdBannerAdRootViewController:(UIViewController * _Nullable)viewController adViewFrame:(CGRect)frame superView:(UIView *_Nullable)superView;
// 插页广告
- (void)showInterstitialAd:(UIViewController *_Nullable)viewController;
// 加载激励视频广告
- (void)showRewardedVideoAd:(UIViewController *_Nullable)viewController;
// 展示全屏视频广告
- (void)showFullScreenVideoAd:(UIViewController *_Nullable)viewController;

@end

NS_ASSUME_NONNULL_END
