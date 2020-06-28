//
//  LEAccountShowView.h
//  ios-game
//
//  Created by leoan on 2020/4/8.
//  Copyright © 2020 leoan. All rights reserved.
//

#import <UIKit/UIKit.h>
@class LEUser;
NS_ASSUME_NONNULL_BEGIN

@interface LEAccountShowView : UIView
+ (instancetype)instanceAccountShowViewWithUser:(LEUser *)user;
@property (nonatomic, copy) void(^closeAlterViewHandler)(void);
@property (nonatomic, copy) void(^logOutHandler)(void);
@property (nonatomic, copy) void(^changeHandler)(void);
@property (nonatomic, copy) void(^selectBannerAtIndex)(NSInteger index);
@end

NS_ASSUME_NONNULL_END
