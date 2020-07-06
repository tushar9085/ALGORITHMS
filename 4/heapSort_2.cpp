#include<iostream>
#define SIZE 9

using namespace std;

void swapNumber(int A[SIZE],int index1,int index2){

    int temp;

    temp = A[index1];
    A[index1] = A[index2];
    A[index2] = temp;

}

//Here You Can find the Heapify process also

void createMaxHeap(int A[SIZE],int n){   //n is the size(Actual index) up to which we want to create a heap

    int root,child,r;
    bool right;

    n = n-1;

    if(n%2  == 0){
        root = n/2 - 1;
        right = true;
    }

    else{
        root = n/2;
    }


    while(root >=0){

        r = root;   //Virtual Root

        if(right){
            if(A[2*r + 1] >= A[2*r + 2])
                child = 2*r + 1;
            else
                child = 2*r + 2;
        }
        else
            child = 2*r + 1;


        while(child<=n){

            if(A[child]>A[r]){
                swapNumber(A,r,child);

                r = child;    //root goes downward and check with child to create max heap

                if(2*r + 1<=n && 2*r + 2<=n){   //Checking existence of child

                    if(A[2*r + 1] >= A[2*r + 2])
                        child = 2*r + 1;
                    else
                        child = 2*r + 2;

                }
                else if(2*r + 1<=n && 2*r + 2 > n)
                    child = 2*r + 1;

                else
                    break;
            }
            else
                break;

        }

        root--;
        right = true;
    }

}

void heapSort(int A[SIZE]){

    int i;
    int heap_size = SIZE;

    for(i = 0;i <SIZE ; i++){
        swapNumber(A,0,heap_size-1);

        heap_size--;

        createMaxHeap(A,heap_size);

    }

    if(A[0]>A[1]){
        swapNumber(A,0,1);
    }
    cout<<endl;

}

int main(){

    int arr[SIZE] = {15, 2, 24, 8, 1, 3, 16, 10, 20};
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
    cout<<endl;

    cout<<"After Sort:"<<endl;

    heapSort(arr);

    for(i = 0;i < SIZE; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    return 0;
}

