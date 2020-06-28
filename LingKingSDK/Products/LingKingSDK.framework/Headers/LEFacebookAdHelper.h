//
//  LEFacebookAdHelper.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/13.
//  Copyright © 2020 leaon jason All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


// 横屏广告事件
typedef NS_ENUM(NSInteger,LEFACEBOOK_BANNERAD_EVENT) {
    LEFACEBOOK_BANNERAD_EVENT_STARTCLICKED, // 开始点击
    LEFACEBOOK_BANNERAD_EVENT_FINISHCLICKED, // 完成点击
    LEFACEBOOK_BANNERAD_EVENT_CAPTUREING, // 正在捕获
    LEFACEBOOK_BANNERAD_EVENT_FAIL, // 加载失败
    LEFACEBOOK_BANNERAD_EVENT_DIDLOAD, // 加载完成可以显示广告
};

// 插屏广告事件
typedef NS_ENUM(NSInteger,LEFACEBOOK_INTERSTITIAL_EVENT) {
    LEFACEBOOK_INTERSTITIAL_EVENT_DIDLOAD, // 加载成功
    LEFACEBOOK_INTERSTITIAL_EVENT_SEEAD, // 用户看见广告
    LEFACEBOOK_INTERSTITIAL_EVENT_CLICKTOGOAL, // 完成点击带到目的地
    LEFACEBOOK_INTERSTITIAL_EVENT_CLOSEAD, // 用户点击关闭广告
    LEFACEBOOK_INTERSTITIAL_EVENT_FINSHCLOSEAD, // 用户已经完成点击关闭广告
    LEFACEBOOK_INTERSTITIAL_EVENT_FAIL, // 广告加载失败
};

// 激励视频广告事件
typedef NS_ENUM(NSInteger,LEFACEBOOK_REWARDEDVIDEO_EVENT) {
    LEFACEBOOK_REWARDEDVIDEO_EVENT_LOADFAIL, // 激励视频加载失败
    LEFACEBOOK_REWARDEDVIDEO_EVENT_DISPLAYED, // 视频广告已经加载并且显示
    LEFACEBOOK_REWARDEDVIDEO_EVENT_CLICK, // 点击了视频广告
    LEFACEBOOK_REWARDEDVIDEO_EVENT_COMPLETE, // 视频广告已完成-在完整视频观看后调用
    LEFACEBOOK_REWARDEDVIDEO_EVENT_CLOESED, // 奖励视频已经关闭
    LEFACEBOOK_REWARDEDVIDEO_EVENT_CLICKCLOSED, // 用户点击了关闭广告
    LEFACEBOOK_REWARDEDVIDEO_EVENT_CAPTURED // 奖励视频展示已被捕获
};

// 横屏广告回调 _Nonnull _Nullable
typedef void(^LEFACEBOOKBANNERAD)(LEFACEBOOK_BANNERAD_EVENT event,NSError * _Nullable error);

// 插屏广告回调
typedef void(^LEFACEBOOKINTERSTITIALAD)(LEFACEBOOK_INTERSTITIAL_EVENT event,NSError * _Nullable error);

// 激励视频广告回调
typedef void(^LEFACEBOOKREWARDEDVIDEOAD)(LEFACEBOOK_REWARDEDVIDEO_EVENT event,NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface LEFacebookAdHelper : NSObject

// 横屏广告回调
@property (nonatomic, copy)LEFACEBOOKBANNERAD facebookBannerAD;
// 插屏广告回调
@property (nonatomic, copy)LEFACEBOOKINTERSTITIALAD facebookInterstitialAD;
// 激励视频广告回调
@property (nonatomic, copy)LEFACEBOOKREWARDEDVIDEOAD facebookRewardedVideoAdAD;
@property (nonatomic, assign) BOOL isInitialize_InterstitialAD;
@property (nonatomic, assign) BOOL isInitialize_RewardedVideoAdAD;
/// 预加载
@property (nonatomic, assign) BOOL preloading_InterstitialAD;
@property (nonatomic, assign) BOOL preloading_RewardedVideoAdAD;
+(instancetype)instance;

# pragma mark - 获取配置信息
- (void)initFacebookParames;
// - 移除横屏广告
- (void)removeBannerSuperView;

- (void)showFacebookBannerAdViewController:(UIViewController *)viewController superView:(UIView *)superView frame:(CGRect)frame;
- (void)initializationFacebookBannerRootViewController:(UIViewController *)viewController superView:(UIView *)superView frame:(CGRect)frame;


- (void)showFacebookInterstitialAd:(UIViewController *)viewController;
- (void)initializationFacebookInterstitialAd:(UIViewController *)viewController;

- (void)showFacebookRewardedVideoAd:(UIViewController *)viewController;
- (void)initializationFacebookRewardedAdRootViewController:(UIViewController *)viewController;



@end

NS_ASSUME_NONNULL_END
