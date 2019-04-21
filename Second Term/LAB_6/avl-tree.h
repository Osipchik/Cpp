#ifndef AVLTREE_H
#define AVLTREE_H

#include "queue.h"
#include <QString>

template<typename T>
class AVL_Tree
{
protected:
    template<typename T1>
    class Node
    {
    public:
        int key;
        T1 data;
        unsigned char height;

        Node* Left;
        Node* Right;

        Node(int key, T1 data = T1())
        {
            this->key = key;
            this->data = data;

            Left = nullptr;
            Right = nullptr;
            height = 1;
        }
    };

protected:
    Node<T>* pRoot = nullptr;

    unsigned char height(Node<T>* pNode) { return pNode ? pNode->height : 0; }
    int balance_factor(Node<T>* pNode)   { return height(pNode->Right) - height(pNode->Left); }
    void fix_height(Node<T>* pNode);

    Node<T>* rotate_right(Node<T>* pAround_Node);
    Node<T>* rotate_left(Node<T>* pAround_Node);
    Node<T>* balance(Node<T>* pNode);

    Node<T>* insert(int key, T data, Node<T>* pNode);
    void change(int key, T newData, Node<T> *pNode);
    T GetData(int key, Node<T>* pNode);

    void GetNLR(Queue<T>& queue, Node<T>* pNode, QString prewKey);
    void GetNLR(Queue<T>& queue, Node<T>* pNode);
    void GetLNR(Queue<T>& queue, Node<T>* pNode);
    void GetLRN(Queue<T>& queue, Node<T>* pNode);

    Node<T>* find_min(Node<T>* pNode) { return pNode->Left ? find_min(pNode->Left) : pNode; }
    Node<T>* remove_min(Node<T>* pNode);
    Node<T>* remove(Node<T>* pNode, int key);

public:
    void Add(int key, T data) { pRoot = insert(key, data, pRoot); }
    void change(int key, T newData) { change(key, newData, pRoot); }

    T GetData(int key) { return GetData(key, pRoot); }
    void GetNLR(Queue<T>& queue, QString text) { GetNLR(queue, pRoot, text + ":|0"); }
    void GetNLR(Queue<T>& queue) { GetNLR(queue, pRoot); }
    void GetLNR(Queue<T>& queue) { GetLNR(queue, pRoot); }
    void GetLRN(Queue<T>& queue) { GetLRN(queue, pRoot); }

    void remove(int key) { pRoot = remove(pRoot, key); }
    int GetHeight() { return pRoot->height; }
    ~AVL_Tree();

//    friend class Tree;
};

#endif // AVLTREE_H

template<typename T>
void AVL_Tree<T>::fix_height(Node<T>* pNode)
{
    unsigned char hLeft = height(pNode->Left);
    unsigned char hRight = height(pNode->Right);
    pNode->height = (hLeft > hRight ? hLeft : hRight) + 1;
}



template<typename T>
T AVL_Tree<T>::GetData(int key, Node<T>* pNode)
{
    if (pNode == nullptr) return 0;
    if (key == pNode->key) return pNode->data;
    else if (key < pNode->key) GetData(key, pNode->Left);
    else if (key > pNode->key) GetData(key, pNode->Right);
}


template<typename T>
void AVL_Tree<T>::change(int key, T newData, Node<T> *pNode)
{
    if(key == pNode->key) pNode->data = newData;
    else if(key < pNode->key) change(key, newData, pNode->Left);
    else if(key > pNode->key) change(key, newData, pNode->Right);
}


template<typename T>
void AVL_Tree<T>::GetNLR(Queue<T>& queue, Node<T>* pNode, QString prewKey)
{
    if (pNode == nullptr) return;

    queue.push_back(QString::number(pNode->key) + "|" + pNode->data + "|" + QString::number(pNode->height) + "|" + prewKey);
    GetNLR(queue, pNode->Left,  "Left:|" + QString::number(pNode->key));
    GetNLR(queue, pNode->Right, "Right:|" +QString::number(pNode->key));
}

