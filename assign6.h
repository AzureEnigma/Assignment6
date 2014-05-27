#include <unordered_map>

union ExprC {};

union Value{}; 

struct idC {
	char* symbol;
};

struct numC {
	int num;
} numC;

struct boolC {
	int boolean;
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

	typedef union ExprC {
		char* type;
		struct numC numC;
		struct boolC boolC;
		struct ifC ifC;
		struct appC appC;
		struct idC idC;
		struct binopC binopC;
	};

	typedef union Value {
		char* type;
		struct numV numV;
		struct cloV cloV;
		struct boolV boolV;
	};

