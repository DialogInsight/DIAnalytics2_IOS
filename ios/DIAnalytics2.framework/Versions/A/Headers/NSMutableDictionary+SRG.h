//
//  NSMutableDictionary+SRG.h
//  AFNetworking
//
//  Created by Simon Richard Giroux on 2021-09-12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableDictionary (SRG)

- (void)srg_setValueIfNotNil:(id)value forKey:(NSString*)key;

@end

NS_ASSUME_NONNULL_END
