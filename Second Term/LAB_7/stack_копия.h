#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    // STACK
    void push_Top(T data);
    void clear();
    void pop_Top();
    T GetTop();
    int GetSize() { return size; }

private:
    template<typename T1>
    class Node
    {
    public:
        Node<T>* pNext;
        T data;
        Node(T data = T(), Node<T>* pNext = nullptr)
        {
            this->pNext = pNext;
            this->data = data;
        }
    };
    Node<T>* Top;
    Node<T>* head;
    int size;
};


template<typename T>
Stack<T>::Stack()
{
    size = 0;
    Top  = nullptr;
    head = nullptr;
}


template<typename T>
Stack<T>::~Stack()
{
    clear();
}


template<typename T>
void Stack<T>::push_Top(T data)
{
    if (Top == nullptr)	Top = new Node<T>(data);
    else Top = new Node<T>(data, Top);
    size++;
}


template<typename T>
void Stack<T>::clear()
{
    Node<T>* toDelete;
    while (Top != nullptr)
    {
        toDelete = Top;
        Top = Top->pNext;
        delete toDelete;
        size--;
    }
}


template<typename T>
void Stack<T>::pop_Top()
{
    Node<T>* toDelete = Top;
    Top = Top->pNext;
    delete toDelete;
    size--;
}

template<typename T>
T Stack<T>::GetTop()
{
    if(size) return Top->data;
    return 0;
}


#endif // STACK_H
