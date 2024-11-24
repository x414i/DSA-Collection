#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class LinkedStack {
private:
    Node* topNode;

public:
    LinkedStack() : topNode(nullptr) {}

    void push(string value) {
        Node* newNode = new Node{ value, topNode };
        topNode = newNode;
    }

    string pop() {
        if (topNode == nullptr) {
            return "";
        }
        Node* temp = topNode;
        string Value = topNode->data;
        topNode = topNode->next;
        delete temp;
        return Value;
    }

    string top() {
        if (topNode != nullptr) {
            return topNode->data;
        }
        return "";
    }

    bool empty() {
        return topNode == nullptr;
    }
};

int p(string op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    return 0;
}

bool isChar(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

void infixToPostfix(string exp, string& result) {
    LinkedStack opt;
    string str;

    for (int i = 0; i < exp.length(); ++i) {
        if (exp[i] == ' ') {
            continue;
        }

        if (isChar(exp[i])) {
            str.clear();
            while (i < exp.length() && (isChar(exp[i]) || isDigit(exp[i]))) {
                str += exp[i++];
            }
            --i;
            result += str + " ";
        }
        else if (isDigit(exp[i])) {
            str.clear();
            while (i < exp.length() && isDigit(exp[i])) {
                str += exp[i++];
            }
            --i;
            result += str + " ";
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            str = exp[i];
            while (!opt.empty() && p(opt.top()) >= p(str)) {
                result += opt.pop() + " ";
            }
            opt.push(str);
        }
        else if (exp[i] == '(') {
            str = "(";
            opt.push(str);
        }
        else if (exp[i] == ')') {
            while (!opt.empty() && opt.top() != "(") {
                result += opt.pop() + " ";
            }
            opt.pop();
        }
    }
    while (!opt.empty()) {
        result += opt.pop() + " ";
    }
}

double eval(string postfix, string* var, double* values, int count) {
    LinkedStack stack;
    string str;

    for (int i = 0; i < postfix.length(); ++i) {
        if (postfix[i] == ' ') continue;

        str.clear();
        while (i < postfix.length() && postfix[i] != ' ') {
            str += postfix[i++];
        }

        if (isDigit(str[0])) {
            stack.push(str);
        }
        else if (isChar(str[0])) {
            bool found = false;
            double value = 0;

            for (int j = 0; j < count; ++j) {
                if (var[j] == str) {
                    value = values[j];
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Enter value for " << str << ": ";
                cin >> value;
                var[count] = str;
                values[count] = value;
                count++;
            }

            stack.push(to_string(value));
        }
        else {
            double num2 = stod(stack.pop());
            double num1 = stod(stack.pop());
            double result = 0;

            if (str == "+") result = num1 + num2;
            else if (str == "-") result = num1 - num2;
            else if (str == "*") result = num1 * num2;
            else if (str == "/") result = num1 / num2;

            stack.push(to_string(result));
        }
    }

    return stod(stack.pop());
}

int main() {
    string exp;
    string postfix;
    string var[100];
    double values[100];
    int count = 0;

    cout << "Enter infix exp: ";
    getline(cin, exp);

    infixToPostfix(exp, postfix);

    cout << "Postfix : " << postfix << endl;

    double result = eval(postfix, var, values, count);

    cout << "Result: " << result << endl;

    return 0;
}