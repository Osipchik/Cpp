#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Node
{
public:
    Node<T>* pNext;
    Node<T>* pPrev;
    T data;

    Node(T data = T(), Node<T>* pNext = nullptr, Node<T>* pPrev = nullptr)
    {
        this->data = data;
        this->pNext = pNext;
        this->pPrev = pPrev;
    }
};

template<typename T>
class Queue
{
public:
    Queue();
    ~Queue();

    void push_back(T data);
    void pop_front();
    void clear();
    int GetSize() { return size; }
    T GetFront();

protected:
    Node<T>* head;
    Node<T>* tail;
    int size;
};

#endif // QUEUE_H

template<typename T>
Queue<T>::Queue()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<typename T>
Queue<T>::~Queue()
{
    clear();
}

template<typename T>
void Queue<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
        tail = head;
    }
    else
    {
        Node<T>* current = tail;
        tail = new Node<T>(data, nullptr, tail);
        current->pNext = tail;
    }
    size++;
}


template<typename T>
void Queue<T>::pop_front()
{
    Node<T>* toDelete = head;
    head = head->pNext;
    if(head) head->pPrev = nullptr;
    delete toDelete;
    size--;
}


template<typename T>
void Queue<T>::clear()
{
    while (size)
    {
        pop_front();
    }
}


template<typename T>
T Queue<T>::GetFront()
{
    return head->data;
}
