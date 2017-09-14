//
//  HDMFeature.h
//  hdm-mapcore-lib
//
//  Created by Stadin Benjamin on 25.03.17.
//
//

#import <Foundation/Foundation.h>
#import <HDMMapCore/HDMMapTypes.h>
#import <HDMMapCore/HDMLocation.h>

/**
 Returns a string representation of the specified point.
 
 @param point Point to convert to string.
 */
NSString* _Nonnull NSStringFromHDMMapCoordinate(HDMMapCoordinate point);


/**
 Class defines map object's parameters and attributes.
 */
@interface HDMFeature : NSObject

/**
 Map object (HDMFeature) constructor
 
 @param featureId Map object(feature) feature Id
 @param location Feature's coordinates
 @param attributes Feature's attributes
 @return Instance of Feature
 */
+ (id _Nonnull)featureWithId:(uint64_t)featureId location:(HDMLocation*_Nullable)location attributes:(NSDictionary* _Nonnull)attributes;

/**
 Map object (HDMFeature) constructor

 @param featureId Map object(feature) feature Id
 @param location Feature's coordinates
 @param attributes Feature's attributes
 @return Instance of Feature
 */
- (id _Nonnull)initWithId:(uint64_t)featureId location:(HDMLocation*_Nullable)location attributes:(NSDictionary*_Nonnull)attributes;

/**
 *  The object's location
 */
@property (nonatomic, readonly, nonnull) HDMLocation *location;

/**
 *  The feature's entity ID
 */
@property (nonatomic, readonly) uint64_t featureId;

/**
 *  The key-value attributes of this feature. All methods below are shortcuts to
 *  query the feature's attributes.
 */
@property (nonatomic, readonly, nonnull) NSDictionary *attributes;

/**
 *  The default display name, commonly used as label on the map.
 
 This is a shortcut to the "name" attribute.
 */
-(NSString* _Nonnull)defaultDisplayName;

/**
 *  The localized default display name, common used as label on the map.
 
 This is a shortcut to the "name:locale" attribute, where locale is a i18n 
 locale identifier (e.g. "en" for english"). 
 
 @note Returns the defaultDisplayName if no localized display name was found.
 @return Localized display name or defaultDisplayName if no localized display name was found.
 */
-(NSString* _Nonnull)defaultDisplayNameWithLocale:(NSString* _Nonnull)locale;


/**
 Fetch localized attribute for sprcifed key

 @param key Requested attribute name (key)
 @param locale Requested localte
 @return Map object attribute value for specified key and locale.
 */
-(NSString* _Nonnull)valueForKey:(NSString*_Nonnull)key withLocale:(NSString* _Nonnull)locale;

/**
 * The original serial (aka customer identifier) of this feature.
 
 The original serial is the main identifier to be used to map customer
 data with features on the map.
 */
-(NSString * _Nonnull)originalSerial;


/**
 Map object's Feture Type
 */
@property (nonatomic, strong, nullable) NSString *featureType;

@end

