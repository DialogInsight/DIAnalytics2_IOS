//
//  DIResponse.h
//  DIAnalytics2
//
//  Created by Simon Richard Giroux on 2021-06-19.
//  Copyright © 2021 DialogInsight. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIResponse : NSObject

@property (nonatomic) int idRequest;
@property (nonatomic) BOOL success;
@property (nonatomic, strong) NSString *errorMessage;
@property (nonatomic, strong) NSString *trace;
@property (nonatomic, strong) NSString *errorCode;

- (id)initWithDictionary:(NSDictionary*)dict;

@end

NS_ASSUME_NONNULL_END
