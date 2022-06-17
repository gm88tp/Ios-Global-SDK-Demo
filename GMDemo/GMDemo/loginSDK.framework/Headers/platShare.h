//
//  PlatShare.h
//  loginSDK
//
//  Created by xy on 2022/4/12.
//  Copyright © 2022 gumo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface platShare : NSObject
+(platShare*)getInstance;
#pragma  ====================FB分享到动态图片和视频分为两种方式传入1.链接2.本地存储路径=====================
// 链接
-(void)FaceBookShareURL:(NSString*)url  Hashtag:(NSString*)tag  Quote:(NSString*)quote;
// 图片
-(void)FaceBookShareURL:(NSString*)url   PhotoUrl:(NSString*)photoUrl Hashtag:(NSString*)tag ;

-(void)FaceBookShareURL:(NSString*)url   PhotoPath:(NSString*)photoPath Hashtag:(NSString*)tag ;
// 视频
-(void)FaceBookShareURL:(NSString*)url  VideoUrl:(NSString *)videoUrl   Hashtag:(NSString*)tag ;

-(void)FaceBookShareURL:(NSString*)url  VideoPath:(NSString *)videoPath  Hashtag:(NSString*)tag;

#pragma  ====================FB分享到快拍图片和视频分为两种方式传入1.data类型2.本地存储路径=====================
- (void)FaceBookShareStoriesVideo:(NSData*)videoData;
- (void)FaceBookShareStoriesVideoPath:(NSString*)videoPath;

- (void)FaceBookShareStoriesPhoto:(NSData*)photoData;

- (void)FaceBookShareStoriesPhotoPath:(NSString*)photoPath;

#pragma  ====================twitter分享到快拍图片和视频分为两种方式传入1.链接2.本地存储路径=====================
- (void)TwitterShareUrl:(NSString*)url ContentTxt:(NSString*)txt  ;

- (void)TwitterShareUrl:(NSString*)url ContentTxt:(NSString*)txt ImageUrl:(NSString*)imgUrl;

- (void)TwitterShareUrl:(NSString*)url ContentTxt:(NSString*)txt ImagePath:(NSString*)imgPath;


- (void)TwitterShareUrl:(NSString *)url ContentTxt:(NSString *)txt VideoUrl:(NSString *)videoUrl;
- (void)TwitterShareUrl:(NSString *)url ContentTxt:(NSString *)txt VideoPath:(NSString *)videoPath;


#pragma  ====================Instagram分享到快拍图片和视频分为两种方式传入1.data类型2.本地存储路径=====================
- (void)InstagramShareStoriesPhoto:(NSData*)photoData;
- (void)InstagramShareStoriesVideo:(NSData*)videoData;

- (void)InstagramShareStoriesPhotoPath:(NSString*)photoPath;
- (void)InstagramShareStoriesVideoPath:(NSString*)videoPath;

#pragma  ====================Instagram分享到动态图片和视频分为两种方式传入1.链接2.本地存储路径 使用系统共享文件不建议使用=====================
- (void)InstagramSharePhotoPath:(NSString *)photoPath ;
- (void)InstagramShareVideoPath:(NSString *)videoPath ;
/**
 Line
 @param txt  分享文本
 @param url  传入分享链接/图片链接/视屏链接==（只能选择一种）
  
 */
- (void)LineShareTxt:(NSString *)txt ShareUrl:(NSString *)url;
/**
 Line
 @param imgPath 分享图片路径
 */
- (void)LineShareImgPath:(NSString *)imgPath;
 
 
#pragma  ====================系统分享图片+链接+tag+引文建议line,Instagram使用=====================
-(void)ShareURL:(NSString*)url   PhotoPath:(NSString*)photoPath Hashtag:(NSString*)tag Quote:(NSString *)quote;
 
#pragma  ====================系统分享视频+链接+tag+引文建议line,Instagram使用=====================
-(void)ShareURL:(NSString*)url  VideoPath:(NSString *)videoPath  Hashtag:(NSString*)tag Quote:(NSString *)quote;
#pragma  ====================系统分享视频+图片+链接+tag+引文建议line,Instagram使用=====================
-(void)ShareURL:(NSString*)url photoPath:(NSString *)imagePath VideoPath:(NSString *)videoPath  Hashtag:(NSString*)tag Quote:(NSString *)quote;
#pragma  =====获取当前安装的平台line,instagram,twitter,facebook ========
-(NSArray *)shareplatType;

/*
 返回 NSString 为0 ：表示失败
 **/
-(void)shareLinkInfoDic:(NSDictionary * )info successBlock:(void(^)(NSString*))success;
/*
 返回 NSDictionary  status为0 ：表示失败
 **/
-(void)shareLinkSourcesuccessBlock:(void(^)(NSDictionary *))success;
@end

NS_ASSUME_NONNULL_END
