#ifndef SETUP_H_DEFINED
#define SETUP_H_DEFINED

// Program setup
void setupGlfw();
void setupScreen();
void setupCallbacks();
void preprocessTextures();


// Vertex setup
void setupRoadVertices();
void setupBusStopCenterVertices();
void setupBusStopCircleVertices();

void setupControlBoardRectangleVertices();

// Road length setup
void setupRoadSegmentLengths();

// VAO setup
void setupRoadVAO();
void setupBusStopVAO();

void setupControlBoardRectangleVAO();

// Shader setup
void setupShaders();

#endif