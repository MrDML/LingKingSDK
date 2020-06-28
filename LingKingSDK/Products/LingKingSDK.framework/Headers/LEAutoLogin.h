//
//  LEAutoLogin.h
//  LingKingSDK
//
//  Created by leoan on 2020/4/10.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>
@class LEUser;
typedef NS_ENUM(NSInteger,LELOGINSTYLE) {
    LELOGINSTYLE_GUEST,
    LELOGINSTYLE_FACEBOOK,
    LELOGINSTYLE_GOOGLE,
    LELOGINSTYLE_GAME,
    LELOGINSTYLE_APPLE
};

@interface LEAutoLogin : NSObject
// 登录方式
@property (nonatomic,assign,readonly) LELOGINSTYLE loginStyle;
- (void)setLoginStyle:(LELOGINSTYLE)loginStyle;
+ (instancetype)instance;
- (void)autoLogin;
@property (nonatomic,copy) void(^autoLoginComplete)(LEUser *user,NSError *error);
@end

