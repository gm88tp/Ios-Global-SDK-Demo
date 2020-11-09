//
//  wfnjiPlat.h
//
//  Created by wfnji on 16/8/15.
//  Copyright © 2016年 wfnji. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "wfnjiUserInfo.h"
#import "wfnjiLoginCallBack.h"
#import "wfnjiPayCallBack.h"
#import "wfnjiOrderModel.h"


/**
 游戏接入用到接口类
 */
@interface wfnjiPlat : NSObject

/*!
 单例,预留接口
 
 @return wfnjiPlat
 */
+(wfnjiPlat*)getInstance;

/**
 AppDelegate.h内的接口,主要用去.后台返回用
 
 @param application application
 */
+(void)applicationWillEnterForeground:(UIApplication *)application;

/**
 AppDelegate.h内的接口, 游戏从后台返回用
 
 
 */
+(void)applicationDidEnterBackground:(UIApplication *)application ;
/*
 
 要针对所有广告系列（包括使用通用链接的广告系列）将应用内事件作为转化衡量，
 您必须将以下代码段添加到应用的 application:continueUserActivity:restorationHandler 方法。
 */
+ (BOOL)application:(UIApplication *)application  continueUserActivity:(NSUserActivity *)userActivity;

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
 必须最先接入的方法  平台初始化方法
老版本使用
gameid 游戏的id
 promote 渠道
 
 */
+ (void) initSDK:(NSString*)gameid
      setPromote:(NSString*)promote
     application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
 appsFlyerDevKey:(NSString *)devKey
      appleAppID:(NSString *)appID
     GGkClientID:(NSString *)kClientID
         Applede:(id) app  ;

/**
 必须最先接入的方法  平台初始化方法
 */
+ (void) initSDKapplication:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
                    Applede:(id) app;

/**
 必须接入的方法  登录
 
 @param mLoginCallBack 回调
 */
+ (void) login:(id<wfnjiLoginCallBack>)mLoginCallBack;

/**
 支付时需要调用的方法
 
 @param payInfo 参数
 @param callBack 回调
 */
+ (void) wfnjipay:(wfnjiOrderModel *)payInfo CallBack:(id<wfnjiPayCallBack>) callBack;


 

/**
 查看当前的登录状态
 
 @return true or false
 */
+ (BOOL) isLogin;

/**
 注销账号
 */
+ (void) logout;


/**
 获取用户信息
 
 @return 用户信息
 */
+(wfnjiUserInfo*)getUserInfo;

/**
 获取游戏用户的唯一ID
 
 @return uid
 */
+ (NSString*) getUid;


/**
 获取用户名
 
 @return Nickname
 */
+ (NSString*) getNickname;

/**
 获取Token
 
 @return Token
 */
+ (NSString*) getToken;


/**
 游戏中调用返回提示，部分SDK需要调用SDK的退出提示，暂时没用,预留接口
 */
+ (void) quit;

/**
 获取当前 SDK 的号
 
 @return SDK 号，
 */
+(NSString*)versions;
///*
// 获取当前游戏用户注册或新手引导  =======废弃======
// */
//+(void)wfnjicreateTheRoleOrCompleteNewbieGuide:(selectStyle)selectStyle;
/**
 
 获取当前游戏的角色
 角色名字：name
 游戏等级：level
 区服:   serverID
 状态值默认选择<3>:status 1:创建角色 2:完成新手引导 3:等级升级
 游戏VIP等级：vipLevel
 */
+ (void)wfnjiRoleName:(NSString *)name
            gameLevel:(NSString *)level
             serverID:(NSString *)serverID
               roleID:(NSString *)roleID
               status:(NSString *)status
             vipLevel:(NSString *)vipLevel;

 
/**
c创建角色页面
 */
+ (void)createRole;
/**
 进入游戏主页面
 */
+ (void)showGamePage;

/**
选择屈服页面
 关闭
 */
+ (void)selectArea;

//获取多语言

+ (NSString *)setlaugulgString:(NSString *)str;


// 获取配置信息
+ (NSString*)getInfoString:(NSString*)str;

// 应用内切换账号
+ (void) WithInApplicationSwitch;

/*
 注册Google广告测试设备
 */

+(void)regisetAdGoogleDevice:(NSArray*)arr;

/*
加载等待loading页面
style 1 至 5
 */

+ (void)setLoadingImg:(UIImage *)image
                Color:(UIColor *)color
         loadingStyle:(NSInteger )style
              imgRect:(CGRect)rec;
/*
移除loading页面
 
 */

+ (void)removeLoadingImg;



+ (void)setCheckoutV:(int )status
         checkoutStr:(NSString * )str
        detaileTitle:(NSString *)detaileTitle;


+ (void)removeCheckoutVU;

//公开的打点数据方法
+ (void)LogInfo:(NSString *)eventName EventDic:(NSDictionary *)info;


/**
 分享使用的方法
 
 @param sharename 分享名
 @param shareID 分享ID
 @param share_uname 角色名
 @param share_server 角色区服
 @param share_code 角色code

 */
+ (void)ShareInfoName:(NSString *)sharename
                  ShareInfoID:(NSString *)shareID
                   shareUname:(NSString *)share_uname
                  shareServer:(NSString *)share_server
                   shareCode :(NSString *)share_code;


//返回渠道号
+ (NSString *)returnChannelID;


/**
 调用广告
 */
+ (void)choseADPlatForm    ;

/**
 调用广告
 type：0：激励广告；1：插页广告；2：横幅广告
 */
+ (void)choseADPlatForm:(NSInteger)type;

//显示绑定页面
+ (void)userInfoBindView;

//显示评价
+ (void)showMarkView;



+ (void)showWinLog;

/*
 广告 ，分享 ，绑定，翻译，vip客服 使用一个通知
 通知名：SDKCenterNotifition
 返回参数：status  0 广告失败
                 1 广告成功
                 2 分享失败
                 3 分享成功
                 4 绑定失败
                 5 绑定成功
                 6 未绑定
                 7 已绑定
                 8 绑定取消
                 9 取消广告
                 10 返回product多语言
                 11 返回product多语言失败
                 12 返回翻译
                 13 返回VIP客服不可显示
                 14 返回vip客服可显示
                 15 返回vip客服关闭

 */
//是否可以绑定
+ (void) isCanBind ;


// 推送相关
+ (void)application:(UIApplication *)application
didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken ;

// 推送相关
+ (void)application:(UIApplication *)application  didReceiveRemoteNotification:(NSDictionary *)userInfo;


//弹出文字

+ (void)toastInfo:(NSString *)text ;


+ (void) toastFacebook:(NSString * )info;


+ (void) toastbahamute:(NSString * )info;

+ (void) toastplatformCode:(NSString *)code Info:(NSString *)info  pageID:(NSString *)pageid;

// 返回设备号
+ (NSString *) returnIDFV;

// 返回广告ID
+ (NSString *) returnIDFA;

+ (NSString *)returnIDFVNomal;

// 获取内购列表
+ (void) setPurchaseInfo;

// 返回时区
+ (NSString *)returnTimeZome ;
// 返回语言码
+ (NSString *)returnLanguageCode;

+ (BOOL) isloading;

+ (void)translateText:(NSString *)text identifier:(NSString *)identifier;

+ (UIWindow *)currentWindow;

//跳转：1：商店；2：三方平台+浏览器
+ (void)showMarkViewType:(NSInteger)type;

//次数
+ (void)ADCounts:(NSString *)str;

//vip客服
+ (void)VIPCustomService;

//是否vip
+ (void)isCanVip;


+ (void)openLog:(BOOL)isOn;

@end

