//
//  PZSpeedAnalyticsEntry.h
//  PZSpeed
//
//  Created by Rocir Marcos Leite Santiago on 11/5/13.
//  Copyright (c) 2013 PacketZoom. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 * PZSpeedAnalyticsEntry is the data model created to make note of PZ metrics for each request
 */
@interface PZSpeedAnalyticsEntry : NSObject <NSCoding>

/*!
 * The request used.
 */
@property (nonatomic, strong) NSURLRequest *request;

/*!
 * Whether the request was fired using PZSpeed or not.
 */
@property (nonatomic, getter = isUsingPZSpeed) BOOL usingPZSpeed;

/*!
 * The timestamp when the request was fired.
 */
@property (nonatomic) uint64_t startTimestamp;

/*!
 * The timestamp when the request actually started.
 */
@property (nonatomic) uint64_t trueStartTimestamp;

/*!
 * The timestamp when the first byte was received.
 */
@property (nonatomic) uint64_t firstByteTimestamp;

/*!
 * The timestamp when the last byte was received.
 */
@property (nonatomic) uint64_t endTimestamp;

/*!
 * The total size of the associated resource.
 */
@property (nonatomic) NSInteger size;

@property (nonatomic) NSInteger contiguousSize;

/*!
 * Status of the request. Success/failure etc.
 */
@property (nonatomic) int status;

/*!
 * The proxyIP used to fetch this request.
 */
@property (nonatomic) uint32_t proxyIP;

/*!
 * State of allow PZ flags collected combinedly.
 */
@property (nonatomic) unsigned char pzFlags;

/*!
 * Specifies if PZ loaded a request from local cache.
 */
@property (nonatomic) BOOL isFromLocalCache;

/*!
 * Index of this metric in it's session.
 */
@property (nonatomic, strong) NSNumber *metricIndex;

/*!
 * Index of this metric this metric is linked to.
 */
@property (nonatomic, strong) NSNumber *linkedMetricIndex;

/*!
 * HTTP status code from the response.
 */
@property (nonatomic) NSInteger httpStatuscode;

/*!
 * For PZ requests, this determines if the request is Dynamic.
 */
@property (nonatomic) BOOL isDynamicRequest;

/*!
 * HTTP request method
 */
@property (nonatomic) NSInteger httpRequestMethod;

/*!
 * The total size of the associated request.
 */
@property (nonatomic) NSInteger requestSize;

/*!
 * The uuid_low64 associated with the transfer
 */
@property (nonatomic) uint64_t uuidLow;


@end
