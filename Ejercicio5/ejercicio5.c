/***
Universidad del Valle de Guatemala
Sara Zavala 18893
SO
****/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 50
#define READ_END 0
#define WRITE_END 1
#define NAME "/SO"

int main (int argc, char *argv[]) {
	const int SIZE = 4096;
	
	int value = 0;
	int namedfd;
	int fin = -1;
	char * myfifo = "/tmp/myfifo";
	int shm_fd;
	char *ptr;
	int n;
	n = atoi(argv[1]);
	char x[sizeof(argv[2])];
	strcpy(x, argv[2]);

	
	printf("I am %c\n", x[0]);
	mkfifo(myfifo, 0666);
	shm_fd = shm_open(NAME, O_RDWR, 0);

	if (shm_fd == -1){

		shm_fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);
		printf("%c: Create new shared mem obj %d\n", x[0], shm_fd);
		ftruncate(shm_fd, SIZE);
		namedfd = open(myfifo, O_WRONLY);
		write(namedfd, &fin, sizeof(fin));
		close(namedfd);
		printf("%c: Initialized shared mem obj\n", x[0]);
	}else {
		printf("%c: Share mem obj already created\n", x[0]);
		namedfd = open(myfifo, O_RDONLY);
		read(namedfd, &value, sizeof(value));
		close(namedfd);
		printf("%c: Received shm fd: %d\n", x[0], value);
		ftruncate(shm_fd, SIZE);
	}
	
	pid_t pid;
	int protection = PROT_READ | PROT_WRITE;
	int visibility = MAP_SHARED;
	ptr = mmap(0, SIZE, protection, visibility, shm_fd, 0);

	printf("%c: ptr creado con el valor: %p\n", x[0], ptr);
	
	char write_msg[BUFFER_SIZE];
	char read_msg[BUFFER_SIZE];
	sprintf(write_msg, "%s", x);
	int fd[2];
	pipe(fd);
	
 	pid = fork();

	if (pid > 0 ) {
	 	
	 	for (int i=0; i<SIZE; i++){

	 		if (i%n == 0){

				close(fd[READ_END]);
	 			write(fd[WRITE_END], write_msg, strlen(write_msg)+1);
			 	close(fd[WRITE_END]);
	 		}
	 	}


		wait(NULL);
	 	printf("%c: La memoria compartida tiene: %s\n", x[0], (char *)ptr);
	 	if (value == 0) {
	 		
			shm_unlink(NAME);	
	 	}
	}else {
		
		if (value < 0) {
	 		ptr += 26;
	 	}	
		int s = 0;
		while(s < SIZE/n +1){
			close(fd[WRITE_END]);
		 	read(fd[READ_END], read_msg, BUFFER_SIZE);
			close(fd[READ_END]);
			
				sprintf(ptr, "%s", (char *)read_msg);
			 	ptr += strlen(read_msg);
	 		
			s = s+ 1;
		}
	}
	
	return (0);
	
}