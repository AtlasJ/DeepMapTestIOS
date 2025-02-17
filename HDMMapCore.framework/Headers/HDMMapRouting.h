//
//  HDMMapRouting.h
//  HDMMapCore
//
//  Created by Mikalai Lasitsa on 2/15/16.
//  Copyright © 2016 Heidelberg mobil International GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <HDMMapCore/HDMMapTypes.h>
#import <HDMMapCore/HDMLocation.h>
#import <HDMMapCore/HDMRoutingPathFeature.h>

#import "HDMProjector.h"

/**
 Callback defenition

 @param geoID <#geoID description#>
 @return <#return value description#>
 */

/**
 *  Class represent
 */
@interface HDMMapRouting : NSObject

/**
 *  Path to using MapData database
 */
@property (nonatomic, readonly) NSString* mapPath;

/**
 * @return Return YES if routing data is avaiable.
 */
@property (nonatomic, readonly) BOOL isRoutingDataAvailable;

/**
 *  Path to using HDMMapScene
 */
//@property (nonatomic, readonly) HDMMapScene* scene;

/**
 *  Locale that will be used for fetching names of map objects.
 *
 *  @note Default value is "en". If text description of route is not required this property can be ignored.
 */
@property (nonatomic, copy) NSString* locale;

/**
 *  Find and return the path beetween points.
 *
 *  @param points       array of points with will used for finding route
 *
 *  @return Route descriptor.
 *  @see HDMMapRouteInfo
 */
- (HDMRoutingPathFeature*)calculateRouteBetweenPoints:(NSArray<HDMLocation*>*)locations;

/**
 *  Find and return the shortestr path beetween specified points.
 *
 *  @param points       array of points with will used for finding route
 *
 *  @return Route descriptor.
 *  @see HDMMapRouteInfo
 *  @note Methods implement greedy TSP algorithm. First element in points array is a start point of path. 
 */
- (HDMRoutingPathFeature*)findShortestPathBetweenLocations:(NSArray<HDMLocation*>*)locations;

/**
 *  Find and return the shoterst path from startPoint to destinationPoint.
 *
 *  @param startPoint       start Location
 *  @param destinationPoint destination Location
 *
 *  @return Route descriptor.
 *  @see HDMMapRouteInfo
 */
- (HDMRoutingPathFeature*)calculateRouteFromLocation:(HDMLocation*)start toDestination:(HDMLocation*)destination NS_SWIFT_NAME(calculateRoute(from:to:));

//- (void)sayWord:(NSString*)word NS_SWIFT_NAME(say(_:));

/**
 *  Find and return the shoterst path from startPoint to destinationPoint.
 *
 *  @param startPoint       start point
 *  @param destinationPoint destination point
 *
 *  @return Route descriptor.
 *  @see HDMMapRouteInfo
 */
- (HDMRoutingPathFeature*)calculateRouteFrom:(HDMMapCoordinate)startPoint destinationPoint:(HDMMapCoordinate)destinationPoint  NS_SWIFT_NAME(calculateRoute(from:to:));

/**
 *  Find and return the shoterst path from startPoint to destinationPoint.
 *
 *  @param startPoint       start point
 *  @param destinationGeoID destination Geo ID
 *
 *  @return Route descriptor.
 *  @see HDMMapRouteInfo
 */
- (HDMMapRouteInfo*)calculateRouteFrom:(HDMMapCoordinate)startPoint destinationGeoID:(uint64_t)destinationGeoID NS_SWIFT_NAME(calculateRoute(from:to:));

/**
 *  Returns HDMMapRouting objects init with routing graph from data base on path.
 *
 *  @param path path to MapData database which includes routing graph.
 *
 *  @return HDMMapRouting instance.
 *  @note If developer create HDMMapRouting instance using this constructor text desctription for route will unavailable.
 *  @see initWithMapPath:sceneForTextDescription:
 */
- (instancetype)initWithMapPath:(NSString*)path coordinateProjector:(HDMProjector*)projector;

/**
 *  Returns HDMMapRouting objects init with routing graph from data base on path.
 *
 *  @param path path to MapData database which includes routing graph.
 *
 *  @return HDMMapRouting instance.
 *  @note If developer create HDMMapRouting instance using this constructor text desctription for route will unavailable.
 *  @see initWithMapPath:sceneForTextDescription:
 */
- (instancetype)initWithMapPath:(NSString*)path coordinateProjector:(HDMProjector*)projector coordinateProvider:(HDMMapCoordinate (^)(uint64_t geoID))block;

@end
