//
//  libxpc_private.h
//  libxpc
//
//  Created by Spotlight Deveaux on 2022-05-06.
//

#ifndef libxpc_private_h
#define libxpc_private_h

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

/// Loads an XPC bundle into the process's service path.
/// @param path The path to the XPC bundle.
/// @param unknown An unknown value. Seemingly must be set to the value 2.
void xpc_add_bundle(const char *path, uint32_t unknown);

/// Adds an array of bundles to the process's service path.
/// @param process_dict A dictionary with the key "pid" set to the process's
/// PID.
/// @param paths An array of paths to add to the process's service path.
void xpc_add_bundles_for_domain(xpc_object_t process_dict, xpc_object_t paths);

/// Dispatches a request via the given pipe.
/// @param pipe The pipe to dispatch this request via.
/// @param unknown Observed to be 0.
/// @param request_dict The dictionary supplied upon request.
/// @param reply_dict The dictionary returned on response.
int _xpc_pipe_interface_routine(xpc_object_t pipe, uint32_t unknown,
                                xpc_object_t request_dict,
                                xpc_object_t _Nullable *_Nonnull reply_dict);

/// Adds a Mach port to the dictionary to use for sending.
/// @param dictionary The dictionary to modify.
/// @param name The key to add to the dictionary.
/// @param value A Mach port to use for sending.
void xpc_dictionary_set_mach_send(xpc_object_t dictionary, const char *name,
                                  mach_port_t value);

/// Adds a Mach port to the dictionary to use for receiving.
/// @param dictionary The dictionary to modify.
/// @param name The key to add to the dictionary.
/// @param value A Mach port to use for receiving.
void xpc_dictionary_set_mach_recv(xpc_object_t dictionary, const char *name,
                                  mach_port_t value);

/// Returns an error message for the given code.
/// @param error The error code to look up.
const char *xpc_strerror(int64_t error);

NS_ASSUME_NONNULL_END

#endif /* libxpc_private_h */
