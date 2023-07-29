#include<iostream>
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <GL/glut.h>
#define PI          3.141516
#include<math.h>
using namespace std;

void filledCircle(float c1, float c2, float r, float x, float y, float z)
{
    int i=0;
    int tringle2=40;

    GLfloat tp2 =2.0f * PI  ;

    glBegin (GL_TRIANGLE_FAN);
    glColor3f(x, y, z);
    glVertex2f (c1,c2);
    for(i= 0;i<=tringle2; i++)
    {
        glVertex2f(
                    c1+(r*cos(i*tp2/tringle2)),
                    c2+(r*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();


}


void bezier_curve4(float x1, float y1, float x2, float y2,float x3, float y3,float x4, float y4)
{
    float t=0;
    glVertex2f(((x1*pow((1-t),3))+x2*3*t*pow((1-t),2)+x3*3*pow(t,2)*(1-t)+x4*pow(t,3)),
    ((y1*pow((1-t),3))+y2*3*t*pow((1-t),2)+y3*3*pow(t,2)*(1-t)+y4*pow(t,3)));
    for (int i = 0; i <=100 ; i++){
        t+=.01;
    glVertex2f(((x1*pow((1-t),3))+x2*3*t*pow((1-t),2)+x3*3*pow(t,2)*(1-t)+x4*pow(t,3)),
               ((y1*pow((1-t),3))+y2*3*t*pow((1-t),2)+y3*3*pow(t,2)*(1-t)+y4*pow(t,3)));
        glVertex2f(((x1*pow((1-t),3))+x2*3*t*pow((1-t),2)+x3*3*pow(t,2)*(1-t)+x4*pow(t,3)),
                   ((y1*pow((1-t),3))+y2*3*t*pow((1-t),2)+y3*3*pow(t,2)*(1-t)+y4*pow(t,3)));

    }
}
void circle(float x, float y, float radius, float height)
{
    int triangleAmount = 360;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= 360; i++)
        glVertex2f(x + (radius * cos(i * 2 * 3.1416 / triangleAmount)), y + (height * sin(i * 2 * 3.1416 / triangleAmount)));
    glEnd();
}

void tree(float x, float y, float height,float r1, float g1, float b1,float r2, float g2, float b2,float r3, float g3, float b3)
{
    //int triangleAmount = 360;



   float block = (height/11);
   float half_block = ((height/11)/2);


    glColor3f(r1,g1,b1);
    circle((x-(2*block)),(y+(6*block)),(3*block),(4*block));
    circle((x+(2*block)),(y+(6*block)),(3*block),(3*block));
    circle(x,(y+(9*block)-half_block),(3*block),(3*block));



   glColor3f(r2,g2,b2);
    circle((x-(2*block)),(y+(5*block)),(2*block),(2*block));
    circle(x , (y+(7*block)),(2*block),(2*block));
    circle((x+(2*block)),(y+(5*block)),(2*block),(2*block));




    glBegin(GL_TRIANGLES);
    glColor3f(r3,g3,b3);
    glVertex2f(x , (y+(6*block)));
    glVertex2f((x-half_block) ,y);
    glVertex2f((x+half_block) ,y);
    glEnd();



   glBegin(GL_TRIANGLES);
    glVertex2f((x-(2*block)), (y+(5*block)));
    glVertex2f(x , (y+(4*block)-half_block));
    glVertex2f(x , (y+(3*block)-half_block));
    glEnd();



   glBegin(GL_TRIANGLES);
    glVertex2f((x+(2*block)), (y+(5*block)));
    glVertex2f(x , (y+(4*block)-half_block));
    glVertex2f(x , (y+(3*block)-half_block));
    glEnd();
}

GLfloat position = 0.0f;
GLfloat speed = 0.02f;
GLfloat positionB = 0.0f;
GLfloat speedB = 0.01f;
float rain  ;



float _rain1x = 0.0;
float _rain2x = 0.0;
float _rain3x = 0.0;
float _rain4x = 0.0;
float _rain5x = 0.0;
float _rain6x = 0.0;
float _rain7x = 0.0;
float _rain8x = 0.0;
float _rain9x = 0.0;
float _rain10x = 0.0;

float _rain1y = 0.0;
float _rain2y = 0.0;
float _rain3y = 0.0;
float _rain4y = 0.0;
float _rain5y = 0.0;
float _rain6y = 0.0;
float _rain7y = 0.0;
float _rain8y = 0.0;
float _rain9y = 0.0;
float _rain10y = 0.0;


int i = 0;

void resetRain()
{
    _rain1y = 0.0;
    _rain2y = 0.0;
    _rain3y = 0.0;
    _rain4y = 0.0;
    _rain5y = 0.0;
    _rain6y = 0.0;
    _rain7y = 0.0;
    _rain8y = 0.0;
    _rain9y = 0.0;
    _rain10y = 0.0;

    i = 0;
}


void update(int value)
{

    if(position > 2.5)
        position = -1.0f;
   // if(position<0)
       // position = 1.15;

    position += speed;

    if(positionB > 2.5)
        positionB = 0.0f;
    if(positionB<0)
        positionB = 1.15;

    positionB += speedB;
    if(rain)
        {
            _rain1y -= .05;
            _rain2y -= .05;
            _rain3y -= .05;
            _rain4y -= .05;
            _rain5y -= .05;
            _rain6y -= .05;
            _rain7y -= .05;
            _rain8y -= .05;
            _rain9y -= .05;
            _rain10y -= .05;
            i += 1;
            _rain1x -= .0055;
            _rain2x -= .0055;
            _rain3x -= .0055;
            _rain4x -= .0055;
            _rain5x -= .0055;
            _rain6x -= .0055;
            _rain7x -= .0055;
            _rain8x -= .0055;
            _rain9x -= .0055;
            _rain10x -= .0055;


    if(_rain1y < -1.9)
    {
        _rain1y = .1;
        _rain1x = 0;
    }
    if(_rain2y < -1.7)
    {
        _rain2y = .3;
        _rain2x = 0;
    }
    if(_rain3y < -1.5)
    {
        _rain3y = .5;
        _rain3x = 0;
    }
    if(_rain4y < -1.3)
    {
        _rain4y = .7;
        _rain4x = 0;
    }
    if(_rain5y < -1.1)
    {
        _rain5y = 0.9;
        _rain5x = 0;
    }
    if(_rain6y < -.9)
    {
        _rain6y = 1.1;
        _rain6x = 0;
    }
    if(_rain7y < -.7)
    {
        _rain7y = 1.3;
        _rain7x = 0;
    }
    if(_rain8y < -.5)
    {
        _rain8y = 1.5;
        _rain8x = 0;
    }
    if(_rain9y < -.3)
    {
        _rain9y = 1.7;
        _rain9x = 0;
    }
    if(_rain10y < -.1)
    {
        _rain10y = 1.9;
        _rain10x = 0;
    }

    if(i == 120)
    {
        resetRain();
    }
        }

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}




void day (void)
{





//glClearColor(0.54f,0.6f,0.33f, 1.0f); // Set background color to black and opaque
glClearColor(0.4f,0.5f,0.4f, 1.0f); // Set background color to black and opaque

glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glLineWidth(1);





glBegin(GL_QUADS);
glColor3f(0.49f,0.93f,0.99f); // sky
glVertex2f(1.0f, 0.60f); // x, y
glVertex2f(1.0f, 1.0f); // x, y
glVertex2f(-1.0f, 1.0f);
glVertex2f(-1.0f, 0.60f); // x, y
 // x, y
/*glBegin(GL_QUADS);
glColor3f(0.89f,1.0f,0.32f);//sky
glVertex2f(-1.0f, 0.60f);
glVertex2f(-1.0f, 1.0f); // x, y
glVertex2f(1.0f, 1.0f); // x, y
glVertex2f(1.0f, 0.60f); // x, y*/



glEnd();





glPushMatrix();
    glTranslatef(position,0.0f,0.0f);   // Cloud left Circle
    filledCircle(-0.85,0.9,0.04, 1.0,1.0,1.0);
    filledCircle(-0.85,0.9,0.04, 1.0,1.0,1.0);
    filledCircle(-0.8,0.9,0.05, 1.0,1.0,1.0);

    filledCircle(-0.7,0.81,0.04, 1.0,1.0,1.0); // Clod MIDDLE Circle
    filledCircle(-0.5,0.81,0.04, 1.0,1.0,1.0);
    filledCircle(-0.6,0.81,0.07, 1.0,1.0,1.0);

    filledCircle(-0.5,0.9,0.04, 1.0,1.0,1.0);  // Cloud RIGHT circle
    filledCircle(-0.3,0.9,0.04, 1.0,1.0,1.0);
    filledCircle(-0.4,0.9,0.07, 1.0,1.0,1.0);
    glPopMatrix();

    // tree(float x, float y, float height,float r1, float g1, float b1,float r2, float g2, float b2,float r3, float g3, float b3)


    glPushMatrix();
glTranslatef(positionB,0.0f,0.0f);
glLineWidth(.1);
    glBegin(GL_LINES);

	glColor3ub(0, 0, 0); // birds
	glVertex2f(-0.45f, 0.85f);    // x, y
    glVertex2f(-0.40f, 0.80f);
    glVertex2f(-0.45f, 0.75f);    // x, y
    glVertex2f(-0.40f, 0.80f);

    glVertex2f(-0.45f, 1.0f);    // x, y
    glVertex2f(-0.40f, 0.95f);
    glVertex2f(-0.45f, 0.90f);    // x, y
    glVertex2f(-0.40f, 0.95f);

    glVertex2f(-0.35f, 0.95f);    // x, y
    glVertex2f(-0.30f, 0.90f);
    glVertex2f(-0.30f, 0.90f);    // x, y
    glVertex2f(-0.35f, 0.85f);


glEnd();
glPopMatrix();

    //glPushMatrix();
    //glTranslatef(0.0f,-position,0.0f);   // Sun
    filledCircle(0.8,0.9,0.07, 1.0,1.0,0.0);
   // glPopMatrix();



    glBegin(GL_QUADS);
    glColor3ub(0, 138, 216); // river Upper Quads
    glVertex2f(1.0f, 0.40f);
    glVertex2f(1.0f, 0.60f);
    glVertex2f(-1.0f, 0.60f);
    glVertex2f(-1.0f, 0.40f);
    glEnd();

glBegin(GL_POLYGON);
glColor3ub(0, 138, 216); // river Lower
glVertex2f(1.0f, -1.0f);
glVertex2f(1.0f, 0.4f);
glVertex2f(0.4f, 0.4f);
glVertex2f(0.5f, 0.3f);
glVertex2f(0.4f, 0.2f);
glVertex2f(0.6f, 0.1f);
glVertex2f(0.3f, -0.3f);
glVertex2f(0.5f, -0.5f);
glVertex2f(0.5f, -0.7f);
glVertex2f(0.4f, -0.8f);
glVertex2f(0.52f, -0.88f);
glVertex2f(0.38f, -0.88f);
glVertex2f(0.6f, -1.0f);
glEnd();


glBegin(GL_LINES);
glLineWidth(5);
	glColor3f(1.0f, 1.0f, 1.0f); //  river side line
	    glVertex2f(0.40f, 0.30f);

	glVertex2f(0.40f, 0.20f);    // x, y
    glEnd();


glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); // upper nouka quads
glVertex2f(0.8f, 0.45f); // x, y
glVertex2f(0.85f, 0.5f); // x, y
glVertex2f(0.55f, 0.5f); // x, y
glVertex2f(0.6f, 0.45f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.8f, 0.0f); //  upper nouka quads
glVertex2f(0.8f, 0.5f); // x, y
glVertex2f(0.75f, 0.55f); // x, y
glVertex2f(0.65f, 0.55f); // x, y
glVertex2f(0.6f, 0.5f); // x, y
glEnd();
glPopMatrix();
    tree(-0.90,0.2,0.40,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);


glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); //  House
glVertex2f(-0.5f, 0.57f); // x, y
glVertex2f(-0.47f, 0.6f); // x, y
glVertex2f(-0.7f, 0.6f); // x, y
glVertex2f(-0.73f, 0.57f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  House 2
glVertex2f(-0.5f, 0.55f); // x, y
glVertex2f(-0.5f, 0.57f); // x, y
glVertex2f(-0.73f, 0.57f); // x, y
glVertex2f(-0.73f, 0.55f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); //  House 3
glVertex2f(-0.5f, 0.45f); // x, y
glVertex2f(-0.5f, 0.55f); // x, y
glVertex2f(-0.73f, 0.55f); // x, y
glVertex2f(-0.73f, 0.45f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  House 4
glVertex2f(-0.5f, 0.43f); // x, y
glVertex2f(-0.5f, 0.45f); // x, y
glVertex2f(-0.73f, 0.45f); // x, y
glVertex2f(-0.73f, 0.43f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); //  House 5
glVertex2f(-0.5f, 0.33f); // x, y
glVertex2f(-0.5f, 0.43f); // x, y
glVertex2f(-0.73f, 0.43f); // x, y
glVertex2f(-0.73f, 0.33f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  House 6
glVertex2f(-0.5f, 0.31f); // x, y
glVertex2f(-0.5f, 0.33f); // x, y
glVertex2f(-0.73f, 0.33f); // x, y
glVertex2f(-0.73f, 0.31f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); //  House 7
glVertex2f(-0.5f, 0.18f); // x, y
glVertex2f(-0.5f, 0.31f); // x, y
glVertex2f(-0.73f, 0.31f); // x, y
glVertex2f(-0.73f, 0.18f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  House 8
glVertex2f(-0.5f, 0.18f); // x, y
glVertex2f(-0.47f, 0.21f); // x, y
glVertex2f(-0.47f, 0.6f); // x, y
glVertex2f(-0.5f, 0.57f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window upper left
glVertex2f(-0.65f, 0.47f); // x, y
glVertex2f(-0.65f, 0.53f); // x, y
glVertex2f(-0.7f, 0.53f); // x, y
glVertex2f(-0.7f, 0.47f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window upper right
glVertex2f(-0.52f, 0.47f); // x, y
glVertex2f(-0.52f, 0.53f); // x, y
glVertex2f(-0.57f, 0.53f); // x, y
glVertex2f(-0.57f, 0.47f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window middle Right
glVertex2f(-0.52f, 0.35f); // x, y
glVertex2f(-0.52f, 0.41f); // x, y
glVertex2f(-0.57f, 0.41f); // x, y
glVertex2f(-0.57f, 0.35f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window middle Left
glVertex2f(-0.65f, 0.35f); // x, y
glVertex2f(-0.65f, 0.41f); // x, y
glVertex2f(-0.7f, 0.41f); // x, y
glVertex2f(-0.7f, 0.35f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //   Window lower Right
glVertex2f(-0.52f, 0.22f); // x, y
glVertex2f(-0.52f, 0.28f); // x, y
glVertex2f(-0.57f, 0.28f); // x, y
glVertex2f(-0.57f, 0.22f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window Lower Left
glVertex2f(-0.65f, 0.22f); // x, y
glVertex2f(-0.65f, 0.28f); // x, y
glVertex2f(-0.7f, 0.28f); // x, y
glVertex2f(-0.7f, 0.22f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Door
glVertex2f(-0.59f, 0.18f); // x, y
glVertex2f(-0.59f, 0.25f); // x, y
glVertex2f(-0.63f, 0.25f); // x, y
glVertex2f(-0.63f, 0.18f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(0.35f, 0.36f, 0.38f); // Bridge
glVertex2f(1.0f, -0.45f); // x, y
glVertex2f(1.0f, -0.25f); // x, y
glVertex2f(-1.0f, -0.25f); // x, y
glVertex2f(-1.0f, -0.45f); // x, y
glEnd();

glLineWidth(0.1);
glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); //  middle bridge White
    glVertex2f(0.95f, -0.35f);    // x, y
    glVertex2f(0.55f, -0.35f);

    glVertex2f(0.45f, -0.35f);    // x, y
    glVertex2f(0.05f, -0.35f);

    glVertex2f(-0.05f, -0.35f);    // x, y
    glVertex2f(-0.45f, -0.35f);

    glVertex2f(-0.55f, -0.35f);    // x, y
    glVertex2f(-0.95f, -0.35f);
    glEnd();


    glLineWidth(1);
  glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // white upper/Lower bridge

    glVertex2f(1.0f, -0.25f);    // x, y
    glVertex2f(-1.0f, -0.25f);

    glVertex2f(1.0f, -0.45f);    // x, y
    glVertex2f(-1.0f, -0.45f);
    glEnd();

    glBegin(GL_POLYGON);
glColor3f(0.8f, 0.8f, 0.8f); // bridge pillar right
glVertex2f(0.8f, -0.5f); // x, y
glVertex2f(0.9f, -0.45f); // x, y
glVertex2f(0.6f, -0.45f);
glVertex2f(0.7f, -0.5f); // x, y
glVertex2f(0.7f, -0.6f); // x, y
glVertex2f(0.8f, -0.6f); // x, y
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.8f, 0.8f, 0.8f); // bridge pillar middle
glVertex2f(0.1f, -0.5f); // x, y
glVertex2f(0.2f, -0.45f); // x, y
glVertex2f(-0.1f, -0.45f);
glVertex2f(0.0f, -0.5f); // x, y
glVertex2f(0.0f, -0.65f); // x, y
glVertex2f(0.1f, -0.65f); // x, y
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.8f, 0.8f, 0.8f); // bridge pillar left
glVertex2f(-0.6f, -0.5f); // x, y
glVertex2f(-0.5f, -0.45f); // x, y
glVertex2f(-0.8f, -0.45f);
glVertex2f(-0.7f, -0.5f); // x, y
glVertex2f(-0.7f, -0.7f); // x, y
glVertex2f(-0.6f, -0.7f); // x, y
glEnd();








glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); //  lower nouka quads
glVertex2f(0.75f, -0.75f); // x, y
glVertex2f(0.75f, -0.65f); // x, y
glVertex2f(0.65f, -0.65f); // x, y
glVertex2f(0.65f, -0.75f); // x, y
glEnd();

glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); // Nouka left
      glVertex2f(0.65f, -0.75f);    // x, y
	glVertex2f(0.57f, -0.7f);    // x, y
	glVertex2f(0.65f, -0.7f);    // x, y
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); // Nouka Right
      glVertex2f(0.75f, -0.75f);    // x, y
	glVertex2f(0.83f, -0.7f);    // x, y
	glVertex2f(0.75f, -0.7f);    // x, y
	glEnd();

glBegin(GL_POLYGON);
//glColor3f(0.04f,0.54f,0.07f); // hill left
glColor3f(0.04f,0.43f,0.07f);
glVertex2f(-1.0f, 0.6f);
glVertex2f(-0.90f, 0.63f);
glVertex2f(-0.88f, 0.70f);
glVertex2f(-0.81f, 0.75f);
glVertex2f(-0.74f, 0.80f);
glVertex2f(-0.6f, 0.70f);
glVertex2f(-0.53f, 0.63f);
glVertex2f(-0.5f, 0.60f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.04f,0.43f,0.07f);//  middle hill
glVertex2f(-0.5f, 0.60f);
glVertex2f(-0.40f, 0.70f);
glVertex2f(-0.20f, 0.80f);
glVertex2f(0.0f, 0.70f);
glVertex2f(0.11f, 0.60f);
glEnd();


glBegin(GL_POLYGON);
glColor3f(0.43f,0.63f,0.51f);//  middle hill shadow
glVertex2f(0.03f, 0.60f);
glVertex2f(0.11f, 0.60f);

glVertex2f(-0.02f, 0.71f);

//glVertex2f(0.11f, 0.60f);
//glVertex2f(0.50f, 0.65f);
//glVertex2f(-0.02f, 0.72f);
glVertex2f(0.0f, 0.70f);
//glVertex2f(0.03f, 0.60f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.04f,0.43f,0.07f); // hill right
glVertex2f(0.11f, 0.60f);
glVertex2f(0.19f, 0.69f);
glVertex2f(0.22f, 0.65f);
glVertex2f(0.40f, 0.80f);
glVertex2f(0.62f, 0.60f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.04f,0.43f,0.07f); // hill last
glVertex2f(0.62f, 0.60f);
glVertex2f(0.70f, 0.66f);
glVertex2f(0.73f, 0.63f);
glVertex2f(0.82f, 0.70f);
glVertex2f(0.84f, 0.67f);
glVertex2f(1.0f, 0.83f);
glVertex2f(1.0f, 0.60f);


glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  house 2nd
glVertex2f(-0.2f, 0.2f); // x, y
glVertex2f(-0.2f, 0.55f); // x, y
glVertex2f(-0.40f, 0.55f); // x, y
glVertex2f(-0.40f, 0.20f); // x, y
glEnd();



glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd shade
glVertex2f(-0.2f, 0.53f); // x, y
glVertex2f(-0.2f, 0.55f); // x, y
glVertex2f(-0.40f, 0.55f); // x, y
glVertex2f(-0.40f, 0.53f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.33f, 0.41f); // x, y
glVertex2f(-0.33f, 0.47f); // x, y
glVertex2f(-0.37f, 0.47f); // x, y
glVertex2f(-0.37f, 0.41f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.33f, 0.33f); // x, y
glVertex2f(-0.33f, 0.38f); // x, y
glVertex2f(-0.37f, 0.38f); // x, y
glVertex2f(-0.37f, 0.33f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.33f, 0.25f); // x, y
glVertex2f(-0.33f, 0.29f); // x, y
glVertex2f(-0.37f, 0.29f); // x, y
glVertex2f(-0.37f, 0.25f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.24f, 0.41f); // x, y
glVertex2f(-0.24f, 0.47f); // x, y
glVertex2f(-0.28f, 0.47f); // x, y
glVertex2f(-0.28f, 0.41f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.24f, 0.33f); // x, y
glVertex2f(-0.24f, 0.38f); // x, y
glVertex2f(-0.28f, 0.38f); // x, y
glVertex2f(-0.28f, 0.33f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.24f, 0.25f); // x, y
glVertex2f(-0.24f, 0.29f); // x, y
glVertex2f(-0.28f, 0.29f); // x, y
glVertex2f(-0.28f, 0.25f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  house 3rd
glVertex2f(0.04f, 0.2f); // x, y
glVertex2f(0.04f, 0.60f); // x, y
glVertex2f(-0.14f, 0.60f); // x, y
glVertex2f(-0.14f, 0.20f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd shade
glVertex2f(0.04f, 0.58f); // x, y
glVertex2f(0.04f, 0.60f); // x, y
glVertex2f(-0.14f, 0.60f); // x, y
glVertex2f(-0.14f, 0.58f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(-0.08f, 0.46f); // x, y
glVertex2f(-0.08f, 0.53f); // x, y
glVertex2f(-0.11f, 0.53f); // x, y
glVertex2f(-0.11f, 0.46f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(-0.08f, 0.38f); // x, y
glVertex2f(-0.08f, 0.44f); // x, y
glVertex2f(-0.11f, 0.44f); // x, y
glVertex2f(-0.11f, 0.38f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(-0.08f, 0.30f); // x, y
glVertex2f(-0.08f, 0.35f); // x, y
glVertex2f(-0.11f, 0.35f); // x, y
glVertex2f(-0.11f, 0.30f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(-0.08f, 0.22f); // x, y
glVertex2f(-0.08f, 0.26f); // x, y
glVertex2f(-0.11f, 0.26f); // x, y
glVertex2f(-0.11f, 0.22f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(0.0f, 0.46f); // x, y
glVertex2f(0.0f, 0.53f); // x, y
glVertex2f(-0.03f, 0.53f); // x, y
glVertex2f(-0.03f, 0.46f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(0.0f, 0.38f); // x, y
glVertex2f(0.0f, 0.44f); // x, y
glVertex2f(-0.03f, 0.44f); // x, y
glVertex2f(-0.03f, 0.38f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(0.0f, 0.30f); // x, y
glVertex2f(0.0f, 0.35f); // x, y
glVertex2f(-0.03f, 0.35f); // x, y
glVertex2f(-0.03f, 0.30f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(0.0f, 0.22f); // x, y
glVertex2f(0.0f, 0.26f); // x, y
glVertex2f(-0.03f, 0.26f); // x, y
glVertex2f(-0.03f, 0.22f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  house 4th
glVertex2f(0.22f, 0.2f); // x, y
glVertex2f(0.22f, 0.60f); // x, y
glVertex2f(0.08f, 0.60f); // x, y
glVertex2f(0.08f, 0.20f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.22f, 0.58f); // x, y
glVertex2f(0.22f, 0.60f); // x, y
glVertex2f(0.08f, 0.60f); // x, y
glVertex2f(0.08f, 0.58f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.14f, 0.46f); // x, y
glVertex2f(0.14f, 0.53f); // x, y
glVertex2f(0.11f, 0.53f); // x, y
glVertex2f(0.11f, 0.46f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.14f, 0.38f); // x, y
glVertex2f(0.14f, 0.44f); // x, y
glVertex2f(0.11f, 0.44f); // x, y
glVertex2f(0.11f, 0.38f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.14f, 0.30f); // x, y
glVertex2f(0.14f, 0.35f); // x, y
glVertex2f(0.11f, 0.35f); // x, y
glVertex2f(0.11f, 0.30f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.14f, 0.22f); // x, y
glVertex2f(0.14f, 0.26f); // x, y
glVertex2f(0.11f, 0.26f); // x, y
glVertex2f(0.11f, 0.22f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.20f, 0.46f); // x, y
glVertex2f(0.20f, 0.53f); // x, y
glVertex2f(0.17f, 0.53f); // x, y
glVertex2f(0.17f, 0.46f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.20f, 0.38f); // x, y
glVertex2f(0.20f, 0.44f); // x, y
glVertex2f(0.17f, 0.44f); // x, y
glVertex2f(0.17f, 0.38f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.20f, 0.30f); // x, y
glVertex2f(0.20f, 0.35f); // x, y
glVertex2f(0.17f, 0.35f); // x, y
glVertex2f(0.17f, 0.30f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.20f, 0.22f); // x, y
glVertex2f(0.20f, 0.26f); // x, y
glVertex2f(0.17f, 0.26f); // x, y
glVertex2f(0.17f, 0.22f); // x, y
glEnd();



glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
glBegin(GL_POLYGON);
    glColor3ub(255, 69, 0); // Car left
    glVertex2f(0.71f, -0.31f);
    glVertex2f(0.89f, -0.31f);
    glVertex2f(0.91f, -0.28f);
    glVertex2f(0.91f, -0.23f);
    glVertex2f(0.885f, -0.19f);
    glVertex2f(0.79f, -0.19f);
    glVertex2f(0.76f, -0.24f);
    glVertex2f(0.71f, -0.24f);
    glVertex2f(0.7f, -0.25f);
    glVertex2f(0.7f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
glColor3ub(248, 248, 255); // Window 1st
glVertex2f(0.769f, -0.24f); // x, y
glVertex2f(0.82f, -0.24f); // x, y
glVertex2f(0.82f, -0.2f); // x, y
glVertex2f(0.7909f, -0.2f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3ub(248, 248, 255); // Window 2nd
glVertex2f(0.84f, -0.24f); // x, y
glVertex2f(0.89f, -0.24f); // x, y
glVertex2f(0.869f, -0.2f); // x, y
glVertex2f(0.84f, -0.2f); // x, y
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f); //
    glVertex2f(0.805f, -0.25f);    // Car line
    glVertex2f(0.82f, -0.25f);
    glEnd();

    glLineWidth(2);
glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f); //
    glVertex2f(0.885f, -0.25f);    // Car line
    glVertex2f(0.87f, -0.25f);
    glEnd();

     glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Right  car Dhoya
    glVertex2f(0.91f, -0.297f);
    glVertex2f(0.93f, -0.297f);

    glVertex2f(0.917f, -0.312f);
    glVertex2f(0.937f, -0.312f);

    glVertex2f(0.91f, -0.326f);
    glVertex2f(0.93f, -0.326f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); //  Right car light
    glVertex2f(0.7f, -0.27f); // x, y
    glVertex2f(0.7f, -0.26f); // x, y
    glVertex2f(0.695f, -0.26f); // x, y
    glVertex2f(0.695f, -0.27f); // x, y
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); //  Right car light
    glVertex2f(0.7f, -0.29f); // x, y
    glVertex2f(0.7f, -0.28f); // x, y
    glVertex2f(0.695f, -0.28f); // x, y
    glVertex2f(0.695f, -0.29f); // x, y
    glEnd();

    filledCircle(0.75,-0.31,0.03, 0.0,0.0,0.0);  // Front wheel Car
    filledCircle(0.75,-0.31,0.015, 1.0,1.0,1.0);

    filledCircle(0.85,-0.31,0.03, 0.0,0.0,0.0);  // Back wheel Car
    filledCircle(0.85,-0.31,0.015, 1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
glTranslatef(position,0.0f,0.0f);

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); //  Truck
glVertex2f(-0.92f, -0.41f); // x, y
glVertex2f(-0.8f, -0.41f); // x, y
glVertex2f(-0.8f, -0.36f); // x, y
glVertex2f(-0.92f, -0.36f); // x, y
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0f, 0.0f, 0.0f); // Truck 1 left
glVertex2f(-0.8f, -0.41f);
glVertex2f(-0.7f, -0.41f);
glVertex2f(-0.7f, -0.35f);
glVertex2f(-0.74f, -0.29f);
glVertex2f(-0.8f, -0.29f);
glEnd();

filledCircle(-0.86,-0.41,0.03, 0.0,0.0,0.0); // Front wheel track
filledCircle(-0.86,-0.41,0.015, 1.0,1.0,1.0);

filledCircle(-0.75,-0.41,0.03, 0.0,0.0,0.0); // Back wheel Track
filledCircle(-0.75,-0.41,0.015, 1.0,1.0,1.0);

glBegin(GL_QUADS);
glColor3ub(248, 248, 255);  //  Truck middle white
glVertex2f(-0.78f, -0.35f); // x, y
glVertex2f(-0.725f, -0.35f); // x, y
glVertex2f(-0.75f, -0.31f); // x, y
glVertex2f(-0.78f, -0.31f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f); //  Truck Load space
glVertex2f(-0.8f, -0.36f); // x, y
glVertex2f(-0.8f, -0.26f); // x, y
glVertex2f(-0.92f, -0.26f); // x, y
glVertex2f(-0.92f, -0.36f); // x, y
glEnd();

glLineWidth(5);
glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f); //
    glVertex2f(-0.92f, -0.28f);    // Truck load line  upper
    glVertex2f(-0.97f, -0.28f);

    glVertex2f(-0.92f, -0.3f);    // Truck load line  middle
    glVertex2f(-0.95f, -0.3f);

    glVertex2f(-0.92f, -0.32f);    // Truck load line  lower
    glVertex2f(-0.935f, -0.32f);
    glEnd();

     glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // left Truck Dhoya
    glVertex2f(-0.93f, -0.393f);
    glVertex2f(-0.95f, -0.393f);

    glVertex2f(-0.94f, -0.407f);
    glVertex2f(-0.96f, -0.407f);

    glVertex2f(-0.93f, -0.419f);
    glVertex2f(-0.95f, -0.419f);
    glEnd();

     glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); // Truck Light
glVertex2f(-0.7f, -0.39f);
glVertex2f(-0.7f, -0.37f);
glVertex2f(-0.696f, -0.37f);
glVertex2f(-0.696f, -0.39f);
glEnd();
glPopMatrix();

//rains <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  glPopMatrix();
    glLoadIdentity();

    glPopMatrix();

    glPopMatrix();

    if(rain)
    {
        glPushMatrix();
        glTranslatef(_rain1x,_rain1y,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);

     glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();

        //rain 2 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain2x,_rain2y,0);

        glPushMatrix();
        glTranslatef(-.02,-.2,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 3 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain3x,_rain3y,0);

        glPushMatrix();
        glTranslatef(-.0,-.4,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();


        //rain 4 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain4x,_rain4y,0);

        glPushMatrix();
        glTranslatef(-.03,-.6,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 5 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain5x,_rain5y,0);

        glPushMatrix();
        glTranslatef(-.03,-.8,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();


        //rain 6 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain6x,_rain6y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 7 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain7x,_rain7y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.2,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();


        //rain 8 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain8x,_rain8y,0);

        glPushMatrix();
        glTranslatef(-.0,-1.4,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 9 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain9x,_rain9y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.6,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 10 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain10x,_rain10y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.8,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();
    }

glBegin(GL_QUADS);
glColor3f(0.0f,1.0f,0.0f); //  Football Play Ground
glVertex2f(0.05f, -0.15f); // x, y
glVertex2f(0.35f, -0.15f); // x, y
glVertex2f(0.35f, 0.05f); // x, y
glVertex2f(0.05f, 0.05f); // x, y
glEnd();




    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); //  Football line
    glVertex2f(0.2f, -0.15f);    // x, y
    glVertex2f(0.2f, 0.05f);
    glEnd();



   filledCircle(0.2,-0.05,0.04, 1.0,1.0,1.0);



   glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f); //  goal post left
glVertex2f(0.05f, -0.09f); // x, y
glVertex2f(0.08f, -0.09f); // x, y
glVertex2f(0.08f, -0.01f); // x, y
glVertex2f(0.05f, -0.01f); // x, y
glEnd();



glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f); //  goal post right
glVertex2f(0.35f, -0.09f); // x, y
glVertex2f(0.32f, -0.09f); // x, y
glVertex2f(0.32f, -0.01f); // x, y
glVertex2f(0.35f, -0.01f); // x, y
glEnd();



glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); //
    glVertex2f(0.05f, -0.15f);    // x, y
    glVertex2f(0.35f, -0.15f);



   glVertex2f(0.05f, 0.05f);    // x, y
    glVertex2f(0.35f, 0.05f);



   glVertex2f(0.05f, 0.05f);    // x, y
    glVertex2f(0.05f, -0.15f);



   glVertex2f(0.35f, 0.05f);    // x, y
    glVertex2f(0.35f, -0.15f);






    glEnd();
        tree(-0.90,-0.80,0.2,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);


    glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f); // house a
glVertex2f(-0.88f, -0.84f);    // x, y
glVertex2f(-0.86f, -0.8f);    // x, y
glVertex2f(-0.82f, -0.84f);    // x, y
glEnd();

   glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); // house a
glVertex2f(-0.86f, -0.8f);
glVertex2f(-0.75f, -0.8f);
glVertex2f(-0.73f, -0.84f);
glVertex2f(-0.84f, -0.84f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.5f); // house a
glVertex2f(-0.84f, -0.84f);
glVertex2f(-0.73f, -0.84f);
glVertex2f(-0.73f, -0.9f);
glVertex2f(-0.84f, -0.9f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 1.0f); // house a
glVertex2f(-0.88f, -0.84f);
glVertex2f(-0.84f, -0.84f);
glVertex2f(-0.84f, -0.9f);
glVertex2f(-0.88f, -0.9f);
glEnd();
glPopMatrix();
glBegin(GL_QUADS);
glColor3f(1.0f, 0.5f, 0.0f); // house a floor
glVertex2f(-0.88f, -0.9f);
glVertex2f(-0.84f, -0.9f);
glVertex2f(-0.84f, -0.92f);
glVertex2f(-0.90f, -0.92f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.10f); // house a floor
glVertex2f(-0.84f, -0.9f);
glVertex2f(-0.73f, -0.9f);
glVertex2f(-0.71f, -0.92f);
glVertex2f(-0.84f, -0.92f);
glEnd();
glPopMatrix();



glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); // house a door
glVertex2f(-0.8f, -0.86f);
glVertex2f(-0.78f, -0.86f);
glVertex2f(-0.78f, -0.9f);
glVertex2f(-0.8f, -0.9f);
glEnd();
glPopMatrix();

glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f); // house j
glVertex2f(-0.73f, -0.84f);    // x, y
glVertex2f(-0.71f, -0.8f);    // x, y
glVertex2f(-0.69f, -0.84f);    // x, y
glEnd();
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); // house j
glVertex2f(-0.71f, -0.8f);
glVertex2f(-0.64f, -0.8f);
glVertex2f(-0.62f, -0.84f);
glVertex2f(-0.69f, -0.84f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); // house j
glVertex2f(-0.69f, -0.84f);
glVertex2f(-0.62f, -0.84f);
glVertex2f(-0.62f, -0.9f);
glVertex2f(-0.69f, -0.9f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 0.0f); // house j
glVertex2f(-0.73f, -0.84f);
glVertex2f(-0.69f, -0.84f);
glVertex2f(-0.69f, -0.9f);
glVertex2f(-0.73f, -0.9f);
glEnd();
glPopMatrix();
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); // house j door
glVertex2f(-0.66f, -0.86f);
glVertex2f(-0.64f, -0.86f);
glVertex2f(-0.64f, -0.9f);
glVertex2f(-0.66f, -0.9f);
glEnd();
glPopMatrix();


glBegin(GL_QUADS);
glColor3f(1.0f, 0.5f, 0.0f); // house j floor
glVertex2f(-0.73f, -0.9f);
glVertex2f(-0.69f, -0.9f);
glVertex2f(-0.69f, -0.92f);
glVertex2f(-0.71f, -0.92f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.5f, 0.10f); // house j floor
glVertex2f(-0.69f, -0.9f);
glVertex2f(-0.62f, -0.9f);
glVertex2f(-0.60f, -0.92f);
glVertex2f(-0.69f, -0.92f);
glEnd();
glPopMatrix();

glBegin(GL_TRIANGLES);
glColor3f(1.0f, 1.0f, 1.0f); //  house g 1st part
glVertex2f(-0.99f, -0.8f);    // x, y
glVertex2f(-0.97f, -0.77f);    // x, y
glVertex2f(-0.95f, -0.8f);    // x, y
glEnd();

   glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f); // house g 2nd part
glVertex2f(-0.97f, -0.77f);
glVertex2f(-0.87f, -0.77f);
glVertex2f(-0.84f, -0.8f);
glVertex2f(-0.95f, -0.8f);
glEnd();
glPopMatrix();

   glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // house g 3rd
glVertex2f(-0.99f, -0.8f);
glVertex2f(-0.95f, -0.8f);
glVertex2f(-0.95f, -0.88f);
glVertex2f(-0.99f, -0.88f);
glEnd();
glPopMatrix();

glBegin(GL_POLYGON);
glColor3f(0.5f,0.5f,1.0f); // house g 4th
glVertex2f(-0.95f, -0.8f);
glVertex2f(-0.86f,- 0.8f);
glVertex2f(-0.88f, -0.84f);
glVertex2f(-0.88f, -0.88f);
glVertex2f(-0.95f, -0.88f);
glEnd();
 glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // house g window
glVertex2f(-0.92f, -0.82f);
glVertex2f(-0.88f, -0.82f);
glVertex2f(-0.88f, -0.85f);
glVertex2f(-0.92f, -0.85f);
glEnd();
glPopMatrix();

     glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); // house g floor
glVertex2f(-0.99f, -0.88f);
glVertex2f(-0.88f, -0.88f);
glVertex2f(-0.88f, -0.90f);
glVertex2f(-1.0f, -0.90f);
glEnd();
glPopMatrix();
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 0.0f); // lower puj
glVertex2f(0.3f, -0.9f); // x, y
glVertex2f(0.3f, -0.75f); // x, y
glVertex2f(0.26f, -0.7f);
glVertex2f(0.2f, -0.65f); // x, y
glVertex2f(0.14f, -0.7f); // x, y
glVertex2f(0.1f, -0.75f); // x, y
glVertex2f(0.1f, -0.9f); // x, y
glEnd();

glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f); // Puj Line
	glVertex2f(0.2f, -0.66f);
    glVertex2f(0.2f, -0.6f);
    glEnd();
    glBegin(GL_QUADS);
glColor3f(0.0f,0.0f,0.0f); //  Bench_upper side
glVertex2f(-0.933f, -0.068f); // x, y
glVertex2f(-0.90f, 0.060f); // x, y
glVertex2f(-0.94f, 0.10f); // x, y
glVertex2f(-0.979f, -0.020f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f);//  Bench_lower side
glVertex2f(-0.88f, -0.071f); // x, y
glVertex2f(-0.84f, 0.080f); // x, y
glVertex2f(-0.900f, 0.060f); // x, y
glVertex2f(-0.933f, -0.068f); // x, y
glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); //  Bench left leg 1
	glVertex2f(-0.882f, -0.124f);    // x, y
    glVertex2f(-0.882f, -0.067f);
    glEnd();


    glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);  //  Bench left leg 2
	glVertex2f(-0.931f, -0.121f);    // x, y
    glVertex2f(-0.931f, -0.067f);
    glEnd();
 glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); //  Bench left leg 3
	glVertex2f(-0.928f, -0.098f);    // x, y
    glVertex2f(-0.881f, -0.108f);
    glEnd();

        glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); //  Bench right leg 1
	glVertex2f(-0.824f, 0.021f);    // x, y
    glVertex2f(-0.842f, 0.057f);
    glEnd();

            glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); //  Bench right leg 2
	glVertex2f(-0.830f, 0.035f);    // x, y
    glVertex2f(-0.846f, 0.036f);
    glEnd();

     glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); //  Bench sit line 1
	glVertex2f(-0.891f, -0.048f);    // x, y
    glVertex2f(-0.861f, 0.062f);
    glEnd();
 glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); //  Bench sit line 2
	glVertex2f(-0.884f, 0.060f);    // x, y
    glVertex2f(-0.912f, -0.036f);
    glEnd();
        glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 255.0f, 0.0f); //  flower-tree 1
	glVertex2f(-0.3f, 0.0f);    // x, y
    glVertex2f(-0.240f, 0.022f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.361f, 0.022f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.260f, 0.034f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.349f, 0.040f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.3f, 0.05f);
    glEnd();


    glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 255.0f, 0.0f); //  flower-tree 2
	glVertex2f(-0.500f, 0.018f);    // x, y
    glVertex2f(-0.500f, 0.060f);
    glVertex2f(-0.500f, 0.018f);
    glVertex2f(-0.469f, 0.051f);
    glVertex2f(-0.500f, 0.018f);
    glVertex2f(-0.450f, 0.039f);
    glVertex2f(-0.500f, 0.018f);
    glVertex2f(-0.529f, 0.050f);
    glVertex2f(-0.500f, 0.018f);
    glVertex2f(-0.551f, 0.040f);
    glEnd();


    glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 255.0f, 0.0f); //  flower-tree 3
	glVertex2f(-0.125f, -0.050f);    // x, y
    glVertex2f(-0.129f, -0.008f);
    glVertex2f(-0.125f, -0.050f);
    glVertex2f(-0.090f, -0.020f);
    glVertex2f(-0.125f, -0.050f);
    glVertex2f(-0.080f, -0.041f);
    glVertex2f(-0.125f, -0.050f);
    glVertex2f(-0.171f, -0.019f);
    glVertex2f(-0.125f, -0.050f);
    glVertex2f(-0.181f, -0.040f);
    glEnd();


    glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 255.0f, 0.0f); //  flower-tree 4
	glVertex2f(-0.669f, -0.031f);    // x, y
    glVertex2f(-0.670f, -0.001f);
    glVertex2f(-0.669f, -0.031f);
    glVertex2f(-0.641f, -0.008f);
    glVertex2f(-0.669f, -0.031f);
    glVertex2f(-0.627f, -0.022f);
    glVertex2f(-0.669f, -0.031f);
    glVertex2f(-0.698f, -0.009f);
    glVertex2f(-0.669f, -0.031f);
    glVertex2f(-0.712f, -0.022f);
    glEnd();

