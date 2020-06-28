//
//  NSBundle+LECategory.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/13.
//  Copyright © 2020 leaon jason All rights reserved.
//




#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (LECategory)

+ (NSBundle *)le_loadBundleClass:(Class)aClass bundleName:(NSString *)bundleName;
+ (NSString *)le_localizedStringForKey:(NSString *)key;
+ (NSString *)le_localizedStringForKey:(NSString *)key value:(NSString *)value;
@end

NS_ASSUME_NONNULL_END
