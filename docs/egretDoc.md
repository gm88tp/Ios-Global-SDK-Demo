# Gm88海外H5游戏SDK 对接文档

本文档旨在帮忙CP对接Gm88游戏的登陆和支付，Gm88也会提供相应SDK需要的技术文件。

## 1. 适用范围

* 只面向使用白鹭(Egret)引擎开发的H5游戏
* 只面向海外地区，国内地区请联系对接的Gm88运营

## 对接流程

CP应先提供相应信息给到运营，然后进行后端对接，完成后再根据游戏发行的终端，进行各终端的对接

对接流程如下图：

```
    graph TD
    信息提供[CP提供对接游戏信息] --> 加密信息[Gm88提供appId和appSecret]
    加密信息 --> 后端对接[CP进行对接后端对接]
    后端对接 --> H5端对接[CP进行H5端对接]
    后端对接 --> Android端对接
    后端对接 --> IOS端对接
    H5端对接 --> Gm88输出H5端游戏地址
    Android端对接 --> Android端输出[CP使用白鹭引擎输出Android工程]
    Android端输出 --> Android端发布[Gm88前端输出Android包,提审Google Play]
    IOS端对接 --> IOS端输出[CP使用白鹭引擎输出IOS工程]
    IOS端输出 --> IOS端发布[Gm88前端输出IOS包,提审Apple Store]
```

## 2. 前期信息对接

前两步只是信息提供，后三步是技术文档对接，以下说明具体步骤。

### 2.1 CP方提供对接游戏信息

具体信息包括：

* 游戏名称
* 游戏Icon
* 游戏简介
* 游戏测试地址
* 充值回调地址

请将以上信息提供给对接的运营人员

### 2.2 Gm88方提供加密信息

Gm88的运营人员根据第一步提供的信息，生成appId和appSecret，并提供给CP，这两者会在加密传输时用到。

## 3. 后端对接

后端对接是技术对接的第一步，由于是H5游戏，我们通过htpp请求来对接用户信息的部分。

#### 3.1 AccessToken传递

Gm88会在游戏访问地址之后，使用GET方式传输AccessToken，这引参数将在下一步登陆接口调用时用到，CP方可将此AccessToken临时存储。

#### 3.2 登陆接口

CP方可以使用此接口获得用户信息

UserInfo /GET

**地址**

https://open.hkpctimes.com/UserInfo

**参数**

| 字段          | 类型     | 描述                  |
| ----------- | ------ | ------------------- |
| accessToken | string | 加载游戏时传入的accessToken |

**返回**

| 字段        | 类型     | 描述           |
| --------- | ------ | ------------ |
| code      | Int    | 0:正确   其他：错误 |
| res       | object | 用户信息         |
| msg       | string | 错误信息         |
| sys\_time | Int    | 服务器时间戳       |

**res参数中的内容**

| 字段     | 类型     | 描述     |
| ------ | ------ | ------ |
| openid | Int    | 用户唯一ID |
| name   | string | 用户名    |

#### 3.2 支付回调

这是用户支付完成之后，Gm88方确认用户已经付款完成时，发起的异步支付成功通知，CP方应有后端程序接收此请求，并在接收到此通知后，在游戏内向用户发货，并返回正确的响应，以便Gm88后端知晓发放成功。

异步通知 

请求类型：POST

**回调参数**

| 字段            | 类型     | 说明                                |
| ------------- | ------ | --------------------------------- |
| order\_id     | int    | Gm88订单号                             |
| server\_id    | int    | H5                                |
| role\_id      | int    | 用户唯一ID，和用户openId相同                |
| developerinfo | string | 自定义参数，和下单的extra相同，请参数4.1章节的发起支付接口 |
| coin          | float  | 订单金额，单位：美元                        |
| signature     | string | 签名字段                              |

**signature签名**

* 将以上字段连接,再加上app私钥,最后计算md5值。如

```
signature = md5(order_id=xxx&server_id=xxx&role_id=xxx&developerinfo=xxx&coin=xxx&appSecret)
```

**加密示例(PHP)**

```php
$appSecret = 'nHxJ8D8YkbZmYfTE';

$data = array(
    'order_id' => '2018112601033300001',
    'server_id' => '1',
    'role_id' => '0',
    'developerinfo' => 'developerinfo1543219387578',
    'coin' => '6.00'
);

$perstr = 'order_id=2018112601033300001&server_id=1&role_id=0&developerinfo=developerinfo1543219387578&coin=6.00&nHxJ8D8YkbZmYfTE';

$signature = md5($perstr); // a827d5349551c56b11aae65d9ace3a66
```

