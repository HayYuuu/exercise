#include "mysocket.h"

mysock::mysock() {};
mysock::~mysock() {};

mysock::mysock(sa_family_t domain = AF_INET,int type = SOCK_STREAM,int protocol = IPPROTO_TCP, const char *ip = "0.0.0.0",short port = 80) {
	inet_pton(domain, ip, &(mysocket.sin_addr.s_addr));
	mysocket.sin_port = htons(port);
	mysocket.sin_family = domain;
	mysocket_fd = socket(domain, type, protocol);
}

int mysock::bind_socket() {
	return bind(mysocket_fd, (const struct sockaddr *)(&mysocket), sizeof(mysocket));
}

int mytcpserver::listen_socket(int backlog) {
	max_con = backlog >= SOMAXCONN ? SOMAXCONN : backlog;
	fd_list = new int[max_con];
	return listen(mysocket_fd, max_con);
}

int mytcpserver::accept_socket() {
	int newfd = accept(mysocket_fd, NULL, NULL);
	if (newfd == -1) {
		return -1;
	}
	for (int i = 0;i < max_con;i++) {
		if (fd_list[i] == 0) {
			fd_list[i] = newfd;
			break;
		}
	}
	return 0;
}

int mytcpserver::getconnections() {
	for (int i = 0;i < max_con;i++) {
		if (fd_list[i] > 0) {
			fd_list[i] = -fd_list[i];
			return -fd_list[i];
		}
	}
	return -1;
}

void mysock::getinfo() {
};

mytcpserver::mytcpserver(const char* ip, short port):mysock(AF_INET, SOCK_STREAM, IPPROTO_TCP, ip, port)
{

}

