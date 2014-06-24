//
//  Map.h
//  Crapenstein
//
//  Created by Bruno Caceiro on 24/06/14.
//  Copyright (c) 2014 Bruno Caceiro. All rights reserved.
//

#ifndef Crapenstein_Map_h
#define Crapenstein_Map_h

#include "Room.h"

class Map
{
public:
    
    //Constructor
    Map();
    
    //Destroy
    ~Map();
    
    //Methods
    void update();
    
private:
    
    Room* room1;
    Room* room2;
    Room* room3;
    Room* room4;
    Room* room5;
    Room* room6;
    Room* room7;
    Room* room8;
    Room* room9;

};

inline Map::~Map()
{
}

#endif