CP收到请求后，应进行发货操作，在发货成功后返回“ok“(字符串)，表示已经接收支付结果，如未收到ok，系统会每隔5分钟发起一次通知，如果发货是异步的，可以返回"ok"，但请保证后续发货一定成功。

### 3.3 支付订单查询（可选）

CP在收到支付回调之后，可以使用此接口查询订单状态

接口地址：https://m.hkpctimes.com/api/index.php 

请求类型：POST

| 字段        | 类型     | 说明        |
| --------- | ------ | --------- |
| action    | string | 定值:verify |
| game_id   | int    | appID     |
| order_id  | Int    | 订单ID      |
| signature | string | 签名字段      |

**signature签名**

* 将以上字段连接,再加上app私钥,最后计算md5值。如

```
signature = md5(action=verify&game_id=xxx&order_id=xxx&APP_SECRET)
```

返回内容为json格式：

**正确返回示例：**

```javascript
{
    "data":{
        "status":"N",  // Y：成功
        "server_id":"3服", // 区服
        "role_id":"668", // 角色ID
        "developerinfo":"game_3-668-7878", // 透传参数
        "coin":"648", // 订单金额
        "pay_time":"2018-12-30 02:54:39" // 支付时间
    },
    "status":true
}
```

**错误返回示例**

```javascript

{
    "status":false,
    "errorno":101,
    "errortext":"签名错误"
}
```

## 4. Android/IOS端对接

Android和IOS的对接方式相同，所以一并叙述。在完成后端对接后，应该使用白鹭引擎导出Android/IOS工程文件，并提供给怪猫。这种由白鹭官方的IDE提供，可以通过白鹭一键生成。

在输出Android/IOS工程之前，应按白鹭官方文档方法，对接以下三个JS接口

### 4.1 发起支付接口

当游戏内需发起支付时，应调用此接口

接口定义：doPay(String payJson)

**payJson参数**

| 字段          | 类型     | 说明                                 |
| ----------- | ------ | ---------------------------------- |
| productName | string | 商品名称，会显示在相应支付界面上                   |
| price       | float  | 商品价格，单位：美元                         |
| extra       | string | 订单透传参数，这些参数会在支付回调时一并回传给CP，请CP自行解析  |
| payStage    | string | 额外支付参数（默认为商品ID）                    |
| roleId      | string | 待支付角色ID                            |
| serverId    | string | 待支付角色区服名称或者ID                      |
| productId   | string | 商品ID                               |
| notifyUrl   | string | 支付通知地址，没有的话请不要传递该参数(请求信息内不需要该参数为空) |

Java示例

```java
String payJson = "{
    productName:"xx", 
    price: "xx",
    extra: "xx",
    payStage: "xx",
    roleId: "xx",
    serverId: "xx",
    productId: "xx"
}";
doPay(payJson)
```

### 4.2 角色信息变更接口

接口定义： doSpot(String spotJson)

| 字段       | 类型     | 说明                                                                                    |
| -------- | ------ | ------------------------------------------------------------------------------------- |
| spotType | string | 事件类型，取值为：1：创建角色   2：完成新手引导 3：玩家等级变化后上传 4:玩家选择完区服                                      |
| extra    | json   | 这是角色具体信息，格式为Json，包括4种信息：roleId: 角色ID, roleName： 角色名，roleServer：  角色区服，roleLevel： 角色等级 |

java调用示例：

```java
String spotJson = "{
    "spotType":   "1" , 
    "extra": {
        "roleName": "角色名" , 
        "roleServer": "区服名",
        "roleLevel": "10",
        "roleId":"1"
    }
}";
doSpot(spotJson)
```

### 4.3 游戏加载完成接口

当游戏加载完成时，应调用此接口，告知IOS/Android原生端

接口定义：doCancelLoading()

java调用示例：

```java
doCancelLoading();
```

### 4.4 发起分享

当游戏需要拉起分享的时候，应调用此接口，告知IOS/Android原生端

接口定义：share(String shareInfo)

调用示例：

```java
String shareInfo = "{"shareID":"1","shareName":"每日分享","uName":"分享者游戏名","server":"分享者所在区服","code":"邀请码"}"
doShare(shareInfo);
```

shareInfo 示例:

| 字段        | 类型     | 说明               |
| --------- | ------ | ---------------- |
| shareID   | int    | 分享内容Id(Gm88运营提供)   |
| shareName | string | 分享内容Name(Gm88运营提供) |
| uName     | string | 分享者游戏名           |
| server    | string | 分享者所在区服          |
| code      | string | 邀请码(可供接受分享者使用等)  |

