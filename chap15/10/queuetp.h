#ifndef QUEUETP_H_
#define QUEUETP_H_
#include <functional>
template <typename Item> class QueueTP {
  private:
    enum { Q_SIZE = 10 };
    // nested class
    class Node {
        Item item;
        Node *next;
        Node(const Item &i) : item(i), next(0) {}
    };
    Node *front;
    Node *rear;

    int items;
    const int qsize;
    QueueTP(const QueueTP &q) : qsize(0) {}
    QueueTP &operator=(const QueueTP &q) { return *this; }

  public:
    QueueTP(int qs = Q_SIZE); // constructer
    ~QueueTP();

    bool isFull() { return items == qsize; }

    bool isEmpty() { return items == 0; }

    int queuecount() { return items; }

    bool enqueue(const Item &item);
    bool dequeue(Item &item); // 由 item 返回
};
#endif