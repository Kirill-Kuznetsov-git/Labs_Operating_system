#include <stdio.h>
  
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
void bubbleSort(int arr[], int arr_len)
{
   int i, j;
   for (i = 0; i < arr_len-1; i++)      
       for (j = 0; j < arr_len-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
  
void printArray(int arr[], int arr_size)
{
    int i;
    for (i=0; i < arr_size; i++)
        printf("%d\n", arr[i]);
}

int main()
{
    int array[8] = {7, 4, 9, 2, 23, 2, 9, 12};
    int size_arr = sizeof(array)/sizeof(array[0]);
    printf("Initial array:\n");
    printArray(array, size_arr);
    bubbleSort(array, size_arr);
    printf("Array after bubble sort:\n");
    printArray(array, size_arr);
    return 0;
}
