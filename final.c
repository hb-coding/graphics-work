#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include "CSCIx229.h"
#endif
using namespace std;

       
int axes=1;       //  Display axes
int th=180;         //  Azimuth of view angle
int ph=25;         //  Elevation of view angle
int light=1;      //  Lighting
int rep=1;        //  Repitition
double asp=1;     //  Aspect ratio
double dim=10.0;   //  Size of world
double xpos= 1;
int ra=0;
int q=0;
int f=0;
// Light values
int emission  =   0;  // Emission intensity (%)
int ambient   =  00;  // Ambient intensity (%)
int diffuse   = 100;  // Diffuse intensity (%)
int specular  =   0;  // Specular intensity (%)
int shininess =   0;  // Shininess (power of two)
float shinyvec[1];    // Shininess (value)
int zh        =  90;  // Light azimuth
float ylight  =   1;
int w, s, a;
int d =15;
unsigned int texture[20];
unsigned int floors[3];
unsigned int wall[2];
double v=1;
int f1=0;
int height=7;
int fog=0;
void set(){





}
static void ball()
{
GLUquadricObj *obj1 = gluNewQuadric();
   //  Save transformation
   glPushMatrix();

gluQuadricNormals(obj1, GLU_SMOOTH);
gluQuadricTexture(obj1, GL_TRUE);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[6]);  //9ball
   //  Offset, scale and rotate
   glTranslated(2,2.1,-2);    
   glScaled(.1,.1,.1);
   
   gluSphere(obj1, 1.0,16,16);
   //  Undo transofrmations

glDisable(GL_TEXTURE_2D);
   glPopMatrix();

glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[7]);  //2ball
   //  Offset, scale and rotate
   glTranslated(2.4 ,2.1,-2);    
   glScaled(.1,.1,.1);
   gluSphere(obj1, 1.0,16,16);
   //  Undo transofrmations
   glDisable(GL_TEXTURE_2D);
   glPopMatrix();

glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[8]);  //14ball
   //  Offset, scale and rotate
   glTranslated(1.4 , 2.1,-1);    
   glScaled(.1,.1,.1);
   gluSphere(obj1, 1.0,16,16);
   //  Undo transofrmations
   glDisable(GL_TEXTURE_2D);
   glPopMatrix();

glPushMatrix();
  glTranslated(2.0, 5.0, 0.0);  
   glScaled(.1,.1,.1);                                    //light1
   //  White ball
   glColor3f(1,1,0);
   gluSphere(obj1, 1.0,16,16);
glPopMatrix();

glPushMatrix();
  glTranslated(2.0, 5.0, 1.0);  
   glScaled(.1,.1,.1);                                    //light2
   //  White ball
   glColor3f(1,1,0);
   gluSphere(obj1, 1.0,16,16);
glPopMatrix();

glPushMatrix();
  glTranslated(2.0, 5.0, -1.0);  
   glScaled(.1,.1,.1);                                    //light3
   //  White ball
   glColor3f(1,1,0);
   gluSphere(obj1, 1.0,16,16);
glPopMatrix();

glPushMatrix();   //cue ball
  glTranslated(2.0, 2.1, 2.0);  
   glScaled(.1,.1,.1);
   //  White ball
   glColor3f(1,1,1);
   gluSphere(obj1, 1.0,16,16);
glPopMatrix();

glPushMatrix();   //end of light
  glTranslated(2.0, 6.0, -1.6);  
   glScaled(.1,.1,.1);
   //  White ball
   glColor3f(1,1,1);
   gluSphere(obj1, 1.0,16,16);
glPopMatrix();

glPushMatrix();   //end of light
glTranslated(2.0, 6.0, 1.6);  
   glScaled(.1,.1,.1);
   //  White ball
   glColor3f(1,1,1);
   gluSphere(obj1, 1.0,16,16);
glPopMatrix();

glEnd();
}
void walls(){
 glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D,wall[q]);
    glBegin(GL_QUADS);
glNormal3f(1.0, 0.0, 0.0);
glTexCoord2f(0, 0); glVertex3f(-20, 0.0, 20); 
glTexCoord2f(0, 1); glVertex3f(-20, 15.0, 20);
glTexCoord2f(1, 1); glVertex3f(-20, 15.0, -20);
glTexCoord2f(1, 0);glVertex3f(-20, 0.0, -20);

