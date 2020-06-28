//
//  LEUser.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/12.
//  Copyright © 2020 leaon jason All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LEUser : NSObject<NSCoding>
@property (nonatomic, copy) NSString *id;
@property (nonatomic, copy) NSString *age;
@property (nonatomic, copy) NSString *timestamp;
@property (nonatomic, copy) NSString *verify;
@property (nonatomic, copy) NSString *login_type;
@property (nonatomic, copy) NSString *ppid;
@property (nonatomic, copy) NSString *is_new_user;
@property (nonatomic, copy) NSString *nick_name;
@property (nonatomic, copy) NSString *third_id; // 是否绑定过账号
@property (nonatomic, copy) NSString *head_icon;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *create_time;
@property (nonatomic, copy) NSString *gender;


- (instancetype)initWithDictionary:(NSDictionary *)dictionary;
+ (LEUser *)getUser;
+ (void)setUser:(LEUser *)user;
+ (void)removeUserInfo;
@end

NS_ASSUME_NONNULL_END
