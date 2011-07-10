#ifndef NETWORK_HEADER
#define NETWORK_HEADER

#include	<sys/types.h>	// basic system data types 
#include	<sys/socket.h>	// basic socket definitions 
#include	<sys/time.h>	// timeval{} for select() 
#include	<netinet/in.h>	// sockaddr_in{} and other Internet defns 
#include	<arpa/inet.h>	// inet(3) functions
#include	<netdb.h>
#include	<sys/stat.h>	// for S_xxx file mode constants 
#include	<sys/uio.h>		// for iovec{} and readv/writev 
#include	<sys/wait.h>
#include	<sys/un.h>		// for Unix domain sockets 

#define DATABASE_PORT 7777
#define LISTENQ 13

int openSocket(void);
int serverConnect(char *ip_address);

#endif