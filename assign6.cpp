#include <tr1/unordered_map>
#include "assign6.h"
#include "string.h"
#include <stdio.h>
#include <string>

using namespace std;
using namespace __gnu_cxx;

tr1::unordered_map<string, ExprC> empty_env;

struct ExprC parse(char** expression) {
	ExprC temp;
    if (strcmp(*expression, "true") == 0) {
        temp.type = (char *)calloc(1, strlen("boolC"));
        strcpy(temp.type, "boolC");
        temp.boolC.boolean = 1;
    }
    if (strcmp(*expression, "false") == 0) {
        temp.type = (char *)calloc(1, strlen("boolC"));
        strcpy(temp.type, "boolC");
        temp.boolC.boolean = 0;
    }
    if (strcmp(*expression, "if") == 0) {
        temp.type = (char *)calloc(1, strlen("ifC"));
        strcpy(temp.type, "ifC");
    }
    if (strcmp(*expression, "with") == 0) {
        temp.type = (char *)calloc(1, strlen("appC"));
        strcpy(temp.type, "appC");
    }
    if (strcmp(*expression, "fn") == 0) {
        temp.type = (char *)calloc(1, strlen("fnC"));
        strcpy(temp.type, "fnC");
    }
    if (strcmp(*expression, "fn") == 0) {
        temp.type = (char *)calloc(1, strlen("fnC"));
        strcpy(temp.type, "fnC");
        temp.fnC.params = (char *)calloc(1, strlen(expression[1]));
        memcpy(temp.fnC.params, expression[1], strlen(expression[1]));
        temp.fnC.body = (struct ExprC*) calloc(1, sizeof(struct ExprC));
        struct ExprC parsedBody = parse(&expression[2]);
        memcpy(temp.fnC.body, &parsedBody, sizeof(struct ExprC));
    } else {
        throw "not implemented";
    }
    return temp;
}

	struct Value* interp(ExprC expr)
	{
		struct Value* temp = (struct Value*) calloc(1, sizeof(struct Value));
		if (!(strcmp(expr.type, "numC"))) {
			temp->numV.num = expr.numC.num;
			temp->type = "numV";
		}
		if (!(strcmp(expr.type, "boolC"))) {
			temp->boolV.boolean = expr.boolC.boolean;
			temp->type = "boolV";
		}
		if (!(strcmp(expr.type, "idC"))) {
			/*
			hash_map<string, Value>::const_iterator got = Environment.find(expr.idC.symbol);
			if (got == Environment.end()) {
			printf("symbol not found in environment\n");
			}
			else
			{
			temp = got->second;
			}
			*/
		}
		if (!(strcmp(expr.type, "ifC"))) {
			//change temp
		}
		if (!(strcmp(expr.type, "fnC"))) {
            temp->type = "cloV";
            temp->cloV.params = expr.fnC.params;
            temp->cloV.body = expr.fnC.body;
		}
		if (!(strcmp(expr.type, "binopC"))) {
			//change temp
		}
		if (!(strcmp(expr.type, "appC"))) {
			//change temp
		}
		return temp;
	}

	int main() {
		struct ExprC temp;
		temp.numC.num = 6;
		temp.type = "numC";
		struct Value* temp2 = interp(temp);
		printf("%d\n", temp2->numV.num);

		Value test1;
		test1.type = "HA I WORK";

		tr1::unordered_map<string, Value> my_env;
		my_env["test1"] = test1;
		printf("type of test1 is %s\n", my_env["test1"].type);

		return 1;
		while (1);
	}
