#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void selectionsort(int[], int);
void countingsort(int[], int);
void countingsortv2(int[], int);


int main(){
    int arr[] = {999, 777, 666, 67, 67, 42, 101};
    int nums = 7;

    for(int i = 0; i < nums; i++){
        printf("%d ", arr[i]);
    }

    // selectionsort(arr, nums);

    // countingsort(arr, nums);

    countingsortv2(arr, nums);

    printf("\n");

    for(int i = 0; i < nums; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void selectionsort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int lowest = arr[i];
        int lowestIndex = i;
        
        for(int j = i + 1; j < size; j++){  
            if(arr[j] < lowest){
                lowest = arr[j];
                lowestIndex = j;
            }
        }

        if(lowestIndex != i){
            int temp = arr[i];
            arr[i] = arr[lowestIndex];
            arr[lowestIndex] = temp;
        }
    }
}

//without getting a specific range;
void countingsort(int arr[], int size){
    
    if(size == 0){
        printf("We can't sort an array with size 0 lil bro");
        return;
    }
    //determine maxmimum value
    int largest = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] > largest) largest = arr[i];
    }

    //make the array for the counting sort
    int dictSize = largest + 1;
    int *dict = calloc(dictSize, sizeof(int));
    if(dict == NULL){
        exit(1);
    }

    //add 1 for every occurrence of a word in the dictionary
    for(int i = 0; i < size; i++){
        dict[arr[i]] += 1;
    }
    //add them sequentially
    for(int i = 0; i < dictSize - 1; i++){        
        dict[i+1] += dict[i];       
    }

    //insert them to the temp array
    int *temp = malloc(sizeof(int)*size);
    if(temp == NULL){
        exit(1);
    }
    for(int i = size-1; i >= 0; i--){
        dict[arr[i]] -= 1;
        temp[dict[arr[i]]] = arr[i]; 
    }

    //bring them back to the normal array
    for(int i = 0; i < size; i++){
        arr[i] = temp[i];
    }

    free(dict);
    free(temp);
}

void countingsortv2(int arr[], int size){
    if(size == 0){
        printf("You can't expect me to sort an array with size 0 bro.");
        return;
    }
    
    //determine the range
    int lowest = arr[0], highest = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] > highest) highest = arr[i];
        if(arr[i] < lowest) lowest = arr[i];
    }

    //make dict with range
    int dictSize = highest - lowest + 1;
    int *dict = calloc(dictSize, sizeof(int));

    //add 1 for every occurrence of the word
    for(int i = 0; i < size; i++){
        dict[arr[i] - lowest] += 1;
    }

    //sum sequentially
    for(int i = 0; i < dictSize-1; i++){
        dict[i+1] += dict[i];
    }

    //add to temp
    int *temp = malloc(sizeof(int)*size);
    for(int i = size-1; i >= 0; i--){
        dict[(arr[i] - lowest)] -= 1;
        temp[dict[(arr[i]-lowest)]] = arr[i];
    }

    //put back inside yo mama
    for(int i = 0; i < size; i++){
        arr[i] = temp[i];
    }

    free(temp);
    free(dict);
}
