//
//  BTKTrackDelegate.h
//  BaiduTraceSDK
//
//  Created by Daniel Bey on 2017年04月11日.
//  Copyright © 2017 Daniel Bey. All rights reserved.
//

#import <Foundation/Foundation.h>

/// track代理协议，track相关操作的执行结果，通过本协议中的方法回调
/**
 track代理协议，track相关操作的执行结果，通过本协议中的方法回调
 */
@protocol BTKTrackDelegate <NSObject>

@optional
/**
 实时位置查询的回调方法

 @param response 查询结果
 */
-(void)onQueryTrackLatestPoint:(NSData *)response;

/**
 里程查询的回调方法

 @param response 查询结果
 */
-(void)onQueryTrackDistance:(NSData *)response;

/**
 轨迹查询的回调方法

 @param response 查询结果
 */
-(void)onQueryHistoryTrack:(NSData *)response;

@end
