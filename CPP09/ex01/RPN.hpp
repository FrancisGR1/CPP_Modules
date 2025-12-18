#include <stack>
#include <queue>
#include <string>

class RPN
{
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int compute(const std::string& expr);

	private:
		std::queue<char> m_output;
		std::stack<char> m_operators;
		std::stack<int> m_result;

		//utils
		bool has_precedence(char op1, char op2);
		bool is_operator(char op);
};
