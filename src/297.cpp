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
        
        stringstream ss;//  初始化stringstream对象，用于存储序列化后的字符串
        ss << "[";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                ss << node->val;
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "null";
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
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (!getline(ss, token, ',')) break;
            if (token != "null") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }
            
            if (!getline(ss, token, ',')) break;
            if (token != "null") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
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
    
    cout << "Test Case 1:" << endl;
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(5);
    cout << "Original: ";
    printTree(root1);
    cout << endl;
    string serialized1 = codec.serialize(root1);
    cout << "Serialized: " << serialized1 << endl;
    TreeNode* deserialized1 = codec.deserialize(serialized1);
    cout << "Deserialized: ";
    printTree(deserialized1);
    cout << endl;
    deleteTree(root1);
    deleteTree(deserialized1);
    
    cout << "\nTest Case 2:" << endl;
    TreeNode* root2 = nullptr;
    cout << "Original: ";
    printTree(root2);
    cout << endl;
    string serialized2 = codec.serialize(root2);
    cout << "Serialized: " << serialized2 << endl;
    TreeNode* deserialized2 = codec.deserialize(serialized2);
    cout << "Deserialized: ";
    printTree(deserialized2);
    cout << endl;
    
    cout << "\nTest Case 3:" << endl;
    TreeNode* root3 = new TreeNode(1);
    cout << "Original: ";
    printTree(root3);
    cout << endl;
    string serialized3 = codec.serialize(root3);
    cout << "Serialized: " << serialized3 << endl;
    TreeNode* deserialized3 = codec.deserialize(serialized3);
    cout << "Deserialized: ";
    printTree(deserialized3);
    cout << endl;
    deleteTree(root3);
    deleteTree(deserialized3);
    
    cout << "\nTest Case 4:" << endl;
    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    cout << "Original: ";
    printTree(root4);
    cout << endl;
    string serialized4 = codec.serialize(root4);
    cout << "Serialized: " << serialized4 << endl;
    TreeNode* deserialized4 = codec.deserialize(serialized4);
    cout << "Deserialized: ";
    printTree(deserialized4);
    cout << endl;
    deleteTree(root4);
    deleteTree(deserialized4);
    
    return 0;
}