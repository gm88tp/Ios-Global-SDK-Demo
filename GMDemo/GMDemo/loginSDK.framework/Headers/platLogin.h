//
//  platLogin.h
//  loginSDK
//
//  Created by xy on 2020/11/11.
//  Copyright © 2020 gumo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "loginCallBack.h"
#import "UserInfoModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface platLogin : NSObject
#pragma 登陆
/**
 必须接入的方法  登录
 @param mLoginCallBack 回调
 */
+ (void) login:(id<LoginCallBack>)mLoginCallBack;

#pragma 退出

/**
 账号退出
 */
+ (void) logout;

/**
 查看当前的登录状态
 @return true or false
 */
+ (BOOL) isLogin;

/**
 获取用户信息
 @return 用户信息
 */
+(UserInfoModel*)getUserInfo;

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
 显示绑定页面
 */
+ (void)userInfoBindView;

 
/**
 是否可以绑定
 结果在通知中回调
 */
+ (void) isCanBind ;


/**
 应用内切换账号
 */
+ (void) WithInApplicationSwitch;
@end

NS_ASSUME_NONNULL_END