glNormal3f(0.0, 0.0, 1.0);
glTexCoord2f(0, 0); glVertex3f(-21, 0.0, -20); 
glTexCoord2f(0, 1); glVertex3f(-21, 15.0, -20);
glTexCoord2f(1, 1); glVertex3f(21, 15.0, -20);
glTexCoord2f(1, 0);glVertex3f(21, 0.0, -20);

glNormal3f(0.0, 0.0, -1.0);
glTexCoord2f(0, 0); glVertex3f(-20, 0.0, 20); 
glTexCoord2f(0, 1); glVertex3f(-20, 15.0, 20);
glTexCoord2f(1, 1); glVertex3f(20, 15.0, 20);
glTexCoord2f(1, 0);glVertex3f(20, 0.0, 20);

glNormal3f(-1.0, 0.0, 0.0);
glTexCoord2f(0, 0); glVertex3f(20, 0.0, 20); 
glTexCoord2f(0, 1); glVertex3f(20, 15.0, 20);
glTexCoord2f(1, 1); glVertex3f(20, 15.0, -20);
glTexCoord2f(1, 0);glVertex3f(20, 0.0, -20);


glDisable(GL_TEXTURE_2D);
glEnd();
}
void ground(){
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D,texture[12]);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(1, 1); glVertex3f(-20, 0, -20);
    glTexCoord2f(0, 1); glVertex3f(-20, 0, 20);
   glTexCoord2f(0, 0); glVertex3f(20, 0, 20);
    glTexCoord2f(1, 0); glVertex3f(20, 0, -20);

glDisable(GL_TEXTURE_2D);
glEnd();
}
void drawtable(){
 glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D,texture[1]);
    glBegin(GL_QUADS);
  
glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(0, 2, 5);     //top of table
    glTexCoord2f(0, 1); glVertex3f(0, 2, -5);
    glTexCoord2f(1, 1); glVertex3f(4, 2, -5);
    glTexCoord2f(1, 0); glVertex3f(4, 2, 5);
glDisable(GL_TEXTURE_2D);
glEnd();

glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D,texture[2]);


glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glTexCoord2f(1, 1); glVertex3f(-0.5, 2.25, 5.25);  //front edge
    glTexCoord2f(0, 1); glVertex3f(-0.5, 1.5, 5.25);
    glTexCoord2f(0, 0); glVertex3f(4.5, 1.5, 5.25);
    glTexCoord2f(1, 0); glVertex3f(4.5, 2.25, 5.25);
  
    glNormal3f(0, 1, 0);
    glTexCoord2f(1, 1); glVertex3f(-.5, 2.25, 5.25);  //front cover
    glTexCoord2f(0, 1); glVertex3f(-0.5, 2.25, 5.0);
    glTexCoord2f(0, 0); glVertex3f(4.5, 2.25, 5.0);
    glTexCoord2f(1, 0); glVertex3f(4.5, 2.25, 5.25);

   
    glNormal3f(0, 0, -1);
    glTexCoord2f(1, 1); glVertex3f(-0.5, 2.25, -5.25); //back edge
    glTexCoord2f(0, 1); glVertex3f(-0.5, 1.5, -5.25);
    glTexCoord2f(0, 0); glVertex3f(4.5, 1.5, -5.25);
    glTexCoord2f(1, 0); glVertex3f(4.5, 2.25, -5.25);

    glNormal3f(0, 1, 0);
    glTexCoord2f(1, 1); glVertex3f(-0.5, 2.25, -5.25); //back cover
    glTexCoord2f(0, 1); glVertex3f(-0.5, 2.25, -5.0);
    glTexCoord2f(0, 0); glVertex3f(4.5, 2.25, -5.0);
    glTexCoord2f(1, 0); glVertex3f(4.5, 2.25, -5.25);
    
    glNormal3f(-1, 0, 0);
    glTexCoord2f(1, 1); glVertex3f(-.5, 2.25, 5.25);
    glTexCoord2f(0, 1); glVertex3f(-.5, 2.25, -5.25); //left side
    glTexCoord2f(0, 0); glVertex3f(-.5, 1.5, -5.25);
    glTexCoord2f(1, 0); glVertex3f(-.5, 1.5, 5.25);
    
    glNormal3f(1, 0, 0);
    glTexCoord2f(1, 1); glVertex3f(4.5, 2.25, 5.25);
    glTexCoord2f(0, 1); glVertex3f(4.5, 2.25, -5.25);
    glTexCoord2f(0, 0); glVertex3f(4.5, 1.5, -5.25); //right side
    glTexCoord2f(1, 0); glVertex3f(4.5, 1.5, 5.25);

    

glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(4.5, 2.25, 4.6);
    glTexCoord2f(1, 1); glVertex3f(4.5, 2.25, 0.2);  //left cover
    glTexCoord2f(1, 0); glVertex3f(4, 2.25, 0.2);
    glTexCoord2f(0, 1); glVertex3f(4, 2.25, 4.6); 

glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(4.5, 2.25, -0.2);
    glTexCoord2f(1, 1); glVertex3f(4.5, 2.25, 0.2);  //left connector
    glTexCoord2f(1, 0); glVertex3f(4.25, 2.25, 0.2);
    glTexCoord2f(0, 1); glVertex3f(4.25, 2.25, -0.2);
                                                    
glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(4.5, 2.25, -4.7);
    glTexCoord2f(1, 1); glVertex3f(4.5, 2.25, -0.2);    //left cover 2nd half
    glTexCoord2f(1, 0); glVertex3f(4, 2.25, -0.2);
    glTexCoord2f(0, 1); glVertex3f(4, 2.25, -4.7); 

glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(4.5, 2.25, -4.5);
    glTexCoord2f(1, 1); glVertex3f(4.5, 2.25, -5.25);  //back left connector
    glTexCoord2f(1, 0); glVertex3f(4.15, 2.25, -5.25);
    glTexCoord2f(0, 1); glVertex3f(4.15, 2.25, -4.5);

glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(4.5, 2.25, 4.5);
    glTexCoord2f(1, 1); glVertex3f(4.5, 2.25, 5.25);  //front left connector
    glTexCoord2f(1, 0); glVertex3f(4.15, 2.25, 5.25);
    glTexCoord2f(0, 1); glVertex3f(4.15, 2.25, 4.5);

    glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(-.5, 2.25, 4.6);
    glTexCoord2f(1, 1); glVertex3f(-.5, 2.25, 0.2);  //right cover 1st half
    glTexCoord2f(1, 0); glVertex3f(0, 2.25, 0.2);
    glTexCoord2f(0, 1); glVertex3f(0, 2.25, 4.6); 

   glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(-.25, 2.25, -.2);
    glTexCoord2f(1, 1); glVertex3f(-.25, 2.25, 0.2);  //right connector
    glTexCoord2f(1, 0); glVertex3f(-.5, 2.25, 0.2);
    glTexCoord2f(0, 1); glVertex3f(-.5, 2.25, -.2);

 glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(-.25, 2.25, -4.5);
    glTexCoord2f(1, 1); glVertex3f(-.25, 2.25, -5.25);  //back right connector
    glTexCoord2f(1, 0); glVertex3f(-.5, 2.25, -5.25);
    glTexCoord2f(0, 1); glVertex3f(-.5, 2.25, -4.5);

glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(-.25, 2.25, 4.5);
    glTexCoord2f(1, 1); glVertex3f(-.25, 2.25, 5.25);  //front right connector
    glTexCoord2f(1, 0); glVertex3f(-.5, 2.25, 5.25);
    glTexCoord2f(0, 1); glVertex3f(-.5, 2.25, 4.5);

glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0); glVertex3f(-.5, 2.25, -4.65); //right cover 2nd half
    glTexCoord2f(1, 1); glVertex3f(-.5, 2.25, -0.2);
    glTexCoord2f(1, 0); glVertex3f(0, 2.25, -0.2);
    glTexCoord2f(0, 1); glVertex3f(0, 2.25, -4.65); 
glDisable(GL_TEXTURE_2D);
glEnd();
//**************************************************************************bumpers

glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D,texture[4]);
glBegin(GL_QUADS);
  glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(0, 2.25, 5);
    glTexCoord2f(1, 1); glVertex3f(0, 2.25, 0.25);    //left bumper first half
    glTexCoord2f(1, 0); glVertex3f(0, 2.0, 0.25);
    glTexCoord2f(0, 1); glVertex3f(0, 2.0, 5);

    glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 0); glVertex3f(0, 2.25, -5);
    glTexCoord2f(1, 1); glVertex3f(0, 2.25, -0.25);    //left bumper 2nd half
    glTexCoord2f(1, 0); glVertex3f(0, 2.0, -0.25);
    glTexCoord2f(0, 1); glVertex3f(0, 2.0, -5);

 glNormal3f(1, 0, 0);    
    glTexCoord2f(0, 0); glVertex3f(4, 2.25, 5);
    glTexCoord2f(1, 1); glVertex3f(4, 2.25, 0.25);
    glTexCoord2f(1, 0); glVertex3f(4, 2.0, 0.25);    //right bumper 1st half
    glTexCoord2f(0, 1); glVertex3f(4, 2.0, 5);

glNormal3f(1, 0, 0);    
    glTexCoord2f(0, 0); glVertex3f(4, 2.25, -5);
    glTexCoord2f(1, 1); glVertex3f(4, 2.25, -0.25);
    glTexCoord2f(1, 0); glVertex3f(4, 2.0, -0.25);    //right bumper 2nd half
    glTexCoord2f(0, 1); glVertex3f(4, 2.0, -5);

glNormal3f(0, 0, -1);
    glTexCoord2f(1, 1); glVertex3f(0.25, 2.25, 5.0);  //front bumper
    glTexCoord2f(0, 1); glVertex3f(0.25, 2.0, 5.0);
    glTexCoord2f(0, 0); glVertex3f(3.75, 2.0, 5.0);
    glTexCoord2f(1, 0); glVertex3f(3.75, 2.25, 5.0);

glNormal3f(0, 0, 1);
    glTexCoord2f(1, 1); glVertex3f(0.25, 2.25, -5.0); //back bumper
    glTexCoord2f(0, 1); glVertex3f(0.25, 2.0, -5.0);
    glTexCoord2f(0, 0); glVertex3f(3.75, 2.0, -5.0);
    glTexCoord2f(1, 0); glVertex3f(3.75, 2.25, -5.0);

glDisable(GL_TEXTURE_2D);
glEnd();
}
void ceiling(){

    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D,texture[15]);
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(1, 1); glVertex3f(-20, 10, -20);
    glTexCoord2f(0, 1); glVertex3f(-20, 10, 20);
   glTexCoord2f(0, 0); glVertex3f(20, 10, 20);
    glTexCoord2f(1, 0); glVertex3f(20, 10, -20);

glDisable(GL_TEXTURE_2D);
glEnd();


}
void drawlight(){
 glDisable(GL_TEXTURE_2D);
GLUquadricObj *obj2 = gluNewQuadric();
glEnable(GL_TEXTURE_2D);
   glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D,texture[14]);
glPushMatrix();
glTranslated(2.0, 6.0, -1.5);
//glRotated(0.0, 1.0, 0.0, 0.0);
gluCylinder(obj2, .1, .1, 3.0, 30.0, 30.0);
glPopMatrix();

glPushMatrix();
glTranslated(2, 5, 1);
glRotated(270, 1.0, 0.0, 0.0);
 glutSolidCone(.5, 1,10, 10);
glPopMatrix();

glPushMatrix();
glTranslated(2, 5, 0);
glRotated(270, 1.0, 0.0, 0.0);
 glutSolidCone(.5, 1,10, 10);
glPopMatrix();

glPushMatrix();
glTranslated(2, 5, -1);
glRotated(270, 1.0, 0.0, 0.0);
 glutSolidCone(.5, 1,10, 10);
glPopMatrix();


glDisable(GL_TEXTURE_2D);
glEnd();
}
void drawpic(){

    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D,texture[5]);
    glBegin(GL_QUADS);
    
    glTexCoord2f(1, 1); glVertex3f(19, 8, 0);
    glTexCoord2f(0, 1); glVertex3f(19, 8, 10);
    glTexCoord2f(0, 0); glVertex3f(19, 2, 10);
    glTexCoord2f(1, 0); glVertex3f(19, 2, 0);
