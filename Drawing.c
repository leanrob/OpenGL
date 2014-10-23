/* Example 10
 * Drawing.c
 * 
 *
 * This program illustrates the use of the glut library
 * for interfacing with a Window System
 *
 * The program opens a window, clears it to black, then
 * draws a trail of random colored points at the location of
 * the mouse each time the left button is clicked and the
 * mouse is moved. The middle button exits the program.
 * The right button attaches the menu.
 *
 * The program also reacts correctly when the window is
 * resized by clearing the new window to black
 */

#include <stdio.h>
#include <GL/glut.h>

/*globals */

GLsizei wh = 500, ww = 500; /* initial window size */
GLdouble size = 4.0;

void drawPoint(int x, int y)
{
  glPointSize(size);
  y = wh - y;
  glColor3ub((char) random() % 256, (char) random() % 256,
             (char) random() % 256);

  glBegin(GL_POINTS);
    glVertex2i(x, y);
  glEnd();
  glFlush();
}

/* mouse callback routine */

void mouse(int button, int state, int x, int y)//GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, GLUT_RIGHT_BUTTON
{
  if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)//
    exit(0);
}

/* reshaping callback routine -- called whenever
 * window is resized or moved */

void reshape(GLsizei w, GLsizei h)
{
  /* adjust clipping box */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, (GLdouble) w, 0.0, (GLdouble) h, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  /* adjust viewport and clear */
  glViewport(0, 0, w, h);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
  
  /* set global size for use by drawing routine */
  ww = w;
  wh = h;

  size = 4.0;
}

void init(void)
{
  glViewport(0, 0, ww, wh);

  /* set 2D clipping window to match size of screen window.
   * This choice avoids having to scale object coordinates
   * each time window is resized 
   * /

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, (GLdouble) ww, 0.0, (GLdouble) wh, -1.0, 1.0);

  /* set clear color to black and clear window */

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}
  
void display(void)
{
  glEnable(GL_POINT_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void keyboard(unsigned char key, int x, int y)
{
  switch(key)
  {
    case '1' : size = 1.0; break;   
    case '2' : size = 2.0; break;   
    case '4' : size = 4.0; break;   
    case '6' : size = 6.0; break;   
    case '8' : size = 8.0; break;   

    case 'c' : glClear(GL_COLOR_BUFFER_BIT); glFlush(); break;// glFlush had to be added to make the c work.

    case 'q' : exit(0);  
  }
}

void menu(int value)
{
  keyboard((unsigned char) value, 0, 0);
}

/* The main program -- note that there is no "flow
 * of control" -- the program merely calls functions
 * to handle interactions
 */

int main(int argc, char** argv)
{
  int point_menu;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("Drawing");
  init();
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);//to call register mouse listener.
  glutMotionFunc(drawPoint);
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);

  point_menu = glutCreateMenu(menu);
    glutAddMenuEntry("1", '1');
    glutAddMenuEntry("2", '2');
    glutAddMenuEntry("4", '4');
    glutAddMenuEntry("6", '6');
    glutAddMenuEntry("8", '8');
  
  glutCreateMenu(menu);
    glutAddMenuEntry("Clear c", 'c');
    glutAddSubMenu("Point size", point_menu);
    glutAddMenuEntry("Quit  q", 'q');
  glutAttachMenu(GLUT_RIGHT_BUTTON);  

  glutMainLoop();
}

