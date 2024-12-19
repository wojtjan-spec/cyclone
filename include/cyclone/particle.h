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

            /**
            * Integrates the particle forward in time by the given amount.
            * This function uses a Newton-Euler integration method, which is a
            * linear approximation of the correct integral. For this reason it
            * may be inaccurate in some cases.
            */
            void integrate(real duration);

            /**
            * Holds the accumulated force to be applied at the next
            * simulation iteration only. This value is zeroed at each
            * integration step.
            */
            Vector3 forceAccum;
    };
} // namespace cyclone
