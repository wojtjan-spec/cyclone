#include <cyclone/precision.h>
#include <cyclone/core.h>

namespace cyclone{
    class Particle {
        public:
            Vector3 position;
            Vector3 velocity;
            Vector3 acceleration;

            real damping;
            real inverseMass; // TODO: make protected
    };
} // namespace cyclone
