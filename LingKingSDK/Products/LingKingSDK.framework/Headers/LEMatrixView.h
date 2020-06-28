//
//  LEMatrixView.h
//  LingKingSDK
//
//  Created by leoan on 2020/4/29.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LEMatrixView : UIView
+ (instancetype)instanceMatrixViewWithViewController:(UIViewController *)viewController;
- (void)setMatrixConfig:(NSDictionary *)matrixConfig withGroup:(NSInteger)group;
//@property (nonatomic, strong) NSDictionary *matrixConfig;
//@property (nonatomic, strong) NSArray *matrixConfigArray;
@property (nonatomic, copy) void (^didSelectItemAtIndex)(NSString *appid);
@end

NS_ASSUME_NONNULL_END
