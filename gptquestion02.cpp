#include<iostream>
using namespace std;

class Node{
public:
    int orderID;
    string customerName;
    int noOfItems;
    int totalPrice;
    Node* next;
    
    Node(int id, string n, int items,int p):orderID(id),customerName(n),totalPrice(p),noOfItems(items),next(nullptr){}
};

class Queue{
public:
    Node* front;
    Node* rear;
    
    Queue():front(nullptr),rear(nullptr){}

    bool isEmpty(){
        if(front==nullptr){
            return true;
        }
        return false;
    }

    void enqueue(int id, string n, int items, int p){
        Node* newNode= new Node(id,n,items,p);
        if(!front){
            front=rear=newNode;
            cout<<"Enqueued new order!"<<endl;
        }
        else{
            rear->next=newNode;
            rear=newNode;
            cout<<"Enqueued new order!"<<endl;
        }
    }

    void dequeue(){
        if(!front){
            cout<<"Can not dequeue, queue is empty!"<<endl;
            return;
        }
        else{
            Node* temp=front;
            front=front->next;
            delete temp;
            if(front == nullptr) rear = nullptr;
            cout<<"sucessfully dequeued the order!"<<endl;
        }
    }


    void peekOrder(){
        if(front){
            cout<<"Peeking next Order: "<<endl;
            cout<<"Order ID: "<<front->orderID<<" Customer Name: "<<front->customerName<<" Total Items: "<<front->noOfItems<<" Total Price: "<<front->totalPrice<<endl;
        }
        else{
            cout<<"No next order to peek!"<<endl;
        }
    }    

    void displayOrders(){
        if(isEmpty()){
            cout<<"Can not display Order, empty queue!"<<endl;
            return;
        }
        Node* temp=front;

        while(temp!=nullptr){
            cout<<"Order ID: "<<temp->orderID<<" Customer Name: "<<temp->customerName<<" Total Items: "<<temp->noOfItems<<" Total Price: "<<temp->totalPrice<<endl;
            temp=temp->next;
        }
    }   
};

int main(){

    Queue q;

    q.enqueue(01,"Abdullah",10,2000);
    q.enqueue(02,"Ali",11,3000);
    q.enqueue(01,"Arham",10,2330);
    q.enqueue(01,"Akbar",17,2220);
    q.enqueue(01,"Asghar",9,2111);

    q.displayOrders();

    q.dequeue();

    q.peekOrder();
}