#include "LinkQuickSort.h"

using namespace std;

int main() {
    List list; // 创建一个空的双向链表
    list.insert(5); // 插入一些数据
    list.insert(3);
    list.insert(7);
    list.insert(2);
    list.insert(9);
    list.insert(4);
    list.insert(6);
    list.insert(8);
    list.insert(1);
    cout << "Before sorting: " << endl;
    list.print(); // 打印排序前的链表
    list.sort(); // 对链表进行快速排序
    cout << "After sorting: " << endl;
    list.print(); // 打印排序后的链表
    return 0;
}
