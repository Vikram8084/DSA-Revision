//sort a stack

#include<iostream>
#include<Stack>
using namespace std;

void insertSorted(stack<int> &st, int element){
    //base case
    if(st.empty() ||element> st.top()){
        st.push(element);
        return;

   }
   // 1 case mai sambhalunga
    int temp =st.top();
    st.pop();

    //recursion sambhalega
    insertSorted(st,element);
    //backtracking

    st.push(temp);
}

void sortstack(stack<int>&st){
    //base case
    if(st.empty()){
        return;
    }

    //1 case ami sambhalunga
    int temp =st.top();
    st.pop();

    //recursion
    sortstack(st);

    //backtraking

    insertSorted(st,temp);
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);

//    insertSorted(st,25);
//         while(!st.empty()){
//             cout<<st.top()<<" ";
//             st.pop();
//         }
st.push(25);
st.push(100);

sortstack(st);
while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}


    return 0;
}