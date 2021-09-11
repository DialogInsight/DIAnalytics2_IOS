//
//  DINetworkCenter.h
//  DIAnalytics2
//
//  Created by Samuel Cote on 2016-10-31.
//

#import <AFNetworking/AFNetworking.h>
#import <Foundation/Foundation.h>

typedef void (^block_success)(id _Nullable object);
typedef void (^block_failure)(NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface DINetworkCenter : NSObject

+ (DINetworkCenter*)shared;
//+ (NSString*)getUserAgent;

- (AFHTTPSessionManager*)getManager;

- (void)post:(NSString*)path
  parameters:(NSDictionary*)parameters
     success:(block_success)success
     failure:(block_failure)failure;

@end

NS_ASSUME_NONNULL_END
