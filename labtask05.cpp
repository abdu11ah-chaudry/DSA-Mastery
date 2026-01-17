#include<iostream>
#include<math.h>
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


int evaluatePreFix(string preFix){
    Stack myStack;
    if(preFix.length()==0){
        return 0;
    }

    for(int i=preFix.length()-1; i>=0; i--){
        if(preFix[i]=='*' || preFix[i]=='/' || preFix[i]=='-' || preFix[i]=='+'  ||  preFix[i]== '^'){

            int value2=myStack.pop();
            int value1=myStack.pop();
            if(preFix[i]=='*'){
                myStack.push(value1*value2);
            }
            else if(preFix[i]=='/'){
                myStack.push(value1/value2);
            }
            else if(preFix[i]=='+'){
                myStack.push(value1+value2);
            }
            else if(preFix[i]=='^'){
                myStack.push(pow(value1,value2));
            }
            else{
                myStack.push(value1-value2);
            }
        }
        else{
            myStack.push(preFix[i]-'0');
        }
    }

    return myStack.getTopValue();
}

int main(){
    string preFix;
    cout<<"Enter the prefix expression to be evaluated: "<<endl;
    cin>>preFix;

    cout<<"Evaluated Result: "<<evaluatePreFix(preFix);
}