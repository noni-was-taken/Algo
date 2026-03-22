#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>


void bubblesort(int[] , int);
void combsort(int[] , int);

int main(){
    int arr[] = {999, 777, 666, 67, 67, 42, 101};
    int nums = 7;

    for(int i = 0; i < nums; i++){
        printf("%d ", arr[i]);
    }

    // bubblesort(arr, nums);

    combsort(arr, nums);

    printf("\n");

    for(int i = 0; i < nums; i++){
        printf("%d ", arr[i]);
    }
}

void bubblesort(int arr[], int size){
    for(int i = 0; i < size; i++){
        bool isSorted = true;
        for(int j = 0; j < size - 1 - i; j++){
            
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                isSorted = false;
            }
        }
        if(isSorted){
            break;
        }
    }
}

void combsort(int arr[], int size){
    int gap = size; 
    bool swapped = true;

    while(gap > 1 || swapped){
        gap = floor(gap/1.3);
        if(gap < 1) gap = 1;

        swapped = false;
        for(int j = 0; j+gap <= size; j++){
            if(j+gap < size && arr[j] > arr[j+gap]){
                //swap
                int temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;

                swapped = true;
            }
        }
    }
}