同时，会给游戏对应的分享回调

```java
 doShareDone(String status)
```

| 字段     | 类型     | 说明                     |
| ------ | ------ | ---------------------- |
| status | string | 1：分享成功    0：分享失败或者分享取消 |

返回示例 ：

```java
doShareDone("{"status":"1"}")
```

### 4.5 拉起广告

当游戏需要拉起广告的时候，应调用此接口，告知IOS/Android原生端

接口定义：doAdShow(String extra)

| 字段    | 类型     | 说明                   |
| ----- | ------ | -------------------- |
| extra | string | 广告透传参数，在成功的回调内，会原样返回 |

调用示例：

```java
 doAdShow(String extra);            
```

 同时，会给游戏对应的回调               

```java
doAdShowDone(String adInfo)
```

返回示例: 

```java
doAdShowDone("{"status":"1","extra":"info"}")
```

| 字段     | 类型     | 说明                                   |
| ------ | ------ | ------------------------------------ |
| status | string | 1：激励视频播放成功    0：激励视频播放失败   -1: 当前无广告 |
| extra  | string | 广告透传参数，为发起广告时传过来的参数                  |

### 4.6 游戏内行为打点（非必接，若运营有需求，需要接入）

当游戏内发生相关行为后，应调用此接口，告知IOS/Android原生端

接口定义：doEventInfo(String eventInfo)

| 字段        | 类型     | 说明               |
| --------- | ------ | ---------------- |
| eventInfo | string | 行为事件名(该值由Gm88运营提供) |

 Java调用示例： 

```java
 doEventInfo(eventInfo);
```

### 4.7 游戏绑定账号入口

游戏内需提供显示绑定账号页面的入口，点击入口时调用此接口，告知IOS/Android原生端

接口定义：doBind()

Java调用示例：

```java
doBind();
```

在用户完成绑定后，会给游戏对应的回调

```java
doBindDone(String status)
```

| 字段     | 类型     | 说明               |
| ------ | ------ | ---------------- |
| status | string | 1：绑定成功    0：绑定失败 |

返回示例 : 

```java
doBindDone("{"status":"1"}");
```

### 4.8 查询账号绑定

游戏内需查询当前账号绑定状态时时调用此接口，告知IOS/Android原生端

接口定义：doQuery()

Java调用示例：

```java
doQuery();
```

在用户完成绑定后，会给游戏对应的回调

```java
doQueryDone(String status)
```

| 字段     | 类型     | 说明                      |
| ------ | ------ | ----------------------- |
| status | string | 1：已绑定    0：未绑定  -1:查询失败 |

返回示例 : 

```java
doBindDone("{"status":"1"}");
```

### 4.9 获取token

当游戏需要获取角色验证token时,调用此方法

调用示例：

```java
doGetToken()
```

同时，会给游戏对应的回调

```java
 doGetTokenDone(String accessToken)
```

| 字段          | 类型     | 说明                         |
| ----------- | ------ | -------------------------- |
| accessToken | string | 当前登录用户token，可用于向后端做用户真实性验证 |

返回示例 : 

```java
doGetTokenDone("{"accessToken":"xxxxxx"}");
```

### 4.10 获取当前版本

当游戏需要对某些特定版本进行相关操作时，可以调用此方法来区分版本。

调用示例：

```java
doGetVersion()
```

同时，会给游戏对应的回调

```java
 doGetVersionDone(String versionCode)
```

| 字段          | 类型     | 说明                |
| ----------- | ------ | ----------------- |
| versionCode | string | 当前apk的versionCode |

返回示例 : 

```java
doGetVersionDone("{"versionCode":"1"}");
```

### 4.11  游戏内需要拉起切换账号

当游戏需要在游戏内拉起切换账号功能，可以调用此方法来显示登录页

调用示例：

```java
doReLogin()
```

### 4.12 获取当前手机系统语言

当游戏需要区分当前手机系统语言时，可以调用此方法来获取

调用示例：

```java
doLanguage()
```

同时，会给游戏对应的回调

```java
 doLanguageDone(String languageInfo)
```

| 字段       | 类型     | 说明                |
| -------- | ------ | ----------------- |
| language | string | 当前apk的versionCode |

返回示例 :  

```java
doLanguageDone("{"language":"zh-CN")
```

### 4.13 打开一个外部网页

当游戏需要通过外部浏览器打开一个网页时，可以使用此方法，包括但不限定打开Facebook粉丝页，Lobi，Twitter,巴哈姆特等。

调用示例：

```java
openURL(String url)
```

