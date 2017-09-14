//
//  HDMLocation.h
//  hdm-mapcore-lib
//
//  Created by Stadin Benjamin on 26.03.17.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <HDMMapCore/HDMMapTypes.h>


/**
 Class defines building descriptor
 */
@interface HDMBuilding : NSObject <NSCopying>

/**
 Initialize with the specified feature id

 @param featureId FeatureID of initializing building
 @return Initialized instance of HDMBuilding
 */
-(instancetype _Nonnull )initWithfeatureId:(uint64_t)featureId;

/**
    The unique identifier of a building node.
 */
@property(readonly, nonatomic) uint64_t featureId;

@end

/**
 Class defines a logical representation for a building floor.
 */
@interface HDMFloor : NSObject <NSCopying>

/**
 Initialize with the specified feature id and level

 @param featureId  The unique identifier of a building node where floor are in.
 @param level level
 @return Initialized instance of HDMFloor
 */
-(instancetype _Nonnull )initWithfeatureId:(uint64_t)featureId level:(float)level;

/**
 Level
 
 @note 
    This is a logical representation for a building floor.
    Floor 0 represents the floor designated as "ground".
    Negative numbers designate floors below the ground floor
    and positive to indicate floors above the ground floor.
 
    It is not intended to match any numbering used within the building,
    though values can be expressed as floats to ease keeping the
    numbering scheme close to actual levels with additional consideration of
    mezzanine floor levels.
 
    It is also wrong to use the level as an estimate of altitude.
 */
@property(readonly, nonatomic) float level;


/**
 The unique identifier of a building node.
 */
@property(readonly, nonatomic) uint64_t featureId;

@end

/**
 Represents a geographical coordinate with accuracy and timestamp information.
 
 This object basically provides the same info as CLLocation and can be initialized from a
 CLLocation object, but it uses Deep Map's 3D coordinates which allow to use various CRS
 and elevation models, and also allows to define the current building node and floor level.
 */
@interface HDMLocation : NSObject <NSCopying>


/**
 Initialize with the specified coordinate and CRS.

 @param coordinate Coordnates of location
 @param crs Coordinate reference system
 @return Initialized instance of HDMLocation
 */
- (_Nonnull instancetype)initWithCoordinate:(HDMMapCoordinate)coordinate
                                        crs:(NSString*_Nonnull)crs;

/**
 Initialize a location with the specified building and floor, without knowledge of coordinate and CRS.

 @param building Building where coordunates are in
 @param floor Information about the logical floor that you are on in the current building.
 @return Initialized instance of HDMLocation
 */
- (_Nonnull instancetype)initWithBuilding:(HDMBuilding*_Nullable)building
                                    floor:(HDMFloor*_Nullable)floor;

/**
 Initializes an instance of HDMLocation with specified parameters.
 The crs defaults to EPSG:4326 (WGS84 used by GPS) if nil.

 @param coordinate Coordnates of location
 @param crs Coordinate reference system
 @param hAccuracy Horizontal accuracy of location
 @param vAccuracy Vertical accuracy of location
 @param course The course of the location in degrees to the true North
 @param speed The speed of the location in meter / second
 @param timestamp Time when at which the location was determined.
 @param building Building where coordunates are in
 @param floor Information about the logical floor that you are on in the current building.
 @return Initialized instance of HDMLocation
 */
- (_Nonnull instancetype)initWithCoordinate:(HDMMapCoordinate)coordinate
                               crs:(NSString* _Nonnull)crs
                horizontalAccuracy:(CLLocationAccuracy)hAccuracy
                  verticalAccuracy:(CLLocationAccuracy)vAccuracy
                            course:(CLLocationDirection)course
                             speed:(CLLocationSpeed)speed
                          timestamp:(NSDate * _Nonnull)timestamp
                          building:(HDMBuilding*_Nullable)building
                             floor:(HDMFloor*_Nullable)floor;

/**
 Initializes an instance of HDMLocation with specified coordinate.
 
 @param coordinate Required coordinates
 @return HDMLocation instance
 */
+ (_Nonnull instancetype)locationWithCoordinate:(HDMMapCoordinate)coordinate;

/**
 The coordinate of the current location.
 */
@property(readonly, nonatomic) HDMMapCoordinate coordinate;

/**
 The coordinate reference system (CRS) used by this coordinate.
 */
@property(readonly, nonatomic, nonnull) NSString *CRS;

/**
 The horizontal accuracy of the current location. Negative lateral location is invalid.
 */
@property(readonly, nonatomic) CLLocationAccuracy horizontalAccuracy;


/**
 The vertical accuracy of the current location. Negative if altitude is invalid.
 */
@property(readonly, nonatomic) CLLocationAccuracy verticalAccuracy;

/**
 The course of the location in degrees to the true North. Value is negative if the course is invalid.
 @note Range: 0.0 - 359.9 degrees, 0 is true North
 */
@property(readonly, nonatomic) CLLocationDirection course;


/**
 The speed of the location in meter / second. The value is negative if the speed is invalid
 */
@property(readonly, nonatomic) CLLocationSpeed speed;


/**
 Timestamp when at which the location was determined.
 */
@property(readonly, nonatomic, copy, nonnull) NSDate *timestamp;

/**
 Contains information about the building ID that you are in.

 @note Returns nil if no building info is available.
 */
@property(readonly, nonatomic, copy, nullable) HDMBuilding *building;


/**
 Contains information about the logical floor that you are on in the current building.
 
 @note Returns nil if no floor info is available.
 */
@property(readonly, nonatomic, copy, nullable) HDMFloor *floor;

@end
