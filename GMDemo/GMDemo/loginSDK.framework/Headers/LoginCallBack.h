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
   
    /** 切换账号*/
    LOGIN_SWITCH = 4,
    /** 退出成功*/
    LOGOUT_SUCCESS = 5,
    /** 账号被封*/
    LOGIN_UNUSE = 6,
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
