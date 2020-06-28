//
//  LEImageDownloader.h
//  LingKingSDK
//
//  Created by leoan on 2020/4/9.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface LEImageDownloader : NSObject
+(instancetype)instance;
@property (nonatomic,copy) NSString * imageUrl;
//开始下载图像
- (void)startDownloadImage:(NSString *)imageUrl withImageView:(UIImageView *)imageView;
//从本地加载图像
- (UIImage *)loadLocalImage:(NSString *)imageUrl;
@property (nonatomic,copy) void(^downloadComplete)(UIImage *image);

@end

NS_ASSUME_NONNULL_END
