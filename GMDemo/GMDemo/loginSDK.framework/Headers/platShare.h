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
//// 图片
//-(void)FaceBookShareURL:(NSString*)url   PhotoUrl:(NSString*)photoUrl Hashtag:(NSString*)tag ;
//-(void)FaceBookShareURL:(NSString*)url   PhotoDate:(NSData*)photoData Hashtag:(NSString*)tag ;
//-(void)FaceBookShareURL:(NSString*)url   PhotoPath:(NSString*)photoPath Hashtag:(NSString*)tag ;
//// 视频
//
//-(void)FaceBookShareURL:(NSString*)url  VideoUrl:(NSString *)videoUrl   Hashtag:(NSString*)tag ;
//-(void)FaceBookShareURL:(NSString*)url  VideoData:(NSData *)videoData   Hashtag:(NSString*)tag ;
//-(void)FaceBookShareURL:(NSString*)url  VideoPath:(NSString *)videoPath  Hashtag:(NSString*)tag;
// 图片
-(void)FaceBookSharePhotoUrl:(NSString*)photoUrl Hashtag:(NSString*)tag ;
-(void)FaceBookSharePhotoDate:(NSData*)photoData Hashtag:(NSString*)tag ;
-(void)FaceBookSharePhotoPath:(NSString*)photoPath Hashtag:(NSString*)tag ;
// 视频
-(void)FaceBookShareVideoUrl:(NSString *)videoUrl   Hashtag:(NSString*)tag ;
-(void)FaceBookShareVideoData:(NSData *)videoData   Hashtag:(NSString*)tag ;
-(void)FaceBookShareVideoPath:(NSString *)videoPath  Hashtag:(NSString*)tag;

#pragma  ====================FB分享到快拍图片和视频分为两种方式传入1.data类型2.本地存储路径=====================
- (void)FaceBookShareStoriesVideo:(NSData*)videoData;
- (void)FaceBookShareStoriesVideoPath:(NSString*)videoPath;
- (void)FaceBookShareStoriesVideoUrl:(NSString*)videoUrl;

- (void)FaceBookShareStoriesPhoto:(NSData*)photoData;
- (void)FaceBookShareStoriesPhotoUrl:(NSString*)photoUrl;
- (void)FaceBookShareStoriesPhotoPath:(NSString*)photoPath;

#pragma  ====================新twitter分享到快拍图片和视频分为两种方式传入1.链接2.本地存储路径     media 为图片,gif=====================
- (void)TwitterUrlShareUrl:(NSString*)url Tag:(NSString*)tag ContentTxt:(NSString*)txt media:(NSString*)mediaUrl;
- (void)TwitterImageShareUrl:(NSString *)url Tag:(NSString*)tag  ContentTxt:(NSString *)txt Image:(UIImage *)img;
- (void)TwitterPathShareUrl:(NSString *)url Tag:(NSString*)tag  ContentTxt:(NSString *)txt media:(NSString *)mediaPath;

#pragma  ====================twitter分享到快拍图片和视频分为两种方式传入1.链接2.本地存储路径=====================
- (void)TwitterShareUrl:(NSString*)url ContentTxt:(NSString*)txt  ;

- (void)TwitterShareUrl:(NSString*)url ContentTxt:(NSString*)txt ImageUrl:(NSString*)imgUrl;
- (void)TwitterShareUrl:(NSString*)url ContentTxt:(NSString*)txt ImageData:(NSData*)imgData;
- (void)TwitterShareUrl:(NSString*)url ContentTxt:(NSString*)txt ImagePath:(NSString*)imgPath;


- (void)TwitterShareUrl:(NSString *)url ContentTxt:(NSString *)txt VideoUrl:(NSString *)videoUrl;
- (void)TwitterShareUrl:(NSString *)url ContentTxt:(NSString *)txt VideoData:(NSData *)videoData;
- (void)TwitterShareUrl:(NSString *)url ContentTxt:(NSString *)txt VideoPath:(NSString *)videoPath;


#pragma  ====================Instagram分享到快拍图片和视频分为两种方式传入1.data类型2.本地存储路径=====================
- (void)InstagramShareStoriesPhoto:(NSData*)photoData;
- (void)InstagramShareStoriesPhotoPath:(NSString*)photoPath;
- (void)InstagramShareStoriesPhotoUrl:(NSString*)photoUrl;

- (void)InstagramShareStoriesVideo:(NSData*)videoData;
- (void)InstagramShareStoriesVideoPath:(NSString*)videoPath;
- (void)InstagramShareStoriesVideoUrl:(NSString*)videoUrl;
#pragma  ====================Instagram分享到动态图片和视频分为两种方式传入1.链接2.本地存储路径 使用系统共享文件不建议使用=====================
- (void)InstagramSharePhotoPath:(NSString *)photoPath ;
- (void)InstagramSharePhotoData:(NSData *)photoData ;
- (void)InstagramSharePhotoUrl:(NSString *)photoUrl ;


- (void)InstagramShareVideoPath:(NSString *)videoPath ;
- (void)InstagramShareVideoData:(NSData *)videoData ;
- (void)InstagramShareVideoUrl:(NSString *)videoUrl ;

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
- (void)LineShareImgData:(NSData *)imgData;
- (void)LineShareImgUrl:(NSString *)imgUrl;
 
 
#pragma  ====================系统分享图片+链接+tag+引文建议line,Instagram使用=====================
-(void)ShareURL:(NSString*)url   PhotoPath:(NSString*)photoPath Hashtag:(NSString*)tag Quote:(NSString *)quote;
-(void)ShareURL:(NSString*)url   photoData:(NSData *)imageData Hashtag:(NSString*)tag Quote:(NSString *)quote;
-(void)ShareURL:(NSString*)url   photoUrl:(NSString *)imageUrl Hashtag:(NSString*)tag Quote:(NSString *)quote;

#pragma  ====================系统分享视频+链接+tag+引文建议line,Instagram使用=====================
-(void)ShareURL:(NSString*)url  VideoPath:(NSString *)videoPath  Hashtag:(NSString*)tag Quote:(NSString *)quote;
-(void)ShareURL:(NSString*)url  VideoData:(NSData *)videoData  Hashtag:(NSString*)tag Quote:(NSString *)quote;
-(void)ShareURL:(NSString*)url  VideoUrl:(NSString *)videoUrl  Hashtag:(NSString*)tag Quote:(NSString *)quote;

#pragma  ====================系统分享视频+图片+链接+tag+引文建议line,Instagram使用=====================
-(void)ShareURL:(NSString*)url photoPath:(NSString *)imagePath VideoPath:(NSString *)videoPath  Hashtag:(NSString*)tag Quote:(NSString *)quote;
-(void)ShareURL:(NSString*)url photoData:(NSData *)imageData VideoData:(NSData *)videoData  Hashtag:(NSString*)tag Quote:(NSString *)quote;
-(void)ShareURL:(NSString*)url photoUrl:(NSString *)imageUrl VideoUrl:(NSString *)videoUrl  Hashtag:(NSString*)tag Quote:(NSString *)quote;


-(void)TwitterShareURL:(NSString*)url photoData:(NSData *)imageData   Hashtag:(NSString*)tag Quote:(NSString *)quote;
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
