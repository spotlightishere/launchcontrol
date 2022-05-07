//
//  libxpc.h
//  libxpc
//
//  Created by Spotlight Deveaux on 2022-05-02.
//

#ifndef libxpc_h
#define libxpc_h

#import <TargetConditionals.h>

// While macOS has a complete set of XPC headers, iOS and similar do not.
// We optionally provide our own SDK headers.
#import <libxpc_sdk.h>

// Private XPC functions.
// Some of these are quite useful.
#import <libxpc_private.h>

// Polyfills to support multiple platforms.
#import <libxpc_polyfill.h>

// Used to obtain the bootstrap pipe for launchd.
#import <libxpc_bootstrap.h>

#endif /* libxpc_h */
