//
//  ViewController.m
//  GMDemo
//
//  Created by rosehyird on 2020/4/29.
//  Copyright © 2020 rosehyird. All rights reserved.
//

#import "ViewController.h"
#import <loginSDK/wfnjiPlat.h>
@interface ViewController ()<wfnjiLoginCallBack,wfnjiPayCallBack>
@property (weak, nonatomic) IBOutlet UITextField *eventTF;
@property (weak, nonatomic) IBOutlet UITextField *textTF;
@property (weak, nonatomic) IBOutlet UILabel *translatedLb;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //设置SDK 通知
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notifitionCenter:)  name:@"SDKCenterNotifition" object:nil];
}

- (void)notifitionCenter:(NSNotification *)notification {
    NSDictionary * Info = (NSDictionary *)notification.object;
       
    if([[Info objectForKey:@"status"] isEqualToString:@"0"]){
           //广告失败
    }else  if([[Info objectForKey:@"status"] isEqualToString:@"9"]) {
           //取消广告
    }else  if([[Info objectForKey:@"status"] isEqualToString:@"1"]) {
           //广告成功
    }else  if([[Info objectForKey:@"status"] isEqualToString:@"2"]) {
           //分享失败
    }else  if([[Info objectForKey:@"status"] isEqualToString:@"3"]) {
           //分享成功
    }else  if([[Info objectForKey:@"status"] isEqualToString:@"10"]) {
           //返回商品信息成功
        //商品信息
        [Info objectForKey:@"product"];
    }else  if([[Info objectForKey:@"status"] isEqualToString:@"11"]) {
           //返回商品信息失败
    }else  if([[Info objectForKey:@"status"] isEqualToString:@"12"]) {
           //返回翻译
        //可以根据code的值，当值为1时，表示获取到翻译。翻译内容是translate的值
           if([[Info objectForKey:@"code"]isEqualToString:@"1"]){
                NSString *str = [Info objectForKey:@"translate"];
               self.translatedLb.text = str;
           }
    }else if ([[Info objectForKey:@"status"] isEqualToString:@"13"]) {
        //vip客服不可显示
    }else if ([[Info objectForKey:@"status"] isEqualToString:@"14"]) {
        //vip客服可显示
    }else if ([[Info objectForKey:@"status"] isEqualToString:@"15"]) {
        //vip客服已关闭
    }
}

#pragma mark - wfnjiLoginCallBack,wfnjiPayCallBack
-(void)onFinish:(wfnjiStatus)code   Data:(NSDictionary*)Data {
    NSLog(@"回调状态值：%ld",(long)code);
    
    
    NSLog(@"回调：%@",Data);
    if(code==LOGIN_SUCCESS){
        
        //登录成功
    }
    else if(code== LOGOUT_SUCCESS){
        //登出成功
    }else if (code ==PAY_SUCCESS){
        //支付成功
    } else if (code== PAY_FAILED){
        //支付失败
    } else if (code==PAY_CANCEL){
        //支付取消
    } else if (code==PAY_UNKNOWN){
        //支付未知
    }
}

- (IBAction)login:(id)sender {
    //登录
    [wfnjiPlat login:self];
}

- (IBAction)logout:(id)sender {
    //登出
    [wfnjiPlat logout];
}
- (IBAction)switchAccount:(id)sender {
    //切换账号
    [wfnjiPlat WithInApplicationSwitch];
}



- (IBAction)pay:(id)sender {
    //支付
    wfnjiOrderModel* mPayInfo = [[wfnjiOrderModel alloc] init];
    /** 商品id */
    mPayInfo.productID=@"商品id";
    /** Y 商品名 */
    mPayInfo.productName=@"商品名称";
    /** Y 商品价格 */
    mPayInfo.productPrice=@"价格";
    /** 商品描述（不传则使用productName） */
    mPayInfo.productDes=@"商品描述";
    /** 游戏传入的有关用户的区id，服务器id，角色id,订单等，属于透传数据功能 */
    mPayInfo.gameReceipts=@"透传数据";
    /** Y 游戏角色id */
    mPayInfo.roleID=@"";
    /** Y 游戏角色名 */
    mPayInfo.roleName=@"";
    /** 游戏角色等级 */
    mPayInfo.roleLevel=@"";
    /** Y Vip等级 */
    mPayInfo.vipLevel=@"";
    /** Y 帮派、公会等 */
    mPayInfo.partyName=@"";
    /** Y 服务器id，若无填“1” */
    mPayInfo.zoneID=@"";
    /** Y 服务器名 */
    mPayInfo.zoneName=@"";
    /** N 扩展字段 */
    mPayInfo.text=@"";
    /**
     回调地址 可传可不传，不传使用默认
     */
     mPayInfo. notifyURL = @"1234567890-123456789";
    
    [wfnjiPlat wfnjipay:mPayInfo CallBack:self];
    
}
- (IBAction)share:(id)sender {
    [wfnjiPlat ShareInfoName:@"请传入分享信息"
                 ShareInfoID:@"分享id"
                  shareUname:@"角色名称"
                 shareServer:@"角色区服"
                   shareCode:@"角色code"
     ];
}
- (IBAction)ad:(id)sender {
    //广告有两种接入方式，如下所示，可以任意选择其中一种激励视频的接入
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"广告" message:@"请选择广告类型" preferredStyle:UIAlertControllerStyleActionSheet];
    UIAlertAction *ad1 = [UIAlertAction actionWithTitle:@"激励视频1" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [wfnjiPlat choseADPlatForm];
    }];
    
    UIAlertAction *ad4 = [UIAlertAction actionWithTitle:@"激励视频2" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [wfnjiPlat choseADPlatForm:0];
    }];
        
    UIAlertAction *ad2 = [UIAlertAction actionWithTitle:@"插页广告" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [wfnjiPlat choseADPlatForm:1];
    }];
    UIAlertAction *ad3 = [UIAlertAction actionWithTitle:@"横幅广告" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [wfnjiPlat choseADPlatForm:2];
    }];
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
            
    }];
    [alert addAction:ad1];
    [alert addAction:ad4];
    [alert addAction:ad2];
    [alert addAction:ad3];
    [alert addAction:cancel];
    [self presentViewController:alert animated:YES completion:nil];
}

