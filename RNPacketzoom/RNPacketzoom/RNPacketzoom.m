//
//  RNPacketzoom.m
//  RNPacketzoom
//
//  Created by Leanid Vouk on 11/10/16.
//  Copyright © 2016 Packetzoom. All rights reserved.
//

#import "RNPacketzoom.h"

#import <PZSpeed/PZSpeed.h>

@import CoreLocation;
@import SystemConfiguration;
@import CoreTelephony;
@import Foundation;

@implementation RNPacketzoom

RCT_EXPORT_MODULE()

- (id) init {
    self = [super init];
    NSLog(@"RNSignalStrength init");
    [PZSpeedController controllerWithAppID: @"dca51e6ecd4fd71df12a26c8f5014ce6" apiKey: @"69fe84992a5242317d7235ce16c1b845090ec2d8"];
    
    return self;
}

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

- (NSDictionary *)constantsToExport
{
    return @{
             @"signal": @"1",
             @"hello": @"world",
             };
}

RCT_EXPORT_METHOD(init:(NSString *)appId apiKey:(NSString *)apiKey)
{
    NSLog(@"RNPacketzoom init");
    [PZSpeedController controllerWithAppID: @"dca51e6ecd4fd71df12a26c8f5014ce6" apiKey: @"69fe84992a5242317d7235ce16c1b845090ec2d8"];

}

@end
