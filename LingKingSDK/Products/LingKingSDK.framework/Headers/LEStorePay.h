//
//  LEStorePay.h
//  LingKing_Example
//
//  Created by leoan on 2020/4/3.
//  Copyright © 2020 MrDML. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LESKProduct;
typedef enum {
    SIAPPurchSuccess = 0,       // 购买成功
    SIAPPurchFailed = 1,        // 购买失败
    SIAPPurchCancle = 2,        // 取消购买
    SIAPPurchVerFailed = 3,     // 订单校验失败
    SIAPPurchVerSuccess = 4,    // 订单校验成功
    SIAPPurchNotArrow = 5,      // 不允许内购
}SIAPPurchType;
 
typedef void (^IAPCompletionHandle)(SIAPPurchType type,NSData *data);

@protocol LEStoreDelegate <NSObject>

@optional
- (void)storePayCreateOrderIsSuccess:(BOOL)isSuccess withError:(NSError *)error;
- (void)storePayFinishPay:(BOOL)isSuccess withError:(NSError *)error;
- (void)productsRequest:(NSArray <LESKProduct *>*)request invalidProductIdentifiers:(NSArray<NSString *> *)invalidProductIdentifiers didFailWithError:(NSError *)error;
@end

@interface LEStorePay : NSObject
@property (nonatomic, weak) id <LEStoreDelegate> delegate;
+ (instancetype)instance;


/// 拉取所有商品信息
- (void)requestProductDatas;

//开始内购
- (void)startPurchWithID:(NSString *)purchID parames:(NSDictionary *)parames completeHandle:(IAPCompletionHandle)handle;
/// 创建订单
/// @param params params description
/// @param createComplete createComplete description
- (void)requestCreateOrderParames:(NSDictionary *)params createComplete:(void(^)(BOOL isSuccess))createComplete;

/// 完成订单
/// @param params params description
/// @param createComplete createComplete description
- (void)requestFinishOrder:(NSDictionary *)params createComplete:(void(^)(BOOL isSuccess))createComplete;


/// 单个商品id, 查询商品信息
/// @param productId productId description
- (void)requestProductData:(NSString *)productId;

/// 多个商品ID, 查询多个商品信息
/// @param productIds productIds description
- (void)requestProductDatas:(NSArray <NSString *>*)productIds;


@end

