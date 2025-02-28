#include<iostream>
using namespace std;

//function for binary search

int binarySearch(int arr[],int n, int target){
    int left =0;
    int right =n-1;

    while(left <= right){
        //here we can calculate mid index of the array
        int mid =left+(right -left)/2;

        //if target is mid element then
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            //then we have to search in right half
            left =mid + 1;

        }
        else{
            //search in the left half of the array
            right =mid - 1;
        }



    }
    //if target not found return -1;
    return -1;
}

//here we can write the main function of the code

int main(){
    int arr[] ={1,3,4,5,7,9,11,30,50};
    int n =sizeof(arr)/sizeof(arr[0]);
    int target =11;
    int result =binarySearch(arr,n,target);

    if(result != -1){
        cout<<"Element "<<target<< " found at index: "<<result<<endl;

    }

    else
        cout<<"Element not found"<<endl;

    return 0;
}