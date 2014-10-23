/* Example 4
 * Shapes.c
 */

#include <GL/glut.h>

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 480.0, 0.0, 480.0);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(20.0, 20.0);
      glVertex2f(60.0, 160.0);
    glColor3f(0.0f, 0.0f, 1.0f);
      glVertex2f(180.0, 100.0);
      glVertex2f(220.0, 20.0);
  glEnd();

  glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(120.0, 320.0);
      glVertex2f(160.0, 420.0);
    
    glColor3f(0.0f, 1.0f, 0.0f);
      glVertex2f(200.0, 320.0);

    glColor3f(0.0f, 0.0f, 1.0f);
      glVertex2f(240.0, 420.0);
      glVertex2f(280.0, 320.0);
  glEnd();

  glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0);
      glVertex2f(320.0, 180.0);
    glColor3f(0.0f, 1.0f, 0.0f);
      glVertex2f(320.0, 260.0);
    glColor3f(0.0f, 0.0f, 1.0f);
      glVertex2f(360.0, 260.0);
    glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(400.0, 220.0);
    glColor3f(0.0f, 1.0f, 1.0f);
      glVertex2f(360.0, 180.0);
    glColor3f(1.0f, 0.0f, 1.0f);
      glVertex2f(340.0, 120.0);
  glEnd();

  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(480, 480);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Shapes");
  init();   
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
