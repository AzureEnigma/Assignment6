#include <tr1/unordered_map>
#include "assign6.h"
#include "string.h"
#include <stdio.h>
#include <string>
#include <malloc.h>
#include <stdlib.h>

using namespace std;
using namespace __gnu_cxx;

tr1::unordered_map<string,Value> empty_env;

struct ExprC parse(char** expression) {
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
        temp.ifC.condition = (struct ExprC*) calloc(1, sizeof(struct ExprC));
        struct ExprC parsedCond = parse(&expression[1]);
        memcpy(temp.ifC.condition, &parsedCond, sizeof(struct ExprC));
        
        temp.ifC.trueC = (struct ExprC*) calloc(1, sizeof(struct ExprC));
        struct ExprC parsedTrue = parse(&expression[2]);
        memcpy(temp.ifC.trueC, &parsedTrue, sizeof(struct ExprC));
        
        temp.ifC.falseC = (struct ExprC*) calloc(1, sizeof(struct ExprC));
        struct ExprC parsedFalse = parse(&expression[3]);
        memcpy(temp.ifC.falseC, &parsedFalse, sizeof(struct ExprC));
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

struct Value* interp(struct ExprC expr, tr1::unordered_map<string,Value> Environment) {
    struct Value* temp = (struct Value*) calloc(1, sizeof(struct Value));
    if (strcmp(expr.type, "numC") == 0) {
        temp->type = "numV";
        temp->numV.num = expr.numC.num;
    }
    if (strcmp(expr.type, "boolC") == 0) {
        temp->type = "boolV";
        temp->boolV.boolean = expr.boolC.boolean;
    }
    if (strcmp(expr.type, "idC") == 0) {
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
    if (strcmp(expr.type, "ifC") == 0) {
        struct Value* condTemp = interp(*(expr.ifC.condition), Environment);
        
        if (strcmp(condTemp->type, "boolV") != 0) {
            throw "if statement condition not a boolean";
        }
        
        if (condTemp->boolV.boolean != 0) {
            temp = interp(*(expr.ifC.trueC), Environment);
        }
        else {
            temp = interp(*(expr.ifC.falseC), Environment);
        }
    }
    if (strcmp(expr.type, "fnC") == 0) {
        temp->type = "cloV";
        temp->cloV.params = expr.fnC.params;
        temp->cloV.body = expr.fnC.body;
    }
    if (strcmp(expr.type, "binopC") == 0) {
        //change temp
    }
    if (strcmp(expr.type, "appC") == 0) {
        //change temp
    }
    return temp;
}

int main() {
    /*
     Value test1;
     test1.type = "HA I WORK";
     tr1::unordered_map<string, Value> my_env;
     my_env["test1"] = test1;
     printf("type of test1 is %s\n", my_env["test1"].type);
     */
    
    struct ExprC testC;
    struct Value* testV;
    
    //numC test
    printf("numC test...\n");
    char *numPtr[] = {"3"};
    testC = parse(numPtr);
    testV = interp(testC, empty_env);
    printf("expected output: numV 3, got: %s %d\n",testV->type, testV->numV.num);
    
    //boolC test
    printf("boolC tests...\n");
    char *boolPtr[] = {"true"};
    testC = parse(boolPtr);
    testV = interp(testC, empty_env);
    printf("expected output: boolV 1, got: %s %d\n",testV->type, testV->boolV.boolean);
    
    boolPtr = {"false"};
    testC = parse(boolPtr);
    testV = interp(testC, empty_env);
    printf("expected output: boolV 0, got: %s %d\n",testV->type, testV->boolV.boolean);
    
    //fnC test
    printf("fnC tests...\n");
    char *fnPtr[] = {"fn", "a", "3"};
    testC = parse(fnPtr);
    testV = interp(testC, empty_env);
    printf("expected output: cloV a 3, got: %s %s %d\n",
           testV->type, testV->cloV.params, testV->cloV.body->numC.num);
    
    //ifC tests
    printf("ifC tests...\n");
    char *ifTestTrue[] = {"if", "true", "2", "3"};
    testC = parse(ifTestTrue);
    testV = interp(testC, empty_env);
    printf("expected output: numV 2, got: %s %d\n",testV->type, testV->numV.num);

    char *ifTestFalse[] = {"if", "false", "2", "3"};
    testC = parse(ifTestFalse);
    testV = interp(testC, empty_env);
    printf("expected output: numV 3, got: %s %d\n",testV->type, testV->numV.num);
    
    char *ifCond[] = {">", "1", "2"};
    char *ifTrue[] = {"+", "1", "2"};
    char *ifFalse[] = {"+", "1", "1"};
    char *ifTest[] = {"if", (char*)ifCond, (char*)ifTrue, (char*)ifFalse};
    testC = parse(ifTest);
    testV = interp(testC, empty_env);
    printf("expected output: numV 2, got: %s %d\n",testV->type, testV->numV.num);
    
    char *ifTestBool[] = {"if", "true", "true", "false"};
    testC = parse(ifTestBool);
    testV = interp(testC, empty_env);
    printf("expected output: boolV true, got: %s %d\n",testV->type, testV->boolV.boolean);
    
    char *ifFn[] = {"fn", "x", "1"};
    char *ifTestClo[] = {"if", "true", (char*)ifFn, "3"};
    testC = parse(ifTestClo);
    testV = interp(testC, empty_env);
    printf("expected output: cloV x 1, got: %s %s %s\n",
           testV->type, testV->cloV.params, testV->cloV.body->numC.num);
    
    char *ifTestError[] = {"if", "1", "2", "3"};
    testC = parse(ifTestError);
    testV = interp(testC, empty_env);
    printf("expected output: error\n");
    
    
    return 1;
    while (1);
}
