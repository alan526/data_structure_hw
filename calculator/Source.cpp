#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void trans(string in,char post[80]);
int priority(char symbol);
double evaluate(char post[80]);
double calculate(char sym, double num1, double num2);

int main() {
	string infix;
	char postfix[80] = { '\0' };
	double answer;
	cout << "輸入運算式(範圍<10) => ";
	cin >> infix;
	trans(infix, postfix);
	cout << "postfix => " << postfix << endl;
	answer = evaluate(postfix);
	cout << "運算結果 => " << answer;
	system("pause");
	return(0);

}

void trans(string in,char post[80]) {
	char stack[80] = { '\0' };
	int j = 0, top = 0;
	for (int i = 0; i < in.length(); i++) {
		switch (in[i]) {
		case'(':
				stack[++top] = in[i];
			break;
		case'+': case'-': case'*': case'/': case'^': case'%':
			if (top == 0) {
				stack[++top] = in[i];
			}
			else {
				while (priority(in[i]) <= priority(stack[top])) {
					post[j++] = stack[top--];
				}
					stack[++top] = in[i];
			}
			break;
		case')':
			while (stack[top] != '(') {
				post[j++] = stack[top--];
			}
			top--;
			break;
		default:
			post[j++] = in[i];

		}
	}
	while (top > 0) {
		post[j++] = stack[top--];
	}
}

double evaluate(char post[80]) {
	double stack[10];
	int top = 0;
	for (int i = 0; post[i] != '\0'; i++) {
		string toDouble;
		switch (post[i]) {
		case'+': case'-': case'*': case'/': case'^': case'%':
			stack[top - 1] = calculate(post[i], stack[top - 1], stack[top]);
			top--;
			break;
		default:
			if (post[i + 1] == '.') {
				toDouble = post[i];
				toDouble += post[i + 1];
				toDouble += post[i + 2];
				stack[++top] = stod(toDouble);
				i = i + 2;
			}
			else {
				toDouble = post[i];
				stack[++top] = stod(toDouble);
			}
		}
	}
	return(stack[top]);
}
double calculate(char sym, double num1, double num2) {
	int n1, n2;
	switch (sym)
	{
	case'+':
		return(num1 + num2);
	case'-':
		return(num1 - num2);
	case'*':
		return(num1*num2);
	case'/':
		return(num1 / num2);
	case'^':
		return(pow(num1, num2));
	case'%':
		n1 = num1 * 10;
		n2 = num2 * 10;
		return(n1%n2/10);
	default:
		break;
	}
}

int priority(char symbol) {
	switch (symbol) {
	case'+':
		return(1);
	case'-':
		return(1);
	case'*':
		return(2);
	case'/':
		return(2);
	case'%':
		return(2);
	case'^':
		return(3);
	default:
		return(0);

	}
}