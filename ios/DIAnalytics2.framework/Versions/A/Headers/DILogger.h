//
//  DILogger.h
//  DIAnalytics2
//
//  Created by Simon Richard Giroux on 2021-09-05.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DILogger : NSObject

@property (nonatomic) BOOL enabled;

+ (DILogger*)shared;

- (void)displayLog:(NSString*)message;
- (void)displayErrorLog:(NSString*)message;

@end

NS_ASSUME_NONNULL_END
