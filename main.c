//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ti/grlib/grlib.h>  // Need to include this in order to use Graphics functions!
////#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
//#include "LcdDriver/Crystalfontz128x128_ST7735.h"  // Need these drivers to use the LCD!
//
////#define BUTTON1 0b00000010
//
//
//void initializeGraphics(Graphics_Context *g_sContext_p);
//void addEdge(int vertexIndex1, int vertexIndex2);
//void printEdge(int index);
//void printEdges();
//void getProjectedVertices();
//void drawWireframe();
////void initializeInputs();
//
//int vertexCount = 8;
//int vertexTable[8][3] = {
//    {24, 24, 0},  // Vertex 0
//    {104, 24, 0}, // Vertex 1
//    {104, 104, 0}, // Vertex 2
//    {24, 104, 0}, // Vertex 3
//    {24, 24, 40}, // Vertex 4
//    {104, 24, 40}, // Vertex 5
//    {104, 104, 40}, // Vertex 6
//    {24, 104, 40}  // Vertex 7
//};
////signed int vertexTable[16][3] = {
////        {1, 2, 3},   // Vertex 1
////        {4, 5, 6},   // Vertex 2
////        {7, 8, 9},   // Vertex 3
////        {10, 11, 12},   // Vertex 4
////        {0, 0, 0},   // Vertex 5
////        {0, 0, 0},   // Vertex 6
////        {0, 0, 0},   // Vertex 7
////        {0, 0, 0},   // Vertex 8
////        {0, 0, 0},   // Vertex 9
////        {0, 0, 0},   // Vertex 10
////        {0, 0, 0},   // Vertex 11
////        {0, 0, 0},   // Vertex 12
////        {0, 0, 0},   // Vertex 13
////        {0, 0, 0},   // Vertex 14
////        {0, 0, 0},   // Vertex 15
////        {0, 0, 0}    // Vertex 16
////};
//
//typedef struct {
//        int *p_vertex1;
//        int *p_vertex2;
//} Edge;
//
//Edge* edgeTable = NULL;
//int edgeCount = 0;
//
//signed int projectedVertexTable[16][2] = {0};
//int focalLength = 10;
//
//
///**
// * main.c
// */
//int main(void) {
//
//    addEdge(0, 1); // Edge between Vertex 0 and Vertex 1
//    addEdge(1, 2); // Edge between Vertex 1 and Vertex 2
//    addEdge(2, 3); // Edge between Vertex 2 and Vertex 3
//    addEdge(3, 0); // Edge between Vertex 3 and Vertex 0
//    addEdge(4, 5); // Edge between Vertex 4 and Vertex 5
//    addEdge(5, 6); // Edge between Vertex 5 and Vertex 6
//    addEdge(6, 7); // Edge between Vertex 6 and Vertex 7
//    addEdge(7, 4); // Edge between Vertex 7 and Vertex 4
//    addEdge(0, 4); // Vertical Edge between Vertex 0 and Vertex 4
//    addEdge(1, 5); // Vertical Edge between Vertex 1 and Vertex 5
//    addEdge(2, 6); // Vertical Edge between Vertex 2 and Vertex 6
//    addEdge(3, 7); // Vertical Edge between Vertex 3 and Vertex 7
//
//
//    getProjectedVertices();
//    printEdges();
//
////    initializeInputs();
//
////    while(1) {
////        if ((P1IN & BUTTON1) == 0) {
////            focalLength += 10;
////            getProjectedVertices();
////            drawWireframe();
////        }
//////        if ((P1IN & BIT4) == 1) {
//////            focalLength -=10;
//////            getProjectedVertices();
//////            drawWireframe();
//////        }
////
////    }
//    drawWireframe();
////
////
////    printEdges();
////
////    free(edgeTable);
//
//    return 0;
//
//
//}
//
//
///**
// *  Function Declarations
// */
//void initializeGraphics(Graphics_Context *g_sContext_p) {
//    // Initialize the LCD
//    Crystalfontz128x128_Init();
//    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);
//
//    // Initialize context
//    Graphics_initContext(g_sContext_p, &g_sCrystalfontz128x128,
//                       &g_sCrystalfontz128x128_funcs);
//
//    // Set colors and fonts
//    Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
//    Graphics_setBackgroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
//    Graphics_setFont(g_sContext_p, &g_sFontFixed6x8);
//
//    // Clear the screen
//    Graphics_clearDisplay(g_sContext_p);
//}
//
//void addEdge(int vertexIndex1, int vertexIndex2) {
//    // Reallocate memory to store new edge
//    edgeTable = realloc (edgeTable, (edgeCount + 1) * sizeof(Edge));
//
//    // Check for successful allocation
//    if (edgeTable == NULL) {
//        printf("edgeTable memory allocation failed!\n");
//        exit(1);
//    }
//
//    // Add new edge w/ address of vertices
//    edgeTable[edgeCount].p_vertex1 = &vertexTable[vertexIndex1][0];
//    edgeTable[edgeCount].p_vertex2 = &vertexTable[vertexIndex2][0];
//
//    edgeCount++;
//}
//
//void printEdge(int index) {
//    printf("Edge %d: Vertex 1 at (%d, %d, %d), Vertex 2 at (%d, %d, %d)\n",
//           index + 1,
//           edgeTable[index].p_vertex1[0], edgeTable[index].p_vertex1[1], edgeTable[index].p_vertex1[2],
//           edgeTable[index].p_vertex2[0], edgeTable[index].p_vertex2[1], edgeTable[index].p_vertex2[2]);
//}
//
//void printEdges() {
//    int i = 0;
//    for (i = 0; i < edgeCount; i++) {
//        printEdge(i);
//    }
//}
//
//void getProjectedVertices() {
//    int xProj, yProj, vertex;
//    for (vertex = 0; vertex < vertexCount; vertex++) {
//        // Calculate projected 2D coords
//        xProj = (focalLength * vertexTable[vertex][0]) / (focalLength + vertexTable[vertex][2]);
//        yProj = (focalLength * vertexTable[vertex][1]) / (focalLength + vertexTable[vertex][2]);
//
//        // Set vertex to projected coords
//        vertexTable[vertex][0] = xProj;
//        vertexTable[vertex][1] = yProj;
//    }
//}
//
//void drawWireframe() {
//    int i;
//    // Initializes LCD
//    Graphics_Context g_sContext; // Creates context
//    initializeGraphics(&g_sContext);
//
//    for(i = 0; i < edgeCount; i++) {
//        Graphics_drawLine(&g_sContext, edgeTable[i].p_vertex1[0], edgeTable[i].p_vertex1[1], edgeTable[i].p_vertex2[0], edgeTable[i].p_vertex2[1]);
//    }
//}
//
////void initializeInputs() {
//    // Stop watchdog timer
////    WDT_A_hold(WDT_A_BASE);
//
//    // step 3: Initializing S1 (ACTIVE LOW)
////    P1DIR = P1DIR & ~BUTTON1; // set button pin as input
////    P1REN |= BUTTON1; // enable pull-up/pull-down resistor for pin
////    P1OUT |= BUTTON1; // controls resistor behavior (1 pull-up to Vcc; 0 pull-down to GND)
//
//
////    // S2 is connected to P1.4
////    // Therefore, bit 4 of P1DIR register should be reset to 0
////    P1DIR = P1DIR & ~BIT4;
////    // To enable the pull resistor we should set the bit 4 of P1REN to 1
////    P1REN = P1REN | BIT4;
////    // To make the pull resistor a pull-up, we need to set the bit 4 of P1OUT to 1
////    P1OUT = P1OUT | BIT4;
////    // To read the status of S2, we need to check bit 4 of P1IN
////    // masking all other bits leaves a value that it is either zero, or non-zero.
////}
////
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ti/grlib/grlib.h>  // Need to include this in order to use Graphics functions!
//#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "LcdDriver/Crystalfontz128x128_ST7735.h"  // Need these drivers to use the LCD!
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <math.h>

