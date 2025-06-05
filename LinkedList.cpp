#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for data "<<value<<endl;
    }
    
};
void deleteNode(int p,Node* &head){
    if(p==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<=p){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertToPosition(Node* &tail,Node* &head,int p,int d){
    Node* temp=head;
    int cnt=1;
    if(p==1){
        insertAtHead(head,d);
        return;
    }
    if(temp->next==NULL){
        insertAtHead(tail,d);
        return;
    }
    while(cnt<p-1){
    temp=temp->next;
    cnt++;
}
    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1=new Node(10);
    //cout<<node1->data<<endl;
   // cout<<node1->next<<endl;
    Node* head=node1;
    Node* tail=node1;
    print(head);
    insertAtTail(tail,12);
    print(tail);
    insertAtHead(head,15);
    print(head);
    insertToPosition(tail,head,3,22);
    print(head);
    cout<<"Tail "<<tail->data<<endl<<"Head "<<head->data<<endl;
    deleteNode(1,head);
    print(head);
    return 0;
}