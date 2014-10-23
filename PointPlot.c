/* Example 5
 * PointPlot.c
 */

#include <math.h>
#include <GL/glut.h>

const double PI = 3.14159265;
const int screenWidth = 640;
const int screenHeight = 480;
GLdouble A, B, C, D;//used for scaling and shifting.

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, screenWidth, 0.0, screenHeight);// used to scale x.
  A = screenWidth / 4.0;
  B = 0.0;//0 because we are not shifting along the x axis.
  C = D = screenHeight / 2.0;//scaling and shifting y.
}

void display(void)
{
  GLdouble x;
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(4.0);

  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glBegin(GL_POINTS);
    for (x = 0; x < 4.0; x += 0.005) {
      GLdouble f = exp(-x) * cos(2 * PI * x);
      glColor3f(1.0 - x / 4, 1.0, 0.0 + x / 4);//dont worry, changes color for every pixel.
      glVertex2d(A * x + B, C * f + D);
    }
  glEnd();

  glFlush();
}

int main(int argc, char** argv)
{ 
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(screenWidth, screenHeight);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Point Plot");
  init();   
  glutDisplayFunc(display);
  glutMainLoop();   
  return 0;
}

