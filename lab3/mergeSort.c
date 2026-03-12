#include "mySort.h"
#include "metrics.h"

static void merge(int data[], unsigned int first, unsigned int mid, unsigned int last)
{
    unsigned int i = first;
    unsigned int j = mid + 1;
    unsigned int k = 0;

    int temp[last - first + 1];

    // merge the two sorted halves into temp[]
    while (i <= mid && j <= last) {
        if (myCompare(data[i], data[j]) <= 0) {
            myCopy(&data[i], &temp[k]);
            i++;
        } else {
            myCopy(&data[j], &temp[k]);
            j++;
        }
        k++;
    }

    // copy remaining elements from left half
    while (i <= mid) {
        myCopy(&data[i], &temp[k]);
        i++;
        k++;
    }

    // copy remaining elements from right half
    while (j <= last) {
        myCopy(&data[j], &temp[k]);
        j++;
        k++;
    }

    // copy temp back into data[first..last]
    for (i = 0; i < k; i++) {
        myCopy(&temp[i], &data[first + i]);
    }
}

void mySort(int data[], unsigned int first, unsigned int last)
{
    if (first >= last) {
        return;
    }

    unsigned int mid = (first + last) / 2;

    mySort(data, first, mid);
    mySort(data, mid + 1, last);
    merge(data, first, mid, last);
}
