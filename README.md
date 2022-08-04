# DIAnalytics2

[![CI Status](https://img.shields.io/travis/Simon/DIAnalytics2.svg?style=flat)](https://travis-ci.org/Simon/DIAnalytics2)
[![Version](https://img.shields.io/cocoapods/v/DIAnalytics2.svg?style=flat)](https://cocoapods.org/pods/DIAnalytics2)
[![License](https://img.shields.io/cocoapods/l/DIAnalytics2.svg?style=flat)](https://cocoapods.org/pods/DIAnalytics2)
[![Platform](https://img.shields.io/cocoapods/p/DIAnalytics2.svg?style=flat)](https://cocoapods.org/pods/DIAnalytics2)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

- Firebase project and his "GoogleService-Info.plist". For more information, refer to [Firebase Cloud Messaging docs][1]
- Application ID provided by Dialog Insight

## Installation

DIAnalytics2 is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

1. Add the pods.

```ruby
pod 'Firebase/Core'
pod 'Firebase/Messaging'
pod 'DIAnalytics2'
```
2. Add Background Modes to your project

Click on your project's name in the explorer, select your target and go to the Signing & Capabilities tab. In the Background Modes section, select Background fetch and Remote notifications. Also click on +Capabilities and add Push Notifications.

3. Configure your Firebase project and copy your "GoogleService-Info.plist" in the Xcode project.

## Usage

1. Open your `AppDelegate.h` file.
2. Add the following imports

```
#import <FirebaseCore/FirebaseCore.h>
#import <FirebaseMessaging/FirebaseMessaging.h>
```

3. Add `FIRMessagingDelegate` to your AppDelegate delegates.

```
@interface AppDelegate : UIResponder <UIApplicationDelegate, FIRMessagingDelegate>
```

4. Open your `AppDelegate.m` file.
5. Add the import `#import <DIAnalytics2/DIAnalytics.h>`.
6. In `application:didFinishLaunchingWithOptions:`, copy the following code.

```objective-c
// For France
[[DIAnalytics shared] setBaseUrl:@"https://app.mydialoginsight.com/"];
// For other countries
[[DIAnalytics shared] setBaseUrl:@"https://app.dialoginsight.com/"];
[[DIAnalytics shared] enableLogs];
[[DIAnalytics shared] startWithApplication:application applicationId:@"YOUR_DIALOG_INSIGHT_APPLICATION_ID"];
[[DIAnalytics shared] registerForRemoteNotification];

[FIRApp configure];
[FIRMessaging messaging].delegate = self;
```

7. In `application:didReceiveRemoteNotification:fetchCompletionHandler:`, copy the following code.

```objective-c
[[DIAnalytics shared] didReceiveRemoteNotification:userInfo];
completionHandler(UIBackgroundFetchResultNoData);
```

8. Add the following code for `didReceiveRegistrationToken`.

```
- (void)messaging:(FIRMessaging*)messaging didReceiveRegistrationToken:(NSString*)fcmToken {
    [[DIAnalytics shared] didReceiveRegistrationToken:fcmToken];
}
```

9. Send information about a user.

The code below is an example on how to send information about a contact.

```objective-c
DIContact *contactData = [[DIContact alloc] init];
[contactData.diContactData setValue:@"1" forKey:@"f_ID"];
[contactData.diContactData setValue:@"john@doe.com" forKey:@"f_EMail"];
[contactData.diContactData setValue:@"John" forKey:@"f_FirstName"];
[contactData.diContactData setValue:@"Doe" forKey:@"f_LastName"];

[[DIAnalytics shared] updateContact:contactData];
```

You can then retrieve, if needed, this contact's unique guid.

```objective-c
[[DIAnalytics shared] getGuid:^(NSString *guid) {
    NSLog(@"%@", guid);
}];
```

10. (optional) Provide your own UNUserNotificationCenterDelegate

You can, if you wish, provide your own or a custom UNUserNotificationCenterDelegate by setting `[DIAnalytics shared].userNotificationCenterDelegate`

11. (optional) If your project is in Swift

If your project is in Swift, you will need a briding header file. In the bridging header file, add the import

## (optional) Enable images in your push notifications

1. Change, in the `application:didReceiveRemoteNotification:fetchCompletionHandler:` method, the line `completionHandler(UIBackgroundFetchResultNoData);` to `completionHandler(UIBackgroundFetchResultNewData);`

2. Add a Notification Service Extension to your project. Click on File > New > Target and select Notification Service Extension.

3. Important! Make sure the deployment target of the newly created Notification Service Extension is the same as your app's deployment target. This can be verified in the Deployment Info section of the app's target and the extension's target. Also make sure your Podfile's deployment target is the same.

4. Since the Notification Service Extension has its own bundle id, it must be set up with its own App ID and provisioning profile. Please verify through the Apple Developer Service.

5. In your Podfile, add the following lines.

```
target 'YourNotificationServiceExtension' do
  pod 'GoogleUtilities'
  pod 'Firebase/Messaging'
end
```

and in your Podfile regular app's target, also add `pod 'GoogleUtilities'` above the `Firebase` pods.

6. In your NotificationService.m, copy the following code.

```
#import "NotificationService.h"
#import <FirebaseCore/FirebaseCore.h>
#import <FirebaseMessaging/FirebaseMessaging.h>

@interface NotificationService () <NSURLSessionDelegate>
@property(nonatomic) void (^contentHandler)(UNNotificationContent *contentToDeliver);
@property(nonatomic) UNMutableNotificationContent *bestAttemptContent;
@end

@implementation NotificationService

- (void)didReceiveNotificationRequest:(UNNotificationRequest *)request withContentHandler:(void (^)(UNNotificationContent * _Nonnull))contentHandler {
    self.contentHandler = contentHandler;
    self.bestAttemptContent = [request.content mutableCopy];


    // Call FIRMessaging extension helper API.
    [[FIRMessaging extensionHelper] populateNotificationContent:self.bestAttemptContent
                                            withContentHandler:contentHandler];
}

- (void)serviceExtensionTimeWillExpire {
    // Called just before the extension will be terminated by the system.
    // Use this as an opportunity to deliver your "best attempt" at modified content, otherwise the original push payload will be used.
    self.contentHandler(self.bestAttemptContent);
}

@end
```

## Author

Simon, simonricgir@gmail.com

## License

Commercial, see LICENSE.txt
