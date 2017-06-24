#include <stdio.h>
#include <syscall.h>


int
main (int argc, char *argv[])
{
    printf("soy %s, con %s", argv[0], argv[1]);

    esys_semInit(1);
    esys_semInit(1);
    

    int id[10];
    id[0] = exec("writer 5");
    id[4] = exec("writer 4");  
    id[1] = exec("reader 1");
    id[2] = exec("reader 2");
    id[3] = exec("reader 3");
 

    wait(id[0]);
    wait(id[1]);
    wait(id[2]);
    wait(id[3]);
    wait(id[4]);

    

    return 0;

}