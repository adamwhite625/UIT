#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode* next;
	SinglyLinkedListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void insertNode(int node_data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);
        if(!this->head)
        {
            this->head = node;
        }
        else{
            this->tail->next = node;
        }
        this->tail = node;
    }

    void printLinkedList()
    {
        SinglyLinkedListNode *p = this->head;
        while(p != NULL)
        {
            cout << p->data << endl;
            p = p->next;
        }
    }
};

void free_singlylinkedlist(SinglyLinkedListNode *node)
{
    while(node){
        SinglyLinkedListNode *temp = node;
        node = node->next;
        free(temp);
    }
}

int main(){
    SinglyLinkedList *llist = new SinglyLinkedList();
    int cnt;
    int x;
    cin >> cnt;
    for(int i = 0; i < cnt; i++)
    {
        int item;
        cin >> item;
        llist->insertNode(item);
    }
    llist->printLinkedList();
    free_singlylinkedlist(llist->head);
    return 0;
}
