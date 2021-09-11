//
//  DITimeUtils.h
//  DIAnalytics2
//
//  Created by Simon Richard Giroux on 2021-06-19.
//  Copyright © 2021 DigitalInsight. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DITimeUtils : NSObject

+ (NSString*)getTimeStamp:(NSDate*)date;
+ (float)secondsSince:(NSDate*)date;

@end

NS_ASSUME_NONNULL_END
