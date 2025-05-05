#include<iostream>
using namespace std;

class AbstractStack{
public:
    int size;
    int* stack;
    int topIndex;
    AbstractStack(int value){
        size = value;
        stack = new int[size];
        topIndex = 0;
    }

    void push(int value){
        if(topIndex == size){
            cout << "The stack is full";
            return;
        }
        stack[topIndex] = value;
        topIndex++;
        cout << value << " added to the stack " << endl; 
    }

    int pop(){
        if(topIndex == 0){
            cout << "The stack is empty" << endl;
            return 0;
        }
        int val = stack[topIndex-1];
        topIndex--;
        cout << "Removed " << val << " from the stack" << endl;
        return val;
    }

    int top(){
        if(topIndex == 0){
            cout << "The stack is empty " << endl;
            return 0;
        }
        return stack[topIndex-1];
    }

    bool isEmpty(){
        if(topIndex == 0){
            return true;
        }
        return false;
    }

    int stackSize(){
        return topIndex;
    }

};

int main(){
    AbstractStack* s = new AbstractStack(5);
    s->push(10);
    s->push(20);
    s->push(30);
    int val = s->top();
    cout << val << endl;
    val = s->pop();
    cout << val << endl;
    val = s->top();
    cout << val << endl;
    return 0;
}