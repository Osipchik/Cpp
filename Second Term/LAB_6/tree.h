#ifndef TREEBRANCH_H
#define TREEBRANCH_H

#include "avl-tree.h"

template<typename T>
class Tree : public AVL_Tree<T>
{
public:
    typename AVL_Tree<T>::template Node<T>* remove_branch(typename AVL_Tree<T>::template Node<T>* pNode);
    typename AVL_Tree<T>::template Node<T>* GetBrach(int key, typename AVL_Tree<T>::template Node<T>* pNode);

public:
    void remove_branch(int key); //{ AVL_Tree<T>::pRoot = GetBrach(key, AVL_Tree<T>::pRoot); }
};

#endif // TREEBRANCH_H

template<typename T>
typename AVL_Tree<T>::template Node<T>* Tree<T>::remove_branch(typename AVL_Tree<T>::template Node<T>* pNode)
{
    if (pNode->Left == nullptr && pNode->Right == nullptr)
    {
       delete pNode;
       return nullptr;
    }
    if (pNode->Left != nullptr) pNode->Left = remove_branch(pNode->Left);
    if (pNode->Right != nullptr) pNode->Right = remove_branch(pNode->Right);
}


template<typename T>
typename AVL_Tree<T>::template Node<T>* Tree<T>::GetBrach(int key, typename AVL_Tree<T>::template Node<T>* pNode)
{
    if (key < pNode->key) pNode->Left = GetBrach(key, pNode->Left);
    else if (key > pNode->key) pNode->Right = GetBrach(key, pNode->Right);

    if (key == pNode->key)
    {
        return pNode = remove_branch(pNode);
    }
    AVL_Tree<T>::balance(pNode);
}

template<typename T>
void Tree<T>::remove_branch(int key)
{
    AVL_Tree<T>::pRoot = GetBrach(key, AVL_Tree<T>::pRoot);
    AVL_Tree<T>::remove(key);
}
