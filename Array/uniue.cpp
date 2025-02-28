#include<iostream>
using namespace std;

int getUnique(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        //perform xor operation to find unique
        ans=ans^arr[i];
    }
    return ans;
}
int main(){
    int arr[]={4, 7, 4, 3, 5, 5, 3};
    //unique element is 7
    int size=7;
    int finalAns= getUnique(arr,size);
    cout<<"Unique Element is :"<<finalAns<<endl;
    return 0;
}