filledCircle(-0.129,-0.008,0.01, 1.0,0.0,0.0); //flower
filledCircle(-0.090,-0.020,0.01, 1.0,1.0,0.0);
filledCircle(-0.171,-0.019,0.01, 1.0,1.0,0.0);

filledCircle(-0.3,0.05,0.01, 1.0,1.0,0.0);
filledCircle(-0.349,0.040,0.01, 1.0,0.0,0.0);
filledCircle(-0.260,0.034,0.01, 1.0,0.0,0.0);


filledCircle(-0.501,0.060,0.01, 1.0,0.0,0.0);
filledCircle(-0.529,0.0505,0.01, 1.0,1.0,0.0);
filledCircle(-0.469,0.0510,0.01, 1.0,1.0,0.0);

filledCircle(-0.670,0.001,0.01, 1.0,1.0,0.0);
filledCircle(-0.641,-0.0086,0.01, 1.0,0.0,0.0);
filledCircle(-0.698,-0.009,0.01, 1.0,0.0,0.0);


     tree(-0.50,-1.0,0.2,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);
     tree(0.58,0.63,0.1,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);
    tree(0.12,0.60,0.1,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);
    tree(-0.50,0.60,0.1,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);
    tree(-0.40,-1.0,0.2,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);









glFlush(); // Render now
}


