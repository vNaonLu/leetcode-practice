#include "../solution.h"
#include <deque>

struct parenthesis{
  std::string expression;
  int openParenthesisCount;
  int closeParenthesisCount;
};

std::vector<std::string> Solution::generateParenthesis(int parenthesisCount){
  std::deque<parenthesis> resultObjs = {{"(", 1, 0}};
  while (resultObjs.front().openParenthesisCount < parenthesisCount ||
         resultObjs.front().closeParenthesisCount < parenthesisCount){
    auto parenthesisObj = resultObjs.front();
    std::string currentExpression = parenthesisObj.expression;
    resultObjs.pop_front();
    if(parenthesisObj.openParenthesisCount < parenthesisCount){
      resultObjs.push_back({
        currentExpression+"(", 
        parenthesisObj.openParenthesisCount+1, 
        parenthesisObj.closeParenthesisCount
      });
    }
    if(parenthesisObj.closeParenthesisCount < parenthesisCount && 
      parenthesisObj.closeParenthesisCount < parenthesisObj.openParenthesisCount){
      resultObjs.push_back({
        currentExpression+")", 
        parenthesisObj.openParenthesisCount, 
        parenthesisObj.closeParenthesisCount+1
      });
    }
  }
  std::vector<std::string> returnValue;
  for(auto parenthesisObj : resultObjs)
    returnValue.push_back(parenthesisObj.expression);
  return returnValue;
}

void Solution::_0022_solveGenerateParenthesis(int parenthesisCount){
  auto answer = Solution::generateParenthesis(parenthesisCount);
  for(auto expression : answer)
    std::cout << expression << std::endl;
}