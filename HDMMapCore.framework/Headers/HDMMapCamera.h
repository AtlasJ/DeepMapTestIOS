//
//  HDMMapCamera.h
//  hdm-mapcore-lib
//
//  Created by Stadin Benjamin on 05.04.17.
//
//

#import <Foundation/Foundation.h>
#import <HDMMapCore/HDMMapTypes.h>


/**
 Enum provides available easing functions
 */
typedef NS_ENUM(NSInteger, HDMCameraEasingMode)
{
    /// Linear
    HDMEasingLinear,
    ///QuadraticIn
    HDMEasingQuadraticIn,
    ///QuadraticOut
    HDMEasingQuadraticOut,
    ///QuadraticInOut
    HDMEasingQuadraticInOut,
    ///CubicIn
    HDMEasingCubicIn,
    ///CubicOut
    HDMEasingCubicOut,
    ///CubicInOuе
    HDMEasingCubicInOut,
    ///Constant
    HDMEasingConstant,
    ///Instant
    HDMEasingInstant
};

/**
 HDMMapCamera
 */
@interface HDMMapCamera : NSObject


/**
 Initialize instance of HDMMapCamera

 @param lookAt The center coordinate the camera is looking at.
 @param distance Distance from the center coordinate the camera is located at.
 @param bearingAngle Angle the camera is oriented to look at the map. Zero means up is north.
 @param tiltAngle  The angle the camera is looking on the map. 90 means directly from above, zero means from the side.
 @return Initialized instance of HDMMapCamera
 */
- (instancetype)initWithLookAt:(HDMMapCoordinate)lookAt distance:(double)distance bearingAngle:(double)bearingAngle tiltAngle:(double)tiltAngle;


/**
 Initialize instance of HDMMapCamera

 @param lookAt The center coordinate the camera is looking at.
 @param distance Distance from the center coordinate the camera is located at.
 @param bearingAngle Angle the camera is oriented to look at the map. Zero means up is north.
 @param lowerTiltAngle The lower tilt angle of the camera (when zoomed in max). Same as for tiltAngle.
 @param upperTiltAngle The upper tilt angle of the camera (when zoomed out max). Same as for tiltAngle.
 @param easingMode  The easing mode used to interpolate between lower and upper tilt angles.
 @return Initialized instance of HDMMapCamera
 */
- (instancetype)initWithLookAt:(HDMMapCoordinate)lookAt distance:(double)distance bearingAngle:(double)bearingAngle lowerTiltAngle:(double)lowerTiltAngle upperTiltAngle:(double)upperTiltAngle easingMode:(HDMCameraEasingMode)easingMode;

/**
 The center coordinate the camera is looking at. Camera is actually moved to look at that location. Has the same effect as using mapview.moveTo 
 */
@property (assign) HDMMapCoordinate lookAt;

/**
 Distance from the center coordinate the camera is located at. 
 */
@property (assign) double distance;

/**
 Angle the camera is oriented to look at the map. Zero means up is north. 
 */
@property (assign) double bearingAngle;

/**
 The angle the camera is looking on the map. 90 means directly from above, zero means from the side. 
 */
@property (assign) double tiltAngle;

/**
 The lower tilt angle of the camera (when zoomed in max). Same as for tiltAngle.
 */
@property (assign) double lowerTiltAngle;


/**
 The upper tilt angle of the camera (when zoomed out max). Same as for tiltAngle.
 */
@property (assign) double upperTiltAngle;

/**
 The easing mode used to interpolate between lower and upper tilt angles.
 */
@property (assign) HDMCameraEasingMode easingMode;

@end
