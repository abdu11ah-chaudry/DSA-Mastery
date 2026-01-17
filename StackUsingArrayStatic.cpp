#include<iostream>
using namespace std;

const int stackSize=3;

class IntStack{
    int array[stackSize];
    int top;
public:
    IntStack():top(0){}

    bool isEmpty(){
        if(top==0) { return true;}
        else { return false; }
    }

    bool isFull(){
        if(top==stackSize) {return true;}
        else {return false;}
    }

    void push(int e){
        if(isFull()){
            cout<<"Stack is full."<<endl;
            return;
        }
        else{
            array[top++]=e;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Nothing in stack to be popped out."<<endl;
            return;
        }
        else{
            cout<<"Poped: "<<array[top-1]<<endl;
            top--;
        }
    }

    void displayStack(){
        if(isEmpty()){
            cout<<"Empty Stack!"<<endl;
            return;
        }
        for(int i=top-1; i>=0; i--){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    IntStack stack1;
    stack1.push(20);
    stack1.push(10);
    stack1.push(50);
    stack1.push(40);
    stack1.pop();

    stack1.displayStack();
    
    return 0;
}