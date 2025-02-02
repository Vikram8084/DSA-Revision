#include<iostream>
#include<utility>
using namespace std;
void reverseArray(int arr[],int n){
    int start =0;
    int end =n-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

}
void printArray(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
int arr[]={1,3,6,8,9,10};
int n=6;
cout<<"The array before reversing: ";
printArray(arr,6);
cout<<"The array after reversing: ";
reverseArray(arr,6);
printArray(arr,6);
}