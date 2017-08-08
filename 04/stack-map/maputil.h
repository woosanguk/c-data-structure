//
// Created by sanguk on 08/08/2017.
//

#ifndef STACK_MAP_MAPUTIL_H
#define STACK_MAP_MAPUTIL_H


void findPath(int mazeArray[HEIGHT][WIDTH],
              MapPosition startPos,
              MapPosition endPos,
              Stack *pStack);

int pushMapPosition(Stack *pStack, MapPosition data);

void showPath(Stack *pStack, int mazeArray[HEIGHT][WIDTH]);

void printMaze(int mazeArray[HEIGHT][WIDTH]);


#endif //STACK_MAP_MAPUTIL_H