void night (void)
{




//glClearColor(0.54f,0.6f,0.33f, 1.0f); // Set background color to black and opaque
glClearColor(0.4f,0.5f,0.4f, 1.0f); // Set background color to black and opaque

glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glLineWidth(1);



glBegin(GL_QUADS);
glColor3f(0.12f,0.13f,0.27f); // sky
glVertex2f(1.0f, 0.60f); // x, y
glVertex2f(1.0f, 1.0f); // x, y
glVertex2f(-1.0f, 1.0f);
glVertex2f(-1.0f, 0.60f); // x, y
 // x, y
/*glBegin(GL_QUADS);
glColor3f(0.89f,1.0f,0.32f);//sky
glVertex2f(-1.0f, 0.60f);
glVertex2f(-1.0f, 1.0f); // x, y
glVertex2f(1.0f, 1.0f); // x, y
glVertex2f(1.0f, 0.60f); // x, y*/



glEnd();





glPushMatrix();
    glTranslatef(position,0.0f,0.0f);   // Cloud left Circle
    filledCircle(-0.85,0.9,0.04, 1.0,1.0,1.0);
    filledCircle(-0.85,0.9,0.04, 1.0,1.0,1.0);
    filledCircle(-0.8,0.9,0.05, 1.0,1.0,1.0);

    filledCircle(-0.7,0.81,0.04, 1.0,1.0,1.0); // Clod MIDDLE Circle
    filledCircle(-0.5,0.81,0.04, 1.0,1.0,1.0);
    filledCircle(-0.6,0.81,0.07, 1.0,1.0,1.0);

    filledCircle(-0.5,0.9,0.04, 1.0,1.0,1.0);  // Cloud RIGHT circle
    filledCircle(-0.3,0.9,0.04, 1.0,1.0,1.0);
    filledCircle(-0.4,0.9,0.07, 1.0,1.0,1.0);
    glPopMatrix();



    //glPushMatrix();
    //glTranslatef(0.0f,-position,0.0f);   // Sun
    filledCircle(0.8,0.9,0.07, 0.85,0.85,0.85);
   // glPopMatrix();



    glBegin(GL_QUADS);
glColor3f(0.03f,0.3f,0.37f); // river upper
    glVertex2f(1.0f, 0.40f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-1.0f, 0.40f);
    glEnd();

glBegin(GL_POLYGON);
glColor3f(0.03f,0.3f,0.37f); // river lower
glVertex2f(1.0f, -1.0f);
glVertex2f(1.0f, 0.4f);
glVertex2f(0.4f, 0.4f);
glVertex2f(0.5f, 0.3f);
glVertex2f(0.4f, 0.2f);
glVertex2f(0.6f, 0.1f);
glVertex2f(0.3f, -0.3f);
glVertex2f(0.5f, -0.5f);
glVertex2f(0.5f, -0.7f);
glVertex2f(0.4f, -0.8f);
glVertex2f(0.52f, -0.88f);
glVertex2f(0.38f, -0.88f);
glVertex2f(0.6f, -1.0f);
glEnd();


glBegin(GL_LINES);
glLineWidth(5);
	glColor3f(1.0f, 1.0f, 1.0f); //  river side line
	    glVertex2f(0.40f, 0.30f);

	glVertex2f(0.40f, 0.20f);    // x, y
    glEnd();



glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); // upper nouka quads
glVertex2f(0.8f, 0.45f); // x, y
glVertex2f(0.85f, 0.5f); // x, y
glVertex2f(0.55f, 0.5f); // x, y
glVertex2f(0.6f, 0.45f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.8f, 0.0f); //  upper nouka quads
glVertex2f(0.8f, 0.5f); // x, y
glVertex2f(0.75f, 0.55f); // x, y
glVertex2f(0.65f, 0.55f); // x, y
glVertex2f(0.6f, 0.5f); // x, y
glEnd();
glPopMatrix();
    tree(-0.90,0.30,0.25,0.09f,0.08f,0.27f,0.04f,0.04f,0.12f,0.32f,0.2f,0.05f);


glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); //  House
glVertex2f(-0.5f, 0.57f); // x, y
glVertex2f(-0.47f, 0.6f); // x, y
glVertex2f(-0.7f, 0.6f); // x, y
glVertex2f(-0.73f, 0.57f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  House 2
glVertex2f(-0.5f, 0.55f); // x, y
glVertex2f(-0.5f, 0.57f); // x, y
glVertex2f(-0.73f, 0.57f); // x, y
glVertex2f(-0.73f, 0.55f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); //  House 3
glVertex2f(-0.5f, 0.45f); // x, y
glVertex2f(-0.5f, 0.55f); // x, y
glVertex2f(-0.73f, 0.55f); // x, y
glVertex2f(-0.73f, 0.45f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  House 4
glVertex2f(-0.5f, 0.43f); // x, y
glVertex2f(-0.5f, 0.45f); // x, y
glVertex2f(-0.73f, 0.45f); // x, y
glVertex2f(-0.73f, 0.43f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); //  House 5
glVertex2f(-0.5f, 0.33f); // x, y
glVertex2f(-0.5f, 0.43f); // x, y
glVertex2f(-0.73f, 0.43f); // x, y
glVertex2f(-0.73f, 0.33f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  House 6
glVertex2f(-0.5f, 0.31f); // x, y
glVertex2f(-0.5f, 0.33f); // x, y
glVertex2f(-0.73f, 0.33f); // x, y
glVertex2f(-0.73f, 0.31f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); //  House 7
glVertex2f(-0.5f, 0.18f); // x, y
glVertex2f(-0.5f, 0.31f); // x, y
glVertex2f(-0.73f, 0.31f); // x, y
glVertex2f(-0.73f, 0.18f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  House 8
glVertex2f(-0.5f, 0.18f); // x, y
glVertex2f(-0.47f, 0.21f); // x, y
glVertex2f(-0.47f, 0.6f); // x, y
glVertex2f(-0.5f, 0.57f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window upper left
glVertex2f(-0.65f, 0.47f); // x, y
glVertex2f(-0.65f, 0.53f); // x, y
glVertex2f(-0.7f, 0.53f); // x, y
glVertex2f(-0.7f, 0.47f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window upper right
glVertex2f(-0.52f, 0.47f); // x, y
glVertex2f(-0.52f, 0.53f); // x, y
glVertex2f(-0.57f, 0.53f); // x, y
glVertex2f(-0.57f, 0.47f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window middle Right
glVertex2f(-0.52f, 0.35f); // x, y
glVertex2f(-0.52f, 0.41f); // x, y
glVertex2f(-0.57f, 0.41f); // x, y
glVertex2f(-0.57f, 0.35f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window middle Left
glVertex2f(-0.65f, 0.35f); // x, y
glVertex2f(-0.65f, 0.41f); // x, y
glVertex2f(-0.7f, 0.41f); // x, y
glVertex2f(-0.7f, 0.35f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //   Window lower Right
glVertex2f(-0.52f, 0.22f); // x, y
glVertex2f(-0.52f, 0.28f); // x, y
glVertex2f(-0.57f, 0.28f); // x, y
glVertex2f(-0.57f, 0.22f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window Lower Left
glVertex2f(-0.65f, 0.22f); // x, y
glVertex2f(-0.65f, 0.28f); // x, y
glVertex2f(-0.7f, 0.28f); // x, y
glVertex2f(-0.7f, 0.22f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Door
glVertex2f(-0.59f, 0.18f); // x, y
glVertex2f(-0.59f, 0.25f); // x, y
glVertex2f(-0.63f, 0.25f); // x, y
glVertex2f(-0.63f, 0.18f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(0.35f, 0.36f, 0.38f); // Bridge
glVertex2f(1.0f, -0.45f); // x, y
glVertex2f(1.0f, -0.25f); // x, y
glVertex2f(-1.0f, -0.25f); // x, y
glVertex2f(-1.0f, -0.45f); // x, y
glEnd();

glLineWidth(0.1);
glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); //  middle bridge White
    glVertex2f(0.95f, -0.35f);    // x, y
    glVertex2f(0.55f, -0.35f);

    glVertex2f(0.45f, -0.35f);    // x, y
    glVertex2f(0.05f, -0.35f);

    glVertex2f(-0.05f, -0.35f);    // x, y
    glVertex2f(-0.45f, -0.35f);

    glVertex2f(-0.55f, -0.35f);    // x, y
    glVertex2f(-0.95f, -0.35f);
    glEnd();


    glLineWidth(1);
  glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // white upper/Lower bridge

    glVertex2f(1.0f, -0.25f);    // x, y
    glVertex2f(-1.0f, -0.25f);

    glVertex2f(1.0f, -0.45f);    // x, y
    glVertex2f(-1.0f, -0.45f);
    glEnd();

    glBegin(GL_POLYGON);
glColor3f(0.8f, 0.8f, 0.8f); // bridge pillar right
glVertex2f(0.8f, -0.5f); // x, y
glVertex2f(0.9f, -0.45f); // x, y
glVertex2f(0.6f, -0.45f);
glVertex2f(0.7f, -0.5f); // x, y
glVertex2f(0.7f, -0.6f); // x, y
glVertex2f(0.8f, -0.6f); // x, y
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.8f, 0.8f, 0.8f); // bridge pillar middle
glVertex2f(0.1f, -0.5f); // x, y
glVertex2f(0.2f, -0.45f); // x, y
glVertex2f(-0.1f, -0.45f);
glVertex2f(0.0f, -0.5f); // x, y
glVertex2f(0.0f, -0.65f); // x, y
glVertex2f(0.1f, -0.65f); // x, y
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.8f, 0.8f, 0.8f); // bridge pillar left
glVertex2f(-0.6f, -0.5f); // x, y
glVertex2f(-0.5f, -0.45f); // x, y
glVertex2f(-0.8f, -0.45f);
glVertex2f(-0.7f, -0.5f); // x, y
glVertex2f(-0.7f, -0.7f); // x, y
glVertex2f(-0.6f, -0.7f); // x, y
glEnd();








glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); //  lower nouka quads
glVertex2f(0.75f, -0.75f); // x, y
glVertex2f(0.75f, -0.65f); // x, y
glVertex2f(0.65f, -0.65f); // x, y
glVertex2f(0.65f, -0.75f); // x, y
glEnd();

glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); // Nouka left
      glVertex2f(0.65f, -0.75f);    // x, y
	glVertex2f(0.57f, -0.7f);    // x, y
	glVertex2f(0.65f, -0.7f);    // x, y
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); // Nouka Right
      glVertex2f(0.75f, -0.75f);    // x, y
	glVertex2f(0.83f, -0.7f);    // x, y
	glVertex2f(0.75f, -0.7f);    // x, y
	glEnd();

glBegin(GL_POLYGON);
//glColor3f(0.04f,0.54f,0.07f); // hill left
glColor3f(0.02f,0.03f,0.17f);
glVertex2f(-1.0f, 0.6f);
glVertex2f(-0.90f, 0.63f);
glVertex2f(-0.88f, 0.70f);
glVertex2f(-0.81f, 0.75f);
glVertex2f(-0.74f, 0.80f);
glVertex2f(-0.6f, 0.70f);
glVertex2f(-0.53f, 0.63f);
glVertex2f(-0.5f, 0.60f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.02f,0.03f,0.17f);// hill 2nd
glVertex2f(-0.5f, 0.60f);
glVertex2f(-0.40f, 0.70f);
glVertex2f(-0.20f, 0.80f);
glVertex2f(0.0f, 0.70f);
glVertex2f(0.11f, 0.60f);
glEnd();


glBegin(GL_POLYGON);
glColor3f(0.43f,0.63f,0.51f);//  middle hill shadow
glVertex2f(0.03f, 0.60f);
glVertex2f(0.11f, 0.60f);

glVertex2f(-0.02f, 0.71f);

//glVertex2f(0.11f, 0.60f);
//glVertex2f(0.50f, 0.65f);
//glVertex2f(-0.02f, 0.72f);
glVertex2f(0.0f, 0.70f);
//glVertex2f(0.03f, 0.60f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.02f,0.03f,0.17f);//hill 3rd
glVertex2f(0.11f, 0.60f);
glVertex2f(0.19f, 0.69f);
glVertex2f(0.22f, 0.65f);
glVertex2f(0.40f, 0.80f);
glVertex2f(0.62f, 0.60f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.02f,0.03f,0.17f);// hill last
glVertex2f(0.62f, 0.60f);
glVertex2f(0.70f, 0.66f);
glVertex2f(0.73f, 0.63f);
glVertex2f(0.82f, 0.70f);
glVertex2f(0.84f, 0.67f);
glVertex2f(1.0f, 0.83f);
glVertex2f(1.0f, 0.60f);


glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  house 2nd
glVertex2f(-0.2f, 0.2f); // x, y
glVertex2f(-0.2f, 0.55f); // x, y
glVertex2f(-0.40f, 0.55f); // x, y
glVertex2f(-0.40f, 0.20f); // x, y
glEnd();



glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd shade
glVertex2f(-0.2f, 0.53f); // x, y
glVertex2f(-0.2f, 0.55f); // x, y
glVertex2f(-0.40f, 0.55f); // x, y
glVertex2f(-0.40f, 0.53f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.33f, 0.41f); // x, y
glVertex2f(-0.33f, 0.47f); // x, y
glVertex2f(-0.37f, 0.47f); // x, y
glVertex2f(-0.37f, 0.41f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.33f, 0.33f); // x, y
glVertex2f(-0.33f, 0.38f); // x, y
glVertex2f(-0.37f, 0.38f); // x, y
glVertex2f(-0.37f, 0.33f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.33f, 0.25f); // x, y
glVertex2f(-0.33f, 0.29f); // x, y
glVertex2f(-0.37f, 0.29f); // x, y
glVertex2f(-0.37f, 0.25f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.24f, 0.41f); // x, y
glVertex2f(-0.24f, 0.47f); // x, y
glVertex2f(-0.28f, 0.47f); // x, y
glVertex2f(-0.28f, 0.41f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.24f, 0.33f); // x, y
glVertex2f(-0.24f, 0.38f); // x, y
glVertex2f(-0.28f, 0.38f); // x, y
glVertex2f(-0.28f, 0.33f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.24f, 0.25f); // x, y
glVertex2f(-0.24f, 0.29f); // x, y
glVertex2f(-0.28f, 0.29f); // x, y
glVertex2f(-0.28f, 0.25f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  house 3rd
glVertex2f(0.04f, 0.2f); // x, y
glVertex2f(0.04f, 0.60f); // x, y
glVertex2f(-0.14f, 0.60f); // x, y
glVertex2f(-0.14f, 0.20f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd shade
glVertex2f(0.04f, 0.58f); // x, y
glVertex2f(0.04f, 0.60f); // x, y
glVertex2f(-0.14f, 0.60f); // x, y
glVertex2f(-0.14f, 0.58f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(-0.08f, 0.46f); // x, y
glVertex2f(-0.08f, 0.53f); // x, y
glVertex2f(-0.11f, 0.53f); // x, y
glVertex2f(-0.11f, 0.46f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(-0.08f, 0.38f); // x, y
glVertex2f(-0.08f, 0.44f); // x, y
glVertex2f(-0.11f, 0.44f); // x, y
glVertex2f(-0.11f, 0.38f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(-0.08f, 0.30f); // x, y
glVertex2f(-0.08f, 0.35f); // x, y
glVertex2f(-0.11f, 0.35f); // x, y
glVertex2f(-0.11f, 0.30f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(-0.08f, 0.22f); // x, y
glVertex2f(-0.08f, 0.26f); // x, y
glVertex2f(-0.11f, 0.26f); // x, y
glVertex2f(-0.11f, 0.22f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(0.0f, 0.46f); // x, y
glVertex2f(0.0f, 0.53f); // x, y
glVertex2f(-0.03f, 0.53f); // x, y
glVertex2f(-0.03f, 0.46f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(0.0f, 0.38f); // x, y
glVertex2f(0.0f, 0.44f); // x, y
glVertex2f(-0.03f, 0.44f); // x, y
glVertex2f(-0.03f, 0.38f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(0.0f, 0.30f); // x, y
glVertex2f(0.0f, 0.35f); // x, y
glVertex2f(-0.03f, 0.35f); // x, y
glVertex2f(-0.03f, 0.30f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(0.0f, 0.22f); // x, y
glVertex2f(0.0f, 0.26f); // x, y
glVertex2f(-0.03f, 0.26f); // x, y
glVertex2f(-0.03f, 0.22f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  house 4th
glVertex2f(0.22f, 0.2f); // x, y
glVertex2f(0.22f, 0.60f); // x, y
glVertex2f(0.08f, 0.60f); // x, y
glVertex2f(0.08f, 0.20f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.22f, 0.58f); // x, y
glVertex2f(0.22f, 0.60f); // x, y
glVertex2f(0.08f, 0.60f); // x, y
glVertex2f(0.08f, 0.58f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.14f, 0.46f); // x, y
glVertex2f(0.14f, 0.53f); // x, y
glVertex2f(0.11f, 0.53f); // x, y
glVertex2f(0.11f, 0.46f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.14f, 0.38f); // x, y
glVertex2f(0.14f, 0.44f); // x, y
glVertex2f(0.11f, 0.44f); // x, y
glVertex2f(0.11f, 0.38f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.14f, 0.30f); // x, y
glVertex2f(0.14f, 0.35f); // x, y
glVertex2f(0.11f, 0.35f); // x, y
glVertex2f(0.11f, 0.30f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.14f, 0.22f); // x, y
glVertex2f(0.14f, 0.26f); // x, y
glVertex2f(0.11f, 0.26f); // x, y
glVertex2f(0.11f, 0.22f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.20f, 0.46f); // x, y
glVertex2f(0.20f, 0.53f); // x, y
glVertex2f(0.17f, 0.53f); // x, y
glVertex2f(0.17f, 0.46f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.20f, 0.38f); // x, y
glVertex2f(0.20f, 0.44f); // x, y
glVertex2f(0.17f, 0.44f); // x, y
glVertex2f(0.17f, 0.38f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.20f, 0.30f); // x, y
glVertex2f(0.20f, 0.35f); // x, y
glVertex2f(0.17f, 0.35f); // x, y
glVertex2f(0.17f, 0.30f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.20f, 0.22f); // x, y
glVertex2f(0.20f, 0.26f); // x, y
glVertex2f(0.17f, 0.26f); // x, y
glVertex2f(0.17f, 0.22f); // x, y
glEnd();



glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
glBegin(GL_POLYGON);
    glColor3ub(255, 69, 0); // Car left
    glVertex2f(0.71f, -0.31f);
    glVertex2f(0.89f, -0.31f);
    glVertex2f(0.91f, -0.28f);
    glVertex2f(0.91f, -0.23f);
    glVertex2f(0.885f, -0.19f);
    glVertex2f(0.79f, -0.19f);
    glVertex2f(0.76f, -0.24f);
    glVertex2f(0.71f, -0.24f);
    glVertex2f(0.7f, -0.25f);
    glVertex2f(0.7f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
glColor3ub(248, 248, 255); // Window 1st
glVertex2f(0.769f, -0.24f); // x, y
glVertex2f(0.82f, -0.24f); // x, y
glVertex2f(0.82f, -0.2f); // x, y
glVertex2f(0.7909f, -0.2f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3ub(248, 248, 255); // Window 2nd
glVertex2f(0.84f, -0.24f); // x, y
glVertex2f(0.89f, -0.24f); // x, y
glVertex2f(0.869f, -0.2f); // x, y
glVertex2f(0.84f, -0.2f); // x, y
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f); //
    glVertex2f(0.805f, -0.25f);    // Car line
    glVertex2f(0.82f, -0.25f);
    glEnd();

    glLineWidth(2);
glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f); //
    glVertex2f(0.885f, -0.25f);    // Car line
    glVertex2f(0.87f, -0.25f);
    glEnd();

     glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Right  car Dhoya
    glVertex2f(0.91f, -0.297f);
    glVertex2f(0.93f, -0.297f);

    glVertex2f(0.917f, -0.312f);
    glVertex2f(0.937f, -0.312f);

    glVertex2f(0.91f, -0.326f);
    glVertex2f(0.93f, -0.326f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); //  Right car light
    glVertex2f(0.7f, -0.27f); // x, y
    glVertex2f(0.7f, -0.26f); // x, y
    glVertex2f(0.695f, -0.26f); // x, y
    glVertex2f(0.695f, -0.27f); // x, y
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); //  Right car light
    glVertex2f(0.7f, -0.29f); // x, y
    glVertex2f(0.7f, -0.28f); // x, y
    glVertex2f(0.695f, -0.28f); // x, y
    glVertex2f(0.695f, -0.29f); // x, y
    glEnd();

    filledCircle(0.75,-0.31,0.03, 0.0,0.0,0.0);  // Front wheel Car
    filledCircle(0.75,-0.31,0.015, 1.0,1.0,1.0);

    filledCircle(0.85,-0.31,0.03, 0.0,0.0,0.0);  // Back wheel Car
    filledCircle(0.85,-0.31,0.015, 1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
glTranslatef(position,0.0f,0.0f);

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); //  Truck
glVertex2f(-0.92f, -0.41f); // x, y
glVertex2f(-0.8f, -0.41f); // x, y
glVertex2f(-0.8f, -0.36f); // x, y
glVertex2f(-0.92f, -0.36f); // x, y
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0f, 0.0f, 0.0f); // Truck 1 left
glVertex2f(-0.8f, -0.41f);
glVertex2f(-0.7f, -0.41f);
glVertex2f(-0.7f, -0.35f);
glVertex2f(-0.74f, -0.29f);
glVertex2f(-0.8f, -0.29f);
glEnd();

filledCircle(-0.86,-0.41,0.03, 0.0,0.0,0.0); // Front wheel track
filledCircle(-0.86,-0.41,0.015, 1.0,1.0,1.0);

filledCircle(-0.75,-0.41,0.03, 0.0,0.0,0.0); // Back wheel Track
filledCircle(-0.75,-0.41,0.015, 1.0,1.0,1.0);

glBegin(GL_QUADS);
glColor3ub(248, 248, 255);  //  Truck middle white
glVertex2f(-0.78f, -0.35f); // x, y
glVertex2f(-0.725f, -0.35f); // x, y
glVertex2f(-0.75f, -0.31f); // x, y
glVertex2f(-0.78f, -0.31f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f); //  Truck Load space
glVertex2f(-0.8f, -0.36f); // x, y
glVertex2f(-0.8f, -0.26f); // x, y
glVertex2f(-0.92f, -0.26f); // x, y
glVertex2f(-0.92f, -0.36f); // x, y
glEnd();

glLineWidth(5);
glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f); //
    glVertex2f(-0.92f, -0.28f);    // Truck load line  upper
    glVertex2f(-0.97f, -0.28f);

    glVertex2f(-0.92f, -0.3f);    // Truck load line  middle
    glVertex2f(-0.95f, -0.3f);

    glVertex2f(-0.92f, -0.32f);    // Truck load line  lower
    glVertex2f(-0.935f, -0.32f);
    glEnd();

     glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // left Truck Dhoya
    glVertex2f(-0.93f, -0.393f);
    glVertex2f(-0.95f, -0.393f);

    glVertex2f(-0.94f, -0.407f);
    glVertex2f(-0.96f, -0.407f);

    glVertex2f(-0.93f, -0.419f);
    glVertex2f(-0.95f, -0.419f);
    glEnd();

     glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); // Truck Light
glVertex2f(-0.7f, -0.39f);
glVertex2f(-0.7f, -0.37f);
glVertex2f(-0.696f, -0.37f);
glVertex2f(-0.696f, -0.39f);
glEnd();
glPopMatrix();

//rains <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  glPopMatrix();
    glLoadIdentity();

    glPopMatrix();

    glPopMatrix();

    if(rain)
    {
        glPushMatrix();
        glTranslatef(_rain1x,_rain1y,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);

     glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();
        glPopMatrix();

        //rain 2 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain2x,_rain2y,0);

        glPushMatrix();
        glTranslatef(-.02,-.2,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 3 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain3x,_rain3y,0);

        glPushMatrix();
        glTranslatef(-.0,-.4,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();


        //rain 4 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain4x,_rain4y,0);

        glPushMatrix();
        glTranslatef(-.03,-.6,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 5 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain5x,_rain5y,0);

        glPushMatrix();
        glTranslatef(-.03,-.8,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();


        //rain 6 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain6x,_rain6y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 7 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain7x,_rain7y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.2,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();


        //rain 8 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain8x,_rain8y,0);

        glPushMatrix();
        glTranslatef(-.0,-1.4,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 9 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain9x,_rain9y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.6,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();

        //rain 10 <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        glPushMatrix();
        glTranslatef(_rain10x,_rain10y,0);

        glPushMatrix();
        glTranslatef(-.03,-1.8,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();

        glPushMatrix();
        glTranslatef(-.05,0,0);
        glBegin(GL_LINES);
        glColor3f(1,1,1);

        glVertex2f(-.95,.9);
        glVertex2f(-.955,.85);

        glVertex2f(-.85,.9);
        glVertex2f(-.855,.85);

        glVertex2f(-.75,.9);
        glVertex2f(-.755,.85);

        glVertex2f(-.65,.9);
        glVertex2f(-.655,.85);

        glVertex2f(-.55,.9);
        glVertex2f(-.555,.85);

        glVertex2f(-.45,.9);
        glVertex2f(-.455,.85);

        glVertex2f(-.35,.9);
        glVertex2f(-.355,.85);

        glVertex2f(-.25,.9);
        glVertex2f(-.255,.85);

        glVertex2f(-.15,.9);
        glVertex2f(-.155,.85);

        glVertex2f(-.05,.9);
        glVertex2f(-.055,.85);

        glVertex2f(.05,.9);
        glVertex2f(.045,.85);

        glVertex2f(.15,.9);
        glVertex2f(.145,.85);

        glVertex2f(.25,.9);
        glVertex2f(.245,.85);

        glVertex2f(.35,.9);
        glVertex2f(.345,.85);

        glVertex2f(.45,.9);
        glVertex2f(.445,.85);

        glVertex2f(.55,.9);
        glVertex2f(.545,.85);

        glVertex2f(.65,.9);
        glVertex2f(.645,.85);

        glVertex2f(.75,.9);
        glVertex2f(.745,.85);

        glVertex2f(.85,.9);
        glVertex2f(.845,.85);

        glVertex2f(.95,.9);
        glVertex2f(.945,.85);

        glVertex2f(1.05,.9);
        glVertex2f(1.045,.85);

        glVertex2f(1.15,.9);
        glVertex2f(1.145,.85);

        glVertex2f(1.25,.9);
        glVertex2f(1.245,.85);

        glVertex2f(1.35,.9);
        glVertex2f(1.345,.85);

        glEnd();
        glPopMatrix();

        glPopMatrix();

        glPopMatrix();
    }
    glBegin(GL_QUADS);
glColor3f(0.03f,0.11f,0.04f); //  Football Play Ground
glVertex2f(0.05f, -0.15f); // x, y
glVertex2f(0.35f, -0.15f); // x, y
glVertex2f(0.35f, 0.05f); // x, y
glVertex2f(0.05f, 0.05f); // x, y
glEnd();




    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); //  Football line
    glVertex2f(0.2f, -0.15f);    // x, y
    glVertex2f(0.2f, 0.05f);
    glEnd();



   filledCircle(0.2,-0.05,0.04, 1.0,1.0,1.0);



   glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f); //  goal post left
glVertex2f(0.05f, -0.09f); // x, y
glVertex2f(0.08f, -0.09f); // x, y
glVertex2f(0.08f, -0.01f); // x, y
glVertex2f(0.05f, -0.01f); // x, y
glEnd();



glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f); //  goal post right
glVertex2f(0.35f, -0.09f); // x, y
glVertex2f(0.32f, -0.09f); // x, y
glVertex2f(0.32f, -0.01f); // x, y
glVertex2f(0.35f, -0.01f); // x, y
glEnd();



glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); //
    glVertex2f(0.05f, -0.15f);    // x, y
    glVertex2f(0.35f, -0.15f);



   glVertex2f(0.05f, 0.05f);    // x, y
    glVertex2f(0.35f, 0.05f);



   glVertex2f(0.05f, 0.05f);    // x, y
    glVertex2f(0.05f, -0.15f);



   glVertex2f(0.35f, 0.05f);    // x, y
    glVertex2f(0.35f, -0.15f);




    glEnd();
            tree(-0.90,-0.80,0.2,0.09f,0.08f,0.27f,0.04f,0.04f,0.12f,0.32f,0.2f,0.05f);

    glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f); // house a
glVertex2f(-0.88f, -0.84f);    // x, y
glVertex2f(-0.86f, -0.8f);    // x, y
glVertex2f(-0.82f, -0.84f);    // x, y
glEnd();

   glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); // house a
glVertex2f(-0.86f, -0.8f);
glVertex2f(-0.75f, -0.8f);
glVertex2f(-0.73f, -0.84f);
glVertex2f(-0.84f, -0.84f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.5f); // house a
glVertex2f(-0.84f, -0.84f);
glVertex2f(-0.73f, -0.84f);
glVertex2f(-0.73f, -0.9f);
glVertex2f(-0.84f, -0.9f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 1.0f); // house a
glVertex2f(-0.88f, -0.84f);
glVertex2f(-0.84f, -0.84f);
glVertex2f(-0.84f, -0.9f);
glVertex2f(-0.88f, -0.9f);
glEnd();
glPopMatrix();
glBegin(GL_QUADS);
glColor3f(1.0f, 0.5f, 0.0f); // house a floor
glVertex2f(-0.88f, -0.9f);
glVertex2f(-0.84f, -0.9f);
glVertex2f(-0.84f, -0.92f);
glVertex2f(-0.90f, -0.92f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.10f); // house a floor
glVertex2f(-0.84f, -0.9f);
glVertex2f(-0.73f, -0.9f);
glVertex2f(-0.71f, -0.92f);
glVertex2f(-0.84f, -0.92f);
glEnd();
glPopMatrix();



glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); // house a door
glVertex2f(-0.8f, -0.86f);
glVertex2f(-0.78f, -0.86f);
glVertex2f(-0.78f, -0.9f);
glVertex2f(-0.8f, -0.9f);
glEnd();
glPopMatrix();

glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f); // house j
glVertex2f(-0.73f, -0.84f);    // x, y
glVertex2f(-0.71f, -0.8f);    // x, y
glVertex2f(-0.69f, -0.84f);    // x, y
glEnd();
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); // house j
glVertex2f(-0.71f, -0.8f);
glVertex2f(-0.64f, -0.8f);
glVertex2f(-0.62f, -0.84f);
glVertex2f(-0.69f, -0.84f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); // house j
glVertex2f(-0.69f, -0.84f);
glVertex2f(-0.62f, -0.84f);
glVertex2f(-0.62f, -0.9f);
glVertex2f(-0.69f, -0.9f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 0.0f); // house j
glVertex2f(-0.73f, -0.84f);
glVertex2f(-0.69f, -0.84f);
glVertex2f(-0.69f, -0.9f);
glVertex2f(-0.73f, -0.9f);
glEnd();
glPopMatrix();
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); // house j door
glVertex2f(-0.66f, -0.86f);
glVertex2f(-0.64f, -0.86f);
glVertex2f(-0.64f, -0.9f);
glVertex2f(-0.66f, -0.9f);
glEnd();
glPopMatrix();


glBegin(GL_QUADS);
glColor3f(1.0f, 0.5f, 0.0f); // house j floor
glVertex2f(-0.73f, -0.9f);
glVertex2f(-0.69f, -0.9f);
glVertex2f(-0.69f, -0.92f);
glVertex2f(-0.71f, -0.92f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.5f, 0.10f); // house j floor
glVertex2f(-0.69f, -0.9f);
glVertex2f(-0.62f, -0.9f);
glVertex2f(-0.60f, -0.92f);
glVertex2f(-0.69f, -0.92f);
glEnd();
glPopMatrix();

glBegin(GL_TRIANGLES);
glColor3f(1.0f, 1.0f, 1.0f); //  house g 1st part
glVertex2f(-0.99f, -0.8f);    // x, y
glVertex2f(-0.97f, -0.77f);    // x, y
glVertex2f(-0.95f, -0.8f);    // x, y
glEnd();

   glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f); // house g 2nd part
glVertex2f(-0.97f, -0.77f);
glVertex2f(-0.87f, -0.77f);
glVertex2f(-0.84f, -0.8f);
glVertex2f(-0.95f, -0.8f);
glEnd();
glPopMatrix();

   glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // house g 3rd
glVertex2f(-0.99f, -0.8f);
glVertex2f(-0.95f, -0.8f);
glVertex2f(-0.95f, -0.88f);
glVertex2f(-0.99f, -0.88f);
glEnd();
glPopMatrix();

glBegin(GL_POLYGON);
glColor3f(0.5f,0.5f,1.0f); // house g 4th
glVertex2f(-0.95f, -0.8f);
glVertex2f(-0.86f,- 0.8f);
glVertex2f(-0.88f, -0.84f);
glVertex2f(-0.88f, -0.88f);
glVertex2f(-0.95f, -0.88f);
glEnd();
 glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // house g window
glVertex2f(-0.92f, -0.82f);
glVertex2f(-0.88f, -0.82f);
glVertex2f(-0.88f, -0.85f);
glVertex2f(-0.92f, -0.85f);
glEnd();
glPopMatrix();

     glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); // house g floor
glVertex2f(-0.99f, -0.88f);
glVertex2f(-0.88f, -0.88f);
glVertex2f(-0.88f, -0.90f);
glVertex2f(-1.0f, -0.90f);
glEnd();
glPopMatrix();

glBegin(GL_POLYGON);
glColor3f(0.04f,0.04f,0.12f); // lower puj
glVertex2f(0.3f, -0.9f); // x, y
glVertex2f(0.3f, -0.75f); // x, y
glVertex2f(0.26f, -0.7f);
glVertex2f(0.2f, -0.65f); // x, y
glVertex2f(0.14f, -0.7f); // x, y
glVertex2f(0.1f, -0.75f); // x, y
glVertex2f(0.1f, -0.9f); // x, y
glEnd();

glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.04f,0.04f,0.12f); // Puj Line
	glVertex2f(0.2f, -0.66f);
    glVertex2f(0.2f, -0.6f);
    glEnd();

    glBegin(GL_QUADS);
glColor3f(0.0f,0.0f,0.0f); //  Bench_upper side
glVertex2f(-0.933f, -0.068f); // x, y
glVertex2f(-0.90f, 0.060f); // x, y
glVertex2f(-0.94f, 0.10f); // x, y
glVertex2f(-0.979f, -0.020f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  Bench_lower side
glVertex2f(-0.88f, -0.071f); // x, y
glVertex2f(-0.84f, 0.080f); // x, y
glVertex2f(-0.900f, 0.060f); // x, y
glVertex2f(-0.933f, -0.068f); // x, y
glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); //  Bench left leg 1
	glVertex2f(-0.882f, -0.124f);    // x, y
    glVertex2f(-0.882f, -0.067f);
    glEnd();


    glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);  //  Bench left leg 2
	glVertex2f(-0.931f, -0.121f);    // x, y
    glVertex2f(-0.931f, -0.067f);
    glEnd();
 glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); //  Bench left leg 3
	glVertex2f(-0.928f, -0.098f);    // x, y
    glVertex2f(-0.881f, -0.108f);
    glEnd();

        glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); //  Bench right leg 1
	glVertex2f(-0.824f, 0.021f);    // x, y
    glVertex2f(-0.842f, 0.057f);
    glEnd();

            glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); //  Bench right leg 2
	glVertex2f(-0.830f, 0.035f);    // x, y
    glVertex2f(-0.846f, 0.036f);
    glEnd();

     glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); //  Bench sit line 1
	glVertex2f(-0.891f, -0.048f);    // x, y
    glVertex2f(-0.861f, 0.062f);
    glEnd();
 glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f); //  Bench sit line 2
	glVertex2f(-0.884f, 0.060f);    // x, y
    glVertex2f(-0.912f, -0.036f);
    glEnd();
        glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 255.0f, 0.0f); //  flower-tree 1
	glVertex2f(-0.3f, 0.0f);    // x, y
    glVertex2f(-0.240f, 0.022f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.361f, 0.022f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.260f, 0.034f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.349f, 0.040f);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(-0.3f, 0.05f);
    glEnd();


    glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 255.0f, 0.0f); //  flower-tree 2
	glVertex2f(-0.500f, 0.018f);    // x, y
    glVertex2f(-0.500f, 0.060f);
    glVertex2f(-0.500f, 0.018f);
    glVertex2f(-0.469f, 0.051f);
    glVertex2f(-0.500f, 0.018f);
    glVertex2f(-0.450f, 0.039f);
    glVertex2f(-0.500f, 0.018f);
    glVertex2f(-0.529f, 0.050f);
    glVertex2f(-0.500f, 0.018f);
    glVertex2f(-0.551f, 0.040f);
    glEnd();


    glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 255.0f, 0.0f); //  flower-tree 3
	glVertex2f(-0.125f, -0.050f);    // x, y
    glVertex2f(-0.129f, -0.008f);
    glVertex2f(-0.125f, -0.050f);
    glVertex2f(-0.090f, -0.020f);
    glVertex2f(-0.125f, -0.050f);
    glVertex2f(-0.080f, -0.041f);
    glVertex2f(-0.125f, -0.050f);
    glVertex2f(-0.171f, -0.019f);
    glVertex2f(-0.125f, -0.050f);
    glVertex2f(-0.181f, -0.040f);
    glEnd();


    glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(0.0f, 255.0f, 0.0f); //  flower-tree 4
	glVertex2f(-0.669f, -0.031f);    // x, y
    glVertex2f(-0.670f, -0.001f);
    glVertex2f(-0.669f, -0.031f);
    glVertex2f(-0.641f, -0.008f);
    glVertex2f(-0.669f, -0.031f);
    glVertex2f(-0.627f, -0.022f);
    glVertex2f(-0.669f, -0.031f);
    glVertex2f(-0.698f, -0.009f);
    glVertex2f(-0.669f, -0.031f);
    glVertex2f(-0.712f, -0.022f);
    glEnd();

