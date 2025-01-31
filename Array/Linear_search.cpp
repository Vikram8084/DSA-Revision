#include<iostream>
using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool linearSearch(int arr[], int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}
int main(){
    int arr[5]={2,3,4,8,10};
    int size=5;
    printArray(arr,size);
    int target=8;
    bool ans=linearSearch(arr,size,target);
    if(ans==true){
        cout<<"target found";
    
    }
    else{
    cout<<"target not found";
}
    return 0;
}