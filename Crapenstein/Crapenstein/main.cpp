#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <math.h>

//
GLfloat r,g,b;
GLfloat desx,desy;
GLboolean keyStates[256]; // Create an array of boolean values of length 256 (0-255)
const float DEG2RAD = 3.14159/180;
int figure;
//init
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // Cor para apagar (Branco)
    gluOrtho2D(0, 1, 0, 1);
    glShadeModel(GL_FLAT);
    r = 1;
    g = 0;
    g = 0;
    desx = 0;
    desy = 0;
    figure = 0;
}

void keyboard()
{
    if(keyStates['1']) {
            r = 1.0; g = 0.0; b = 0.0;
            glutPostRedisplay();
    }else if(keyStates['2']) {
            r = 0.0; g = 1.0; b = 0.0;
            glutPostRedisplay();
    }else if(keyStates['3']) {
            r = 0.0; g = 0.0; b = 1.0;
            glutPostRedisplay();
    }
    if(keyStates['w'] || keyStates['W']) {
            desx+=0.01;
            glutPostRedisplay();
    }else if(keyStates['s'] || keyStates['S']) {
            desx-=0.01;
            glutPostRedisplay();
    }if(keyStates['d'] || keyStates['D']) {
            desy+=0.01;
            glutPostRedisplay();
    }else if(keyStates['a'] || keyStates['A']) {
            desy-=0.01;
            glutPostRedisplay();
    }
    if(keyStates[27]) {
            exit(0);
    }
    if(keyStates['q'] || keyStates['Q']) {
        keyStates['q']=0;
        keyStates['Q']=0;
        figure++;
        if (figure>2)
            figure=0;
        glutPostRedisplay();
    }
    if(keyStates['e'] ||keyStates['E']) {
        keyStates['e']=0;
        keyStates['E']=0;
        figure--;
        if (figure<0)
            figure=2;
        glutPostRedisplay();
    }
}

void keypressed(unsigned char key, int x, int y)
{
    keyStates[key] = 1; // Set the state of the current key to pressed
    keyboard();
}

void keyUp(unsigned char key, int x, int y)
{
    keyStates[key] = 0; // Set the state of the current key to pressed
}

void quadrado(void)
{
    glColor3f(r, g, b); // Especifica cor actual
    glBegin(GL_POLYGON); // Desenhar o Poligono
    glVertex2f(0.25+desy, 0.25+desx);
    glVertex2f(0.75+desy, 0.25+desx);
    glVertex2f(0.75+desy, 0.75+desx);
    glVertex2f(0.25+desy, 0.75+desx);
    glEnd();
}

void triangulo(void)
{
    glColor3f(r, g, b); // Especifica cor actual
    glBegin(GL_POLYGON); // Desenhar o Poligono
    glVertex2f(0.25+desy, 0.25+desx);
    glVertex2f(0.75+desy, 0.25+desx);
    glVertex2f(0.75+desy, 0.75+desx);
    glEnd();
}


void circle(float radius)
{
    glBegin(GL_POLYGON);
    int i;
    for (i = 0; i < 360; i++)
    {
        float degInRad = i * 3.14159/180;
        glVertex2f(0.5+desy+cos(degInRad)*radius, 0.5+desx+sin(degInRad)*radius);
    }
    glEnd();

}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Apaga o Ecrã
    if (figure==0){
        quadrado();
    }
    else if(figure==1){
        triangulo();
    }
    else{
        circle(0.25);
    }
    keyboard();
    glutSwapBuffers(); //Actualiza o Ecrã

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Iniciar a janela
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Double Mode | RGB
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Teste");

    init();

    glutDisplayFunc(draw);
    glutKeyboardFunc(keypressed);
    glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events

    glutMainLoop();

    return 0;
}
