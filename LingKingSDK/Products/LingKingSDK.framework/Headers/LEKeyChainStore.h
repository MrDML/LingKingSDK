//
//  LEKeyChainStore.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/11.
//  Copyright © 2020 leaon jason All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LEKeyChainStore : NSObject
+ (void)save:(NSString *)service data:(id)data;
+ (id)load:(NSString *)service;
+ (void)deleteKeyData:(NSString *)service;
@end

NS_ASSUME_NONNULL_END
