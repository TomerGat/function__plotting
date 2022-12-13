#include "desmos.h"

//class function implementations
graph::graph(graph_data dat) : data{ dat } {
	this->create_graph();
}

void graph::create_graph() {
	static int depth = 0; //increment after each recursive call
	//handling first quadrant
	int x = 0;
	while (x != 10) {
		int y;
		y = int(data.a * std::pow(x, data.n) + data.b * x + data.c);
		first_quadrant.mat[x][y]->defined = true;
		x++;
	}
}

void graph::print_graph() {

}

//implementations of helper functions
std::string remove_spaces(const std::string& str) {
	std::string s(str);
	int j = 0;
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		if (s[i] != ' ') {
			s[j] = s[i];
			j++;
		}
	}

	s.resize(j);
	return s;
}

token_type check_type(const char ch) {
	token_type type;
	type = token_type::none;
	int ascii = int(ch);
	if (47 < ascii && ascii < 58) {
		type = token_type::number;
	}
	else if (ch == 'x' || ch == 'y') {
		type = token_type::variable;
	}
	else {
		if ((ch == '=') || (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '(') || (ch == ')')) {
			type = token_type::op;
		}

	}
	return type;
}

op_type check_opType(const char ch) {
	op_type optype = op_type::none;
	if (ch == '=') { optype = op_type::equal; }
	else if (ch == '+') { optype = op_type::plus; }
	else if (ch == '-') { optype = op_type::minus; }
	else if (ch == '*') { optype = op_type::multiply; }
	else if (ch == '/') { optype = op_type::divide; }
	else if (ch == '(') { optype = op_type::par_open; }
	else if (ch == ')') { optype = op_type::par_close; }
	return optype;
}

std::string return_type(const token_type& tk) {
	switch (tk) {
	case token_type::number:
		return "number";
	case token_type::variable:
		return "variable";
	case token_type::op:
		return "operator";
	}
	return "none";
}

//implementations for expression manipulation functions
std::vector<token> tokenize(const std::string expression) {  //receives expression and returnes vector of tokens
	std::vector<token> tokens = {};
	return tokens; //develop
}

std::vector<token> organize(std::vector<token> tokens) { //receives vector of tokens and organizes it into y=ax^n+bx+c
	return tokens; //develop
}

graph_data extract_data(std::vector<token> tokens) {
	graph_data data = {};
	return data;
}

//main - driver function
int main() {
	std::string input;
	std::getline(std::cin, input);
	graph plot = graph(extract_data(organize(tokenize(remove_spaces(input)))));
	plot.print_graph();
}
