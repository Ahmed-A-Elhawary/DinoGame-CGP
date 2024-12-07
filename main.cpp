#include<GL/freeglut.h>

void drawGround(){

  glColor3f(0.0,0.8,0.0);
  glBegin(GL_QUADS);
    glVertex2f(0.0,50.0);
    glVertex2f(800.0, 50.0);
    glVertex2f(800.0, 0.0);
    glVertex2f(0.0, 0.0);
  glEnd();

}
void drawDino(){

  glColor3f(0.8,0.3,0.0);
  glBegin(GL_QUADS);
    glVertex2f(100.0f, 150.0f);
    glVertex2f(130.0f, 150.0f);
    glVertex2f(130.0f, 100.0f);
    glVertex2f(100.0f, 100.0f);
  glEnd();

}

void display(){

  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT);

  //Draw the ground and the dino
  drawGround();
  drawDino();

  glutSwapBuffers();

}

void reshape(int wigth, int height){

  glViewport(0,0,wigth,height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,wigth,0.0,height);

}

int main(int argc, char** argv){

  //initialize FreeGLUT
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

  // Create a window
  glutInitWindowSize(800,600);
  glutCreateWindow("Dino Game");


  //set up callbacks
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);


  glutMainLoop();

  return 0;


}
