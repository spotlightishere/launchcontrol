# launchcontrol
A `launchd` GUI with a similar goal to `launchctl`, or... something. Also inclues `libxpc` and `liblaunchd` to allow for easier access.

## Usage
Open, and enjoy. Hardly any functionality comparable to `launchctl` is implemented.

## Resources
 - `/sbin/launchd`
 - `/bin/launchctl`
 - `/usr/lib/system/libxpc.dylib`
 - [launchd source from OS X 10.9](https://github.com/apple-oss-distributions/launchd) - while now outdated, some of the design remains.
 - [GitHub Search](https://cs.github.com) - if you're lucky
 - Frantically [Googling](https://google.com) and learning you're the first to encounter this error
 - [The Five Stages of Grief](https://en.wikipedia.org/wiki/Five_stages_of_grief)
 - [Hopper](https://hopperapp.com)
 - [Ghidra](https://ghidra-sre.org)

## Caveats
 - The macOS Sandbox had to be disabled for this application in order to interface with `launchd`.
 - Does not function on iOS/watchOS/tvOS without the `platform-application` entitlement. How you manage that is trivial/beyond the scope of this paper/other academic excuses for not actually knowing.
 - This relies heavily on private XPC functionality. It is highly possible that, come next major OS release, this interface will change.

## Contributing
Thank you for wanting to contribute! This source is by no means wonderful.

Please follow these loose guidelines:
 - Run [clang-format](https://clang.llvm.org/docs/ClangFormat.html) on all C/Objective-C source.
 - Run [swiftformat](https://github.com/nicklockwood/SwiftFormat) on all Swift source. We target Swift 5.6.

## License
Released under the MIT license.
