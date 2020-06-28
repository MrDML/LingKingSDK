//
//  LECheckAgeView.h
//  ios-game
//
//  Created by leoan on 2020/4/8.
//  Copyright © 2020 leoan. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LECheckAgeView : UIView
+ (instancetype)instanceCheckAgeView;
@property (nonatomic, copy) void(^commitOKHandler)(BOOL isSelectAge);
@property (nonatomic, assign) int selectButtonTag;
@end

NS_ASSUME_NONNULL_END
