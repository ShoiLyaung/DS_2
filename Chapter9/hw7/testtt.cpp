#include <iostream>

// 双向链表节点的结构定义
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// 创建新节点
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// 交换两个节点的指针
void swap(Node* node1, Node* node2) {
    if (node1 == node2) {
        return;
    }

    // 交换节点的前向指针
    Node* temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;

    // 交换节点的后向指针
    temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    // 更新相邻节点的指针
    if (node1->prev != nullptr) {
        node1->prev->next = node1;
    }
    if (node1->next != nullptr) {
        node1->next->prev = node1;
    }
    if (node2->prev != nullptr) {
        node2->prev->next = node2;
    }
    if (node2->next != nullptr) {
        node2->next->prev = node2;
    }
}

// 根据基准元素进行分割
Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data <= pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(i, j);
        }
    }

    i = (i == nullptr) ? low : i->next;
    swap(i, high);
    return i;
}



// 快速排序算法
void quickSort(Node* low, Node* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node* pivot = partition(low, high);
        quickSort(low, pivot->prev);
        quickSort(pivot->next, high);
    }
}

// 打印链表
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// 主函数
int main() {
    // 创建示例链表
    Node* head = createNode(3);
    head->next = createNode(9);
    head->next->prev = head;
    head->next->next = createNode(2);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(1);
    head->next->next->next->prev = head->next->next;

    std::cout << "原始链表: ";
    printList(head);

        // 对链表进行快速排序
    Node* lastNode = head;
    while (lastNode->next != nullptr) {
        lastNode = lastNode->next;
    }
    quickSort(head, lastNode);

    std::cout << "排序后链表: ";
    printList(head);

    // 释放链表节点的内存
    Node* currNode = head;
    while (currNode != nullptr) {
        Node* nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

    return 0;
}
