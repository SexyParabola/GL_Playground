#ifndef MODELENGINE_H
#define MODELENGINE_H

#include <vector>
#include <glm/glm.hpp>
using namespace glm;

vec4 nek(const vec3 v);
vec3 denek(const vec4 v);

struct Triangle {
    Triangle(vec3 P1, vec3 P2, vec3 P3);
    Triangle(vec3 P1, vec3 P2, vec3 P3, vec3 C);
    Triangle(vec3 P1, vec3 P2, vec3 P3, vec3 C1, vec3 C2, vec3 C3);
	Triangle* next = nullptr;
    vec3 data[6];
};

struct Mesh {
private:
    Triangle* root = nullptr;
    int triangles = 0;
public:
    ~Mesh();
    void addTriangle(Triangle t);
    void updateData();
    int getCount();
    float* vertexData = nullptr;
    float* vertexColorData = nullptr;
    void translate(vec3 offset);
    void rotate(float theta, vec3 axis);
};

#endif