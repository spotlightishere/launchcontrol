//
//  LaunchdList.swift
//  liblaunchd
//
//  Created by Spotlight Deveaux on 2022-05-07.
//

import Foundation
import libxpc

/// ServiceDetails represents the state of services while listing.
public struct ServiceDetails: Identifiable {
    public let id = UUID()
    public let serviceName: String
    public let pid: Int64
    public let status: Int64

    public init(_ serviceName: String, _ pid: Int64, _ status: Int64) {
        self.serviceName = serviceName
        self.pid = pid
        self.status = status
    }
}

public extension Launchd {
    /// Lists running services.
    /// - Returns: An array of services running.
    static func list() -> [ServiceDetails] {
        let response = LaunchdRequest(type: .list).dispatch()
        // Ensure we were given services.
        let services = xpc_dictionary_get_dictionary(response, "services")
        guard let services = services else {
            print("Something has gone horribly awry.")
            return []
        }

        // Iterate through services to create a list.
        var serviceList: [ServiceDetails] = []
        xpc_dictionary_apply(services) { name, metadata in
            let name = String(cString: name)
            let pid = xpc_dictionary_get_int64(metadata, "pid")
            let status = xpc_dictionary_get_int64(metadata, "status")

            serviceList.append(ServiceDetails(name, pid, status))
            return true
        }
        return serviceList
    }
}