glDisable(GL_TEXTURE_2D);
glEnd();

}
void bar(){
 //glEnable(GL_TEXTURE_2D);
   // glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    //glBindTexture(GL_TEXTURE_2D,texture[2]);
  
int i;
for(int i=3; i>0; i-=1){
glPushMatrix();
   glTranslated(-20.0, i, 0.0);
   glRotated(90, 1.0, 0.0, 0.0);  
   glRotated(180, 0.0, 1.0, 0.0);               
   gluPartialDisk(gluNewQuadric(),5, 8, 10, 1, 0.0, -180); 
   glPopMatrix();
}

glDisable(GL_TEXTURE_2D);
glEnd();
}
void disk() {

   glPushMatrix();
   glTranslated(0.0,2.26,0.0);
   glRotated(90, 1.0, 0.0, 0.0);                  //right side
   gluPartialDisk(gluNewQuadric(),0.2, .4, 10, 1, 0.0, -180); 
   glPopMatrix();
 
glPushMatrix();
   glTranslated(0.1, 2.26, -4.8);
   glRotated(90, 1.0, 0.0, 0.0); //back right side
   glRotated(45, 0.0, 0.0, 1.0);
   gluPartialDisk(gluNewQuadric(),0.2, .4, 10, 1, 0.0, -180); 
   glPopMatrix();

  glPushMatrix();
  glTranslated(4.0, 2.26,0.0);
  glRotated(90, 1.0, 0.0, 0.0);   //left side
  glRotated(180, 0.0, 1.0, 0.0);
  gluPartialDisk(gluNewQuadric(),0.2, .4, 10, 1, 0.0, -180);
  glPopMatrix();
 
 glPushMatrix();
  glTranslated(3.9, 2.26, -4.8);
  glRotated(90, 1.0, 0.0, 0.0);   //back left
  glRotated(180, 0.0, 1.0, 0.0);
  glRotated(45, 0.0, 0.0, 1.0);
  gluPartialDisk(gluNewQuadric(),0.2, .4, 10, 1, 0.0, -180);
  glPopMatrix();

glPushMatrix();
  glTranslated(3.9, 2.26, 4.8);
  glRotated(90, 1.0, 0.0, 0.0);   //front left
  glRotated(180, 0.0, 1.0, 0.0);
  glRotated(315, 0.0, 0.0, 1.0);
  gluPartialDisk(gluNewQuadric(),0.2, .4, 10, 1, 0.0, -180);
  glPopMatrix();

glPushMatrix();
   glTranslated(0.1, 2.26, 4.8);
   glRotated(90, 1.0, 0.0, 0.0); //front right side
   glRotated(315, 0.0, 0.0, 1.0);
   gluPartialDisk(gluNewQuadric(),0.2, .4, 10, 1, 0.0, -180); 
   glPopMatrix();



}
void legs(){
glDisable(GL_TEXTURE_2D);
GLUquadricObj *obj = gluNewQuadric();
gluQuadricNormals(obj, GLU_SMOOTH);
gluQuadricTexture(obj, GL_TRUE);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, texture[2]);

glPushMatrix();
glTranslated(0.0, 2.0, 4.5);
glRotated(90, 1.0, 0.0, 0.0);
gluCylinder(obj, .15, .15, 2.0, 30.0, 30.0);
glPopMatrix();

glPushMatrix();
glTranslated(0.0, 2.0, -4.5);
glRotated(90, 1.0, 0.0, 0.0);
gluCylinder(obj, .15, .15, 2.0, 30.0, 30.0);
glPopMatrix();

glPushMatrix();
glTranslated(4.0, 2.0, -4.5);
glRotated(90, 1.0, 0.0, 0.0);
gluCylinder(obj, .15, .15, 2.0, 30.0, 30.0);
glPopMatrix();

glPushMatrix();
glTranslated(4.0, 2.0, 4.5);
glRotated(90, 1.0, 0.0, 0.0);
gluCylinder(obj, .15, .15, 2.0, 30.0, 30.0);
glPopMatrix();

}
void shelf(){

 glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D,texture[2]);
    glBegin(GL_QUADS);

