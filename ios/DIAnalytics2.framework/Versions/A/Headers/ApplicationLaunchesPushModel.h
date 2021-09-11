//
//  ApplicationLaunchesPushModel.h
//  DIAnalytics2
//
//  Created by Simon Richard Giroux on 2021-06-19.
//  Copyright © 2021 DialogInsight. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ApplicationLaunchesPushModel : NSObject

@property (nonatomic, strong) NSString *applicationId;
@property (nonatomic, strong) NSString *guid;
@property (nonatomic, strong) NSString *token;
@property (nonatomic, strong) NSMutableArray *timeStamps;

- (id)initWithApplicationId:(NSString*)applicationId
                       guid:(NSString*)guid
                      token:(NSString*)token
                      dates:(NSArray*)dates;
- (id)initWithDictionary:(NSDictionary*)dict;
- (NSDictionary*)toDictionary;

@end

NS_ASSUME_NONNULL_END
