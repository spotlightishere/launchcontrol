//
//  libxpc_bootstrap.h
//  libxpc
//
//  Created by Spotlight Deveaux on 2022-05-07.
//

#ifndef libxpc_bootstrap_h
#define libxpc_bootstrap_h

@import Foundation;

NS_ASSUME_NONNULL_BEGIN

// XPC pipe obtaining courtesy of
// http://newosxbook.com/articles/jlaunchctl.html
// (thank you!)
struct xpc_global_data {
  uint64_t a;
  uint64_t xpc_flags;
  mach_port_t task_bootstrap_port; /* 0x10 */
#ifndef _64
  uint32_t padding;
#endif
  xpc_object_t xpc_bootstrap_pipe; /* 0x18 */
  // and there's more, but you'll have to wait for MOXiI 2 for those...
  // ...
};

// os_alloc_once_table:
//
// Ripped this from XNU's libsystem
#define OS_ALLOC_ONCE_KEY_MAX 100

struct _os_alloc_once_s {
  long once;
  void *ptr;
};
extern struct _os_alloc_once_s _os_alloc_once_table[];

// Our own helper functions.
struct xpc_global_data *get_xpc_global_data();
xpc_object_t get_process_bootstrap_pipe();
mach_port_t get_process_task_port();

NS_ASSUME_NONNULL_END

#endif /* libxpc_bootstrap_h */
