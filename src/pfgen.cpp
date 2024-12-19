#include <cyclone/pfgen.h>

using namespace cyclone;

void ParticleForceRegistry::updateForces(real duration) {
    Registry::iterator i = registrations.begin();
    for (; i!= registrations.end(); i++){
        i->fg->updateForce(i->particle, duration);
    }
}

void ParticleGravity::updateForce(Particle* particle, real duration) {
    if (particle->hasFiniteMass()) return;
    particle->addForce(gravity * particle->getMass());
}