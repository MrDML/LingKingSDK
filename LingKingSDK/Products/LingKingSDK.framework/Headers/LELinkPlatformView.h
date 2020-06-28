//
//  LELinkPlatformView.h
//  ios-game
//
//  Created by leoan on 2020/4/8.
//  Copyright © 2020 leoan. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LELinkPlatformView : UIView
+ (instancetype)instanceLinkPlatformView;
@property (nonatomic, copy) void(^doLoginFacebookHandler)(void);
@property (nonatomic, copy) void(^doLoginGoogleHandler)(void);
@property (nonatomic, copy) void(^doLoginAppleHandler)(void);
@property (nonatomic, copy) void(^closeAlterViewHandler)(void);
@end

NS_ASSUME_NONNULL_END
