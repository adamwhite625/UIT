
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

    void inOrder(Node *root) {
// Ki?m tra n?u cây r?ng
    if (root == nullptr) {
        return;
    }

    stack<Node*> s;
    Node* current = root;

    // Duy?t t? g?c cho d?n khi h?t cây ho?c ngan x?p tr?ng
    while (current != nullptr || !s.empty()) {
        // Ðua t?t c? các node trái c?a current vào ngan x?p
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // L?y node d?u tiên ra kh?i ngan x?p
        current = s.top();
        s.pop();

        // In giá tr? c?a node
        cout << current->data << " ";

        // Di chuy?n d?n cây con ph?i c?a node
        current = current->right;
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
  
    myTree.inOrder(root);

    return 0;
}
