#pragma once
#ifndef MY_MSG_H
#define MY_MSG_H

#include <sys/types.h>
#include <sys/msg.h>

struct mymesg {
	long types;
	char mtext[1024];
};

class msg
{
private:
	int msqid;
	struct mymesg mesgbuf;

public:
	msg(int key);
	int get();
	int ctl(int cmd, struct msqid_ds* buf);
	int snd(int flag);
	ssize_t rcv(long type, int flag);
};

#endif // !MY_MSG_H

