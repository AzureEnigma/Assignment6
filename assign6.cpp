union ExprC {
	char* type;
	
	struct numC {
		int num;
	};

	struct boolC {
		int boolean;
	};

	struct idC {
		char symbol;
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
	}

	struct binopC {
		char operator;
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
	char* type;
	
	struct numV {
		int num;
	}
	
	struct cloV {
		char params;
		struct ExprC body;
		//env
	}
	
	struct boolV {
		int boolean;
	}
}

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