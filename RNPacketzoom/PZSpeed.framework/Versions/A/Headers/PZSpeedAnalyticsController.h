//
//  PZSpeedAnalyticsController.h
//  PZSpeed
//
//  Created by Rocir Marcos Leite Santiago on 11/5/13.
//  Copyright (c) 2013 PacketZoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PZSpeedAnalyticsEntry;
@class PZSpeedGroupAnalyticsEntry;

@protocol PZSpeedAnalyticsControllerDelegate;


@interface PZSpeedAnalyticsController : NSObject


/*!
 * The PZSpeedAnalytics' singleton instance.
 */
+ (PZSpeedAnalyticsController *) sharedAnalyticsController;

/*!
 * Setting to measure app launch time
 */
+ (void) measureAppLaunchDelay:(BOOL)shouldMeasure;

/*!
 * A BOOL value that determines if App launch delay is measured by PZSpeed. 
 * By Default, this is set to NO.
 */
+ (BOOL) isMeasuringAppLaunchDelay;

/*!
 * This method marks an end of app launch. Failing to call this method when PZSpeed is set to measure 
 * app launch delay will result in app launch to be marked as never ending.
 *
 * @return YES if success, NO if app launch delay is not being measured.
 */
- (BOOL)appLaunchCompleted;

/*!
 * A BOOL value specifying if the analytics should be reported to analytics server. 
 */
@property (nonatomic, readwrite) BOOL shouldReportAnalytics;

/*!
 * A delegate object to which metrics are reported to via PZSpeedAnalyticsControllerDelegate protocol.
 */
@property (nonatomic, weak) id <PZSpeedAnalyticsControllerDelegate> delegate;

@end


@protocol PZSpeedAnalyticsControllerDelegate <NSObject>

@optional
- (void) pzSpeedRequestFinishedWithAnalyticEntry:(PZSpeedAnalyticsEntry *)entry;

@end
