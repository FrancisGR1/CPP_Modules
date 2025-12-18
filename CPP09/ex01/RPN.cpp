#include <stdexcept>
#include <iostream>

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& other)
	: m_output(other.m_output)
	, m_operators(other.m_operators) {}

RPN& RPN::operator=(const RPN& other)
{
	m_output = other.m_output;
	m_operators = other.m_operators;
	return *this;
}

RPN::~RPN(){}

int RPN::compute(const std::string& expr)
{
	for (size_t i = 0; i < expr.size(); ++i)
	{
		char c = expr.at(i);
		if (std::isspace(c))
		{
			continue;
		}
		else if (std::isdigit(c))
		{
			m_output.push(c);
		}
		else if (is_operator(c))
		{
			while (!m_operators.empty() && !has_precedence(c, m_operators.top()))
			{
				m_output.push(m_operators.top());
				m_operators.pop();

			}
			//std::cout << "pusing to op: " << c << "\n";
			m_operators.push(c);
		}
		else
		{
			const std::string error_msg = "Unkown character: " + std::string(1, c);
			throw std::runtime_error(error_msg);
		}
	}
	// flush
	while (!m_operators.empty()) 
	{
		m_output.push(m_operators.top());
		m_operators.pop();
	}

	//print output
	std::queue<char> tmp = m_output;

	while (!tmp.empty())
	{
		std::cout << tmp.front() << ' ';
		tmp.pop();
	}
	std::cout << '\n';

	// calculate result
	while (!m_output.empty())
	{
		char c = m_output.front();
		if (is_operator(c))
		{
			int lval = m_result.top();
			m_result.pop();

			int rval = m_result.top();
			m_result.pop();

			int op_result = 0;
			switch(c)
			{
				case '+': 
					op_result = lval + rval; 
					break;
				case '-': 
					op_result = lval - rval; 
					break;
				case '/': 
					op_result = lval / rval; 
					break;
				case '*': 
					op_result = lval * rval; 
					break;
			}
			std::cout << lval << " " << c << " " << rval << " = " << op_result << "\n";
			m_result.push(op_result);
		}
		else
		{
			m_result.push(c - '0');
		}
		m_output.pop();
	}
	std::cout << "Final: " << m_result.top() << "\n";
	return m_result.top();
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

	//	bool res = o1 > o2;
	//	if (res)
	//		std::cout << op1 << ">"  <<  op2 << "\n";
	//	else
	//		std::cout << op1 << "<=" <<  op2 << "\n";
	//
	return (o1 > o2);
}

bool RPN::is_operator(char op)
{
	return (op == '+' || op == '-' || op == '/' || op == '*');
}
