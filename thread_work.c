#include <unistd.h>
#include "epoll_server.h"

/*Recieve message from client and answer to it*/
void *work_with_client(void *arg)
{
	int byte_count, resp_size;
	char request[MAX_BUF], buf[MAX_BUF], response[MAX_BUF];
	pid_t pid;

	int client = *((int*)arg);

	/*Get pid of thread*/
	pid = getpid();

	/*Read request*/
	byte_count = recv(client, buf, sizeof buf, 0);
	if (byte_count == -1) {
		perror("recv error");
		exit(EXIT_FAILURE);
	}
	memcpy(request, buf, byte_count);
	puts(request);

	if(strstr(request, " /Hello ")>0)
		resp_size = sprintf(response,"Hello %d!", pid);
	else 
		resp_size = sprintf(response,"Print \"/Hello\" in browser url");

	/*Send answer to client*/
	if (send(client, response, resp_size, 0) == -1) {
		perror("send error");
		exit(EXIT_FAILURE);
	}

	/*Done with this client - close its fd*/
	close(client);
	
}
