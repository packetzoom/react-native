//
//  PZURLConnection.h
//  PZSpeed
//
//  Created by Rocir Marcos Leite Santiago on 11/8/13.
//  Copyright (c) 2013 PacketZoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PZURLConnectionDelegate;

@interface PZURLConnection : NSObject

+ (PZURLConnection *) connectionWithRequest:(NSURLRequest *)request
                                   delegate:(id<PZURLConnectionDelegate>)delegate;

- (PZURLConnection *) initWithRequest:(NSURLRequest *)request delegate:(id)delegate;

- (PZURLConnection *) initWithRequest:(NSURLRequest *)request
                             delegate:(id)delegate
                     startImmediately:(BOOL)startImmediately;

- (void) scheduleInRunLoop:(NSRunLoop *)runLoop forMode:(NSString *)mode;
- (void) start;
- (void) cancel;
@end

@protocol PZURLConnectionDelegate <NSObject>

@optional

- (void) pzConnectionDidStartLoading:(PZURLConnection *)connection;

- (void) pzConnection:(PZURLConnection *)connection
   didReceiveResponse:(NSURLResponse *)urlResponse;

- (void) pzConnection:(PZURLConnection *)connection didReceiveData:(NSData *)data;

- (void) pzConnection:(PZURLConnection *)connection didFailWithError:(NSError *)error;

- (void) pzConnectionDidFinishLoading:(PZURLConnection *)connection;

- (void) pzConnection:(PZURLConnection *)connection
wasRedirectedToRequest:(NSURLRequest *)request
     redirectResponse:(NSURLResponse *)response;

- (void) pzConnection:(PZURLConnection *)connection wasBypassedToNonPZWithRequest:(NSURLRequest *)request;
@end
