//
//  PZSpeedGroupAnalyticsEntry.h
//  PZSpeed
//
//  Created by ravi on 27/11/13.
//  Copyright (c) 2013 PacketZoom. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PZSpeedAnalyticsEntry.h"
#import <CoreLocation/CoreLocation.h>
#import <SystemConfiguration/SystemConfiguration.h>

@interface PZSpeedGroupAnalyticsEntry : PZSpeedAnalyticsEntry <NSCoding>

/*!
 * This data model is used to hold groups of PZSpeedAnalyticsEntries 
 * along with additional common data like location, network type etc.
 */
@property (nonatomic, strong) NSMutableArray *analyticEntries;
@property (readwrite) CLLocationCoordinate2D location;
@property (nonatomic, strong) NSDictionary *address;
@property (nonatomic, strong) NSString *networkType;
@property (nonatomic, strong) NSDictionary *carrierInfo;
@property (nonatomic, strong) NSString *deviceModel;
@property (nonatomic, strong) NSMutableDictionary *additionalInfo;
@end
