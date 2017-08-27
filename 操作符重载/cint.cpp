#include <iostream>
using namespace std;

class CInt
{
	friend ostream& operator<<(ostream& _cout, const CInt& I);
	friend istream& operator>>(istream& _cin, CInt& I);
public:
	CInt& operator=(const CInt& I);
	CInt operator+(const CInt& I);
	CInt operator-(const CInt& I);
	CInt operator*(const CInt& I);
	CInt operator/(const CInt& I);
	bool operator==(const CInt& I);
	bool operator!=(const CInt& I);
	bool operator>(const CInt& I);
	bool operator<(const CInt& I);
	bool operator>=(const CInt& I);
	bool operator<=(const CInt& I);
	bool operator||(const CInt& I);
	bool operator&&(const CInt& I);
	CInt& operator++();
	CInt operator++(int);
	CInt& operator--();
	CInt operator--(int);

private:
	int _value;
};

ostream& operator<<(ostream& _cout, const CInt& I)
{
	_cout<<I._value;
	return _cout;
}
istream& operator>>(istream& _cin, CInt& I)
{
	_cin>>I._value;
	return _cin;
}
CInt& CInt::operator=(const CInt& I)
{
	if(this != &I)
	{
		this->_value = I._value;
	}
	return *this;
}
CInt CInt::operator+(const CInt& I)
{
	CInt ret;
	ret._value = I._value + _value;
	return ret;
}
CInt CInt::operator-(const CInt& I)
{	
	CInt ret;
	ret._value = I._value - _value;
	return ret;
}
CInt CInt::operator*(const CInt& I)
{
	CInt ret;
	ret._value = I._value * _value;
	return ret;
}
CInt CInt::operator/(const CInt& I)
{
	if(I._value == 0)
	{
		return I;
	}
	else
	{
		CInt ret;
		ret._value = I._value / _value;
		return ret;
	}
}
bool CInt::operator==(const CInt& I)
{
	if(_value == I._value)
		return true;
	else
		return false;
}
bool CInt::operator!=(const CInt& I)
{
	if(_value != I._value)
		return true;
	else
		return false;
}
bool CInt::operator>(const CInt& I)
{
	if(_value > I._value)
		return true;
	else
		return false;
}
bool CInt::operator<(const CInt& I)
{
	if(_value < I._value)
		return true;
	else
		return false;
}
bool CInt::operator>=(const CInt& I)
{
	if(_value >= I._value)
		return true;
	else
		return false;
}
bool CInt::operator<=(const CInt& I)
{
	if(_value <= I._value)
		return true;
	else
		return false;
}
bool CInt::operator||(const CInt& I)
{
	if(_value)
		return true;
	else
	{
		if(I._value)
			return true;
		else
			return false;
	}
}
bool CInt::operator&&(const CInt& I)
{
	if(!_value)
		return false;
	else
	{
		if(I._value)
			return true;
		else
			return false;
	}
}
CInt& CInt::operator++()
{
	_value++;
	return *this;
}
CInt CInt::operator++(int)
{
	CInt ret(*this);
	_value = _value+1;
	return ret;
}
CInt& CInt::operator--()
{
	_value--;
	return *this;
}
CInt CInt::operator--(int)
{
	CInt ret(*this);
	_value = _value-1;
	return ret;
}

void Funtest()
{
	CInt a;
	cin>>a;
	cout<<a<<endl;
	
	/*CInt c;
	CInt c1;
	cin>>c>>c1;
	c = c1-c;
	cout<<c<<endl;

	bool b;
	b = c>c1;
	cout<<b<<endl;*/
	
	CInt a1;
	a1 = a++;
	cout<<a1<<endl;
}
int main()
{
	Funtest();
	system("pause");
	return 0;
}
