#include <stdlib.h>

typedef struct config {
	int someDaemonOption;
	char* pidfile_path;
	char* config_path;
} config_t;


config_t* active_conf;

/*
 * this'll be moved to another file later when implemented, but is just here so that the skeleton compiles for now
 */
static void run() {

}

/*
 * reads and parses the config at this path.
 */
static config_t* readconf(char* path) {
	return NULL;
}

/*
 * parse the command-line arguments and returns the path to the config file
 * given by the arguments
 * parses that config file, sets it up to defaults, and then also sticks the command into the config
 */
static config_t* argparse(int argc, char** argv) {
	return NULL;
}



/*
 *  Does the double fork magic and uses the pidfile/etc given by the config
 *  exits with exit() and an error code if it cannot daemonize.
 */
static void daemonize(config_t* override_conf) {
	config_t* conf = active_conf;
	if (override_conf != NULL)
		conf = override_conf;
}

/*
 * stops the running daemon, if one exists
 */
static void stop(int restart) {

}

/*
 * starts a daemon, if one is not currently running
 */
static void start() {
	// do checks first
	daemonize(NULL);
	run();
}

/*
 * stops running daemon (if it exists), then kicks up a new daemon
 */
static void restart() {
	stop(1); //ignores if no process exists; will still exit if it fails to stop a process
	start();
}

int main(int argc, char** argv) {
	// need to parse argv and get config path
	config_t* conf = argparse(argc, argv);
	return 0;
}
