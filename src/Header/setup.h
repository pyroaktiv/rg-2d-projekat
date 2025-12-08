#ifndef SETUP_H_DEFINED
#define SETUP_H_DEFINED

// Program setup
void setupGlfw();
void setupScreen();
void setupCallbacks();
void preprocessTextures();


// Vertex setup
void setupRoadVertices();
void setupBusStopCircleVertices();
void setupControlBoardRectangleVertices();

void setupBusStopCenterVertices();
void setupTextureCenterVertices();

void setupTextureVertices();

// Road length setup
void setupRoadSegmentLengths();

// VAO setup
void setupRoadVAO();
void setupBusStopVAO();
void setupControlBoardRectangleVAO();
void setupTextureVAO();

// Shader setup
void setupShaders();

#endif