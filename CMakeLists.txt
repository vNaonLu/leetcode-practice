cmake_minimum_required(VERSION 3.0.0)
project(leetcode VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(leetcode 
  src/main.cpp
  src/solution.h
  src/0010_RegularExpressionMatching/source.cpp
  src/0022_GenerateParenthesis/source.cpp
  src/0032_LongestValidParentheses/source.cpp
  src/0042_TrappingRainWater/source.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
