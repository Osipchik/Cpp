//---------------------------------------------------------------------------

#ifndef myListH
#define myListH
//---------------------------------------------------------------------------

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data);
	void push_front(T data);
	void insert(const int index, T data);
	void clear();
	void pop_front();
	void pop_back();
	void remove(int index);
	int GetSize() { return Size; };

	T& operator[] (const int index);

private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = NULL)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
};

#endif
