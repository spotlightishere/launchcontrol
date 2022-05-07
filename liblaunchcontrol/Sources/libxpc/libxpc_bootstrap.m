//
//  libxpc_bootstrap.c
//  libxpc
//
//  Created by Spotlight Deveaux on 2022-05-07.
//

#include <libxpc.h>

/// Returns global data initialized by XPC.
struct xpc_global_data *get_xpc_global_data() {
  return (struct xpc_global_data *)_os_alloc_once_table[1].ptr;
}

/// Returns the bootstrap pipe for this process.
xpc_object_t get_process_bootstrap_pipe() {
  return get_xpc_global_data()->xpc_bootstrap_pipe;
}

/// Returns the bootstrap pipe for this process.
mach_port_t get_process_task_port() {
  return get_xpc_global_data()->task_bootstrap_port;
}
