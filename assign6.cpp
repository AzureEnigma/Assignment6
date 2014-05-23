#include <unordered_map>

union ExprC {
	string type;
	
	struct numC {
		int num;
	};

	struct boolC {
		int boolean;
	};

	struct idC {
		string symbol;
	};

	struct ifC {
		struct ExprC condition;
		struct ExprC true;
		struct ExprC false;
	};

	struct fnC 
		//needs to be a list
		char params;
		struct ExprC body;
	};

	struct binopC {
		string op;
		struct ExprC left;
		struct ExprC right;
	};

	struct appC {
		struct ExprC body;
		//needs to be a list
		struct ExprC def;
	};
}

union Value {
	string type;
	
	struct numV {
		int num;
	};
	
	struct cloV {
		string params;
		struct ExprC body;
		unordered_map<string, struct Value> env;
	};
	
	struct boolV {
		int boolean;
	};
}

unordered_map<string, struct Value> Environment;

unordered_map<string, struct Value> empty-env;

struct Value interp(struct ExprC expr) {
	if ((strcmp(expr->type, "numC"))) {
        return 1;
    }
	if ((strcmp(expr->type, "boolC"))) {
        return 2;
    }
	if ((strcmp(expr->type, "idC"))) {
        return 3;
    }
	if ((strcmp(expr->type, "ifC"))) {
        return 4;
    }
	if ((strcmp(expr->type, "fnC"))) {
        return 5;
    }
	if ((strcmp(expr->type, "binopC"))) {
        return 6;
    }
	if ((strcmp(expr->type, "appC"))) {
        return 7;
    }
}