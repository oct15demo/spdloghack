#include "main.h"

static spdlog::logger logger = getLog();

void foo(){
	logger.debug("this log.debug from foo");
}

int main(int argc, char** argv){
	logger.debug("this is log.debug");
	foo();
	foofromfile();
}
