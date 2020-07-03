
#include<iostream>
#include<string.h>
#define SIZE 9

using namespace std;

void mergeFunction(int A[SIZE],int lb,int mid,int ub){

    int n1,n2;
    n1 = mid -lb + 1;
    n2 = ub - mid;

    int L[n1],R[n2];

    for(int i = 0;i<n1;i++){
        L[i] = A[i + lb];
    }

    for(int i = 0;i<n2;i++){
        R[i] = A[mid + 1 + i];
    }

    int i,j,k;
    i = 0;
    j = 0;
    k = lb;

    while (i < n1 and j < n2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
            k++;
        }
        else{
            A[k] = R[j];
            j++;
            k++;
        }
    }

    while(j< n2){
        A[k] = R[j];
        k++;
        j++;
    }

    while(i< n1){
        A[k] = L[i];
        k++;
        i++;
    }

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

    mergeSort(arr,0,SIZE - 1);

    for(int i = 0;i<SIZE;i++){
        cout<<arr[i]<<"   ";
    }


return 0;
}