glNormal3f(-1, 0, 0);
 glTexCoord2f(1, 0); glVertex3f(-19.5, 0, -6);
 glTexCoord2f(0, 0); glVertex3f(-19.5, 0, 6);
 glTexCoord2f(0, 1); glVertex3f(-19.5, 8, 6);
 glTexCoord2f(1, 1); glVertex3f(-19.5, 8, -6);

glNormal3f(0,0,-1);
glTexCoord2f(0, 0); glVertex3f(-19.5, 0, 6);
glTexCoord2f(0, 1); glVertex3f(-19.5, 8, 6);
glTexCoord2f(1, 1); glVertex3f(-16.5, 8, 6);
glTexCoord2f(1, 0); glVertex3f(-16.5, 0, 6);

glNormal3f(0,0,1);
glTexCoord2f(0, 0); glVertex3f(-19.5, 0, -6);
glTexCoord2f(0, 1); glVertex3f(-19.5, 8, -6);
glTexCoord2f(1, 1); glVertex3f(-16.5, 8, -6);
glTexCoord2f(1, 0); glVertex3f(-16.5, 0, -6);

glNormal3f(0,1,0);
glTexCoord2f(1, 1); glVertex3f(-19.5, 8, -6);
glTexCoord2f(0, 1); glVertex3f(-19.5, 8, 6);
glTexCoord2f(0, 0); glVertex3f(-16.5, 8, 6);
glTexCoord2f(1, 0); glVertex3f(-16.5, 8, -6);

glNormal3f(0,1,0);
glTexCoord2f(1, 1); glVertex3f(-19.5, 6, -6);
glTexCoord2f(0, 1); glVertex3f(-19.5, 6, 6);
glTexCoord2f(0, 0); glVertex3f(-16.5, 6, 6);
glTexCoord2f(1, 0); glVertex3f(-16.5, 6, -6);

glNormal3f(0,1,0);
glTexCoord2f(1, 1); glVertex3f(-19.5, 4, -6);
glTexCoord2f(0, 1); glVertex3f(-19.5, 4, 6);
glTexCoord2f(0, 0); glVertex3f(-16.5, 4, 6);
glTexCoord2f(1, 0); glVertex3f(-16.5, 4, -6);

glNormal3f(0,1,0);
glTexCoord2f(1, 1); glVertex3f(-19.5, 2, -6);
glTexCoord2f(0, 1); glVertex3f(-16.5, 2, 6);
glTexCoord2f(0, 0); glVertex3f(-16.5, 2, 6);
glTexCoord2f(1, 0); glVertex3f(-16.5, 2, -6);
glDisable(GL_TEXTURE_2D);
glEnd();


glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D,texture[9]);
glBegin(GL_QUADS);
glNormal3f(1,0,0); //books
glTexCoord2f(1, 1); glVertex3f(-16.5, 4, -6);
glTexCoord2f(1, 0); glVertex3f(-16.5, 2, -6);
glTexCoord2f(0, 0); glVertex3f(-16.5, 2, 6);
glTexCoord2f(0, 1); glVertex3f(-16.5, 4, 6);

glDisable(GL_TEXTURE_2D);
glEnd();

glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D,texture[10]);
glBegin(GL_QUADS);
glNormal3f(1,0,0); //books
glTexCoord2f(1, 1); glVertex3f(-16.5, 8, -6);
glTexCoord2f(1, 0); glVertex3f(-16.5, 6, -6);
glTexCoord2f(0, 0); glVertex3f(-16.5, 6, 6);
glTexCoord2f(0, 1); glVertex3f(-16.5, 8, 6);

