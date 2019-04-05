#ifndef DL_LIST_H
#define DL_LIST_H

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
class dlList
{
public:
    dlList();
    ~dlList();

    void push_back(T data);
    void push_front(T data);
    void pop_front();
    void pop_back();
    void remove(int index);
    void clear();
    int GetSize() { return size; }

    T GetData(int index);
    T GetBack();
    T GetFront();

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};

#endif // DL_LIST_H

template<typename T>
dlList<T>::dlList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<typename T>
dlList<T>::~dlList()
{
    clear();
}

template<typename T>
void dlList<T>::push_back(T data)
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
void dlList<T>::push_front(T data)
{
    Node<T>* temp = head;
    head = new Node<T>(data, head);
    temp->pPrev = head;
    size++;
}

template<typename T>
void dlList<T>::pop_front()
{
    Node<T>* toDelete = head;
    head = head->pNext;
    if(head) head->pPrev = nullptr;
    delete toDelete;
    size--;
}

template<typename T>
void dlList<T>::pop_back()
{
    Node<T>* toDelete = tail;
    tail = tail->pPrev;
    if (tail) tail->pNext = nullptr;
    delete toDelete;
    size--;
}

template<typename T>
void dlList<T>::remove(int index)
{
    if (index == 0) pop_front();
    else if (index == size - 1) pop_back();
    else
    {
        if (index > (size - 1) / 2)
        {
            Node<T>* next = tail;
            for (int i = size - 1; i > index + 1; i--)
            {
                next = next->pPrev;
            }
            Node<T>* toDelete = next->pPrev;
            next->pPrev = toDelete->pPrev;
            Node<T>* temp = toDelete->pPrev;
            temp->pNext = toDelete->pNext;
            delete toDelete;
        }
        else
        {
            Node<T>* previous = head;
            for (int i = 0; i < index - 1; i++)
            {
                previous = previous->pNext;
            }
            Node<T>* toDelete = previous->pNext;
            previous->pNext = toDelete->pNext;
            Node<T>* prev = toDelete->pNext;
            prev->pPrev = toDelete->pPrev;
            delete toDelete;
        }
        size--;
    }
}

template<typename T>
void dlList<T>::clear()
{
    while (size)
    {
        pop_front();
    }
}

template<typename T>
T dlList<T>::GetData(int index)
{
    if (index > size / 2)
    {
        int count = size - 1;
        Node<T>* search = tail;

        while (search->pPrev != nullptr)
        {
            if (count == index) break;
            search = search->pPrev;
            count--;
        }
        return search->data;
    }
    else
    {
        int count = 0;
        Node<T>* search = head;

        while (search->pNext != nullptr)
        {
            if (count == index) break;
            search = search->pNext;
            count++;
        }
        return search->data;
    }
}

template<typename T>
T dlList<T>::GetBack()
{
    return tail->data;
}

template<typename T>
T dlList<T>::GetFront()
{
    return head->data;
}
