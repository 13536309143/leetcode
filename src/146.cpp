#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        Node* node = cache[key];
        removeNode(node);
        addToHead(node);
        
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            addToHead(node);
            return;
        }
        
        if (cache.size() == capacity) {
            Node* last = tail->prev;
            removeNode(last);
            cache.erase(last->key);
            delete last;
        }
        
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        addToHead(newNode);
    }
};

int main() {
    LRUCache* obj = new LRUCache(2);
    
    cout << "Operations: [\"LRUCache\", \"put\", \"put\", \"get\", \"put\", \"get\", \"put\", \"get\", \"get\", \"get\"]" << endl;
    cout << "Arguments: [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]" << endl;
    
    obj->put(1, 1);
    cout << "put(1, 1) -> null" << endl;
    
    obj->put(2, 2);
    cout << "put(2, 2) -> null" << endl;
    
    cout << "get(1) -> " << obj->get(1) << endl;
    
    obj->put(3, 3);
    cout << "put(3, 3) -> null" << endl;
    
    cout << "get(2) -> " << obj->get(2) << endl;
    
    obj->put(4, 4);
    cout << "put(4, 4) -> null" << endl;
    
    cout << "get(1) -> " << obj->get(1) << endl;
    cout << "get(3) -> " << obj->get(3) << endl;
    cout << "get(4) -> " << obj->get(4) << endl;
    
    delete obj;
    
    return 0;
}