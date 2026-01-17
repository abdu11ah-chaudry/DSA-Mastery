#include<iostream>
using namespace std;

int main(){

    string name="abdullah";
    string reversed;
    int a=0;
    for(int i=name.length()-1; i>=0; i--){
        reversed+=name[i];
        a++;
    }
    cout<<reversed;
}