- (IBAction)role:(id)sender {
    /**
    
    获取当前游戏的角色
    角色名字：name
    游戏等级：level
    区服:   serverID
    状态值默认选择<3>:status 1:创建角色 2:完成新手引导 3:等级升级 4：进入游戏
    */
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"上报角色打点" message:@"" preferredStyle:UIAlertControllerStyleActionSheet];
    UIAlertAction *ad1 = [UIAlertAction actionWithTitle:@"新手引导" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        //新手引导
        [wfnjiPlat wfnjiRoleName:@"a" gameLevel:@"1" serverID:@"1" roleID:@"1" status:@"2"];
    }];
        
    UIAlertAction *ad2 = [UIAlertAction actionWithTitle:@"角色等级" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        //角色等级
        [wfnjiPlat wfnjiRoleName:@"b" gameLevel:@"" serverID:@"1" roleID:@"2" status:@"3"];
    }];
    
    UIAlertAction *ad3 = [UIAlertAction actionWithTitle:@"创建角色" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        //创建角色
        [wfnjiPlat wfnjiRoleName:@"b" gameLevel:@"" serverID:@"1" roleID:@"2" status:@"1"];
    }];
    
    UIAlertAction *ad4 = [UIAlertAction actionWithTitle:@"进入游戏" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        //进入游戏
        [wfnjiPlat wfnjiRoleName:@"b" gameLevel:@"" serverID:@"1" roleID:@"2" status:@"4"];
    }];

    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
            
    }];
    [alert addAction:ad1];
    [alert addAction:ad2];
    [alert addAction:ad3];
    [alert addAction:ad4];
    [alert addAction:cancel];
    [self presentViewController:alert animated:YES completion:nil];

}

- (IBAction)upEvent:(id)sender {
    [wfnjiPlat LogInfo:self.eventTF.text EventDic:nil];
   
}

- (IBAction)social:(id)sender {
    //打开社交有两种调用，cp可根据自己需要调用，详见接入文档
    //方法一：
    /**
     *param:
     *      code:2--facebook, 3--lobi, 4--appstore
     *      info：链接地址/包名/应用ID(无参数默认给个空字符)
     *      pageId：粉丝页ID（无参数默认给个空字符）
     **/
    [wfnjiPlat toastplatformCode:@"2" Info:@"" pageID:@""];
    
    //方法二：
    /**
    *param:
    *      type:1--应用商店, 2--三方平台
    **/
    [wfnjiPlat showMarkViewType:1];
}

- (IBAction)tran:(id)sender {
    /**
     *param
     *     text:需要翻译的文本（必传）
     *     identifier：文本标识符（可不传）
     **/
    [wfnjiPlat translateText:self.textTF.text identifier:@"2"];
}

- (IBAction)vipCS:(id)sender {
    [wfnjiPlat VIPCustomService];
}

- (IBAction)tools:(id)sender {
    
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"工具型接口" message:@"请选择需求自行接入相关接口" preferredStyle:UIAlertControllerStyleActionSheet];
    UIAlertAction *language = [UIAlertAction actionWithTitle:@"获取当前手机系统语言和地区" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
       NSString *str = [wfnjiPlat returnLanguageCode];
        //此接口是弹出相应文字,将获取到的手机系统语言和地区弹出做示例
        [wfnjiPlat toastInfo:str];
        
    }];
        
    UIAlertAction *version = [UIAlertAction actionWithTitle:@"获取SDK版本" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        NSString *str = [wfnjiPlat versions];
        //此接口是弹出相应文字,将SDK版本弹出做示例
        [wfnjiPlat toastInfo:str];
    }];
    UIAlertAction *zome = [UIAlertAction actionWithTitle:@"获取手机所在时区" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        NSString *str = [wfnjiPlat returnTimeZome];
        //此接口是弹出相应文字,将获取手机所在时区弹出做示例
        [wfnjiPlat toastInfo:str];
    }];
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
            
    }];
    [alert addAction:language];
    [alert addAction:version];
    [alert addAction:zome];
    [alert addAction:cancel];
    [self presentViewController:alert animated:YES completion:nil];
}

@end
