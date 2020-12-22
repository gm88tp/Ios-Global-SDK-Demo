//
//  platTools.h
//  loginSDK
//
//  Created by xy on 2020/11/11.
//  Copyright © 2020 gumo. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface platTools : NSObject
 
/**
 获取当前 SDK 的号
 @return SDK 号，
 */
+(NSString*)versions;
 
/**
 获取当前游戏的角色
 @param name 角色名字
 @param level 游戏等级
 @param serverID 区服
 @param status 状态值默认选择<3>: 1:创建角色 2:完成新手引导 3:等级升级
 @param vipLevel 游戏VIP等级
 */
+ (void)platRoleName:(NSString *)name
            gameLevel:(NSString *)level
             serverID:(NSString *)serverID
               roleID:(NSString *)roleID
               status:(NSString *)status
             vipLevel:(NSString *)vipLevel;

 
/**
 打点：创建角色页面
 老版本使用
 */
+ (void)createRole;

/**
 打点：进入游戏主页面
 老版本使用
 */
+ (void)showGamePage;

/**
 打点：选择屈服页面
 老版本使用
 */
+ (void)selectArea;

/**
 获取多语言
 @param str SDK资源包中多语言文件的key
 @return 多语言文案
 */
+ (NSString *)setlaugulgString:(NSString *)str;


/**
 获取配置信息
 @param str SDK资源包中infoset.plist参数的key
 @return 配置参数的值
 */
+ (NSString*)getInfoString:(NSString*)str;

 

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

/**
 数据打点
 @param eventName 事件名称
 @param info      参数，没有可以传空
 */
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


/**
 返回渠道号
 */
+ (NSString *)returnChannelID;

/**
 调用广告
 */
+ (void)choseADPlatForm;

/**
 调用广告
 @param type 0：激励广告；1：插页广告；2：横幅广告
 结果在通知中回调
 */
+ (void)choseADPlatForm:(NSInteger)type;


/**
 显示评价
 */
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



/**
 弹出文字提示
 @param text 文本内容
 */
+ (void) toastInfo:(NSString *)text;


// 返回设备号
+ (NSString *) returnIDFV;

/*
 * 返回广告ID
 */
+ (NSString *) returnIDFA;

+ (NSString *)returnIDFVNomal;

/*
 * 获取内购列表
 */
+ (void) setPurchaseInfo;

/*
 * 返回时区
 */
+ (NSString *)returnTimeZome ;

/*
 * 返回语言码
 */
+ (NSString *)returnLanguageCode;

+ (BOOL) isloading;

/**
 翻译
 @param text 需要翻译的文本
 @param identifier 文本标识符（透传字段）
 结果在通知中回调
 */
+ (void)translateText:(NSString *)text identifier:(NSString *)identifier;

+ (UIWindow *)currentWindow;

/**
 打开社交平台方法一
 @param code 2、Facebook;3、lobi；4、应用商店
 @param info 链接地址/包名/应用ID (无参数默认给个空字符)
 @param pageid 粉丝页ID(无参数默认给个空字符)
 */
+ (void) toastplatformCode:(NSString *)code Info:(NSString *)info  pageID:(NSString *)pageid;

/**
 打开社交平台方法二
 @param type 1：商店；2：三方平台+浏览器
 */
+ (void)showMarkViewType:(NSInteger)type;



/**
 广告剩余显示次数
 @param str 次数，没有限制可不调用此方法
 */
+ (void)ADCounts:(NSString *)str;

/*
 *vip客服
 */
+ (void)VIPCustomService;

/*
 *是否可以显示vip
 */
+ (void)isCanVip;

/*
 *日志，是否开启日志
 */
+ (void)openLog:(BOOL)isOn;

/*
 *客服入口
 */
+ (void)showCustomView;

/*
 *常见问题入口
 */
+ (void)showFAQView;

/**
 打开入口
 @param str 链接
 */
+ (void)showViewWithStr:(NSString *)str;

@end

NS_ASSUME_NONNULL_END
