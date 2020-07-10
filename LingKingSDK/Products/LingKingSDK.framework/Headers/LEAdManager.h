//
//  LEAdManager.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/13.
//  Copyright © 2020 leaon jason All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LEAdManager.h"
NS_ASSUME_NONNULL_BEGIN

// 广告类型
typedef NS_ENUM(NSInteger,LEADSTYLE) {
    LEADSTYLE_None,         // 不加载任何类型广告
    LEADSTYLE_Banner,       // 横屏广告
    LEADSTYLE_Interstitial, // 插屏广告
    LEADSTYLE_RewardedVideo // 激励广告
};

// 横屏广告
typedef NS_ENUM(NSInteger,LEAD_BANNER_EVENT) {
    LEAD_BANNER_DidLoad, // 加载完成
    LEAD_BANNER_Fail, // 加载失败
    LEAD_BANNER_DisLike, // 不喜欢
    LEAD_BANNER_StartClick, // 开始点击
    LEAD_BANNER_DidDisplay, // 加载完成显示
    LEAD_BANNER_EndClick, // 结束点击
    LEAD_BANNER_Captureing, // 正在捕获
    LEAD_BANNER_DidCloseVC,// 离开其他控制器
    LEAD_BANNER_WillPresentScreen, // 生命周期：广告将要弹起
    LEAD_BANNER_WillDismissScreen, // 生命周期：广告将要消失
    LEAD_BANNER_DidDismissScreen, // 生命周期：广告已经消失
    LEAD_BANNER_WillLeaveApplication, // 生命周期：将要离开应用
    LEAD_BANNER_OrientationChanged // 屏幕发生旋转
};

// 插屏广告
typedef NS_ENUM(NSInteger,LEAD_INTERSTITIAL_EVENT) {
    LEAD_INTERSTITIAL_DidLoad, // 加载完成
    LEAD_INTERSTITIAL_Fail, // 加载失败
    LEAD_INTERSTITIAL_DidShow, // 广告已经显示
    LEAD_INTERSTITIAL_ShowError, // 显示失败
    LEAD_INTERSTITIAL_StartClick, // 点击广告
    LEAD_INTERSTITIAL_EndClick, // 结束点击
    LEAD_INTERSTITIAL_ClickToGoal, // 完成点击带到目的地
    LEAD_INTERSTITIAL_ClickClose,  // 用户点击了关闭广告
    LEAD_INTERSTITIAL_DidClickClose, // 广告已经关闭
    LEAD_INTERSTITIAL_DidOpen,//广告已经打开
    LEAD_INTERSTITIAL_DidCloseVC,// 离开其他控制器
    LEAD_INTERSTITIAL_WillPresentScreen, // 生命周期：广告将要弹起
    LEAD_INTERSTITIAL_WillDismissScreen, // 生命周期：广告将要消失
    LEAD_INTERSTITIAL_DidDismissScreen, // 生命周期：广告已经消失
    LEAD_INTERSTITIAL_WillLeaveApplication // 生命周期：将要离开应用
};

// 激励视频广告
typedef NS_ENUM(NSInteger,LEAD_REWARDEDVIDEO_EVENT){
    LEAD_REWARDEDVIDEO_DidLoad, // 加载完成可以显示
    LEAD_REWARDEDVIDEO_CacheDidLoad,//成功缓存后将调用此方法。
    LEAD_REWARDEDVIDEO_Fail, // 加载失败
    LEAD_REWARDEDVIDEO_Click, // 点击了视频广告
    LEAD_REWARDEDVIDEO_ClickClosed, // 点击了关闭视频广告
    LEAD_REWARDEDVIDEO_Closed, // 视频广告已经关闭
    LEAD_REWARDEDVIDEO_EarnReward, // 用户赢得了激励广告
    LEAD_REWARDEDVIDEO_Display, // 视频广告已完成-在完整视频观看后调用 奖励广告已被展示
    LEAD_REWARDEDVIDEO_NoDisplay, // 激励广告未能展示,展示失败
    LEAD_REWARDEDVIDEO_Cartured, // 视频广告已经被捕获
    LEAD_REWARDEDVIDEO_DidDismissScreen, // 视频广告已经消失
    LEAD_REWARDEDVIDEO_Change, // 激励视频发生更改
    LEAD_REWARDEDVIDEO_DidStart, // 激励视频开始播放
    LEAD_REWARDEDVIDEO_DidEnd,// 激励视频播放完成
    LEAD_REWARDEDVIDEO_ServerDidFail, // 服务器响应失败后调用
    LEAD_REWARDEDVIDEO_ServerDidSucceed // 服务器响应成功后调用
};

