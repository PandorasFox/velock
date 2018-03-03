#include <stdlib.h>
#include "config.h"
#include "daemon.h"

int main(int argc, char** argv) {
	// need to parse argv and get config path
	config_t* conf = argparse(argc, argv);
	switch(conf->args.command) {
	case STOP:
		stop(conf);
		break;
	case START:
		start(conf);
		break;
	case RESTART:
		stop(conf);
		start(conf);
		break;
	default:
		break;
	}
	free(conf);
	return 0;
}
