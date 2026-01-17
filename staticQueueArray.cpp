#include<iostream>
using namespace std;

const int queueSize=3;

class Queue{
public:
    int array[queueSize];
    int front;
    int rear;
    int number; //how many elements in queue.
    
    Queue():front(-1),rear(-1),number(0){}

    bool isEmpty(){
        return number==0;
    }

    bool isFull(){
        return number==queueSize;
    }

    void enqueue(int e){
        if(!isFull()){
            rear=(rear+1)%queueSize; //Mod for wrapping

            array[rear]=e;
            number++;
            cout<<"Enqueued: "<<e<<endl;
        }
        else{
            cout<<"Can't enqueue, queue is full."<<endl;
        }
    }

    void dequeue(){
        if(!isEmpty()){
            front=(front+1)%queueSize;
            int x=array[front];
            number--;
            cout<<"Dequeued: "<<x<<endl;
        }
    }

};


int main(){

    Queue q1;
    q1.enqueue(20);
    q1.enqueue(10);
    q1.enqueue(15);
    q1.enqueue(5);

    q1.dequeue();
    q1.enqueue(3);

}