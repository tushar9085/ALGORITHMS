#include<stdio.h>
#define SIZE 100

void bin_ser(int arr[SIZE],int arr_size,int number){

    int UB,LB,mid;

    UB = arr_size -1;
    LB = 0;
    mid = (UB - LB)/2;

    while(UB != LB){

        if(arr[mid] == number){
            printf("number is in %d\n",mid+1);
        }

        if(number <= arr[mid]){
            UB = mid - 1;
            mid = (UB - LB)/2;
        }

        else if(number >= arr[mid]){
            LB = mid + 1;
            mid = (UB - LB)/2 + LB;
        }

    }

}


void main(){

    int n,arr[SIZE] = {0,1,2,3,4,5,6,7,8,9},i;



    n= 10;


    bin_ser(arr,n,9);

}
