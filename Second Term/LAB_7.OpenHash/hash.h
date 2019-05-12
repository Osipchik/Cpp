#ifndef HASH_H
#define HASH_H

#include <QString>
#include <iostream>


template<typename T>
class Hash
{
    const int SIMPLE[11] = {13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    struct HTable
    {
        bool deleted = 1;
        int key = 0;
    };

    int size;
    HTable *table = nullptr;
    void resize();

public:
    Hash();
    ~Hash() { delete[] table; }

    int GetHashCode(int key, int i);
    int GetSize() { return size; }

    void add(int key, T data = T());
    void remove(int key);
    T GetItem(int key);
    QString all();
    void removeMinus();
};

#endif // HASH_H


template<typename T>
Hash<T>::Hash()
{
    size = SIMPLE[0];
    table = new HTable[size];
}


template<typename T>
int Hash<T>::GetHashCode(int key, int i)
{
    if(key < 0) key *= (-1);
    int h1 = key % size;
    int h2 = 1 + key % (size - 2);
    return (h1 + i * h2) % size;
}

template<typename T>
void Hash<T>::add(int key, T data)
{
    int h = 0;
    for(int i = 0; i < size; i++)
    {
        h = GetHashCode(key, i);
        if(h >= size) return;
        if(!table[h].deleted) continue;
        table[h].key = key;
        table[h].deleted = 0;
        return;
    }
    if(size == 53) return;
    resize();
    add(key, data);
}

template<typename T>
void Hash<T>::remove(int key)
{
    int h = 0;
    for(int i = 0; i < size; i++)
    {
        h = GetHashCode(key, i);
        if(h >= size) return;
        if(table[h].deleted == 0 && table[h].key == key)
        {
            table[h].key = 0;
            table[h].deleted = 1;
            break;
        }
    }
}

template<typename T>
T Hash<T>::GetItem(int key)
{
    int h = 0;
    for(int i = 0; i < size; i++)
    {
        h = GetHashCode(key, i);
        if(h >= size) return;
        if(table[h].deleted == 0 && table[h].key == key) return table[h].key;
    }
    return T();
}

template<typename T>
QString Hash<T>::all()
{
    QString str = "";
    for(int i = 0; i < size; i++)
    {
        if(!table[i].deleted) str += "\ni: " + QString::number(i) + "\tkey: " + QString::number(table[i].key);
    }
    return str;
}

template<typename T>
void Hash<T>::removeMinus()
{
    for(int i = 0; i < size; i++)
    {
        if(table[i].key < 0)
        {
            remove(table[i].key);
        }
    }
}

template<typename T>
void Hash<T>::resize()
{
    int oldSize = size;
    if(size == 53) return;

    HTable temp[oldSize];
    for(int i = 0; i < oldSize; i++)
    {
        temp[i].key = table[i].key;
    }

    for(int i = 0; i < 11; i++)
    {
        if(size < SIMPLE[i])
        {
            size = SIMPLE[i];
            break;
        }
    }

    delete[] table;
    table = new HTable[size];

    for(int i = 0; i < oldSize; i++)
    {
        add(temp[i].key, i);
    }
}