#define TIMER_FREQUENCY 3000000  // Assume SMCLK at 3MHz
#define TIMER_LOAD_VALUE (TIMER_FREQUENCY / 48)  // 2-second delay
//#define BUTTON1 0b00000010


//void initializeGraphics(Graphics_Context *g_sContext_p); //single buffer render
void initializeGraphics(Graphics_Context *g_sContext_p);
void addEdge(int vertexIndex1, int vertexIndex2);
void printEdge(int index);
void printEdges();
void getProjectedVertices();
void drawWireframe(Graphics_Context *g_sContext_p, bool eraseOld);
void Timer32_2SecondDelay();
void swapBuffers();
void createRotationMatrixZ(float matrix[3][3], float theta);
void rotateVertexTable(rotationMatrix, vertexTable);
void rotateCubeZ(float theta);
//void initializeInputs();

const int vertexCount = 8;
float projectedVertices[vertexCount][2];
float previousProjectedVertexTable[vertexCount][2] = {0};
float vertexTable[8][3] = {
    {24, 24, 0},  // Vertex 0
    {104, 24, 0}, // Vertex 1
    {104, 104, 0}, // Vertex 2
    {24, 104, 0}, // Vertex 3
    {24, 24, 40}, // Vertex 4
    {104, 24, 40}, // Vertex 5
    {104, 104, 40}, // Vertex 6
    {24, 104, 40}  // Vertex 7
};
//signed int vertexTable[16][3] = {
//        {1, 2, 3},   // Vertex 1
//        {4, 5, 6},   // Vertex 2
//        {7, 8, 9},   // Vertex 3
//        {10, 11, 12},   // Vertex 4
//        {0, 0, 0},   // Vertex 5
//        {0, 0, 0},   // Vertex 6
//        {0, 0, 0},   // Vertex 7
//        {0, 0, 0},   // Vertex 8
//        {0, 0, 0},   // Vertex 9
//        {0, 0, 0},   // Vertex 10
//        {0, 0, 0},   // Vertex 11
//        {0, 0, 0},   // Vertex 12
//        {0, 0, 0},   // Vertex 13
//        {0, 0, 0},   // Vertex 14
//        {0, 0, 0},   // Vertex 15
//        {0, 0, 0}    // Vertex 16
//};

