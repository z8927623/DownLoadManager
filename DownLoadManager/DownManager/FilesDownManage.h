//
//  FilesDownManage.h
//  Created by yu on 13-1-21.


#import <Foundation/Foundation.h>
#import "ASIHTTPRequest.h"
#import "ASINetworkQueue.h"
#import "CommonHelper.h"
#import "DownloadDelegate.h"
#import "FileModel.h"

#import <AVFoundation/AVAudioPlayer.h>
extern NSInteger  maxcount;

@interface FilesDownManage : NSObject<ASIHTTPRequestDelegate,ASIProgressDelegate>
{
    NSInteger type;
    int count;
    
}
@property int count;
@property(nonatomic,retain)id<DownloadDelegate> VCdelegate;//获得下载事件的vc，用在比如多选图片后批量下载的情况，这时需配合 allowNextRequest 协议方法使用
@property(nonatomic,retain)id<DownloadDelegate> downloadDelegate;//下载列表delegate

@property(nonatomic,retain)NSString *basepath;
@property(nonatomic,retain)NSString *TargetSubPath;
@property(nonatomic,retain)NSMutableArray *finishedlist;//已下载完成的文件列表（文件对象）

@property(nonatomic,retain)NSMutableArray *downinglist;//正在下载的文件列表(ASIHttpRequest对象)
@property(nonatomic,retain)NSMutableArray *filelist;
@property(nonatomic,retain)NSMutableArray *targetPathArray;

@property(nonatomic,retain)AVAudioPlayer *buttonSound;//按钮声音

@property(nonatomic,retain)AVAudioPlayer *downloadCompleteSound;//下载完成的声音
@property(nonatomic,retain)FileModel *fileInfo;
@property(nonatomic)BOOL isFistLoadSound;//是否第一次加载声音，静音

-(void)clearAllRquests;
-(void)clearAllFinished;
-(void)resumeRequest:(ASIHTTPRequest *)request;
-(void)deleteRequest:(ASIHTTPRequest *)request;
-(void)stopRequest:(ASIHTTPRequest *)request;
-(void)saveFinishedFile;
-(void)deleteFinishFile:(FileModel *)selectFile;
-(void)downFileUrl:(NSString*)url
          filename:(NSString*)name
        filetarget:(NSString *)path
         fileimage:(UIImage *)image
         ;

+(FilesDownManage *) sharedFilesDownManage;
//＊＊＊第一次＊＊＊初始化是使用，设置缓存文件夹和已下载文件夹，构建下载列表和已下载文件列表时使用
+(FilesDownManage *) sharedFilesDownManageWithBasepath:(NSString *)basepath
                                         TargetPathArr:(NSArray *)targetpaths;
-(void)beginRequest:(FileModel *)fileInfo isBeginDown:(BOOL)isBeginDown ;
-(void)startLoad;
-(void)restartAllRquests;

@end


