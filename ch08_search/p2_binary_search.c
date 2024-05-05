/**
* Part2: 折半查找
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int array[] = {5,13,19,21,37,56,64,75,80,88,92};
    int length = 11;
    int key = 88;

    int low = 0;
    int high = length-1;
    int mid;
    while (low<=high) {
        mid = (low+high)/2;
        if(array[mid]==key) {
            printf("index:%d",mid);
            break;
        }
        else if (array[mid]>key) high = mid-1;
        else low = mid+1;
    }

}