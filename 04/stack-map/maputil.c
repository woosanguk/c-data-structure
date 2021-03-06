//
// Created by sanguk on 08/08/2017.
//

#include "mapdef.h"
#include "mapstack.h"
#include "maputil.h"
#include <stdio.h>
#include <stdlib.h>

void findPath(int mazeArray[HEIGHT][WIDTH],
              MapPosition startPos,
              MapPosition endPos,
              Stack *pStack) {
    StackNode *pNode = NULL;
    int isEmpty = FALSE, isFound = FALSE, i = 0;
    int markArray[HEIGHT][WIDTH] = {0,};
    if (pStack == NULL) return;
    MapPosition newPosition = startPos;
    newPosition.direction = 0;
    pushMapPosition(pStack, newPosition);
    while (isEmpty == FALSE && isFound == FALSE) {
        pNode = pop(pStack);
        if (pNode == NULL) break;
        int x = pNode->data.x;
        int y = pNode->data.y;
        int direction = pNode->data.direction;
        while (isFound == FALSE && direction < NUM_DIRECTIONS) {
            int newX = x + DIRECTION_OFFSETS[direction][0];
            int newY = y + DIRECTION_OFFSETS[direction][1];
            if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && markArray[newY][newX] == NOT_VISIT &&
                mazeArray[newY][newX] == NOT_VISIT){
                MapPosition newPosition;
                newPosition.x = x;
                newPosition.y = y;
                newPosition.direction = direction + 1;
                pushMapPosition(pStack, newPosition);
                markArray[y][x] = VISIT;

                x = newX;
                y = newY;
                direction = 0;

                if (newX  == endPos.x && newY == endPos.y){
                    isFound = TRUE;
                    newPosition.x = newX;
                    newPosition.y = newY;
                    newPosition.direction = 0;
                    pushMapPosition(pStack, newPosition);
                    markArray[newY][newX] = VISIT;
                }
            } else{
                direction++;
            }
        }
        free(pNode);
        isEmpty = isStackEmpty(pStack);
    }
}

int pushMapPosition(Stack *pStack, MapPosition data) {
    StackNode node = {0,};
    if (pStack == NULL) return FALSE;
    node.data = data;
    return push(pStack, node);
}

void showPath(Stack *pStack, int mazeArray[HEIGHT][WIDTH]) {
    StackNode *pNode = NULL;
    int resultArray[HEIGHT][WIDTH] = {0,};
    int isEmpty = FALSE;

    int i, j;
    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            resultArray[i][j] = mazeArray[i][j];
        }
    }
    i = 0;
    while(isEmpty == FALSE) {
        pNode = pop(pStack);
        if (pNode != NULL) {
            int x = pNode->data.x;
            int y = pNode->data.y;
            resultArray[y][x] = VISIT;
            if (i > 0) {
                printf("<-");
            }
            printf("(%d,%d) ", x, y);
            i++;
            free(pNode);
        }
        isEmpty = isStackEmpty(pStack);
    }
    printf("\n");
    printMaze(resultArray);
}

void printMaze(int mazeArray[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (mazeArray[i][j] == WALL) {
                printf("*");
            } else if (mazeArray[i][j] == VISIT) {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}