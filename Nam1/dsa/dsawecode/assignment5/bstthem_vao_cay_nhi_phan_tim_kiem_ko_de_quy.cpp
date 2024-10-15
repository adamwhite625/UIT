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
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
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

    Node * insert(Node * root, int data) {
// T?o m?t node m?i v?i giá tr? data
    Node *newNode = new Node(data);
    
    // N?u cây r?ng, node m?i s? là g?c c?a cây
    if (root == nullptr) {
        root = newNode;
        return root;
    }

    // L?p d? tìm v? trí thích h?p cho node m?i
    Node *current = root;
    while (true) {
        // N?u data nh? hon giá tr? c?a node hi?n t?i, di?u ch?nh cây con trái
        if (data < current->data) {
            if (current->left == nullptr) {
                current->left = newNode;
                break;
            } else {
                current = current->left;
            }
        }
        // N?u data l?n hon ho?c b?ng giá tr? c?a node hi?n t?i, di?u ch?nh cây con ph?i
        else {
            if (current->right == nullptr) {
                current->right = newNode;
                break;
            } else {
                current = current->right;
            }
        }
    }

    return root;
        }
}; 

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
