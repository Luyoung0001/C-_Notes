#ifndef STACKTP_H_
#define STACKTP_H_
template <class Type> class Stack {
  private:
    enum { MAX = 10 };
    Type items[MAX];
    int top;

  public:
    Stack();
    bool isEmpty();
    bool isFull();
    bool push(const Type &item);
    bool pop(Type &item);
};
// 由于模板不是函数，它们不能单独编译。模板必须与特定的模板实例化请求一起使用。
// 不能将模板成员函数放在独立的实现文件中

// 这是一个 "空栈",即当前栈指针指向 空白
template <class Type> Stack<Type>::Stack() { top = 0; }
template <class Type> bool Stack<Type>::isEmpty() { return top == 0; }
template <class Type> bool Stack<Type>::isFull() { return top == MAX; }
template <class Type> bool Stack<Type>::push(const Type &item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    }
    return false;
}
template <class Type> bool Stack<Type>::pop(Type &item) {
    if (top > 0) {
        item = items[--top];
        return true;
    }
    return false;
}

#endif
