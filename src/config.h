#ifndef CONFIG_H
#define CONFIG_H

typedef enum command {
	STOP,
	START,
	RESTART,
	LOCK,
	RELOAD
} command_t;

typedef struct config {
	int someDaemonOption;
	char* pidfile_path;
	char* config_path;
	command_t command;
} config_t;

/*
 * reads and parses the config at this path.
 */
config_t* readconf(char* path);

/*
 * parse the command-line arguments and returns the path to the config file
 * given by the arguments
 * parses that config file, sets it up to defaults, and then also sticks the command into the config
 */
config_t* argparse(int argc, char** argv); 

#endif
