#include "../solution.h"

bool Solution::isMatch(std::string statement, std::string pattern){
  if(pattern.empty()) return statement.empty();
  bool matchFirst = !statement.empty() &&
                    (statement[0] == pattern[0] || pattern[0] == '.');
  return (pattern.size() >= 2 && pattern[1] == '*' ? 
         (Solution::isMatch(statement, pattern.substr(2)) || (matchFirst && isMatch(statement.substr(1), pattern))) : 
         (matchFirst && Solution::isMatch(statement.substr(1), pattern.substr(1))));
}

void Solution::_0010_solveRegularExpressionMatching(){
  std::cout << "Given an input \"statement\" and a \"pattern\", implement regular expression matching with support for '.' and '*'." << std::endl;
  std::cout << "Constraints:" << std::endl;
  std::cout << "  0 <= statement.length <= 20" << std::endl;
  std::cout << "  0 <= pattern.length <= 30" << std::endl;
  std::cout << "  statement contains only lowercase English letters." << std::endl;
  std::cout << "  pattern contains only lowercase English letters, \".\", and \"*\"." << std::endl;
  std::string statement;
  std::string pattern;
  std::cout << "statement: ";
  std::cin >> statement;
  std::cout << "pattern: ";
  std::cin >> pattern;
  std::cout << (Solution::isMatch(statement, pattern) ? "True" : "False");
}