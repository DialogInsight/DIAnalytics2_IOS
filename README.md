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

11. (optional) If your project uses the "Trusted identity" flag, you must pass the guid linked to your contact, the Firebase token and the identity fields of the contact to an authenticated web service. See [doc](http://app.dialoginsight.com/webservices/#tab=client&section=services&application=OFC4&service=Mobile&method=Identity). 

## Author

Simon, simonricgir@gmail.com

## License

Commercial, see LICENSE.txt
