#ifndef COLLIDINGOBJECT_CPP
#define COLLIDINGOBJECT_CPP

#include <stdio.h>
#include "collidingObject.h"


CollidingObject::CollidingObject(){

}
/**
 * @brief CollidingObject::setBounds
 * @param x         min x
 * @param y         min y
 * @param z         min z
 * @param thickness (espessura do x)
 * @param height    altura (espessura do y
 * @param width     largura (espessura do z)
 */
void CollidingObject::setBounds(float x, float y ,float z ,float thickness,float height,float width){
    printf("Setting bounds\n");
    this->collide_minX = x;
    this->collide_minY = y;
    this->collide_minZ = z;
    this->collide_maxX = x + thickness;
    this->collide_maxY = y + height;
    this->collide_maxZ = z + width;

}
bool CollidingObject::isColliding(CollidingObject* obj){
    printf("Not implemented!\n");
    return false;
}

#endif
