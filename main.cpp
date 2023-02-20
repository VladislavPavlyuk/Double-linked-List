#include <iostream>
#include "List.h"

using namespace std;
int main()
{
	List lst;
	char s[] = "Hello, World !!!";
	//char s[] = "abcdefghijklmnop";

	cout << s << endl;

	int len = strlen(s);
	for (int i = len - 1; i >= 0; i--)
		lst.AddHead(s[i]);
	cout << "\nFirst list\n";
	lst.PrintHead();
	List lst2 = lst;
	cout << "\nSecond list\n";
	lst2.PrintHead();
	List lst3;
	lst3 = lst;
	cout << "\nThird list\n";
	lst3.PrintHead();
	cout << "\nFirst list\n";
	lst.PrintTail();
	lst.Del(2);
	lst.PrintHead();

	lst.Insert('?', 0);
	lst.Insert('?', 4);
	lst.Insert('?', 4);
	lst.PrintHead();
	lst.DelHead();
	lst.PrintHead();
	lst.DelTail();

	lst.PrintHead();

	system("pause");
	system("cls");


	int test = 3;

	// Проверка поиска номера элемента по значению
	cout << "\nMETHOD FIND\n";

	while (test > 0) {
		// Распечатываем содержимое списка
		lst.PrintHead();

		char key;
		cout << "\nEnter value to find: ";
		cin >> key;

		if (lst.Find(key) == -1)
			cout << "\nEntered value wasn't found!\n";
		else
			cout << "\nEntered value was found at position: " << lst.Find(key) << "\n";

		system("pause");
		system("cls");
		test--;
	}

	test = 3;
	while (test > 0)
	{
		lst.PrintHead();
		cout << "\nDELETE METHOD\n";
		char key;
		cout << "\nENTER THE KEY THAT HAVE TO BE DELETED WITH: ";
		cin >> key;
		lst.DelElementByKey(key);
		lst.PrintHead();

		system("pause");
		system("cls");

		test--;
	}

	test = 3;
	lst.PrintHead();
	cout << "\nREPLACE METHOD\n";
	const char value = '$';
	int position;
	while (test > 0) {
		cout << "\nENTER THE POSITION THAT HAVE TO BE REPLACED WITH " << value << ": ";
		cin >> position;
		lst.Replace(value, position);
		lst.PrintHead();
		test--;
	}
	system("pause");
	system("cls");

	lst.PrintHead();
	cout << "\nSORTING METHOD\n";

	int pos = 1;

	lst.Sort();

	lst.PrintHead();

	system("pause");
	system("cls");

	return 0;
}
