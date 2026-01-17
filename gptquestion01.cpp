#include<iostream>
using namespace std;

class Node{
public:
    char data;
    Node* next;
    
    Node(char d):data(d),next(nullptr){}
};

class Stack{
public:
    Node* top;    

    Stack():top(nullptr){}

    bool isEmpty(){
        if(top)
            return false;
        return true;     
    }

    void push(char d){
        if(isEmpty()){
            Node* newNode=new Node(d);
            top=newNode;
        }
        else{
            Node* newNode=new Node(d);
            newNode->next=top;
            top=newNode;
        }
    }

    void pop(){
        if(isEmpty()){
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

int getPrecedence(char c){
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

string infixToPostFix(string s){
    string result;
    Stack st;

    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            result+=s[i];
        }

        else if(s[i]>='0' && s[i]<='9'){
            result+=s[i];
        }

        else if(s[i]=='('){
            st.push(s[i]);
        }

        else if(s[i]==')'){
            bool found=false;
            while(!st.isEmpty() && st.topvalue()!='('){
                found=true;
                result+=st.topvalue();
                st.pop();
            }
            if(!found){
                cout<<"The string contains un balanaced parenthisis!"<<endl;
                return "";
            }
            if(!st.isEmpty()){
                st.pop();
            }
        }
        else{
            while(!st.isEmpty() && ((getPrecedence(st.topvalue())>getPrecedence(s[i])) || ((getPrecedence(st.topvalue())==getPrecedence(s[i])) &&(s[i]!='^')))){
                result+=st.topvalue();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.isEmpty()){
        result+=st.topvalue();
        st.pop();
    }

    return result;
}

string reverseString(string s){
    string result;
    for(int i=s.length()-1; i>=0; i--){
        result+=s[i];
    }
    return result;
}

string infixToPreFix(string s){
    string result;

    result=reverseString(s);

    for(int i=0; i<result.length(); i++){
        if(result[i]=='('){
            result[i]=')';
        }
        else if(result[i]==')'){
            result[i]='(';
        }
    }

    //convert it to postfix:
    result=infixToPostFix(result);

    //now reverse again:(now you have pre fix):
    result=reverseString(result);

    return result;
}

int main(){

    string s="(a-b/c)*(a/k-l)";

    cout<<"Post Fix equivalent: "<<infixToPostFix(s)<<endl;
    cout<<"Pre Fix equivalent: "<<infixToPreFix(s)<<endl;

}