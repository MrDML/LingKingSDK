//
//  LEFoatView.h
//  ios-game
//
//  Created by leoan on 2020/4/21.
//  Copyright © 2020 leoan. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef NS_ENUM(NSInteger, StayMode) {
 
    STAYMODE_LEFTANDRIGHT = 0,
    
    STAYMODE_LEFT = 1,

    STAYMODE_RIGHT = 2
};
@interface LEFoatView : UIImageView
@property (nonatomic, assign) StayMode stayMode;


@property (nonatomic, assign) CGFloat stayEdgeDistance;


@property (nonatomic, assign) CGFloat stayAnimateTime;


- (void)setTapActionWithBlock:(void (^)(void))block;


- (void)setImageWithName:(NSString *)imageName;


- (void)moveTohalfInScreenWhenScrolling;

- (void)setCurrentAlpha:(CGFloat)stayAlpha;
@end


