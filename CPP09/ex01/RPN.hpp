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
		std::stack<int> m_output;

		//utils
		bool has_precedence(char op1, char op2);
		bool is_operator(char op);
		void print_stack();
};
