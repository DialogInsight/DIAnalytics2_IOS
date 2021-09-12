//
//  DIAnalytics.h
//  DIAnalytics2_Example
//
//  Created by Simon Richard Giroux on 2021-06-19.
//  Copyright © 2021 Simon. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef _DIAnalytics_
#define _DIAnalytics_
#import <FirebaseCore/FirebaseCore.h>
#import <FirebaseMessaging/FirebaseMessaging.h>
#endif


@class DIContact;
@class PushReceptionPushModel;

NS_ASSUME_NONNULL_BEGIN

typedef void (^block_success)(id _Nullable object);

@interface DIAnalytics : NSObject <FIRMessagingDelegate>

@property (nonatomic, strong) DIContact *contact;
@property (nonatomic, strong) PushReceptionPushModel *pushReceptionsData;

@property (nonatomic, strong) UIApplication *application;
@property (nonatomic, strong) NSString *applicationId;

@property (nonatomic, strong) NSString *baseUrl;
@property (nonatomic, strong) NSString *apiUrl;

+ (DIAnalytics*)shared;

- (NSString*)libraryVersion;
- (NSString*)getBaseUrl;
- (void)enableLogs;
- (void)startWithApplication:(UIApplication*)application applicationId:(NSString*)applicationId;
- (void)addPushId:(NSString*)pushId;
- (void)registerForRemoteNotification;
- (void)updateContact:(DIContact*)contactData;
- (void)reset;
//- (void)requestToken:(block_success)success;
- (void)updateContactSync;
- (void)getGuid:(block_success)success;
- (void)didReceiveRemoteNotification:(NSDictionary*)userInfo;

@end

NS_ASSUME_NONNULL_END
