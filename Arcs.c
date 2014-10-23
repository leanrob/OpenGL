/* Example 8
 * Arcs.c
 */

#include <math.h>
#include <GL/glut.h>

void drawArc(float cx, float cy, float radius, float startAngle, float sweep) {
//  const int n = 30;
  int n = 30;
  float angle = startAngle * 3.14159265 / 180;
  float angleInc = sweep * 3.14159265 / (180 * n);

  int i;
  glBegin(GL_LINE_STRIP);
    for(i = 0; i <= n; i++) {
      glVertex2d(cx + radius * cos(angle), cy + radius * sin(angle));
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

  glLineWidth(1.0);
  
  glColor3f(1.0, 0.0, 0.0);

  drawArc(160, 160, 80, -15, 210);

  drawArc(160, 160, 80, 0, 360);
  drawArc(200, 160, 40, 0, 180);
  drawArc(120, 160, 40, 0, -180);
  drawArc(120, 160, 10, 0, 360);
  drawArc(200, 160, 10, 0, 360);
  drawArc(160, 160, 10, 0, 300);// added by me.

  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(320, 320);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Arcs");
  init();   
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

