<h3>spdloghack</h3>

This is a demo of a modified version of spdlog, https://github.com/gabime/spdlog which I've appropriated for my own evil purposes. Actually I just wanted to print log files without using the macro token SPDLOG_DEBUG or SPDLOG_INFO and the like. Along the way, I found my hack also allowed conventional use of individual loggers, since the macro token used the default logger. In addition, I wanted to use syntax similar to what I've been used to in Java, logger.info("my log message here") . So that's kind of where the real hack came in, meaning the only place I touched spdlog code. I changed the variable names used in spdlog.h and logger.h so that trace, debug, info, warn, error, and critical were free to use in my own macros. 

One more thing included is a python script that calls the a.out C/C++ program. If you use Eclipse CDT and have pydev also installed, you can run your C/++ program from the python wrapper, and the log console output will link to the source code line.

You can see the changes I made to spdlog.h and logger.h by checking the history of the files. Also, if referring to the docs in the original spdlog project, you'll need to substitute the names I modified if they refer to a function called by logger. All the changed names simply have an underscore prepended, so logptr->debug("hello logger") becomes logptr->_debug("hello logger"). But all the changes are simple and can be further modified, the headers returned to their original state in fact if you change the names used in main.h.

All the code in include/spdlog is from https://github.com/gabime/spdlog except for aforementioned small changes to spdlog.h and logger.h

The resulting syntax of this setup is very Java log4j like. For any source file, you would just need to do the following:
1) Include the header that contains the macros and getLog() function (in this example, main.h)
2) Get the logger
    
     static spdlog::logger logger = getLog();
  
And you are good to go.

    logger.info("hello log");

