//
//  LEHandleKeychain.h
//  LingKingSDK
//
//  Created by leoan on 2020/5/9.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LEHandleKeychain : NSObject
+ (void)save:(NSString *)service data:(id)data;
+ (id)load:(NSString *)service;
+ (void)delete:(NSString *)service;
@end

NS_ASSUME_NONNULL_END