| 字段  | 类型     | 说明        |
| --- | ------ | --------- |
| url | string | 需要打开的网页地址 |

### 4.14 打开Facebook粉丝页客户端。

当游戏需要直接打开Facebook客户端时，请直接拉起

调用示例：

```java
openFbPage(String url)
```

| 字段  | 类型     | 说明                     |
| --- | ------ | ---------------------- |
| url | string | 需要打开的网页地址（若无客户端会拉起该网址） |

### 4.15 将文字存入剪贴板

当游戏需要将文字存入剪贴板时，可以调用此方法

调用示例：

```java
setPasteboard(String extra)
```

| 字段    | 类型     | 说明         |
| ----- | ------ | ---------- |
| extra | string | 需要存入剪贴板的文字 |

### 4.16 获取当前用户手机时间所在时区

当游戏需要获取当前用户手机时间所在时区时，调用此方法

调用示例：

```java
doTimeZone()
```

同时，会给游戏对应的回调

```java
 doTimeZoneDone(String timeZone)
```

| 字段       | 类型     | 说明                    |
| -------- | ------ | --------------------- |
| timeZone | string | 用户当前所在时区缩写   +8 表示东八区 |

返回示例: 

```java
 doAdShowDone("{"timeZone":"+8")
```

### 4.17 重新登录

当游戏需要重新登录时，调用此方法。多数用于当前token已失效。

调用示例：

```java
doLogout()
```

### 4.18 查询当前游戏需要展示给用户查看的货币。

当游戏需要查询当前游戏需要展示给用户查看的货币时。可以调用此方法

调用示例：

```java
doPurchaseList()
```

同时，会给游戏对应的回调

```java
 doPurchaseListDone(String purchaseListInfo)
```

| 字段           | 类型      | 说明                                                                         |
| ------------ | ------- | -------------------------------------------------------------------------- |
| status       | boolean | true : 查询成功    false:  查询失败                                                |
| purchaselist | string  | 商品信息实体beanlist                                                             |
| errorno      | string  | 仅在status 为false 的时候返回，    0：查询失败，游戏可以再次拉起查询，请不要一直尝试。  -1: 因为某些特殊原因，请显示默认货币 |

purchaselist 示例:

```java
String purchaselist = "{"1001":"$0.99","1002":"$4.99"}";
```

| 字段        | 类型     | 说明                      |
| --------- | ------ | ----------------------- |
| productId | string | 商品id                    |
| price     | string | 商品当前价格 带货币符号   ￥6/$0.99 |

返回示例:  

```java
String doPurchaseListDoneList = "{"status":true,"purchaselist":"{"1001":"$0.99","1002":"$4.99"}"}";

doPurchaseListDone(purchaselist)
```

### 4.19 翻译

当游戏需要对任何语言进行翻译时，调用以下方法，该方法会返回源语言对应当前手机语言的翻译。

调用示例：

```java
doTranslation(String sourceText,String extra)
```

| 字段         | 类型     | 说明                  |
| ---------- | ------ | ------------------- |
| sourceText | string | 源语言，待翻译的语句          |
| extra      | string | 当前语句的唯一标识，在返回的时候会透传 |

在翻译结束后，会给游戏相应的回调

返回示例:  

```java
String doTranslationDoneText = "{"status":true,"targetText":"hello","extra":"test1"};

doTranslationDone(doTranslationDoneText);
```

| 字段         | 类型      | 说明                                            |
| ---------- | ------- | --------------------------------------------- |
| status     | boolean | true : 翻译成功   false : 翻译失败（源语言识别失败，翻译失败等各种原因） |
| targetText | string  | 若翻译成功，则返回翻译文字                                 |
| extra      | string  | 翻译前的透传信息                                      |

### 4.20 IOS刘海屏适配接口（IOS适配，可选）

如果游戏在在IOS适配刘海屏困难，可以调用这个接口获得屏幕宽度和高度，便于CP适配。
为了适应白鹭的JS交互方式，所以实现上，我们使用doReady接口作为CP发起的接口，doResize作为由CP发起，获得高度的方法。

**接口定义：doReady()**

此接口请在游戏第一次加载完资源时调用，只有调用此接口后，doResize接口才可用。

**接口定义：doResize(): string**

当调用过doReady()接口后，才能调用doResize接口，它会返回正常webview与屏幕底部/顶部的距离，单位是pixel

java示例：

```java
doReady();

//Timeout只为了表示是异步调用
setTimeout(function() {
    let height = doResize().split('|');
    console.log('顶部高度：' + height[0]);
    console.log('底部高度：' + height[1]);
},200)

//输出：
//顶部高度：xxx
//底部高度：xxx
```

