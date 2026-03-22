#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>


void insertion(int[] , int);
void shellsort(int[] , int);

int main(){
    int arr[] = {999, 777, 666, 67, 67, 42, 101};
    int nums = 7;

    for(int i = 0; i < nums; i++){
        printf("%d ", arr[i]);
    }

    // insertion(arr, nums);

    shellsort(arr, nums);

    printf("\n");

    for(int i = 0; i < nums; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void insertion(int arr[], int size){
    for(int i = 1; i < size ; i++){
        int j = i;
        int temp = arr[i];
        while(j > 0 && temp < arr[j-1]){
            arr[j] = arr[j-1];
            j--;
        }   
        arr[j] = temp;
    }
}

void shellsort(int arr[], int size){
    //const gap 
    int ciuraseq[] = {1, 4, 10, 23, 57, 132, 301, 701};
    int ciuraseqCount = 8;

    int gapIndex;

    for(int i = 0; i < ciuraseqCount && ciuraseq[i] <= size; i++){
        gapIndex = i;
    }

    while(gapIndex >= 0){
        int gap = ciuraseq[gapIndex];
        for(int i = gap; i < size; i++){
            int temp = arr[i];
            int j;
            for(j = i; j >= gap && arr[j-gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gapIndex--;
    }


}

