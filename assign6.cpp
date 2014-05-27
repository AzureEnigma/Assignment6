#include "assign6.h"
#include "string.h"
#include <stdio.h>
#include <malloc.h>
	

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
			//get symbol
		}
		if (!(strcmp(expr.type, "ifC"))) {
			//change temp
		}
		if (!(strcmp(expr.type, "fnC"))) {
			//chaneg temp
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
		while (1);
	}