typedef struct {
        int *p_vertex1;
        int *p_vertex2;
} Edge;

Edge* edgeTable = NULL;
int edgeCount = 0;

float projectedVertexTable[16][2] = {0};
int focalLength = 150;




Graphics_Context buffer1, buffer2; // Two buffers for double buffering
Graphics_Context *g_sCurrentContext = &buffer1; // Initially use buffer1
Graphics_Context *g_sNextContext = &buffer2; // Use buffer2 as next buffer

// Initialize both graphics contexts correctly
     // Pass the pointer to buffer2

/**
 * main.c
 */
int main(void) {
    float rotationMatrix[3][3];
    float theta = M_PI / 4;  // 45 degrees in radians
    createRotationMatrixZ(rotationMatrix, theta);
//    // Initializes LCD
//    Graphics_Context g_sContext; // Creates context
    initializeGraphics(g_sCurrentContext);  // Pass the pointer to buffer1
    initializeGraphics(g_sNextContext);

    addEdge(0, 1); // Edge between Vertex 0 and Vertex 1
    addEdge(1, 2); // Edge between Vertex 1 and Vertex 2
    addEdge(2, 3); // Edge between Vertex 2 and Vertex 3
    addEdge(3, 0); // Edge between Vertex 3 and Vertex 0
    addEdge(4, 5); // Edge between Vertex 4 and Vertex 5
    addEdge(5, 6); // Edge between Vertex 5 and Vertex 6
    addEdge(6, 7); // Edge between Vertex 6 and Vertex 7
    addEdge(7, 4); // Edge between Vertex 7 and Vertex 4
    addEdge(0, 4); // Vertical Edge between Vertex 0 and Vertex 4
    addEdge(1, 5); // Vertical Edge between Vertex 1 and Vertex 5
    addEdge(2, 6); // Vertical Edge between Vertex 2 and Vertex 6
    addEdge(3, 7); // Vertical Edge between Vertex 3 and Vertex 7

    unsigned char string2[25] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                               1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    getProjectedVertices();

    printEdges();

    while (1) {
        // Get the projected vertices
        drawWireframe(g_sNextContext, true);
        getProjectedVertices();
        // Draw the old wireframe in black to erase it
        drawWireframe(g_sNextContext, false);




        // Swap the buffers
        swapBuffers();

        // Update the display string (optional)
        snprintf((char *)string2, 25, "focalLength: %d", focalLength);
        Graphics_drawString(g_sCurrentContext, (int8_t *)string2, -1, 5, 0, true);

        // Wait for the timer
//        Timer32_2SecondDelay();


        // Create the rotation matrix for rotation around the Z-axis

        // Rotate the vertex table
//        rotateVertexTable(rotationMatrix, vertexTable);
//         rotateCubeZ(M_PI / 30);
        rotateAroundYX((&vertexTable), M_PI / 30);
//        rotateAroundYX(vertexTable, M_PI / 6);
//        focalLength += 10;
    }

//    while (1) {
//        // Get the projected vertices and draw the wireframe
//        getProjectedVertices();
//        // Don't clear the current display, just clear the next context
//        swapBuffers();
//
//        // Draw the wireframe to the next context
//        drawWireframe(g_sNextContext);
//        // Swap the buffers
//
//        // Update the display string (optional)
//        snprintf((char *)string2, 25, "focalLength: %d", focalLength);
//        Graphics_drawString(g_sCurrentContext, (int8_t *)string2, -1, 5, 0, true);
//        // Wait for the timer
//        Timer32_2SecondDelay();
//        // Adjust the focal length
//        focalLength += 10;
//    }
//    while(1) {
//        getProjectedVertices();
//        Graphics_clearDisplay(g_sNextContext);
//        drawWireframe(g_sNextContext);
//        swapBuffers();
//        snprintf((char *)string2, 25, "focalLength: %d", focalLength);
//        Graphics_drawString(g_sCurrentContext, (int8_t *)string2, -1, 5, 0, true);
//        Timer32_2SecondDelay(); // Delay for 2 seconds
//        focalLength += 10; // Adjust focal length
//    }


//    while(1) { // single buffer render
//        getProjectedVertices();
//        Graphics_clearDisplay(&g_sContext);
//        drawWireframe(&g_sContext);
//        snprintf((char *)string2, 25, "focalLength: %d", focalLength);
//        Graphics_drawString(&g_sContext, (int8_t *)string2, -1, 5, 0, true);
//        Timer32_2SecondDelay();
//        focalLength += 10;
//    }


//    initializeInputs();

//    while(1) {
//        if ((P1IN & BUTTON1) == 0) {
//            focalLength += 10;
//            getProjectedVertices();
//            drawWireframe();
//        }
////        if ((P1IN & BIT4) == 1) {
////            focalLength -=10;
////            getProjectedVertices();
////            drawWireframe();
////        }
//
//    }

//
//
//    printEdges();
//
//    free(edgeTable);

    return 0;


}



