#include "../solution.h"
#include "algorithm"

int Solution::trap(std::vector<int> &height){
  if(height.size() == 0) return 0;
  int trapValue = 0;
  int arraySize = height.size();
  std::vector<int> waterHeight(arraySize, 0);
  for (int i = 0; i < arraySize; i++)
    waterHeight[i] = std::max(
      i == 0 ? 0 : waterHeight[i - 1], 
      height[i]
      );
  for (int i = arraySize - 1; i > -1; i--)
    waterHeight[i] = std::min(
      std::max(i == arraySize - 1 ? 0 : waterHeight[i + 1], height[i]), 
      waterHeight[i]
    );
  for (int i = 0; i < arraySize; i++)
    trapValue += std::max(0, waterHeight[i] - height[i]);
  return trapValue;
}

void Solution::_0042_solveTrappingRainWater(){
  int size = 0;
  std::vector<int> height{4, 2, 0, 3, 2, 5};
  std::cout << "Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining." << std::endl;
  std::cout << "Constraints:" << std::endl;
  std::cout << "  n == height.length" << std::endl;
  std::cout << "  0 <= n <= 3 * 10^4" << std::endl;
  std::cout << "  0 <= height[i] <= 10^5" << std::endl;
  std::cout << "n = ";
  std::cin >> size;
  std::cout << "height = ";
  for (int i = 0; i < size; i++)
    std::cin >> height[i];
  std::cout << Solution::trap(height);
}