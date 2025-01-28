#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node*next;
        Node(){
            //default constructor
            this->next=NULL;

        }
        Node(int data){
            //parametrized constructor
            this->data= data;
            this->next =NULL;

        }
        ~Node(){
            cout<<"Destructor is called for : "<< this->data<<endl;

        }

};

void print(Node*head){
    Node* temp =head;//imp
    while(temp !=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node*head){
    Node*temp=head;
    int count=0;
    while(temp !=NULL){
        count++;
        temp =temp->next;
    }
    return count;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    //if empty LL
    if (head == NULL)
    {
       //step1: create a new Node
       Node* newNode=new Node(data);
       //step2: update head 
       head =newNode;
       tail =newNode;

    }
    else{
        //create a new node
        Node* newNode =new Node(data);
        //attach the new node to a head node
        newNode ->next= head;
        //update head
        head =newNode;

    }
    
    
}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(head ==NULL){
        //empty LL
        //step1:create to karo node
        Node* newNode=new Node(data);
        //step2: single node hai ll me that's why
        //head and tail ko ispar point karwa do
        head=newNode;
        tail =newNode;

    }
    else{
        //non empty LL
        //step1: create a new node
        Node* newNode =new Node(data);
        //step2:tail node ko attach karo newNode se
         tail->next=newNode;
         //step3: update tail
         tail =newNode;



    }
}

void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    if(position <1){
        cout<<"we canot insert "<<endl;
        return;
    }
    int len =getLength(head);
    if(position ==1){
        insertAtHead(head,tail,data);
    }
    else if(position > len){
        cout<<"Cannot insert ,please enter a valid position"<<endl;
    }

    if(position ==len +1){
        insertAtTail(head,tail,data);
    }

    else{
        //insert at middle of the linked list 

        //step1: create a new node
        Node* newNode =new Node(data);
        //step2: traverse the prev // curr to the position
        Node* prev =NULL;
        Node* curr =head;
        while(position != 1){
            prev =curr;
            curr=curr->next;
            position--;
        }
        //step3: attach prev to newNode
        prev->next= newNode;
        //step4:attach newNode to curr
        newNode->next =curr;

    }

}

void deleteNode(Node* &head,Node* &tail,int position){
    //empty linked list
    if(head == NULL){
        cout<<"Cannot delete because Linked List is empty "<<endl;
        return;
    }
    // if LL has single element
    if(head == tail){
        Node* temp =head;
        delete temp;
        head= NULL;
        tail= NULL;
        return;

    }
    int len=getLength(head);

    //deletion from head
    if(position == 1){
        //first node ko delte kar do 
        Node*temp =head;
        head =head->next;
        temp->next=NULL;
        delete temp;

    }

    else if(position == len){
        // last node ko delete karna hai

        //find prev
        Node* prev=head;
        while(prev->next !=tail){
            prev=prev->next;
        }

        //prev node ka link null karo
        prev ->next =NULL;

        //node ko delte karo

        delete tail;
        //update tail

        tail=prev;
    }

    else {
        //middle node ko delete karo

        //step1:set prev/curr pointers
        Node*prev=NULL;
        Node*curr =head;
        while(position != 1){
            position--;
            prev=curr;
            curr=curr->next;

        }

        //step2: prev->next me curr ka next node add karo
        prev->next =curr->next;
        //step3: node isolate kar do
        curr->next=NULL;

        //step4: delete Node
        delete curr;

    }

}


int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail,30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

   
    print(head);
    cout<<endl;

    // deleteNode(head,tail,1);
    // printLL(head);
    
    // deleteNode(head,tail,5);
    // printLL(head);
    // cout<<endl;

    deleteNode(head,tail,3);
    print(head);
    cout<<endl;


    return 0;
}