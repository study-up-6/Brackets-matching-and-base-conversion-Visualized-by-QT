#pragma once
#include <exception>

#include<QGraphicsRectItem>
#include<QGraphicsTextItem>

// 定义 stackEmpty 异常类
class stackEmpty : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "Stack is empty";
    }
};

// 链表节点的结构定义
template <class T>
struct chainNode {
    // 数据成员
    T element;
    chainNode<T>* next; // 链表区别于数组的特性

    // 方法
    chainNode() {}
    chainNode(const T& element) {
        this->element = element;
    }
    chainNode(const T& element, chainNode<T>* next) {
        this->element = element;
        this->next = next;
    }
};

// 抽象类栈
template<class T>
class stack {
public:
    virtual ~stack() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T& top() const = 0;
    virtual T pop() = 0;
    virtual void push(const T& theElement) = 0;
};

// 定制的栈
template<class T>
class linkedStack : public stack<T> {
private:
    chainNode<T>* stackTop;   // 栈顶指针
    int stackSize;   // 栈中元素的个数

public:
    linkedStack(int initialCapicity = 10) {
        stackTop = nullptr;
        stackSize = 0;
    }
    ~linkedStack();

    bool empty() const;
    int size() const;
    T& top() const;
    T pop();
    void push(const T& theElement);
    T& operator[](int index); // 添加下标操作符
    void removeAt(int index); // 添加 removeAt 方法
    void clear(); // 添加 clear 方法

};

// 实现 linkedStack 类的方法
template<class T>
linkedStack<T>::~linkedStack() {
    while (stackTop != nullptr) {
        chainNode<T>* nextNode = stackTop->next;
        delete stackTop;
        stackTop = nextNode;
    }
}

template<class T>
bool linkedStack<T>::empty() const {
    return stackSize == 0;
}

template<class T>
int linkedStack<T>::size() const {
    return stackSize;
}

template<class T>
T& linkedStack<T>::top() const {
    if (stackTop == nullptr) throw stackEmpty();
    return stackTop->element;
}

template<class T>
T linkedStack<T>::pop() {
    if (stackTop == nullptr) throw stackEmpty();
    chainNode<T>* oldTop = stackTop;
    T topElement = stackTop->element; // 获取栈顶元素
    stackTop = stackTop->next;
    delete oldTop;
    stackSize--;
    return topElement; // 返回栈顶元素
}


template<class T>
void linkedStack<T>::push(const T& theElement) {
    stackTop = new chainNode<T>(theElement, stackTop);
    stackSize++;
}

template<class T>
T& linkedStack<T>::operator[](int index) {
    if (index < 0 || index >= stackSize) throw std::out_of_range("Index out of range");
    chainNode<T>* currentNode = stackTop;
    for (int i = 0; i < index; ++i) {
        currentNode = currentNode->next;
    }
    return currentNode->element;
}

template<class T>
void linkedStack<T>::removeAt(int index) {
    if (index < 0 || index >= stackSize) throw std::out_of_range("Index out of range");
    if (index == 0) {
        pop();
        return;
    }
    chainNode<T>* currentNode = stackTop;
    for (int i = 0; i < index - 1; ++i) {
        currentNode = currentNode->next;
    }
    chainNode<T>* nodeToRemove = currentNode->next;
    currentNode->next = nodeToRemove->next;
    delete nodeToRemove;
    stackSize--;
}

template<class T>
void linkedStack<T>::clear() {
    while (!empty()) {
        pop();
    }
}
