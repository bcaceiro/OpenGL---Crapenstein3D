//
//  Room.cpp
//  Crapenstein
//
//  Created by Bruno Caceiro on 24/06/14.
//  Copyright (c) 2014 Bruno Caceiro. All rights reserved.
//

#include "Room.h"
#include "Wall.h"

//Constructor
Room::Room(GLfloat roomPosX, GLfloat roomPosY, GLfloat roomPosZ, GLfloat leftWallWidth, GLfloat roomHeight, GLfloat backWallWidth, bool isLeftWallActive, bool isBackWallActive, bool isRightWallActive, bool isFrontWallActive) {


    posX          = roomPosX;
    posY          = roomPosY;
    posZ          = roomPosZ;
    leftWidth     = leftWallWidth;
    height        = roomHeight;
    backWidth     = backWallWidth;
    
    leftWallActive  = isLeftWallActive;
    backWallActive  = isBackWallActive;
    rightWallActive = isRightWallActive;
    frontWallActive = isFrontWallActive;
    

}


void Room::buildRoom() {
    
    if(leftWallActive)
        leftWall = new Wall (posX, posY, posZ, leftWidth, height, 1);
    
    if(backWallActive)
        backWall = new Wall(posX, posY, posZ, backWidth, height, 2);
    
    if(rightWallActive)
        rightWall = new Wall (posX, posY, posZ + backWidth, leftWidth, height, 1);

    if(frontWallActive)
        frontWall = new Wall(posX + leftWidth,posY,posZ,backWidth,height,2);
    
    floor = new Wall (posX,posY,posZ, leftWidth,backWidth,0);
    
}
    


void Room::update() {
    
    if(leftWallActive)
        leftWall->draw();
    
    if(backWallActive)
        backWall->draw();
    
    if(rightWallActive)
        rightWall->draw();
    
    if(frontWallActive)
        frontWall->draw();
    
    floor->draw();
    
}
