#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int)getpid());
    int output_fd;
    ssize_t ret_out;
    char buffer[40];
    int rc = fork();
    char filename[] = "test.txt";

    if (rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        printf("hello, I am a child(pid:%d)\n", (int)getpid());
        output_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        if (output_fd == -1)
        {
            perror("open in child");
            return 2;
        }
        strcpy(buffer, "child write\n");
        ret_out = write(output_fd, &buffer, (ssize_t)strlen(buffer));
    }
    else
    {
        // wait(NULL);
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int)getpid());
        output_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        if (output_fd == -1)
        {
            perror("open in parent");
            return 3;
        }
        strcpy(buffer, "parent write\n");
        ret_out = write(output_fd, &buffer, (ssize_t)strlen(buffer));
    }

    close(output_fd);
    return 0;
}
