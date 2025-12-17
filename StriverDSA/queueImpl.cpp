
// enqueue, dequeue, peek, isEmpty
#include <iostream>
using namespace std;

class CustomQueue{
public:
    int size;
    int* arr;
    int index;
    int start;
    CustomQueue(int num){
        size = num;
        arr = new int[size];
        index = -1;
        start = 0;
    }
    int top(){
        if(index == -1){
            cout << "Queue is empty" << endl;
            return 0;
        }
        return arr[start];
    }
    void enqueue(int num){
        if (index - start + 1 == size) {
            int* newArr = new int[size*2];
            int count = index - start + 1;
            for (int i = 0; i < count; i++){
                newArr[i] = arr[start + i];
            }
            start = 0;
            size *=2;
            delete[] arr;
            arr = newArr;
        }
        index++;
        arr[index] = num; 
    }
    void dequeue(){
        if(index < start){
            cout << "Queue already empty" << endl;
            return;
        }
        start++; 
    }

    bool isEmpty(){
        if(index < start){
            return true;
        }
        return false;
    }
    ~CustomQueue(){
        delete[] arr;
    }
}


