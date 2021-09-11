//
//  DIResponseWithGuid.h
//  DIAnalytics2
//
//  Created by Simon Richard Giroux on 2021-06-19.
//  Copyright © 2021 DialogInsight. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DIResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface DIResponseWithGuid : DIResponse

@property (nonatomic, strong) NSString *guid;

- (id)initWithDictionary:(NSDictionary*)dict;

@end

NS_ASSUME_NONNULL_END
