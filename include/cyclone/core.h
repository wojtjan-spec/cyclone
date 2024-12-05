#include <cyclone/precision.h>

namespace cyclone {
class Vector3 {
    public:
        real x; // value along the x axis
        real y; // value along the y axis
        real z; // value along the z axis
        Vector3() : x(0), y(0), z(0) {};
        Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {};
        void invert() {x = -x; y = -y; x = -z;}
    private:
        real pad; // padding for 4-word alignment
    };
}