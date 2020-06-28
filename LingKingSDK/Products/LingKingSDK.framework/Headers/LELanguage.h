//
//  LELanguage.h
//  LingKingSDK
//
//  Created by leoan on 2020/4/22.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface LELanguage : NSObject
+ (instancetype)instance;
@property (copy, nonatomic) NSString *preferredLanguage;
@property (strong, nonatomic) NSBundle *languageBundle;
@end
