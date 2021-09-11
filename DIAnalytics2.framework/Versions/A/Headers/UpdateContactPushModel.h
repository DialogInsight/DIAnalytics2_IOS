//
//  UpdateContactPushModel.h
//  DIAnalytics2
//
//  Created by Simon Richard Giroux on 2021-06-19.
//  Copyright © 2021 DialogInsight. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UpdateContactPushModel : NSObject

@property (nonatomic, strong) NSString *applicationId;
@property (nonatomic, strong) NSDictionary *contact;
@property (nonatomic, strong) NSString *token;
@property (nonatomic, strong) NSString *oldToken;
@property (nonatomic, strong) NSString *language;
@property (nonatomic, strong) NSString *guid;

- (id)initWithApplicationId:(NSString*)applicationId
                    contact:(NSDictionary*)contact
                      token:(NSString*)token
                   oldToken:(NSString*)oldToken
                   language:(NSString*)language
                       guid:(NSString*)guid;
- (id)initWithDictionary:(NSDictionary*)dict;
- (NSDictionary*)toDictionary;


@end

NS_ASSUME_NONNULL_END
