#include <stdio.h>
#include <syscall.h>


int
main (int argc, char *argv[])
{
    printf("soy %s, con %s", argv[0], argv[1]);
    int semRw = 0;
    int mutex = 1;

  
   while(1){
    esys_semWait(mutex);
    esys_Reader(1);
    if(esys_Reader(0) == 1)
      esys_semWait(semRw);
    esys_semPost(mutex);
    printf("Reader %s got \n", argv[1]);
    esys_semWait(mutex);
    esys_Reader(2);
    if(esys_Reader(0) == 0)
      esys_semPost(semRw);
    esys_semPost(mutex);
  }


    return 0;

}