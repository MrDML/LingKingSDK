//
//  LEAccountCenterView.h
//  ios-game
//
//  Created by leoan on 2020/4/8.
//  Copyright © 2020 leoan. All rights reserved.
//

#import <UIKit/UIKit.h>
@class LEUser;
NS_ASSUME_NONNULL_BEGIN

@interface LEAccountCenterView : UIView
+ (instancetype)instanceAccountCenterView;
@property (nonatomic, copy) void(^changeHandler)(void);
@property (nonatomic, copy) void(^linkAccountHandler)(void);
@property (nonatomic, copy) void(^logoutHandler)(void);
- (void)setUser:(LEUser *)user;
@end

NS_ASSUME_NONNULL_END