glDisable(GL_TEXTURE_2D);
glEnd();

}
void display(){
double Ex = (-2*dim*Sin(th)*Cos(ph));
   double Ey = +2*dim*Sin(ph);
   double Ez = +2*dim*Cos(th)*Cos(ph);
   //  Erase the window and the depth buffer
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   //  Enable Z-buffering in OpenGL

 

   //  Set perspective
   glLoadIdentity();
   gluLookAt(w,height,d, (w+Ex),Ey,(d+Ez), 0,Cos(ph),0);
   //  Light switch
  
   GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};
   GLfloat density = 0.06;
   glEnable(GL_DEPTH_TEST);
   
   glFogi (GL_FOG_MODE, GL_EXP2);
   glFogfv (GL_FOG_COLOR, fogColor);
   glFogf (GL_FOG_DENSITY, density);
   glHint (GL_FOG_HINT, GL_NICEST);

   if(light)
   {
      //  Translate intensity to color vectors
      float Ambient[]   = {0.01*ambient ,0.01*ambient ,0.01*ambient ,1.0};
      float Diffuse[]   = {0.01*diffuse ,0.01*diffuse ,0.01*diffuse ,1.0};
      float Specular[]  = {0.01*specular,0.01*specular,0.01*specular,1.0};
      //  Light direction
      float Position[]  = {5*Cos(zh),ylight,5*Sin(zh),1};
      float pos[] = {2.0, 5.0, 0.0, 1};
      float pos2[] = {2.0, 5.0, -1.0, 1};
      float pos3[] = {2.0, 5.0, 1.0, 1};
      float pos0[] = {18.0, 8.0, 11.0, 1};
      
      
      ball();
      //  OpenGL should normalize normal vectors
      glEnable(GL_NORMALIZE);
      //  Enable lighting
      glEnable(GL_LIGHTING);
      //  glColor sets ambient and diffuse color materials
      glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
      glEnable(GL_COLOR_MATERIAL);
      //  Enable light 0
      glEnable(GL_LIGHT2);
      glEnable(GL_LIGHT1);
      glEnable(GL_LIGHT3);
      glEnable(GL_LIGHT0);

      glLightfv(GL_LIGHT1,GL_AMBIENT ,Ambient);
      glLightfv(GL_LIGHT1,GL_DIFFUSE ,Diffuse);
      glLightfv(GL_LIGHT1,GL_SPECULAR,Specular);
      glLightfv(GL_LIGHT1, GL_POSITION, pos);
      //  Set ambient, diffuse, specular components and position of light 0
      glLightfv(GL_LIGHT2,GL_AMBIENT ,Ambient);
      glLightfv(GL_LIGHT2,GL_DIFFUSE ,Diffuse);
      glLightfv(GL_LIGHT2,GL_SPECULAR,Specular);
      glLightfv(GL_LIGHT2,GL_POSITION,pos2);

      glLightfv(GL_LIGHT0,GL_AMBIENT ,Ambient);
      glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
      glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
      glLightfv(GL_LIGHT0,GL_POSITION,pos0);
	
      glLightfv(GL_LIGHT3,GL_AMBIENT ,Ambient);
      glLightfv(GL_LIGHT3,GL_DIFFUSE ,Diffuse);
      glLightfv(GL_LIGHT3,GL_SPECULAR,Specular);
      glLightfv(GL_LIGHT3,GL_POSITION,pos3);
   }
   else
      glDisable(GL_LIGHTING);
   //  Draw scene
ground();
walls();
drawtable(); 
drawpic();
//bar();
ceiling();
shelf();
 disk();
legs();
drawlight();

