#include <iostream>

using namespace std;

class Test
{
public:
	int val;
	Test(int x = 0)
	{
		val = x;
	}
};

Test operator+(const Test &obj1, const Test &obj2)
{
	Test temp;
	temp.val = obj1.val + obj2.val;
	return temp;
}

Test operator+(int i, const Test &obj2)
{
	Test temp;
	temp.val = i + obj2.val;
	return temp;
}

bool operator==(const Test &obj1, const Test &obj2)
{
	return obj1.val == obj2.val;
}

bool operator<(const Test &obj1, const Test &obj2)
{
	return obj1.val < obj2.val;
}

bool operator==(int i, const Test &obj2)
{
	return i == obj2.val;
}

bool operator!=(int i, const Test &obj2)
{
	return i != obj2.val;
}

int main()
{
	cout << "Enter value of obj1 : ";
	int val;
	cin >> val;
	Test obj1(val);

	cout << "Enter value of obj2 : ";
	cin >> val;
	Test obj2(val);

	cout << "Enter value to be added to obj1 : ";
	cin >> val;
	obj1 = obj1 + val;

	cout << "Value of obj1 : " << obj1.val << "\n";

	cout << "Value of obj2 after adding obj1 and obj2 : ";
	obj2 = obj1 + obj2;
	cout << obj2.val << "\n";

	cout << "Is obj1 == obj2 : ";
	if (obj1 == obj2)
		cout << "True\n";
	else
		cout << "False\n";
	return 0;
}