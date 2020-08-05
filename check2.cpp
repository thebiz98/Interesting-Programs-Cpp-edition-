#include<bits/stdc++.h>

using namespace std;

struct bracket {
	bracket (char t, int pos): type(t), pos(pos) {}
	bracket () {}
	bool match(char c) {
		if((type == '[' && c == ']') || (type == '{' && c == '}') || (type == '(' && c == ')')) 
			return true;
		return false;
	}

	char type;
	int pos;
};

template <typename T>
struct node{
	T data;
	node *next;
};

template <typename T>
class Stack {
	node<T> *head;
	
	public:
		Stack() {
			head = NULL;
		}
       		void push(T data);
		T top();
		bool isEmpty();
		void pop();
};

template <typename T>
void Stack<T>::push(T item) {
	node<T> *tmp = new node<T>;
	tmp->data = item;
	tmp->next = head;
	head = tmp;
}

template <typename T>
T Stack<T>::top() {
	return head->data;
}

template <typename T>
bool Stack<T>::isEmpty() {
	if(head==NULL)
		return true;
	return false;
}

template <typename T>
void Stack<T>::pop() {
	if(isEmpty()) {
		cout<<"Cannot pop an empty stack";
		return ;
	}
	node<T> *tmp = head;
	head = head->next;
	delete tmp;
}

int main() {
	string code;
	getline(cin,code);
	Stack<bracket> open;
	for(int i=0;i<code.length();i++) {
		char next = code[i];
		if(next == '[' || next == '{' || next == '(') {
			bracket tmp(next, i+1);
			open.push(tmp);
		}
		if(next == ']' || next == '}' || next == ')') {
			if(open.isEmpty()) {
				cout<<i+1<<endl;
				return 0;
			}
			if(!open.top().match(next)) {
				cout<<i+1<<endl;
				return 0;
			}
			open.pop();
		}
	}
	if(!open.isEmpty()) {
		int ans;
		while(!open.isEmpty()) {
			ans=open.top().pos;
			open.pop();
		}
		cout<<ans<<endl;
	}
	else
		cout<<"Success\n";
	return 0;
}
