//
//  LEShareViewController.m
//  LingKingSDK_Example
//
//  Created by leoan on 2020/4/10.
//  Copyright © 2020 dml1630@163.com. All rights reserved.
//

#import "LEShareViewController.h"

@interface LEShareViewController ()
@end

@implementation LEShareViewController

- (void)viewDidLoad {
    [super viewDidLoad];
  
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
- (IBAction)shareLink:(id)sender {

}

- (IBAction)shareImage:(id)sender {
    
    // 只能分享本地资源
    
}
- (IBAction)shareVideo:(id)sender {
    

}

- (IBAction)shareMedia:(id)sender {

}
// 分享成功
- (void)linkingShareDidCompleteWithResults:(NSDictionary<NSString *, id> *)results{
}
// 分享失败
- (void)linkingShareDidFailWithError:(NSError *)error{
}
// 取消分享
- (void)linkingShareDidCancel{
}
@end
