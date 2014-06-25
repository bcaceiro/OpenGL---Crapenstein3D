/*

 Crapenstein:
 
    - Bruno Caceiro
    - David Cardouzo

*/

#include "OpenGLIncludes.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include "Camera.h"
#include "Room.h"
#include "Wall.h"
#include "Robot.h"
#include "DoorWall.h"
#include "Map.h"
#include "Ball.h"
#include "RgbImage.h"
#include "collidingObject.h"
#include "torch.h"
#include "Cube.h"
using namespace std;

void Keyboard(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void specialkeypressed(int key, int x, int y);
void specialkeyUp(int key, int x, int y);
void MouseMotion(int x, int y);
void Mouse(int button, int state, int x, int y);
void desenhaRobot();
void createMap();
void Display();
void Reshape (int w, int h);
void Timer(int value);
void Idle();
void initFog();
void desenhaTexto(char *string, GLfloat x, GLfloat y, GLfloat z);

Camera* camera;
vector<CollidingObject*> collidableObjects;
vector<CollidingObject*>::iterator collidableObjectsIterator;
GLuint  texture[5];

bool enableFog = false;

GLint wScreen=800, hScreen=600;
bool keyStates[256] = {false};
bool specialKeyStates[256] = {false};
bool g_fps_mode = false;
//bool g_mouse_left_down = false;
// Movement settings
const float g_translation_speed = 0.5;
const float g_rotation_speed = M_PI/180*0.2;
int g_viewport_width = 0;
int g_viewport_height = 0;

Map* map;
DoorWall* testeDoor;

Robot* robotFofinho;


Cube* cuboTeste;
Cube* cuboTeste2;
Cube* cuboTeste3;

Ball * bola1;
Ball * bola2;
Torch* huehuehue;


char     texto[30];
char     paused[30];

bool openDoor = false;
GLuint skyTexture[1];
const float BOX_SIZE = 3.0f; //The length of each side of the cube
const float BOX_HEIGHT = BOX_SIZE; //The height of the box off of the ground
const float FLOOR_SIZE = 10.0f; //The length of each side of the floor

float angle;


bool isPaused = false;


//Draws the cube
void drawCube(float angle) {
    
    
    glPushMatrix();
    glTranslatef(20,10,10);
    
	glDisable(GL_TEXTURE_2D);
	
	glPushMatrix();
	glRotatef(-angle, 1.0f, 1.0f, 0.0f);
	
	glBegin(GL_QUADS);
	
	//Top face
	glColor3f(1.0f, 1.0f, 0.0f);
	glNormal3f(0.0, 1.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	
	//Bottom face
	glColor3f(1.0f, 0.0f, 1.0f);
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	
	//Left face
	glNormal3f(-1.0, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	
	//Right face
	glNormal3f(1.0, 0.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	
	glEnd();
	
    
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	
	//Front face
	glNormal3f(0.0, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, BOX_SIZE / 2);
	
	//Back face
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	
	glEnd();
	
	glPopMatrix();
    glPopMatrix();
}

//Draws the floor
void drawFloor() {

    
    glPushMatrix();
    glTranslatef(20,5,10);
	glBegin(GL_QUADS);
	
	glNormal3f(0, 1, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-FLOOR_SIZE / 2, 0, FLOOR_SIZE / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-FLOOR_SIZE / 2, 0, -FLOOR_SIZE / 2);
	glTexCoord2f(1, 1);
	glVertex3f(FLOOR_SIZE / 2, 0, -FLOOR_SIZE / 2);
	glTexCoord2f(1, 0);
	glVertex3f(FLOOR_SIZE / 2, 0, FLOOR_SIZE / 2);
	
	glEnd();
        glPopMatrix();
}

void drawScene() {
    
    /*LUZESSSS*/
    //luz vermelha situada perto da origem
    GLfloat ambientLight[4] = {0.2,0.2,0.2,1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);



    //glEnable(GL_LIGHT0);
    /*GLfloat lightPos[4] = {0, 1, 0, 1.0};
    
    glLightfv(GL_LIGHT0,GL_POSITION, lightPos);
    GLfloat lightColor[4] = {255,0,0,1};
    glLightfv(GL_LIGHT0,GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0,GL_SPECULAR, lightColor);
    
    angle += 1.0f;
	if (angle > 360) {
		angle -= 360;
	}
    
    
    

	glPushMatrix();
    	drawCube(angle);
	glPopMatrix();
    


	glEnable(GL_STENCIL_TEST); //Enable using the stencil buffer
	glColorMask(0, 0, 0, 0); //Disable drawing colors to the screen
	glDisable(GL_DEPTH_TEST); //Disable depth testing
	glStencilFunc(GL_ALWAYS, 1, 1); //Make the stencil test always pass
	//Make pixels in the stencil buffer be set to 1 when the stencil test passes
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	//Set all of the pixels covered by the floor to be 1 in the stencil buffer
	drawFloor();
	
	glColorMask(1, 1, 1, 1); //Enable drawing colors to the screen
	glEnable(GL_DEPTH_TEST); //Enable depth testing
	//Make the stencil test pass only when the pixel is 1 in the stencil buffer
	glStencilFunc(GL_EQUAL, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP); //Make the stencil buffer not change
	
	//Draw the cube, reflected vertically, at all pixels where the stencil
	//buffer is 1
	glPushMatrix();
	glScalef(1, -1, 1);
	drawCube(angle);
	glPopMatrix();
	
	glDisable(GL_STENCIL_TEST); //Disable using the stencil buffer
	
	//Blend the floor onto the screen
	glEnable(GL_BLEND);
	glColor4f(1, 1, 1, 0.7f);
	drawFloor();
	glDisable(GL_BLEND);
    
    
    

    
    
    

    glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,	1);
    glLightf(GL_LIGHT0,GL_LINEAR_ATTENUATION,		0.5);
    glLightf(GL_LIGHT0,GL_QUADRATIC_ATTENUATION,	0.5);
    //glLightf(GL_LIGHT1,GL_SPOT_CUTOFF,				0.5);
    //glLightf(GL_LIGHT1,GL_SPOT_EXPONENT,			1);
*/
    //draw Skybox
    //glDisable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,skyTexture[0]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glPushMatrix();
            glColor4f(1.0,1.0,1.0,1.0);
            glNormal3f(0.0f, 1.0f, 0.0f);
                glBegin(GL_QUADS);
                        glTexCoord2f(0.0f,0.0f);  glVertex3f( -5000,    51,  -5000);
                        glTexCoord2f(1000.0f,0.0f);  glVertex3f(  5000,    51,  -5000);
                        glTexCoord2f(1000.0f,1000.0f);  glVertex3f(  5000,    51,   5000);
                        glTexCoord2f(0.0f,1000.0f);  glVertex3f( -5000,         51,   5000);
                        glColor4f(1.0,1.0,1.0,1.0);
                glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


    //huehuehue->draw();
    map->update();

    /* Update Robot */
    robotFofinho->drawRobot();
    bola1->update();
    bola2->update();
    if(camera->m_x>400)
        glEnable(GL_FOG);
    else
        glDisable(GL_FOG);
}



void criaDefineTexturas()
{
        RgbImage imag;
        glGenTextures(1, &texture[0]);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        imag.LoadBmpFile("assets/doorFofa.bmp");
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
        imag.GetNumCols(),
                imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                imag.ImageData());

        glGenTextures(1, &texture[1]);
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        imag.LoadBmpFile("assets/chaoFofinho.bmp");
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
        imag.GetNumCols(),
            imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
            imag.ImageData());

        glGenTextures(1, &texture[2]);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        imag.LoadBmpFile("assets/parede3.bmp");
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
        imag.GetNumCols(),
            imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
            imag.ImageData());

        glGenTextures(1, &texture[3]);
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        imag.LoadBmpFile("assets/wolf.bmp");
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
        imag.GetNumCols(),
            imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
            imag.ImageData());

        glGenTextures(1, &skyTexture[0]);
        glBindTexture(GL_TEXTURE_2D, skyTexture[0]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        imag.LoadBmpFile("assets/chaleira.bmp");
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
        imag.GetNumCols(),
            imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
            imag.ImageData());

    
    glGenTextures(1, &texture[4]);
    glBindTexture(GL_TEXTURE_2D, texture[4]);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    imag.LoadBmpFile("assets/skyBox.bmp");
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 imag.GetNumCols(),
                 imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                 imag.ImageData());
}

