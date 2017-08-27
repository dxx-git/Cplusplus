/*#include <iostream>
using namespace std;
#include <assert.h>

#define DataType int

struct Node
{
	//Node(const DataType& data = 0);
	Node* _pNext;
	Node* _pPre;
	DataType _data;
};

class List
{
public:
	List()
		:_size(0)
		,_pHead(NULL)
		,_pTail(NULL)
	{}
	List(DataType arr[], size_t size)
	:_pHead(NULL)
	,_pTail(NULL)
	,_size(0)
	{
		size_t i = 0;
		for(i=0; i<_size; i++)
		{
			PushBack(arr[i]);
		}
	}
	List(const List& l)
	:_size(0)
	,_pHead(NULL)
	,_pTail(NULL)
	{
		Node* temp = _pHead;
		_pHead->_pPre = NULL;
		Node* CurNode = l._pHead;
		while(CurNode)
		{
			temp = CurNode;
			CurNode = CurNode->_pNext;
			temp = temp->_pNext;
			_size++;
		}
		temp->_pNext = NULL;
	}
	List& operator=(const List& l)
	{
		if(this != &l)
		{
			Node* temp = _pHead;
			_pHead->_pPre = NULL;
			Node* CurNode = l._pHead;
			while(CurNode)
			{
				temp = CurNode;
				CurNode = CurNode->_pNext;
				temp = temp->_pNext;
				_size++;
			}
			temp->_pNext = NULL;
	    }
	}
	~List()
	{
		if(NULL != this)
		{
			Clear();
		}
	}

	void PushBack(const DataType& data);
	void PopBack();
	void PushFront(const DataType& data);
	void PopFront();
	bool Empty()const;
	Node* Find(const DataType& data)const;
	void Insert(Node* pos, const DataType& data);
	void Erase(Node* pos);
	void Remove(const DataType& data);
	size_t Size()const;
	void Clear();
	Node& Front();
	const Node& Front()const;
	Node& Back();
	Node& Back()const;
private:
	Node* BuyNode(const DataType &data)
	{
		Node *NewNode = new Node;
		NewNode->_data = data;
		return NewNode;
	}
	friend ostream& operator<<(ostream& _cout, const List& l)
	{
		Node* pCur = l._pHead;
		while(pCur)
		{
			_cout<<pCur->_data<<"<-->";
			pCur = pCur->_pNext;
		}
		_cout<<"end";
		return _cout;
	}

private:
	size_t _size;
	Node* _pHead;
	Node* _pTail;
};


void List::PushBack(const DataType& data)
{
	if(_size == 0)//链表为空
	{
		_pHead = _pTail = BuyNode(data);
		_pHead->_pPre = NULL;
		_pTail->_pNext = NULL;
	}
	else//链表不为空
	{
		Node* temp = BuyNode(data);
		Node* CurNode = _pHead;
		while(CurNode->_pNext)
		{
			CurNode = CurNode->_pNext;
		}
		temp->_pPre = CurNode;
		CurNode->_pNext = temp;
		temp->_pNext = NULL;

		_pTail = temp;
	}
	_size++;
}
void List::PopBack()
{
	if(_size == 0)//链表为空
	{
		assert(false);
		return;
	}
	else if(_size == 1)//链表仅有一个节点
	{
		Node* pDel = _pTail;
		delete pDel;
		_pHead = _pTail = NULL;
		_size--;
	}
	else//有多个节点
	{
		Node* pDel = _pTail;
		_pTail = _pTail->_pPre;
        _pTail->_pNext = NULL;
		delete pDel;
		_size--;
	}
}
void List::PushFront(const DataType& data)
{
	if(_size == 0)//链表为空
	{
		_pHead = BuyNode(data);
		_pTail = _pHead;
		_pHead->_pPre = NULL;
		_pTail->_pNext = NULL;
	}
	else//链表不为空
	{
		Node* temp = BuyNode(data);
		temp->_pNext = _pHead;
		_pHead->_pPre = temp;
		_pHead = temp; 
	}
	_size++;
}
void List::PopFront()
{
	if(_size == 0)
	{
		assert(false);
		return;
	}
	else if(_size == 1)
	{
		Node* pDel = _pHead;
		delete pDel;
		_pHead = _pTail = NULL;
		_size--;
	}
	else
	{
		Node* pDel = _pHead;
		_pHead = _pHead->_pNext;
		_pHead->_pPre = NULL;
		delete pDel;
		_size--;
	}
}
bool List::Empty()const
{
	return _size==0;
}
Node* List::Find(const DataType& data)const
{
	Node* pCur = _pHead;
	while(pCur)
	{
		if(pCur->_data == data)
			return pCur;
		else
			pCur = pCur->_pNext;
	}
	return pCur;
}
void List::Insert(Node* pos, const DataType& data)//插入到pos之前
{
	if(pos == _pHead)
	{
		PushFront(data);
	}
	else
	{
		Node* pCur = _pHead;
		while(pCur->_pNext != pos)
		{
			pCur = pCur->_pNext;
		}
		Node* temp = BuyNode(data);
		pCur->_pNext = temp;
		pos->_pPre = temp;
		temp->_pPre = pCur;
		temp->_pNext = pos;
	}
	_size++;
}
//void List::Insert(Node* pos, const DataType& data)//插入到pos之后
//{
//	if(pos == _pTail)
//	{
//		PushBack(data);
//	}
//	else
//	{
//		Node* pCur = _pHead;
//		while(pCur != pos->_pNext)
//		{
//			pCur = pCur->_pNext;
//		}
//		Node* temp = BuyNode(data);
//		pCur->_pPre = temp;
//		pos->_pNext = temp;
//		temp->_pPre = pos;
//		temp->_pNext = pCur;
//	}
//	_size++;
//}
void List::Erase(Node* pos)
{
	if(pos == _pHead)
	{
		PopFront();
	}
	else if(pos == _pTail)
	{
		PopBack();
	}
	else
	{
		Node* pDel = _pHead; 
		Node* pPre = _pHead;
		while(pDel != pos)
		{
			pPre = pDel;
			pDel = pDel->_pNext;
		}
		pPre->_pNext = pDel->_pNext;
		pos->_pNext->_pPre = pPre;
		delete pDel;
	}
	_size--;
}
void List::Remove(const DataType& data)//删除第一个值为data的数据
{
	Erase(Find(data));
}
size_t List::Size()const
{
	return _size;
}
void List::Clear()
{
	if(_size == 0)
	{
		return;
	}
	else
	{
		Node* pDel = _pHead;
		Node* pCur = _pHead->_pNext;
		while(pCur->_pNext)
		{
			pCur = pCur->_pNext;
			pDel = pCur->_pPre;
			delete pDel;
		}
		delete pCur;
		_pTail = NULL;
		pDel = _pHead;
		delete pDel;
		_pHead = NULL;
		_size = 0;
	}
}
Node& List::Front()
{
	assert(Empty());
	return *_pHead;
}
const Node& List::Front()const
{
	assert(Empty());
	return *_pHead;
}
Node& List::Back()
{
	assert(Empty());
	return *_pTail;
}
Node& List::Back()const
{
	assert(Empty());
	return *_pTail;
}
int main()
{
	List l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	cout<<l1<<endl;
	l1.PopBack();
	cout<<l1<<endl;
	l1.PopBack();
	cout<<l1<<endl;
	l1.PopBack();
	cout<<l1<<endl;
	l1.PopBack();
	cout<<l1<<endl;


	List l1;
	l1.PushFront(5);
	cout<<l1<<endl;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	cout<<l1<<endl;
	l1.PushFront(4);
	cout<<l1<<endl;
	Node* ret = l1.Find(4);
	ret = l1.Find(2);
	l1.Erase(ret);
	cout<<l1<<endl;
	l1.Insert(ret,6);
	cout<<l1<<endl;
	ret = l1.Find(3);
	ret = l1.Find(6);
	l1.PopFront();
	cout<<l1<<endl;
	l1.PopFront();
	l1.PopFront();
	l1.PopFront();
	cout<<l1<<endl;
	l1.PopFront();
	l1.Clear();
	cout<<l1<<endl;

	List l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(1);
	l1.PushBack(1);
    l1.Remove(1);
	cout<<l1<<endl;
	system("pause");
	return 0;
}
*/
