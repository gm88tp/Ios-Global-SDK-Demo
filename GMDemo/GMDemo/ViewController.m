//
//  ViewController.m
//  GMDemo
//
//  Created by rosehyird on 2020/4/29.
//  Copyright © 2020 rosehyird. All rights reserved.
//

#import "ViewController.h"

//登录
#import <loginSDK/platLogin.h>

//支付
#import <loginSDK/platPurchase.h>

//工具类
#import <loginSDK/platTools.h>

//支付需要传递对象的头文件
#import <loginSDK/purchaseModel.h>

//PurchaseCallBack 支付回调；LoginCallBack 登录回调
@interface ViewController ()<PurchaseCallBack,LoginCallBack,UITableViewDelegate,UITableViewDataSource>
@property (weak, nonatomic) IBOutlet UITableView *mTable;
@property (strong, nonatomic) NSArray *dataArray;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //设置SDK 通知
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notifitionCenter:)  name:@"SDKCenterNotifition" object:nil];
    
    //demo
    self.dataArray = @[@"登录",@"登出",@"切换账号",@"支付",@"广告",@"社交",@"分享",@"客服中心",@"常见问题",@"vip客服",@"角色信息上报",@"自定义打点上报",@"打开webview",@"其他",@"播放视频"];
}

#pragma mark - SDKCenterNotifition 通知回调结果
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
               NSLog(@"翻译完内容：%@",str);
           }
    }else if ([[Info objectForKey:@"status"] isEqualToString:@"13"]) {
        //vip客服不可显示
    }else if ([[Info objectForKey:@"status"] isEqualToString:@"14"]) {
        //vip客服可显示
    }else if ([[Info objectForKey:@"status"] isEqualToString:@"15"]) {
        //vip客服已关闭
    }else if ([[Info objectForKey:@"status"] isEqualToString:@"16"]) {
        //ip限制
    }else if ([[Info objectForKey:@"status"] isEqualToString:@"17"]) {
        //播放完成后用户点击关闭
        
    } else if ([[Info objectForKey:@"status"] isEqualToString:@"18"]) {
        //未播放完毕用户点击关闭
       
    } else if ([[Info objectForKey:@"status"] isEqualToString:@"19"]) {
        //视频播放失败
    }
}

#pragma mark - LoginCallBack
- (void)loginOnFinish:(loginStatus)code Data:(NSDictionary *)Data {
    NSLog(@"《登录》回调状态值：%ld",(long)code);
    
    
    NSLog(@"回调：%@",Data);
    if(code==LOGIN_SUCCESS){
    //登陆成功
    }else if(code ==LOGIN_SWITCH){
    //切换账号无需特殊处理
    }else if(code== LOGOUT_SUCCESS){
    //退出账号 需要主动拉起登陆
    }else if (code == LOGIN_UNUSE) {
    //封号退出程序
    exit(0);
    }
}

#pragma mark - PurchaseCallBack
- (void)purchaseOnFinish:(purchaseStatus)code Data:(NSDictionary *)Data {
    NSLog(@"《支付》回调状态值：%ld",(long)code);
    
    
    NSLog(@"回调：%@",Data);
    
    if (code == PURCHASE_SUCCESS){
        //支付成功
    } else if (code == PURCHASE_FAILED){
        //支付失败
    } else if (code == PURCHASE_CANCEL){
        //支付取消
    } else if (code == PURCHASE_UNKNOWN){
        //支付未知
    }
}

#pragma mark - 登录模块接口调用示例
- (void)login {
    //登录
    [platLogin login:self];
}

- (void)logout {
    //登出
    [platLogin logout];
}


- (void)switchAccount {
    //切换账号
    [platLogin WithInApplicationSwitch];
}

#pragma mark - 支付模块接口调用示例
- (void)pay {
    //支付
    purchaseModel * mPayInfo = [[purchaseModel alloc] init];
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
    
    [platPurchase purchase:mPayInfo CallBack:self];
    
}

#pragma mark - 工具型接口调用示例
#pragma 分享
- (void)share {
    //分享有两种接入方式，如下所示，可以按需接入
    //分享方法1：此方法cp接入ShareInfoName和ShareInfoID必须和我们后台配置相符合
    [platTools ShareInfoName:@"请传入分享信息"
                 ShareInfoID:@"分享id"
                  shareUname:@"角色名称"
                 shareServer:@"角色区服"
                   shareCode:@"角色code"
     ];
    
    //分享方法2：
    /**
     分享使用的方法
     
     @param text 分享文本
     @param image 图片列表，可以传空，传一张
     @param link 分享链接
     @param type 分享类型：1 引文分享（链接），2 图片分享,3 使用SDK后台配置分享
     @param info SDK后台配置分享，需要传入参数格式如下：
                @{@"shareName":@"分享名称",
                    @"shareID":@"分享ID",
                 @"shareUName":@"角色名",
                @"shareServer":@"角色区服",
                  @"shareCode":@"角色code"
     
                 }
     */
    //示例：图片分享
    [platTools shareInfo:@"请输入需要分享文案"
                   image:[UIImage imageWithData:[NSData dataWithContentsOfURL:[NSURL URLWithString:@"https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fimage.biaobaiju.com%2Fuploads%2F20180210%2F23%2F1518276333-RXexUJcntC.jpg&refer=http%3A%2F%2Fimage.biaobaiju.com&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=jpeg?sec=1614306450&t=e1c9d6c5223192f3f335c377048882bf"]] ]
                    link:@"此处示例图片分享，链接可以传空"
                    type:@"2"
               otherInfo:@{}];
}

