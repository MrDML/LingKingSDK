//
//  LETitokExpressHelper.h
//  LingKingSDK
//
//  Created by leoan on 2020/4/15.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

// 横屏广告事件
typedef NS_ENUM(NSInteger,LETITOK_EX_BANNERAD_EVENT){
    LETITOK_EX_BANNERAD_DidLoad, //  广告加载完成，可在此事件中显示广告
    LETITOK_EX_BANNERAD_DidDisplay, // 加载完成显示
    LETITOK_EX_BANNERAD_Click, // 点击广告
    LETITOK_EX_BANNERAD_DidFail, // 加载失败
    LETITOK_EX_BANNERAD_Dislike, // 不喜欢，原因
    LETITOK_EX_BANNERAD_DidCloseVC // 关闭其他控制器
};

// 插屏广告事件
typedef NS_ENUM(NSInteger,LETITOK_EX_INTERSTITIAL_EVENT){
      LETITOK_EX_INTERSTITIAL_DidClose, // 已经关闭
      LETITOK_EX_INTERSTITIAL_DidLoad, // 已经加载完成
       LETITOK_EX_INTERSTITIAL_Click, // 点击广告
      LETITOK_EX_INTERSTITIAL_DidFail, // 加载失败
      LETITOK_EX_INTERSTITIAL_DidCloseVC // 关闭其他控制器
};

////   激励广告事件
// rewardedAd
typedef NS_ENUM(NSInteger,LETITOK_EX_REWAARDEDAD_EVENT){
    LETITOK_EX_REWAARDEDAD_DidLoad, // 视频素材加载成功后后将调用此方法。
    LETITOK_EX_REWAARDEDAD_CacheDidLoad, //成功缓存后将调用此方法。
     LETITOK_EX_REWAARDEDAD_DidFail, // 加载失败
    LETITOK_EX_REWAARDEDAD_DidDisplay, // 视频显示后调用
    LETITOK_EX_REWAARDEDAD_DidClose, // 视频广告关闭后调用
    LETITOK_EX_REWAARDEDAD_DidClick, // 点击视频广告后调用
    LETITOK_EX_REWAARDEDAD_ClickSkip, // 点击跳过按钮
    LETITOK_EX_REWAARDEDAD_PlayFinish, // 播放成功或者失败后调用
    LETITOK_EX_REWAARDEDAD_ServerDidFail, // 服务器响应失败后调用
    LETITOK_EX_REWAARDEDAD_ServerDidSucceed // 服务器响应成功后低啊用
};


typedef NS_ENUM(NSInteger,LETITOK_EX_FULLSCREEN_EVENT){
   LETITOK_EX_FULLSCREEN_DidLoad, // 视频素材加载成功后后将调用此方法。
   LETITOK_EX_FULLSCREEN_CacheDidLoad, //成功缓存后将调用此方法。
    LETITOK_EX_FULLSCREEN_DidFail,     // 视频加载失败
   LETITOK_EX_FULLSCREEN_DidClickSkip, // 点击跳过
   LETITOK_EX_FULLSCREEN_DidClick, // 点击视频后加载
   LETITOK_EX_FULLSCREEN_DidClose,  // 关闭视频后加载
   LETITOK_EX_FULLSCREEN_PlayFinish // 播放成功或者失败后调用
};

// 横屏广告回调 _Nonnull _Nullable
typedef void(^LETITOKE_OR_BANNERAD)(LETITOK_EX_BANNERAD_EVENT event,NSError * _Nullable error);

// 插屏广告回调 _Nonnull _Nullable
typedef void(^LETITOK_OR_INTERSTITIALAD)(LETITOK_EX_INTERSTITIAL_EVENT event,NSError * _Nullable error);

// 激励广告回调 _Nonnull _Nullable
typedef void(^LETITOK_OR_REWAARDEDADAD)(LETITOK_EX_REWAARDEDAD_EVENT event,NSError * _Nullable error);


// 全屏广告回调 _Nonnull _Nullable
typedef void(^LETITOK_OR_FULLSCREENVIDEAD)(LETITOK_EX_FULLSCREEN_EVENT event,NSError * _Nullable error);

@interface LETitokExpressHelper : NSObject
+ (instancetype)instance;
/// 预加载
@property (nonatomic, assign) BOOL isInitialize_InterstitialAD;
@property (nonatomic, assign) BOOL preloading_InterstitialAD;

@property (nonatomic, assign) BOOL isInitialize_RewardedVideoAdAD;
@property (nonatomic, assign) BOOL preloading_RewardedVideoAdAD;

@property (nonatomic, assign) BOOL isInitialize_FullscreenVideoAdAD;
@property (nonatomic, assign) BOOL preloading_FullscreenVideoAdAD;

// 横屏广告回调
@property (nonatomic, copy)LETITOKE_OR_BANNERAD titokBannerAD;

// 插屏广告回调
@property (nonatomic, copy)LETITOK_OR_INTERSTITIALAD titokInterstitialAD;

// 激励广告回调
@property (nonatomic, copy)LETITOK_OR_REWAARDEDADAD titokRewardedAD;
// 全屏视频广告
@property (nonatomic, copy)LETITOK_OR_FULLSCREENVIDEAD titokFullScreenAD;
// 初始化参数
- (void)initTitokParames;
// - 移除横屏广告
- (void)removeBannerSuperView;
// 展示横屏广告
- (void)showTittokBannerAdViewController:(UIViewController *)viewController superView:(UIView *)superView frame:(CGRect)frame;
// 初始化横屏广告
- (void)initializationTittokBannerRootViewController:(UIViewController *)viewController superView:(UIView *)superView frame:(CGRect)frame;

// 展示插屏广告
- (void)showTittokInterstitialAd:(UIViewController *)viewController;
// 先进行初始化，在类加载的时候就可以进行初始化
- (void)initializationTittokInterstitialAd:(UIViewController *)viewController;
@property(nonatomic, copy) NSString *userId; // 用户userID

// 展示激励视频广告
- (void)showTittokRewardVideoAd:(UIViewController *)viewController;
// 初始化激励视频广告
- (void)initializationRewardVideoAd:(UIViewController *)viewController;

// 展示全屏广告
- (void)showTittokFullScreenVideoAd:(UIViewController *)viewController;
// 初始全屏广告
- (void)initializationFullScreenVideoAd:(UIViewController *)viewController;

@end

NS_ASSUME_NONNULL_END