//void rotateAroundYX(int (*vertexTable)[3], float theta) {
//    // Rotation matrix for rotating around Y=X
//    float R1[3][3] = {
//        {cosf(M_PI / 4), -sinf(M_PI / 4), 0},
//        {sinf(M_PI / 4), cosf(M_PI / 4), 0},
//        {0, 0, 1}
//    };
//
//    // Inverse of the rotation matrix
//    float R1_inv[3][3] = {
//        {cosf(M_PI / 4), sinf(M_PI / 4), 0},
//        {-sinf(M_PI / 4), cosf(M_PI / 4), 0},
//        {0, 0, 1}
//    };
//
//    // Rotation matrix around the X-axis
//    float Rx[3][3] = {
//        {1, 0, 0},
//        {0, cosf(theta), -sinf(theta)},
//        {0, sinf(theta), cosf(theta)}
//    };
//
//    int i;
//    signed int newVertex[3];
//
//    // Loop through each vertex and apply the rotations
//    for (i = 0; i < vertexCount; i++) {
//        // Multiply R1_inv * vertex
//        newVertex[0] = R1_inv[0][0] * vertexTable[i][0] + R1_inv[0][1] * vertexTable[i][1] + R1_inv[0][2] * vertexTable[i][2];
//        newVertex[1] = R1_inv[1][0] * vertexTable[i][0] + R1_inv[1][1] * vertexTable[i][1] + R1_inv[1][2] * vertexTable[i][2];
//        newVertex[2] = R1_inv[2][0] * vertexTable[i][0] + R1_inv[2][1] * vertexTable[i][1] + R1_inv[2][2] * vertexTable[i][2];
//
//        // Apply the rotation around the X-axis (Rx)
//        signed int rotatedVertex[3];
//        rotatedVertex[0] = Rx[0][0] * newVertex[0] + Rx[0][1] * newVertex[1] + Rx[0][2] * newVertex[2];
//        rotatedVertex[1] = Rx[1][0] * newVertex[0] + Rx[1][1] * newVertex[1] + Rx[1][2] * newVertex[2];
//        rotatedVertex[2] = Rx[2][0] * newVertex[0] + Rx[2][1] * newVertex[1] + Rx[2][2] * newVertex[2];
//
//        // Multiply by R1 to complete the transformation
//        vertexTable[i][0] = R1[0][0] * rotatedVertex[0] + R1[0][1] * rotatedVertex[1] + R1[0][2] * rotatedVertex[2];
//        vertexTable[i][1] = R1[1][0] * rotatedVertex[0] + R1[1][1] * rotatedVertex[1] + R1[1][2] * rotatedVertex[2];
//        vertexTable[i][2] = R1[2][0] * rotatedVertex[0] + R1[2][1] * rotatedVertex[1] + R1[2][2] * rotatedVertex[2];
//    }
//}
void calculateCenter(float (*vertexTable)[3], int *center) {
    int i;
    center[0] = 0;
    center[1] = 0;
    center[2] = 0;

    for (i = 0; i < vertexCount; i++) {
        center[0] += vertexTable[i][0];
        center[1] += vertexTable[i][1];
        center[2] += vertexTable[i][2];
    }

    // Compute the average (center)
    center[0] /= vertexCount;
    center[1] /= vertexCount;
    center[2] /= vertexCount;
}

