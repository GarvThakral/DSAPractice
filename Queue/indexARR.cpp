#include <iostream>
using namespace std;

class AbstractQueue{
public:
    int size;
    int frontIndex = 0;
    int rearIndex = 0;
    int* queue;
    AbstractQueue(int val){
        size = val;
        queue = new int[size];
    }
    void enqueue(int val){
        if(rearIndex == size){
            cout << "Full" << endl;
            return;
        }
        queue[rearIndex] = val;
        rearIndex++;
    }
    int dequeue(){
        if(rearIndex == frontIndex){
            cout << "Empty" << endl;
            return 0;
        }
        int value = queue[frontIndex];
        frontIndex++;
        return value;
    }
    int front(){
        if(frontIndex == rearIndex){
            cout << "Empty" <<endl;
            return 0;
        }
        return queue[frontIndex];
    }
    int rear(){
        if(frontIndex == rearIndex){
            cout << "Empty" <<endl;
            return 0;
        }
        return queue[rearIndex-1];

    }
    bool isEmpty(){
        if(frontIndex == rearIndex){
            return true;
        }
        return false;

    }
    ~AbstractQueue() {
        delete[] queue;
    }
};

int main(){
    AbstractQueue* q1 = new AbstractQueue(3);
    bool yes = q1->isEmpty();
    cout << yes << endl;
    return 0; 
}