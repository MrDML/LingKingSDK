//
//  LEViewController.m
//  LingKing
//
//  Created by MrDML on 03/20/2020.
//  Copyright (c) 2020 MrDML. All rights reserved.
//

#import "LEViewController.h"
#import "LEOauthViewController.h"
#import "LEAdViewController.h"
#import "LEPointEventViewController.h"
#import "LEStorePayViewController.h"
#import "LEShareViewController.h"
@interface LEViewController ()<UITableViewDelegate,UITableViewDataSource>

@property (nonatomic, strong) UITableView *tableView;

@property (nonatomic, strong) NSArray *headers;
@property (nonatomic, strong) NSArray *dataSources;

@end

@implementation LEViewController


- (void)viewDidLoad
{
    [super viewDidLoad];
//    [self sdkinitconfig];
 //   [self addCustomeLoginButton];
//
//    [self request];
   
    
    self.navigationItem.title = @"LingKingSDK";
    
    self.tableView = [[UITableView alloc] initWithFrame:CGRectZero style:UITableViewStyleGrouped];
    self.tableView.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height);
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    self.tableView.sectionFooterHeight = 0.001;
    [self.view addSubview:self.tableView];
 
  
    self.headers = @[@"Oauth",@"Google",@"Facebook",@"IronSource",@"Titok",@"RandomAd",@"Point",@"StorePay",@"Share"];
    
    self.dataSources = @[@[@"Login&Link"],@[@"Start Test"],@[@"Start Test"],@[@"Start Test"],@[@"Start Test"],@[@"Start Test"],@[@"Start Test"],@[@"Start Test"],@[@"Share Test"]];
    


}



- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    
    
    return  self.headers.count; // 5 个区
}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    
    NSArray *sections = self.dataSources[section];
    
    return sections.count;
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:@"idenitfire"];
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"idenitfire"];
        
        cell.textLabel.text = [NSString stringWithFormat:@"%ld",(long)indexPath.row];
        
        
        
    }
    cell.textLabel.text = self.dataSources[indexPath.section][indexPath.row];
    return cell;
}




- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    return 44.0;
}


- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    
   UITableViewHeaderFooterView *headerView = [tableView dequeueReusableHeaderFooterViewWithIdentifier:@"headerIdetifire"];
    
    if (headerView == nil) {
        headerView = [[UITableViewHeaderFooterView alloc] initWithReuseIdentifier:@"headerIdetifire"];
    
//        headerView.contentView.backgroundColor = [UIColor whiteColor];
        UILabel *label = [[UILabel alloc] init];
        label.frame = CGRectMake(10, 0, [UIScreen mainScreen].bounds.size.width-20, 44);
        label.font = [UIFont systemFontOfSize:20 weight:UIFontWeightMedium];
        label.textAlignment =  NSTextAlignmentLeft;
        label.tag = 10;
        [headerView.contentView addSubview:label];
    }
    
   UILabel *label =  [headerView viewWithTag:10];
    label.text = self.headers[section];
    
    return headerView;
}

/* 测试先暂用此标志
 顺序 1.穿山甲
 顺序 2.facebook
 顺序 3.google
 顺序 4.IronSrc
 
 **/

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    if (indexPath.section == 0) {  // 授权登录
        UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
        LEOauthViewController *loginViewController = [storyboard instantiateViewControllerWithIdentifier:@"oauthViewController"];
        [self.navigationController pushViewController:loginViewController animated:YES];
    }else {
        UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:[NSBundle mainBundle]];
        LEAdViewController *adViewController = [storyboard instantiateViewControllerWithIdentifier:@"adViewController"];
        if (indexPath.section == 1) {
            adViewController.flagPlatform = 3; // google
            adViewController.navigationItem.title = @"Google";
             [self.navigationController pushViewController:adViewController animated:YES];
        }else if (indexPath.section == 2){
            adViewController.flagPlatform = 2; // facebook
              adViewController.navigationItem.title = @"Facebook";
             [self.navigationController pushViewController:adViewController animated:YES];
        }else if (indexPath.section == 3){
            adViewController.flagPlatform = 4; // IronSrc
            adViewController.navigationItem.title = @"IronSrcource";
             [self.navigationController pushViewController:adViewController animated:YES];
        }else if (indexPath.section == 4){
            adViewController.flagPlatform  = 1; //穿山甲
             [self.navigationController pushViewController:adViewController animated:YES];
            adViewController.navigationItem.title = @"Titok";
        }else if (indexPath.section == 5){
            adViewController.flagPlatform  = 5; // 随机
            adViewController.navigationItem.title = @"Random";
             [self.navigationController pushViewController:adViewController animated:YES];
        }else if (indexPath.section == 6){
                LEPointEventViewController *pointViewController = [storyboard instantiateViewControllerWithIdentifier:@"pointEventViewController"];
            pointViewController.navigationItem.title = @"Point";
            [self.navigationController pushViewController:pointViewController animated:YES];
        }else if (indexPath.section == 7){
            LEStorePayViewController *storePayViewController = [storyboard instantiateViewControllerWithIdentifier:@"storePayViewController"];
                storePayViewController.navigationItem.title = @"StorePay";
                [self.navigationController pushViewController:storePayViewController animated:YES];
        }else if (indexPath.section == 8){
            LEShareViewController *shareViewController = [storyboard instantiateViewControllerWithIdentifier:@"shareViewController"];
               shareViewController.navigationItem.title = @"Sahre";
               [self.navigationController pushViewController:shareViewController animated:YES];
            
        }

        //
       
    }
    
}

@end
