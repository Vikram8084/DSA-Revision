#include <iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* next;

        Node(){
           // cout <<"I am inside the default constructor"<<endl;

            this->next =NULL;
        }

        Node(int data){
            //cout<<"I am inside parametrized constructor"<<endl;
            this->data = data;
            this->next =NULL;
        }

};

void printLL(Node*head){
    Node* temp = head;//imp

    while(temp != NULL){
        cout <<temp->data <<"-> " ;
        temp = temp ->next;
    }
    cout<<endl;

}

int getLength(Node*head){
    Node* temp =head;
    int count =0;
    while(temp !=NULL){
        temp=temp->next;
        count++;

    }
    return count;
}

void insertAtHead(Node* &head, Node* &tail,int data){//pass by reference yaad rakhna 
    if(head == NULL){
        //empty LL

        //step1 : create new node
        Node* newNode =new Node(data);
        //step: 2 update head
        head = newNode;
        tail = newNode;
    }
    else{
    //create a new node
    Node* newNode =new Node(data);
    //attach a new node to a head node
    newNode ->next = head;
    //update head
    head = newNode;
    // tail = newNode;
    }
}


//Insertion at Tail
void insertAtTail(Node* &head,Node* &tail, int data){
    if(head == NULL){
        //empty LL
        //step1: create toh karo node
        Node* newNode =new Node(data);
        //step2: single node hai entire list me to
        //that's why head and tail ko ispar point karwado
        head = newNode;
        tail =newNode;
    }
    else{
        //non-empty LL
        //step1: create a new node
        Node* newNode =new Node(data);
        //step2: tail node ko attach karo newNode se
        tail->next =newNode;
        //step3:update
        tail = newNode;


    }
}

void createTail(Node* &head, Node* &tail){
    Node* temp =head;
    while(temp -> next != NULL){
        tail = temp;
        temp =temp->next;
    }
    //jab ye loop khatam ho gay hoga then 
    //aapka temp wala pointer 
    //khad hoga last node par
    //tab temp = temp krke , tail ko last node par le aao
    tail =temp;

}

int main(){

    //creation of node
   // Node a;
   Node* first = new Node(10);
   Node* second = new Node(20);
   Node* third = new Node(30);
   Node* fourth = new Node(40);
   Node* fifth = new Node(50);
   Node* sixth = new Node(60);

   first->next = second;
   second->next =third;
   third->next =fourth;
   fourth->next =fifth;
   fifth->next =sixth;
   //Linked list is created

   Node* head = first;
   Node* tail =sixth;
   cout<<"Printing the linked list"<<endl;
   printLL(head);

   cout<<"Length of the linkedlist:"<<getLength(head)<<endl;
   
//    cout<<"Insertion at head"<<endl;
//    insertAtHead(head,tail,500);
//    printLL(head);

   //cout<<"Insert at tail"<<endl;
   //insertAtTail(head,tail,300);
   //printLL(head);
    return 0;
}