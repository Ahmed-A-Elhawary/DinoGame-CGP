# Dino Game - CGP
Dion game - CGP (computer graphic Project)
## Code
```cpp
#include <GL/freeglut.h>

// Function to display content on the window (currently blank)
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen
    glFlush(); // Ensure all OpenGL commands are executed
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                         // Initialize FreeGLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Set display mode (Single Buffer, RGB)
    glutInitWindowSize(800, 600);                  // Set the window size
    glutInitWindowPosition(100, 100);              // Set the window position on screen
    glutCreateWindow("My First FreeGLUT Window");  // Create the window with a title

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);          // Set background color (black)

    glutDisplayFunc(display);                      // Set the display callback function

    glutMainLoop();                                // Enter the GLUT event processing loop
    return 0;
}
```

---

## Explanation of Functions and Variables

### `#include <GL/freeglut.h>`

- **Purpose**: Includes the FreeGLUT library, which provides functions for creating and managing OpenGL windows and rendering graphics.

### `void display()`

- **Purpose**: A callback function to render the window's content. It is executed whenever the window needs to be redrawn.
- **Inside the Function**:
  - `glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)`: Clears the window. The color buffer is cleared to the background color, and the depth buffer is cleared for 3D rendering.
  - `glFlush()`: Ensures all OpenGL commands are executed immediately.

### `int main(int argc, char** argv)`

- **Purpose**: The entry point of the program where the FreeGLUT window is initialized and displayed.

#### `glutInit(&argc, argv)`
- **Purpose**: Initializes the FreeGLUT library.
- **Parameters**:
  - `argc` and `argv`: Command-line arguments passed to the program.

#### `glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)`
- **Purpose**: Sets the display mode of the window.
- **Parameters**:
  - `GLUT_SINGLE`: Indicates the use of a single-buffered window.
  - `GLUT_RGB`: Specifies the RGB color mode.

#### `glutInitWindowSize(800, 600)`
- **Purpose**: Sets the size of the window.
- **Parameters**:
  - `800`: Width of the window in pixels.
  - `600`: Height of the window in pixels.

#### `glutInitWindowPosition(100, 100)`
- **Purpose**: Sets the initial position of the window on the screen.
- **Parameters**:
  - `100`: Horizontal offset from the top-left corner of the screen.
  - `100`: Vertical offset from the top-left corner of the screen.

#### `glutCreateWindow("My First FreeGLUT Window")`
- **Purpose**: Creates the window with the specified title.
- **Parameters**:
  - `"My First FreeGLUT Window"`: Title of the window.

#### `glClearColor(0.0f, 0.0f, 0.0f, 1.0f)`
- **Purpose**: Sets the background color of the window.
- **Parameters**:
  - `0.0f, 0.0f, 0.0f`: RGB values for black.
  - `1.0f`: Alpha value for full opacity.

#### `glutDisplayFunc(display)`
- **Purpose**: Registers the `display` function as the callback for rendering the window's content.

#### `glutMainLoop()`
- **Purpose**: Starts the FreeGLUT event processing loop, keeping the window open and responsive.
- **Details**: This function never returns; it runs indefinitely to process window events.

---

## Summary of Workflow
1. **Initialization**: FreeGLUT is initialized with `glutInit` and the display mode, size, and position are set.
2. **Window Creation**: A window is created with `glutCreateWindow`.
3. **Rendering Setup**: The background color and display callback function are configured.
4. **Event Loop**: The program enters an event-processing loop with `glutMainLoop`, allowing the window to remain open and responsive.

---

Feel free to extend this program with additional features like drawing shapes, handling input, or adding animations!

