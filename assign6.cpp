#include <unordered_map>
#include "assign6.h"
#include "string.h"

std::unordered_map<std::string, Value> emptyEnv;

union ExprC parse(char** expression) {
	ExprC temp;
	
}

	

union Value interp(union ExprC expr, std::unordered_map<std::string, Value> Environment)
	{
		Value temp;
		if ((strcmp(expr.type, "numC"))) {
			//change temp
		}
		if ((strcmp(expr.type, "boolC"))) {
			//change temp
		}
		if ((strcmp(expr.type, "idC"))) {
			std::unordered_map<std::string, Value>::const_iterator got = Environment.find(expr.idC.symbol);
			if (got == Environment.end()) {
				printf("symbol not found in environment\n");
			}
			else
			{
				temp = got->second;
			}
		}
		if ((strcmp(expr.type, "ifC"))) {
			//change temp
		}
		if ((strcmp(expr.type, "fnC"))) {
			//chaneg temp
		}
		if ((strcmp(expr.type, "binopC"))) {
			//change temp
		}
		if ((strcmp(expr.type, "appC"))) {
			//change temp
		}
		return temp;
	}

	int main() {

	}
