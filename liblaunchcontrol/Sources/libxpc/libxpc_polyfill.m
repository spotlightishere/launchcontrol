//
//  libxpc_polyfill.m
//  libxpc
//
//  Created by Spotlight Deveaux on 2022-05-07.
//

// As Swift does not appear to be fond of exposing
//
//   extern const struct _xpc_type_s _xpc_type_array;
//   #define XPC_TYPE_ARRAY (&_xpc_type_array)
//
// we must write our own helper functions in order to use types.
#import "libxpc_polyfill.h"

/// Returns whether this object is an array.
/// @param object The object to compare with.
bool xpc_object_is_array(xpc_object_t object) {
  return xpc_get_type(object) == XPC_TYPE_ARRAY;
}

/// Returns whether this object is a boolean type.
/// @param object The object to compare with.
bool xpc_object_is_bool(xpc_object_t object) {
  return xpc_get_type(object) == XPC_TYPE_BOOL;
}

/// Returns whether this object is a connection type.
/// @param object The object to compare with.
bool xpc_object_is_connection(xpc_object_t object) {
  return xpc_get_type(object) == XPC_TYPE_CONNECTION;
}

/// Returns whether this object is a dictionary.
/// @param object The object to compare with.
bool xpc_object_is_dictionary(xpc_object_t object) {
  return xpc_get_type(object) == XPC_TYPE_DICTIONARY;
}

/// Returns whether this object is an endpoint.
/// @param object The object to compare with.
bool xpc_object_is_endpoint(xpc_object_t object) {
  return xpc_get_type(object) == XPC_TYPE_ENDPOINT;
}

/// Returns whether this object is an error.
/// @param object The object to compare with.
bool xpc_object_is_error(xpc_object_t object) {
  // Sometimes, we get an error type directly.
  if (xpc_get_type(object) == XPC_TYPE_ERROR) {
    return true;
  }

  // Other times, we need to ensure the existence of the 'error' key.
  if (xpc_dictionary_get_int64(object, "error") == 0) {
    return false;
  } else {
    return true;
  }
}

/// Returns whether this object is a string.
/// @param object The object to compare with.
bool xpc_object_is_string(xpc_object_t object) {
  return xpc_get_type(object) == XPC_TYPE_STRING;
}
