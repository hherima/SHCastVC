//
//  Device.h
//  SVDLNADemo
//
//  Created by  bolizhou on 17/2/7.
//  Copyright © 2017年  bolizhou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Service.h"

@interface Address : NSObject <NSCoding>

@property (copy, nonatomic) NSString *ipv4;
@property (copy, nonatomic) NSString *ipv6;
@property (copy, nonatomic) NSString *port;

@end

@interface SsdpResponseHeader : NSObject

@property (copy, nonatomic) NSString *statusCode;
@property (copy, nonatomic) NSString *location;
@property (copy, nonatomic) NSString *maxAge;
@property (copy, nonatomic) NSString *usn;
@property (copy, nonatomic) NSString *st;

@property (strong, nonatomic) Address *address;

- (instancetype)initWithReceivedMsg:(NSString *)message;

@end

@class Device;

@interface DeviceDescription : NSObject <NSCoding>

@property (copy, nonatomic) NSString *deviceType;
@property (copy, nonatomic) NSString *friendlyName;
@property (copy, nonatomic) NSString *manufacturer;
@property (copy, nonatomic) NSString *modelDescription;
@property (copy, nonatomic) NSString *modelName;
@property (copy, nonatomic) NSString *udn;
@property (strong, nonatomic) NSArray<Service *> *services;
@property (weak, nonatomic) Service *connectionService;
@property (weak, nonatomic) Service *transportService;
@property (weak, nonatomic) Service *renderControlService;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

@interface Device : NSObject <NSCopying, NSCoding>

@property (strong, nonatomic) DeviceDescription *ddd;
@property (strong, nonatomic) Address *address;
@property (copy, nonatomic) NSString *location;
@property (copy, nonatomic) NSString *maxAge;
@property (copy, nonatomic) NSString *usn;
@property (copy, nonatomic) NSString *st;

- (instancetype)initWithSsdpResponse:(SsdpResponseHeader *)header;

@end
