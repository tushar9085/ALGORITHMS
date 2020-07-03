#include<iostream>
#include<string.h>
#define SIZE 9

using namespace std;

void mergeFunction(int A[SIZE],int lb,int mid,int ub){

    int n1,n2;
    n1 = mid + 1;
    n2 = ub - mid;

    int L[n1],R[n2];

    for(int i = 0;i<n1;i++){
        L[i] = A[i];
    }

    for(int i = 0;i<n2;i++){
        R[i] = A[mid + 1 + i];
    }

    for(int i = 0;i<n1;i++){
         cout<<L[i]<<"  ";
    }
    cout<<endl;

    for(int i = 0;i<n2;i++){
         cout<<R[i]<<"  ";
    }
    cout<<endl;

}

void mergeSort(int A[SIZE],int lb, int ub){

    int mid;

    if(lb < ub){
        mid = (lb + ub)/2;
        mergeSort(A,lb,mid);
        mergeSort(A,mid+1,ub);
        mergeFunction(A,lb,mid,ub);

    }

}


int main(){

    int arr[] = {15, 5, 24, 8, 1, 3, 16, 10, 20};

    mergeSort(arr,0,8);

return 0;
}
