//
//  LingKingSDKManager.h
//  LingKing_Example
//
//  Created by leoan on 2020/3/20.
//  Copyright © 2020 MrDML. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, LENetworkStatus) {
    LE_NotReachable,
    LE_ReachableViaWiFi,
    LE_ReachableViaWWAN
};

@protocol LingKingSDKManagerDelegate <NSObject>

@optional
- (void)lingKingInitSDK:(BOOL)isSuccess WithError:(NSError *_Nullable)error;
/// 管理类初始化成功
/// @param error <#error description#>
- (void)lingkingManagerInitComplete:(NSError *_Nullable)error;
- (void)lingKingInitSDKNetworkStatusError:(NSError *_Nullable)error;

@end


NS_ASSUME_NONNULL_BEGIN
@interface LingKingSDKManager : NSObject
@property (nonatomic, weak) id<LingKingSDKManagerDelegate>delegate;
@property(nonatomic) BOOL isDebug;
/// 首选语言，如果设置了就用该语言，不设则取当前系统语言。
/// 由于目前只支持中文、繁体中文、英文、阿拉伯。故该属性只支持zh-Hans、zh-Hant、en、ar四种值，其余值无效。
@property (copy, nonatomic) NSString *preferredLanguage;

/// 语言bundle，preferredLanguage变化时languageBundle会变化
/// 可通过手动设置bundle，让选择器支持新的的语言（需要在设置preferredLanguage后设置languageBundle）。欢迎提交PR把语言文件提交上来~
@property (strong, nonatomic) NSBundle *_Nullable languageBundle;

+ (instancetype)instance;
@property (nonatomic, copy) void(^lingKingSDKInitComplete)(BOOL isSuccess,NSError *error);


- (void)setMatrixLanguage:(NSString *)language;

/// 注册SDK
/// @param appID 应用appID
/// @param secretkey 秘钥
- (void)registLingKingSDKAppID:(NSString *)appID withSecretkey:(NSString *)secretkey;
- (void)initializeLingKingSDKApplication:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (void)trackAppLaunch;
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
- (BOOL)application:(nonnull UIApplication *)application openURL:(nonnull NSURL *)url options:(nonnull NSDictionary<NSString *, id> *)options;
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
- (void)applicationDidBecomeActive:(UIApplication *)application;

@end
NS_ASSUME_NONNULL_END

