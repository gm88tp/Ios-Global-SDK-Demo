//
//  OrderModel.h
//  SDK
//
//  Created by  on 2018/4/12.
//  Copyright © 2018年 . All rights reserved.
//

#import <Foundation/Foundation.h>

@interface wfnjiOrderModel : NSObject

/** id */
@property (nonatomic,copy)NSString* productID;
/** 名 */
@property (nonatomic,copy)NSString* productName;
/** 价格(元)，可能有的SDK只支持整数 */
@property (nonatomic,copy)NSString* productPrice;
/** 描述（不传则使用productName） */
@property (nonatomic,copy)NSString* productDes;
/** 游戏传入的有关用户的区id，服务器id，角色id */
@property (nonatomic,copy)NSString* gameReceipts;
/** Y 游戏角色id */
@property (nonatomic,copy)NSString* roleID;
/** Y 游戏角色名 */
@property (nonatomic,copy)NSString* roleName;
/** 游戏角色等级 */
@property (nonatomic,copy)NSString* roleLevel;
/** Y Vip等级 */
@property (nonatomic,copy)NSString* vipLevel;
/** Y 帮派、公会等 */
@property (nonatomic,copy)NSString* partyName;
/** Y 服务器id，若无填“1” */
@property (nonatomic,copy)NSString* zoneID;
/** Y 服务器名 */
@property (nonatomic,copy)NSString* zoneName;
/** N 扩展字段 */
@property (nonatomic,copy)NSString* text;
/** 回调地址 */
@property (nonatomic,copy)NSString* notifyURL;


@end
