
#include "Cube.h"

#include <stdio.h>
#include "OpenGLIncludes.h"


Cube::Cube(GLfloat cubePosX, GLfloat cubePosY, GLfloat cubePosZ, GLfloat cubeSize, GLfloat alphaCube,GLfloat red,GLfloat green,GLfloat blue){
        
    alpha = 0.25f;
    posX = cubePosX;
    posY = cubePosY;
    posZ = cubePosZ;
    size = cubeSize;
    
    r = red;
    g = green;
    b = blue;
    }


    void Cube::draw() {
        
        
        glEnable(GL_BLEND);

        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glBegin (GL_QUADS);
 
        glColor4f(r,g,b, alpha);

        glEnable(GL_DEPTH_TEST);
        
        glNormal3f(0.0f, 0.0f, 0.0f);

        
        glVertex3f(posX + size, posY + size, posZ - size );	// Top Right Of The Quad (Top)
        glVertex3f(posX - size, posY + size, posZ - size);	// Top Left Of The Quad (Top)
        glVertex3f(posX - size, posY + size, posZ + size);	// Bottom Left Of The Quad (Top)
        glVertex3f(posX + size, posY + size, posZ + size);	// Bottom Right Of The Quad (Top)
        
        glVertex3f(posX + size, posY - size, posZ + size);	// Top Right Of The Quad (Bottom)
        glVertex3f(posX - size, posY - size, posZ + size);	// Top Left Of The Quad (Bottom)
        glVertex3f(posX - size, posY - size, posZ - size);	// Bottom Left Of The Quad (Bottom)
        glVertex3f(posX + size, posY - size, posZ - size);	// Bottom Right Of The Quad (Bottom)
        
        glVertex3f(posX + size, posY + size, posZ + size);	// Top Right Of The Quad (Front)
        glVertex3f(posX - size, posY + size, posZ + size);	// Top Left Of The Quad (Front)
        glVertex3f(posX - size, posY - size, posZ + size);	// Bottom Left Of The Quad (Front)
        glVertex3f(posX + size, posY - size, posZ + size);	// Bottom Right Of The Quad (Front)
        
        glVertex3f(posX + size, posY - size, posZ - size);	// Top Right Of The Quad (Back)
        glVertex3f(posX - size, posY - size, posZ - size);	// Top Left Of The Quad (Back)
        glVertex3f(posX - size, posY + size, posZ - size);	// Bottom Left Of The Quad (Back)
        glVertex3f(posX + size, posY + size, posZ - size);	// Bottom Right Of The Quad (Back)
        
        glVertex3f(posX - size, posY + size, posZ + size);	// Top Right Of The Quad (Left)
        glVertex3f(posX - size, posY + size, posZ - size);	// Top Left Of The Quad (Left)
        glVertex3f(posX - size, posY - size, posZ - size);	// Bottom Left Of The Quad (Left)
        glVertex3f(posX - size, posY - size, posZ + size);	// Bottom Right Of The Quad (Left)
        
        glVertex3f(posX + size, posY + size,posZ - size);	// Top Right Of The Quad (Right)
        glVertex3f(posX + size, posY + size,posZ + size);	// Top Left Of The Quad (Right)
        glVertex3f(posX + size, posY - size,posZ + size);	// Bottom Left Of The Quad (Right)
        glVertex3f(posX + size, posY - size,posZ - size);	// Bottom Right Of The Quad (Right)
        glEnd();
        
        glDisable(GL_BLEND); 
    }
