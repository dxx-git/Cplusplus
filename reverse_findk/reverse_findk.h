#include<iostream>
#include<cassert>
using namespace std;

struct Node
{
	Node(int data)
	:_data(data)
	, _next(NULL)
	{}

	int _data;
	Node* _next;
};

class List
{
public:
	List()
	:_head(NULL)
	{}
	void PushBack(const int data)
	{
		if (NULL == _head)
		{
			_head = new Node(data);
		}
		else
		{
			Node* cur = _head;
			while (cur->_next)
			{
				cur = cur->_next;
			}
			cur->_next = new Node(data);
		}
	}
	int Size()
	{
		if (NULL == _head)
			return 0;

		int count = 0;
		Node* cur = _head;
		while (cur)
		{
			++count;
			cur = cur->_next;
		}
		return count;
	}
	bool Empty()
	{
		return _head == NULL;
	}
	void Print()
	{
		if (NULL == _head)
			cout << "list empty" << endl;
		else
		{
			Node* cur = _head;
			while (cur)
			{
				cout << cur->_data << "-->";
				cur = cur->_next;
			}
			cout << "null" << endl;
		}
	}
	void Reverse()
	{
		if (NULL == _head || NULL == _head->_next)
			return;
		
		Node* prev = NULL;
		Node* cur = _head;
		Node* next = NULL;
		while (cur)
		{
			next = cur->_next;
			cur->_next = prev;
			prev = cur;
			cur = next;
		}
		_head = prev;
	}
	Node* Reverse_k(int k)
	{
		assert(k > 0);
		Node* fast = _head;
		Node* slow = _head;
		while (fast && --k)//注意判断链表是否走到头了
		{
			fast = fast->_next;
		}
		while (fast->_next)
		{
			slow = slow->_next;
			fast = fast->_next;
		}
		return slow;
	}
private:
	Node* _head;
};

int Add(int n1, int n2)
{
	while (n2 != 0)
	{
		int tmp1 = n1 ^ n2;//异或,得到不同的位
		int tmp2 = (n1 & n2) << 1;//按位与之后左移一位，得到所有的进位
		n1 = tmp1;
		n2 = tmp2;
	}
	return n1;
}

void Test()
{
	List l1;
	for (int i = 0; i < 10; ++i)
	{
		l1.PushBack(i);
	}
	l1.Print();
	l1.Reverse();
	l1.Print();
	l1.Reverse();
	int ret = l1.Reverse_k(2)->_data;
	cout << ret << endl;

	int n1, n2;
	cout << "enter two numbers:";
	cin >> n1 >> n2;
	cout << n1 << "+" << n2 << "=" << Add(n1, n2) << endl;
}