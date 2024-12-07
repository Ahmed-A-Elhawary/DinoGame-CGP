#include<GL/freeglut.h>




void display(){

  glClearColor(1,1,1,1);
  glClear(GL_COLOR_BUFFER_BIT);

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
  glutCreateWindow("Dino Game - Step1");


  //set up callbacks
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);


  glutMainLoop();

  return 0;


}
