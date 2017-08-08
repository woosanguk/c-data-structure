//
// Created by sanguk on 08/08/2017.
//

#ifndef STACK_CALC_STACKCALC_H
#define STACK_CALC_STACKCALC_H

void calcExpr(ExprToken *pExprTokens, int tokenCount);

int pushExprToken(Stack *pStack, ExprToken data);

void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount);

int inStackPrecedence(Precedence oper);

int outStackPrecedence(Precedence oper);

void printToken(ExprToken element);

#endif //STACK_CALC_STACKCALC_H
