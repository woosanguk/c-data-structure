#include <stdio.h>
#include <stdlib.h>
#include "exprdef.h"
#include "exprstack.h"
#include "stackcalc.h"

int main() {

    int i = 0;

    // 2 3 4 + 5 * -
    ExprToken *pExprTokens = (ExprToken *) malloc(sizeof(ExprToken) * 7);
    pExprTokens[0].type = operand;
    pExprTokens[0].value = 2;
    pExprTokens[1].type = operand;
    pExprTokens[1].value = 3;
    pExprTokens[2].type = operand;
    pExprTokens[2].value = 4;
    pExprTokens[3].type = plus;
    pExprTokens[3].value = 0;
    pExprTokens[4].type = operand;
    pExprTokens[4].value = 5;
    pExprTokens[5].type = times;
    pExprTokens[5].value = 0;
    pExprTokens[6].type = minus;
    pExprTokens[6].value = 0;

    printf("Expression: 2 3 4 + 5 * -\n");

    calcExpr(pExprTokens, 7);

    free(pExprTokens);

    // 2 - (3 + 4 ) * 5
    pExprTokens = (ExprToken *) malloc(sizeof(ExprToken) * 9);
    pExprTokens[0].type = operand;
    pExprTokens[0].value = 2;
    pExprTokens[1].type = minus;
    pExprTokens[1].value = 0;
    pExprTokens[2].type = lparen;
    pExprTokens[2].value = 0;
    pExprTokens[3].type = operand;
    pExprTokens[3].value = 3;
    pExprTokens[4].type = plus;
    pExprTokens[4].value = 0;
    pExprTokens[5].type = operand;
    pExprTokens[5].value = 4;
    pExprTokens[6].type = rparen;
    pExprTokens[6].value = 0;
    pExprTokens[7].type = times;
    pExprTokens[7].value = 0;
    pExprTokens[8].type = operand;
    pExprTokens[8].value = 5;

    printf("Infix Expression: 2 - (3 + 4 ) * 5\n");
    printf("Postfix Expression: \n");

    convertInfixToPostfix(pExprTokens, 9);

    free(pExprTokens);

    return 0;
}