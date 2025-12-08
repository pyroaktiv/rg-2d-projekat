#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../Header/Util.h"
#include "../Header/constants.h"
#include "../Header/setup.h"
#include "../Header/globals.h"
#include "../Header/draw.h"
#include "../Header/fsm.h"

// Main fajl funkcija sa osnovnim komponentama OpenGL programa

// Projekat je dozvoljeno pisati počevši od ovog kostura
// Toplo se preporučuje razdvajanje koda po fajlovima (i eventualno potfolderima) !!!
// Srećan rad! fala

// Vladimir Zorić RA 36/2022

int main()
{
    setupGlfw();
    setupScreen();
    if (g_window == NULL) return endProgram("Prozor nije uspeo da se kreira.");
    glfwMakeContextCurrent(g_window);

    if (glewInit() != GLEW_OK) return endProgram("GLEW nije uspeo da se inicijalizuje.");

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(1.0f, 1.0f, 0.1f, 1.0f);

    setupCallbacks();

    setupRoadVertices();
    setupRoadSegmentLengths();
    setupBusStopCenterVertices();
    setupBusStopCircleVertices();
    setupControlBoardRectangleVertices();
    setupTextureVertices();
    setupTextureCenterVertices();

    setupRoadVAO();
    setupBusStopVAO();
    setupControlBoardRectangleVAO();
    setupTextureVAO();

    setupShaders();

    preprocessTextures();

    g_fsm_start_time = glfwGetTime();

    while (!glfwWindowShouldClose(g_window))
    {
        double init_frame_time = glfwGetTime();
        glClear(GL_COLOR_BUFFER_BIT);

        drawRoad();
        drawBusStops();

        doFSMLoop();

        drawControlBoardRectangle();

        drawTextures();

        glfwSwapBuffers(g_window);
        glfwPollEvents();


        while (glfwGetTime() - init_frame_time < 1 / TARGET_FPS);
    }

    glfwDestroyWindow(g_window);
    glfwTerminate();
    return 0;
}