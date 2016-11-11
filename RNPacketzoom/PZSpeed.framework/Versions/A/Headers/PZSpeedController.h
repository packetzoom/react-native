
//
//  PZSpeedController.h
//  PZSpeed
//
//  Created by Rocir Marcos Leite Santiago on 10/31/13.
//  Copyright (c) 2013 PacketZoom. All rights reserved.
//

#import <Foundation/Foundation.h>

enum PZLogLevel
{
    PZLOG_NOLOGS = 0,       //no logs are printed from PZ
    PZLOG_ERROR = 1,        //logs out just the errors if any
    PZLOG_WARNING = 2,      //logs out errors and warnings
    PZLOG_INFO = 3,         //logs out errors, warnings and additional information like request start/end
    PZLOG_VINFO = 4,        //logs out user related info in addition to info logs
    PZLOG_DEBUG = 5,        //prints out all the logs. Use this just for debugging
};
typedef enum PZLogLevel PZLogLevel;

extern NSString const * PZSpeedControllerProxyIPAddress;

@interface PZSpeedController : NSObject

/*!
 * Creates and initializes the singleton instance of PZSpeedController for a given app ID and API key.
 * Initializes PacketZoom after allocation.
 *
 * @param appID The app ID provided by PacketZoom.
 * @param apiKey The API key provided by PacketZoom.
 *
 * @return The singleton instance.
 */
+ (PZSpeedController *) controllerWithAppID:(NSString *)appID apiKey:(NSString *)apiKey;

/*!
 * Creates and initializes the singleton instance of PZSpeedController for a given app ID and API key.
 *
 * @param appID The app ID provided by PacketZoom.
 * @param apiKey The API key provided by PacketZoom.
 * @param shouldActivatePZ Whether to activate PacketZoom at allocation
 *
 * @return The singleton instance.
 */
+ (PZSpeedController *) controllerWithAppID:(NSString *)appID apiKey:(NSString *)apiKey activatePZ:(BOOL)shouldActivatePZ;

/*!
 * The PZController singleton instance.
 *
 * @return The singleton instance.
 * Ideally, this has to be called after initializing the PZController with controllerWithAppID: apiKey:
 * But, temporarily for alpha usage, a singleton is created (if not already created) with default values for appID, apiKey and is returned back.
 */
+ (PZSpeedController *) sharedController;

/*!
 * Starts or stops using PZSpeed for making url requests. 
 * @param a BOOL value specifying if PZSpeed should be used or not. By Default, PZSpeed is used.
 */
- (void) usePZ:(BOOL)shouldUsePZ;

/*!
 * Starts using PZSpeed and registers PZ in the protocol stack.
 */
- (void) activatePZ;

/*!
 * Stops using PZSpeed and unregisters PZ from the protocol stack.
 */
- (void) deactivatePZ;

/*!
 * Sets a custom ID that PZSpeed will report with the init call and this could also be used to acheive additional user level details and control.
 * @param userId to set
 *
 */
- (void) setCustomID:(NSString *)userId;

/*!
 * returns the pzUUID.
 *
 */
- (NSNumber *)getPZUUID;


/*!
 * Sets the logging level to be used by the SDK.
 * @param logLevel to set
 */
+(void)setPZLogLevel:(PZLogLevel)logLevel;

/*!
 * Temporary method to set pz proxy ip and port. This will be removed in release versions.
 *
 */
+(void)setProxyIP:(NSString *)proxyIP andPort:(int)proxyPort;


@end
