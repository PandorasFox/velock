#include "daemon.h"

void daemonize(config_t* conf) {

}

/*
 * stops running daemon (if it exists), then kicks up a new daemon
 */
void restart(config_t* conf) {
	stop(conf); //ignores if no process exists; will still exit if it fails to stop a process
	start(conf);
}

/*
 * stops the running daemon, if one exists
 */
void stop(config_t* conf) {

}

/*
 * starts a daemon, if one is not currently running
 */
void start(config_t* conf) {
	// do checks first
	daemonize(conf);
}

