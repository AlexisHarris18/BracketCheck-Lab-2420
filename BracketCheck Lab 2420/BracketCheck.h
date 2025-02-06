#pragma once
#include <stack>
#include <iostream>
#include <string>

class BracketCheck {
	public:
		std::string expression;
		BracketCheck(std::string exp) : expression(exp){}
		int numBrackets();
		bool isBalanced();
		bool bracketCheckTest(int count);
		friend std::ostream& operator<<(std::ostream&, const BracketCheck&);

};

bool BracketCheck::bracketCheckTest(int count) {
	std::stack<char> myList;
		for (char c : expression) {
			if (c == '[' || c == '{' || c == '(') {
				myList.push(c);
			}
			else if (c == ')' || c == ']' || c == '}'){
				if (myList.empty()) {
					return false;
				}
				else if (c == ']' && !myList.empty() && myList.top() == '[' || c == ')' && !myList.empty() && myList.top() == '(' || c == '}' && !myList.empty() && myList.top() == '{') {
					myList.pop();
					count++;
				}
				else {
					return false;
				}
			}
		}
		return myList.empty();

}

int BracketCheck::numBrackets() {
	int count = 0;
	this->bracketCheckTest(count);
	return count;

}

bool BracketCheck::isBalanced() {
	int count = 0;
	return bracketCheckTest(count);
}


std::ostream& operator<<(std::ostream& out, BracketCheck& b) {
	int count = 0;
	if (!b.bracketCheckTest(count)) {
		out << "Not Balanced";
	}
	else {
		out << "Balanced";
	}
	return out;
}
