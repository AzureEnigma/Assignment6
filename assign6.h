struct ExprC;

struct Value;

struct idC {
	char* symbol;
};

struct numC {
	int num;
};

struct boolC {
	int boolean;
};


struct ifC {
	struct ExprC* condition;
	struct ExprC* trueC;
	struct ExprC* falseC;
};

struct fnC {
	//needs to be a list
	char params;
	struct ExprC* body;
};

struct binopC {
	char* op;
	struct ExprC* left;
	struct ExprC* right;
};

struct appC {
	struct ExprC* body;
	//needs to be a list
	struct ExprC* def;
};

struct numV {
	int num;
};

struct cloV {
	//needs to be a list
	char* params;
	struct ExprC* body;
};

struct boolV {
	int boolean;
};

	struct ExprC {
		char* type;
		struct numC numC;
		struct boolC boolC;
		struct ifC ifC;
		struct appC appC;
		struct idC idC;
		struct binopC binopC;
		struct fnC fnC;
	};

	struct Value {
		char* type;
		struct numV numV;
		struct cloV cloV;
		struct boolV boolV;
	};

