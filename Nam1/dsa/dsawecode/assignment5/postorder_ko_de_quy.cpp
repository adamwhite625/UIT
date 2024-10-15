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

    void postOrder(Node *root) {
// Ki?m tra n?u c�y r?ng
    if (root == nullptr) {
        return;
    }

    stack<Node*> s;
    vector<int> result;

    Node* current = root;
    Node* lastVisited = nullptr;

    // Duy?t t? g?c cho d?n khi h?t c�y ho?c ngan x?p tr?ng
    while (current != nullptr || !s.empty()) {
        // �ua t?t c? c�c node tr�i c?a current v�o ngan x?p
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // L?y node d?u ti�n ra kh?i ngan x?p
        Node* topNode = s.top();

        // N?u kh�ng c� c�y con ph?i ho?c c�y con ph?i d� du?c duy?t
        if (topNode->right == nullptr || topNode->right == lastVisited) {
            // Th�m gi� tr? c?a node v�o vector
            result.push_back(topNode->data);
            // �?t lastVisited th�nh node hi?n t?i
            lastVisited = topNode;
            // X�a node d� duy?t kh?i ngan x?p
            s.pop();
        } else {
            // N?u c� c�y con ph?i v� c�y con ph?i chua du?c duy?t
            // Di chuy?n d?n c�y con ph?i
            current = topNode->right;
        }
    }

    // In k?t qu? duy?t LRN
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
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
  
    myTree.postOrder(root);

    return 0;
}
