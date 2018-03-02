#include <stdlib.h>
#include "config.h"
#include "daemon.h"

int main(int argc, char** argv) {
	// need to parse argv and get config path
	config_t* conf = argparse(argc, argv);
	switch(conf->command) {
	STOP:
		stop(conf);
		break;
	START:
		start(conf);
		break;
	RESTART:
		stop(conf);
		start(conf);
		break;
	default:
		break;
	}
	return 0;
}