// Rotate function with translation to the center
void rotateAroundYX(float (*vertexTable)[3], float theta) {
    // Rotation matrix for rotating around Y=X
    float R1[3][3] = {
        {cosf(M_PI / 4), -sinf(M_PI / 4), 0},
        {sinf(M_PI / 4), cosf(M_PI / 4), 0},
        {0, 0, 1}
    };

    // Inverse of the rotation matrix
    float R1_inv[3][3] = {
        {cosf(M_PI / 4), sinf(M_PI / 4), 0},
        {-sinf(M_PI / 4), cosf(M_PI / 4), 0},
        {0, 0, 1}
    };

    // Rotation matrix around the X-axis
    float Rx[3][3] = {
        {1, 0, 0},
        {0, cosf(theta), -sinf(theta)},
        {0, sinf(theta), cosf(theta)}
    };

    // Find the center of the object
    int center[3];
    calculateCenter(vertexTable, center);

    int i;
    float newVertex[3];

    // Loop through each vertex
    for (i = 0; i < vertexCount; i++) {
        // Translate vertex to the origin (by subtracting the center)
        float tempVertex[3] = {
            vertexTable[i][0] - center[0],
            vertexTable[i][1] - center[1],
            vertexTable[i][2] - center[2]
        };

        // Multiply R1_inv * vertex (rotation step 1)
        newVertex[0] = R1_inv[0][0] * tempVertex[0] + R1_inv[0][1] * tempVertex[1] + R1_inv[0][2] * tempVertex[2];
        newVertex[1] = R1_inv[1][0] * tempVertex[0] + R1_inv[1][1] * tempVertex[1] + R1_inv[1][2] * tempVertex[2];
        newVertex[2] = R1_inv[2][0] * tempVertex[0] + R1_inv[2][1] * tempVertex[1] + R1_inv[2][2] * tempVertex[2];

        // Apply the rotation around the X-axis (Rx)
        signed int rotatedVertex[3];
        rotatedVertex[0] = Rx[0][0] * newVertex[0] + Rx[0][1] * newVertex[1] + Rx[0][2] * newVertex[2];
        rotatedVertex[1] = Rx[1][0] * newVertex[0] + Rx[1][1] * newVertex[1] + Rx[1][2] * newVertex[2];
        rotatedVertex[2] = Rx[2][0] * newVertex[0] + Rx[2][1] * newVertex[1] + Rx[2][2] * newVertex[2];

        // Multiply by R1 to complete the transformation
        vertexTable[i][0] = R1[0][0] * rotatedVertex[0] + R1[0][1] * rotatedVertex[1] + R1[0][2] * rotatedVertex[2];
        vertexTable[i][1] = R1[1][0] * rotatedVertex[0] + R1[1][1] * rotatedVertex[1] + R1[1][2] * rotatedVertex[2];
        vertexTable[i][2] = R1[2][0] * rotatedVertex[0] + R1[2][1] * rotatedVertex[1] + R1[2][2] * rotatedVertex[2];

        // Translate the vertex back by adding the center coordinates
        vertexTable[i][0] += center[0];
        vertexTable[i][1] += center[1];
        vertexTable[i][2] += center[2];
    }
}


/**
 *  Function Declarations
 */
//void initializeGraphics(Graphics_Context *g_sContext_p) {
//    // Initialize the LCD
//    Crystalfontz128x128_Init();
//    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);
//
//    // Initialize context
//    Graphics_initContext(g_sContext_p, &g_sCrystalfontz128x128,
//                       &g_sCrystalfontz128x128_funcs);
//
//    // Set colors and fonts
//    Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
//    Graphics_setBackgroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
//    Graphics_setFont(g_sContext_p, &g_sFontFixed6x8);
//
//    // Clear the screen
//    Graphics_clearDisplay(g_sContext_p);
//}

void addEdge(int vertexIndex1, int vertexIndex2) {
    // Reallocate memory to store new edge
    edgeTable = realloc (edgeTable, (edgeCount + 1) * sizeof(Edge));

    // Check for successful allocation
    if (edgeTable == NULL) {
        printf("edgeTable memory allocation failed!\n");
        exit(1);
    }

    // Add new edge w/ address of vertices
    edgeTable[edgeCount].p_vertex1 = &vertexTable[vertexIndex1][0];
    edgeTable[edgeCount].p_vertex2 = &vertexTable[vertexIndex2][0];

    edgeCount++;
}

