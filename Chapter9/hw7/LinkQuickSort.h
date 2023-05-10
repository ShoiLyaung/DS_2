#include<iostream>

using namespace std;

// 定义双向链表结点
struct Node {
    int data; // 数据域
    Node* prev; // 前指针域
    Node* next; // 后指针域
    Node(int x): data(x), prev(nullptr), next(nullptr) {} // 构造函数
};

// 定义快速排序函数
Node* quick_sort(Node* head, Node* tail) {
    if (head == tail || head->next == tail) return head; // 区间只有一个或零个结点时直接返回
    Node* pivot = head; // 选择基准元素为区间第一个元素
    Node* left = head; // 定义左指针
    Node* right = tail->prev; // 定义右指针
    while (left != right) { // 当左右指针不相遇时循环
        while (left != right && right->data >= pivot->data) right = right->prev; // 从右向左找到第一个小于基准元素的结点
        while (left != right && left->data <= pivot->data) left = left->next; // 从左向右找到第一个大于基准元素的结点
        if (left != right) { // 如果左右指针还没有相遇，则交换它们所指向的结点的数据
            int temp = left->data;
            left->data = right->data;
            right->data = temp;
        }
    }
    // 当左右指针相遇时，将基准元素与中间结点交换数据，并返回中间结点
    int temp = pivot->data;
    pivot->data = left->data;
    left->data = temp;
    return left;
}

// 定义带头结点的双向链表类
class List {
private:
    Node* head; // 头结点指针
public:
    List(): head(new Node(0)) {} // 构造函数，创建一个空的头结点
    ~List() { // 析构函数，释放所有结点内存
        Node* p = head;
        while (p) {
            Node* q = p->next;
            delete p;
            p = q;
        }
    }
    void insert(int x) { // 在链表尾部插入一个新结点
        Node* p = head;
        while (p->next) p = p->next; // 找到链表尾结点
        Node* q = new Node(x); // 创建一个新结点
        p->next = q; // 将新结点插入到尾部
        q->prev = p; // 更新新结点的前指针
    }
    void sort() { // 对链表进行快速排序
        quick_sort(head->next, nullptr); // 调用快速排序函数，传入头结点的后继结点和空指针作为区间
    }
    void print() { // 打印链表中的数据
        Node* p = head->next;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};
