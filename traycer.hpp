#ifndef TRAYCER_HPP
#define TRAYCER_HPP

#include <vector>
#include <memory>
#include <random>

#include "geometry.hpp"

class Object;

extern const float kInfinity;
extern std::random_device rd;
extern std::mt19937 gen;
extern std::uniform_real_distribution<> dis;

// Compute the roots of a quadratic equation
bool solveQuadratic(const float &,
                    const float &,
                    const float &,
                    float &,
                    float &);

inline
float clamp(const float &lo, const float &hi, const float &v)
{ return std::max(lo, std::min(hi, v)); }

inline
float deg2rad(const float &deg)
{ return deg * M_PI / 180; }

inline
Vec3f mix(const Vec3f &a, const Vec3f& b, const float &mixValue)
{ return a * (1 - mixValue) + b * mixValue; }

struct Options
{
    uint32_t width;
    uint32_t height;
    float fov;
    Matrix44f cameraToWorld;
};

// Returns true if the ray intersects an object. The variable tNear is set to the closest intersection distance and hitObject
// is a pointer to the intersected object. The variable tNear is set to infinity and hitObject is set null if no intersection
// was found.
bool trace(const Rayf &,
           const std::vector<std::unique_ptr<Object>> &, float &, const Object *&);

// Compute the color at the intersection point if any (returns background color otherwise)
Vec3f castRay(const Rayf &,
              const std::vector<std::unique_ptr<Object>> &);

// The main render function. This where we iterate over all pixels in the image, generate
// primary rays and cast these rays into the scene. The content of the framebuffer is
// saved to a file.
void render(const Options &,
            const std::vector<std::unique_ptr<Object>> &);

#endif // TRAYCER_HPP
