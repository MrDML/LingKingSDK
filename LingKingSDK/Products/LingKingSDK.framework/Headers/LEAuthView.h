//
//  LEAuthView.h
//  ios-game
//
//  Created by leoan on 2020/4/8.
//  Copyright © 2020 leoan. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LEAuthView : UIView
+ (instancetype)instanceAuthView;
@property (nonatomic, copy) void(^closeHandler)(void);
@property (nonatomic, copy) void(^doAuthHandler)(void);
@property (nonatomic, copy) void(^doAuthGoogleHandler)(void);
@property (nonatomic, copy) void(^doAuthFacebookHandler)(void);
@property (nonatomic, copy) void(^doAuthAppleHandler)(void);
@property (nonatomic, copy) void(^informationHandler)(void);
@property (nonatomic, copy) void(^privacyPolicyHandler)(void);
@property (nonatomic, copy) void(^selectedHandler)(BOOL isSelected);
@property (nonatomic, assign) BOOL selected;
- (void)hiddenThirdPlatform;
- (void)setCheckState:(BOOL)isCheck;
@end

NS_ASSUME_NONNULL_END
