//
// Created by sanguk on 08/08/2017.
//

#ifndef STACK_CALC_EXPRDEF_H
#define STACK_CALC_EXPRDEF_H

typedef enum PrecedenceType {
    lparen,
    rparen,
    times,
    divide,
    plus,
    minus,
    operand
} Precedence;

typedef struct ExprTokenType {
    float value;
    Precedence type;
} ExprToken;

#endif //STACK_CALC_EXPRDEF_H
