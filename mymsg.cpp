#ifndef MSG_MY
#define MSG_MY

#include "mymsg.h"

msg::msg(int key) {
	msqid = key;
}

int msg::get() {
	return msgget(msqid, IPC_CREAT);
}

int msg::ctl(int cmd, struct msqid_ds *buf){
	return msgctl(msqid, cmd, buf);
}

int msg::snd(int flag) {
	return msgsnd(msqid, &mesgbuf, 1024, flag);
}

ssize_t msg::rcv(long type, int flag) {
	mesgbuf.types = type;
	return msgrcv(msqid, &mesgbuf, 1024, type, flag);
}


#endif // !MSG_MY