template<typename T>
void AVL_Tree<T>::GetNLR(Queue<T> &queue, Node<T> *pNode)
{
    if (pNode == nullptr) return;

    queue.push_back(pNode->data);
    GetLNR(queue, pNode->Left);
    GetLNR(queue, pNode->Right);
}

template<typename T>
void AVL_Tree<T>::GetLNR(Queue<T>& queue, Node<T>* pNode)
{
    if (pNode == nullptr) return;

    GetLNR(queue, pNode->Left);
    queue.push_back(pNode->data);
    GetLNR(queue, pNode->Right);
}

template<typename T>
void AVL_Tree<T>::GetLRN(Queue<T>& queue, Node<T>* pNode)
{
    if (pNode == nullptr) return;

    GetLRN(queue, pNode->Left);
    GetLRN(queue, pNode->Right);
    queue.push_back(pNode->data);
}


template<typename T>
typename AVL_Tree<T>::template Node<T>* AVL_Tree<T>::insert(int key, T data, Node<T>* pNode)
{
    if (pNode == nullptr) return new Node<T>(key, data);

    if (key < pNode->key)
    {
        pNode->Left = insert(key, data, pNode->Left);
    }
    else
    {
        pNode->Right = insert(key, data, pNode->Right);
    }
    return balance(pNode);
}


template<typename T>
typename AVL_Tree<T>::template Node<T>* AVL_Tree<T>::rotate_right(Node<T>* pAround_Node)
{
    Node<T>* pNode = pAround_Node->Left;
    pAround_Node->Left = pNode->Right;
    pNode->Right = pAround_Node;
    fix_height(pAround_Node);
    fix_height(pNode);
    return pNode;
}

template<typename T>
typename AVL_Tree<T>::template Node<T>* AVL_Tree<T>::rotate_left(Node<T>* pAround_Node)
{
    Node<T>* pNode = pAround_Node->Right;
    pAround_Node->Right = pNode->Left;
    pNode->Left = pAround_Node;
    fix_height(pAround_Node);
    fix_height(pNode);
    return pNode;
}

template<typename T>
typename AVL_Tree<T>::template Node<T>* AVL_Tree<T>::balance(Node<T>* pNode)
{
    fix_height(pNode);
    if (balance_factor(pNode) == 2)
    {
        if (balance_factor(pNode->Right) < 0)
            pNode->Right = rotate_right(pNode->Right);
        return rotate_left(pNode);
    }

    if (balance_factor(pNode) == -2)
    {
        if (balance_factor(pNode->Left) > 0)
            pNode->Left = rotate_left(pNode->Left);
        return rotate_right(pNode);
    }
    return pNode;
}


template<typename T>
typename AVL_Tree<T>::template Node<T>* AVL_Tree<T>::remove_min(Node<T>* pNode)
{
    if (pNode->Left == nullptr)
    {
        if (pNode->Right == nullptr) return nullptr;
        return pNode->Right;
    }
    pNode->Left = remove_min(pNode->Left);
    return balance(pNode);
}

template<typename T>
typename AVL_Tree<T>::template Node<T>* AVL_Tree<T>::remove(Node<T>* pNode, int key)
{
    if (pNode == nullptr) return nullptr;
    else if (key < pNode->key) pNode->Left = remove(pNode->Left, key);
    else if (key > pNode->key) pNode->Right = remove(pNode->Right, key);
    else
    {
        Node<T>* pNodeL = pNode->Left;
        Node<T>* pNodeR = pNode->Right;
        delete pNode;

        if (pNodeR == nullptr) return pNodeL;

        Node<T>* pmin = find_min(pNodeR);
        pmin->Right = remove_min(pNodeR);
        pmin->Left = pNodeL;
        return balance(pmin);
    }
    return balance(pNode);
}


template<typename T>
AVL_Tree<T>::~AVL_Tree()
{
    while (this->pRoot != nullptr)
    {
        this->pRoot = remove(this->pRoot, this->pRoot->key);
    }
}
