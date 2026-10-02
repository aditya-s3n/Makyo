// Shared structs and helpers. Must stay in sync with include/renderer/GpuTypes.h.

struct Triangle {
    vec4 v0;
    vec4 v1;
    vec4 v2;
    vec4 n0;
    vec4 n1;
    vec4 n2;
    vec4 centroid;
};

struct Material {
    vec4 albedo;
    vec4 emission;
    vec4 params;
};

struct BVHNode {
    vec3 aabbMin;
    uint leftOrFirst;
    vec3 aabbMax;
    uint triangleCount;
};

struct Camera {
    vec4 position;
    vec4 forward;
    vec4 right;
    vec4 up;
};

// TODO: RNG, ray/triangle intersection, BVH traversal, BSDF sampling
