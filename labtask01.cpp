#include<iostream>
using namespace std;

class Node{
public:
    Node* next;
    int Number;
    string name;
    int duration;
    Node(int n, string nam, int d){
        next=nullptr;
        Number=n;
        duration=d;
        name=nam;
    }
};

class CallHistoryStack{
    Node* top;
public:
    CallHistoryStack(){
        top=nullptr;
    }

    bool isEmpty(){
        return top==nullptr;
    }

    
    void push(int n, string nam, int d){
        Node* newNode=new Node(n,nam,d);

        newNode->next=top;
        top=newNode;
        cout<<"Call with number:"<<n<<" Pushed into call log."<<endl;
    }

    void pop(){
        if(top==nullptr){
            cout<<"Nothing in call log to be deleted."<<endl;
            return;
        }
        Node* temp=top;
        cout<<"Deleted call log with number: "<<top->Number<<" and caller: "<<temp->name<<endl;
        top=top->next;
        delete temp;
    }

    void displayCallLog(){
        if(top!=nullptr){
            Node* temp=top;
            cout<<"Call Log: "<<endl;
            while(temp!=nullptr){
                cout<<"Caller name: "<<temp->name<<" Phone Number: "<<temp->Number<<" Call duration: "<<temp->duration<<endl;
                temp=temp->next;
            }
        }
        else{
            cout<<"Empty Stack!"<<endl;
        }
    }

    void topp(){
        cout<<"Last call :"<<top->Number<<endl;
    }

    ~CallHistoryStack() { // destructor to free memory
        while (!isEmpty()) {
            cout<<"Destructor"<<endl;
            pop();
        }
    }
};

int main(){
    CallHistoryStack calllog1;
    //Checking call log is empty or not"
    if(calllog1.isEmpty()){
        cout<<"Call log is empty!"<<endl;
    }
    else{
        cout<<"Call log is not empty!"<<endl;
    }
    //Adding new call records:
    calllog1.push(123,"Abdullah",30);
    calllog1.push(231,"Ali",10);
    calllog1.push(912,"Rehman",24);
    //Displaying call log:
    calllog1.displayCallLog();
    //Deleting most recent call log:
    calllog1.pop();
    calllog1.displayCallLog();
    //Showing last call:
    calllog1.topp();
    return 0;
}