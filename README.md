# DIAnalytics2_IOS

[![Version](https://img.shields.io/cocoapods/v/DIAnalytics.svg?style=flat)](http://cocoapods.org/pods/DIAnalytics)
[![License](https://img.shields.io/cocoapods/l/DIAnalytics.svg?style=flat)](http://cocoapods.org/pods/DIAnalytics)
[![Platform](https://img.shields.io/cocoapods/p/DIAnalytics.svg?style=flat)](http://cocoapods.org/pods/DIAnalytics)

## Requirements

- Firebase Project
- Firebase Cloud Messaging configured in Firebase console. For more information, refer to [Firebase Cloud Messaging docs][1]
- Firebase project's "GoogleService-Info.plist".
- Application ID provided by Dialog Insight

## Installation

DIAnalytics is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "DIAnalytics"
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

----------------------------------------------old doc--------------------------------------------


1. Add your "GoogleService-Info.plist" provided by Firebase to the root of your project. Ensure that the file is in the "Copy Bundle Resources" of your target project.  

2. Add the following code to your AppDelegate:

```objective-c
#pragma mark - Notification delegate

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo {
    [DIAnalytics handleDidReceiveRemoteNotification:userInfo];

    if (application.applicationState == UIApplicationStateActive ) {
        NSLog(@"Application is in foreground when it received the notification, application should handle display of notification.");
    }
}

//For iOS under 10, you must implement these two methods to register for a token
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    NSLog(@"Unable to register for remote notifications: %@", error);
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [DIAnalytics handleDidRegisterForRemoteNotificationWithDeviceToken:deviceToken];
}

```

3. Setup your preference.
```objective-c
[DIAnalytics setLogEnabled:YES];
[DIAnalytics setBaseUrl:@"https://ofsys.com"];
```

4. Start the library with your ApplicationID provided by Dialog Insight in your "didFinishLaunchingWithOptions" implementation.

```objective-c
[DIAnalytics startWithApplicationId:@"MY_APPLICATION_ID_PROVIDED_BY_DIALOG_INSIGHT" withLaunchOptions:launchOptions];
```

5. Send information about the user.


    In order to identify a user of the application as a contact of your DI project, you must provide the information corresponding to        the fields of the [unique key][2].


    Note: 
    the DI fields always start with a "f_". In the DI project fields page, look at the fields tagged as “primary field” and note their      code. In the following steps, just prepend “f_” with any field code. For instance, a DI field with the code “idCustomer” will            become “f_idCustomer”.


    This is made in two simples step. First, gather the primary key fields informations in a dictionary.

    For example, a project where the unique key is composed only of the EMail field, do:
     ```objective-c
    NSMutableDictionary *customFieldsDictionary = [[NSMutableDictionary alloc] init];
    [customFieldsDictionary setObject:self.emailTextField.text forKey:@"f_EMail"];
    ```

    For a project where the unique key is composed of the fields FirstName and LastName, do:
    ```objective-c
    NSMutableDictionary *customFieldsDictionary = [[NSMutableDictionary alloc] init];
    [customFieldsDictionary setObject:self.firstNameTextField.text forKey:@"f_FirstName"];
    [customFieldsDictionary setObject:self.nameTextField.text forKey:@"f_LastName"];
    ```

    For a project where the unique key is composed only of a field named “idCustomer”, do:
    ```objective-c
    NSMutableDictionary *customFieldsDictionary = [[NSMutableDictionary alloc] init];
    [customFieldsDictionary setObject:self.idCustomerTextField.text forKey:@"f_idCustomer"];
    ```

    Then, make another dictionary with a “contact” entry and send it.
    ```objective-c
    NSDictionary *contactDictionary = [[NSDictionary alloc] initWithObjectsAndKeys:customFieldsDictionary, @"contact", nil];

    [DIAnalytics identify:contactDictionary];
    ```

6. Register for push notification. This will prompt to user an UIAlertView asking to authorize notifications.
```objective-c
[DIAnalytics registeForRemoteNotification];
```

## Authors

Dialog Insight, info@dialoginsight.com

## License

[1]: https://firebase.google.com/docs/cloud-messaging/
[2]: https://support.dialoginsight.com/en/support/solutions/articles/1000249331-defining-project-fields
