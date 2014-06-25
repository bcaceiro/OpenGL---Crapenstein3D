//
//  Room.h
//  Crapenstein
//
//  Created by Bruno Caceiro on 24/06/14.
//  Copyright (c) 2014 Bruno Caceiro. All rights reserved.
//

#ifndef Crapenstein_Room_h
#define Crapenstein_Room_h

#include <stdio.h>
#include <assert.h>
#include "OpenGLIncludes.h"
#include "Wall.h"

#include <vector>
#include "collidingObject.h"

using namespace std;
extern vector<CollidingObject*> collidableObjects;
extern vector<CollidingObject*>::iterator collidableObjectsIterator;


class Room
{
public:
    
    //Constructor
    Room(GLfloat roomPosX, GLfloat roomPosY, GLfloat roomPosZ, GLfloat leftWallWidth, GLfloat roomHeight, GLfloat backWallWidth, bool isLeftWallActive, bool isBackWallActive, bool isRightWallActive, bool isFrontWallActive);
    
    //Destroy
    ~Room();
    
    //Methods
    void buildRoom();
    void update();
    
private:
    
    Wall* leftWall;
    Wall* rightWall;
    Wall* backWall;
    Wall* frontWall;
    Wall* floor;
    
    GLfloat posX;
    GLfloat posY;
    GLfloat posZ;
    GLfloat leftWidth;
    GLfloat height;
    GLfloat backWidth;
    
    bool leftWallActive;
    bool backWallActive;
    bool rightWallActive;
    bool frontWallActive;

};

inline Room::~Room()
{
}

#endif
