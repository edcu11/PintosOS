#include <stdio.h>
#include <syscall.h>
#include <stdlib.h>


int
main (int argc, char *argv[])
{
    printf("soy %s, con %d", argv[1], argc);
    int philosopherId = atoi(argv[1]);
    int palillos[10];
    int lock = 0;
    int NUM_PHILOSOPHERS = 5;
    
    for(int x = 1; x < atoi(argv[2]); x++)
    {
        palillos[x] = x;
    }

    while (1)
    {
        esys_semWait(lock);
        esys_semWait(palillos[philosopherId]);
        printf("%d Got first fork %d  .....................", philosopherId, philosopherId);
        esys_semWait(palillos[(philosopherId + 1) % NUM_PHILOSOPHERS]);
        printf("|||.................%d Got second fork %d ", philosopherId, philosopherId + 1);
        printf("Philosopher %d: eating ", philosopherId);
        esys_semPost(palillos[philosopherId]);
        esys_semPost(palillos[(philosopherId + 1) % NUM_PHILOSOPHERS]);
        esys_semPost(lock);
    }
    return 0;

}
