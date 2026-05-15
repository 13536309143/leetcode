#include <iostream>
#include <string>
using namespace std;

struct TrieNode {
    bool isEnd;
    TrieNode* children[26];
    
    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};

int main() {
    Trie* trie = new Trie();
    
    cout << "Test Case:" << endl;
    
    trie->insert("apple");
    cout << "insert(\"apple\") -> null" << endl;
    
    bool result1 = trie->search("apple");
    cout << "search(\"apple\") -> " << (result1 ? "true" : "false") << endl;
    
    bool result2 = trie->search("app");
    cout << "search(\"app\") -> " << (result2 ? "true" : "false") << endl;
    
    bool result3 = trie->startsWith("app");
    cout << "startsWith(\"app\") -> " << (result3 ? "true" : "false") << endl;
    
    trie->insert("app");
    cout << "insert(\"app\") -> null" << endl;
    
    bool result4 = trie->search("app");
    cout << "search(\"app\") -> " << (result4 ? "true" : "false") << endl;
    
    delete trie;
    
    return 0;
}
