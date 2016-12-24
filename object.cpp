#include <algorithm>

#include "traycer.hpp"
#include "object.hpp"
#include "geometry.hpp"

bool Sphere::intersect(const Rayf &ray, float &t) const
{
    float t0, t1; // solutions for t if the ray intersects
    Vec3f L = ray.orig - center;
    float a = ray.dir.dotProduct(ray.dir);
    float b = 2 * ray.dir.dotProduct(L);
    float c = L.dotProduct(L) - radius2;
    if (!solveQuadratic(a, b, c, t0, t1)) return false;

    if (t0 > t1) std::swap(t0, t1);

    if (t0 < 0) {
        t0 = t1; // if t0 is negative, let's use t1 instead
        if (t0 < 0) return false; // both t0 and t1 are negative
    }

    t = t0;

    return true;
}

void Sphere::getSurfaceData(const Vec3f &Phit, Vec3f &Nhit, Vec2f &tex) const
{
    Nhit = Phit - center;
    Nhit.normalize();
    // In this particular case, the normal is simular to a point on a unit sphere
    // centred around the origin. We can thus use the normal coordinates to compute
    // the spherical coordinates of Phit.
    // atan2 returns a value in the range [-pi, pi] and we need to remap it to range [0, 1]
    // acosf returns a value in the range [0, pi] and we also need to remap it to the range [0, 1]
    tex.x = (1 + atan2(Nhit.z, Nhit.x) / M_PI) * 0.5;
    tex.y = acosf(Nhit.y) / M_PI;
}

