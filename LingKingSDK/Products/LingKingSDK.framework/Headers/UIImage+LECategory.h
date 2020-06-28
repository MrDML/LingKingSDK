//
//  UIImage+LECategory.h
//  FireflySDK_Example
//
//  Created by leoan on 2020/3/13.
//  Copyright © 2020 leaon jason All rights reserved.
//




#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (LECategory)


+ (UIImage *)le_ImageNamed:(NSString *)name;
+ (UIImage *)le_ImageNamed:(NSString *)name withCls:(Class)cls;

@end

NS_ASSUME_NONNULL_END
