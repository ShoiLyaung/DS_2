#include<iostream>

using namespace std;

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(): prev(nullptr), next(nullptr) {} // 构造函数
    Node(int x): data(x), prev(nullptr), next(nullptr) {} // 构造函数
};

class DoublyLinkedList {
private:
    Node* head;
public:
    DoublyLinkedList() {
        head = new Node();
    }

    void insert(int x) { // 在链表尾部插入一个新结点
        Node* p = head;
        while (p->next) p = p->next; // 找到链表尾结点
        Node* q = new Node(x); // 创建一个新结点
        p->next = q; // 将新结点插入到尾部
        q->prev = p; // 更新新结点的前指针
    }

    void print() {
        Node* temp = head->next;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void quickSort() {
        Node* tail = head;
        while (tail->next) tail = tail->next;
        
        quickSort(head->next, tail);
    }

private:
    void quickSort(Node* left, Node* right) {
        if (right != nullptr && left != right && left != right->next) {
            Node* pivot = partition(left, right);
            quickSort(left, pivot->prev);
            quickSort(pivot->next, right);
        }
    }

    Node* partition(Node* left, Node* right) {
        int pivot = right->data;    // 取枢轴元素 
        Node* i = left->prev;

        for (Node* j = left; j != right; j = j->next) {
            if (j->data <= pivot) {
                i = (i == nullptr) ? left : i->next;
                swap(i, j);
            }
        }
        i = (i == nullptr) ? left : i->next;
        swap(i, right);
        return i;
    }

    void swap(Node* a, Node* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }
};

