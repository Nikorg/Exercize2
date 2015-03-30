all: epoll thread run

epoll:
	gcc -c epoll_server.c

thread:
	gcc -c thread_work.c

run:
	gcc epoll_server.o thread_work.o -pthread -o epoll_server

clean:
	rm -rf *.o epoll_server
