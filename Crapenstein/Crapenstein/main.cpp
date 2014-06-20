/*

 Crapenstein:
 
    - Bruno Caceiro
    - David Cardouzo

*/

#include "OpenGLIncludes.h"
#include <iostream>
#include <cmath>
#include "Camera.h"
#include "Wall.h"
#include "Robot.h"
#include "RgbImage.h"
#include "mapLimits.h"




#define AZUL 0.0, 0.0, 1.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0, 1.0
#define VERDE 0.0, 1.0, 0.0, 1.0
#define BRANCO 1.0, 1.0, 1.0, 1.0
#define BLACK 0.0, 0.0, 0.0, 1.0


using namespace std;

void Display();
void Reshape (int w, int h);

void Timer(int value);
void Idle();

Camera* camera;

bool keyStates[256] = {false};
bool specialKeyStates[256] = {false};
bool g_mouse_left_down = false;
bool g_mouse_right_down = false;
bool g_shift_down = false;
bool g_fps_mode = false;
// Movement settings
const float g_translation_speed = 0.5;
const float g_rotation_speed = M_PI/180*0.2;

int g_viewport_width = 0;
int g_viewport_height = 0;

void Keyboard(unsigned char key, int x, int y);
void KeyboardUp(unsigned char key, int x, int y);
void specialkeypressed(int key, int x, int y);
void specialkeyUp(int key, int x, int y);
void MouseMotion(int x, int y);
void Mouse(int button, int state, int x, int y);
void desenhaRobot();





Wall* merda;
Robot* robotFofinho;


//--------------------------------- Definir cores
#define BLUE     0.0, 0.0, 1.0, 1.0
#define RED      1.0, 0.0, 0.0, 1.0
#define YELLOW  1.0, 1.0, 0.0, 1.0
#define GREEN    0.0, 1.0, 0.0, 1.0
#define ORANGE   1.0, 0.5, 0.1, 1.0
#define WHITE    1.0, 1.0, 1.0, 1.0
#define BLACK    0.0, 0.0, 0.0, 1.0
#define GRAY     0.9, 0.92, 0.29, 1.0
#define PI		 3.14159


//================================================================================
//===========================================================Variaveis e constantes

//------------------------------------------------------------ Sistema Coordenadas
GLfloat   xC=15.0, yC=15.0, zC=30.0;
GLint     wScreen=800, hScreen=600;
GLfloat   mesa=3.0;
GLfloat   bule=1.3;
GLfloat   quad=6.0;
GLfloat   mesaP[]= {4, 0, 10};
GLfloat   buleP[]= {4, 0, 10};
GLfloat   quadP[]= {4, 4, 0.1};


//------------------------------------------------------------ Observador
GLint    defineView=0;
GLint    defineProj=1;
GLfloat  raio   = 20;
GLfloat  angBule = 0;
GLfloat  incBule = 1;

//------------------------------------------------------------ Texturas
GLint    repete=1;
GLfloat  rr=1;
GLint    maxR  =20;
GLint    numQuadro =5;
GLint    msec=10;					//.. definicao do timer (actualizacao)

//================================================================================
//=========================================================================== INIT

//------------------------------------------------------------ Texturas
GLuint  texture[4];
GLuint  tex;
RgbImage imag;



/* ROBOT */
GLfloat robotX = 2;
GLfloat robotZ = 2;
GLfloat robotY = 2;



void drawScene(){

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Mesa
    
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[0]);
        glPushMatrix();
                glTranslatef( mesaP[0], mesaP[1]+mesa/2, mesaP[2]);
                glRotatef (       90, -1, 0, 0);
                GLUquadricObj*  y = gluNewQuadric ( );
                gluQuadricDrawStyle ( y, GLU_FILL   );
                gluQuadricNormals   ( y, GLU_SMOOTH );
                gluQuadricTexture   ( y, GL_TRUE    );
                glutSolidCube(1.5);
                //gluSphere ( y, 0.5*mesa, 150, 150);

                gluDeleteQuadric ( y );
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);

        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Chao y=0
        /*glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture[1]);
        glPushMatrix();
                glBegin(GL_QUADS);
                        glTexCoord2f(0.0f,0.0f); glVertex3i( 0,  0, 0 );
                        glTexCoord2f(10.0f,0.0f); glVertex3i( xC, 0, 0 );
                        glTexCoord2f(10.0f,10.0f); glVertex3i( xC, 0, xC);
                        glTexCoord2f(0.0f,10.0f); glVertex3i( 0,  0,  xC);
                glEnd();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);*/

        parede1->draw();
        parede2->draw();
        parede3->draw();
        parede4->draw();
        chao->draw();

        //*****************************************************
        // A IMPLEMENTAR PELOS ALUNOS
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Chaleira
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Quadro
        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Parede z=0
        //*****************************************************


        //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Eixos
        glColor4f(WHITE);
        glBegin(GL_LINES);
                glVertex3i( 0, 0, 0);
                glVertex3i(100, 0, 0);
        glEnd();
        glColor4f(RED);
        glBegin(GL_LINES);
                glVertex3i(0,  0, 0);
                glVertex3i(0, 100, 0);
        glEnd();
        glColor4f(BLUE);
        glBegin(GL_LINES);
                glVertex3i( 0, 0, 0);
                glVertex3i( 0, 0,100);
        glEnd();


}








