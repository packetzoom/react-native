//
//  NSURLRequest+PZAdditions.h
//  PZSpeed
//
//  Created by ravi on 4/10/15.
//  Copyright (c) 2015 PacketZoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURLRequest (PZAdditions)
- (NSMutableDictionary *)getPZHeaders;
@end

@interface NSMutableURLRequest (SpecialProtocol)
- (void)enablePZHeaderReporting:(BOOL)shouldEnable;
@end