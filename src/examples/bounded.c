#include <stdio.h>
#include <syscall.h>
#include <string.h>

int
main (int argc, char *argv[])
{
    printf("soy %s, con %d \n", argv[0], argc);

    //int cant = 5;

    int mutex = esys_semInit(1);
    esys_semInit(0);
    esys_semInit(3);

    //prepare params
 /*    char * consumer = "consumerB ";
    char * param = "0       ";
    snprintf(param, sizeof cant, "%d", cant);
    strlcat(consumer, param, 2);
   strlcat(consumer, " ", 1);
    snprintf(param, sizeof(mutex), (char*)mutex);
    strlcat(consumer, param, sizeof(param));
*/
    //printf("%s \n", consumer);

    int id[10];

    id[0] = exec("producer 5");
    id[4] = exec("producer 4");
    id[1] = exec("consumerB 1");
    id[2] = exec("consumerB 2");
    id[3] = exec("consumerB 3");
  
    wait(id[0]);
    wait(id[1]);
    wait(id[2]);
    wait(id[3]);
    wait(id[4]);


    return 0;

}
