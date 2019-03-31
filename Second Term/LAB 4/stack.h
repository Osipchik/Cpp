#ifndef STACK_H
#define STACK_H

template<typename T>
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

template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    void push_Top(T data);
    void clear();
    void pop_Top();
    T GetTop();

    void push_back(T data);//
    void pop_Head();       // только для очереди
    T GetHead();           //
    int GetSize() { return size; }

private:
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
void Stack<T>::push_back(T data)
{
    if (head == nullptr) head = new Node<T>(data);
    else
    {
        Node<T>* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
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
void Stack<T>::pop_Head()
{
    Node<T>* toDelete = head;
    //delete toDelete;
    head = head->pNext;
    delete toDelete;
    size--;
}


template<typename T>
T Stack<T>::GetTop()
{
    return Top->data;
}


template<typename T>
T Stack<T>::GetHead()
{
    return head->data;
}


#endif // STACK_H
