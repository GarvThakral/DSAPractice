
struct Node{
    int key;
    int val;
    int freq;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v),freq(1), prev(nullptr), next(nullptr) {}
};
class LFUCache {
public:
    // Node* dummyHead = new Node(-1,-1);
    // Node* dummyTail = new Node(-1,-1);
    int used;
    int capacity_var;
    int frequency;
    unordered_map<int,pair<Node*,Node*>> freqMap;
    unordered_map<int,Node*> nodeMap;
    LFUCache(int capacity) {
        // dummyHead->next = dummyTail;
        // dummyTail->prev = dummyHead;
        used = 0;
        frequency = 0;
        capacity_var = capacity;
    }

    Node* insertAtHead(Node*& head , int key , int value){
        Node* newNode = new Node(key, value);
        Node* nextNode = head->next;
        newNode->next = nextNode;
        nextNode->prev = newNode;
        newNode->prev = head;
        head->next = newNode;
        return newNode;
    }
    void insertAtTail(Node*& tail , int key , int value){
        Node* newNode = new Node(key, value);
        Node* prevNode = tail->prev;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        newNode->next = tail;
        tail->prev = newNode;
        return;
    }

    void deleteNode(Node* address){
        Node* prevNode = address->prev;
        Node* nextNode = address->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete address;
    }

    void moveNode(Node*& head , Node*& toMove){
        Node* nextNode = toMove->next;
        Node* prevNode = toMove->prev;
        nextNode->prev = prevNode; 
        prevNode->next = nextNode;
        Node* nextToHead = head->next;
        head->next = toMove;
        toMove->prev = head;
        toMove->next = nextToHead;
        nextToHead->prev = toMove;
        return; 
    }

    int get(int key) {
        auto it = nodeMap.find(key);
        if(it == nodeMap.end()){
            return -1;
        }
        Node* foundNode = it->second;
        int oldFreq = foundNode->freq;
        if(freqMap.find(oldFreq+1)==freqMap.end()){
            freqMap[oldFreq+1] = {nullptr,nullptr};
            Node* dummyHead = new Node(-1,-1);
            Node* dummyTail = new Node(-1,-1);
            freqMap[oldFreq+1].first = dummyHead;
            freqMap[oldFreq+1].second = dummyTail;
            dummyHead->next = dummyTail;
            dummyTail->prev = dummyHead;
        }
        Node* newDummyHead = freqMap[oldFreq+1].first;
        int newFreq = oldFreq + 1;
        foundNode->freq = newFreq;
        moveNode(freqMap[newFreq].first, foundNode);       
        if(freqMap[oldFreq].first->next == freqMap[oldFreq].second){
            if (oldFreq == frequency) frequency++;
        }
        return foundNode->val;
    }
    
    void put(int key, int value) {
        // Case not exists
        if (capacity_var == 0) return;
        auto it = nodeMap.find(key);
        if(it == nodeMap.end()){
            if(used == capacity_var){
                Node* victim = freqMap[frequency].second->prev;
                int victimKey = victim->key;
                deleteNode(victim);
                nodeMap.erase(victimKey);
                nodeMap[key] = insertAtHead(freqMap[1].first,key,value);
                frequency = 1;
            }else{
                if(freqMap[1].first == nullptr){
                    Node* dummyHead = new Node(-1,-1);
                    Node* dummyTail = new Node(-1,-1);
                    dummyHead->next = dummyTail;
                    dummyTail->prev = dummyHead;
                    freqMap[1].first = dummyHead;
                    freqMap[1].second = dummyTail;
                }
                Node* created = insertAtHead(freqMap[1].first,key,value);
                nodeMap[key] = created ;
                used++;
                frequency = 1;
            }
        }else{
           it->second->val = value;
           get(key); 
        }
        // Case not exists
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */