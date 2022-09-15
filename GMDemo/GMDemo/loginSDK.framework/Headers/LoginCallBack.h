//
//  wfnjiLoginCallBack.h
//  Mili
//
//  Created by mili on 2016/10/31.
//  Copyright © 2016年 wfnji. All rights reserved.
//

#ifndef wfnjiLoginCallBack_h
#define wfnjiLoginCallBack_h

#import <Foundation/Foundation.h>
 

typedef NS_ENUM(NSInteger,loginStatus) {
    /** 登陆成功 */
    LOGIN_SUCCESS = 0,
    /**显示登录页面***/
    LOGIN_VIEW=1,
    /**静默自动登录失败***/
    LOGIN_SILENT_FAILURE=2,
    /** 切换账号*/
    LOGIN_SWITCH = 4,
    /** 退出成功*/
    LOGOUT_SUCCESS = 5,
    /** 账号被封*/
    LOGIN_UNUSE = 6,
    /** 登陆取消*/
    LOGIN_CANCEL=7,
    /**登陆报错*/
    LOGIN_FAILURE =8,
    /**删除账号*/
    DEL_ACCOUNT =9
    
};
/**
 登录回调代理
 */
@protocol LoginCallBack <NSObject>

@required

/**
 登录回调接口

 @param code 状态值
 
 @param Data 数据
 */
-(void)loginOnFinish:(loginStatus)code   Data:(NSDictionary*)Data;

@end

#endif /* wfnjiLoginCallBack_h */
