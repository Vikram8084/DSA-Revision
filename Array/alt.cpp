#include<iostream>
#include<utility>
using namespace std;
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
}
void swapAlternate(int arr[], int n){
    for(int i=0; i<n;i+2){
        if(i+1<n){
            swap(arr[i],arr[i+1]);
        }

    }
}
int main(){
    int even[6]={2,4,5,6,10,7};
    swapAlternate(even,6);
    printArray(even,6);
    return 0;
}