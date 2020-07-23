#pragma once
#ifndef MY_SOCKET
#define MY_SOCKET

#include <sys/socket.h>
#include <arpa/inet.h>
#include <vector>
#include <netinet/in.h>

using namespace std;

class mysock
{
public:
	//my socket fd
	int mysocket_fd;
	//sockaddr_in to hold IP:port
	struct sockaddr_in mysocket;

	//record and store IP:port
	mysock();
	mysock(sa_family_t domain, int type, int protocol, const char* ip, short port);
	~mysock();
	//bind
	int bind_socket();
	//get socket info
	void getinfo();
	void close();
};

class mytcpserver: public mysock
{
public:
	//connections list
	int* fd_list;
	//connection limits
	int max_con;

	mytcpserver(const char* ip, short port);
	//listen
	int listen_socket(int backlog);
	//accept
	int accept_socket();
	//give a connection
	int getconnections();
};

class mytcpclient :public mysock
{
public:
	int connect();
	int receive_data();
	int send_data();
};




#endif // !MY_TCP