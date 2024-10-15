
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
// Ki?m tra n?u cây r?ng
    if (root == nullptr) {
        return;
    }

    // T?o m?t hàng d?i d? luu tr? các node
    queue<Node*> q;
    // Thêm g?c vào hàng d?i
    q.push(root);

    // Duy?t t?ng node trong cây
    while (!q.empty()) {
        // L?y node d?u tiên ra kh?i hàng d?i và in giá tr? c?a node dó
        Node* current = q.front();
        cout << current->data << " ";
        q.pop();

        // N?u có cây con trái, thêm vào hàng d?i
        if (current->left != nullptr) {
            q.push(current->left);
        }
        // N?u có cây con ph?i, thêm vào hàng d?i
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
