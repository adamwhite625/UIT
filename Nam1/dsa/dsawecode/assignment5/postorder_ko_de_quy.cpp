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
// Ki?m tra n?u cây r?ng
    if (root == nullptr) {
        return;
    }

    stack<Node*> s;
    vector<int> result;

    Node* current = root;
    Node* lastVisited = nullptr;

    // Duy?t t? g?c cho d?n khi h?t cây ho?c ngan x?p tr?ng
    while (current != nullptr || !s.empty()) {
        // Ðua t?t c? các node trái c?a current vào ngan x?p
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // L?y node d?u tiên ra kh?i ngan x?p
        Node* topNode = s.top();

        // N?u không có cây con ph?i ho?c cây con ph?i dã du?c duy?t
        if (topNode->right == nullptr || topNode->right == lastVisited) {
            // Thêm giá tr? c?a node vào vector
            result.push_back(topNode->data);
            // Ð?t lastVisited thành node hi?n t?i
            lastVisited = topNode;
            // Xóa node dã duy?t kh?i ngan x?p
            s.pop();
        } else {
            // N?u có cây con ph?i và cây con ph?i chua du?c duy?t
            // Di chuy?n d?n cây con ph?i
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
