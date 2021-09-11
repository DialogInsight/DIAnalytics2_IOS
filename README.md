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

1. Add the pod.

```ruby
pod 'DIAnalytics2'
```
2. Add Background Modes to your project

Click on your project's name in the explorer, select your target and go to the Signing & Capabilities tab. In the Background Modes section, select Background fetch and Remote notifications. Also click on +Capabilities and add Push Notifications.

3. Configure your Firebase project and copy your "GoogleService-Info.plist" in the Xcode project.

## Usage

1. Open your `AppDelegate.m` file.
2. Add the import `@import DIAnalytics2`.
3. In `application:didFinishLaunchingWithOptions:`, copy the following code.

```objective-c
// For France
[[DIAnalytics shared] setBaseUrl:@"https://app.mydialoginsight.com/"];
// For other countries
[[DIAnalytics shared] setBaseUrl:@"https://app.dialoginsight.com/"];
[[DIAnalytics shared] enableLogs];
[[DIAnalytics shared] startWithApplication:application applicationId:@"YOUR_DIALOG_INSIGHT_APPLICATION_ID"];
[[DIAnalytics shared] registerForRemoteNotification];
```

4. In `application:didReceiveRemoteNotification:fetchCompletionHandler:`, copy the following code.

```objective-c
[[DIAnalytics shared] didReceiveRemoteNotification:userInfo];
completionHandler(UIBackgroundFetchResultNoData);
```

3. Send information about a user.

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

## Author

Simon, simonricgir@gmail.com

## License

DIAnalytics2 is available under the MIT license. See the LICENSE file for more info.
