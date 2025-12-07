#ifndef DEFS_H_DEFINED
#define DEFS_H_DEFINED

#include <glm/glm.hpp>

struct character_st {
    unsigned TextureID;
    glm::ivec2   Size;
    glm::ivec2   Bearing;
    unsigned Advance;
};

#endif