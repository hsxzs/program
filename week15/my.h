#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include<pthread.h>
#include "err_exit.h"
#define check_error(return_val,msg){ \
	if(return_val != 0){\
		fprintf(stderr,"%s:%s\n",msg,strerror(return_val));\
		exit(-1);\
	}\
}