void printEdge(int index) {
    printf("Edge %d: Vertex 1 at (%d, %d, %d), Vertex 2 at (%d, %d, %d)\n",
           index + 1,
           edgeTable[index].p_vertex1[0], edgeTable[index].p_vertex1[1], edgeTable[index].p_vertex1[2],
           edgeTable[index].p_vertex2[0], edgeTable[index].p_vertex2[1], edgeTable[index].p_vertex2[2]);
}

void printEdges() {
    int i = 0;
    for (i = 0; i < edgeCount; i++) {
        printEdge(i);
    }
}

//void getProjectedVertices() {
//    // Copy current projected vertices to previous buffer
//    memcpy(previousProjectedVertexTable, projectedVertices, sizeof(projectedVertices));
//
//    int xProj, yProj, vertex;
//    for (vertex = 0; vertex < vertexCount; vertex++) {
//        // Calculate new projected 2D coords
//        xProj = (focalLength * vertexTable[vertex][0]) / (focalLength + vertexTable[vertex][2]);
//        yProj = (focalLength * vertexTable[vertex][1]) / (focalLength + vertexTable[vertex][2]);
//
//        // Set current projected vertex to the new values
//        projectedVertices[vertex][0] = xProj;
//        projectedVertices[vertex][1] = yProj;
//    }
//}

void getProjectedVertices() {
    int xProj, yProj, vertex;
    for (vertex = 0; vertex < vertexCount; vertex++) {
        // Calculate projected 2D coords
        xProj = (focalLength * vertexTable[vertex][0]) / (focalLength + vertexTable[vertex][2]);
        yProj = (focalLength * vertexTable[vertex][1]) / (focalLength + vertexTable[vertex][2]);

        // Set vertex to projected coords
        projectedVertices[vertex][0] = xProj;
        projectedVertices[vertex][1] = yProj;
    }
}

//void drawWireframe(Graphics_Context *g_sContext_p) { // Modified original vertexTable
//    int i;
//    for(i = 0; i < edgeCount; i++) {
//        int v1 = edgeTable[i].p_vertex1;
//        int v2 = edgeTable[i].p_vertex2;
//        Graphics_drawLine(g_sContext_p,projectedVertices[i][], projectedVertices[i][edgeTable[i].p_vertex1[1]], projectedVertices[i][edgeTable[i].p_vertex2[0]], projectedVertices[i][edgeTable[i].p_vertex2[1]]);
//    }
//}
//void drawWireframe(Graphics_Context *g_sContext_p) { // single buffer render
//    int i, v1Index, v2Index;
//
//    for (i = 0; i < edgeCount; i++) {
//        // Find the indices of the two vertices in vertexTable
//        for (v1Index = 0; v1Index < vertexCount; v1Index++) {
//            if (edgeTable[i].p_vertex1 == vertexTable[v1Index]) break;
//        }
//        for (v2Index = 0; v2Index < vertexCount; v2Index++) {
//            if (edgeTable[i].p_vertex2 == vertexTable[v2Index]) break;
//        }
//
//        // Draw the edge using projected 2D coordinates
//        Graphics_drawLine(g_sContext_p,
//            projectedVertices[v1Index][0], projectedVertices[v1Index][1],
//            projectedVertices[v2Index][0], projectedVertices[v2Index][1]);
//    }
//}

void Timer32_2SecondDelay() {
    // Step 1: Initialize Timer32 (TIMER32_0) in periodic mode
    Timer32_initModule(TIMER32_0_BASE,
                       TIMER32_PRESCALER_1,
                       TIMER32_32BIT,
                       TIMER32_PERIODIC_MODE);

    // Step 2: Set timer count for 2 seconds
    Timer32_setCount(TIMER32_0_BASE, TIMER_LOAD_VALUE);

    // Step 3: Start the timer (not in one-shot mode)
    Timer32_startTimer(TIMER32_0_BASE, false);

    // Step 4: Wait until the timer counts down to zero
    while (Timer32_getValue(TIMER32_0_BASE) > 0);

    // Timer has expired after 2 seconds
}


/**
 * Dual-Buffer Render Functions
 */
