#ifndef WALL_H
#define WALL_H
#include <stdio.h>
#include <assert.h>

// Include the next line to turn off the routines that use OpenGL
// #define RGBIMAGE_DONT_USE_OPENGL

class Wall
{
public:
    //constructor
    Wall();
    //destroy
    ~Wall();
    void draw();

private:
    int cenas;
};
inline Wall::~Wall()
{
}
#endif // WALL_H
