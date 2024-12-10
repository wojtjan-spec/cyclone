#include <cyclone/precision.h>

namespace cyclone {
class Vector3 {
    public:
        real x; // value along the x axis
        real y; // value along the y axis
        real z; // value along the z axis
        Vector3() : x(0), y(0), z(0) {};
        Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {};
        void operator*=(const real value) {x*=value; y*=value; z*=value;};
        void operator+=(const Vector3& v) {x += v.x; y += v.y; z += v.z;};
        void operator-=(const Vector3& v) {x -= v.x; y -= v.y; z -= v.z;};
        Vector3 operator*(const real value) const {return Vector3(x*value, y*value, z*value);};
        Vector3 operator+(const Vector3& v) const {return Vector3(x+v.x, y+v.y, z+v.z);};
        Vector3 operator-(const Vector3& v) const {return Vector3(x-v.x, y-v.y, z-v.z);};

        void invert() {x = -x; y = -y; x = -z;}
        real magnitude() const {return real_sqrt(x*x + y*y + z*z);};
        real squaredMagnitude() const {return (x*x + y*y + z*z);};
        void normalize() {
            real l = magnitude();
            if(l > 0) {
                (*this) *= ((real)1)/l;
            }
        }
        void addScaledVector(const Vector3& vector, real scale) {
            x += vector.x * scale;
            y += vector.y * scale;
            z += vector.z * scale;
        }

    private:
        real pad; // padding for 4-word alignment
    };
}