void initializeObjects() {
    initFog();

    camera = new Camera();

    huehuehue = new Torch(GL_LIGHT1,0,1,50);


    map    = new Map();

    bola1 =     new Ball(15,5,3,3,8,1);
    bola2 =     new Ball(25,5,10,0.5,9,-1);
    robotFofinho = new Robot(8,5,3,1.3,camera);
    
    cuboTeste = new Cube(30,2,25,2,0.25, 1.0f,0.0f,0.0f);
    cuboTeste2 = new Cube(40,2,25,2,0.25, 0.0f,1.0f,0.0f);
    cuboTeste3 = new Cube(50,2,25,2,0.25, 0.0f,0.0f,1.0f);


    //set Robot Bounds FIXME move inside the robot class
    robotFofinho->setBounds(8,5,3,1.3,1.3,5);
    //set the camera to have the bounds of the robot
    camera->setObject(robotFofinho);
    
    
    
}

void initFog(void){
    GLfloat nevoeiroCor[] = {0.7, 0.7, 0.7, 1.0};
    glFogfv(GL_FOG_COLOR,nevoeiroCor);
	glFogi(GL_FOG_MODE, GL_LINEAR); //Equao do nevoeiro - linear
    glFogf(GL_FOG_START, 10); // Distncia a que ter incio o nevoeiro
	glFogf(GL_FOG_END, 30); // Distncia a que o nevoeiro terminar
    glFogf (GL_FOG_DENSITY, 0.3);
}

