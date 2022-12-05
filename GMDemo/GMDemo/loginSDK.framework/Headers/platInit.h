//
//  platInit.h
//  loginSDK
//
//  Created by xy on 2020/11/11.
//  Copyright © 2020 gumo. All rights reserved.
//  firebase 10.2.0
//  fb 13
//  af 6.4.2
//  buad 4.6.0.5
//  fbad 6.11.1
//  ggad 9.50

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface platInit : NSObject

+(platInit*)getInstance;

/**
 AppDelegate.h内的接口,主要用去.后台返回用
 @param application application
 */
+(void)applicationWillEnterForeground:(UIApplication *)application;

/**
 AppDelegate.h内的接口, 游戏从后台返回用
 */
+(void)applicationDidEnterBackground:(UIApplication *)application ;
 

/**
 AppDelegate.
 @param app app
 @param url url
 @param options options
 @return BOOL
 */
+(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString *,id> *)options;

/**
 AppDelegate.h内的接口
 @param application application
 @param url url
 @param sourceApplication sourceApplication
 @param annotation annotation
 @return BOOL
 */
+(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;


/**
 AppDelegate.h内的接口
 
 @param app application
  需要调用一些事件激活
 */
+ (void)applicationDidBecomeActive:(UIApplication *)app;

/**
 AppDelegate.h内的接口
 游戏方向设置
 
 @param gameOrientation 1表示横屏游戏 0表示竖屏游戏
 */
+ (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window gameOrientation:(NSInteger)gameOrientation;

/**
 必须最先接入的方法  平台初始化方法
老版本使用
gameid 游戏的id
 promote 渠道
 
 */
#pragma 必须最先接入的方法 废弃

/*+ (void) initSDK:(NSString*)gameid
      setPromote:(NSString*)promote
     application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 appsFlyerDevKey:(NSString *)devKey
      appleAppID:(NSString *)appID
     GGkClientID:(NSString *)kClientID
         Applede:(id) app  ;*/

 
#pragma 必须最先接入的方法  平台初始化方法2 参数在login.bundle中设置
+ (void) initSDKapplication:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
                    Applede:(id) app;

+ (void) initSDKapplication:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
                    Applede:(id) app
                     gameID:(NSString *)gameId;
#pragma 推送相关
+ (void)application:(UIApplication *)application
didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken ;

#pragma 推送相关
+ (void)application:(UIApplication *)application  didReceiveRemoteNotification:(NSDictionary *)userInfo;

+ (void)FirebaseAd:(UIViewController *)viewController ;
+ (void)MaxbaseAd ;

+ (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray * _Nullable))restorationHandler;

@end

NS_ASSUME_NONNULL_END
