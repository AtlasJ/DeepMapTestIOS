//
//  HDMRoutingPathFeature.h
//  hdm-mapcore-lib
//
//  Created by Mikalai Lasitsa on 7/14/17.
//
//

#import <HDMMapCore/HDMFeature.h>

/**
*  Class represents routing data, including points and text description.
*  @see HDMMapRouting
*/
@interface HDMMapRouteInfo : NSObject

/**
 *  Returns HDMMapRouteInfo object init. Unless required, this method should not be used
 *          by applications, other than for changing route segments of a precalculated HDMMapRouting instance.
 *
 *  @param points             Array of route points
 *  @param pointsDescription  the point descriptions for each node
 *  @param originalPoiIndexes sortered indexes of points
 *  @param routeLenght        length of the route
 *
 *  @return HDMMapRouting instance.
 */
- (instancetype)initWithRoutePoints:(NSArray*)points pointsDescription:(NSArray*)pointsDescription indexes:(NSArray*)originalPoiIndexes routeLenght:(double)routeLenght;

/**
 *  Array of map points (UTM: x,y,z) for drawing route line on a map view
 */
@property (nonatomic, readonly) NSArray* routePoints;

/**
 *  Array of text descriptions for each point in routePoints
 */
@property (nonatomic, readonly) NSArray<NSString*>* pointsDescription;

/**
 *  Lenght of found path in meters.
 */
@property (nonatomic, readonly) double lenght;

/**
 *  Sortered indexes of points
 */
@property (nonatomic,readonly) NSArray *originalPoiIndexes;

@end


/**
 Routing path feature descriptor.
 */
@interface HDMRoutingPathFeature : HDMFeature


/**
 Information about roting line points, length end etc
 */
@property (nonatomic, readonly) HDMMapRouteInfo *routeInfo;


/**
 Initialize HDMRoutingPathFeature

 @param routeInfo Routing info
 @param featureType Map style identifier which defined in map.css (like "routing.line")
 @return Initialized HDMRoutingPathFeature inctance
 */
- (instancetype)initWithRouteInfo:(HDMMapRouteInfo*)routeInfo featureType:(NSString*)featureType;


/**
 Initialize HDMRoutingPathFeature

 @param routeInfo <#routeInfo description#>
 @return Initialized HDMRoutingPathFeature inctance
 
 @note If send this instance of HDMRoutingPathFeature to draw engine will use "routing.line" as routing line styling
 */
- (instancetype)initWithRouteInfo:(HDMMapRouteInfo*)routeInfo;

@end


