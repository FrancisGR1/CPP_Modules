#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>

double rpn(const std::string &expr){
  std::istringstream iss(expr);
  std::vector<double> stack;
  std::cout << "Input\tOperation\tStack after" << std::endl;
  std::string token;
  while (iss >> token) {
    std::cout << token << "\t";
    double tokenNum;
    if (std::istringstream(token) >> tokenNum) {
      std::cout << "Push\t\t";
      stack.push_back(tokenNum);
    } else {
      std::cout << "Operate\t\t";
      double secondOperand = stack.back();
      stack.pop_back();
      double firstOperand = stack.back();
      stack.pop_back();
      if (token == "*")
	stack.push_back(firstOperand * secondOperand);
      else if (token == "/")
	stack.push_back(firstOperand / secondOperand);
      else if (token == "-")
	stack.push_back(firstOperand - secondOperand);
      else if (token == "+")
	stack.push_back(firstOperand + secondOperand);
      else if (token == "^")
	stack.push_back(std::pow(firstOperand, secondOperand));
      else { //just in case
	std::cerr << "Error" << std::endl;
	std::exit(1);
      }
    }
    std::copy(stack.begin(), stack.end(), std::ostream_iterator<double>(std::cout, " "));
    std::cout << std::endl;
  }
  return stack.back();
}

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cerr << "./a.out <RPN expr>\n";
		return 1;
	}
  std::string s = argv[1];
  std::cout << "Final answer: " << rpn(s) << std::endl;
  
  return 0;
}
