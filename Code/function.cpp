#include "function.h"

// Writing of each Infix to Postfix Conversion functions.

// Function to return operators
bool theOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// Function to return opening brackets
bool theOpeningBracket(char c) { return (c == '{' || c == '(' || c == '['); }

// Function to return the closing brackets
bool theClosingBracket(char c) { return (c == '}' || c == ')' || c == ']'); }

// Function to return the matching bracket of the codes.
bool theMatchingBracket(char open, char close) {
  return ((open == '{' && close == '}') || (open == '(' && close == ')') ||
          (open == '[' && close == ']'));
}

// Function to return the precedence of the operators.
bool theBalancedParentheses(const string &expression) {
  stack<char> stack;
  for (char c : expression) {
    if (theOpeningBracket(c)) {
      stack.push(c);
    } else if (theClosingBracket(c)) {
      if (stack.empty() || !theMatchingBracket(stack.top(), c)) {
        return false;
      }
      stack.pop();
    }
  }
  return stack.empty();
}

string theinfixToPostfix(const string &infixExpression) {
  string postfix;
  stack<char> operators;

  for (char c : infixExpression) {
    if (isalnum(c)) {
      postfix += c;
    } else if (theOperator(c)) {
      while (!operators.empty() && operators.top() != '(' &&
             operators.top() != '{' && operators.top() != '[' &&
             (c == '+' || c == '-' ||
              (c == '*' || c == '/' || c == '%') &&
                  (operators.top() == '*' || operators.top() == '/' ||
                   operators.top() == '%'))) {
        postfix += operators.top();
        operators.pop();
      }
      operators.push(c);
    } else if (theOpeningBracket(c)) {
      operators.push(c);
    } else if (theClosingBracket(c)) {
      while (!operators.empty() && operators.top() != '(' &&
             operators.top() != '{' && operators.top() != '[') {
        postfix += operators.top();
        operators.pop();
      }
      operators.pop();
    }
  }
  while (!operators.empty()) {
    postfix += operators.top();
    operators.pop();
  }
  return postfix;
}

