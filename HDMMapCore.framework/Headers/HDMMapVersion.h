//
//  HDMMapVersion.h
//  HDMMapCore
//
//  Copyright (c) 2015 Heidelberg mobil International GmbH. All rights reserved.
//

#ifndef HDMMapCore_HDMMapVersion_h
#define HDMMapCore_HDMMapVersion_h

#include <stdint.h>

#ifdef __cplusplus
#define HDM_MAP_VERSION_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define HDM_MAP_VERSION_EXTERN extern __attribute__((visibility ("default")))
#endif

#define HDM_MAP_MAKE_VERSION_NUMBER(MAJOR, MINOR, PATCH, BUILD) \
(                                                               \
    ((uint64_t)(MAJOR) << 48) |                                 \
    ((uint64_t)(MINOR) << 32) |                                 \
    ((uint64_t)(PATCH) << 16) |                                 \
    ((uint64_t)(BUILD) << 0)                                    \
)

/* See http://semver.org/ for reference */

#define HDM_MAP_VERSION         "2.0.1"
#define HDM_MAP_VERSION_NUMBER  HDM_MAP_MAKE_VERSION_NUMBER(2, 0, 1, 0)

/** HDMMapCore version number as const char*/
HDM_MAP_VERSION_EXTERN const char kHDMMapVersion[];
/** HDMMapCore version number as uint64_t*/
HDM_MAP_VERSION_EXTERN const uint64_t kHDMMapVersionNumber;

/** HDMMapCore version number as const char*/
HDM_MAP_VERSION_EXTERN const char* HDMMapGetVersion();
/** HDMMapCore version number as uint64_t*/
HDM_MAP_VERSION_EXTERN uint64_t HDMMapGetVersionNumber();

#endif
