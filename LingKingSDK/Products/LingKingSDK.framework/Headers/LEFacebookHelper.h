//
//  LEFacebookHelper.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/12.
//  Copyright © 2020 leaon jason All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


@class LEFacebookHelper;
@class FBSDKLoginManagerLoginResult;

@protocol LEFacebookHelperDelegate <NSObject>

- (void)loginSuccess:(LEFacebookHelper * _Nullable)facebookHelp resultObject:(id _Nullable)object;
- (void)loginFail:(LEFacebookHelper* _Nullable)facebookHelp error:(NSError * _Nullable)error;
- (void)cancelLogin:(LEFacebookHelper*_Nullable)facebookHelp;

@end

@interface LEFacebookHelper : NSObject

@property (nonatomic, weak)id <LEFacebookHelperDelegate> _Nullable delegate;

+ (instancetype _Nullable)instance;
/**
 - (BOOL)application:(UIApplication *)application
 didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 需要在这个方法中进行初始化
 */
- (void)initFacebook:(UIApplication * _Nonnull)application didFinishLaunchingWithOptions:(NSDictionary * _Nullable)launchOptions;

/// 支持iOS8
- (BOOL)application:(UIApplication * _Nullable)application openURL:(NSURL * _Nullable)url sourceApplication:(NSString * _Nullable)sourceApplication annotation:(id _Nullable)annotation;
- (BOOL)application:(nonnull UIApplication *)application openURL:(nonnull NSURL *)url options:(nonnull NSDictionary<NSString *, id> *)options;

- (void)login:(UIViewController * _Nonnull)viewController;

- (void)login:(UIViewController * _Nonnull)viewController stateComplete:(void(^_Nullable)(FBSDKLoginManagerLoginResult* _Nullable result, BOOL isCancelled, NSError * _Nonnull error))complete;

-(void)logOut;

-(BOOL)isLogin;

@end


