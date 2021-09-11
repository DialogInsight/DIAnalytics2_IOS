//
//  DISharedPref.h
//  DIAnalytics2
//
//  Created by Simon Richard Giroux on 2021-06-19.
//  Copyright © 2021 DigitalInsight. All rights reserved.
//

#define NOTIFICATION_TOKEN_SHARED_PREF @"vCKwYHeI4MFTaRk"
#define OLD_NOTIFICATION_TOKEN_SHARED_PREF @"3dEuiW86ITliPVH"
#define GUID @"contactGUID"
#define LAST_SYNCHRONIZE_DATE @"lastSynchronizeDate"
#define DI_CONTACT @"diContact"
#define DI_CONTACT_LAST_UPDATE_DATE @"contactLastUpdateDate"
#define PUSH_RECEPTIONS_DATA @"pushReceptionsData"
#define PUSH_RECEPTIONS_LAST_SEND_DATE @"pushReceptionsLastSendDate"
#define PUSH_LAUNCH_DATA @"pushLaunchData"
#define LOGS @"diLogs"
#define SYNCED @"diSynced"
#define APPLICATION_LAUNCHES_LAST_SEND_DATE @"applicationLaunchesLastSendDate"
#define GET_GUID_LAST_SEND_DATE @"getGuidLastSendDate"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DISharedPref : NSObject

+ (NSString*)getNoficationTokenSharedPref;
+ (void)setNoficationTokenSharedPref:(NSString*)inNotificationToken;
+ (NSString*)getOldNoficationTokenSharedPref;
+ (void)setOldNoficationTokenSharedPref:(NSString*)inNotificationToken;
+ (NSString*)getGuid;
+ (void)setGuid:(NSString*)guid;
+ (NSDate*)getLastSynchronizeDate;
+ (void)setLastSynchronizeDate:(NSDate*)date;
+ (NSDate*)getPushReceptionsLastSendDate;
+ (void)setPushReceptionsLastSendDate:(NSDate*)date;
+ (NSDictionary*)getDiContact;
+ (void)setDiContact:(NSDictionary*)contactData;
+ (BOOL)isSynced;
+ (void)setSynced:(BOOL)synced;
+ (NSDate*)getApplicationLaunchesLastSendDate;
+ (void)setApplicationLaunchesLastSendDate:(NSDate*)date;
+ (NSDate*)getGetGuidLastSendDate;
+ (void)setGetGuidLastSendDate:(NSDate*)date;
+ (NSDictionary*)getPushReceptionsData;
+ (void)setPushReceptionsData:(NSDictionary*)pushReceptionsData;
+ (NSArray*)getLaunchData;
+ (void)setLaunchData:(NSArray*)launchData;
+ (void)setLogs:(NSArray*)logs;
+ (NSArray*)getLogs;

@end

NS_ASSUME_NONNULL_END
