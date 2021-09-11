//
//  GetGuidPushModel.h
//  DIAnalytics2
//
//  Created by Simon Richard Giroux on 2021-06-19.
//  Copyright © 2021 DialogInsight. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GetGuidPushModel : NSObject

@property (nonatomic, strong) NSString *applicationId;
@property (nonatomic, strong) NSString *token;

- (id)initWithApplicationId:(NSString*)applicationId token:(NSString*)token;
- (id)initWithDictionary:(NSDictionary*)dict;
- (NSDictionary*)toDictionary;

@end

NS_ASSUME_NONNULL_END
