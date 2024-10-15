
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
bool checkBST(Node* root) {
return checkBSTUtil(root, INT_MIN, INT_MAX);
}

bool checkBSTUtil(Node* root, int minValue, int maxValue) {
    if (root == nullptr) {
        return true;
    }

    // Ki?m tra xem giá tr? c?a nút root có n?m trong kho?ng h?p l? không
    if (root->data <= minValue || root->data >= maxValue) {
        return false;
    }

    // Ki?m tra BST trong cây con trái và cây con ph?i
    return checkBSTUtil(root->left, minValue, root->data) &&
           checkBSTUtil(root->right, root->data, maxValue);
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
  
    std::cout<<myTree.checkBST(root);

    return 0;
}
