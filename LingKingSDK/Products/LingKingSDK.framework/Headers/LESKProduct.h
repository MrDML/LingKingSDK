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
/// 商品ID
@property (nonatomic,copy) NSString *productId;
/// 商品描述
@property (nonatomic,copy) NSString *desc;
/// 商品标题
@property (nonatomic,copy) NSString *localizedTitle;
/// 本地描述
@property (nonatomic,copy) NSString *localizedDescription;
/// 价格
@property (nonatomic,strong) NSDecimalNumber *price;
@end


