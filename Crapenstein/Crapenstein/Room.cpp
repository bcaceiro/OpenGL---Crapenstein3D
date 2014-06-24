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
    /* 1- LeftDoor; 2- BackDoor 3- RightDoor; 4 - FrontDoor;*/
    
    
    leftWallActive  = isLeftWallActive;
    backWallActive  = isBackWallActive;
    rightWallActive = isRightWallActive;
    frontWallActive = isFrontWallActive;
    

}


/*
 x= 0; y = 0; z = 0; leftWallWidth = 100; roomHeight = 15;
 room1LeftWall  = new Wall(0,0,0,100,15,1);
 room1RightWall = new Wall(0,0,50,100,15,1);
 room1BackWall  = new Wall(0,0,0,50,15,2);
 
 parede1 = new Wall(0,  0,0, 100,15,1);
 parede2 = new Wall(0,  0,0, 50,15,2);
 parede3 = new Wall(0,  0,50,100,15,1);
 parede4 = new Wall(100,0,0, 50,15,2);
         chao = new Wall(0,0,0,100,50,0);
 
 */

void Room::buildRoom() {
    
    if(leftWallActive)
        leftWall = new Wall (posX, posY, posZ, leftWidth, height, 1);
    
    if(backWallActive)
        backWall = new Wall(posX, posY, posZ, backWidth, height, 2);
    
    if(rightWallActive)
        rightWall = new Wall (posX, posY, posZ + backWidth, leftWidth, height, 1);

    if(frontWallActive)
        frontWall = new Wall(posX + leftWidth,0,0,backWidth,height,2);
    
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