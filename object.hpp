#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "traycer.hpp"

// Object base class
class Object
{
public:
    Object() : color(dis(gen), dis(gen), dis(gen)) {}

    virtual ~Object() {}

    // Method to compute the intersection of the object with a ray
    // Returns true if an intersection was found, false otherwise
    // See method implementation in children class for details
    virtual bool intersect(const Rayf &, float &) const = 0;

    // Method to compute the surface data such as normal and texture coordnates at the intersection point.
    // See method implementation in children class for details
    virtual void getSurfaceData(const Vec3f &, Vec3f &, Vec2f &) const = 0;

    Vec3f color;
};

// Sphere class. A sphere type object
class Sphere : public Object
{
public:
    Sphere(const Vec3f &c, const float &r) : radius(r), radius2(r * r), center(c) {}

    // Ray-sphere intersection test
    // orig is the ray origin
    // dir is the ray direction
    // t is the distance from the ray origin to the intersection point
    bool intersect(const Rayf &, float &) const override;

    // Set surface data such as normal and texture coordinates at a given point on the surface
    // Phit is the point ont the surface we want to get data on
    // Nhit is the normal at Phit
    // tex are the texture coordinates at Phit
    void getSurfaceData(const Vec3f &, Vec3f &, Vec2f &) const override;

    float radius, radius2;
    Vec3f center;
};

#endif // OBJECT_HPP