void criaDefineTexturas()
{
        //----------------------------------------- Mesa
        glGenTextures(1, &texture[0]);
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        imag.LoadBmpFile("assets/mesa.bmp");
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
        imag.GetNumCols(),
                imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
                imag.ImageData());

        //----------------------------------------- Chao y=0
        glGenTextures(1, &texture[1]);
        glBindTexture(GL_TEXTURE_2D, texture[1]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        imag.LoadBmpFile("assets/chao.bmp");
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
        imag.GetNumCols(),
            imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
            imag.ImageData());

        //----------------------------------------- Chao y=0
        glGenTextures(1, &texture[2]);
        glBindTexture(GL_TEXTURE_2D, texture[2]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        imag.LoadBmpFile("assets/azulejo.bmp");
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
        imag.GetNumCols(),
            imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
            imag.ImageData());

        //----------------------------------------- Chao y=0
        glGenTextures(1, &texture[3]);
        glBindTexture(GL_TEXTURE_2D, texture[3]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        imag.LoadBmpFile("assets/parede.bmp");
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
        imag.GetNumCols(),
            imag.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE,
            imag.ImageData());


        //*****************************************************
        // A IMPLEMENTAR PELOS ALUNOS
        //
        //----------------------------------------- Chaleira
        //----------------------------------------- Parede z=0
        //----------------------------------------- Parede x=0
        //----------------------------------------- Quadros
        //*****************************************************
}


int main (int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(wScreen, hScreen);
    glutCreateWindow("CGenstein");

    camera = new Camera();
    parede1 = new Wall(0,  0,0, 100,15,1);
    parede2 = new Wall(0,  0,0, 50,15,2);
    parede3 = new Wall(0,  0,50,100,15,1);
    parede4 = new Wall(100,0,0, 50,15,2);
    chao = new Wall(0,0,0,100,50,0);
    merda = new Wall();
    robotFofinho = new Robot(8,5,3,1.3);
    glClearColor(BLACK);
    glShadeModel(GL_SMOOTH);
    criaDefineTexturas( );
    glEnable(GL_TEXTURE_2D);
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
    glLoadIdentity();

    camera->Refresh();

    glColor3f(0,1,0);

    //glutSolidTeapot(0.5);
    //glutWireTeapot(0.5);
    drawScene();

    glutSwapBuffers(); //swap the buffers
}

void Reshape (int w, int h) {
    g_viewport_width = w;
    g_viewport_height = h;

    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection

    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1 , 100.0); //set the perspective (angle of sight, width, height, ,depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
}



void Timer(int value)
{
    if(g_fps_mode) {
        if(keyStates['w'] || specialKeyStates[GLUT_KEY_UP]) {
            camera->Move(g_translation_speed);
        }
        if(keyStates['s'] || specialKeyStates[GLUT_KEY_DOWN]) {
            camera->Move(-g_translation_speed);
        }
        if(keyStates['a'] || specialKeyStates[GLUT_KEY_LEFT]) {
            camera->Strafe(g_translation_speed);
        }
        if(keyStates['d'] ||  specialKeyStates[GLUT_KEY_RIGHT]) {
            camera->Strafe(-g_translation_speed);
        }
        if(g_mouse_left_down) {
            camera->Fly(-g_translation_speed);
        }
        else if(g_mouse_right_down) {
            camera->Fly(g_translation_speed);
        }
    }

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
        exit(0);
    }

    if(key == ' ') {
        g_fps_mode = !g_fps_mode;

        if(g_fps_mode) {
            glutSetCursor(GLUT_CURSOR_NONE);
            glutWarpPointer(g_viewport_width/2, g_viewport_height/2);
        }
        else {
            glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
        }
    }

    if(glutGetModifiers() == GLUT_ACTIVE_SHIFT) {
        g_shift_down = true;
    }
    else {
        g_shift_down = false;
    }

    keyStates[key] = true;
}

void KeyboardUp(unsigned char key, int x, int y)
{
    keyStates[key] = false;
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
            g_mouse_left_down = true;
        }
        else if(button == GLUT_RIGHT_BUTTON) {
            g_mouse_right_down = true;
        }
    }
    else if(state == GLUT_UP) {
        if(button == GLUT_LEFT_BUTTON) {
            g_mouse_left_down = false;
        }
        else if(button == GLUT_RIGHT_BUTTON) {
            g_mouse_right_down = false;
        }
    }
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




