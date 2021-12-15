#include "ModelEngine.hpp"
#include <new>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

vec4 nek(const vec3 v) { return vec4(v.x, v.y, v.z, 0.0); }
vec3 denek(const vec4 v) { return vec3(v.x, v.y, v.z); }

Triangle::Triangle(vec3 P1, vec3 P2, vec3 P3) { data[0] = P1; data[1] = P2; data[2] = P3; }
Triangle::Triangle(vec3 P1, vec3 P2, vec3 P3, vec3 C) {
    data[0] = P1; data[1] = P2; data[2] = P3; data[3] = C; data[4] = C; data[5] = C; 
}
Triangle::Triangle(vec3 P1, vec3 P2, vec3 P3, vec3 C1, vec3 C2, vec3 C3) {
    data[0] = P1; data[1] = P2; data[2] = P3; data[3] = C1; data[4] = C2; data[5] = C3; 
}

Mesh::~Mesh() {
    delete[] vertexData;
    delete[] vertexColorData;
}

int Mesh::getCount() {
    return triangles;
}

void Mesh::addTriangle(Triangle t) {
    if (root == nullptr) {
        root = new Triangle(t);
    } else {
        Triangle* cassi = root;
        root = new Triangle(t);
        root->next = cassi;
    }
    triangles++;
}

void Mesh::updateData() {
    vertexData = new float[triangles * 9];
    vertexColorData = new float[triangles * 9];

    int t = 0;
    for (Triangle* curr = root; curr != nullptr; curr = curr->next) {
        vertexData[  t*9  ] = curr->data[0].x;
        vertexData[t*9 + 1] = curr->data[0].y;
        vertexData[t*9 + 2] = curr->data[0].z;
        vertexData[t*9 + 3] = curr->data[1].x;
        vertexData[t*9 + 4] = curr->data[1].y;
        vertexData[t*9 + 5] = curr->data[1].z;
        vertexData[t*9 + 6] = curr->data[2].x;
        vertexData[t*9 + 7] = curr->data[2].y;
        vertexData[t*9 + 8] = curr->data[2].z;
        vertexColorData[  t*9  ] = curr->data[3].x;
        vertexColorData[t*9 + 1] = curr->data[3].y;
        vertexColorData[t*9 + 2] = curr->data[3].z;
        vertexColorData[t*9 + 3] = curr->data[4].x;
        vertexColorData[t*9 + 4] = curr->data[4].y;
        vertexColorData[t*9 + 5] = curr->data[4].z;
        vertexColorData[t*9 + 6] = curr->data[5].x;
        vertexColorData[t*9 + 7] = curr->data[5].y;
        vertexColorData[t*9 + 8] = curr->data[5].z;
        t++;
    }
}

void Mesh::translate(vec3 offset) {
    for (Triangle* curr = root; curr != nullptr; curr = curr->next) { 
        for (int i = 0; i < 3; i++) {
            curr->data[i] += offset;
        }
    }
    updateData();
}

void Mesh::rotate(float theta, vec3 axis) {
    mat4 rotMatrix = glm::rotate(mat4(1.0), theta, axis);
    for (Triangle* curr = root; curr != nullptr; curr = curr->next) { 
        for (int i = 0; i < 3; i++) {
            curr->data[i] = denek(rotMatrix * nek(curr->data[i]));
        }
    }
    updateData();
}