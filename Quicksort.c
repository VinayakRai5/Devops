#include <stdio.h>
void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int partition(int A[], int low, int high){
    int pivot=A[low];
    int i=low+1;
    int j=high;
    do{ //do while loop is put because these operations have to be done atleast once.
    while(A[i]<=pivot){

        i++; //to find the first largest element from right
    }
    while(A[j]>pivot){
        j--; //to find the first smallest element from left
    }
    if(i<j){ 
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    }while(i<j);

    //swapping pivot with A[j];
    int temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
}
void quickSort(int A[], int low, int high){
    int partitionIndex;//index of pivot after partition
    if(low<high){ //continues till there are atleast 2 elements in the subarray
    partitionIndex=partition(A, low, high);
    quickSort(A, low, partitionIndex-1); //sort left subarray
    quickSort(A, partitionIndex+1, high); //sort right subarray
    }
}
int main(){
    printf("Enter the number of elements of the array: ");
    int n;
    scanf("%d",&n);
    int A[50];
    printf("Enter the elements of the array: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("The array is: \n");
    printarray(A,n);
    printf("The sorted array is: \n");
    quickSort(A, 0, n-1);
    printarray(A,n);
return 0;
}