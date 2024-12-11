#include <GL/freeglut.h>
#include <iostream>
using namespace std;

// Global variables for dino's position and jump state
float dinoY = 100.0f;
float velocity = 0.0f;
bool isJumping = false;
bool gameOver = false; // To track the game state
float windowWidth = 800.0f;
float windowHeight = 600.0f;

// Obstacle variables
float obstacleX = windowWidth;
float obstacleWidth = 30.0f;
float obstacleHeight = 50.0f;
float obstacleSpeed = 5.0f;

void drawGround() {
    glColor3f(0.0, 0.8, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 100.0);            // bottom-left corner
    glVertex2f(windowWidth, 100.0);    // bottom-right corner
    glVertex2f(windowWidth, 0.0);      // top-right corner
    glVertex2f(0.0, 0.0);              // top-left corner
    glEnd();
}

void drawDino() {
    glColor3f(0.8, 0.3, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(100.0f, dinoY + 50.0f);
    glVertex2f(130.0f, dinoY + 50.0f);
    glVertex2f(130.0f, dinoY);
    glVertex2f(100.0f, dinoY);
    glEnd();
}

void drawObstacle() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(obstacleX, 100.0f);                  // Bottom-left
    glVertex2f(obstacleX + obstacleWidth, 100.0f); // Bottom-right
    glVertex2f(obstacleX + obstacleWidth, 100.0f + obstacleHeight); // Top-right
    glVertex2f(obstacleX, 100.0f + obstacleHeight);                 // Top-left
    glEnd();
}

void drawGameOver() {
    glColor3f(1, 0, 0); // Red color
    glRasterPos2f(windowWidth / 2 - 50, windowHeight / 2); // Center the message
    const char* message = "GAME OVER!";
    for (const char* c = message; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    glRasterPos2f(windowWidth / 2 - 100, windowHeight / 2 - 30); // Restart message
    const char* restart = "Press SPACE to play again!";
    for (const char* c = restart; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 32) { // Space bar
        if (!isJumping && !gameOver) { // Jump if not game over
            isJumping = true;
            velocity = 10.0f;
        } else if (gameOver) { // Restart game
            gameOver = false;
            dinoY = 100.0f;
            obstacleX = windowWidth;
            velocity = 0.0f;
            isJumping = false;
        }
    }
}

void update(int value) {
    if (!gameOver) {
        // Dino jumping logic
        if (isJumping) {
            velocity -= 0.5f;
            dinoY += velocity;

            if (dinoY <= 100.0f) { // Ground level
                dinoY = 100.0f;
                isJumping = false;
                velocity = 0.0f;
            }
        }

        // Obstacle movement
        obstacleX -= obstacleSpeed;

        // Reset obstacle if it moves off-screen
        if (obstacleX + obstacleWidth < 0) {
            obstacleX = windowWidth;
        }

        // Collision detection
        if (obstacleX < 130.0f && obstacleX + obstacleWidth > 100.0f &&
            dinoY < 100.0f + obstacleHeight) {
            gameOver = true; // Stop the game
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    if (!gameOver) {
        drawGround();
        drawDino();
        drawObstacle();
    } else {
        drawGameOver();
    }

    glutSwapBuffers();
}

void reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, 0.0, height);
}

int main(int argc, char** argv) {
    // Initialize FreeGLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Create a window
    glutInitWindowSize(800, 600);
    glutCreateWindow("Dino Game");

    // Set up callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
