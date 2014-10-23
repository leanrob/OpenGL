/* Example 9
 * FilledArcs.c
 */

#include <math.h>
#include <GL/glut.h>

#ifndef PI
#define PI 3.14159625
#endif

void drawFilledArc(float cx, float cy, float radius, float startAngle,
		   float sweep)
{
  const int n = 30;
  float angle = startAngle * PI / 180;
  float angleInc = sweep * PI / (180 * n);

  int i;
  glBegin(GL_TRIANGLE_STRIP);
    for(i = 0; i < n; i++) {
      glVertex2d(cx, cy);
      glVertex2d(cx + radius * cos(angle), cy + radius * sin(angle));
      glVertex2d(cx + radius * cos(angle + angleInc),
                 cy + radius * sin(angle + angleInc));
      angle = angle + angleInc;
    }
  glEnd();
}

void init(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.5);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 320.0, 0.0, 320.0);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glColor4f(1.0, 0.0, 0.0, 0.3);
  drawFilledArc(135, 185, 60, 0, 360);

  glColor4f(0.0, 1.0, 0.0, 0.5);
  drawFilledArc(185, 185, 60, 0, 360);

  glColor4f(0.0, 0.0, 1.0, 0.3);
  drawFilledArc(160, 135, 60, 0, 360);

  glFlush();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(320, 320);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Filled Arcs");
  init();   
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

