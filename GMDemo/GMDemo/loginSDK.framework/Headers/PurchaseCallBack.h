//
//  wfnjiPayCallBack.h
//  Mili
//
//  Created by mili on 2016/10/31.
//  Copyright © 2016年 wfnji. All rights reserved.
//

#ifndef wfnjiPayCallBack_h
#define wfnjiPayCallBack_h

#import <Foundation/Foundation.h>
 

typedef NS_ENUM(NSInteger,purchaseStatus){
    /** 支付成功 */
    PURCHASE_SUCCESS = 10,
    /** 支付失败*/
    PURCHASE_FAILED = 11,
    /** 支付取消 */
    PURCHASE_CANCEL = 12,
    /** 未知支付状态*/
    PURCHASE_UNKNOWN = 13
};

/**
 返回代理，需在调用前实例化
 */
@protocol PurchaseCallBack <NSObject>

@required
/**
 接口
 @param code 状态值

 @param Data 数据
 */
-(void)purchaseOnFinish:(purchaseStatus)code   Data:(NSDictionary*)Data;

@end
#endif /* wfnjiPayCallBack_h */
