#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        
        stringstream ss;
        ss << "[";
        queue<TreeNode*> q;
        q.push(root);
        
        cout << "===== Serialization Process =====" << endl;
        cout << "Initial queue: [1]" << endl;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                ss << node->val;
                q.push(node->left);
                q.push(node->right);
                
                cout << "Output: " << node->val 
                     << " | Enqueue: ";
                if(node->left) cout << node->left->val;
                else cout << "null";
                cout << ", ";
                if(node->right) cout << node->right->val;
                else cout << "null";
                cout << " | Current queue: ";
                
                queue<TreeNode*> temp = q;
                while (!temp.empty()) {
                    if (temp.front()) cout << temp.front()->val;
                    else cout << "null";
                    temp.pop();
                    if (!temp.empty()) cout << ",";
                }
                cout << endl;
            } else {
                ss << "null";
                
                cout << "Output: null | Current queue: ";
                queue<TreeNode*> temp = q;
                while (!temp.empty()) {
                    if (temp.front()) cout << temp.front()->val;
                    else cout << "null";
                    temp.pop();
                    if (!temp.empty()) cout << ",";
                }
                cout << endl;
            }
            
            if (!q.empty()) {
                ss << ",";
            }
        }
        
        ss << "]";
        return ss.str();
    }

    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;
        
        string content = data.substr(1, data.size() - 2);
        stringstream ss(content);
        string token;
        
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);
        
        cout << "\n===== Deserialization Process =====" << endl;
        cout << "Input string: " << data << endl;
        cout << "Element 1: " << token << " -> Create root node" << endl;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (!getline(ss, token, ',')) break;
            cout << "Process node " << node->val << " left: " << token;
            if (token != "null") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
                cout << " -> Create left child " << token << ", enqueue";
            }
            cout << endl;
            
            if (!getline(ss, token, ',')) break;
            cout << "Process node " << node->val << " right: " << token;
            if (token != "null") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
                cout << " -> Create right child " << token << ", enqueue";
            }
            cout << endl;
        }
        
        return root;
    }
};

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void printTree(TreeNode* root) {
    if (!root) {
        cout << "[]";
        return;
    }
    
    cout << "[";
    queue<TreeNode*> q;
    q.push(root);
    bool first = true;
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (!first) cout << ",";
        first = false;
        
        if (node) {
            cout << node->val;
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null";
        }
    }
    
    cout << "]";
}

int main() {
    Codec codec;
    
    cout << "========== Test: root = [1,2,3,null,null,4,5] ==========" << endl;
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    cout << "\nOriginal tree: ";
    printTree(root);
    cout << "\n" << endl;
    
    string serialized = codec.serialize(root);
    cout << "\nFinal serialized result: " << serialized << endl;
    
    TreeNode* deserialized = codec.deserialize(serialized);
    
    cout << "\nDeserialized result: ";
    printTree(deserialized);
    cout << "\n" << endl;
    
    deleteTree(root);
    deleteTree(deserialized);
    
    return 0;
}