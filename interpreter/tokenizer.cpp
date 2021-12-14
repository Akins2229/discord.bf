#include <iostream>
#include <exception>

//define tokens

#define ADD_PTR = 0
#define SUBT_PTR = 1
#define ADD_CELL = 2
#define SUBT_CELL = 3
#define PUT_PTR = 4
#define GET_INPUT = 5
#define LBRACK = 6
#define RBRACK = 7
#define START_FUNC = 8
#define END_FUNC = 9
#define DECL_VAR = 10
#define CALL_VAR = 11
#define NEWLINE = 12

class invalidtoken : public exception
{
	virtual const std::str msg(std::string token, int line, int character_number) const throw()
	{
		return "An invalid token '" + token + "' has appeared at line " + std::to_string(line) + " character "+ std::to_string(character_number) + "." + std::edl;;
	}
} invalidtokenexception;

//300,000 maximum tokens per one interpretation
int [300000] tokenize(std::string data)
{
	int tokens[data.size()];
	int n = -1;
	int line = 1;
	for (std::string::size_type i = 0; i < data.size(); i++)
	{
		switch (data[i])
		{
		case "+":
			line++;
			tokens[n++] = ADD_PTR;
			n = -1;
		case "-":
			tokens[n++] = SUBT_PTR;
		case ">":
			tokens[n++] = ADD_CELL;
		case "<":
			tokens[n++] = SUBT_CELL;
		case ".":
			tokens[n++] = PUT_PTR;
		case ",":
			tokens[n++] = GET_INPUT;
		case "[":
			tokens[n++] = LBRACK;
		case "]":
			tokens[n++] = RBRACK;
		case "$":
			tokens[n++] = START_FUNC;
		case "?":
			tokens[n++] = END_FUNC;
		case "!":
			tokens[n++] = DECL_VAR;
		case ":":
			tokens[n++] = CALL_VAR;
		case "\n":
			tokens[n++] = NEWLINE;
		default:
			try {
				throw invalidtokenexception;
			} catch(exception& e) {
				std::cout << e.msg(data[i], line, n) << std::endl;
			}
		}
	}

}
