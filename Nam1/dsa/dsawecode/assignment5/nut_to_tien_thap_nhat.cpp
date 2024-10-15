
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

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
  
    Node *lca(Node *root, int v1,int v2) {
if (root == nullptr) {
        return nullptr;
    }

    // N?u giá tr? c?a nút root l?n hon c? v1 và v2,
    // thì nút t? tiên th?p nh?t s? ? cây con trái
    if (root->data > v1 && root->data > v2) {
        return lca(root->left, v1, v2);
    }

    // N?u giá tr? c?a nút root nh? hon c? v1 và v2,
    // thì nút t? tiên th?p nh?t s? ? cây con ph?i
    if (root->data < v1 && root->data < v2) {
        return lca(root->right, v1, v2);
    }

    // N?u giá tr? c?a nút root n?m gi?a v1 và v2,
    // ho?c là b?ng v1 ho?c v2 thì nút root chính là nút t? tiên th?p nh?t
    return root;
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
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
