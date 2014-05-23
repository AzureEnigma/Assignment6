union ExprC {
	char* type;
	
	struct numC {
		int num;
	};

	struct bolC {
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

int interp(struct ExprC exprc) {
	if ((strcmp(exprc->type, "numC"))) {
        return 1;
    }
	if ((strcmp(exprc->type, "bolC"))) {
        return 2;
    }
	if ((strcmp(exprc->type, "idC"))) {
        return 3;
    }
	if ((strcmp(exprc->type, "ifC"))) {
        return 4;
    }
	if ((strcmp(exprc->type, "fnC"))) {
        return 5;
    }
	if ((strcmp(exprc->type, "binopC"))) {
        return 6;
    }
	if ((strcmp(exprc->type, "appC"))) {
        return 7;
    }
}