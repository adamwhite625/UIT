
#include <bits/stdc++.h>
using namespace std;

	
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void levelOrder(Node *root) {
// Ki?m tra n?u c�y r?ng
    if (root == nullptr) {
        return;
    }

    // T?o m?t h�ng d?i d? luu tr? c�c node
    queue<Node*> q;
    // Th�m g?c v�o h�ng d?i
    q.push(root);

    // Duy?t t?ng node trong c�y
    while (!q.empty()) {
        // L?y node d?u ti�n ra kh?i h�ng d?i v� in gi� tr? c?a node d�
        Node* current = q.front();
        cout << current->data << " ";
        q.pop();

        // N?u c� c�y con tr�i, th�m v�o h�ng d?i
        if (current->left != nullptr) {
            q.push(current->left);
        }
        // N?u c� c�y con ph?i, th�m v�o h�ng d?i
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
        }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.levelOrder(root);

    return 0;
}
