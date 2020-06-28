//
//  LENoticeView.h
//  ios-game
//
//  Created by leoan on 2020/4/8.
//  Copyright © 2020 leoan. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LENoticeView : UIView
@property (nonatomic, copy) void(^closeHandler)(void);
+ (instancetype)instanceNoticeView;
- (void)setNoticeInfo:(NSString *)info;
@end

NS_ASSUME_NONNULL_END