// 全屏视频广告
typedef NS_ENUM(NSInteger,LEAD_FULLSCREENVIDEO_EVENT){
     LEAD_FULLSCREENVIDEO_DidLoad, // 视频素材加载成功后后将调用此方法。
     LEAD_FULLSCREENVIDEO_CacheDidLoad, // 成功缓存后将调用此方法。
     LEAD_FULLSCREENVIDEO_DidFail, // 视频加载失败
     LEAD_FULLSCREENVIDEO_DidClickSkip, //点击跳过
     LEAD_FULLSCREENVIDEO_DidClick, // 点击视频后加载
     LEAD_FULLSCREENVIDEO_DidClose, // 关闭视频后加载
     LEAD_FULLSCREENVIDEO_EarnReward // 视频播放完成应得激励
};




// 广告是否出初始化成功回调
typedef void(^LEINITSUCCESSAD)(BOOL isSuccess);

// 横屏广告回调 _Nonnull _Nullable
typedef void(^LEADBANNERAD)(LEAD_BANNER_EVENT event,NSError * _Nullable error);

// 插屏广告回调
typedef void(^LEADINTERSTITIALAD)(LEAD_INTERSTITIAL_EVENT event,NSError * _Nullable error);

// 激励视频广告回调
typedef void(^LEADREWARDEDVIDEOAD)(LEAD_REWARDEDVIDEO_EVENT event,NSError * _Nullable error);

// 全屏视频广告回调
typedef void(^LEADFULLSCREENVIDEAD)(LEAD_FULLSCREENVIDEO_EVENT event,NSError * _Nullable error);




@interface LEAdManager : NSObject

// 广告是否初始化成功
@property (nonatomic, copy) LEINITSUCCESSAD isSuccessADHander;
// 横屏广告的回调
@property (nonatomic, copy) LEADBANNERAD bannerEventHandler;

// 插屏广告的回调
@property (nonatomic, copy) LEADINTERSTITIALAD interstitialEventHandler;

// 激励广告的回调
@property (nonatomic, copy) LEADREWARDEDVIDEOAD rewardedVideoEventHandler;

// 全屏视频广告的回调
@property (nonatomic, copy) LEADFULLSCREENVIDEAD fullScreenVideoEventHandler;

/// 广告类型
@property (nonatomic, assign) LEADSTYLE style;

@property (nonatomic, copy) NSString *userId; // 用户userId

+ (instancetype)instance;

- (void)initPlatformParames;

// 初始化广告
- (void)initializationRootViewController:(UIViewController *)viewController superView:(UIView *)superView;

// 需要将四个广告合并成一个，定义一套返回接口
// 定义统一接口对外暴露
// 随机选一种广告平台（具体什么广告类型还未知）在100 以内随机一个数
- (void)showRandomADRootViewController:(UIViewController *)viewController adViewFrame:(CGRect)frame superView:(UIView *)superView;

// 指定具体的广告类型
- (void)showRandomADRootViewController:(UIViewController *)viewController adViewFrame:(CGRect)frame superView:(UIView *)superView adStyle:(LEADSTYLE)style;




// 以下指定具体的广告类型
// 横屏广告
- (void)showAdBannerAdRootViewController:(UIViewController *)viewController adViewFrame:(CGRect)frame superView:(UIView *)superView;

// 插页广告
- (void)showInterstitialAd:(UIViewController *)viewController;
// 加载激励视频广告
- (void)showRewardedVideoAd:(UIViewController *)viewController;
// 展示全屏视频广告
- (void)showFullScreenVideoAd:(UIViewController *)viewController;


/// 将banner冲父视图上移除
- (void)removeBannerSuperView;

@end

NS_ASSUME_NONNULL_END
