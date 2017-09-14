//
//  HDMMapTypes.h
//  HDMMapCore
//
//  Copyright (c) 2017 Heidelberg mobil International GmbH. All rights reserved.
//

#ifndef HDMMapCore_HDMMapTypes_h
#define HDMMapCore_HDMMapTypes_h

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 User data for easing functions
 */
typedef void* HDMMapEasingData;

/**
 Function that describes the value of a property given a percentage of completeness.
 
 @param time        Current time in a range [0, duration]
 @param source      Start value
 @param change      Change in value (eg. destination - source)
 @param duration    Duration
 @param data        Any user provided data
 */
typedef float (*HDMMapEasingFunction1f)(double time, float source, float change, double duration, HDMMapEasingData data);

/**
 A structure that contains a point in a three-dimensional coordinate system.
 */
typedef struct {
    ///Point on x-axis.
    double x;
    ///Point on y-axis.
    double y;
    ///Point on z-axis.
    double z;
    
} HDMMapCoordinate;

/**
 Compare two Coordainates

 @param lhs First coordunate for comparing
 @param rhs Second coordunate for comparing
 @return Return true if coordinates are equal, otherwise return false
 */
extern bool HDMMapCoordinateEqualCoordinate(HDMMapCoordinate lhs, HDMMapCoordinate rhs);

/**
 Returns a point with the specified coordinates.
 
 @param x The x-coordinate of the point to construct.
 @param y The y-coordinate of the point to construct.
 @param z The z-coordinate of the point to construct.
 */
extern HDMMapCoordinate HDMMapCoordinateMake(double x, double y, double z);
  
///A coordnate constant with location (0,0,0)
extern const HDMMapCoordinate HDMMapCoordinateZero;

typedef struct {
    HDMMapCoordinate point1;
    HDMMapCoordinate point2;
    HDMMapCoordinate point3;
    HDMMapCoordinate point4;
} HDMMapRegion;
    

/**
 Returns a region with the specified coordinates values.

 @param point1X The x-coordinate of the 1st point.
 @param point1Y The y-coordinate of the 1st point.
 @param point1Z The z-coordinate of the 1st point.
 @param point2X The x-coordinate of the 2nd point.
 @param point2Y The y-coordinate of the 2nd point.
 @param point2Z The z-coordinate of the 2nd point.
 @param point3X The x-coordinate of the 3rd point.
 @param point3Y The y-coordinate of the 3rd point.
 @param point3Z The z-coordinate of the 3rd point.
 @param point4X The x-coordinate of the 4th point.
 @param point4Y The y-coordinate of the 4th point.
 @param point4Z The z-coordinate of the 4th point.
 @return Region with the specified coordinates values.
 */
extern HDMMapRegion HDMMapRegionMake(double point1X, double point1Y, double point1Z,
                                                         double point2X, double point2Y, double point2Z,
                                                         double point3X, double point3Y, double point3Z,
                                                         double point4X, double point4Y, double point4Z);

/// A structure that contains width and height values.
typedef struct{
    double width;
    double height;
} HDMMapSize;

/**
 Returns a size with the specified size values.

 @param width The width
 @param height The height
 @return Size with the specified size values.
 */
extern HDMMapSize HDMMapSizeMake(double width, double height);
    
typedef struct{
    HDMMapCoordinate origin;
    HDMMapSize size;
} HDMMapRect;

/**
 Returns a map rectangle with the specified coordinate and size values.
 
 @param x The x-coordinate of the rectangle’s origin point.
 @param y The y-coordinate of the rectangle’s origin point.
 @param z The z-coordinate of the rectangle’s origin point.
 @param width The width of the rectangle.
 @param height The height of the rectangle.

 */
extern HDMMapRect HDMMapRectMake(double x, double y, double z, double width, double height);

/**
  A structure that defines a region of coordinates.
 
 @field center coordinate of the center of the region.
 @field span The size of the region given in the span of latitude and longitude.

 */
typedef struct{
    HDMMapCoordinate center;
    struct HDMMapCoordinateSpan{
        double latitudeDelta;
        double longitudeDelta;
    } span;
} HDMMapCoordinateRegion;

/**
 Returns a HDMMapCoordinateRegion at the given center point with given coordinate-span.
 
 @param x The x-coordinate of the center.
 @param y The y-coordinate of the center.
 @param z The z-coordinate of the center.
 @param latitudeDelta The size of the region in direction of latitude.
 @param longitudeDelta The size of the region in direction of logitude.
 */
extern HDMMapCoordinateRegion HDMMapCoordinateRegionMake(double x, double y, double z, double latitudeDelta, double longitudeDelta);
    
#ifdef __cplusplus
}
#endif

#endif
