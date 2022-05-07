//
//  ServiceDetailView.swift
//  Shared
//
//  Created by Spotlight Deveaux on 2022-05-07.
//

import liblaunchd
import SwiftUI

struct ServiceDetailView: View {
    let details: ServiceDetails

    var body: some View {
        VStack {
            Text("Service name: \(details.serviceName)")
            Text("Status: \(details.status)")
            Text("PID: \(details.pid)")
        }
    }
}

struct ServiceDetailView_Previews: PreviewProvider {
    static var previews: some View {
        ServiceDetailView(details: ServiceDetails("space.joscomputing.mock-service", 621, 0))
    }
}
