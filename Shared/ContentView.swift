//
//  ContentView.swift
//  Shared
//
//  Created by Spotlight Deveaux on 2022-05-06.
//

import liblaunchd
import SwiftUI

struct ContentView: View {
    @State private var services: [ServiceDetails] = Launchd.list()

    var body: some View {
        // TODO: handle refreshing
        NavigationView {
            List(services) { service in
                NavigationLink(destination: ServiceDetailView(details: service)) {
                    // TODO: properly obtain app icon
                    Image(systemName: "questionmark.app.fill")
                    Text(service.serviceName)
                }
            }
            .navigationTitle("Services")
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