void desenhaTexto(char *string, GLfloat x, GLfloat y, GLfloat z) {
	glRasterPos3f(x,y,z);
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *string++);
}







int main (int argc, char **argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowSize(wScreen, hScreen);
    glutCreateWindow("CGenstein");

    // Initialize the container of the collidableObjects
    collidableObjects.clear();

    glClearColor(BLACK);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);


    criaDefineTexturas( );
    initializeObjects();
    initFog();

        sprintf(texto, "Bruno Caceiro | David Cardoso");
            sprintf(paused, "Paused");

    /* LIGHTS */
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



    glEnable(GL_DEPTH_TEST);






    

    glutIgnoreKeyRepeat(1);
    glutDisplayFunc(Display);
    glutIdleFunc(Display);
    glutReshapeFunc(Reshape);
    glutMouseFunc(Mouse);
    glutMotionFunc(MouseMotion);
    glutPassiveMotionFunc(MouseMotion);
    glutKeyboardFunc(Keyboard);
    glutKeyboardUpFunc(KeyboardUp);
    glutSpecialFunc(specialkeypressed);
    glutSpecialUpFunc(specialkeyUp);
    glutIdleFunc(Idle);
    glutTimerFunc(1, Timer, 0);
    glutMainLoop();

    return 0;
}

void Display (void) {
    
    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    //glLoadIdentity();
    //draw the minimap
    
    if(!isPaused) {
                glEnable(GL_LIGHTING);
    glViewport(g_viewport_width/2 + g_viewport_width/6 ,0,g_viewport_width/2 , g_viewport_height/5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20,20,-20,20,-20,20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(1, 1, 1, 0, 0, 0, 0, 1, 0);
    glPushMatrix();
    
    glClear( GL_COLOR_BUFFER_BIT);

    glPopMatrix();
    desenhaTexto(texto, -15, -15, 0);
    

    
    


    glViewport (0, 0, g_viewport_width/4, g_viewport_height/4);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-50,50,-50,50,-50,50);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        float a,b,c;
        camera->GetPos(a,b,c);
        float q,w,e;
        camera->GetDirectionVector(q,w,e);
        gluLookAt(a, 0, c, a, -5, c, q, 0, e);
        glPushMatrix();


        glClear( GL_COLOR_BUFFER_BIT);

        glColor3f(0.1, 0.0, 0.0);
         glBegin(GL_POLYGON);
          glVertex3f(a-100, -0.1, c-100);
          glVertex3f(a+100, -0.1, c-100);
          glVertex3f(a+100, -0.1, c+100);
          glVertex3f(a-100, -0.1, c+100);
         glEnd();
        glPopMatrix();
    
        drawScene();
    
    





    glViewport (0, 0, (GLsizei)g_viewport_width , (GLsizei)g_viewport_height); //set the viewport to the current window specifications
        glMatrixMode (GL_PROJECTION); //set the matrix to projection
        glLoadIdentity();
        gluPerspective (60, (GLfloat)g_viewport_width / (GLfloat)g_viewport_height, 0.1 , 1000.0); //set the perspective (angle of sight, width, height, ,depth)
        camera->Refresh();
    drawScene();
    }
    
    else {
        
        glDisable(GL_LIGHTING);
        glViewport(0,0,g_viewport_width, g_viewport_height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-20,20,-20,20,-20,20);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        gluLookAt(5, 5, 5, 0, 0, 0, 0 , 1, 0);
        glPushMatrix();
        
        glClear( GL_COLOR_BUFFER_BIT);
        
        glPopMatrix();
        glColor4f(1.0, 1.0, 1.0,1.0);
        desenhaTexto(paused, 1, 1, 1);
        
    }


    glutSwapBuffers(); //swap the buffers
}

