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

class IntStack{
    Node* top;
public:
    IntStack(){
        top=nullptr;
    }

    bool isEmpty(){
        return top==nullptr;
    }

    
    void push(int e){
        Node* newNode=new Node(e);

        newNode->next=top;
        top=newNode;
        cout<<"Element :"<<e<<" Pushed into stack."<<endl;
    }

    void pop(){
        if(top==nullptr){
            cout<<"Nothing in stack to be poped out."<<endl;
            return;
        }
        Node* temp=top;
        cout<<"Poped: "<<top->data<<endl;
        top=top->next;
        delete temp;
    }

    int peek(){  //Peak: viewing top element.
        if(top!=nullptr){
            cout<<"Top element: "<<top->data<<endl;
        }
        else{
            cout<<"Empty stack!"<<endl;
        }
    } 

    void displayStack(){
        if(top!=nullptr){
            Node* temp=top;
            cout<<"Stack elements top to bottom: "<<endl;
            while(temp!=nullptr){
                cout<<temp->data<<"  ";
                temp=temp->next;
            }
            cout<<endl;
        }
        else{
            cout<<"Empty Stack!"<<endl;
        }
    }

    ~IntStack() { // destructor to free memory
        while (!isEmpty()) {
            cout<<endl<<"Destructor doing its job."<<endl;
            pop();
        }
    }
};

int main(){
    IntStack stack1;
    stack1.push(20);
    stack1.push(10);
    stack1.push(50);
    stack1.push(40);
    stack1.displayStack();
    stack1.pop(); 
    stack1.pop();
    
    stack1.displayStack();

    return 0;
}