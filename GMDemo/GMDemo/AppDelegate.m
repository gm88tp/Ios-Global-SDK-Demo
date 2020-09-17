//
//  AppDelegate.m
//  GMDemo
//
//  Created by rosehyird on 2020/4/29.
//  Copyright © 2020 rosehyird. All rights reserved.
//

#import "AppDelegate.h"
#import <loginSDK/wfnjiPlat.h>
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //初始化有两个接口，如下,请选择其中一种进行初始化，  推荐使用方式一，详见接入文档
    /**
     *方式一：
     *参数全部在bundle中
     **/
    [wfnjiPlat initSDKapplication:application didFinishLaunchingWithOptions:launchOptions Applede:self];
    
    /**
    *方式二：
    * 自行传入相关参数
    **/
//    [wfnjiPlat
//    initSDK : @"游戏id"
//    setPromote : @"17"
//    application : application
//    didFinishLaunchingWithOptions : launchOptions
//    appsFlyerDevKey : @"appflyer的devkey"
//    appleAppID : @"苹果id"
//    GGkClientID : @"google id"
//    Applede:self];
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    [wfnjiPlat applicationDidEnterBackground:application];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    [wfnjiPlat applicationWillEnterForeground:application];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    [wfnjiPlat applicationDidBecomeActive:application];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


-(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString *,id> *)options{
    return [wfnjiPlat application:app openURL:url options:options];
}

-(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation{
   
    return  [wfnjiPlat application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(nonnull NSData *)deviceToken{
    [wfnjiPlat application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
}


- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary * _Nonnull)userInfo{
    [wfnjiPlat application:application didReceiveRemoteNotification:userInfo];
}


- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    [wfnjiPlat application:application didReceiveRemoteNotification:userInfo];
}

@end
