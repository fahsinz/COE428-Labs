#include <stdio.h>
#include <stdlib.h>
#include "towers.h"

//prints a usage/error message to stderr for incorrect invocation
static void usage(void)
{
    fprintf(stderr, "Usage: towers [numberDisks [fromTower destTower]]\n");
}

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;

    // case 1: no arguments
    // program name only, so use default values
    if (argc == 1) {
    //base case: n=3, from=1, dest=2
    
    }
    
    // case 2: one argument (number of disks)
    else if (argc == 2) {
        n = atoi(argv[1]);  // convert string to integer
        if (n <= 0) {      // disk count must be positive
            usage();       // print error message to stderr
            return 1;
        }
    }
    
    // case 3: three arguments (number of disks, from tower, dest tower)
    else if (argc == 4) {
        n = atoi(argv[1]);
        from = atoi(argv[2]);
        dest = atoi(argv[3]);
		
		// # of disks is positive number
        if (n <= 0) {
            usage();
            return 1;
        }
        // # of towers and  must be maximum 3 but more than 1
        if (from < 1 || from > 3 || dest < 1 || dest > 3 || from == dest) {
            usage();
            return 1;
        }
    }
    else {
        usage();
        return 1;
    }

    towers((unsigned int)n, (unsigned int)from, (unsigned int)dest);
    return 0;
}
