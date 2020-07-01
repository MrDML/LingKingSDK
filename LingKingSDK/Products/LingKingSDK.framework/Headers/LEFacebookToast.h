//
//  LEFacebookToast.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/10.
//  Copyright © 2020 leaon jason All rights reserved.
//

#import <UIKit/UIKit.h>

@class LEUser;
typedef NS_ENUM(NSInteger,LETOASTSTYLE) {
    LETOASTSTYLE_Platform,
    LETOASTSTYLE_AccountCenter,
    LETOASTSTYLE_AccountShow,
    LETOASTSTYLE_Auth,
    LETOASTSTYLE_Start,
    LETOASTSTYLE_Account,
    LETOASTSTYLE_FB,
    LETOASTSTYLE_AccountSetting,
    LETOASTSTYLE_Fail,
    LETOASTSTYLE_Success,
    LETOASTSTYLE_Pay,
    LETOASTSTYLE_Verification, // 验证
    LETOASTSTYLE_Notice,  // 注意
    LETOASTSTYLE_License, // 许可协议
    LETOASTSTYLE_Alert  // 重新登录提示
};

NS_ASSUME_NONNULL_BEGIN

@interface LEFacebookToast : UIViewController


@property (nonatomic, copy) void(^dismissComplete)(NSInteger index,NSString *info);

// 点击banner的回调
@property (nonatomic, copy) void(^selectBannerAtIndex)(NSInteger index);


// 点击重新登录的回调
@property (nonatomic, copy) void(^againLoginComplete)();

@property (nonatomic,assign)LETOASTSTYLE toastStyle;

@property (nonatomic,strong) UIViewController *viewController;

@property (nonatomic,strong) LEUser *user;

@property (nonatomic,assign) BOOL isHiddenFacebookLogin;

@property (nonatomic,assign) BOOL isTickAgreement;

// 协议连接
@property (nonatomic, strong) NSURL *webURL;


// 是否禁用绑定账号
@property (nonatomic, assign) BOOL isDisableLintAccount;


@property (nonatomic, copy) NSString *noticeInfo;
@end

NS_ASSUME_NONNULL_END
