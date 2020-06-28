//
//  LEFBShare.h
//  LingKing_Example
//
//  Created by leoan on 2020/4/7.
//  Copyright © 2020 MrDML. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface LEFBShare : NSObject

+ (instancetype)instance;

@property (nonatomic, copy)void (^shareComplete)(NSDictionary <NSString *, id> * _Nullable results,BOOL isCancel,NSError  * _Nullable error);
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
