#include <tr1/unordered_map>
#include "assign6.h"
#include "string.h"
#include <stdio.h>
#include <string>

using namespace std;
using namespace __gnu_cxx;

tr1::unordered_map<string, ExprC> empty_env;

struct ExprC parse(char** expression) throw(string) {
    ExprC temp;
    if (isdigit(**expression)) {
        temp.type = "numC";
        temp.numC.num = atoi(*expression);
    } else if (strcmp(*expression, "true") == 0) {
        temp.type = "boolC";
        temp.boolC.boolean = 1;
    } else if (strcmp(*expression, "false") == 0) {
        temp.type = "boolC";
        temp.boolC.boolean = 0;
    } else if (strcmp(*expression, "if") == 0) {
        temp.type = "ifC";
    } else if (strcmp(*expression, "with") == 0) {
        temp.type = "appC";
    } else if (strcmp(*expression, "fn") == 0) {
        temp.type = "fnC";
        temp.fnC.params = expression[1];
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
        
        //Nicki added everything below
        struct ExprC testC;
        struct Value* testV;
        
        //numC test
        char *numPtr[] = {"3"};
        testC = parse(numPtr);
        printf("type %s with num %d\n", testC.type, testC.numC.num);
        testV = interp(testC, empty_env);
        printf("type %s with num %d\n", testV->type, testV->numV.num);
        
        //boolC test
        char *boolPtr[] = {"true"};
        testC = parse(boolPtr);
        printf("type %s with boolean %d\n", testC.type, testC.boolC.boolean);
        testV = interp(testC, empty_env);
        printf("type %s with boolean %d\n", testV->type, testV->boolV.boolean);
        
        boolPtr = {"false"};
        testC = parse(boolPtr);
        printf("type %s with boolean %d\n", testC.type, testC.boolC.boolean);
        testV = interp(testC, empty_env);
        printf("type %s with boolean %d\n", testV->type, testV->boolV.boolean);
        
        //fnC test
        char *fnPtr[] = {"fn", "a", "3"};
        testC = parse(fnPtr);
        printf("type %s with param \"%s\" and body of type %s\n",
               testC.type, testC.fnC.params, testC.fnC.body->type);
        testV = interp(testC, empty_env);
        printf("type %s with param \"%s\" and body of type %s\n",
               testV->type, testV->cloV.params, testV->cloV.body->type);

		return 1;
		while (1);
	}
