//
//  BTKAction.h
//  BaiduTraceSDK
//
//  Created by Daniel Bey on 2017年02月27日.
//  Copyright © 2017 Daniel Bey. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BTKTraceDelegate.h"
#import "BTKStartServiceOption.h"
#import "BTKServiceOption.h"
#import <CoreLocation/CoreLocation.h>

/// 轨迹服务与采集的操作类
/** 
 轨迹服务与采集的操作类
 服务的启停和采集的启停都通过此类提供的方法来控制
 */
@interface BTKAction : NSObject

+(BTKAction *)sharedInstance;

/**
 设置SDK运行所需的基础信息，调用任何方法之前都需要先调用此方法

 @param option 服务信息
 @return TRUE代表设置成功，FALSE代表设置失败
 */
-(BOOL)initInfo:(BTKServiceOption *)option;

/**
 开启轨迹服务

 @param option 开启服务需要的配置信息
 @param delegate 操作结果的回调对象
 */
-(void)startService:(BTKStartServiceOption *)option delegate:(id <BTKTraceDelegate>)delegate;

/**
 停止轨迹服务

 @param delegate 操作结果的回调对象
 */
-(void)stopService:(id <BTKTraceDelegate>)delegate;

/**
 开始采集

 @param delegate 操作结果的回调对象
 */
-(void)startGather:(id <BTKTraceDelegate>)delegate;

/**
 停止采集

 @param delegate 操作结果的回调对象
 */
-(void)stopGather:(id <BTKTraceDelegate>)delegate;

/**
 设置定位的选项

 @param activityType 活动类型
 @param desiredAccuracy 期望的定位精度
 @param distanceFilter 触发定位的距离阀值
 */
-(void)setLocationAttributeWithActivityType:(CLActivityType)activityType desiredAccuracy:(CLLocationAccuracy)desiredAccuracy distanceFilter:(CLLocationDistance)distanceFilter;

/**
 设置采集周期和打包上传的周期

 @param gatherInterval 采集周期，单位：秒
 @param packInterval 打包上传周期，单位：秒
 @param delegate 操作结果的回调对象
 */
-(void)changeGatherAndPackIntervals:(NSUInteger)gatherInterval packInterval:(NSUInteger)packInterval delegate:(id <BTKTraceDelegate>)delegate;
@end
