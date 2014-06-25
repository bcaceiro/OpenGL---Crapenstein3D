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
    this->collide_minX = x;
    this->collide_minY = y;
    this->collide_minZ = z;
    this->collide_maxX = x + thickness;
    this->collide_maxY = y + height;
    this->collide_maxZ = z + width;

}
bool CollidingObject::isColliding(CollidingObject* obj){
    //printf("Default collide\n");
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
void CollidingObject::drawBoundingBox(){
    glBegin (GL_QUADS);

    glColor4f(1.0,0.0,0.0,1.0);
    glEnable(GL_DEPTH_TEST);

    glNormal3f(0.0f, 0.0f, 0.0f);

    glVertex3f(this->collide_maxX, this->collide_maxY, this->collide_minZ );	// Top Right Of The Quad (Top)
    glVertex3f(this->collide_minX, this->collide_maxY, this->collide_minZ);	// Top Left Of The Quad (Top)
    glVertex3f(this->collide_minX, this->collide_maxY, this->collide_maxZ);	// Bottom Left Of The Quad (Top)
    glVertex3f(this->collide_maxX, this->collide_maxY, this->collide_maxZ);	// Bottom Right Of The Quad (Top)

    glVertex3f(this->collide_maxX, this->collide_minY, this->collide_maxZ);	// Top Right Of The Quad (Bottom)
    glVertex3f(this->collide_minX, this->collide_minY, this->collide_maxZ);	// Top Left Of The Quad (Bottom)
    glVertex3f(this->collide_minX, this->collide_minY, this->collide_minZ);	// Bottom Left Of The Quad (Bottom)
    glVertex3f(this->collide_maxX, this->collide_minY, this->collide_minZ);	// Bottom Right Of The Quad (Bottom)

    glVertex3f(this->collide_maxX, this->collide_maxY, this->collide_maxZ);	// Top Right Of The Quad (Front)
    glVertex3f(this->collide_minX, this->collide_maxY, this->collide_maxZ);	// Top Left Of The Quad (Front)
    glVertex3f(this->collide_minX, this->collide_minY, this->collide_maxZ);	// Bottom Left Of The Quad (Front)
    glVertex3f(this->collide_maxX, this->collide_minY, this->collide_maxZ);	// Bottom Right Of The Quad (Front)

    glVertex3f(this->collide_maxX, this->collide_minY, this->collide_minZ);	// Top Right Of The Quad (Back)
    glVertex3f(this->collide_minX, this->collide_minY, this->collide_minZ);	// Top Left Of The Quad (Back)
    glVertex3f(this->collide_minX, this->collide_maxY, this->collide_minZ);	// Bottom Left Of The Quad (Back)
    glVertex3f(this->collide_maxX, this->collide_maxY, this->collide_minZ);	// Bottom Right Of The Quad (Back)

    glVertex3f(this->collide_minX, this->collide_maxY, this->collide_maxZ);	// Top Right Of The Quad (Left)
    glVertex3f(this->collide_minX, this->collide_maxY, this->collide_minZ);	// Top Left Of The Quad (Left)
    glVertex3f(this->collide_minX, this->collide_minY, this->collide_minZ);	// Bottom Left Of The Quad (Left)
    glVertex3f(this->collide_minX, this->collide_minY, this->collide_maxZ);	// Bottom Right Of The Quad (Left)

    glVertex3f(this->collide_maxX, this->collide_maxY,this->collide_minZ);	// Top Right Of The Quad (Right)
    glVertex3f(this->collide_maxX, this->collide_maxY,this->collide_maxZ);	// Top Left Of The Quad (Right)
    glVertex3f(this->collide_maxX, this->collide_minY,this->collide_maxZ);	// Bottom Left Of The Quad (Right)
    glVertex3f(this->collide_maxX, this->collide_minY,this->collide_minZ);	// Bottom Right Of The Quad (Right)
    glEnd();
}

#endif
