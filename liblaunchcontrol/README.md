# liblaunchcontrol

Contains two notable packages:

### libxpc
libxpc simply provides XPC headers.

While there is a large amount public on macOS, there is very little on iOS/watchOS/tvOS.
Despite their seeming differences, libxpc is extremely similar on all platforms.

On macOS, this library exposes the SDK header.
On non-macOS platforms, this library simply defines headers in order to ensure XPC usability.

Note that on all platforms, several private XPC functions are additionally defined. 

### liblaunch
liblaunch is simple wrapper to communicate with `launchd`.


## Wishlist
 - Find a way to expose XPC types as Apple does - via `module.modulemap`, possibly?
 Swift does not appear to be fond of current `extern` and `#define`.