filledCircle(-0.129,-0.008,0.01, 1.0,0.0,0.0); //flower
filledCircle(-0.090,-0.020,0.01, 1.0,1.0,0.0);
filledCircle(-0.171,-0.019,0.01, 1.0,1.0,0.0);

filledCircle(-0.3,0.05,0.01, 1.0,1.0,0.0);
filledCircle(-0.349,0.040,0.01, 1.0,0.0,0.0);
filledCircle(-0.260,0.034,0.01, 1.0,0.0,0.0);


filledCircle(-0.501,0.060,0.01, 1.0,0.0,0.0);
filledCircle(-0.529,0.0505,0.01, 1.0,1.0,0.0);
filledCircle(-0.469,0.0510,0.01, 1.0,1.0,0.0);

filledCircle(-0.670,0.001,0.01, 1.0,1.0,0.0);
filledCircle(-0.641,-0.0086,0.01, 1.0,0.0,0.0);
filledCircle(-0.698,-0.009,0.01, 1.0,0.0,0.0);



tree(-0.50,-1.0,0.2,0.09f,0.08f,0.27f,0.04f,0.04f,0.12f,0.32f,0.2f,0.05f);
     tree(0.58,0.63,0.1,0.09f,0.08f,0.27f,0.04f,0.04f,0.12f,0.32f,0.2f,0.05f);
    tree(0.12,0.60,0.1,0.09f,0.08f,0.27f,0.04f,0.04f,0.12f,0.32f,0.2f,0.05f);
    tree(-0.50,0.60,0.1,0.09f,0.08f,0.27f,0.04f,0.04f,0.12f,0.32f,0.2f,0.05f);
    tree(-0.40,-1.0,0.2,0.09f,0.08f,0.27f,0.04f,0.04f,0.12f,0.32f,0.2f,0.05f);


