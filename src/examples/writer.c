#include <stdio.h>
#include <syscall.h>


int
main (int argc, char *argv[])
{
    printf("soy %s, con %s", argv[0], argv[1] );

    int semRw = 0;
    

    while(1)
    {
        esys_semWait(semRw);
        printf("wrote: %s\n", argv[1]);
        esys_semPost(semRw);
        //usleep(5000);
    }
    return 0;

}