
#ifndef __WALL__
#define __WALL__

#include <stdio.h>
#include "Wall.h"
#include "OpenGLIncludes.h"

extern GLuint texture[2];
//constructor
Wall::Wall(){
    //fazer cenas, dá jeito!
    cenas = 5;
    printf("\nCenas= %d\n",cenas);
}
void Wall::draw(){
    printf("merda\n\n");
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texture[1]);
    glPushMatrix();
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f,0.0f);   glVertex3i( 0,  0,  0);
            glTexCoord2f(10.0f,0.0f);  glVertex3i( 15, 0,  0);
            glTexCoord2f(10.0f,10.0f); glVertex3i( 15, 15, 0);
            glTexCoord2f(0.0f,10.0f);  glVertex3i( 0,  15, 0);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    printf("acabou a merda\n");


}

#endif
