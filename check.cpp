#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position): type(type), position(position)
	{}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);

    stack <Bracket> open;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
		Bracket tmp(next, position+1);
            	open.push(tmp);
        }

        if (next == ')' || next == ']' || next == '}') {
		if(open.empty()){
			cout<<position+1<<endl;
			return 0;
		}
            	Bracket tmp (open.top().type, open.top().position);
		if(!tmp.Matchc(next)) {
			cout<<(position+1)<<endl;
			return 0;
		}
		open.pop();
        }
    }
    if(open.empty())
	    cout<<"Success\n";
    else {
	    int ans;
	    while(!open.empty()) {
		    ans=open.top().position;
		    open.pop();
	    }
	    cout<<ans<<endl;
    }
    return 0;
}
