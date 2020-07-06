
#include<iostream>
#define SIZE 9

using namespace std;


// INSTERTION ACTUALLY

void createMaxHeap(int A[SIZE], int n){

    int B[n],i,root,temp,child;

    for(i = 0;i<n;i++){

        B[i] = A[i];

        if(i%2 == 0)
            root = i/2 - 1;
        else
            root = i/2;

        child = i;


        while(B[child]>B[root] && root >=0){
            temp = B[child];
            B[child] = B[root];
            B[root] = temp;

            child = root;
            if(child%2 == 0)
                root = child/2 - 1;
            else
                root = child/2;

        }

    }


    for(i = 0;i<n;i++){
            A[i] = B[i];
        }


}

void heapSort(int A[SIZE]){

    int temp,i;
    int heap_size = SIZE;

    for(i = 0;i <SIZE ; i++){
        temp = A[0];
        A[0] = A[heap_size - 1];
        A[heap_size - 1] = temp;

        heap_size--;

        createMaxHeap(A,heap_size);

    }
    cout<<endl;

}
int main(){

    int arr[SIZE] = {15, 0, 24, 8, 1, 3, 16, 10, 20};
    int i;

    cout<<"Before MaxHeap Creation:"<<endl;

    for(i = 0;i < SIZE; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    createMaxHeap(arr,SIZE);

    cout<<"After MaxHeap Creation:"<<endl;

    for(i = 0;i < SIZE; i++){
        cout<<arr[i]<<"\t";
    }

    heapSort(arr);
    cout<<endl;
    for(i = 0;i < SIZE; i++){
        cout<<arr[i]<<"\t";
    }


    return 0;
}
