//
//  wfnjiUserInfo.h
//  Mili
//
//  Created by mili on 2016/10/31.
//  Copyright © 2016年 wfnji. All rights reserved.
//

#import <Foundation/Foundation.h>
 


/**
 用户信息
 */
@interface wfnjiUserInfo : NSObject


/**
 用户的 UID
 */
@property (nonatomic, copy) NSString* uid;

/**
 用户的 Nickname
 */
@property (nonatomic, copy) NSString* nickname;

/**
 用户的 sid
 */
@property (nonatomic, copy) NSString* sid;

/**
 用户的 token
 */
@property (nonatomic, copy) NSString* token;

/**
 用户的头像地址
 */
@property (nonatomic, copy) NSString* face;//头像地址

/**
 用户的猫币数量
 */
@property (nonatomic, copy) NSString* coins;//

/**
 用户是否绑定手机
 */
@property (nonatomic,assign) BOOL need_bind;//是否绑定手机

/**
 
 */
@property (nonatomic,assign) int promote_coin;// 

/**
 用户积分
 */
@property (nonatomic) int user_point;//积分

@property (nonatomic, strong) NSString* phone;//手机号

@property (nonatomic, assign) BOOL  user_new;

@property (nonatomic, copy) NSString * selectType;


@property (nonatomic, strong) NSString *time;//存储时间

/**
 UserInfo转NSDictionary

 @param mUserInfo 用户信息
 @return NSDictionary
 */
+(NSDictionary*)UserInfoToNSDictionary:(wfnjiUserInfo*)mUserInfo;

/**
 NSDictionary转wfnjiUserInfo

 @param dic NSDictionary转wfnjiUserInfo
 @return wfnjiUserInfo
 */
+(wfnjiUserInfo*)NSDictionaryToUserInfo:(NSDictionary*)dic;

@end
