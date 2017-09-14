//
//  HDMAnnotation.h
//  HDMMapCoreDemo
//
//  Created by Mikalai Lasitsa on 29.10.15.
//  Copyright (c) 2015 Heidelberg mobil International GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HDMMapCore/HDMMapTypes.h>
#import <UIKit/UIKit.h>

@class HDMAnnotation;

/**
 * The HDMAnnotationDelegate protocol defines a set of optional methods that you can use to receive annotation-related update messages
 */
@protocol HDMAnnotationDelegate <NSObject>

@optional
/**
 Method called if annotation view was tapped.
 @param annotation Annotation was tapped
 */
-(void)annotationTapped:(HDMAnnotation * _Nonnull)annotation;

/**
 Method called if Left Accessory of annotation view was tapped.

 @param annotation Annotation was tapped
 */
-(void)leftAnnotationAccessoryTapped:(HDMAnnotation * _Nonnull)annotation;

/**
 Method called if Rigth Accessory of annotation view was tapped.
 
 @param annotation Annotation was tapped
 */
-(void)rightAnnotationAccessoryTapped:(HDMAnnotation * _Nonnull)annotation;

@end

/**
 The HDMAnnotation class defines a annotation object located at a specified point. You can use this class for showing title, subtitle and two images.
 */
@interface HDMAnnotation : NSObject

/**
 *  @name Properties
 */

/**
 The coordinate of the annotation.
 @note Returns coordinates of annotation in world coordinates (WGS84)
 */
@property (nonatomic, readonly) HDMMapCoordinate coordinate;

/**
 Read-only selfgenerated annotation view.
 @note Generated from title & subtitle, left & right accessory views if available. Do not recommended use it for adding extra subviews.
 */
@property (nonatomic, readonly, nullable) UIView *anotationView;

/**
 Custom view for annotation can be set by passing new view to this property.
 @note By default passed custom view is clipped by default annotation border, which can be turn off by passing YES to defaultBorderHidden property. Normalazed ancor point for view is (0.5,1)
 */
@property (strong, nonatomic, nullable) UIView *contentView;

/**
 By default annotation view is clipped by annotation border, in case another layout is required border can be turn off by passing YES.
 @note For hidding default border value YES should be passed BEFORE adding annotation to the map.
 */
@property (assign, nonatomic) BOOL defaultBorderHidden;

/**
 Annotation title.
 @see subtitle
 */
@property (nonatomic, copy, nullable) NSString *title;

/**
 Annotation subtitle
 @see title
 */
@property (nonatomic, copy, nullable) NSString *subtitle;

/**
 Left Accessory view
 @note Can be used for dispaying extra annotation icons. size is 30x30px
 */
@property (nonatomic, strong, nonnull) UIView *leftCalloutAccessoryView;

/**
 Right Accessory view
 @note Can be used for dispaying extra annotation icons like size is 30x30px
 */
@property (nonatomic, strong, nonnull) UIView *rightCalloutAccessoryView;

/**
 Annotation Delegate
 @note See HDMAnnotationDelegate.
 */
@property (nonatomic, assign, nonnull) id<HDMAnnotationDelegate> delegate;

/**
 *  @name Creating
 */
/**
 Contructor
 @param coordinate The center point (specified as a UTM map coordinate) of the annotation

 @note Returns an initialized HDMAnnotation object that located in specified coordinate

     HDMAnnotation *annotation = [[HDMAnnotation alloc] initWithCoordinate:_tapPoint];
     annotation.title = @"test annotation"
     [self.mapViewController.mapView addAnnotation:annotation];
 */
- (instancetype _Nonnull)initWithCoordinate:(HDMMapCoordinate)coordinate;


/**
 Change coordinate of exist annotation

 @param coordinate New anotation's coordinate
 @param animated If YES, animate annotation moving to required coordinate.
 */
- (void)updateCoordinate:(HDMMapCoordinate)coordinate animated:(BOOL)animated;

@end

/**
 The HDMPinAnnotation class defines a annotation Pin object located at a specified point.
 */
@interface HDMPinAnnotation : HDMAnnotation

/**
 YES if want to show callout by tap to pin
 @note Default value is NO
 */
@property (nonatomic, assign) BOOL canShowCallout;

/**
 Set color for head of pin.
 @note Default value is Red
 */
@property (nonatomic, retain, nonnull) UIColor *pinColor;

@end

/**
 The HDMUserLocationAnnotation class defines a annotation cirle object("blue dot" style)
 */
@interface HDMUserLocationAnnotation : HDMAnnotation

/**
 Set color for user location.
 @note Default value is Blue
 */
@property (nonatomic, retain, nonnull) UIColor *tintColor;

/**
 Set accuracy radius
 */
@property (nonatomic, assign) float accuracyRadius;

@end



