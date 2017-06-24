#include <stdio.h>
#include <syscall.h>


int
main (int argc, char *argv[])
{
    printf("soy %s, con %d", argv[1], argc);
    int lock = esys_semInit(4);
    
    for(int x = 1; x < 5; x++)
    {
        esys_semInit(1);
    }

    int id[5];
    id[0] = exec("philosopher 0 5");
    id[1] = exec("philosopher 1 5");
    id[2] = exec("philosopher 2 5");
    id[3] = exec("philosopher 3 5");

    wait(id[0]);
    wait(id[1]);
    wait(id[2]);
    wait(id[3]);
    
    
    

    return 0;

}