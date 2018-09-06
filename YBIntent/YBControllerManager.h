//
//  YBControllerManager.h
//  YBHttpRequestCache
//
//  Created by yangjw on 16/12/9.
//  Copyright © 2016年 yangjw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


/*
 for example:
    ======================================================================================================================
 
     YBIntent *intent = [[YBIntent alloc] initWithClazz:[FirstViewController  class]];
     [intent putExtraWithName:@"number" data: [NSNumber numberWithInteger:2]];
    -----------------------------------------------------------------------------------------------------------------------
     // 自定义跳转方式
     1.presentationDisplay
     YBIntentPresentationDisplay *push = [[YBIntentPresentationDisplay alloc] init];
     intent.controllerDisplay = push;
     
     2.push
     YBIntentPushDisplay *push = [[YBIntentPushDisplay alloc] init];
     intent.controllerDisplay = push;
 
    ***********************************************************************************************************************
 
     //1.
     [[YBDControllerManager sharedInstance] startController:self intent:intent];
     //2.
     [[YBDControllerManager sharedInstance] startController:self intent:intent requestCode:1];
 
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    // In UserController.m
 
     @implementation UserController
 
    // params will be non-nil
     - (id)initWithExtras:(NSDictionary<NSString *,id> *)extras
     {
        if ((self = [self initWithNibName:nil bundle:nil])) 
        {
 
        }
        return self;
    }
 
    如果你想做自定义配置一个控制器,可以使用allocWithRouterParams:
 
    @implementation StoryboardController
     + (id)allocWithRouterParams:(NSDictionary *)params 
    {
        UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
        StoryboardController *instance = [storyboard instantiateViewControllerWithIdentifier:@"StoryboardController"];
        NSLog(@"================%@",params);
        return instance;
     }
    ======================================================================================================================
 */

@class YBIntent;
@interface YBControllerManager : NSObject

+ (instancetype)sharedInstance;
@property(nonatomic,assign)BOOL ignoresExceptions;

- (void)startController:(UIViewController *)source intent:(YBIntent *)intent;
- (void)startController:(UIViewController *)source intent:(YBIntent *)intent  requestCode:(NSNumber *)requestCode;

@end
