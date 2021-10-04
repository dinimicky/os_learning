#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    int rc = fork();

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        close(STDOUT_FILENO);
        open("./p05-hwk-07.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        printf("hello, I am a child(pid:%d)\n", (int)getpid());
        printf("hello from child\n");
    }
    else
    {
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
        printf("goodbye from parent\n");
    }

    return 0;
}
