#ifndef FSM_H_DEFINED
#define FSM_H_DEFINED

#include <GLM/glm.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

unsigned random_number(unsigned n);

glm::vec2 parametricCurve(float t);

bool isInProximity(unsigned station);
void doFSMLoop();

#endif