//
//  LEShareManager.h
//  LingKingSDK
//
//  Created by leoan on 2020/4/10.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@protocol LEShareManagerDelegate <NSObject>

// 分享成功
- (void)linkingShareDidCompleteWithResults:(NSDictionary<NSString *, id> *)results;
// 分享失败
- (void)linkingShareDidFailWithError:(NSError *)error;
// 取消分享
- (void)linkingShareDidCancel;

@end

@interface LEShareManager : NSObject

@property (nonatomic, weak) id <LEShareManagerDelegate> delegate;

+ (instancetype)instance;

/// 分享链接 + 引文 + 标签
/// @param linkUrl 链接  https://developers.facebook.com
/// @param quote 引文
/// @param hashtag 标签
/// @param viewController viewController description
- (void)shareLink:(NSString * _Nullable)linkUrl withQuote:(NSString *_Nullable)quote withHashtag:(NSString *_Nullable)hashtag withViewController:(UIViewController *)viewController;
///  分享单张图片
/// @param imageURL 单张图片URL
/// @param viewController <#viewController description#>
- (void)shareImageURL:(NSURL *)imageURL withViewController:(UIViewController *)viewController;
/// 分享多张图片
/// @param imageURLs imageURLs description
/// @param viewController viewController description
- (void)shareImageURLs:(NSArray<NSURL *>* _Nullable)imageURLs withViewController:(UIViewController *)viewController;

/// 分享视频
/// @param videoURL videoURL description
/// @param viewController viewController description
- (void)shareVideoURL:(NSURL * _Nullable)videoURL withViewController:(UIViewController *)viewController;

/// 分享多媒体
/// @param imageURL 图片资源
/// @param videoURL 视频资源
/// @param viewController viewController description
- (void)shareMediaImageURL:(NSURL * _Nullable)imageURL withVideoURL:(NSURL * _Nullable)videoURL WithViewController:(UIViewController *)viewController;



@end

NS_ASSUME_NONNULL_END
