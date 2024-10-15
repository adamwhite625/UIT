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
// N?u c�y r?ng, t?o m?t node m?i v� tr? v?
    if (root == NULL) {
        return new Node(data);
    } else {
        Node* cur;
        // N?u data nh? hon gi� tr? c?a node hi?n t?i, di?u ch?nh c�y con tr�i
        if (data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        }
        // N?u data l?n hon gi� tr? c?a node hi?n t?i, di?u ch?nh c�y con ph?i
        else {
            cur = insert(root->right, data);
            root->right = cur;
        }
}
        // Tr? v? g?c c?a c�y d� du?c c?p nh?t
        return root;    }
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
