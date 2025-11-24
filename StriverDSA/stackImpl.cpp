// To implement
// Push pop top isEmpty size

#include <iostream>
using namespace std;


class CustomStack{
public:
    int size;
    int index = -1;
    int* arr;
    CustomStack(int n){
        size = n;
        arr = new int[size];
    }

    int top(){
        if(index == -1){
            cout << "stack is empty" << endl;
            return 0;
        }
        return arr[index];
    }
    void push(int num){
        if (index == size - 1) {
            int* newArr = new int[size*2];
            for(int i = 0 ;i < size ;i++){
                newArr[i] = arr[i];
            }
            size *=2;
            delete[] arr;
            arr = newArr;
        }
        index++;
        arr[index] = num; 
    }
    void pop(){
        if(index == -1){
            cout << "Stack already empty" << endl;
            return;
        }
        index--; 
    }

    bool isEmpty(){
        if(index == -1){
            return true;
        }
        return false;
    }
    ~CustomStack(){
        delete[] arr;
    }
    
};


int main(){
    CustomStack S(2);
    S.push(10);
    S.push(12);
    S.push(14);
    S.push(16);
    cout << S.top();
    S.pop();
    cout << S.top();
    S.pop();
    S.pop();
}