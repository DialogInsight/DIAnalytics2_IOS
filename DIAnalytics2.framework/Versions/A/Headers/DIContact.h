//
//  DIContact.h
//  DIAnalytics2
//
//  Created by Simon Richard Giroux on 2021-06-19.
//  Copyright © 2021 DigitalInsight. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DIContact : NSObject

@property (nonatomic, strong) NSString *token;
@property (nonatomic, strong) NSString *guid;
@property (nonatomic, strong) NSMutableDictionary *diContactData;

- (void)resetContact;
- (BOOL)same:(DIContact*)other;

@end

NS_ASSUME_NONNULL_END
