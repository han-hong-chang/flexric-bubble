#ifndef PROXY_AGENT_CONF_H
#define PROXY_AGENT_CONF_H

// Configuration for proxy agent 
#include <libwebsockets.h>

#include "util/conf_file.h"
#include "util/alg_ds/alg/defer.h"
#include "ws_io_ran.h"

typedef struct
 {
    uint16_t             retry_count;  /* WS: count of consecutive retries for connecting to the RAN (UNUSED)*/
    struct io_ran_conf_t io_ran_conf;  // RAN I/O module conf
    fr_args_t            e2args;       /* E2: cmdline args*/
} proxy_conf_t;

/* 
 * Extract configuration for WS interface (RAN ipaddress/port, log levels) and for E2 interface 
 * (flexric conf file and SM libs directory). It is affected by the environment variables WS_RAN_HOST and WS_LOGL 
 * for RAN ipaddress/port and loglevels respectively.
 * Priority is given in the following order:
 * - commandline arguments for E2 interface
 * - environment variables for WS interface
 * - defaults for WS interface are ip/port=localhost/9001, loglevel = user | warn | notice | err.
 * - defaults for E2 interface are specified in src/util/conf_file.c:init_fr_args()
 * Note that there is no concept of logging system on E2 interface for the moment; everything is printed on stdout
 * 
 * RETURNS: false if problem found with a configuration item, otherwise true
 */
proxy_conf_t ws_initconf(int argc, char *argv[]);

void ws_initconf_print_help(void);

void ws_conf_print(proxy_conf_t * c);
#endif