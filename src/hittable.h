#ifndef HITTABLE_H
#define HITTABLE_H

// Hittable class that defines the interface for objects that can be hit by rays in the scene.
class material;

// Hit record struct that stores information about a ray-object intersection, including the hit point, surface normal, material of the hit object, ray parameter t, and whether the hit was on the front face of the surface.
class hit_record {
    public:
    point3 p; 
    vec3 normal; 
    shared_ptr<material> mat;
    double t;
    bool front_face;

    void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

// Hittable class that defines the interface for objects that can be hit by rays in the scene.
class hittable {
    public:
    virtual ~hittable() = default;
    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif