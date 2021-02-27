/***
Universidad del Valle de Guatemala
Sara Zavala 18893
SO
****/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main (){
	pid_t f = fork();
	if (f==0) {

		execl("ipc", "ipc", "157", "a", (char*)NULL);
	} else {
		usleep(1400);
		execl("ipc", "ipc", "157", "b", (char*)NULL);
	}
}