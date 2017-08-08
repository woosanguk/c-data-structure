//
// Created by sanguk on 08/08/2017.
//

#include "exprdef.h"
#include "exprstack.h"
#include "stackcalc.h"
#include <stdio.h>
#include <stdlib.h>

void calcExpr(ExprToken *pExprTokens, int tokenCount) {
    int i = 0;
    Stack *pStack = NULL;
    StackNode *pNode1 = NULL, *pNode2 = NULL;
    Precedence tokenType;
    if (pExprTokens == NULL) return;
    pStack = createStack();
    if (pStack == NULL) return;
    for (i = 0; i < tokenCount; i++) {
        tokenType = pExprTokens[i].type;
        if (tokenType == operand) {
            pushExprToken(pStack, pExprTokens[i]);
        } else {
            pNode2 = pop(pStack);
            if (pNode2 != NULL) {
                pNode1 = pop(pStack);
                if (pNode1 != NULL) {
                    float op1 = pNode1->data.value;
                    float op2 = pNode2->data.value;
                    ExprToken newToken;
                    newToken.type = operand;
                    switch (tokenType) {
                        case plus:
                            newToken.value = op1 + op2;
                            break;
                        case minus:
                            newToken.value = op1 - op2;
                            break;
                        case times:
                            newToken.value = op1 * op2;
                            break;
                        case divide:
                            newToken.value = op1 / op2;
                            break;
                    }
                    pushExprToken(pStack, newToken);
                    free(pNode1);
                }
                free(pNode2);
            }
        }
    }
    pNode1 = pop(pStack);
    if (pNode1 != NULL) {
        printf("answer : [%f] \n", pNode1->data.value);
        free(pNode1);
    }
    deleteStack(pStack);
}

int pushExprToken(Stack *pStack, ExprToken data) {
    if (pStack == NULL) return FALSE;
    StackNode node = {0,};
    node.data = data;
    return push(pStack, node);
}

void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount) {
    Stack *pStack = NULL;
    StackNode *pNode = NULL;
    Precedence tokenType;
    Precedence inStackTokenType;
    int i = 0;
    if (pExprTokens == NULL) return;
    pStack = createStack();
    if (pStack == NULL) return;
    for (i = 0; i < tokenCount; i++) {
        tokenType = pExprTokens[i].type;
        switch (tokenType) {
            case operand:
                printf("%f\n", pExprTokens[i].value);
                break;
            case rparen:
                pNode = pop(pStack);
                while (pNode != NULL && pNode->data.type != lparen) {
                    printToken(pNode->data);
                    free(pNode);
                    pNode = pop(pStack);
                }
                if (pNode != NULL) free(pNode);
                break;
            default:
                while (isStackEmpty(pStack) == FALSE) {
                    inStackTokenType = peek(pStack)->data.type;
                    if (outStackPrecedence(tokenType) <= inStackPrecedence(inStackTokenType)) {
                        pNode = pop(pStack);
                        if (pNode != NULL) {
                            printToken(pNode->data);
                            free(pNode);
                        }
                    } else {
                        break;
                    }
                }
                pushExprToken(pStack, pExprTokens[i]);
                break;
        }
    }
    while(isStackEmpty(pStack) == FALSE) {
        pNode = pop(pStack);
        if (pNode != NULL) {
            printToken(pNode->data);
            free(pNode);
        }
    }
    deleteStack(pStack);
}

int inStackPrecedence(Precedence oper) {
    switch (oper) {
        case lparen:
            return 0;
        case rparen:
            return 4;
        case times:
        case divide:
            return 2;
        case plus:
        case minus:
            return 1;
    }
    return -1;
}

int outStackPrecedence(Precedence oper) {
    switch (oper) {
        case lparen:
            return 5;
        case rparen:
            return 4;
        case times:
        case divide:
            return 2;
        case plus:
        case minus:
            return 1;
    }
    return -1;
}

void printToken(ExprToken element) {
    switch (element.type) {
        case lparen:
            printf("(\n");
            break;
        case rparen:
            printf(")\n");
            break;
        case plus:
            printf("+\n");
            break;
        case minus:
            printf("-\n");
            break;
        case times:
            printf("*\n");
            break;
        case divide:
            printf("/\n");
            break;
        case operand:
            printf("%f\n", element.value);
            break;
    }
}