glFlush();// Render now

}
void flood (void)
{





//glClearColor(0.54f,0.6f,0.33f, 1.0f); // Set background color to black and opaque
glClearColor(0.4f,0.5f,0.4f, 1.0f); // Set background color to black and opaque

glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
glLineWidth(1);



glBegin(GL_QUADS);
glColor3f(0.49f,0.93f,0.99f); // sky
glVertex2f(1.0f, 0.60f); // x, y
glVertex2f(1.0f, 1.0f); // x, y
glVertex2f(-1.0f, 1.0f);
glVertex2f(-1.0f, 0.60f); // x, y




glEnd();





glPushMatrix();
    glTranslatef(position,0.0f,0.0f);   // Cloud left Circle
    filledCircle(-0.85,0.9,0.04, 1.0,1.0,1.0);
    filledCircle(-0.85,0.9,0.04, 1.0,1.0,1.0);
    filledCircle(-0.8,0.9,0.05, 1.0,1.0,1.0);

    filledCircle(-0.7,0.81,0.04, 1.0,1.0,1.0); // Clod MIDDLE Circle
    filledCircle(-0.5,0.81,0.04, 1.0,1.0,1.0);
    filledCircle(-0.6,0.81,0.07, 1.0,1.0,1.0);

    filledCircle(-0.5,0.9,0.04, 1.0,1.0,1.0);  // Cloud RIGHT circle
    filledCircle(-0.3,0.9,0.04, 1.0,1.0,1.0);
    filledCircle(-0.4,0.9,0.07, 1.0,1.0,1.0);
    glPopMatrix();

    glPushMatrix();
glTranslatef(positionB,0.0f,0.0f);
glLineWidth(.1);
    glBegin(GL_LINES);

	glColor3ub(0, 0, 0); // birds
	glVertex2f(-0.45f, 0.85f);    // x, y
    glVertex2f(-0.40f, 0.80f);
    glVertex2f(-0.45f, 0.75f);    // x, y
    glVertex2f(-0.40f, 0.80f);

    glVertex2f(-0.45f, 1.0f);    // x, y
    glVertex2f(-0.40f, 0.95f);
    glVertex2f(-0.45f, 0.90f);    // x, y
    glVertex2f(-0.40f, 0.95f);

    glVertex2f(-0.35f, 0.95f);    // x, y
    glVertex2f(-0.30f, 0.90f);
    glVertex2f(-0.30f, 0.90f);    // x, y
    glVertex2f(-0.35f, 0.85f);


glEnd();
glPopMatrix();





    //glPushMatrix();
    //glTranslatef(0.0f,-position,0.0f);   // Sun
    filledCircle(0.8,0.9,0.07, 1.0,1.0,0.0);
   // glPopMatrix();
   glBegin(GL_QUADS);
glColor3f(0.0f,1.0f,0.0f); //  Football Play Ground
glVertex2f(0.05f, -0.15f); // x, y
glVertex2f(0.35f, -0.15f); // x, y
glVertex2f(0.35f, 0.05f); // x, y
glVertex2f(0.05f, 0.05f); // x, y
glEnd();




    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); //  Football line
    glVertex2f(0.2f, -0.15f);    // x, y
    glVertex2f(0.2f, 0.05f);
    glEnd();



   filledCircle(0.2,-0.05,0.04, 1.0,1.0,1.0);



   glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f); //  goal post left
glVertex2f(0.05f, -0.09f); // x, y
glVertex2f(0.08f, -0.09f); // x, y
glVertex2f(0.08f, -0.01f); // x, y
glVertex2f(0.05f, -0.01f); // x, y
glEnd();



glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f); //  goal post right
glVertex2f(0.35f, -0.09f); // x, y
glVertex2f(0.32f, -0.09f); // x, y
glVertex2f(0.32f, -0.01f); // x, y
glVertex2f(0.35f, -0.01f); // x, y
glEnd();







    glBegin(GL_QUADS);
    glColor3ub(0, 138, 216); // river Upper Quads
    glVertex2f(1.0f, 0.40f);
    glVertex2f(1.0f, 0.62f);
    glVertex2f(-1.0f, 0.62f);
    glVertex2f(-1.0f, 0.40f);
    glEnd();


glBegin(GL_POLYGON);
glColor3ub(0, 138, 216); // river Lower
glVertex2f(1.0f, -1.0f);
glVertex2f(1.0f, 0.4f);
glVertex2f(0.4f, 0.4f);
glVertex2f(0.5f, 0.3f);
glVertex2f(0.4f, 0.2f);
glVertex2f(0.6f, 0.1f);
glVertex2f(0.3f, -0.3f);
glVertex2f(0.5f, -0.5f);
glVertex2f(0.5f, -0.7f);
glVertex2f(0.4f, -0.8f);
glVertex2f(0.52f, -0.88f);
glVertex2f(0.38f, -0.88f);
glVertex2f(0.6f, -1.0f);
glEnd();


glBegin(GL_LINES);
glLineWidth(5);
	glColor3f(1.0f, 1.0f, 1.0f); //  river side line
	    glVertex2f(0.40f, 0.30f);

	glVertex2f(0.40f, 0.20f);    // x, y
    glEnd();
    glPushMatrix();//flood line up
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.95f, 0.55f);
glVertex2f(1.0f, 0.55f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.80f, 0.55f);
glVertex2f(0.85f, 0.55f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.70f, 0.55f);
glVertex2f(0.75f, 0.55f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.60f, 0.55f);
glVertex2f(0.65f, 0.55f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.50f, 0.55f);
glVertex2f(0.55f, 0.55f);
glEnd();
glPopMatrix();

glPushMatrix();

glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.40f, 0.55f);
glVertex2f(0.45f, 0.55f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.30f, 0.55f);
glVertex2f(0.35f, 0.55f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.20f, 0.55f);
glVertex2f(0.25f, 0.55f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.10f, 0.55f);
glVertex2f(0.15f, 0.55f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.00f, 0.55f);
glVertex2f(0.05f, 0.55f);
glEnd();
glPopMatrix();// end up 1 flood line

glPushMatrix();//flood line up
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.95f, 0.45f);
glVertex2f(1.0f, 0.45f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.80f, 0.45f);
glVertex2f(0.85f, 0.45f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.70f, 0.45f);
glVertex2f(0.75f, 0.45f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.60f, 0.45f);
glVertex2f(0.65f, 0.45f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.50f, 0.45f);
glVertex2f(0.55f, 0.45f);
glEnd();
glPopMatrix();

glPushMatrix();

glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.40f, 0.50f);
glVertex2f(0.45f, 0.50f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.30f, 0.50f);
glVertex2f(0.35f, 0.50f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.20f, 0.50f);
glVertex2f(0.25f, 0.50f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.10f, 0.50f);
glVertex2f(0.15f, 0.50f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.00f, 0.50f);
glVertex2f(0.05f, 0.50f);
glEnd();
glPopMatrix();//end

        tree(-0.90,0.30,0.25,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);






glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); //  House
glVertex2f(-0.5f, 0.57f); // x, y
glVertex2f(-0.47f, 0.6f); // x, y
glVertex2f(-0.7f, 0.6f); // x, y
glVertex2f(-0.73f, 0.57f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  House 2
glVertex2f(-0.5f, 0.55f); // x, y
glVertex2f(-0.5f, 0.57f); // x, y
glVertex2f(-0.73f, 0.57f); // x, y
glVertex2f(-0.73f, 0.55f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); //  House 3
glVertex2f(-0.5f, 0.45f); // x, y
glVertex2f(-0.5f, 0.55f); // x, y
glVertex2f(-0.73f, 0.55f); // x, y
glVertex2f(-0.73f, 0.45f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  House 4
glVertex2f(-0.5f, 0.43f); // x, y
glVertex2f(-0.5f, 0.45f); // x, y
glVertex2f(-0.73f, 0.45f); // x, y
glVertex2f(-0.73f, 0.43f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); //  House 5
glVertex2f(-0.5f, 0.33f); // x, y
glVertex2f(-0.5f, 0.43f); // x, y
glVertex2f(-0.73f, 0.43f); // x, y
glVertex2f(-0.73f, 0.33f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  House 6
glVertex2f(-0.5f, 0.31f); // x, y
glVertex2f(-0.5f, 0.33f); // x, y
glVertex2f(-0.73f, 0.33f); // x, y
glVertex2f(-0.73f, 0.31f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); //  House 7
glVertex2f(-0.5f, 0.18f); // x, y
glVertex2f(-0.5f, 0.31f); // x, y
glVertex2f(-0.73f, 0.31f); // x, y
glVertex2f(-0.73f, 0.18f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f, 0.08f, 0.22f); //  House 8
glVertex2f(-0.5f, 0.18f); // x, y
glVertex2f(-0.47f, 0.21f); // x, y
glVertex2f(-0.47f, 0.6f); // x, y
glVertex2f(-0.5f, 0.57f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window upper left
glVertex2f(-0.65f, 0.47f); // x, y
glVertex2f(-0.65f, 0.53f); // x, y
glVertex2f(-0.7f, 0.53f); // x, y
glVertex2f(-0.7f, 0.47f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window upper right
glVertex2f(-0.52f, 0.47f); // x, y
glVertex2f(-0.52f, 0.53f); // x, y
glVertex2f(-0.57f, 0.53f); // x, y
glVertex2f(-0.57f, 0.47f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window middle Right
glVertex2f(-0.52f, 0.35f); // x, y
glVertex2f(-0.52f, 0.41f); // x, y
glVertex2f(-0.57f, 0.41f); // x, y
glVertex2f(-0.57f, 0.35f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window middle Left
glVertex2f(-0.65f, 0.35f); // x, y
glVertex2f(-0.65f, 0.41f); // x, y
glVertex2f(-0.7f, 0.41f); // x, y
glVertex2f(-0.7f, 0.35f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //   Window lower Right
glVertex2f(-0.52f, 0.22f); // x, y
glVertex2f(-0.52f, 0.28f); // x, y
glVertex2f(-0.57f, 0.28f); // x, y
glVertex2f(-0.57f, 0.22f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Window Lower Left
glVertex2f(-0.65f, 0.22f); // x, y
glVertex2f(-0.65f, 0.28f); // x, y
glVertex2f(-0.7f, 0.28f); // x, y
glVertex2f(-0.7f, 0.22f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  Door
glVertex2f(-0.59f, 0.18f); // x, y
glVertex2f(-0.59f, 0.25f); // x, y
glVertex2f(-0.63f, 0.25f); // x, y
glVertex2f(-0.63f, 0.18f); // x, y
glEnd();
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  house 2nd
glVertex2f(-0.2f, 0.2f); // x, y
glVertex2f(-0.2f, 0.55f); // x, y
glVertex2f(-0.40f, 0.55f); // x, y
glVertex2f(-0.40f, 0.20f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd shade
glVertex2f(-0.2f, 0.53f); // x, y
glVertex2f(-0.2f, 0.55f); // x, y
glVertex2f(-0.40f, 0.55f); // x, y
glVertex2f(-0.40f, 0.53f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.33f, 0.41f); // x, y
glVertex2f(-0.33f, 0.47f); // x, y
glVertex2f(-0.37f, 0.47f); // x, y
glVertex2f(-0.37f, 0.41f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.33f, 0.33f); // x, y
glVertex2f(-0.33f, 0.38f); // x, y
glVertex2f(-0.37f, 0.38f); // x, y
glVertex2f(-0.37f, 0.33f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.33f, 0.25f); // x, y
glVertex2f(-0.33f, 0.29f); // x, y
glVertex2f(-0.37f, 0.29f); // x, y
glVertex2f(-0.37f, 0.25f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.24f, 0.41f); // x, y
glVertex2f(-0.24f, 0.47f); // x, y
glVertex2f(-0.28f, 0.47f); // x, y
glVertex2f(-0.28f, 0.41f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.24f, 0.33f); // x, y
glVertex2f(-0.24f, 0.38f); // x, y
glVertex2f(-0.28f, 0.38f); // x, y
glVertex2f(-0.28f, 0.33f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.72f,0.08f,0.22f); //  house 2nd window
glVertex2f(-0.24f, 0.25f); // x, y
glVertex2f(-0.24f, 0.29f); // x, y
glVertex2f(-0.28f, 0.29f); // x, y
glVertex2f(-0.28f, 0.25f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  house 3rd
glVertex2f(0.04f, 0.2f); // x, y
glVertex2f(0.04f, 0.60f); // x, y
glVertex2f(-0.14f, 0.60f); // x, y
glVertex2f(-0.14f, 0.20f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd shade
glVertex2f(0.04f, 0.58f); // x, y
glVertex2f(0.04f, 0.60f); // x, y
glVertex2f(-0.14f, 0.60f); // x, y
glVertex2f(-0.14f, 0.58f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(-0.08f, 0.46f); // x, y
glVertex2f(-0.08f, 0.53f); // x, y
glVertex2f(-0.11f, 0.53f); // x, y
glVertex2f(-0.11f, 0.46f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(-0.08f, 0.38f); // x, y
glVertex2f(-0.08f, 0.44f); // x, y
glVertex2f(-0.11f, 0.44f); // x, y
glVertex2f(-0.11f, 0.38f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(-0.08f, 0.30f); // x, y
glVertex2f(-0.08f, 0.35f); // x, y
glVertex2f(-0.11f, 0.35f); // x, y
glVertex2f(-0.11f, 0.30f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(-0.08f, 0.22f); // x, y
glVertex2f(-0.08f, 0.26f); // x, y
glVertex2f(-0.11f, 0.26f); // x, y
glVertex2f(-0.11f, 0.22f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(0.0f, 0.46f); // x, y
glVertex2f(0.0f, 0.53f); // x, y
glVertex2f(-0.03f, 0.53f); // x, y
glVertex2f(-0.03f, 0.46f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(0.0f, 0.38f); // x, y
glVertex2f(0.0f, 0.44f); // x, y
glVertex2f(-0.03f, 0.44f); // x, y
glVertex2f(-0.03f, 0.38f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(0.0f, 0.30f); // x, y
glVertex2f(0.0f, 0.35f); // x, y
glVertex2f(-0.03f, 0.35f); // x, y
glVertex2f(-0.03f, 0.30f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); //  house 3rd window
glVertex2f(0.0f, 0.22f); // x, y
glVertex2f(0.0f, 0.26f); // x, y
glVertex2f(-0.03f, 0.26f); // x, y
glVertex2f(-0.03f, 0.22f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); //  house 4th
glVertex2f(0.22f, 0.2f); // x, y
glVertex2f(0.22f, 0.60f); // x, y
glVertex2f(0.08f, 0.60f); // x, y
glVertex2f(0.08f, 0.20f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.22f, 0.58f); // x, y
glVertex2f(0.22f, 0.60f); // x, y
glVertex2f(0.08f, 0.60f); // x, y
glVertex2f(0.08f, 0.58f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.14f, 0.46f); // x, y
glVertex2f(0.14f, 0.53f); // x, y
glVertex2f(0.11f, 0.53f); // x, y
glVertex2f(0.11f, 0.46f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.14f, 0.38f); // x, y
glVertex2f(0.14f, 0.44f); // x, y
glVertex2f(0.11f, 0.44f); // x, y
glVertex2f(0.11f, 0.38f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.14f, 0.30f); // x, y
glVertex2f(0.14f, 0.35f); // x, y
glVertex2f(0.11f, 0.35f); // x, y
glVertex2f(0.11f, 0.30f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.14f, 0.22f); // x, y
glVertex2f(0.14f, 0.26f); // x, y
glVertex2f(0.11f, 0.26f); // x, y
glVertex2f(0.11f, 0.22f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.20f, 0.46f); // x, y
glVertex2f(0.20f, 0.53f); // x, y
glVertex2f(0.17f, 0.53f); // x, y
glVertex2f(0.17f, 0.46f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.20f, 0.38f); // x, y
glVertex2f(0.20f, 0.44f); // x, y
glVertex2f(0.17f, 0.44f); // x, y
glVertex2f(0.17f, 0.38f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.20f, 0.30f); // x, y
glVertex2f(0.20f, 0.35f); // x, y
glVertex2f(0.17f, 0.35f); // x, y
glVertex2f(0.17f, 0.30f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(0.29f,0.26f,0.47f); //  house 4th shade
glVertex2f(0.20f, 0.22f); // x, y
glVertex2f(0.20f, 0.26f); // x, y
glVertex2f(0.17f, 0.26f); // x, y
glVertex2f(0.17f, 0.22f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3f(0.35f, 0.36f, 0.38f); // Bridge
glVertex2f(1.0f, -0.45f); // x, y
glVertex2f(1.0f, -0.25f); // x, y
glVertex2f(-1.0f, -0.25f); // x, y
glVertex2f(-1.0f, -0.45f); // x, y
glEnd();


glBegin(GL_QUADS);
glColor3ub(0, 138, 216); // flood under bridge
glVertex2f(1.0f, -0.49f); // x, y
glVertex2f(1.0f, -0.8f); // x, y
glVertex2f(-1.0f, -0.8f); // x, y
glVertex2f(-1.0f, -0.49f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3ub(0, 138, 216); // flood over bridge
glVertex2f(1.0f, -0.17f); // x, y
glVertex2f(1.0f, 0.23f); // x, y
glVertex2f(-1.0f, 0.23f); // x, y
glVertex2f(-1.0f, -0.17f); // x, y
glEnd();

glLineWidth(0.1);
glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); //  middle bridge White
    glVertex2f(0.95f, -0.35f);    // x, y
    glVertex2f(0.55f, -0.35f);

    glVertex2f(0.45f, -0.35f);    // x, y
    glVertex2f(0.05f, -0.35f);

    glVertex2f(-0.05f, -0.35f);    // x, y
    glVertex2f(-0.45f, -0.35f);

    glVertex2f(-0.55f, -0.35f);    // x, y
    glVertex2f(-0.95f, -0.35f);
    glEnd();


    glLineWidth(1);
  glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // white upper/Lower bridge

    glVertex2f(1.0f, -0.25f);    // x, y
    glVertex2f(-1.0f, -0.25f);

    glVertex2f(1.0f, -0.45f);    // x, y
    glVertex2f(-1.0f, -0.45f);
    glEnd();

    glBegin(GL_POLYGON);
glColor3f(0.8f, 0.8f, 0.8f); // bridge pillar right
glVertex2f(0.8f, -0.5f); // x, y
glVertex2f(0.9f, -0.45f); // x, y
glVertex2f(0.6f, -0.45f);
glVertex2f(0.7f, -0.5f); // x, y
glVertex2f(0.7f, -0.6f); // x, y
glVertex2f(0.8f, -0.6f); // x, y
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.8f, 0.8f, 0.8f); // bridge pillar middle
glVertex2f(0.1f, -0.5f); // x, y
glVertex2f(0.2f, -0.45f); // x, y
glVertex2f(-0.1f, -0.45f);
glVertex2f(0.0f, -0.5f); // x, y
glVertex2f(0.0f, -0.65f); // x, y
glVertex2f(0.1f, -0.65f); // x, y
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.8f, 0.8f, 0.8f); // bridge pillar left
glVertex2f(-0.6f, -0.5f); // x, y
glVertex2f(-0.5f, -0.45f); // x, y
glVertex2f(-0.8f, -0.45f);
glVertex2f(-0.7f, -0.5f); // x, y
glVertex2f(-0.7f, -0.7f); // x, y
glVertex2f(-0.6f, -0.7f); // x, y
glEnd();








/*glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); //  lower nouka quads
glVertex2f(0.75f, -0.75f); // x, y
glVertex2f(0.75f, -0.65f); // x, y
glVertex2f(0.65f, -0.65f); // x, y
glVertex2f(0.65f, -0.75f); // x, y
glEnd();

glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); // Nouka left
      glVertex2f(0.65f, -0.75f);    // x, y
	glVertex2f(0.57f, -0.7f);    // x, y
	glVertex2f(0.65f, -0.7f);    // x, y
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); // Nouka Right
      glVertex2f(0.75f, -0.75f);    // x, y
	glVertex2f(0.83f, -0.7f);    // x, y
	glVertex2f(0.75f, -0.7f);    // x, y
	glEnd();*/

glBegin(GL_POLYGON);
//glColor3f(0.04f,0.54f,0.07f); // hill left
glColor3f(0.04f,0.43f,0.07f);
glVertex2f(-1.0f, 0.6f);
glVertex2f(-0.90f, 0.63f);
glVertex2f(-0.88f, 0.70f);
glVertex2f(-0.81f, 0.75f);
glVertex2f(-0.74f, 0.80f);
glVertex2f(-0.6f, 0.70f);
glVertex2f(-0.53f, 0.63f);
glVertex2f(-0.5f, 0.60f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.04f,0.43f,0.07f);//  middle hill
glVertex2f(-0.5f, 0.60f);
glVertex2f(-0.40f, 0.70f);
glVertex2f(-0.20f, 0.80f);
glVertex2f(0.0f, 0.70f);
glVertex2f(0.11f, 0.60f);
glEnd();


glBegin(GL_POLYGON);
glColor3f(0.43f,0.63f,0.51f);//  middle hill shadow
glVertex2f(0.03f, 0.60f);
glVertex2f(0.11f, 0.60f);

glVertex2f(-0.02f, 0.71f);

//glVertex2f(0.11f, 0.60f);
//glVertex2f(0.50f, 0.65f);
//glVertex2f(-0.02f, 0.72f);
glVertex2f(0.0f, 0.70f);
//glVertex2f(0.03f, 0.60f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.04f,0.43f,0.07f); // hill right
glVertex2f(0.11f, 0.60f);
glVertex2f(0.19f, 0.69f);
glVertex2f(0.22f, 0.65f);
glVertex2f(0.40f, 0.80f);
glVertex2f(0.62f, 0.60f);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.04f,0.43f,0.07f); // hill last
glVertex2f(0.62f, 0.60f);
glVertex2f(0.70f, 0.66f);
glVertex2f(0.73f, 0.63f);
glVertex2f(0.82f, 0.70f);
glVertex2f(0.84f, 0.67f);
glVertex2f(1.0f, 0.83f);
glVertex2f(1.0f, 0.60f);
glEnd();





glBegin(GL_POLYGON);
    glColor3ub(255, 69, 0); // Car left
    glVertex2f(0.71f, -0.31f);
    glVertex2f(0.89f, -0.31f);
    glVertex2f(0.91f, -0.28f);
    glVertex2f(0.91f, -0.23f);
    glVertex2f(0.885f, -0.19f);
    glVertex2f(0.79f, -0.19f);
    glVertex2f(0.76f, -0.24f);
    glVertex2f(0.71f, -0.24f);
    glVertex2f(0.7f, -0.25f);
    glVertex2f(0.7f, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
glColor3ub(248, 248, 255); // Window 1st
glVertex2f(0.769f, -0.24f); // x, y
glVertex2f(0.82f, -0.24f); // x, y
glVertex2f(0.82f, -0.2f); // x, y
glVertex2f(0.7909f, -0.2f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3ub(248, 248, 255); // Window 2nd
glVertex2f(0.84f, -0.24f); // x, y
glVertex2f(0.89f, -0.24f); // x, y
glVertex2f(0.869f, -0.2f); // x, y
glVertex2f(0.84f, -0.2f); // x, y
glEnd();

glLineWidth(2);
glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f); //
    glVertex2f(0.805f, -0.25f);    // Car line
    glVertex2f(0.82f, -0.25f);
    glEnd();

    glLineWidth(2);
glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f); //
    glVertex2f(0.885f, -0.25f);    // Car line
    glVertex2f(0.87f, -0.25f);
    glEnd();

     glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Right  car Dhoya
    glVertex2f(0.91f, -0.297f);
    glVertex2f(0.93f, -0.297f);

    glVertex2f(0.917f, -0.312f);
    glVertex2f(0.937f, -0.312f);

    glVertex2f(0.91f, -0.326f);
    glVertex2f(0.93f, -0.326f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); //  Right car light
    glVertex2f(0.7f, -0.27f); // x, y
    glVertex2f(0.7f, -0.26f); // x, y
    glVertex2f(0.695f, -0.26f); // x, y
    glVertex2f(0.695f, -0.27f); // x, y
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f); //  Right car light
    glVertex2f(0.7f, -0.29f); // x, y
    glVertex2f(0.7f, -0.28f); // x, y
    glVertex2f(0.695f, -0.28f); // x, y
    glVertex2f(0.695f, -0.29f); // x, y
    glEnd();

    filledCircle(0.75,-0.31,0.03, 0.0,0.0,0.0);  // Front wheel Car
    filledCircle(0.75,-0.31,0.015, 1.0,1.0,1.0);

    filledCircle(0.85,-0.31,0.03, 0.0,0.0,0.0);  // Back wheel Car
    filledCircle(0.85,-0.31,0.015, 1.0,1.0,1.0);
    glPopMatrix();



glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); //  Truck
glVertex2f(-0.92f, -0.41f); // x, y
glVertex2f(-0.8f, -0.41f); // x, y
glVertex2f(-0.8f, -0.36f); // x, y
glVertex2f(-0.92f, -0.36f); // x, y
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0f, 0.0f, 0.0f); // Truck 1 left
glVertex2f(-0.8f, -0.41f);
glVertex2f(-0.7f, -0.41f);
glVertex2f(-0.7f, -0.35f);
glVertex2f(-0.74f, -0.29f);
glVertex2f(-0.8f, -0.29f);
glEnd();

filledCircle(-0.86,-0.41,0.03, 0.0,0.0,0.0); // Front wheel track
filledCircle(-0.86,-0.41,0.015, 1.0,1.0,1.0);

filledCircle(-0.75,-0.41,0.03, 0.0,0.0,0.0); // Back wheel Track
filledCircle(-0.75,-0.41,0.015, 1.0,1.0,1.0);

glBegin(GL_QUADS);
glColor3ub(248, 248, 255);  //  Truck middle white
glVertex2f(-0.78f, -0.35f); // x, y
glVertex2f(-0.725f, -0.35f); // x, y
glVertex2f(-0.75f, -0.31f); // x, y
glVertex2f(-0.78f, -0.31f); // x, y
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f); //  Truck Load space
glVertex2f(-0.8f, -0.36f); // x, y
glVertex2f(-0.8f, -0.26f); // x, y
glVertex2f(-0.92f, -0.26f); // x, y
glVertex2f(-0.92f, -0.36f); // x, y
glEnd();

glLineWidth(5);
glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f); //
    glVertex2f(-0.92f, -0.28f);    // Truck load line  upper
    glVertex2f(-0.97f, -0.28f);

    glVertex2f(-0.92f, -0.3f);    // Truck load line  middle
    glVertex2f(-0.95f, -0.3f);

    glVertex2f(-0.92f, -0.32f);    // Truck load line  lower
    glVertex2f(-0.935f, -0.32f);
    glEnd();

     glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // left Truck Dhoya
    glVertex2f(-0.93f, -0.393f);
    glVertex2f(-0.95f, -0.393f);

    glVertex2f(-0.94f, -0.407f);
    glVertex2f(-0.96f, -0.407f);

    glVertex2f(-0.93f, -0.419f);
    glVertex2f(-0.95f, -0.419f);
    glEnd();

     glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); // Truck Light
glVertex2f(-0.7f, -0.39f);
glVertex2f(-0.7f, -0.37f);
glVertex2f(-0.696f, -0.37f);
glVertex2f(-0.696f, -0.39f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f,1.0f,0.0f); //  Football Play Ground
glVertex2f(0.05f, -0.15f); // x, y
glVertex2f(0.35f, -0.15f); // x, y
glVertex2f(0.35f, 0.05f); // x, y
glVertex2f(0.05f, 0.05f); // x, y
glEnd();




    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); //  Football line
    glVertex2f(0.2f, -0.15f);    // x, y
    glVertex2f(0.2f, 0.05f);
    glEnd();



   filledCircle(0.2,-0.05,0.04, 1.0,1.0,1.0);



   glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f); //  goal post left
glVertex2f(0.05f, -0.09f); // x, y
glVertex2f(0.08f, -0.09f); // x, y
glVertex2f(0.08f, -0.01f); // x, y
glVertex2f(0.05f, -0.01f); // x, y
glEnd();



glBegin(GL_QUADS);
glColor3f(1.0f,1.0f,1.0f); //  goal post right
glVertex2f(0.35f, -0.09f); // x, y
glVertex2f(0.32f, -0.09f); // x, y
glVertex2f(0.32f, -0.01f); // x, y
glVertex2f(0.35f, -0.01f); // x, y
glEnd();



glLineWidth(2);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); //
    glVertex2f(0.05f, -0.15f);    // x, y
    glVertex2f(0.35f, -0.15f);



   glVertex2f(0.05f, 0.05f);    // x, y
    glVertex2f(0.35f, 0.05f);



   glVertex2f(0.05f, 0.05f);    // x, y
    glVertex2f(0.05f, -0.15f);



   glVertex2f(0.35f, 0.05f);    // x, y
    glVertex2f(0.35f, -0.15f);




    glEnd();

    glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f); // house a
glVertex2f(-0.88f, -0.84f);    // x, y
glVertex2f(-0.86f, -0.8f);    // x, y
glVertex2f(-0.82f, -0.84f);    // x, y
glEnd();

   glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); // house a
glVertex2f(-0.86f, -0.8f);
glVertex2f(-0.75f, -0.8f);
glVertex2f(-0.73f, -0.84f);
glVertex2f(-0.84f, -0.84f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.5f); // house a
glVertex2f(-0.84f, -0.84f);
glVertex2f(-0.73f, -0.84f);
glVertex2f(-0.73f, -0.9f);
glVertex2f(-0.84f, -0.9f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 1.0f); // house a
glVertex2f(-0.88f, -0.84f);
glVertex2f(-0.84f, -0.84f);
glVertex2f(-0.84f, -0.9f);
glVertex2f(-0.88f, -0.9f);
glEnd();
glPopMatrix();
glBegin(GL_QUADS);
glColor3f(1.0f, 0.5f, 0.0f); // house a floor
glVertex2f(-0.88f, -0.9f);
glVertex2f(-0.84f, -0.9f);
glVertex2f(-0.84f, -0.92f);
glVertex2f(-0.90f, -0.92f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.5f, 0.5f, 0.10f); // house a floor
glVertex2f(-0.84f, -0.9f);
glVertex2f(-0.73f, -0.9f);
glVertex2f(-0.71f, -0.92f);
glVertex2f(-0.84f, -0.92f);
glEnd();
glPopMatrix();



glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); // house a door
glVertex2f(-0.8f, -0.86f);
glVertex2f(-0.78f, -0.86f);
glVertex2f(-0.78f, -0.9f);
glVertex2f(-0.8f, -0.9f);
glEnd();
glPopMatrix();

glBegin(GL_TRIANGLES);
glColor3f(1.0f, 0.0f, 0.0f); // house j
glVertex2f(-0.73f, -0.84f);    // x, y
glVertex2f(-0.71f, -0.8f);    // x, y
glVertex2f(-0.69f, -0.84f);    // x, y
glEnd();
glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 0.0f); // house j
glVertex2f(-0.71f, -0.8f);
glVertex2f(-0.64f, -0.8f);
glVertex2f(-0.62f, -0.84f);
glVertex2f(-0.69f, -0.84f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.0f, 1.0f); // house j
glVertex2f(-0.69f, -0.84f);
glVertex2f(-0.62f, -0.84f);
glVertex2f(-0.62f, -0.9f);
glVertex2f(-0.69f, -0.9f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(0.0f, 1.0f, 0.0f); // house j
glVertex2f(-0.73f, -0.84f);
glVertex2f(-0.69f, -0.84f);
glVertex2f(-0.69f, -0.9f);
glVertex2f(-0.73f, -0.9f);
glEnd();
glPopMatrix();
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f); // house j door
glVertex2f(-0.66f, -0.86f);
glVertex2f(-0.64f, -0.86f);
glVertex2f(-0.64f, -0.9f);
glVertex2f(-0.66f, -0.9f);
glEnd();
glPopMatrix();


glBegin(GL_QUADS);
glColor3f(1.0f, 0.5f, 0.0f); // house j floor
glVertex2f(-0.73f, -0.9f);
glVertex2f(-0.69f, -0.9f);
glVertex2f(-0.69f, -0.92f);
glVertex2f(-0.71f, -0.92f);
glEnd();
glPopMatrix();

glBegin(GL_QUADS);
glColor3f(1.0f, 0.5f, 0.10f); // house j floor
glVertex2f(-0.69f, -0.9f);
glVertex2f(-0.62f, -0.9f);
glVertex2f(-0.60f, -0.92f);
glVertex2f(-0.69f, -0.92f);
glEnd();
glPopMatrix();

glBegin(GL_TRIANGLES);
glColor3f(1.0f, 1.0f, 1.0f); //  house g 1st part
glVertex2f(-0.99f, -0.8f);    // x, y
glVertex2f(-0.97f, -0.77f);    // x, y
glVertex2f(-0.95f, -0.8f);    // x, y
glEnd();

   glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 0.0f); // house g 2nd part
glVertex2f(-0.97f, -0.77f);
glVertex2f(-0.87f, -0.77f);
glVertex2f(-0.84f, -0.8f);
glVertex2f(-0.95f, -0.8f);
glEnd();
glPopMatrix();

   glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // house g 3rd
glVertex2f(-0.99f, -0.8f);
glVertex2f(-0.95f, -0.8f);
glVertex2f(-0.95f, -0.88f);
glVertex2f(-0.99f, -0.88f);
glEnd();
glPopMatrix();

glBegin(GL_POLYGON);
glColor3f(0.5f,0.5f,1.0f); // house g 4th
glVertex2f(-0.95f, -0.8f);
glVertex2f(-0.86f,- 0.8f);
glVertex2f(-0.88f, -0.84f);
glVertex2f(-0.88f, -0.88f);
glVertex2f(-0.95f, -0.88f);
glEnd();
 glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 0.0f); // house g window
glVertex2f(-0.92f, -0.82f);
glVertex2f(-0.88f, -0.82f);
glVertex2f(-0.88f, -0.85f);
glVertex2f(-0.92f, -0.85f);
glEnd();
glPopMatrix();

     glBegin(GL_QUADS);
glColor3f(1.0f, 0.0f, 1.0f); // house g floor
glVertex2f(-0.99f, -0.88f);
glVertex2f(-0.88f, -0.88f);
glVertex2f(-0.88f, -0.90f);
glVertex2f(-1.0f, -0.90f);
glEnd();
glPopMatrix();
    glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(0.04f,0.37f,0.06f); // beizer curve
bezier_curve4(0.73f,0.1f,0.75f,0.13f,1.0f,0.1f,0.98f, 0.07f);
glVertex2f(0.73f, 0.1f);
glVertex2f(1.0f, 0.1f);

glVertex2f(0.98f, 0.07f);
glVertex2f(0.75f, 0.13f);

glEnd();
glPopMatrix();

glPushMatrix();//flood line last
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.95f, -0.1f);
glVertex2f(1.0f, -0.1f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.80f, -0.1f);
glVertex2f(0.85f, -0.1f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.70f, -0.1f);
glVertex2f(0.75f, -0.1f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.60f, -0.1f);
glVertex2f(0.65f, -0.1f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.50f, -0.1f);
glVertex2f(0.55f, -0.1f);
glEnd();
glPopMatrix();

glPushMatrix();

glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.40f, -0.1f);
glVertex2f(0.45f, -0.1f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.30f, -0.1f);
glVertex2f(0.35f, -0.1f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.20f, -0.1f);
glVertex2f(0.25f, -0.1f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.10f, -0.1f);
glVertex2f(0.15f, -0.1f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.00f, -0.1f);
glVertex2f(0.05f, -0.1f);
glEnd();
glPopMatrix();

glPushMatrix();//start
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.95f, 0.0f);
glVertex2f(1.0f, 0.0f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.80f, 0.0f);
glVertex2f(0.85f, 0.0f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.70f, 0.0f);
glVertex2f(0.75f, 0.0f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.60f, 0.0f);
glVertex2f(0.65f, 0.0f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.50f, 0.0f);
glVertex2f(0.55f, 0.0f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.40f, 0.0f);
glVertex2f(0.45f, 0.0f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.30f, 0.0f);
glVertex2f(0.35f, 0.0f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.20f, 0.0f);
glVertex2f(0.25f, 0.0f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.10f, 0.0f);
glVertex2f(0.15f, 0.0f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.00f, 0.0f);
glVertex2f(0.05f, 0.0f);
glEnd();
glPopMatrix();//end

glPushMatrix();//flood line down
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.95f, -0.69f);
glVertex2f(1.0f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.80f, -0.69f);
glVertex2f(0.85f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.70f, -0.69f);
glVertex2f(0.75f, -0.69f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.60f, -0.69f);
glVertex2f(0.65f, -0.69f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.50f, -0.69f);
glVertex2f(0.55f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();

glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.40f, -0.69f);
glVertex2f(0.45f, -0.69f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.30f, -0.69f);
glVertex2f(0.35f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.20f, -0.69f);
glVertex2f(0.25f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.10f, -0.69f);
glVertex2f(0.15f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.00f, -0.69f);
glVertex2f(0.05f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.10f, -0.69f);
glVertex2f(-0.05f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.20f, -0.69f);
glVertex2f(-0.15f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.30f, -0.69f);
glVertex2f(-0.25f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.40f, -0.69f);
glVertex2f(-0.35f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.50f, -0.69f);
glVertex2f(-0.45f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.60f, -0.69f);
glVertex2f(-0.55f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.70f, -0.69f);
glVertex2f(-0.65f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.80f, -0.69f);
glVertex2f(-0.75f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.90f, -0.69f);
glVertex2f(-0.85f, -0.69f);
glEnd();
glPopMatrix();

