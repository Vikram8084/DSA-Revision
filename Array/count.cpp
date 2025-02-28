#include<iostream>
using namespace std;

int occurance(int arr[], int n,int target){
    int count =0;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            count++;
        }
        
    }
    return count;
}
int main(){
    int arr[]={1,0,1,1,1,0,0};
    int n =sizeof(arr)/sizeof(arr[0]);
    int target=1;
    cout<<"occurance of 1: "<<occurance(arr,n,target);
    return 0;
}