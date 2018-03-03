#ifndef CONFIG_H
#define CONFIG_H

typedef enum command {
	STOP = 0,
	START,
	RESTART,
	LOCK,
	RELOAD,
	NO_COMMAND,
} command_t;

typedef struct arguments {
	command_t command;
	char* config_path;
	int arg_count;
} args_t;

typedef struct config {
	char* pidfile_path;
	struct arguments args;
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
