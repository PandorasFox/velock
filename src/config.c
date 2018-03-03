#include "config.h"
#include <stdlib.h>
#include <string.h> // memset
#include <argp.h>

/*
 * reads and parses the config at this path.
 */
config_t* readconf(char* path) {
	return NULL;
}

static void set_defaults(config_t* conf) {
	memset(conf, 0, sizeof(*conf));
	conf->args.command = NO_COMMAND;
	conf->args.config_path = NULL;
	conf->args.arg_count = 1;
	conf->pidfile_path = NULL;
}

static struct argp_option opts[] = {

	{"config",	'c',	"CONFIG_PATH",	0,		"Path to a config file to read in" },
	{0,		0,	0, 		OPTION_DOC,	"Command Args:", 5},
	{"command",	0,	"COMMAND",	0,		"Command to run"},
	{0,		0,	0,		OPTION_DOC,	"Available commands are: start, stop, restart, lock, reload"},
	
	{0}
};

const char *argp_program_version = VERSION;

static const char* commands[] = {
	[STOP]		= "stop",
	[START]		= "start",
	[RESTART]	= "restart",
	[LOCK]		= "lock",
	[RELOAD]	= "reload",
	[NO_COMMAND]	= NULL
};

static command_t get_command(const char* arg) {
	const char** i = NULL;
	for (i = commands; *i != NULL; ++i) {
		if (strcmp(arg, *i) == 0) {
			break;
		}
	}
	return (i - commands);
}

static error_t parse_opt(int key, char* arg, struct argp_state *state) {
	args_t* args = (args_t*) state->input;
	switch(key) {
	case 'c':
		args->config_path = arg;
		break;
	case ARGP_KEY_ARG:
		if (--(args->arg_count) < 0) {
			argp_failure(state, 1, 0, "too many arguments given");
		}
		
		args->command = get_command(arg);
		if (args->command == NO_COMMAND) {
			argp_failure(state, 1, 0, "invalid command given");
		}
	case ARGP_KEY_END:
		if (args->command == NO_COMMAND)
			argp_failure(state, 1, 0, "no command given");
		break;
	default:
		break;
	}
	return 0;
}

/*
 * parse the command-line arguments and returns the path to the config file
 * given by the arguments
 * parses that config file, sets it up to defaults, and then also sticks the command into the config
 */
config_t* argparse(int argc, char** argv) {
	config_t* conf = (config_t*) malloc(sizeof(config_t));
	set_defaults(conf);
	struct argp argp = {opts, parse_opt, "nut"};
	argp_parse(&argp, argc, argv, 0, 0, &(conf->args));
	

	return conf;
}

