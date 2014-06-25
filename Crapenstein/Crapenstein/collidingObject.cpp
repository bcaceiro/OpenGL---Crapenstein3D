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
    //printf("Setting bounds\n");
    this->collide_minX = x-thickness;
    this->collide_minY = y-height;
    this->collide_minZ = z-width;
    this->collide_maxX = x + thickness;
    this->collide_maxY = y + height;
    this->collide_maxZ = z + width;

}
bool CollidingObject::isColliding(CollidingObject* obj){
    printf("Default collide\n");
    if(this->collide_minX < obj->collide_maxX && this->collide_maxX > obj->collide_minX){
        if(this->collide_minY < obj->collide_maxY && this->collide_maxY > obj->collide_minY){
           if(this->collide_minZ < obj->collide_maxZ && this->collide_maxZ > obj->collide_minZ){
               return true;
            }
        }
    }
    //printf("Not Colliding...\n");
    return false;
}

#endif
