//
//  LESystem.h
//  LingKingSDK
//
//  Created by leoan on 2020/4/9.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>





@interface LESystem : NSObject<NSCoding>
@property (nonatomic,copy) NSString *appID;
@property (nonatomic,copy) NSString *secretkey;
// 登录方式 guest facebook google game
@property (nonatomic,copy) NSString *loginStyle;
// facebook token  google token
@property (nonatomic,copy) NSString *token;
@property (nonatomic,copy) NSString *gameId;
@property (nonatomic,copy) NSString *userToken;
// 设置矩阵语言版本
@property (nonatomic,copy) NSString *matrixLanguage;


+ (LESystem *)getSystem;
+ (void)setSystem:(LESystem *)system;
+ (void)clearSystemConf;
@end


