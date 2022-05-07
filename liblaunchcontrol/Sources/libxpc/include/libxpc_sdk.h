//
//  libxpc_sdk.h
//  libxpc
//
//  Created by Spotlight Deveaux on 2022-05-02.
//

#ifndef libxpc_sdk_h
#define libxpc_sdk_h

@import Foundation;

#if TARGET_OS_OSX
// On macOS, we use the SDK-provided version.
#import <xpc/xpc.h>
#else
// On iOS/watchOS/tvOS/[...], we must bring our own SDK header.
// Here we go...

NS_ASSUME_NONNULL_BEGIN

// Truly an NSObject<OS_xpc_object>, but this definition will do.
/// A basic XPC object.
typedef NSObject *xpc_object_t;

#pragma mark - XPC dictionary functions
/// Creates an empty XPC dictionary.
xpc_object_t xpc_dictionary_create_empty(void);

/// Creates a new dictionary for the given keys, values, and count.
xpc_object_t
xpc_dictionary_create(const char *_Nonnull const *_Nullable keys,
                      const xpc_object_t _Nullable *_Nullable values,
                      size_t count);

/// Retrieves the uint64 for the given key.
uint64_t xpc_dictionary_get_uint64(xpc_object_t dictionary, const char *key);

/// Sets the given key to be the passed uint64.
void xpc_dictionary_set_uint64(xpc_object_t dictionary, const char *key,
                               uint64_t value);

/// Retrieves the boolean value for the given key.
bool xpc_dictionary_get_bool(xpc_object_t dictionary, const char *key);

/// Sets the given key to be the passed boolean value.
void xpc_dictionary_set_bool(xpc_object_t dictionary, const char *key,
                             bool value);

/// Retrieves the int64 for the given key.
int64_t xpc_dictionary_get_int64(xpc_object_t dictionary, const char *key);

/// Sets the given key to be the passed int64.
void xpc_dictionary_set_int64(xpc_object_t dictionary, const char *key,
                              int64_t value);

/// Retrieves the dictionary for the given key.
xpc_object_t _Nullable xpc_dictionary_get_dictionary(xpc_object_t xdict,
                                                     const char *key);

/// A block permitting iteration through an XPC dictionary.
/// Return true within the block to continue iterating.
typedef bool (^xpc_dictionary_applier_t)(const char *_Nonnull key,
                                         xpc_object_t _Nonnull value);

/// Invokes the passed block for every key/value pair within the dictionary.
void xpc_dictionary_apply(xpc_object_t xdict, xpc_dictionary_applier_t applier);

#pragma mark - XPC type functions
/// A type to describe an object's type.
typedef const struct _xpc_type_s *xpc_type_t;

/// Returns the type for the given object.
xpc_type_t xpc_get_type(xpc_object_t object);

/// Returns an object type's name.
const char *xpc_type_get_name(xpc_type_t type);

#pragma mark - XPC types
extern const struct _xpc_type_s _xpc_type_array;
extern const struct _xpc_type_s _xpc_type_bool;
extern const struct _xpc_type_s _xpc_type_connection;
extern const struct _xpc_type_s _xpc_type_dictionary;
extern const struct _xpc_type_s _xpc_type_endpoint;
extern const struct _xpc_type_s _xpc_type_error;
extern const struct _xpc_type_s _xpc_type_string;

#define XPC_TYPE_ARRAY (&_xpc_type_array)
#define XPC_TYPE_BOOL (&_xpc_type_bool)
#define XPC_TYPE_CONNECTION (&_xpc_type_connection)
#define XPC_TYPE_DICTIONARY (&_xpc_type_dictionary)
#define XPC_TYPE_ENDPOINT (&_xpc_type_endpoint)
#define XPC_TYPE_ERROR (&_xpc_type_error)
#define XPC_TYPE_STRING (&_xpc_type_string)

NS_ASSUME_NONNULL_END

#endif /* TARGET_OS_OSX */
#endif /* libxpc_sdk_h */
