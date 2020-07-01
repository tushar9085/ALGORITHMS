#include<iostream>

using namespace std;

#define ROW 11
#define COL 11

int globalMax_MidColumn(int arr[ROW][COL],int mid){

    int colArr[ROW];
    for(int i=0;i<ROW;i++){
        colArr[i] = arr[i][mid];
    }

    int maxNum = colArr[0];
    int max_mid_pos;
    for(int i=0;i<ROW;i++){
        if(colArr[i]>maxNum){
            max_mid_pos = i;
            maxNum = colArr[i];
        }
    }
    return max_mid_pos;

}

int main(){

    int arr[ROW][COL] = {{4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2},
                         {5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
                         {6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4},
                         {7, 8, 9, 10, 11, 10, 9, 8, 7, 6, 5},
                         {8, 9, 10, 11, 12, 11, 10, 9, 8, 7, 6},
                         {7, 8, 9, 10, 11, 10, 9, 8, 7, 6, 5},
                         {6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4},
                         {5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3},
                         {4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2},
                         {3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1},
                         {2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 0}};


    int UB,LB,mid,max_mid_pos;

    LB = 0;
    UB = COL - 1;

    mid = (UB -LB)/2;


    while(LB != UB){

        max_mid_pos = globalMax_MidColumn(arr,mid);

        if(arr[max_mid_pos][mid] >= arr[max_mid_pos][mid-1] && arr[max_mid_pos][mid] >= arr[max_mid_pos][mid+1]){
            cout<<arr[max_mid_pos][mid];
            break;
        }

        if(arr[max_mid_pos][mid]<=arr[max_mid_pos][mid-1]){
            UB = mid -1;
            mid = (UB -LB)/2;
            cout<<"left"<<endl;

        }

        if(arr[max_mid_pos][mid]<=arr[max_mid_pos][mid+1]){
            LB = (mid +1);
            mid = (UB -LB)/2 + LB;
            cout<<"right"<<endl;
        }

    }

    if(UB == LB){
        int pos = globalMax_MidColumn(arr,LB);

        cout<<arr[pos][LB]<<endl;
    }

return 0;
}