glPushMatrix();//flood line down 2nd
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.95f, -0.74f);
glVertex2f(1.0f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.80f, -0.74f);
glVertex2f(0.85f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.70f, -0.74f);
glVertex2f(0.75f, -0.74f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.60f, -0.74f);
glVertex2f(0.65f, -0.74f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.50f, -0.74f);
glVertex2f(0.55f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();

glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.40f, -0.74f);
glVertex2f(0.45f, -0.74f);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.30f, -0.74f);
glVertex2f(0.35f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.20f, -0.74f);
glVertex2f(0.25f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.10f, -0.74f);
glVertex2f(0.15f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(0.00f, -0.74f);
glVertex2f(0.05f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.10f, -0.74f);
glVertex2f(-0.05f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.20f, -0.74f);
glVertex2f(-0.15f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.30f, -0.74f);
glVertex2f(-0.25f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.40f, -0.74f);
glVertex2f(-0.35f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.50f, -0.74f);
glVertex2f(-0.45f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.60f, -0.74f);
glVertex2f(-0.55f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.70f, -0.74f);
glVertex2f(-0.65f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.80f, -0.74f);
glVertex2f(-0.75f, -0.74f);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslatef(-position,0.0f,0.0f);
     glBegin(GL_LINES);
glColor3f(1.0,1.0f,1.0f);
glVertex2f(-0.90f, -0.74f);
glVertex2f(-0.85f, -0.74f);
glEnd();
glPopMatrix();

glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 0.0f); // lower puj
glVertex2f(0.3f, -0.9f); // x, y
glVertex2f(0.3f, -0.75f); // x, y
glVertex2f(0.26f, -0.7f);
glVertex2f(0.2f, -0.65f); // x, y
glVertex2f(0.14f, -0.7f); // x, y
glVertex2f(0.1f, -0.75f); // x, y
glVertex2f(0.1f, -0.9f); // x, y
glEnd();

glLineWidth(3);
    glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 0.0f); // Puj Line
	glVertex2f(0.2f, -0.66f);
    glVertex2f(0.2f, -0.6f);
    glEnd();

    tree(-0.50,-1.0,0.2,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);
     tree(0.58,0.63,0.1,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);
    tree(0.12,0.60,0.1,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);
    tree(-0.50,0.60,0.1,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);
    tree(-0.40,-1.0,0.2,0.1f,0.33f,0.09f,0.2f,0.67f,0.2f,0.32f,0.2f,0.05f);












//glBegin(GL_LINES);

	//glColor3f(0, 0, 0); // birds
	//glVertex2f(-0.45f, 0.85f);











glFlush(); // Render now
}
void handleMouse(int button, int state, int x, int y)
{
if (button == GLUT_LEFT_BUTTON)
{	speed += 0.1f;
}
if (button == GLUT_RIGHT_BUTTON)
{speed -= 0.1f;   }
glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y)
{
switch (key)
{
case 'n':
    speed = 0.0f;
    break;
case 'h':
    speed = 0.1f;
    break;
     case 'r':
        rain = true;
         break;

    case 'e':

        rain = false;
        break;

        case 'z':
    glutDisplayFunc(day);

    break;

            case 'a':
    glutDisplayFunc(night);
    break;

     case 'f':
    glutDisplayFunc(flood);


    break;
glutPostRedisplay();
}
}



/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(1080, 720);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("flood");
   glutDisplayFunc(day);
   glutTimerFunc(100, update, 0);
    glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutMainLoop();
   return 0;
}
