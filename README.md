# DIAnalytics2_IOS

[![Version](https://img.shields.io/cocoapods/v/DIAnalytics.svg?style=flat)](http://cocoapods.org/pods/DIAnalytics2)
[![License](https://img.shields.io/cocoapods/l/DIAnalytics.svg?style=flat)](http://cocoapods.org/pods/DIAnalytics2)
[![Platform](https://img.shields.io/cocoapods/p/DIAnalytics.svg?style=flat)](http://cocoapods.org/pods/DIAnalytics2)

## Requirements

- Firebase Project
- Firebase Cloud Messaging configured in Firebase console. For more information, refer to [Firebase Cloud Messaging docs][1]
- Firebase project's "GoogleService-Info.plist".
- Application ID provided by Dialog Insight

## Installation

DIAnalytics is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "DIAnalytics2"
```

## Usage

1. To use the SDK code, add @import DIAnalytics2 to the file.

2. Include this code to the application function :
   application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
   
```objective-c
[[DIAnalytics shared] startWithApplication:application applicationId:@"..."]
```

3. Add the following code to your AppDelegate:

```objective-c
- (void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary*)userInfo
  fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    [[DIAnalytics shared] didReceiveRemoteNotification:userInfo];
    completionHandler(UIBackgroundFetchResultNoData);
}
```

4. Add your "GoogleService-Info.plist" provided by Firebase to the root of your project. Ensure that the file is in the "Copy Bundle Resources" of your target project.

5. In Signing & Capabilities of the project, add the Background Modes Background fetch and
Remote notifications and add Push Notifications.

6. Example code to identify a contact.

```objective-c
DIContact *contactData = [[DIContact alloc] init];
[contactData.diContactData setValue:... forKey:@"f_ID"];
[contactData.diContactData setValue:... forKey:@"f_EMail"];
[contactData.diContactData setValue:... forKey:@"f_FirstName"];
[contactData.diContactData setValue:... forKey:@"f_LastName"];
[[DIAnalytics shared] updateContact:contactData];
[[DIAnalytics shared] requestToken:^(NSString *token) {
[Alert show:token];
}];
```
## Authors

Dialog Insight, info@dialoginsight.com

## License

[1]: https://firebase.google.com/docs/cloud-messaging/
[2]: https://support.dialoginsight.com/en/support/solutions/articles/1000249331-defining-project-fields
