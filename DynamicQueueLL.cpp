#include<iostream>
using namespace std;

class Node{
public:
    Node* next;
    int data;
    Node(int d){
        next=nullptr;
        data=d;
    }
};

class Queue{
public:    
    Node* front;
    Node* rear;

    Queue(){
        front=rear=nullptr;
    }

    bool isempty(){
        return (front==nullptr);
    }

    void enqueue(int e){
        if(isempty()){
            Node* newNode=new Node(e);
            front=rear=newNode;
            cout<<"Enqueued: "<<e<<endl;
        }

        else{
            Node* newNode=new Node(e);
            rear->next=newNode;
            rear=newNode;
            cout<<"Enqueued: "<<e<<endl;
        }
    }

    void dequeue(){
        if(isempty()){
            cout<<"Empty queue, Can't Dequeue"<<endl;
            return;
        }
        Node* temp=front;
        front=front->next;
        cout<<"Dequeued: "<<temp->data<<endl;
        delete temp;
        if (front == nullptr) // queue is now empty
        rear = nullptr;
    }

    void displayQueue(){
        if(isempty()){
            cout<<"empty queue, can not display this shit."<<endl;
            return;
        }
        Node* temp=front;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Queue q1;
    q1.enqueue(20);
    q1.enqueue(10);
    q1.enqueue(15);
    q1.enqueue(5);
    q1.displayQueue();

    q1.dequeue();
    q1.enqueue(3);
    q1.displayQueue();
}