void initializeGraphics(Graphics_Context *g_sContext_p) {
    // Initialize the LCD
    Crystalfontz128x128_Init();
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    // Initialize both buffers
    Graphics_initContext(&buffer1, &g_sCrystalfontz128x128, &g_sCrystalfontz128x128_funcs);
    Graphics_initContext(&buffer2, &g_sCrystalfontz128x128, &g_sCrystalfontz128x128_funcs);

    // Set colors and fonts for both buffers
    Graphics_setForegroundColor(&buffer1, GRAPHICS_COLOR_WHITE);
    Graphics_setBackgroundColor(&buffer1, GRAPHICS_COLOR_BLACK);
    Graphics_setFont(&buffer1, &g_sFontFixed6x8);
    Graphics_clearDisplay(&buffer1); // Clear buffer1 initially

    Graphics_setForegroundColor(&buffer2, GRAPHICS_COLOR_WHITE);
    Graphics_setBackgroundColor(&buffer2, GRAPHICS_COLOR_BLACK);
    Graphics_setFont(&buffer2, &g_sFontFixed6x8);
    Graphics_clearDisplay(&buffer2); // Clear buffer2 initially
}

//void drawWireframe(Graphics_Context *g_sContext_p) {
//    int i, v1Index, v2Index;
//
//    for (i = 0; i < edgeCount; i++) {
//        // Find the indices of the two vertices in vertexTable
//        for (v1Index = 0; v1Index < vertexCount; v1Index++) {
//            if (edgeTable[i].p_vertex1 == vertexTable[v1Index]) break;
//        }
//        for (v2Index = 0; v2Index < vertexCount; v2Index++) {
//            if (edgeTable[i].p_vertex2 == vertexTable[v2Index]) break;
//        }
//
//        // Draw the edge using projected 2D coordinates
//        Graphics_drawLine(g_sNextContext,
//            projectedVertices[v1Index][0], projectedVertices[v1Index][1],
//            projectedVertices[v2Index][0], projectedVertices[v2Index][1]);
//    }
//}
void drawWireframe(Graphics_Context *g_sContext_p, bool eraseOld) {
    int i, v1Index, v2Index;

    for (i = 0; i < edgeCount; i++) {
        // Find the indices of the two vertices in vertexTable
        for (v1Index = 0; v1Index < vertexCount; v1Index++) {
            if (edgeTable[i].p_vertex1 == vertexTable[v1Index]) break;
        }
        for (v2Index = 0; v2Index < vertexCount; v2Index++) {
            if (edgeTable[i].p_vertex2 == vertexTable[v2Index]) break;
        }

        // If we are erasing the old frame, draw in black (background color)
        if (eraseOld) {
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
        } else {
            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
        }

        // Draw the edge using projected 2D coordinates
        Graphics_drawLine(g_sContext_p,
            (int) projectedVertices[v1Index][0], (int)projectedVertices[v1Index][1],
            (int) projectedVertices[v2Index][0], (int)projectedVertices[v2Index][1]);
    }
}
//void drawWireframe(Graphics_Context *g_sContext_p, bool eraseOld) { //erase previous wirefram not current
//    int i, v1Index, v2Index;
//
//    for (i = 0; i < edgeCount; i++) {
//        // Find the indices of the two vertices in the vertexTable
//        for (v1Index = 0; v1Index < vertexCount; v1Index++) {
//            if (edgeTable[i].p_vertex1 == vertexTable[v1Index]) break;
//        }
//        for (v2Index = 0; v2Index < vertexCount; v2Index++) {
//            if (edgeTable[i].p_vertex2 == vertexTable[v2Index]) break;
//        }
//
//        // If we are erasing the old frame, use previous projected vertices
//        if (eraseOld) {
//            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_BLACK);
//            Graphics_drawLine(g_sContext_p,
//                previousProjectedVertexTable[v1Index][0], previousProjectedVertexTable[v1Index][1],
//                previousProjectedVertexTable[v2Index][0], previousProjectedVertexTable[v2Index][1]);
//        } else {
//            Graphics_setForegroundColor(g_sContext_p, GRAPHICS_COLOR_WHITE);
//            Graphics_drawLine(g_sContext_p,
//                projectedVertices[v1Index][0], projectedVertices[v1Index][1],
//                projectedVertices[v2Index][0], projectedVertices[v2Index][1]);
//        }
//    }
//}


void swapBuffers() {
    // Swap the buffers
//    Graphics_clearDisplay(g_sNextContext);
    Graphics_Context *temp = g_sCurrentContext;
    g_sCurrentContext = g_sNextContext;
    g_sNextContext = temp;

    // Clear the next buffer (the one that will be displayed next)
//    Graphics_clearDisplay(g_sNextContext);
}

