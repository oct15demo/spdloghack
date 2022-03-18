#include "main.h"
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_sinks.h"

int main(int argc, char** argv){
	std::shared_ptr<spdlog::logger> console = spdlog::stdout_logger_mt("console");
	console->set_pattern("%l %H:%M:%S:%e | %! | %v | %s:%#");
	console->set_level(spdlog::level::trace);
	spdlog::logger log=*console;
	log.debug("this is log.debug");
}
