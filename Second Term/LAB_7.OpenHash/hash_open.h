#ifndef HASH_OPEN_H
#define HASH_OPEN_H

#include <QtMath>
#include <QString>

template<typename T>
struct HashItem
{
    bool Delited = 1;
    int Key = 0;
    int HashCode = 0;
    T Data = T();
};


template<typename T>
class Hash_Open
{
protected:
    int size;
    const long long int S = 2654435769;
    HashItem<T> *hashTable;

public:
    Hash_Open(int size);
    ~Hash_Open() { delete[] hashTable; }
    int GetHashCode(int key);
    void add(int key);
    void remove(int key);
    void clear() { delete[] hashTable; }
    QString GetItem(int key);
};


template<typename T>
Hash_Open<T>::Hash_Open(int size)
{
    this->size = size;
    hashTable = new HashItem<T>[this->size];
}


template<typename T>
int Hash_Open<T>::GetHashCode(int key)
{
    if(key < 0) key *= -1;
    return key % size;
}


template<typename T>
void Hash_Open<T>::add(int key)
{
    int code = GetHashCode(key);
    int count = code % size;

    if (hashTable[count].Delited)
    {
        hashTable[count].Delited = 0;
        hashTable[count].Key = key;
        hashTable[count].HashCode = code;
    }
    else
    {
        while (count < size)
        {
            if (hashTable[count].Delited)
            {
                hashTable[count].Delited = 0;
                hashTable[count].Key = key;
                hashTable[count].HashCode = code;
                return;
            }
            count++;
        }

        this->size *= 2;
        HashItem<T>* temp = new HashItem<T>[size];

        for (int i = 0; i < size / 2; i++)
        {
            code = GetHashCode(hashTable[count].Key);
            count = code % size;
            if (temp[count].Delited)
            {
                temp[count].Delited = 0;
                temp[count].Key = hashTable[count].Key;
                temp[count].HashCode = code;
            }
            else
            {
                while (count < size)
                {
                    if (temp[count].Delited)
                    {
                        temp[count].Delited = 0;
                        temp[count].Key = hashTable[count].Key;
                        temp[count].HashCode = code;
                        break;
                    }
                    count++;
                }
            }
        }
        code = GetHashCode(key);
        count = code % size;

        while (count < size)
        {
            if (temp[count].Delited)
            {
                temp[count].Delited = 0;
                temp[count].Key = key;
                temp[count].HashCode = code;
                break;
            }
            count++;
        }

        delete[] hashTable;
        hashTable = temp;
    }
}


template<typename T>
void Hash_Open<T>::remove(int key)
{
    int code = GetHashCode(key);
    for(int i = code%size; i < size; i++)
    {
        if(!hashTable[i].Delited && hashTable[i].Key == key)
        {
            hashTable[i].Delited = 1;
            hashTable[i].Key = 0;
        }
    }
}


template<typename T>
QString Hash_Open<T>::GetItem(int key)
{
    for (int i = 0; i < size; i++)
    {
        if (!hashTable[i].Delited && hashTable[i].Key == key) return hashTable[i].HashCode;
    }
    return T();
}


#endif // HASH_OPEN_H
