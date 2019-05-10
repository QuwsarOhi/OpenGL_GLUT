#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <GL/freeglut_std.h>
#include <GL/glut.h>
#include <GL/gl.h>
#define PI acos(-1)

// linux compile command: g++ main.c -lglut -lGL -lGLEW -lGLU && ./a.out

// Bizer curve used for drawing curved lines
// Depends on : maximum two control points / one control point
// Parameters : 
//   number of points : 3 or 4 
//   the point co-ordinates

void bizerCurve(int n, float point[][2]) {
   int coeff[10];
   --n;

   // Bizer Coeffecient Calculation
   for(int k = 0; k <= n; k++) {
      coeff[k] = 1;
      for(int i = n; i >= k+1; i--)
         coeff[k] *= i;
      for(int i = n-k; i >= 2; i--)
         coeff[k] /= i;

   }

   // Bizer Point Plotting
   glBegin(GL_LINE_STRIP);
      for(float u = 0; u < 1.0; u += 0.01) {
         float x = 0, y = 0;
         for(int k = 0; k < 4; k++) {
            float blend = coeff[k] * pow(u,k) * pow(1-u,n-k);
            x += point[k][0]*blend;
            y += point[k][1]*blend;
         }
         glVertex2f(x,y);
      }
   glEnd();
}

// Main Display Function
// Remove the commented blocks to see shapes/lines

void display() {

    // --- Default Values ----
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);


    // Modify Co-Ordinate System
    // left-most x, right-most x, lower-y, upper-y
    //gluOrtho2D(-100, 100, -100, 100);

    // Line Width Modifier
    // glLineWidth(5.0);        // Paremeter is the width of line

    /*
    // --- Drawing Lines ---
    // Color [RGB]
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
        // Line Plotting
        glVertex2f(0, 0), glVertex2f(0.5, 0.5);     // Line 1
        glVertex2f(0, 0), glVertex2f(0, 0.10);      // Line 2
        glVertex2f(0, 0), glVertex2f(-0.5, 0);      // Line 3
    glEnd();
    */
    


    /*
    // --- Drawing Polygon ----
    // Color [RGB]
    glColor3f(1.0, 0, 0);

    glBegin(GL_POLYGON);
        // Polygon Points Plotting ClockWise
        glVertex2f(0, 0);
        glVertex2f(0, 0.5);
        glVertex2f(0.25, 0.75);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, 0);
    glEnd();
    // --- End of Polygon ---
    */



    /*
    // --- Drawing Circle ---
    // Color [RGB]
    glColor3f(0, 1, 0);

    glBegin(GL_LINE_LOOP);                  // Can be Used with GL_POLYGON, GL_LINES, GL_LINE_LOOP
        float cx = 0, cy = 0, r = 0.1;      // circle origin(x, y) and radius
        int num_segments = 100;
        for(int ii = 0; ii < num_segments; ii++) {
            float theta = 2.0f * PI * float(ii) / float(num_segments);  //get the current angle
            float x = r * cosf(theta);      //calculate the x component
            float y = r * sinf(theta);      //calculate the y component
            glVertex2f(x + cx, y + cy);     //output vertex

        }
    glEnd();
    // --- End of Circle ---
    */


    /*
    //Curve Drawing
    
    float point[3][2] = {{-0.50, 0}, {0.0, 0.25}, {0.50, 0}};
    glColor3f(1, 0, 0);
    bizerCurve(3, point);
    */

    glFlush();
}


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);       // Window Size
    glutInitWindowPosition(10, 10);     // Window Default Position
    glutCreateWindow("Title Window");   // Window Title
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
