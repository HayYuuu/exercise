#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <sys/epoll.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>


int main() {
	char buff[128];
	long buff_size = 0;
	std::cout << "--this is test--" << std::endl;
	sockaddr_in mysock;
	mysock.sin_family = AF_INET;
	mysock.sin_port = htons(8828);
	inet_pton(AF_INET, "172.105.236.78", &(mysock.sin_addr.s_addr));
	int my_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (bind(my_fd, (struct sockaddr*)&mysock, sizeof(mysock)) == -1) {
		std::cout << "--bind fail--" << std::endl;
		exit(-1);
	}

	if (listen(my_fd, 128)) {
		std::cout << "--listen fail--" << std::endl;
		exit(-1);
	}
	std::cout << "--listen succeed--" << std::endl;
	int cfd = accept(my_fd, NULL, NULL);

	if (cfd < 0) {
		std::cout << strerror(errno) << std::endl;
		exit(-1);
	}
	std::cout << "--accept succeed--" << std::endl;
	/*
	while (1) {
		ssize_t ret = read(cfd, buff, sizeof(buff));
		write(STDOUT_FILENO, buff, ret);
	}*/
	
	int old_option = fcntl(cfd, F_GETFL);
	fcntl(cfd, F_SETFL, old_option | O_NONBLOCK);


	int epoll_fd = epoll_create(128);
	struct epoll_event ev;
	ev.events = EPOLLIN | EPOLLET;
	ev.data.fd = cfd;
	if (epoll_ctl(epoll_fd,EPOLL_CTL_ADD,cfd,&ev) < 0) {
		std::cout << strerror(errno) << std::endl;
		exit(-1);
	}
	std::cout << "--epoll_ctl succeed--" << std::endl;
	struct epoll_event ev_read[1];
	int myfild_fd = open("/root/download_test", O_CREAT|O_RDWR|O_APPEND);

	while (1) {
		epoll_wait(epoll_fd, ev_read, 1, -1);
		std::cout << "\n--found bytes in cfd--" << std::endl;
		buff_size += read(ev_read[0].data.fd, &(buff[buff_size]), sizeof(buff)- buff_size);
		std::cout << "--buff_size = " << buff_size << "--" << std::endl;
		if(buff_size >= 40){
			std::cout << "--exec ouput--" << std::endl;
			//write(myfild_fd, buff, buff_size);
			write(STDOUT_FILENO, buff, buff_size);
			buff_size = 0;
		}
	}
	return 0;
}


