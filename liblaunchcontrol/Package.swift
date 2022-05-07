// swift-tools-version: 5.6

import PackageDescription

let package = Package(
    name: "liblaunchcontrol",
    platforms: [
        .macOS(.v12),
        .iOS(.v15),
        .tvOS(.v15),
        .watchOS(.v8),
    ],
    products: [
        .library(
            name: "liblaunchd",
            targets: ["liblaunchd"]
        ),
        .library(
            name: "libxpc",
            targets: ["libxpc"]
        ),
    ],
    targets: [
        // The actual library utilized to interface with launchd.
        .target(
            name: "liblaunchd",
            dependencies: ["libxpc"]
        ),
        // On platforms where many XPC-related functions are unavailable,
        // this library also provides definitions to allow them to be used.
        .target(
            name: "libxpc",
            dependencies: []
        ),
    ]
)
