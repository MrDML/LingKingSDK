//
//  LEFirebaseHelper.h
//  LingKing
//
//  Created by leoan on 2020/4/2.
//  Copyright © 2020 MrDML. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class GIDGoogleUser;
NS_ASSUME_NONNULL_BEGIN

@interface LEFirebaseHelper : NSObject
@property (nonatomic,copy) void(^didDisconnectHander)(GIDGoogleUser * _Nullable user, NSError * _Nullable error);
@property (nonatomic,copy) void(^didSignInForUserHander)(GIDGoogleUser *_Nullable user,BOOL isCancel,NSError *_Nullable error);
+ (instancetype)instance;
/// 初始化FireBaseSDK
- (void)initializationFireBaseSDK;
/// 谷歌授权登录
/// @param rootViewController <#rootViewController description#>
- (void)loginGoogleRootViewController:(UIViewController *)rootViewController;
/// 推出谷歌登录
- (void)logoutGoogle;
//实现您的应用委托中的 application:openURL:options: 方法。此方法应该调用 GIDSignIn 实例的 handleURL 方法，该方法将对您的应用在身份验证过程结束时收到的网址进行适当处理。
- (BOOL)handleURL:(NSURL *)url;
@end

NS_ASSUME_NONNULL_END
