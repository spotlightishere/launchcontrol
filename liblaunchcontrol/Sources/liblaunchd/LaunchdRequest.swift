//
//  LaunchdRequest.swift
//  liblaunchd
//
//  Created by Spotlight Deveaux on 2022-05-07.
//

import Foundation
import libxpc

public class LaunchdRequest {
    let request: xpc_object_t
    let bootstrap = get_process_bootstrap_pipe()

    /// Fabricates an XPC dictionary for the given type, initializing keys to launchctl defaults.
    /// - Parameter type: The type to fabricate for.
    public init(type: LaunchdTypes) {
        request = xpc_dictionary_create_empty()
        // launchctl sets these values prior to dispatch.
        // TODO: type is not always 7, handle appropriately
        xpc_dictionary_set_uint64(request, "type", 7)
        xpc_dictionary_set_uint64(request, "handle", 0)
        xpc_dictionary_set_uint64(request, "subsystem", 3)
        xpc_dictionary_set_uint64(request, "routine", type.rawValue)
    }

    /// Dispatches this request to launchd.
    /// - Returns: Result from launchd.
    public func dispatch() -> xpc_object_t {
        var reply: xpc_object_t?

        // TODO: REMOVE
        print("Request:")
        print(request)
        // TODO: REMOVE

        let result = _xpc_pipe_interface_routine(bootstrap, 0, request, &reply)

        // TODO: properly handle if result is 0
        if result != 0 {
            print("Something bad occurred... (result \(result))")
            return xpc_dictionary_create_empty()
        }

        // TODO: properly handle error if nil
        guard let reply = reply else {
            print("All has gone awry.")
            return xpc_dictionary_create_empty()
        }

        // TODO: properly read message from key
        if xpc_object_is_error(reply) {
            print("Reply contains an error:")
            print(reply)
            let test = xpc_dictionary_get_int64(reply, "error")
            print(String(cString: xpc_strerror(test)))
            return xpc_dictionary_create_empty()
        }

        // TODO: REMOVE
        print("Reply:")
        print(reply)
        // TODO: REMOVE
        return reply
    }
}
