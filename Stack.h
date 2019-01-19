//Mehmet Şerefoğlu 201611688
#ifndef _STACK_
#define _STACK_
#include <iostream>
using namespace std;
const int MAXSIZE = 1000;
template <class T>
struct Node
{
	T data;
	struct Node *next;
	Node(const T &d)
	{
		data = d;
		next = NULL;
	}
};

template <class T>
class Stack
{
  private:
	Node<T> *top;;

  public:
	Stack()
	{
		top = NULL;
	}

	int convertToPostfix(const char *str)
	{

		cout<<"Postfix : ";
		int i = 0;
		if (str != NULL)
		{
			while (str[i] != '\0')
			{ //(a+b)*c
				if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
				{
					cout << str[i];
					i++;
				}
				else if (str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/')
				{
					if (peek() == '(' || peek() == ')')
					{
						push(str[i]);
						i++;
					}
					else if (peek() == '*' || peek() == '+' || peek() == '-' || peek() == '/')
					{
						cout << peek();
						pop();
						push(str[i]);
						i++;
					}
					else
					{
						push(str[i]);
						i++;
					}
				}
				else if (str[i] == '(')
				{
					push(str[i]);
					i++;
				}
				else if (str[i] == ')')
				{
					if (peek() == '(')
					{
						pop();
						i++;
					}
					else
					{
						cout << peek();
						pop();
					}
				}else if(str[i] == ' '){
					i++;
				}
			}
			cout << peek();
			pop();
			cout << endl;
		}else{
			cout<<"Expression is NULL";
		}
	}

	Stack(const Stack<T> &rhs)
	{
		if (rhs.isEmpty())
			this->top = NULL;
		else
		{
			Node<T> *walk = rhs.top;
			top = NULL;
			Node<T> *walk2;
			while (walk != NULL)
			{
				if (top == NULL)
				{
					top = new Node<T>(walk->data);
					walk2 = top;
				}
				else
				{
					walk2->next = new Node<T>(walk->data);
					walk2 = walk2->next;
				}
				walk = walk->next;
			}
		}
	}

	const Stack<T> &operator=(const Stack<T> &rhs)
	{
		if (this != &rhs)
		{
			Node<T> *walkdel = top;
			while (walkdel != NULL)
			{
				Node<T> *t = walkdel;
				walkdel = walkdel->next;
				delete t;
			}
			top = NULL;

			Node<T> *walk = rhs.top;
			top = NULL;
			Node<T> *walk2;
			while (walk != NULL)
			{
				if (top == NULL)
				{
					top = new Node<T>(walk->data);
					walk2 = top;
				}
				else
				{
					walk2->next = new Node<T>(walk->data);
					walk2 = walk2->next;
				}
				walk = walk->next;
			}
		}
	}

	bool isEmpty() const
	{
		return top == NULL;
	}
	bool isFull() const
	{
		return false;
	}

	bool pop()
	{
		if (isEmpty()) //stack underflow
			return false;
		Node<T> *tmp = top;
		top = top->next;
		delete tmp;
		return true;
	}

	T peek() const
	{
		if (isEmpty())
			return false;
		T res = top->data;
		return res;
	}

	bool push(const T &item)
	{
		if (isFull())
			return false;
		Node<T> *newNode = new Node<T>(item);
		newNode->next = top;
		top = newNode;
	}

	void printStack() const
	{
		Node<T> *walk = top;
		cout << "Stack = ";
		while (walk != NULL)
		{
			cout << walk->data << " ";
			walk = walk->next;
		}
		cout << endl;
	}
	~Stack()
	{

		while (top != NULL)
		{
			Node<T> *t = top;
			top = top->next;
			delete t;
		}
	}
};
#endif //end of Stack.h file
