//implement 2 stack in a sinlge array
#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
        int *arr;
        int size;
        int top1;
        int top2;
        Stack(int size){
            arr=new int[size];
            this->size=size;
            top1=-1;
            top2=size;

        // Initialize array elements to 0 to avoid garbage values
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }

       }

       void push1(int data){
        if(top2 - top1 ==1){
            //no space available
            cout<<"overflow"<<endl;
        }
        else{

        top1++;
        arr[top1] = data;
        }


       }

       void push2(int data){
        if(top2 -top1 ==1){
            cout<<"overflow"<<endl;
        }
        else{

        

        top2--;
        arr[top2] =data;
        }

       }

       void pop1(){
        if(top1==-1){
            //stack1 is empty
            cout<<"underflow"<<endl;
        }
        else{
        arr[top1] = 0;
        top1--;
        }

       }

       void pop2(){
        if(top2==size){
            cout<<"underflow"<<endl;
        }
        else{

        arr[top2]=0;
        top2++;
        }

       }

       void print(){
        cout<<endl;
        cout<<"TOp1: "<<top1<<endl;
        cout<<"Top2: "<<top2<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<< " ";
        }
        cout<<endl;
       }

       
};
int main(){

    Stack st(6);
    st.print();
    st.push1(10);
    st.print();

    st.push1(20);
    st.print();

    st.push2(200);
    st.print();

    st.push2(300);
    st.print();

    st.push2(400);
    st.print();

    st.push2(500);
    st.print();

    st.push1(1000);
    st.print();

    st.pop1();
    st.print();

    st.pop1();
    st.print();

    st.pop1();
    st.print();
    
   return 0;
}