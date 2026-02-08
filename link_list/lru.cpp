// https://leetcode.com/problems/lru-cache/description/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int value;
    Node* prev = NULL;
    Node* next = NULL;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    // unordered_map<int, pair<int, Node*>> cache; // key -> [value, node
    // pointer]
    unordered_map<int, Node*> cache; // key -> node pointer
    Node* head;                      // dummy head
    Node* tail;                      // dummy tail

    // Node* addNode(int key, int value) {
    //     Node* node = new Node(key, value);
    void addNode(Node* node) {
        node->next = head;
        node->prev = head->prev;

        head->prev->next = node;
        head->prev = node;

        // return node;
    }

    void removeNode(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        // delete node;
    }

    // Move existing node to front
    void moveToFront(Node* node) {
        removeNode(node);
        addNode(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        tail->next = head;
        head->prev = tail;
    }

    int get(int key) {

        if (cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        moveToFront(node);

        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            // cache.erase(key);
            // removeNode(node);
            node->value = value;
            moveToFront(node);
            return;
        } else if (cache.size() == capacity) {
            Node* last = tail->next;
            cache.erase(last->key);
            removeNode(last);
            delete last;
        }

        // Node* node = addNode(key, value);
        // cache[key] = {value, node};
        Node* node = new Node(key, value);
        addNode(node);
        cache[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */