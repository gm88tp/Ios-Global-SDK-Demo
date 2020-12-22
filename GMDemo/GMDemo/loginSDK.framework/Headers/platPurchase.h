//
//  platPurchase.h
//  loginSDK
//
//  Created by xy on 2020/11/11.
//  Copyright © 2020 gumo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PurchaseCallBack.h"
#import "purchaseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface platPurchase : NSObject
#pragma   purchaseModel
/*
 <purchaseModel>
 productID： id <必传>
 productName： 名<必传>
 productPrice：价格，可能有的SDK只支持整数<必传>
 productDes： 描述
 gameReceipts： 透传参数，订单信息<必传>
 roleID：游戏角色id
 roleName：游戏角色名
 roleLevel： 游戏角色等级
 vipLevel：Vip等级
 partyName： 帮派、公会等
 zoneID： 服务器id，若无填1
 zoneName： 服务器名
 text：扩展字段
 notifyURL：回调地址 可传可不传，不传使用默认
 */
+ (void) purchase:(purchaseModel *)payInfo CallBack:(id<PurchaseCallBack>) callBack;
@end

NS_ASSUME_NONNULL_END
