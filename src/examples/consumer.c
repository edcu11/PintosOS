#include <stdio.h>
#include <syscall.h>

int
main (int argc, char *argv[])
{
    printf("soy %s, con %d", argv[0], argc);
    printf("Soy: %s \n", argv[1]);
    esys_semPost(0);
    esys_semPost(2);
    esys_semPost(0);
    printf("Ended waiting from consumer\n" );
    return 0;

}
