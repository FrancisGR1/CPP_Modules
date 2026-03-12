#include <stdexcept>
#include <iostream>
#include <iomanip>

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& other)
	: m_output(other.m_output) {}

RPN& RPN::operator=(const RPN& other)
{
	m_output = other.m_output;
	return *this;
}

RPN::~RPN(){}

int RPN::compute(const std::string& expr)
{
	std::cout << std::left
		  << std::setw(10) << "Input"
		  << std::setw(15) << "Operation"
		  << "Stack After\n";

	for (size_t i = 0; i < expr.size(); ++i)
	{
		char c = expr.at(i);
		if (std::isspace(c))
		{
			continue;
		}
		else if (std::isdigit(c))
		{
			std::cout << std::left
				  << std::setw(10) << c
				  << std::setw(15) << "Push";
			m_output.push(c - '0');
		}
		else if (is_operator(c))
		{
			if (m_output.size() <= 1)
				throw std::runtime_error("Need at least 2 numbers in stack for operation\n");
			int rv = m_output.top();
			m_output.pop();

			int lv = m_output.top();
			m_output.pop();

			if (c == '*')
				m_output.push(lv * rv);
			if (c == '/')
			{
				if (rv == 0)
					throw std::runtime_error("Division by 0");
				m_output.push(lv / rv);
			}
			if (c == '-')
				m_output.push(lv - rv);
			if (c == '+')
				m_output.push(lv + rv);
			std::cout << std::left
				<< std::setw(10) << c
				<< std::setw(15) << c;
		}
		else
		{
			const std::string error_msg = "Unkown character: " + std::string(1, c);
			throw std::runtime_error(error_msg);
		}
		print_stack();
	}

	if (m_output.size() != 1)
		throw std::runtime_error("Invalid expression");

	return m_output.top();
};

bool RPN::has_precedence(char op1, char op2)
{
	enum Operation {OpAdd = 0, OpSub = 0, OpDiv, OpMUL};

	Operation o1;
	Operation o2;

	switch (op1)
	{
		case '+': o1 = OpAdd; break;
		case '-': o1 = OpSub; break;
		case '/': o1 = OpDiv; break;
		case '*': o1 = OpMUL; break;
	}
	switch (op2)
	{
		case '+': o2 = OpAdd; break;
		case '-': o2 = OpSub; break;
		case '/': o2 = OpDiv; break;
		case '*': o2 = OpMUL; break;
	}

	return (o1 > o2);
}

bool RPN::is_operator(char op)
{
	return (op == '+' || op == '-' || op == '/' || op == '*');
}

void RPN::print_stack()
{
	std::stack<int> tmp = m_output;

	while (!tmp.empty())
	{
		std::cout << tmp.top() << ' ';
		tmp.pop();
	}
	std::cout << "\n";
}
