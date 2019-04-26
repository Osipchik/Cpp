#ifndef HASH_H
#define HASH_H

#include <QtMath>

#include "Stack.h"

template<typename T>
struct HashItem
{
    int key;
    T data = T();
};


template<typename T>
class Hash
{
public:
//    struct HashItem
//    {
//        int key;
//        T data = T();
//    };

    Stack<HashItem<T>> *array;
    int size;
    const long long int S = 2654435769;

public:
    Hash(int size);
    ~Hash() { delete[] array; }
    void add(T key);
    void remove(int key);
    void cear() { delete[] array; }
    int GetHashCode(int key);
    int GetSizeItem(int item) { return array[item].GetSize(); }
    T GetItem(int key);
};

#endif // HASH_H

template<typename T>
Hash<T>::Hash(int size)
{
    this->size = size;
    this->array = new Stack<HashItem<T>>[size];
}

template<typename T>
int Hash<T>::GetHashCode(int key)
{
    int p = log2(size);
    if(pow(2, p) < size) p++;
    long long int rez = key * S;
    return rez>>=(32-p);
}

template<typename T>
T Hash<T>::GetItem(int key)
{
    int code = GetHashCode(key);
    for(int i = 0; i < size; i++)
    {
        if(array[i].GetSize() && array[i].GetTop().key == code) return array[i].GetTop().key;
    }
    return T();
}

template<typename T>
void Hash<T>::add(T key)
{
    int code = GetHashCode(key);

    for(int i = 0; i < size; i++)
    {
        if(array[i].GetSize())
        {
            if(array[i].GetTop().key == code)
            {
                HashItem<T> newItem;
                newItem.key = code;
                array[i].push_Top(newItem);
                break;
            }
        }
        else
        {
            HashItem<T> newItem;
            newItem.key = code;
            array[i].push_Top(newItem);
            break;
        }
    }
}

template<typename T>
void Hash<T>::remove(int key)
{
    int code = GetHashCode(key);
    for(int i = 0; i < size; i++)
    {
        if(array[i].GetSize() && array[i].GetTop().key == code) array[i].pop_Top();
    }
}

