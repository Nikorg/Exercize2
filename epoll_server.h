#ifndef EPOLL_SERVER_H
#define EPOLL_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_EVENTS 10
#define MAX_BUF    1024

void set_nonblocking(int fd);
void *work_with_client(void *arg);


#endif
