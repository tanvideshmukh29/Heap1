
#include <iostream>
using namespace std;
 
#define MAX 1000 
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void  buildheap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}
void heapsort(int arr[], int n)
{


    
    for (int i = n - 1; i > 0; i--) {
    
        swap(arr[0], arr[i]);
 
        
        heapify(arr, i, 0);
    }
}


void deletei(int arr[],int &n){
    
    arr[0]=arr[n];
    n=n-1;
    int i=0;
    while(i<n){
        int large=i;
        int left=arr[2*i+1];
        int right=arr[2*i+2];
        if(left>right){
            large=2*i+1;
        }
        else{
           large= 2*i+2;
        }
        if(arr[i]<arr[large]){
            swap(arr[i],arr[large]);
            i=large;
        }
        else{
            return;
        }
    }
    
    
}

void insert(int arr[],int &n ,int key)
{ 
    n = n + 1;
 
    
    arr[n - 1] = key;

    int i=n-1;
    while(i>0){
        int parent=(i-1)/2;
        if(arr[parent] <arr[i]){
            swap(arr[parent],arr[i]);
            i=parent;
        }
        else{
            return;
        }
    }
    
}
int  printArray(int arr[],int n)
{
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
 

int main()
{
    int arr[MAX] = {  10, 5, 3, 2, 4 };
 
    int n = 5;
 
    int key = 15;
    
 
    insert(arr, n, key);
     cout<<"insertion--->  ";
    printArray(arr, n);
    cout<<endl;
 
    deletei(arr,n);
    cout<<"deletetion--->  ";
    printArray(arr, n);
    cout<<endl;
    
    
  buildheap(arr,n);
  cout<<"Bulidheap--->  ";
  printArray(arr, n);
  cout<<endl;
    
    
    heapsort(arr,n);
     cout<<"HeapSort--->  ";
    printArray(arr, n);
    
   
    return 0;
}
