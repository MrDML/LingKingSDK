//
//  LEEventAction.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/11.
//  Copyright © 2020 leaon jason All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


@class LEUser;
typedef void (^GUESTCOMPLETE)(LEUser* user,NSError*error);
typedef void (^GAMECOMPLETE)(LEUser* user,NSError*error);
typedef void (^FACEBOOKCOMPLETE)(LEUser* user,BOOL isCancel,NSError*error);
typedef void (^LINKFACEBOOKCOMPLETE)(LEUser* user,BOOL isLinkSuccess,NSError*error);

typedef void (^GOOGLECOMPLETE)(LEUser* user,BOOL isCancel,NSError*error);
typedef void (^LINKGOOGLECOMPLETE)(LEUser* user,BOOL isLinkSuccess,NSError*error);

typedef void (^APPLELECOMPLETE)(LEUser* user,BOOL isCancel,NSError*error);
typedef void (^LINKAPPLECOMPLETE)(LEUser* user,BOOL isLinkSuccess,NSError*error);

@interface LEEventAction : NSObject
// 初始化
- (void)initSDKConfig:(void(^)(BOOL isSuccess,NSError*error))isSuccess;

/// 初始化矩阵广告
/// @param completeHander completeHander description
- (void)initSDKMatrixConfig:(void(^)(id result, BOOL isSuccess,NSError*error))completeHander;


// 事件完成的回調
@property(nonatomic,copy)void(^eventComplete)(void);

+ (instancetype)instance;

/// 调起登录面板
- (void)showAlterOauthTosat:(UIViewController *)viewController;

// 游戏登录
- (void)gameLoginAccountId:(NSString *)accountId;
@property (nonatomic, copy)GAMECOMPLETE gameComplete;

/// 游客登录
- (void)guestLoginAction;
@property (nonatomic, copy)GUESTCOMPLETE guestComplete;

/// facebook 登录
- (void)faceBookLoginAction:(UIViewController *)viewController;
@property (nonatomic, copy)FACEBOOKCOMPLETE faceBookComplete;

/// 绑定登录facebook账号
- (void)facebookLinkAccountLoginAction:(UIViewController *)viewController;
@property (nonatomic, copy)LINKFACEBOOKCOMPLETE linkFaceBookComplete;


/// Google 登录
- (void)googleLoginAction:(UIViewController *)viewController;
@property (nonatomic, copy)GOOGLECOMPLETE googleComplete;

/// 绑定登录Google账号
- (void)googleLinkAccountLoginAction:(UIViewController *)viewController;
@property (nonatomic, copy)LINKGOOGLECOMPLETE linkGoogleComplete;

/// Apple登录
- (void)appleLoginAction:(UIViewController *)viewController;
@property (nonatomic, copy)APPLELECOMPLETE appleComplete;

/// 绑定Apple登录
- (void)appleLinkAccountLoginAction:(UIViewController *)viewController;
@property (nonatomic, copy)LINKAPPLECOMPLETE linkAppleComplete;

/// 登出
- (void)logoutAction;

// 点击无线滚动 banner的回调
@property (nonatomic, copy) void(^selectBannerAtIndex)(NSInteger index);

//======== 自动登录使用

// 请求Google登录， 是否携带请求头

- (void)requestLoginGoogle:(NSString *)urlString parameters:(NSDictionary *)parames WithHTTPHeaderField:(NSDictionary *)headerFields WithLinkAccount:(BOOL)isLink complete:(void(^)(LEUser *user))complete ;
// 请求Facebook登录， 是否携带请求头
- (void)requestLoginFaceBook:(NSString *)urlString parameters:(NSDictionary *)parames WithHTTPHeaderField:(NSDictionary *)headerFields WithLinkAccount:(BOOL)isLink complete:(void(^)(LEUser *user))complete;
// 请求Apple登录， 是否携带请求头
- (void)requestLoginApple:(NSString *)urlString parameters:(NSDictionary *)parames WithHTTPHeaderField:(NSDictionary *)headerFields WithLinkAccount:(BOOL)isLink complete:(void(^)(LEUser *user))complete;
// 游客登录
// - (void)guestLoginAction;
- (NSDictionary *)defaultParames;
// 游戏登录
//- (void)gameLoginAccountId:(NSString *)accountId
@end

