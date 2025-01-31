#include<iostream>
using namespace std;
void countZeroOne(int arr[], int size){
    int zerocount=0;
    int onecount=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0){
            zerocount++;
        }
        if(arr[i] ==1){
            onecount++;
        }
    }
    cout<<"Zero count :"<<zerocount<<endl;
    cout<<"One count :"<<onecount<<endl;
}
int main(){
    int arr[]={1,1,0,0,0,1,1,1,0,0,1,1};
    int size=12;
    countZeroOne(arr,size);
    return 0;
}