### 4.21 各个平台跳转

游戏跳转第三方平台粉丝页，评价

**接口定义：openPlatform(String info)**

点击粉丝平台

```
String info ="{"code":"1","info":"http://fenshi","pageid":"12345676"}"
```

| 字段   | 类型   | 说明                                                     |
| ------ | ------ | -------------------------------------------------------- |
| code   | string | code :1 韩国论坛 2 Facebook 3 洛比 4 应用商店 5吐槽6其他 |
| info   | string | 链接地址/包名/应用ID (无参数默认给个空字符)              |
| pageid | sring  | 粉丝页ID(无参数默认给个空字符)                           |

### ## 5. H5端对接

请先包含JS文件：https://g.hkpctimes.com/js/open.js?v=20160718001

## 5.1 H5端支付接口

如果游戏要支持H5端，则需要额外对接H5端的支付接口。

调用支付

```javascript
OPEN.goToPay(appId,productId,productName,price,extra,sign)
```

**参数**

| 字段          | 类型     | 说明                   |
| ----------- | ------ | -------------------- |
| appId       | int    | 游戏ID                 |
| productId   | int    | 商品ID                 |
| productName | string | 商品名称(不参与签名)          |
| price       | int    | 支付费用(单位:分)           |
| extra       | string | 自定义参数，判断唯一，用于存放游戏订单号 |
| sign        | string |                      |

**sign签名**

将key按照字母升序排列,然后使用&连接,再加上app私钥(只有App_Secret不由&连接),最后计算md5值。如

```
appId 1
productId 123
price 123
extra 123
sign = md5(appId=1&extra=123&price=123&productId=123APP_SECRET)
```

### 5.2 事件回传 （根据游戏具体场景接入）

此接口包含游戏内多个场景的数据打点，接入要求如下：

* 创建⻆角⾊色数据:如果游戏设计有⻆角⾊色存在，必须接⼊入 
* 新⼿手引导完成:如果游戏有新⼿手引导，则必须接⼊入 
* 玩家等级数据:如果游戏设计中有等级，则必须在⽤用户等级变化时上报 
* 展示选区界⾯面:尽量量接⼊入
* 点击选区按钮:尽量量接⼊入 
* 展示创⻆角界⾯面:尽量量接⼊入 
* 点击创⻆角按钮:尽量量接⼊入

**接口定义**

```javascript
  OPEN.spot(appId,spotType,extra,sign)
```

**参数：**
| 字段        | 类型   | 说明                                     |
| --------------- | ---------- | -------------------------------------------- |
| appId       | int    | 游戏ID                                   |
| spotType | int    | 事件类型：1.创建角色数据；2.新手引导完成数据；3.玩家等级数据；10.展示选区界面；11.选区界面点击开始按钮；12.展示创角界面；13.创角界面点击进入游戏按钮 |
| extra       | string | 事件参数：{'roleName':'角色名称', 'roleServer':'角色区服', 'roleLevel':'角色等级'}，无数据时非必填 |
| sign        | string |

**sign签名**

将key按照字母升序排列,然后使用&连接,再加上app私钥(只有App_Secret不由&连接),最后计算md5值。

```
appId 1
spotType 1
extra {'roleName':'⻆角⾊色名称', 'roleServer':'⻆角⾊色区服', 'roleLevel':'⻆角⾊色等级'} sign = md5(appId=1&extra={'roleName':'⻆角⾊色名称', 'roleServer':'⻆角⾊色区服', 'roleLevel':'⻆角⾊色等级'}&spotType=1APP_SECREET)
```

## 6. 支付流程参考

不论是IOS还是Android端，支付流程都是相同的，如果对支付流程不理解，可以通过下图了解。

支付流程图：

```
    graph TD

    subgraph CP前端
    start((开始流程)) --> doPay[调用doPay接口]
    end

    subgraph Gm88前端
    doPay --> pay{用户Google/Apple支付}
    pay --> |支付失败|failEnd((流程结束))
    end


    subgraph Gm88后端
    BSuccess[向Google/Apple验证支付]
    BResponseSuccess[发货成功] -->
    successEnd((流程成功))
    end
    BSuccess --> |发起支付回调|CBRecive

    subgraph CP后端
    CBRecive{发货}
    CBSendRetry[重新发货]
    CBSent[响应ok] --> BResponseSuccess
    CBRecive --> |成功|CBSent
    CBRecive --> |失败|CBSendRetry
    CBSendRetry -.-> |重试发货|CBRecive
    end

    pay --> |支付成功|BSuccess
```
