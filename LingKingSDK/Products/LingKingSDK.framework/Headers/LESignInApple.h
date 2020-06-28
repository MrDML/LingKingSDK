//
//  LESignInApple.h
//  LingKingSDK
//
//  Created by leoan on 2020/5/6.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface LESignInApple : NSObject
+ (instancetype)instance;
- (void)loginApple;
// 1:appleID 2.password 3. 验证失败
@property (nonatomic, copy) void (^didCompleteWithAuthorization)(NSInteger type,NSString * _Nullable user,NSString * _Nullable token,NSString * _Nullable code,NSString * _Nullable password);
@property (nonatomic, copy) void (^didCompleteWithError)(NSError *error);

@end

NS_ASSUME_NONNULL_END
