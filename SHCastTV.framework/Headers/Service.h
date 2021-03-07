//
//  Service.h
//  SVDLNADemo
//
//  Created by  bolizhou on 17/2/7.
//  Copyright © 2017年  bolizhou. All rights reserved.
//

#import <Foundation/Foundation.h>
#define  DDLogDebugPlayer(...) {}
typedef NS_ENUM(NSInteger, UPnPAVTransportState)         //视频播放状态枚举
{
    UPnPAVTransportStateUnknown,
    UPnPAVTransportStatePlaying,
    UPnPAVTransportStatePaused,
    UPnPAVTransportStateStopped,
    UPnPAVTransportStateTransitioning
};

@interface Argument : NSObject

@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *direction;
@property (copy, nonatomic) NSString *relatedStateVariable;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

@interface Action : NSObject

@property (copy, nonatomic) NSString *name;
@property (strong, nonatomic) NSArray<Argument *> *arguments;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

@interface AllowedValueRange : NSObject

@property (copy, nonatomic) NSString *minimum;
@property (copy, nonatomic) NSString *maximum;
@property (copy, nonatomic) NSString *step;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

@interface StateVariable : NSObject

@property (nonatomic) BOOL isMulticast;
@property (nonatomic) BOOL sendEvents;
@property (copy, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *dataType;
@property (copy, nonatomic) NSString *defaultValue;
@property (strong, nonatomic) AllowedValueRange *allowedValueRange;

@end

@class Service;

@interface ServiceDescription : NSObject

@property (strong, nonatomic) NSArray<Action *> *actions;
@property (weak, nonatomic) Service *service;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

@interface Service : NSObject <NSCoding>

@property (copy, nonatomic) NSString *serviceID;
@property (copy, nonatomic) NSString *serviceType;
@property (copy, nonatomic) NSString *SCPDURL;
@property (copy, nonatomic) NSString *controlURL;
@property (copy, nonatomic) NSString *eventSubURL;
@property (copy, nonatomic) NSString *reserved;
@property (strong, nonatomic) ServiceDescription *sdd;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@end

@interface GetProtocolInfoResponse : NSObject
@property (nonatomic, assign) BOOL isError;
@property (copy, nonatomic) NSString *sink;

- (instancetype)init;

- (instancetype)initWithData:(NSData *)data;

@end

@interface GetTransportInfoResponse : NSObject

@property (assign, nonatomic) BOOL isError;
@property (copy, nonatomic) NSString *currentSpeed;
@property (assign, nonatomic) UPnPAVTransportState currentTransportState;
@property (copy, nonatomic) NSString *currentTransportStatus;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (instancetype)initWithData:(NSData *)data;

@end

@interface GetPositionInfoResponse : NSObject

@property (copy, nonatomic) NSString *absCount;
@property (copy, nonatomic) NSString *absTime;
@property (copy, nonatomic) NSString *relCount;
@property (copy, nonatomic) NSString *relTime;
@property (copy, nonatomic) NSString *track;
@property (copy, nonatomic) NSString *trackDuration;
@property (copy, nonatomic) NSString *trackMetaData;

- (instancetype)initWithData:(NSData *)data;

@end
