/* Example 2
 * Points.c
 */

#include <GL/glut.h>
	
void init(void)
{
  glClearColor(1.0, 1.0, 1.0, 0.0);//white
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0f, 0.0f, 0.0f);//black
  glPointSize(12.0);//pixil size of the points

  glBegin(GL_POINTS);//points where vertixes begin
    glVertex2i(100, 50);
    glVertex2i(150, 100);
    glVertex2i(200, 150);
  glEnd();
  glFlush();
}

int main(int argc, char** argv)
{ 
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 400);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Points");
  init();   
  glutDisplayFunc(display);
  glutMainLoop();   
  return 0;
}

