#include<iostream>
using namespace std;

class Node{
public:
    int value;
    Node* next;
    
    Node(int v){
        value=v;
        next=nullptr;
    }
};

class Stack{
public:    
    Node* top;

    Stack(){
        top=nullptr;
    }

    void push(int v){
        Node* newNode= new Node(v);

        newNode->next=top;
        top=newNode;
    }

    int pop(){
        Node* temp=top;
        int val=temp->value;
        top=top->next;
        delete temp;
        return val;
    }

    int getTopValue(){
        return top->value;
    }
    
    bool isEmpty() {
    return top == nullptr;
    }

};


int evaluatePostFix(string postFix){
    Stack myStack;
    if(postFix.length()==0){
        return 0;
    }

    for(int i=0; i<postFix.length(); i++){
        if(postFix[i]=='*' || postFix[i]=='/' || postFix[i]=='-' || postFix[i]=='+'){

            int value2=myStack.pop();
            int value1=myStack.pop();
            if(postFix[i]=='*'){
                myStack.push(value1*value2);
            }
            else if(postFix[i]=='/'){
                myStack.push(value1/value2);
            }
            else if(postFix[i]=='+'){
                myStack.push(value1+value2);
            }
            else{
                myStack.push(value1-value2);
            }
        }
        else{
            myStack.push(postFix[i]-'0');
        }
    }

    return myStack.getTopValue();
}

int main(){
    string postfix;
    cout<<"Enter the postfix expression to be evaluated: "<<endl;
    cin>>postfix;

    cout<<"Evaluated Result: "<<evaluatePostFix(postfix);
}