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
#import "wfnjiStatus.h"


/**
 登录回调代理
 */
@protocol wfnjiLoginCallBack <NSObject>

@required

/**
 登录回调接口

 @param code 状态值
 
 @param Data 数据
 */
-(void)onFinish:(wfnjiStatus)code   Data:(NSDictionary*)Data;

@end

#endif /* wfnjiLoginCallBack_h */
