#include<iostream>
#include<time.h> 
using namespace std;
void merge(int arr[],  int start, int mid, int end);
void insertionSort(int arr[], int n){
    for(int j = 1; j<n; ++j){
        int key = arr[j];
        int i = j-1;
        while ((i>=0) && arr[i]>key){
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
}
}

void mergeSort(int arr[], int start, int end){
    if (start<end){
        int mid = (start+end)/2;
        mergeSort(arr, start, mid); 
        mergeSort(arr, mid+1, end); 
        merge(arr, start, mid, end);
    }
}

void merge(int arr[],  int start, int mid, int end){
    int i, j, k; 
    int n1 = mid - start + 1; 
    int n2 =  end - mid; 

    //Create temp arrays
    int L[n1], R[n2];
    for (i = 0; i<n1;i++)
        L[i] = arr[start+i];
    for (j = 0; j<n2; j++)
        R[j] = arr[mid+1+j];
    i = 0;
    j = 0; 
    k = start;
    
    while(i<n1 && j<n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
        while(i<n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = R[j];
            j++;
            k++;
        }        
}
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
} 

int partition (int arr[], int low, int high)  
{  
    srand(time(0));
    //cout<<r<<p<<"sss"<<"\n";
    int pivotidx = 0+rand() % high;
    //cout<<"idx "<<pivotidx<<"\n";
    swap(&arr[pivotidx], &arr[high]);
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
} 

void printArr(int arr[], int n){
    for (int idx = 0; idx<n; idx++){
        cout<<arr[idx]<<" ";
    }
    cout<<"\n";
}

int main(){
    /*
    int arr[] = { 12, 11, 13, 5, 6};
    int len = sizeof(arr)/sizeof(int);
    cout<<len<<"\n";
    printArr(arr,len);
    insertionSort (arr, len);
    printArr(arr, len);
    int arr2[] = { 12, 11, 13, 5, 6,7};
    int len2 = sizeof(arr2)/sizeof(int);
    //cout<<len2;
    printArr(arr2,len2);
    mergeSort(arr2, 0, len2-1);
    printArr(arr2, len2);*/
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    cout << "Sorted array: \n";  
    printArr(arr, n);  
    return 0;
}