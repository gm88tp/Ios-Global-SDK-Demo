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
 @param serverID 服id
 @param serverName 服名称
 @param roleID 角色id
 @param globalRoleID 全局唯一的角色id
 @param status 状态值默认选择<3>: 1:创建角色 2:完成新手引导 3:等级升级 4:每次进入游戏
 @param vipLevel 游戏VIP等级
 @param zoneID 大区id,没有大区，请默认输入@"0"
 @param zoneName 大区名称,没有大区，请默认输入@"0"
 */
+ (void)platRoleName:(NSString *)name
            gameLevel:(NSString *)level
             serverID:(NSString *)serverID
            serverName:(NSString *)serverName
               roleID:(NSString *)roleID
        globalRoleID:(NSString *)globalRoleID
               status:(NSString *)status
             vipLevel:(NSString *)vipLevel
                zoneID:(NSString *)zoneID
              zoneName:(NSString *)zoneName;


+ (void)platRoleName:(NSString *)name
            gameLevel:(NSString *)level
             serverID:(NSString *)serverID
       
               roleID:(NSString *)roleID
               status:(NSString *)status
             vipLevel:(NSString *)vipLevel;

/**
 获取当前角色是否预约
 @param serverId 区服
 @param roleId 角色id
 @param notifyUrl 通知地址
 @param extra 额外信息
 */
+ (void)checkPreOrder:(NSString *)roleId serverId:(NSString *)serverId notifyUrl:(NSString *)notifyUrl extra:(NSString *)extra;



 
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

+ (void)LogFBInfo:(NSString *)eventName EventDic:(NSDictionary *)info;

+ (void)LogAFInfo:(NSString *)eventName EventDic:(NSDictionary *)info;

+ (void)LogFirbaseInfo:(NSString *)eventName EventDic:(NSDictionary *)info;


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
 分享使用的方法
 
 @param text 分享文本
 @param image 图片列表，可以传空，传一张
 @param link 分享链接
 @param type 分享类型：1 引文分享（链接），2 图片分享,3 使用SDK后台配置分享
 @param info SDK后台配置分享，需要传入参数格式如下：
            @{@"shareName":@"分享名称",
                @"shareID":@"分享ID",
             @"shareUName":@"角色名",
            @"shareServer":@"角色区服",
              @"shareCode":@"角色code" }
 */
+ (void)shareInfo:(NSString *)text image:(UIImage *)image link:(NSString *)link type:(NSString *)type otherInfo:(NSDictionary *)info;



/**
 返回渠道号
 */
+ (NSString *)returnChannelID;

/** 预加载广告 */
+ (void)preloadAD;
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

 

/*
 广告 ，分享 ，绑定，翻译，vip客服，播放视频 使用一个通知
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
                 13 广告开始播放
                 14 accsetoken 获取成功
                 15 accsetoken 获取失败
                 16 国内ip禁止播放广告
                 17 取消分享
                 18 预加载成功
                 19 预加载失败
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
 #pragma 打开社交平台方法一
 @param code  （2，3，6，7，9，10）会提供info和pageid 内容  其他媒体使用code5
 code:1 预留接口
 code:2  Facebook粉丝页或者群组页面
 code:3  luobi主页
 code:4  引导应用评价
 code:5  手机浏览器内打开页面
 code:6  打开抖音主页
 code:7  打开ins主页
 code:8  应用打开页面，注:必须接入项。活动页需要使用
 code:9  打开youtube主页
 code:10  打开line群组
 code:其他 手机浏览器内打开页面
 @param info 链接地址/包名/应用ID
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
//+ (void)VIPCustomService;

/*
 *是否可以显示vip
 */
//+ (void)isCanVip;

/*
 *日志，是否开启日志
 */
+ (void)openLog:(BOOL)isOn;




/**
 打开入口
 @param str 链接
 */
+ (void)showViewWithStr:(NSString *)str;
/**
 打开入口
 @param str 链接
 @param direction 0:默认游戏设置方向，1、竖屏，2、横屏
 */
+ (void)showViewWithStr:(NSString *)str direction:(NSInteger)direction ;

/**
 返回设备信息
 @return @{
          @"system":设备系统信息,
          @"model":  设备型号,
          @"idfv":      设备idfv  }
 */
+ (NSDictionary *)deviceInfo;

/**
播放视频
 @param str 视频地址
 */
+ (void)playVideo:(NSString *)str;

/**
用户中心
 */
+ (void)userCenter;

/**
 帮助中心 修改成进入客服
 */
+ (void)helpCenter;

+(void)openWinLog:(BOOL)isOn;
+(void)logInfoStr:(id)name;


/**
 扫描二维码
 */
+ (void)scanQRCode;


+ (NSDictionary *)strTodic:(NSString *)jsonString ;
   

/**
 字典转换为json字符串
 
 @param dic 需要转换的字典
 @return json 类型的字符串
 */
+ (NSString *) dicTostr:(NSDictionary *)dic;
/*
 *客服入口
 接口废弃
 */
+ (void)showCustomView;

/*
 *常见问题入口
 接口废弃
 */
+ (void)showFAQView;
@end

NS_ASSUME_NONNULL_END
