#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node*prev;
        Node*next;

        Node(){
            this->prev =NULL;
            this->next =NULL;

        }
        Node(int data){
            this->data = data;
            this->prev =NULL;
            this->next =NULL;

        }
};

void print(Node*head){
    Node* temp =head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp =temp->next;
    }
    cout<<endl;
}

int findLength(Node*head){
    Node* temp= head;
    int len=0;
    while(temp != NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    //if Linked list is empty 
    if(head == NULL){
        Node*newNode=new Node(data);
        head =newNode;
        tail= newNode;
    }
    else{
        //Linked list is not empty
        Node* newNode=new Node(data);
        newNode->next =head;
        newNode->prev =newNode;
        head =newNode;
    }
}

void insertAtTail(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node*newNode =new Node(data);
        head =newNode;
        tail =newNode;
    }

    else{
        //Linked list is not empty
        Node*newNode=new Node(data);
        tail->next=newNode;
        newNode->prev =tail;
        tail =newNode;
    }
}

void insertAtposition(Node* &head,Node* &tail,int data, int position){
    if(head == NULL){
        Node* newNode= new Node(data);
        head =newNode;
        tail =newNode;
    }
    else{
        int len =findLength(head);
        if(position == 1){
            insertAtHead(head,tail,data);
        }
        else if(position ==len +1){
            insertAtTail(head,tail,data);

        }

        else{
            //insert at middle 
            //step1:create a node
            Node*newNode =new Node(data);
            //step2: set prev and curr
            Node* prevNode=NULL;
            Node* currNode=head;
            while(position != 1){
                position--;
                prevNode =currNode;
                currNode =currNode->next;
            }
            //step3: pointers update karre the

            prevNode->next =newNode;
            newNode->prev =prevNode;
            newNode->next =currNode;
            currNode->prev =newNode;
        }
    }
    
 }

void deleteNode(Node* &head,Node* &tail,int position){
    if(head ==NULL){
        //LL is empty
        cout<<"Cannot delete , coz LL is empty" <<endl;
        return;
    }

    if(head == NULL){
        Node* temp=head;
        delete temp;
        head= NULL;
        tail =NULL;
    }
    int len =findLength(head);
    if(position == 1){
        // delete from head
        Node* temp =head;
        head =head->next;
        temp->next =NULL;
        head->prev =NULL;
        delete temp;
    }

    else if(position == len){
        //delete from tail
        Node* prevNode=tail->prev;
        prevNode->next =NULL;
        tail->prev =NULL;
        delete tail;
        tail =prevNode;

    }
    else {
        //delete from middle
        //step1: set prevNode/currNode/nextNode
        Node*prevNode =NULL;
        Node* currNode =head;
        while(position != 1){
            position--;
            prevNode =currNode;
            currNode=currNode->next;

        }
        Node* nextNode =currNode ->next;

        prevNode->next =nextNode;
        currNode->prev =NULL;
        currNode->next =NULL;
        nextNode->prev =prevNode;

        delete currNode;

    }
}


int main(){
     Node* head = NULL;
    Node* tail=NULL;
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,10);
    print(head);
    cout<<endl;

    //insertAtTail(head,tail,100);
    //insertAtPosition(head,tail,100,3);
    //print(head);
    deleteNode(head,tail,1);
    print(head);

    cout<<endl;
    deleteNode(head,tail,2);
    print(head);

    cout<<endl;

    deleteNode(head,tail,2);
    print(head);

    cout<<endl;

    deleteNode(head,tail,1);
    print(head);
    cout<<"length of LL is: "<< findLength(head)<<endl;

    deleteNode(head,tail,1);
    print(head);






return 0;
}