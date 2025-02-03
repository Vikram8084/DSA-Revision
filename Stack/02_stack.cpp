#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;
  public:
    Stack(int size){
        arr =new int[size];
        this->size =size;
        this->top =-1;
    }
    void push(int data){
        if(top == size-1){
            cout<<"overflow"<<endl;
        }
        else{

        top++;
        arr[top]= data;
        }
        
    }

    void pop(){
        if(top == -1){
            cout<<"Stack is underflow"<<endl;
        }
        else{

        top--;
        }
    }

        bool isempty(){
            if(top == -1){
                return true;
            }
            else{
              return false;
        }
        }

    
    int getTop(){
        return arr[top];
    }

    int getSize(){
        return top+1;
      }
      void print(){
        cout<<"Top: "<<top<<endl;
        cout<<"Top element: "<<getTop()<<endl;
        cout<<"stack:";
        for(int i=0;i<getSize();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl<<endl;
      }
    
};

int main(){
    //creation
    Stack st(8);

    //push 
    st.push(10);
    st.print();

    st.push(20);
    st.print();

    // st.push(30);
    // st.print();

    // st.pop();
    // st.print();

    // st.pop();
    // st.print();

    // st.pop();
    // st.print();

    cout<<"Top element :"<<st.getTop()<<endl;
    cout<<"Size of the stack:"<<st.getSize()<<endl;
    

    return 0;
}