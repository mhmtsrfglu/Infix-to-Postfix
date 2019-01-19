//Mehmet Şerefoğlu 201611688
#include "Stack.h"
#include <string.h>

int main()
{
	char str[] = "(A + B) * (C - D)";
	int i = 0;
	Stack<char> s;
	cout<<"Infix : "<<str<<endl;
	s.convertToPostfix(str);
	return 0;
}
