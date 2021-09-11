//
//  DIApiInterface.h
//  DIAnalytics2
//
//  Created by Simon Richard Giroux on 2021-06-19.
//  Copyright © 2021 DialogInsight. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ApplicationLaunchesPushModel.h"
#import "DINetworkCenter.h"
#import "GetGuidPushModel.h"
#import "PushReceptionPushModel.h"
#import "UpdateContactPushModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^block_success)(id _Nullable object);
typedef void (^block_failure)(NSError * _Nullable error);

@interface DIApiInterface : NSObject

+ (void)trackPushReceptions:(PushReceptionPushModel*)pushReceptionModel
                    success:(block_success)success
                    failure:(block_failure)failure;
+ (void)trackApplicationLaunches:(ApplicationLaunchesPushModel*)applicationLaunchesModel
                         success:(block_success)success
                         failure:(block_failure)failure;
+ (void)getGuid:(GetGuidPushModel*)getGuidPushModel
        success:(block_success)success
        failure:(block_failure)failure;
+ (void)updateContact:(UpdateContactPushModel*)updateContactPushModel
              success:(block_success)success
              failure:(block_failure)failure;

@end

NS_ASSUME_NONNULL_END
