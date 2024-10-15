
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

    void preOrder(Node *root) {
// Ki?m tra n?u cây r?ng
    if (root == nullptr) {
        return;
    }

    stack<Node*> s;
    Node* current = root;

    // Duy?t t? g?c cho d?n khi h?t cây ho?c ngan x?p tr?ng
    while (current != nullptr || !s.empty()) {
        // In giá tr? c?a node hi?n t?i
        cout << current->data << " ";

        // N?u có cây con ph?i, thêm vào ngan x?p tru?c cây con trái
        if (current->right != nullptr) {
            s.push(current->right);
        }
        
        // Di chuy?n d?n cây con trái c?a node
        current = current->left;

        // N?u không còn cây con trái và ngan x?p không r?ng, l?y node t? ngan x?p
        if (current == nullptr && !s.empty()) {
            current = s.top();
            s.pop();
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
  
    myTree.preOrder(root);

    return 0;
}
