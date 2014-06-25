//
//  Map.cpp
//  Crapenstein
//
//  Created by Bruno Caceiro on 24/06/14.
//  Copyright (c) 2014 Bruno Caceiro. All rights reserved.
//

#include "Map.h"
#include "Room.h"
#include <stdio.h>
#include <assert.h>
#include "OpenGLIncludes.h"
#include "DoorWall.h"


#include <vector>
#include "collidingObject.h"

using namespace std;
extern vector<CollidingObject*> collidableObjects;
extern vector<CollidingObject*>::iterator collidableObjectsIterator;

/* Map
 
 - Rooms (Numbered, 0 means there's no room
 
 0,9,0
 6,7,8
 0,5,0
 2,3,4
 0,1,0
 
 */

Map::Map() {
    
    room1 = new Room(0,0,0,100,15,50,true,true,true,false);
    room1->buildRoom();
    
    room2 = new Room(100,0,-50,100,15,50,true,true,false,true);
    room2->buildRoom();
    
    room3 = new Room (100,0,0,100,15,50,false,false,false,false);
    room3->buildRoom();
    
    room4 = new Room(100,0,50,100,15,50,false,true,true,true);
    room4->buildRoom();
    
    room5 = new Room(200,0,0,100,15,50,true,false,true,false);
    room5->buildRoom();
    
    room6 = new Room(300,0,-50,100,15,50,true,true,false,true);
    room6->buildRoom();
    
    room7 = new Room(300,0,0,100,15,50,false,false,false,false);
    room7->buildRoom();
    
    room8 = new Room(300,0,50,100,15,50,false,true,true,true);
    room8->buildRoom();
    
    room9 = new Room(400,0,0,100,15,50,true,false,true,true);
    room9->buildRoom();
    
    doorRoom1 = new DoorWall(100,0,0,50,15,2);
    doorRoom2 = new DoorWall(100,0,0,100,15,1);
    doorRoom4 = new DoorWall(100,0,50,100,15,1);
    doorRoom5 = new DoorWall(300,0,0,50,15,2);
    doorRoom6 = new DoorWall(300,0,0,100,15,1);
    doorRoom8 = new DoorWall(300,0,50,100,15,2);
    doorRoom9 = new DoorWall(400,0,0,50,15,2);
    
    collidableObjects.push_back(doorRoom1);
    collidableObjects.push_back(doorRoom2);
    collidableObjects.push_back(doorRoom4);
    collidableObjects.push_back(doorRoom5);
    collidableObjects.push_back(doorRoom6);
    collidableObjects.push_back(doorRoom8);
    collidableObjects.push_back(doorRoom9);
    
}

void Map::update() {
    
    room1->update();
    room2->update();
    room3->update();
    room4->update();
    room5->update();
    room6->update();
    room7->update();
    room8->update();
    room9->update();
    
    doorRoom1->update();
    doorRoom2->update();
    doorRoom4->update();
    doorRoom5->update();
    doorRoom6->update();
    doorRoom8->update();
    doorRoom9->update();

}

void Map:: checkOpenDoors() {
    
    doorRoom1->openDoor();
    doorRoom2->openDoor();
    doorRoom4->openDoor();
    doorRoom5->openDoor();
    doorRoom6->openDoor();
    doorRoom8->openDoor();
    doorRoom9->openDoor();
    
}
