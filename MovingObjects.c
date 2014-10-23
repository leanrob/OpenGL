/* Solid Rotation */

#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

GLfloat ambient[3];
GLfloat diffuse[3];
GLfloat specular[3];
GLfloat shiness[] = {50.0f};

static GLfloat spin = 0.0;

void myInit(void)
{
  GLfloat lightIntensity[] = {0.7f, 0.7f, 0.7f, 1.0f};
  GLfloat light_position[] = {2.0f, 6.0f, 3.0f, 0.0f};
  
  glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
//  glOrtho(-2.0 * 64 / 48.0, 2.0 * 64 / 48.0, -2.0, 2.0, 0.1, 100);
  gluPerspective(45.0, 640.0/480.0, 0.5, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(2.0, 3.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void displaySpheres(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  ambient[0] = 1; ambient[1] = 1; ambient[2] = 1;
  diffuse[0] = 1; diffuse[1] = 1; diffuse[2] = 1;
  specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
  
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

  glPushMatrix();
  glRotatef(spin, 0, 1, 0);
  glTranslatef(0, 0, 0);
  glutSolidTeapot(1);
  glPopMatrix();

  ambient[0] = 1; ambient[1] = 0; ambient[2] = 0;
  diffuse[0] = 1; diffuse[1] = 0; diffuse[2] = 0;
  specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
  
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

  glPushMatrix();
  glRotatef(-spin, 0, 1, 0);
  glTranslatef(2, 0, 0);
  glutSolidSphere(0.25, 16, 16);

  ambient[0] = 0; ambient[1] = 1; ambient[2] = 0;
  diffuse[0] = 0; diffuse[1] = 1; diffuse[2] = 0;
  specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
  
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

  glRotatef(4 * spin, 0, 1, 0);
  glTranslatef(0.5, 0, 0);
  glutSolidSphere(0.15, 16, 16);
  glPopMatrix();

  ambient[0] = 0; ambient[1] = 0; ambient[2] = 1;
  diffuse[0] = 0; diffuse[1] = 0; diffuse[2] = 1;
  specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
  
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

  glPushMatrix();
  glRotatef(-8 * spin, 0, 1, 0);
  glTranslatef(0, 1.2, 0);
  glutSolidTorus(0.1, 0.3, 16, 16);

  ambient[0] = 0.3; ambient[1] = 0.5; ambient[2] = 0.2;
  diffuse[0] = 0.2; diffuse[1] = 0.2; diffuse[2] = 0.2;
  specular[0] = 0.7; specular[1] = 0.6; specular[2] = 0.5;
  
  glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, shiness);

  glTranslatef(0, 0.3, 0);
  glRotatef(8 * spin, 1, 0, 0);
  glTranslatef(0, 0.3, 0);
  glutSolidSphere(0.15, 16, 16);
  glPopMatrix();

  glutSwapBuffers();
}
 
void rotateSpheres(void)
{
  spin = spin + 1.0;
  if (spin > 360.0)
    spin = 1.0;
  glutPostRedisplay();
}

void myMouse(int button, int state, int mouseX, int mouseY)
{
  switch (button) {
  case GLUT_RIGHT_BUTTON:
    if (state == GLUT_DOWN)
      glutIdleFunc(rotateSpheres);
    break;
  case GLUT_LEFT_BUTTON: 
    if (state == GLUT_DOWN)
      glutIdleFunc(NULL);
    break;
  default: 
    return;
  }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Solid Rotation");
  glutDisplayFunc(displaySpheres);
  glutMouseFunc(myMouse); 

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);


  myInit();
  glutMainLoop();

  return 0;
}

