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
    
    return self;
}

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

- (NSDictionary *)constantsToExport{
    NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:
                          [NSNumber numberWithInteger:[PZSpeedController version]], @"version", nil];
    return dict;
}

RCT_EXPORT_METHOD(init:(NSString *)appId apiKey:(NSString *)apiKey)
{
    NSLog(@"RNPacketzoom init version = %ld",  [PZSpeedController version]);
   
    [PZSpeedController controllerWithAppID: appId apiKey: apiKey];
}

@end
