#include "queue.h"

Queue::Queue(int qs) : qsize(qs) {
    front = rear = nullptr;
    items = 0;
    // qsize = 0; invald, const 成员必须在构造函数调用前,进行初始化
}
Queue::~Queue() {
    Node *temp;
    while (front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }
}
bool Queue::isEmpty() const { return items == 0; }
bool Queue::isFull() const { return items == qsize; }

bool Queue::enQueue(const Item &item) {
    if (this->isFull()) {
        return false;
    }
    Node *add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;

    if (front == nullptr) {
        // 如果队列为空,头指向它
        front = add;
    } else {
        rear->next = add;
    }
    rear = add;
    return true;
}
bool Queue::deQueue(Item &item) {
    if (this->isEmpty()) {
        return false;
    }
    item = front->item;
    Node *temp = front;
    items--;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    return true;
}
int Queue::queueCount() const { return this->items; }