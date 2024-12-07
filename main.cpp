#include<GL/freeglut.h>
#include<iostream>
using namespace std;


// Global variables for dino's position and jump state
float dinoY = 100.0f;
float velocity = 0.0f;
bool isJumping =false;
float windowWidth = 800.0f;
float windowHeight = 600.0f;

// obstacle variables
float obstacleX      = windowWidth;
float obstacleWidth  = 30.0f;
float obstacleHeight = 50.0f;
float obstacleSpeed  = 5.0f;

void drawGround(){

  glColor3f(0.0,0.8,0.0);
  glBegin(GL_QUADS);
    glVertex2f(0.0,50.0);             // bottom-left corner
    glVertex2f(windowWidth, 50.0);    // bottom-right corner
    glVertex2f(windowWidth, 0.0);     // top-right corner
    glVertex2f(0.0, 0.0);             // top-left corner
  glEnd();

}
void drawDino(){

  glColor3f(0.8,0.3,0.0);
  glBegin(GL_QUADS);
    glVertex2f(100.0f, dinoY + 50.0f);
    glVertex2f(130.0f, dinoY + 50.0f);
    glVertex2f(130.0f, dinoY);
    glVertex2f(100.0f, dinoY);
  glEnd();

}


void keyboard(unsigned char key, int x,int y){

  if(key == 32 && !isJumping){
    isJumping = true;
    velocity = 10.0f;
  }

}

void update(int value){

  if(isJumping){

    velocity -= 0.5f;

    dinoY += velocity;

    cout<<dinoY<<velocity<<endl;

    if(dinoY <= 100.0f){
      dinoY = 100.0f;
      isJumping = false;
      velocity = 0.0f;
    }
  }

  glutPostRedisplay();
  glutTimerFunc(16, update, 0);
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

  windowWidth  = wigth;
  windowHeight = height;

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
  glutKeyboardFunc(keyboard);
  glutTimerFunc(25, update, 0);


  glutMainLoop();

  return 0;


}
