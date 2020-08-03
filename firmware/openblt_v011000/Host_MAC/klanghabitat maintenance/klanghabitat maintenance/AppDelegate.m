//
//  AppDelegate.m
//  klanghabitat maintenance
//
//  Created by Christian Sager on 02.08.20.
//  Copyright © 2020 klanghabitat. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}

- (IBAction)connectButton:(id)sender {

    printf("hello button!");
}



@end
