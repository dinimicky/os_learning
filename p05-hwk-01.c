#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid());
    int share=0;
    int rc = fork();
    if(rc < 0 ) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I a child(pid:%d)\n", (int) getpid());
        printf("increas share %d in child \n", ++share);

    } else {

        // wait(NULL);
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
        printf("increse share %d in parent \n ", ++share);
    }
    return 0;
}
