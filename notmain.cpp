#include "main.h"

static spdlog::logger logger = getLog();

void foofromfile(){
   logger.debug("this log.debug from foofromfile");
}
