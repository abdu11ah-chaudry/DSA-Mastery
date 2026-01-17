#include<iostream>
using namespace std;

class Node{
public:
    string url;
    Node* next;
    
    Node(string u){
        url=u;
        next=nullptr;
    }
};

class Stack{
public:
    Node* top;
    
    Stack(){
        top=nullptr;
    }

    bool isEmpty(){
        return top==nullptr;
    }
    
    void pushURL(string u){
        Node* newNode= new Node(u);

        newNode->next=top;
        top=newNode;
    }

    void popTwo(){
        for(int i=0; i<2; i++){
            if(!isEmpty()){
                Node* temp=top;
                top=top->next;
                delete temp;
            }
            else{
                cout<<"No more pages to go back!"<<endl;
                return;
            }
        }
    }

    void displayCurrentTop(){
        if(!isEmpty()){
            cout<<"Currently on: "<<top->url<<endl;
        }
        else{
            cout<<"No current page!"<<endl;
        }
    }
};

int main(){

    Stack myStack;
    myStack.pushURL("Google");
    myStack.pushURL("Facebook");
    myStack.pushURL("Twitter");
    myStack.pushURL("Linkedin");
    myStack.pushURL("Instagram");

    //User Clicking back:
    myStack.popTwo();

    //Landing to Twitter:
    myStack.displayCurrentTop();
    
}