glDisable(GL_TEXTURE_2D);
glFlush();
glutSwapBuffers();
}
void idle()
{
   //  Elapsed time in seconds
   double t = glutGet(GLUT_ELAPSED_TIME)/1000.0;
   zh = fmod(90*t,360.0);
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}
void special(int key,int x,int y)
{
   //  Right arrow key - increase angle by 5 degrees
   if (key == GLUT_KEY_RIGHT)
      th += 5;
   //  Left arrow key - decrease angle by 5 degrees
   else if (key == GLUT_KEY_LEFT)
      th -= 5;
   else if (key == GLUT_KEY_F1)
     ra+=1;
   //  Up arrow key - increase elevation by 5 degrees
   else if (key == GLUT_KEY_UP)
      ph += 5;
   //  Down arrow key - decrease elevation by 5 degrees
   else if (key == GLUT_KEY_DOWN)
      ph -= 5;
   //  PageUp key - increase dim
   else if (key == GLUT_KEY_F2)
      dim += 0.1;
   //  PageDown key - decrease dim
   else if (key == GLUT_KEY_F3 && dim>1)
      dim -= 0.1;
if (key == GLUT_KEY_F1){
    if(q<=1){
      q++;
	}
	else
	q=0;
	}
   //  Keep angles to +/-360 degrees
   th %= 360;
   ph %= 360;
   //  Update projection
   Project(45,asp,dim);
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}
void key(unsigned char ch,int x,int y)
{
   //  Exit on ESC
   if (ch == 27)
      exit(0);
   //  Reset view angle
   else if (ch == '0')
      th = ph = 0;
   //  Toggle texture mode
  
   //  Toggle axes
   else if (ch == 'x' || ch == 'X')
      v += .1;
   //  Toggle lighting
   else if (ch == 'l' || ch == 'L')
      light = 1-light;
   //  Toggle textures mode

   //  Light elevation
   else if (ch=='[')
      ylight -= 0.1;
   else if (ch==']')
      ylight += 0.1;
   //  Ambient level
   else if (ch=='t' && ambient>0)
      ambient -= 5;
   else if (ch=='T' && ambient<100)
      ambient += 5;
   //  Diffuse level
   else if (ch=='y' && diffuse>0)
      diffuse -= 5;
   else if (ch=='Y' && diffuse<100)
      diffuse += 5;
   //  Specular level
   else if (ch=='u' && specular>0)
      specular -= 5;
   else if (ch=='U' && specular<100)
      specular += 5;
   //  Emission level
   else if (ch=='e' && emission>0)
      emission -= 5;
   else if (ch=='E' && emission<100)
      emission += 5;
   //  Shininess level
   else if (ch=='n' && shininess>-1)
      shininess -= 1;
   else if (ch=='N' && shininess<7)
      shininess += 1;
 else if (ch=='w')
      d -= 1;
else if (ch=='d')
      w += 1;
else if (ch=='s')
      d += 1;
else if (ch=='a')
      w -= 1;
else if (ch=='v')
      height += 1;
else if (ch=='V')
      height -= 1;
   //  Repitition
   else if (ch=='+')
      rep++;
   else if (ch=='-' && rep>1)
      rep--;
 else if (ch=='f')
       glEnable (GL_FOG);
else if (ch=='F')
      glDisable (GL_FOG);

   //  Translate shininess power to value (-1 => 0)
   shinyvec[0] = shininess<0 ? 0 : pow(2.0,shininess);
   //  Reproject
   Project(45,asp,dim);
   //  Tell GLUT it is necessary to redisplay the scene
   glutPostRedisplay();
}
void reshape(int width,int height)
{
   //  Ratio of the width to the height of the window
   asp = (height>0) ? (double)width/height : 1;
   //  Set the viewport to the entire window
   glViewport(0,0, width,height);
   //  Set projection
   Project(45,asp,dim);
}
int main(int argc,char* argv[])
{
   //  Initialize GLUT
   glutInit(&argc,argv);
   //  Request double buffered, true color window with Z buffering at 600x600
   glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
   glutInitWindowSize(800,800);
   glutCreateWindow("HW3 Hayden Berge");
   //  Set callbacks
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutSpecialFunc(special);
   glutKeyboardFunc(key);
   glutIdleFunc(idle);
   //  Load textures
   texture[0] = LoadTexBMP("floor.bmp");
   texture[1]= LoadTexBMP("felt.bmp");
   texture[2]= LoadTexBMP("plank02.bmp");
texture[3]= LoadTexBMP("st.bmp");
texture[4]= LoadTexBMP("leather.bmp");
texture[5]= LoadTexBMP("poker.bmp");
texture[6]= LoadTexBMP("Ball9.bmp");
texture[7]= LoadTexBMP("ball2.bmp");
texture[8]= LoadTexBMP("ball14.bmp");
texture[9]= LoadTexBMP("books2.bmp");
texture[10]= LoadTexBMP("books1.bmp");
texture[12]= LoadTexBMP("floor.bmp");
texture[14]= LoadTexBMP("silver.bmp");
texture[15]= LoadTexBMP("Matte.bmp");
//******************************************
wall[0]= LoadTexBMP("st.bmp");
wall[1]= LoadTexBMP("wall02.bmp");
   //  Pass control to GLUT so it can interact with the user
   glutMainLoop();
   return 0;
}







