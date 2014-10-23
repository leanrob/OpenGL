/* Example 1: Hello.c
 * Simple introductory OpenGL program.
 * It draws a black square on a white 
 * background.
 */

#include <GL/glut.h>

void init(void)
/* set the initial state */
{
  /* select clearing (background) color to white */
  glClearColor(1.0, 1.0, 1.0, 0.0);
  
  /* initialize viewing values */
  glMatrixMode(GL_PROJECTION);//projection from eye point.
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);//defines viewing volumes.
}

void display(void)
{
  /* clear all pixels */
  glClear(GL_COLOR_BUFFER_BIT);

  /* draw a black polygon (rectangle) with corners at
   * (0.25, 0.25) and (0.75, 0.75)
   */

  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
    glVertex2f(0.25, 0.25);//shows where the vertexes for your objuct will show up in on the screen
    glVertex2f(0.75, 0.25);
    glVertex2f(0.75, 0.75);
    glVertex2f(0.25, 0.75);
  glEnd();

  /* don't wait.
   * start processing buffered OpenGL routines.
   */

  glFlush();
}

int main(int argc, char** argv)
{
  /*
   * Declare initial window size, position, and
   * display mode (single buffer and RGBA).
   * Open window with "hello" * in its title bar.
   * Call initialization routines.
   * Register callback function to display graphics.
   * Enter main loop and process events.
   */

  glutInit(&argc, argv); // initializes GLUT library and negotiates sessions with Windows system.
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(250, 250);// sets the size of window.
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Hello");
  init();//user defined
  glutDisplayFunc(display);//displays on screen what you want it to.
  glutMainLoop();//infinite loop that waits for events and returns 0 when done.
  return 0;
}

