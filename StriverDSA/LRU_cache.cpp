struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
public:
    Node* dummyHead = new Node(-1,-1);
    Node* dummyTail = new Node(-1,-1);
    int used;
    int capacity_var;
    unordered_map<int,Node*> newMap;
    LRUCache(int capacity) {
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
        used = 0;
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
        auto it = newMap.find(key);
        if (it == newMap.end()) return -1;
        Node* node = it->second;
        moveNode(dummyHead,node);
        return node->val;
    }
    
    void put(int key, int value) {
        auto it = newMap.find(key);
        if(used < capacity_var){
            if(it == newMap.end()){
                Node* newNode=insertAtHead(dummyHead,key,value);
                newMap[key] = newNode;
                used++;
            }else{
                Node* node = it->second;
                node->val = value;
                moveNode(dummyHead,node);
            }
        }else{
            if(it == newMap.end()){
                Node* lru = dummyTail->prev;
                newMap.erase(lru->key);
                deleteNode(lru);

                Node* newNode = insertAtHead(dummyHead,key,value);
                newMap[key] = newNode;
            }else{
                Node* node = it->second;
                node->val = value;
                moveNode(dummyHead,node);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */