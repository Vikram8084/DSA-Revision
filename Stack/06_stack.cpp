#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st, int &element){
    //base case
    if (st.empty())
    {
        st.push(element);
        return;
    }
    //1 case mai solve karunga
    int temp= st.top();
    st.pop();

    //baki recursion sambhalega
    insertAtBottom(st,element);

    //backtracking'

    st.push(temp);
    
}

void reverseStack(stack<int>&st){
    //base case 
    if(st.empty()){
        return;
    }

    //1 case mai solve karunga
    int temp =st.top();
    st.pop();

    //recursion
    reverseStack(st);

    //backtrackiing
    insertAtBottom(st,temp);
}    
int main(){
    return 0;
}