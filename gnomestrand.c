#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define empty -99999


void gnomesort(int[], int);
void strandsort(int[], int);
void merge(int*, int*, int , int*);
int main()
{
    int arr[] = {999, 777, 666, 67, 67, 42, 101};
    int nums = 7;

    for (int i = 0; i < nums; i++)
    {
        printf("%d ", arr[i]);
    }

    // gnomesort(arr, nums);

    strandsort(arr, nums);

    printf("\n");

    for (int i = 0; i < nums; i++)
    {
        printf("%d ", arr[i]);
    }
}

void gnomesort(int arr[], int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; (swapped) ? i-- : i++)
    {
        swapped = false;
        if (i >= 0 && arr[i] > arr[i + 1])
        {
            // swap
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            swapped = true;
        }
    }
}

void strandsort(int arr[], int size){
    if (size <= 1){
        return;
    }

    int *strand = malloc(sizeof(int) * size);
    int *sortedArr = malloc(sizeof(int) * size);
    bool *used = calloc(size, sizeof(bool));
    int sortedCount = 0;

    if (strand == NULL || sortedArr == NULL || used == NULL){
        free(strand);
        free(sortedArr);
        free(used);
        return;
    }

    int remaining = size;
    while (remaining > 0){
        int strandCount = 0;
        int last = 0;
        bool hasLast = false;

        for (int i = 0; i < size; i++){
            if (used[i]){
                continue;
            }

            if (!hasLast || arr[i] >= last){
                strand[strandCount++] = arr[i];
                last = arr[i];
                hasLast = true;
                used[i] = true;
                remaining--;
            }
        }

        merge(strand, sortedArr, strandCount, &sortedCount);
    }

    for (int i = 0; i < size; i++){
        arr[i] = sortedArr[i];
    }

    free(strand);
    free(sortedArr);
    free(used);
}

void merge(int *temp, int *arr, int tempCount, int *arrCount){
    int mergeSize = tempCount + *arrCount;
    int *merged = malloc(sizeof(int) * mergeSize);
    int mergecount = 0;
    int i = 0;
    int j = 0;

    if (merged == NULL){
        return;
    }

    while (i < tempCount && j < *arrCount){
        if (temp[i] <= arr[j]){
            merged[mergecount++] = temp[i++];
        } else {
            merged[mergecount++] = arr[j++];
        }
    }

    while (i < tempCount){
        merged[mergecount++] = temp[i++];
    }

    while (j < *arrCount){
        merged[mergecount++] = arr[j++];
    }

    for (int k = 0; k < mergecount; k++){
        arr[k] = merged[k];
    }
    *arrCount = mergecount;

    free(merged);
}
