//
//  PushReceptionPushModel.h
//  DIAnalytics2
//
//  Created by Simon Richard Giroux on 2021-06-19.
//  Copyright © 2021 DialogInsight. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PushReceptionPushModel : NSObject

@property (nonatomic, strong) NSString *applicationId;
@property (nonatomic, strong) NSMutableArray *data;
@property (nonatomic, strong) NSString *guid;

- (id)initWithApplicationId:(NSString*)applicationId;
- (id)initWithApplicationId:(NSString*)applicationId
                       data:(NSMutableArray*)data
                       guid:(NSDate*)guid;
- (id)initWithDictionary:(NSDictionary*)dict;
- (NSDictionary*)toDictionary;

@end

NS_ASSUME_NONNULL_END
