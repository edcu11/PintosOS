#include <stdio.h>
#include <syscall.h>

int
main (int argc, char *argv[])
{
    printf("soy %s, con %d", argv[0], argc);
    int semaphore1 = esys_semInit(0);

   /* char * params = "";
    char * consumer = "consumer ";
    printf("Semaforo devolvio: %d", semaphore1);
    
    sprintf(params, "%d", semaphore1);

    strcat(consumer, params);
*/
    int id = exec("consumer 2");


    printf("Waiting in main %d", esys_semWait(semaphore1) );
    printf("not waiting anymore at main\n" );

    wait(id);

}
