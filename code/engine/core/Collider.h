#ifndef __COLLIDER_H__
#define __COLLIDER_H__

#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include "Transform.h"

class AABBCollider {
public:
    AABBCollider() = default;
    ~AABBCollider() = default;
    AABBCollider(std::vector<glm::vec3> vertices);

    void update(std::vector<glm::vec3> vertices);

    void setTransform(Transform *transform)
    {
        pTransform = transform;
    }

    glm::vec3 getMax();
    glm::vec3 getMin();
    glm::vec3 getCenter();

private:
    Transform* pTransform;
    glm::vec3 max{0};
    glm::vec3 min{0};
};

class ConvexHullCollider {
public:
    ConvexHullCollider() = default;
    ~ConvexHullCollider() = default;
    ConvexHullCollider(std::vector<glm::vec3> vertices) : mVertices(vertices) {}

    void update(std::vector<glm::vec3> vertices);

    /* void setTransform(std::shared_ptr<Transform> transform) { pTransform = transform; } */
    void setTransform(Transform *transform)
    {
        pTransform = transform;
    }

private:
    /* std::shared_ptr<Transform> pTransform; */
    Transform* pTransform;
    std::vector<glm::vec3> mVertices;
};

#endif // __COLLIDER_H__
