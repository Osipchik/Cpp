#ifndef HASH_H
#define HASH_H

#include <QtMath>

#include "Stack.h"

template<typename T>
struct HashItem
{
    int key;
    int hashCode;
    T data = T();
};


template<typename T>
class Hash
{
public:
    Stack<HashItem<T>> *array;
    int size;
    const long long int S = 2654435769;

public:
    Hash(int size);
    ~Hash() { delete[] array; }
    void add(T key);
    void remove(int key);
    void clear() { delete[] array; }
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

//    if(key < 0) key *= -1;
//    return key%10;
}

template<typename T>
T Hash<T>::GetItem(int key)
{
    int code = GetHashCode(key);
    T toRet = T();
    for(int i = 0; i < size; i++)
    {
        if(array[i].GetSize() && array[i].GetTop().hashCode == code)
        {
            Stack<HashItem<T>> copy;
            while(array[i].GetSize())
            {
                if(array[i].GetTop().key == key)
                {
                    toRet = array[i].GetTop().key;
                    break;
                }
                copy.push_Top(array[i].GetTop());
                array[i].pop_Top();
            }
            while(copy.GetSize())
            {
                array[i].push_Top(copy.GetTop());
                copy.pop_Top();
            }
            return toRet;
        }
    }
    return 1000;
}

template<typename T>
void Hash<T>::add(T key)
{
    int code = GetHashCode(key);

    for(int i = 0; i < size; i++)
    {
        if(array[i].GetSize())
        {
            if(array[i].GetTop().hashCode == code)
            {
                HashItem<T> newItem;
                newItem.key = key;
                newItem.hashCode = code;
                array[i].push_Top(newItem);
                break;
            }
        }
        else
        {
            HashItem<T> newItem;
            newItem.key = key;
            newItem.hashCode = code;
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
        if(array[i].GetSize() && array[i].GetTop().hashCode == code)
        {
            Stack<HashItem<T>> copy;
            while(array[i].GetSize())
            {
                if(array[i].GetTop().key == key)
                {
                    array[i].pop_Top();
                    while(copy.GetSize())
                    {
                        array[i].push_Top(copy.GetTop());
                        copy.pop_Top();
                    }
                    return;
                }
                copy.push_Top(array[i].GetTop());
                array[i].pop_Top();
            }
            while(copy.GetSize())
            {
                array[i].push_Top(copy.GetTop());
                copy.pop_Top();
            }
        }
    }
}

