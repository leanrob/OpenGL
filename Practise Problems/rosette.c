#include <math.h>
#include <GL/glut.h>
int size;

void rosette(int n, float cx, float cy, float radius, float rotAngle)
{
  double angle, angleInc;
  double xpts[360];
  double ypts[360];
  int i;
  int size;
  int j;



  if(n < 3)
    return;
  
  angle = rotAngle * 3.14159265 / 180; 
  angleInc = 2 * 3.14159265 / n;

  for(i=0; i<=n; i++){
	xpts[i]=(radius*cos(angle)+cx);
	ypts[i]=(radius*sin(angle)+cy);
	angle = angle + angleInc;
}
  glBegin(GL_LINE_STRIP);// to make lines between points.
    for(i = 0; i <= n; i++) {
	for(j=i; j<=n; j++){
      glVertex2d(xpts[i], ypts[i]);
      glVertex2d(xpts[j], ypts[j]);
      }
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
  glColor3f(0.0f, 1.0f, 1.0f);
  rosette(size, 160, 160, 128, 0);

  glFlush();
}


int main(int argc, char** argv)
{
  size = atoi(argv[1]);
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

