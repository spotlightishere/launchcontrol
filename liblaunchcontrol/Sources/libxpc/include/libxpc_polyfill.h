//
//  libxpc_polyfill.h
//  libxpc
//
//  Created by Spotlight Deveaux on 2022-05-07.
//

#import <libxpc.h>

bool xpc_object_is_array(xpc_object_t object);
bool xpc_object_is_bool(xpc_object_t object);
bool xpc_object_is_connection(xpc_object_t object);
bool xpc_object_is_dictionary(xpc_object_t object);
bool xpc_object_is_endpoint(xpc_object_t object);
bool xpc_object_is_error(xpc_object_t object);
bool xpc_object_is_string(xpc_object_t object);
