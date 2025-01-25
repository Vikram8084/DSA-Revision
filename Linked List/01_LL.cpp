#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){
            // default constructor

            this->next =NULL;
        }

        Node(int data){
            //parameterized constructor
            this->data = data;
            this->next =NULL;
        }
};

void printLL(Node*head){
    Node* temp = head;//temp se hi chhed chhad krange
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp= temp->next;
    }
    cout<<endl;
}

int getLength(Node*head){
    Node*temp =head;
    int count =0;
    while(temp!= NULL){
        count++;
        temp =temp->next;
    }
    return count;

}

void insertAtHead(Node* &head, Node* &tail,int data){
    //pass by refernce karna hota hai
    // if the LL is empty
    if(head == NULL){

    //step:1 create a new node
    Node* newNode =new Node(data);
    //step2: update head
    head = newNode;
    tail = newNode;
    }

    else{
        //create a new node
        Node* newNode =new Node(data);
        // attach a new node to a head node
        newNode -> next =head;
        //update head
        head = newNode;
    }

}

void insertAtTail(Node* &head,Node* &tail,int data){
    //if linked list is null
    if(head == NULL){
        Node*newNode = new Node(data);
        //single node hai linked list me so that 
        //that's why head and tail ko ispar hi point karwa do 
        head= newNode;
        tail =newNode;
    }
    else{
        //non- empty linked list
        //step1: create a new node

        Node*newNode= new Node(data);
        //step2: tail node ko attach karo new node me
        tail->next =newNode;
        //step3:update the tail
        tail =newNode;

    }
}

void createTail(Node* &head,Node* &tail){
    Node* temp =head;
    while(temp-> next !=NULL){
        tail =temp;
        temp =temp->next;
    }
    //jab ye loop khatam ho gayahoga then
    //aapka temo wala pointer khada hogalast node par
    //tab temp =temp karke ,tail ko last nodepar le aao
    tail =temp;

}

void insertAtPosition(Node* &head, Node* &tail,int data, int position){
    if(position <1){
        cout<<"we can not insert , please enter a valid position"<<endl;
        return;
    }
    int length =getLength(head);

    if(position == 1){
        insertAtHead(head,tail,data);
    }

    else if(position > length){
        insertAtTail(head,tail,data);
    }

    else{
        //insert at middle point of the linked list 

        //step1: create a new node
        Node* newNode= new Node(data);

        //step2: traverse the previous // curr to the position

        Node* prev =NULL;
        Node* curr =head;
        while(position !=1){
            prev =curr;
            curr =curr->next;
            position --;
        }

        // step3: attach prev node to the new node

        prev->next =newNode;
        //step4: attach a newNode to the currr
        newNode->next =curr;

    }
    // else if (position > length + 1) {
    // cout << "Cannot insert, please enter a valid position" << endl;
    // return;
//}

}

int main(){
    Node*head =NULL;
    Node*tail =NULL;

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,50);
    printLL(head);

    insertAtPosition(head,tail,5,0);
    printLL(head);

    insertAtPosition(head,tail,1000,51);
    printLL(head);

    insertAtPosition(head,tail,100,3);
    printLL(head);
    return 0;

}