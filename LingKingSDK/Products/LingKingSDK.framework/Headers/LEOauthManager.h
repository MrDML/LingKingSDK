//
//  LEOauthManager.h
//  LingKingSDK
//
//  Created by leoan on 2020/4/10.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
@class LEUser;
NS_ASSUME_NONNULL_BEGIN

@protocol LEOauthManagerDelegate <NSObject>

@optional
// 自动登录回调
- (void)lingKingAutoLogin:(LEUser *_Nullable)user WithError:(NSError *_Nullable)error;
// 游戏自主登录
- (void)lingKingGameLogin:(LEUser *_Nullable)user WithError:(NSError *_Nullable)error;

// 游客登录回调
- (void)lingKingGuestLogin:(LEUser *_Nullable)user WithError:(NSError *_Nullable)error;

// FaceBook 登录回调
- (void)lingKingFacebookLogin:(LEUser *_Nullable)user WithIsCancel:(BOOL)cancel WithError:(NSError *_Nullable)error;

// FaceBook绑定账号 回调
- (void)lingKingLinkFacebook:(LEUser *_Nullable)user WithIsLinkSuccess:(BOOL)isSuccess WithError:(NSError *_Nullable)error;

// Google 登录回调
- (void)lingKingGoogleLogin:(LEUser *_Nullable)user WithIsCancel:(BOOL)cancel WithError:(NSError *_Nullable)error;

// Google绑定账号 回调
- (void)lingKingLinkGoogle:(LEUser *_Nullable)user WithIsLinkSuccess:(BOOL)isSuccess WithError:(NSError *_Nullable)error;

// Apple 登录回调
- (void)lingKingAppleLogin:(LEUser *_Nullable)user WithIsCancel:(BOOL)cancel WithError:(NSError *_Nullable)error;

// Apple绑定账号 回调
- (void)lingKingLinkApple:(LEUser *_Nullable)user WithIsLinkSuccess:(BOOL)isSuccess WithError:(NSError *_Nullable)error;


// 点击banner的回调
- (void)lingKingSelectBannerAtIndex:(NSInteger)index;


// SDK 登出的回调
- (void)logoutSDK;

@end

/// <#Description#>
@interface LEOauthManager : NSObject

@property (nonatomic, weak) id <LEOauthManagerDelegate>delegate;

/// 实例化管理对象
+ (instancetype _Nullable )instance;


/// 如果未登录 nil
@property (nonatomic,strong,readonly) LEUser *user;


// 需要进行年龄验证后 才可以登录
- (void)verfication:(UIViewController *)viewController;

// 自动登录 + 登录 面板 逻辑
/// @param viewController viewController description
- (void)autoAuthLogin:(UIViewController *_Nullable)viewController;



/// 仪表盘
/// @param viewController viewController description
/// @param frame frame description
- (void)floatViewDashboard:(UIViewController *_Nullable)viewController withFrame:(CGRect)frame;

/// 隐藏仪表盘
- (void)hiddenFloatViewDashboard;

/// 登录界面
/// @param viewController viewController description
- (void)login:(UIViewController *_Nullable)viewController;

/// 是否绑定
- (void)showUserAccountCenter:(UIViewController *)viewController;
/// 是否绑定
- (void)showUserAccountCenter:(UIViewController *)viewController withUser:(LEUser *)user;

/// 账号绑定
/// @param viewController viewController description
/// @param tokenString tokenString description
- (void)linkAccount:(UIViewController *_Nullable)viewController WithUserToken:(NSString *_Nullable)tokenString;

/// 账号绑定
/// @param viewController viewController description
/// @param user user description
- (void)linkAccount:(UIViewController *_Nullable)viewController WithUser:(LEUser *_Nullable)user;

/// 账号绑定
/// @param viewController viewController description
- (void)linkAccount:(UIViewController *_Nullable)viewController;

/// game游戏登录
/// @param accountId accountId
- (void)gameLoginAccountId:(NSString *)accountId;

// 推出登录
- (void)logout;


@end

NS_ASSUME_NONNULL_END
