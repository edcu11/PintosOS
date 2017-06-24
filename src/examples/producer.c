#include <stdio.h>
#include <syscall.h>


int
main (int argc, char *argv[])
{
    printf("soy %s, con id: %s y argc= %d \n", argv[0], argv[1], argc);
    int mutex = 0;
    int full = 1;
    int empty = 2;

    while(1)
  {
    esys_semWait(empty);
  //  esys_semWait(mutex);
    printf("Productor %s, ha producido! \n", argv[1] );
  //  esys_semPost(mutex);
    esys_semPost(full);
  }

    return 0;

}
