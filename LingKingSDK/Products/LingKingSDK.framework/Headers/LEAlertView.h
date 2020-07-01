//
//  LEAlertView.h
//  LingKingSDK
//
//  Created by leoan on 2020/6/30.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LEAlertView : UIView
@property (nonatomic, copy) void(^againLoginHandler)(void);
+ (instancetype)instanceAlertView;
- (void)setTipInfo:(NSString *)info;
@end

NS_ASSUME_NONNULL_END
