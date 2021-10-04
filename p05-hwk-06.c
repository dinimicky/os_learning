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
        printf("hello, I am a child(pid:%d)\n", (int)getpid());
        printf("hello from child\n");
    }
    else
    {
        pid_t wait_ret = waitpid(-1, NULL, 0);
        printf("parent wait ret value: %d\n", wait_ret);
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
        printf("goodbye from parent\n");
    }

    return 0;
}
