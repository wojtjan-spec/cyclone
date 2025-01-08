#include <iostream> 

// TODO -> fix includes (and build) errors
#include "core.h"
#include "particle.h"
#include "pfgen.h"
#include "precision.h"

int main() {
    std::cout << "Hello world!" << std::endl;

    // one spring
    cyclone::Particle a, b;
    ParticleForceRegistry registry;

    ParticleSpring ps(&b, 1.0f, 2.0f);
    registry.add(&a, &ps);

    // two linked springs - should use separate registry
    ParticleSpring psA(&b, 1.0f, 2.0f);
    registry.add(&a, &psA);

    ParticleSpring psB(&a, 1.0f, 2.0f);
    registry.add(&b, &psB);

    return 0;
}
