//
//  LEIronSourceHelper.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/14.
//  Copyright © 2020 leaon jason All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
// APP KEY: b7ff7c7d



// 横屏广告事件
typedef NS_ENUM(NSInteger,LEIS_BANNERAD_EVENT){
    LEIS_BANNERAD_EVENT_DidLoad, // 横屏广告加载完成
    LEIS_BANNERAD_EVENT_Error, // 加载失败
    LEIS_BANNERAD_EVENT_Click, // 点击广告
    LEIS_BANNERAD_EVENT_WillPresentScreen, // 生命周期：广告将要消失
    LEIS_BANNERAD_EVENT_DidDismissScreen, // 生命周期：广告已经消失
    LEIS_BANNERAD_EVENT_WillLeaveApplication, // 生命周期：将要离开应用
    LEIS_BANNERAD_EVENT_OrientationChanged // 屏幕发生旋转
};

// 插屏广告事件
typedef NS_ENUM(NSInteger,LEIS_INTERSTITIAL_EVENT){
    LEIS_INTERSTITIAL_EVENT_DidLoad, // 横屏广告加载完成
    LEIS_INTERSTITIAL_EVENT_DidShow, // 广告已经显示
    LEIS_INTERSTITIAL_EVENT_ShowError, // 显示失败
    LEIS_INTERSTITIAL_EVENT_Click, // 点击广告
    LEIS_INTERSTITIAL_EVENT_DidClose, // 广告已经关闭
    LEIS_INTERSTITIAL_EVENT_DidOpen, //广告已经打开
    LEIS_INTERSTITIAL_EVENT_LoadFail // 加载失败
};
// 激励广告事件
typedef NS_ENUM(NSInteger,LEIS_REWAARDEDAD_EVENT){
    LEIS_REWAARDEDAD_EVENT_Changed, // 激励视频发生更改
    LEIS_REWAARDEDAD_EVENT_ReceiveReward, // 激励视频看完之后的奖励
    LEIS_REWAARDEDAD_EVENT_ShowFail, // 激励视频播放失败调用
    LEIS_REWAARDEDAD_EVENT_DidOpen, // 打开激励视频后调用
    LEIS_REWAARDEDAD_EVENT_DidClose, // 关闭激励视频之后调用
    LEIS_REWAARDEDAD_EVENT_DidClick, // 点击激励视频之后调用
    LEIS_REWAARDEDAD_EVENT_DidStart, // 激励视频开始播放
    LEIS_REWAARDEDAD_EVENT_DidEnd // 激励视频播放完成
};

// 横屏广告回调 _Nonnull _Nullable
typedef void(^LEISBANNERAD)(LEIS_BANNERAD_EVENT event,NSError * _Nullable error);

// 插屏广告回调 _Nonnull _Nullable
typedef void(^LEISINTERSTITIALAD)(LEIS_INTERSTITIAL_EVENT event,NSError * _Nullable error);

// 激励广告回调 _Nonnull _Nullable
typedef void(^LEISREWAARDEDADAD)(LEIS_REWAARDEDAD_EVENT event,NSError * _Nullable error);




@interface LEIronSourceHelper : NSObject
@property (nonatomic, assign) BOOL isInitialize_InterstitialAD;
@property (nonatomic, assign) BOOL isInitialize_RewardedVideoAdAD;
/// 预加载
@property (nonatomic, assign) BOOL preloading_InterstitialAD;
@property (nonatomic, assign) BOOL preloading_RewardedVideoAdAD;
// 横屏广告回调
@property (nonatomic, copy)LEISBANNERAD _Nullable ironSourceBannerAD;

// 插屏广告回调
@property (nonatomic, copy)LEISINTERSTITIALAD _Nullable ironSourceInterstitialAD;

// 激励广告回调
@property (nonatomic, copy)LEISREWAARDEDADAD _Nullable ironSourceRewardedAD;


+ (instancetype _Nullable)instance;
// - 获取配置信息
- (void)initIronSourceParames;
// - 移除横屏广告
- (void)removeBannerSuperView;

// 展示横屏广告
- (void)showIronSourBannerAdViewController:(UIViewController * _Nullable)viewController superView:(UIView *_Nullable)superView frame:(CGRect)frame;
// 初始化Banner
- (void)initializationIronSourBanner:(UIViewController *_Nullable)viewController superView:(UIView*_Nullable)superView frame:(CGRect)frame;


// 验证SDK是否集成成功
- (void)validateIntegration;
// 其他负载设置(加载其他banner广告)
- (void)loadBannerWithViewController:(UIViewController *_Nullable)viewController withPlacement:(NSString *_Nullable)placement;
// 销毁广告品
- (void)destroyBanner;



// 插屏广告
- (void)showIronSourceInterstitialAd:(UIViewController *_Nullable)viewController;
/// - 初始化插屏广告
- (void)initializationIronSourceInterstitialAd:(UIViewController *_Nullable)viewController;

// 展示激励视频广告
- (void)showIronSourceRewardedVideoAd:(UIViewController *_Nullable)viewController;
// 初始化激励视频广告
- (void)initializationRewardedVideo:(UIViewController *_Nullable)viewController;


 // 设置为yes 监听网络的变化
- (void)shouldTrackReachability;
// 广告刊登位置
// 要获取与每个广告展示位置相关的特定奖励的详细信息，您可以调用以下命令：
- (void)getRewardedVideoAdInfo:(NSString *_Nullable)placementName;
// 动态获取用户ID
-(void)getDynamicUserId;
// 您必须调用以下方法来验证特定的展示位置是否已达到其广告限制。
- (void)ischeckRewardedVideoCapped:(NSString *_Nullable)placement;
@end


