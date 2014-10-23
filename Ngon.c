/* Example 7
 * Ngon.c
 */

#include <math.h>
#include <GL/glut.h>

void ngon(int n, float cx, float cy, float radius, float rotAngle)
{
  double angle, angleInc;
  int i;

  if(n < 3)
    return;
  
  angle = rotAngle * 3.14159265 / 180; 
  angleInc = 2 * 3.14159265 / n;

  glBegin(GL_LINE_STRIP);// to make lines between points.
    for(i = 0; i <= n; i++) {
      glVertex2d(radius * cos(angle) + cx, radius * sin(angle) + cy);
      angle = angle + angleInc;
    }
  glEnd();
}  

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 320.0, 0.0, 320.0);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glLineWidth(2.0);
  glColor3f(1.0f, 1.0f, 1.0f);
  ngon(3, 160, 160, 16, 30);// triangle. (sides, Cx, Cy, radius, angle)
  glColor3f(1.0f, 0.0f, 0.0f);
  ngon(4, 160, 160, 32, 45);// square.
  glColor3f(0.0f, 1.0f, 0.0f);
  ngon(5, 160, 160, 64, 18);// 5 sided.
  glColor3f(0.0f, 0.0f, 1.0f);
  ngon(6, 160, 160, 128, 0);// 6sided.
  ngon(256, 160, 160, 128, 0);// circle, or 256 sided.

  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(320, 320);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Ngon");
  init();   
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

