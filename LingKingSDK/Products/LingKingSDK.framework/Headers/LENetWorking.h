//
//  LENetWorking.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/11.
//  Copyright © 2020 leaon jason All rights reserved.
//

#import <Foundation/Foundation.h>


@interface LENetWorking : NSObject
+(LENetWorking *)sharedHttpSessionManager;
+ (void)getWithURLString:(NSString *)urlString success:(void(^)(id responseObject))success failure:(void(^)(NSError *error))failure;

// 参数不做处理
+ (void)postWithURLString:(NSString *)urlString parameters:(NSDictionary *)parameters success:(void(^)(id responseObject))success failure:(void(^)(NSError *error))failure;

// 处理参数并且处理请求头
+ (void)postWithURLString:(NSString *)urlString parameters:(NSDictionary *)parameters HTTPHeaderField:(NSDictionary *)headerField success:(void(^)(id responseObject))success failure:(void(^)(NSError *error))failure;

@end


