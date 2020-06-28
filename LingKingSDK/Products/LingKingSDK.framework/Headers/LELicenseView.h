//
//  LELicenseView.h
//  ios-game
//
//  Created by leoan on 2020/4/8.
//  Copyright © 2020 leoan. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface LELicenseView : UIView
+ (instancetype)instanceLicenseViewWithURL:(NSURL *)url;
@property (nonatomic, copy) void(^commitOKHandler)(BOOL isCheck);
@end

NS_ASSUME_NONNULL_END
