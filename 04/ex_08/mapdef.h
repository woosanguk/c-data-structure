//
// Created by sanguk on 08/08/2017.
//

#ifndef EX_08_MAPDEF_H_H
#define EX_08_MAPDEF_H_H

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 8

static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
        {0,  1},
        {0,  -1},
        {-1, 0},
        {1,  0},
        {1,  -1},
        {1,  1},
        {-1, -1},
        {-1, 1}
};

enum PosStatus {
    NOT_VISIT = 0, WALL = 1, VISIT = 2
};

typedef struct MapPositionType {
    int x;
    int y;
    int direction;
} MapPosition;

#endif //EX_08_MAPDEF_H_H
