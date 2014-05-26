
	union ExprC {
		char* type;
		struct numC;
		struct boolC;
		struct ifC;
		struct appC;
		struct idC;
		struct appC;
		struct binopC;
	};

	union Value {
		char* type;
		struct numV;
		struct cloV;
		struct boolV;
	};

	struct numC {
		int num;
	};

	struct boolC {
		int boolean;
	};

	struct idC {
		char* symbol;
	};

	struct ifC {
		union ExprC condition;
		union ExprC trueC;
		union ExprC falseC;
	};

	struct fnC {
		//needs to be a list
		char params;
		union ExprC body;
	};

	struct binopC {
		char* op;
		union ExprC left;
		union ExprC right;
	};

	struct appC {
		union ExprC body;
		//needs to be a list
		union ExprC def;
	};

	struct numV {
		int num;
	};

	struct cloV {
		//needs to be a list
		char* params;
		union ExprC body;
	};

	struct boolV {
		int boolean;
	};

