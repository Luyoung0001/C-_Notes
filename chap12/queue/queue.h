#ifndef QUEUE_H_
#define QUEUE_H_
#include "customer.h"
#include <iostream>
typedef Customer Item;

class Queue {
  private:
    // 在类中声明结构体
    struct Node {
        Item item;
        struct Node *next;
    };
    enum { Q_SIZE = 10 };
    Node *front;
    Node *rear;
    int items;       // 队列元素数量
    const int qsize; // C++11 const 成员初始化,队列的最大长度

  public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    int queueCount() const; // 队中结点个数

    bool enQueue(const Item &item);
    bool deQueue(Item &item);
};
#endif