#pragma 广告
- (void)ad {
    //广告有两种接入方式，如下所示，可以任意选择其中一种激励视频的接入
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"广告" message:@"请选择广告类型" preferredStyle:UIAlertControllerStyleActionSheet];
    UIAlertAction *ad1 = [UIAlertAction actionWithTitle:@"激励视频1" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [platTools choseADPlatForm];
    }];
    
    UIAlertAction *ad4 = [UIAlertAction actionWithTitle:@"激励视频2" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [platTools choseADPlatForm:0];
    }];
        
    UIAlertAction *ad2 = [UIAlertAction actionWithTitle:@"插页广告" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [platTools choseADPlatForm:1];
    }];
    UIAlertAction *ad3 = [UIAlertAction actionWithTitle:@"横幅广告" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [platTools choseADPlatForm:2];
    }];
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
            
    }];
    [alert addAction:ad1];
    [alert addAction:ad4];
    [alert addAction:ad2];
    [alert addAction:ad3];
    [alert addAction:cancel];
    alert.popoverPresentationController.sourceView = self.mTable;
    alert.popoverPresentationController.sourceRect = CGRectMake(10, 10, 100, 100);
    [self presentViewController:alert animated:YES completion:nil];
}

#pragma 角色信息上报
- (void)role {
    /**
    
    获取当前游戏的角色
    角色名字：name
    游戏等级：level
    区服:   serverID
    状态值默认选择<3>:status 1:创建角色 2:完成新手引导 3:等级升级
    */
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"上报角色打点" message:@"" preferredStyle:UIAlertControllerStyleActionSheet];
    UIAlertAction *ad1 = [UIAlertAction actionWithTitle:@"新手引导" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        //新手引导
        [platTools platRoleName:@"a" gameLevel:@"1" serverID:@"1" roleID:@"1" status:@"2" vipLevel:@""];
    }];
        
    UIAlertAction *ad2 = [UIAlertAction actionWithTitle:@"角色等级" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        //角色等级
        [platTools platRoleName:@"a" gameLevel:@"1" serverID:@"1" roleID:@"1" status:@"3" vipLevel:@""];
    }];
    
    UIAlertAction *ad3 = [UIAlertAction actionWithTitle:@"创建角色" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        //创建角色
        [platTools platRoleName:@"a" gameLevel:@"1" serverID:@"1" roleID:@"1" status:@"1" vipLevel:@""];
    }];
    

    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
            
    }];
    [alert addAction:ad1];
    [alert addAction:ad2];
    [alert addAction:ad3];
    [alert addAction:cancel];
    alert.popoverPresentationController.sourceView = self.mTable;
    alert.popoverPresentationController.sourceRect = CGRectMake(10, 10, 100, 100);
    [self presentViewController:alert animated:YES completion:nil];

}

#pragma 打点上报
- (void)upEvent:(NSString *)event {
    //自定义打点名称+参数
    [platTools LogInfo:event EventDic:@{}];
   
}

#pragma 打开社交平台
- (void)social {
    //打开社交有两种调用，cp可根据自己需要调用，详见接入文档
    //方法一：
    /**
     *param:
     *      code:2--facebook, 3--lobi, 4--appstore
     *      info：链接地址/包名/应用ID(无参数默认给个空字符)
     *      pageId：粉丝页ID（无参数默认给个空字符）
     **/
    [platTools toastplatformCode:@"2" Info:@"" pageID:@""];
    
    //方法二：
    /**
    *param:
    *      type:1--应用商店, 2--三方平台
    **/
    [platTools showMarkViewType:1];
}

#pragma 翻译
- (void)translate {
    /**
     *@param
     *     text:需要翻译的文本（必传）
     *     identifier：文本标识符（可不传）
     **/
    [platTools translateText:@"要翻译的文案" identifier:@"2"];
}

#pragma 客服中心
- (void)service {
    [platTools showCustomView];
}

#pragma vip客服
- (void)vipCS {
    //vip客服
    [platTools VIPCustomService];
}

#pragma 常见问题
- (void)FAQ {
    [platTools showFAQView];
}

