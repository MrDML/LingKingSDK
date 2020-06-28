//
//  LESKProduct.h
//  LingKingSDK
//
//  Created by leoan on 2020/6/9.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SKProduct;

@interface LESKProduct : NSObject
- (instancetype)initWithArray:(SKProduct *)product;
@property (nonatomic,copy) NSString *productId;
@property (nonatomic,copy) NSString *desc;
@property (nonatomic,copy) NSString *localizedTitle;
@property (nonatomic,copy) NSString *localizedDescription;
@property (nonatomic,strong) NSDecimalNumber *price;
@end


