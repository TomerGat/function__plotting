#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

struct graph_data;
struct token;
enum class token_type;
enum class op_type;
struct matrix;
const int QUADRANT_SIZE = 10;

struct matrix {
	matrix* mat[QUADRANT_SIZE][QUADRANT_SIZE];
	float min;
	float max; 
	bool defined; //is the function defined somewhere in this matrix
	bool defined_here; //function is defined exactly in this location
};

struct graph_data { //y = ax^n + bx + c
	double a;
	double b;
	double c;
	int n;
};

class graph {
public:
	matrix first_quadrant;
	matrix second_quadrant;
	matrix third_quadrant;
	matrix fourth_quadrant;
	graph(graph_data dat);
	void create_graph();
	void print_graph();
private:
	graph_data data;
};

struct token {
	token_type tType;
	op_type oType;
	union data {
		char var;
		char op;
		int num;
	};
};

enum class token_type {
	variable,
	number,
	op,
	none
};

enum class op_type {
	equal,
	plus,
	minus,
	multiply,
	divide,
	par_open,
	par_close,
	none
};

graph_data extract_data(std::vector<token> tokens);
std::string remove_spaces(const std::string& str);
token_type check_type(const char ch);
op_type check_opType(const char ch);
std::string return_type(const token_type& tk);
std::vector<token> organize(std::vector<token> tokens);
std::vector<token> tokenize(const std::string expression);
