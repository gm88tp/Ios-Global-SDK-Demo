//
//  wfnjiStatus.h
//  Mili
//
//  Created by mili on 2016/10/31.
//  Copyright © 2016年 wfnji. All rights reserved.
//

#ifndef wfnjiStatus_h
#define wfnjiStatus_h

/**
 * wfnjiStatus 状态值
 * */
typedef NS_ENUM(NSInteger, wfnjiStatus){
    /** 登陆成功 */
    LOGIN_SUCCESS = 0,
   
   
    /** 切换账号*/
    LOGIN_SWITCH = 4,
    /** 退出成功*/
    LOGOUT_SUCCESS = 5,
    /** 账号被封*/
    LOGIN_UNUSE = 6,
    
   
    /** 支付成功 */
    PAY_SUCCESS = 10,
    /** 支付失败*/
    PAY_FAILED = 11,
    /** 支付取消 */
    PAY_CANCEL = 12,
    /** 未知支付状态*/
    PAY_UNKNOWN = 13
};


#endif /* MLStatus_h */
