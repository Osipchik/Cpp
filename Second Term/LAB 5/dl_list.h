#ifndef DL_LIST_H
#define DL_LIST_H

#include "queue.h"

template<typename T>
class DL_List : public Queue<T>
{
public:
    void push_front(T data);
    void pop_back();
    void remove(int index);
    T GetData(int index);
    T GetBack();
};


template<typename T>
void DL_List<T>::push_front(T data)
{
    typename Queue<T>::template Node<T>* temp = Queue<T>::head;
    Queue<T>::head = new typename Queue<T>::template Node<T>(data, Queue<T>::head);
    temp->pPrev = Queue<T>::head;
    Queue<T>::size++;
}



template<typename T>
void DL_List<T>::pop_back()
{
    typename Queue<T>::template Node<T>* toDelete = Queue<T>::tail;
    Queue<T>::tail = Queue<T>::tail->pPrev;
    if (Queue<T>::tail) Queue<T>::tail->pNext = nullptr;
    delete toDelete;
    Queue<T>::size--;
}

template<typename T>

void DL_List<T>::remove(int index)
{
    if (index == 0) Queue<T>::pop_front();
    else if (index == Queue<T>::size - 1) pop_back();
    else
    {
        if (index > (Queue<T>::size - 1) / 2)
        {
            typename Queue<T>::template Node<T>* next = Queue<T>::tail;
            for (int i = Queue<T>::size - 1; i > index + 1; i--)
            {
                next = next->pPrev;
            }
            typename Queue<T>::template Node<T>* toDelete = next->pPrev;
            next->pPrev = toDelete->pPrev;
            typename Queue<T>::template Node<T>* temp = toDelete->pPrev;
            temp->pNext = toDelete->pNext;
            delete toDelete;
        }
        else
        {
            typename Queue<T>::template Node<T>* previous = Queue<T>::head;
            for (int i = 0; i < index - 1; i++)
            {
                previous = previous->pNext;
            }
            typename Queue<T>::template Node<T>* toDelete = previous->pNext;
            previous->pNext = toDelete->pNext;
            typename Queue<T>::template Node<T>* prev = toDelete->pNext;
            prev->pPrev = toDelete->pPrev;
            delete toDelete;
        }
        Queue<T>::size--;
    }
}


template<typename T>
T DL_List<T>::GetData(int index)
{
    if (index > Queue<T>::size / 2)
    {
        int count = Queue<T>::size - 1;
        typename Queue<T>::template Node<T>* search = Queue<T>::tail;

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
        typename Queue<T>::template Node<T>* search = Queue<T>::head;

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
T DL_List<T>::GetBack()
{
    return Queue<T>::tail->data;
}

#endif // DL_LIST_H
