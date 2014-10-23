/* Example 3
 * SmoothColoredPoints.c
 */

#include <GL/glut.h>
	
void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0f, 0.0f, 0.0f);
  glPointSize(12.0);

  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(100, 50);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(150, 100);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(200, 150);
  glEnd();
  glFlush();
}

int main(int argc, char **argv)
{ 
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 400);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Smooth Colored Points");
  init();   
  glutDisplayFunc(display);
  glutMainLoop();   
  return 0;
}