// Function to rotate the cube around its own origin
void rotateCubeZ(float theta) {
    int center[3], i;
    calculateCenter(vertexTable, center);

    // Translate cube to the origin (subtract center)
    for (i = 0; i < vertexCount; i++) {
        vertexTable[i][0] -= center[0];
        vertexTable[i][1] -= center[1];
        vertexTable[i][2] -= center[2];
    }

    // Create the rotation matrix for Z-axis rotation
    float rotationMatrix[3][3];
    createRotationMatrixZ(rotationMatrix, theta);

    // Rotate the cube
    rotateVertexTable(rotationMatrix, vertexTable);

    // Translate the cube back to its original position (add center)
    for (i = 0; i < vertexCount; i++) {
        vertexTable[i][0] += center[0];
        vertexTable[i][1] += center[1];
        vertexTable[i][2] += center[2];
    }
}

void rotateVertexTable(float rotationMatrix[3][3], float vertexTable[vertexCount][3]) {
    int i;
    float newVertex[3];

    // Apply the rotation matrix to each vertex in the vertexTable
    for (i = 0; i < vertexCount; i++) {
        // Multiply the rotation matrix by the vertex (x, y, z)
        newVertex[0] = rotationMatrix[0][0] * vertexTable[i][0] + rotationMatrix[0][1] * vertexTable[i][1] + rotationMatrix[0][2] * vertexTable[i][2];
        newVertex[1] = rotationMatrix[1][0] * vertexTable[i][0] + rotationMatrix[1][1] * vertexTable[i][1] + rotationMatrix[1][2] * vertexTable[i][2];
        newVertex[2] = rotationMatrix[2][0] * vertexTable[i][0] + rotationMatrix[2][1] * vertexTable[i][1] + rotationMatrix[2][2] * vertexTable[i][2];

        // Update the vertexTable with the new rotated values
        vertexTable[i][0] = newVertex[0];
        vertexTable[i][1] = newVertex[1];
        vertexTable[i][2] = newVertex[2];
    }
}

 //Example: Create a rotation matrix for rotation around the Z-axis by theta radians
void createRotationMatrixZ(float matrix[3][3], float theta) {
    matrix[0][0] = cosf(theta);
    matrix[0][1] = -sinf(theta);
    matrix[0][2] = 0;

    matrix[1][0] = sinf(theta);
    matrix[1][1] = cosf(theta);
    matrix[1][2] = 0;

    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
}

// Function to create a rotation matrix for rotation around the X-axis
//void createRotationMatrixX(float matrix[3][3], float theta) {
//    matrix[0][0] = 1;
//    matrix[0][1] = 0;
//    matrix[0][2] = 0;
//
//    matrix[1][0] = 0;
//    matrix[1][1] = cosf(theta);
//    matrix[1][2] = -sinf(theta);
//
//    matrix[2][0] = 0;
//    matrix[2][1] = sinf(theta);
//    matrix[2][2] = cosf(theta);
//}

// Function to rotate around the line y = x





// Example: Rotate the vertexTable by rotating around the Z-axis
//void rotateExample() {
//    float rotationMatrix[3][3];
//    float theta = M_PI / 4;  // 45 degrees in radians
//
//    // Create the rotation matrix for rotation around the Z-axis
//    createRotationMatrixZ(rotationMatrix, theta);
//
//    // Rotate the vertex table
//    rotateVertexTable(rotationMatrix, vertexTable);
//}



//void swapBuffers() {
//    // Swap the buffers
//    Graphics_Context *temp = g_sCurrentContext;
//    g_sCurrentContext = g_sNextContext;
//    g_sNextContext = temp;
//}



//void initializeInputs() {
    // Stop watchdog timer
//    WDT_A_hold(WDT_A_BASE);

    // step 3: Initializing S1 (ACTIVE LOW)
//    P1DIR = P1DIR & ~BUTTON1; // set button pin as input
//    P1REN |= BUTTON1; // enable pull-up/pull-down resistor for pin
//    P1OUT |= BUTTON1; // controls resistor behavior (1 pull-up to Vcc; 0 pull-down to GND)


//    // S2 is connected to P1.4
//    // Therefore, bit 4 of P1DIR register should be reset to 0
//    P1DIR = P1DIR & ~BIT4;
//    // To enable the pull resistor we should set the bit 4 of P1REN to 1
//    P1REN = P1REN | BIT4;
//    // To make the pull resistor a pull-up, we need to set the bit 4 of P1OUT to 1
//    P1OUT = P1OUT | BIT4;
//    // To read the status of S2, we need to check bit 4 of P1IN
//    // masking all other bits leaves a value that it is either zero, or non-zero.
//}
//
























