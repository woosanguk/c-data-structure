//
// Created by sanguk on 08/08/2017.
//

#ifndef STACK_MAP_MAPDEF_H
#define STACK_MAP_MAPDEF_H

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
        {0,  -1},
        {1,  0},
        {0,  1},
        {-1, 0}
};

enum PosStatus {
    NOT_VISIT = 0, WALL = 1, VISIT = 2
};

typedef struct MapPositionType {
    int x;
    int y;
    int direction;
} MapPosition;

#endif //STACK_MAP_MAPDEF_H