#pragma 播放视频
- (void)playVideo {
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"视频" message:@"请选择播放视频" preferredStyle:UIAlertControllerStyleAlert];
        UIAlertAction *ad1 = [UIAlertAction actionWithTitle:@"本地视频" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            [platTools playVideo:[[NSBundle mainBundle] pathForResource:@"1" ofType:@"mp4"]];
            
        }];
    __block UITextField *shareName;
    [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.text =
        @"https://vd2.bdstatic.com/mda-mcg9h3vutekp38ua/cae_h264_clips/1615940899/mda-mcg9h3vutekp38ua.mp4?auth_key=1624950790-0-0-f48d491ec39e5d0dded6230910d27cb0&bcevod_channel=searchbox_feed&pd=1&pt=3&abtest=";

        shareName = textField;
    }];
        UIAlertAction *ad2 = [UIAlertAction actionWithTitle:@"网络视频" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            [platTools playVideo:shareName.text];
        }];
        
        UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
    
        }];
        [alert addAction:ad1];
        [alert addAction:ad2];
        [alert addAction:cancel];
    
        alert.popoverPresentationController.sourceView = self.mTable;
        alert.popoverPresentationController.sourceRect = CGRectMake(10, 10, 100, 100);
        [self presentViewController:alert animated:YES completion:nil];
}


#pragma 其他工具型接口
- (void)tools {
    
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"工具型接口" message:@"请选择需求自行接入相关接口" preferredStyle:UIAlertControllerStyleActionSheet];
    UIAlertAction *language = [UIAlertAction actionWithTitle:@"获取当前手机系统语言和地区" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
       NSString *str = [platTools returnLanguageCode];
        //此接口是弹出相应文字,将获取到的手机系统语言和地区弹出做示例
        [platTools toastInfo:str];
        
    }];
        
    UIAlertAction *version = [UIAlertAction actionWithTitle:@"获取SDK版本" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        NSString *str = [platTools versions];
        //此接口是弹出相应文字,将SDK版本弹出做示例
        [platTools toastInfo:str];
    }];
    UIAlertAction *zome = [UIAlertAction actionWithTitle:@"获取手机所在时区" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        NSString *str = [platTools returnTimeZome];
        //此接口是弹出相应文字,将获取手机所在时区弹出做示例
        [platTools toastInfo:str];
    }];
    
    UIAlertAction *device = [UIAlertAction actionWithTitle:@"设备信息" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        /**
         返回设备信息
         @return @{
                  @"system":设备系统信息,
                  @"model":  设备型号,
                  @"idfv":      设备idfv  }
         */
       NSLog(@"设备信息：%@",[platTools deviceInfo]);
    }];
    
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
            
    }];
    [alert addAction:language];
    [alert addAction:version];
    [alert addAction:zome];
    [alert addAction:device];
    [alert addAction:cancel];
    alert.popoverPresentationController.sourceView = self.mTable;
    alert.popoverPresentationController.sourceRect = CGRectMake(10, 10, 100, 100);
    [self presentViewController:alert animated:YES completion:nil];
}

#pragma mark - tableview

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return self.dataArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cellid"];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"cellid"];
    }
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    cell.textLabel.text = self.dataArray[indexPath.row];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.row == 0) {
        //登录
        [self login];
    } else if (indexPath.row == 1) {
        //登出
        [self logout];
    } else if (indexPath.row == 2) {
        //切换账号
        [self switchAccount];
    } else if (indexPath.row == 3) {
        //支付
        [self pay];
    } else if (indexPath.row == 4) {
        //广告
        [self ad];
    } else if (indexPath.row == 5) {
        //社交
        [self social];
    } else if (indexPath.row == 6) {
        //分享
        [self share];
    } else if (indexPath.row == 7) {
        //客服中心
        [self service];
    } else if (indexPath.row == 8) {
        //常见问题
        [self FAQ];
    } else if (indexPath.row == 9) {
        //vip客服
        [self vipCS];
    } else if (indexPath.row == 10) {
        //角色信息上报
        [self role];
    } else if (indexPath.row == 11) {
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"自定义打点" message:@"请输入点名" preferredStyle:UIAlertControllerStyleAlert];
        __block UITextField *input;
        [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            input = textField;
        }];
        
        UIAlertAction *up = [UIAlertAction actionWithTitle:@"上报" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            //自定义打点上报
            [self upEvent:input.text];
        }];
        UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
                
        }];
        [alert addAction:up];
        [alert addAction:cancel];
        
        alert.popoverPresentationController.sourceView = self.mTable;
        alert.popoverPresentationController.sourceRect = CGRectMake(10, 10, 100, 100);
        
        [self presentViewController:alert animated:YES completion:nil];
    } else if (indexPath.row == 12) {
        //打开链接
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"打开webview" message:@"请输入链接" preferredStyle:UIAlertControllerStyleAlert];
        __block UITextField *input;
        [alert addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
            input = textField;
        }];
        
        UIAlertAction *open = [UIAlertAction actionWithTitle:@"打开" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            //打开webview接口
            [platTools showViewWithStr:input.text];
        }];
        UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
                
        }];
        [alert addAction:open];
        [alert addAction:cancel];
        alert.popoverPresentationController.sourceView = self.mTable;
        alert.popoverPresentationController.sourceRect = CGRectMake(10, 10, 100, 100);
        [self presentViewController:alert animated:YES completion:nil];
    } else if (indexPath.row == 13) {
        //其他工具类方法
        [self tools];
    } else if (indexPath.row == 14) {
        [self playVideo];
    }
}

@end
