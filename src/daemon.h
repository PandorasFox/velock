#ifndef DAEMON_H
#define DAEMON_H
#include "config.h"

/*
 *  Does the double fork magic and uses the pidfile/etc given by the config
 *  exits with exit() and an error code if it cannot daemonize.
 */
void daemonize(config_t* conf);
void start(config_t* conf);
void stop(config_t* conf);
void restart(config_t* conf);

#endif
