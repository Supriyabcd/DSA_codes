#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class StringStack{
    private:
        vector<string> data;
    public:
        void push(string& str){
            data.push_back(str);
        }

        void pop(){
            if (!data.empty()){
                data.pop_back();
            }
        }

        string top() const {
            if (!data.empty()){
                return data.back();
            }
            return "";
        }

        bool empty() const{
            return data.empty();
        }
};
class ExpressionConversion{
    private: 
        stack<int> stack;

    public:
        bool isOperator(char c){
            return (!isalpha(c) && !isdigit(c));
        }

        int precedence(char c){
            if (c == '+' || c == '-') return 1;
            if (c == '*' || c == '/') return 2;
            if (c == '^') return 3;
            return 0;
        }

        string infixToPostfix(const string &infix); 
        //use stack and observe the precedence of operators and parentheses 
        string infixToPrefix(const string &infix); 
        //reverse the infix expression, convert it to postfix, and then reverse the result to get prefix
        string prefixToPostfix(const string &prefix);
        //traverese backwards, use stack and observe the precedence of operators 
        //reverse the prefix expression, convert it to postfix, and then reverse the result to get infix
        string postfixToPrefix(const string &postfix);
        string prefixToInfix(const string &prefix);
        //traverse backwards and use stack and observe the precedence of operators 
        string postfixToInfix(const string &postfix);
};

string ExpressionConversion::infixToPostfix(const string &infix){
    vector<char> stack;
    string postfix;

    for (char ch : infix){
        if(isalpha(ch) || isdigit(ch)){
            postfix += ch;
        } else if (ch == '(') {
            stack.push_back(ch);
        } else if (ch ==')'){
            while (!stack.empty() && stack.back() != '('){
                postfix += stack.back();
                stack.pop_back();
            }
            stack.pop_back();
        } else {
            while (!stack.empty() && precedence(stack.back()) >= precedence(ch)) 
            // here "stack is implemented as vector<char>" so back() = top()
            {
                postfix += stack.back();
                stack.pop_back();
            }
                stack.push_back(ch);
            
        }
    }

    while(!stack.empty()){
        postfix += stack.back();
        stack.pop_back();
    }
    return postfix;
}

string ExpressionConversion::infixToPrefix(const string &infix){
    vector<char> stack;
    string prefix;
    string reversedInfix = infix;
    reverse(reversedInfix.begin(),reversedInfix.end());

    for(char &ch : reversedInfix){
        if(ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    string postfix = infixToPostfix(reversedInfix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

string ExpressionConversion::prefixToPostfix(const string &prefix){
    StringStack stack;
    for (auto it = prefix.rbegin(); it != prefix.rend(); ++it){ // traverse backwards
        char ch = *it;
        if (isalpha(ch) || isdigit(ch)){
            string s(1, ch);
            stack.push(s);
        } else {
            string op1 = stack.top(); stack.pop();
            string op2 = stack.top(); stack.pop();
            string expr = op1 + op2 + ch;
            stack.push(expr);
        }
    }
    return stack.top();
}

string ExpressionConversion::postfixToPrefix(const string &postfix){
    StringStack stack;
  
    for (char ch : postfix)
    {
        if (isalpha(ch)||isdigit(ch)){
           stack.push(string(1,ch)); 
        } else {
            string op1 = stack.top(); stack.pop();
            string op2 = stack.top(); stack.pop();
            // note the order of op1 and op2 for prefix
            string expr = ch + op2 + op1;
            stack.push(expr);
        }
    }
    return stack.top();
}

string ExpressionConversion::postfixToInfix(const string &postfix){
    vector<string> stack;
    for (char ch : postfix) {
        if (isalpha(ch) || isdigit(ch)) {
            stack.push_back(string(1, ch));
        } else {
            string op1 = stack.back(); stack.pop_back();
            string op2 = stack.back(); stack.pop_back();
            string expr = "(" + op2 + ch + op1 + ")"; // note the order of op2 and op1 for infix
            stack.push_back(expr);
        }
    }
    return stack.back(); //same as stack.top()    
}

string ExpressionConversion::prefixToInfix(const string &prefix){
    vector<string> stack;
    for (auto it = prefix.rbegin(); it != prefix.rend(); ++it) { //traverse backwards
        char ch = *it;
        if (isalpha(ch) || isdigit(ch)) {
            stack.push_back(string(1, ch));
        } else {
            string op1 = stack.back(); stack.pop_back();
            string op2 = stack.back(); stack.pop_back();
            string expr = "(" + op1 + ch + op2 + ")";
            stack.push_back(expr);
        }
    }
    return stack.back(); //same as stack.top()
}

int main()
{
    ExpressionConversion Exp;
    int choice;
    string expression;

    while (true)
    {
        cout <<"\nExpression Conversion Menu:" << endl;
        cout << "1. Infix to Postfix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Postfix to Prefix\n";
        cout << "4. Prefix to Postfix\n";
        cout << "5. Postfix to Infix\n";
        cout << "6. Prefix to Infix\n";
        cout << "0. Exit\n";
    
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0 ){
            cout << "Exiting..." << endl;
            exit(0);
        }

        cout << "Enter expression: ";
        cin >> expression;

        switch(choice){
            case 1: cout << "Infix to Postfix : " << Exp.infixToPostfix(expression) << endl;
                break;
            case 2: cout << "Infix to Prefix : " << Exp.infixToPrefix(expression) << endl;
                break;
            case 3: cout << "Postfix to Prefix : "<< Exp.postfixToInfix(expression) << endl;
                break;
            case 4: cout << "Prefix to Postfix : "<< Exp.prefixToPostfix(expression) << endl;
                break;
            case 5: cout << "Postfix to Infix : "<<Exp.postfixToInfix(expression) << endl;
                break;
            case 6: cout << "Prefix to Infix : "<< Exp.prefixToInfix(expression) << endl;
                break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}