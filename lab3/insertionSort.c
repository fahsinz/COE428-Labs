#include "mySort.h"
#include "metrics.h"

void mySort(int data[], unsigned int first, unsigned int last)
{
    unsigned int i, j;
    int key;

    if (first >= last) {
        return;
    }

    // the outer loop examines each element on the right-hand side of the array 
    // from the 2nd element on to the end of the array
    for (i = first + 1; i <= last; i++) {

        // setting key = data[i]
        myCopy(&data[i], &key);

        // looking at the element before i to compare
        j = i;

        // while (j > first && key < data[j - 1])
        while (j > first && myCompare(key, data[j - 1]) < 0) {

            // data[j] = data[j - 1]
            myCopy(&data[j - 1], &data[j]);
            j--;
        }

        // data[j] = key
        myCopy(&key, &data[j]);
    }
}
