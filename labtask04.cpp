#include<iostream>
using namespace std;

class Node{
public:
    Node* next;
    char data;
    Node(char d){
        next=nullptr;
        data=d;
    }
};

class CharStack{
    Node* top;
public:
    CharStack(){
        top=nullptr;
    }

    bool isEmpty(){
        return top==nullptr;
    }

    
    void push(char e){
        Node* newNode=new Node(e);

        newNode->next=top;
        top=newNode;
    }

    void pop(){
        if(top==nullptr){
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
    }

    char topvalue(){
        return top->data;
    }
};

int precedenceCheck(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='/' || c=='*'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

void infixTopostfix(string s){

    string result;
    CharStack stack;

    for(int i=0; i<s.length(); i++){

        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            result+=s[i];
        }

        else if(s[i]=='('){
            stack.push(s[i]);
        }

        else if(s[i]==')'){
            while(!stack.isEmpty() && stack.topvalue()!='('){
                result+=stack.topvalue();
                stack.pop();
            }
            if(!stack.isEmpty()){
                stack.pop();
            }
        }

        else{
            while(!stack.isEmpty() && ((precedenceCheck(stack.topvalue()) > precedenceCheck(s[i]) ) || 
                    ((precedenceCheck(stack.topvalue()) == precedenceCheck(s[i])) && s[i]!='^')  ))
            {
                result+=stack.topvalue();
                stack.pop();
            }
            stack.push(s[i]);
        }
    }

    while(!stack.isEmpty()){
            result+=stack.topvalue();
            stack.pop();
    }

    cout<<"Converted PostFix: "<<result<<endl;
}

int main(){
    CharStack stack1;
    string s="a+b*(c^d-e)^(f+g*h)-i";

    infixTopostfix(s);

    return 0;
}