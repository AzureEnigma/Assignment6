#include <tr1/unordered_map>
#include "assign6.h"
#include "string.h"
#include <stdio.h>
#include <string>

using namespace std;
using namespace __gnu_cxx;

tr1::unordered_map<string,ExprC> empty_env;

struct ExprC parse(char** expression) {
    ExprC temp;
    
}

struct Value interp(struct ExprC expr, tr1::unordered_map<string,ExprC> Environment)
{
    Value temp;
    if ((strcmp(expr.type, "numC"))) {
        //change temp
    }
    if ((strcmp(expr.type, "boolC"))) {
        //change temp
    }
    if ((strcmp(expr.type, "idC"))) {
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
    if ((strcmp(expr.type, "ifC"))) {
        //change temp
    }
    if ((strcmp(expr.type, "fnC"))) {
        //chaneg temp
    }
    if ((strcmp(expr.type, "binopC"))) {
        //change temp
    }
    if ((strcmp(expr.type, "appC"))) {
        //change temp
    }
    return temp;
}

int main() {
    Value test1;
    test1.type = "HA I WORK";
    
    tr1::unordered_map<string,Value> my_env;
    my_env["test1"] = test1;
    printf("type of test1 is %s\n", my_env["test1"].type);
    
    return 1;
}


