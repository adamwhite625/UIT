#include <iostream>

using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int data)
    {
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

    void inserNode(int data)
    {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(data);
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
        SinglyLinkedListNode *p;
        p = head;
        while(p != NULL)
        {
            cout << p->data << endl;
            p = p->next;
        }
    }

    SinglyLinkedListNode *addHead(int data)
    {
        SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
        if(!head)
        {
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};

void freeSinglyLinkedList(SinglyLinkedListNode *node)
{
    while(node)
    {
        SinglyLinkedListNode *temp = node;
        node = node->next;
        free(temp);
    }
}

int main()
{
    SinglyLinkedList *llist = new SinglyLinkedList();
    int cnt;
    int x;
    cin >> cnt;
    for(int i= 0; i < cnt; i++)
    {
        int item;
        cin >> item;
        llist->inserNode(item);
    }
    cin >> cnt;
    for(int i = 0; i < cnt; i++)
    {
        int item;
        cin >> item;
        llist->addHead(item);
    }
    llist->printLinkedList();
    freeSinglyLinkedList(llist->head);
    return 0;
}
