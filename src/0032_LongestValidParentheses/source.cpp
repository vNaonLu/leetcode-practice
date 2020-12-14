#include "../solution.h"
#include <algorithm>
#include <stack>

int Solution::longestValidParentheses(std::string parenthesisString){
  int result = 0;
  int begin = 0;
  std::stack<int> parenthesisStack;
  for (int i = 0; i < parenthesisString.size(); i++){
    if(parenthesisString[i] == '('){
      parenthesisStack.push(i);
    }else if(parenthesisString[i] == ')'){
      if(parenthesisStack.empty()){
        begin = i + 1;
      } else {
        parenthesisStack.pop();
        result = parenthesisStack.empty() ? std::max(result, i - begin + 1) : std::max(result, i - parenthesisStack.top());
      }
    }
  }
    return result;
}

void Solution::_0032_solveLongestValidParentheses(){
  std::cout << "Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring." << std::endl;
  std::cout << "Constraints:" << std::endl;
  std::cout << "  0 <= s.length <= 3 * 10^4" << std::endl;
  std::cout << "  s[i] is '(', or ')'" << std::endl;
  std::string parenthesisString;
  std::cout << "s = ";
  std::cin >> parenthesisString;
  std::cout << Solution::longestValidParentheses(parenthesisString);
}