void Reshape (int w, int h) {
    //printf("reshape!!!!\n");
    g_viewport_width = w;
    g_viewport_height = h;

    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection

    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1 , 1000.0); //set the perspective (angle of sight, width, height, ,depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
}

void Timer(int value)
{
    if(g_fps_mode){
        if(keyStates['w'] || specialKeyStates[GLUT_KEY_UP]) {
            robotFofinho->Move(g_translation_speed);

        }
        if(keyStates['s'] || specialKeyStates[GLUT_KEY_DOWN]) {
            robotFofinho->Move(-g_translation_speed);
        }
        if(keyStates['a'] || specialKeyStates[GLUT_KEY_LEFT]) {
            robotFofinho->Strafe(g_translation_speed);

        }
        if(keyStates['d'] ||  specialKeyStates[GLUT_KEY_RIGHT]) {
            robotFofinho->Strafe(-g_translation_speed);
        }

    }
    robotFofinho->updateLasers();
    glutTimerFunc(1, Timer, 0);
}

void Idle()
{
    Display();
}

//========================================================
//Input

void Keyboard(unsigned char key, int x, int y)
{
    
    
    if(key == 27) {
        g_fps_mode = !g_fps_mode;

        if(g_fps_mode) {
            glutSetCursor(GLUT_CURSOR_NONE);
            glutWarpPointer(g_viewport_width/2, g_viewport_height/2);
        }
        else {
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
        }
    }

    keyStates[tolower(key)] = true;
}

void KeyboardUp(unsigned char key, int x, int y)
{
    if(key == 'p') {
        map->checkOpenDoors();
    }
    
    if(key == 'f')
        initFog();
    
    if(key == 'b')
        isPaused = !isPaused;
    
    keyStates[tolower(key)] = false;
}

void specialkeypressed(int key, int x, int y)
{
    specialKeyStates[key] = true; // Set the state of the current key to pressed
}
void specialkeyUp(int key, int x, int y)
{
    specialKeyStates[key] = false; // Set the state of the current key to pressed
}

void Mouse(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN) {
        if(button == GLUT_LEFT_BUTTON) {
           robotFofinho->fireLaser();
        }
    }
    /*else if(state == GLUT_UP) {
        if(button == GLUT_LEFT_BUTTON) {
            g_mouse_left_down = false;
        }
    }*/
}

void MouseMotion(int x, int y)
{
    // This variable is hack to stop glutWarpPointer from triggering an event callback to Mouse(...)
    // This avoids it being called recursively and hanging up the event loop
    static bool just_warped = false;

    if(just_warped) {
        just_warped = false;
        return;
    }

    if(g_fps_mode) {
        int dx = x - g_viewport_width/2;
        int dy = y - g_viewport_height/2;

        if(dx) {
            camera->RotateYaw(g_rotation_speed*dx);
        }

        if(dy) {
            camera->RotatePitch(g_rotation_speed*dy);
        }
        //glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
        glutWarpPointer(g_viewport_width/2, g_viewport_height/2);

        just_warped = true;
    }
}




