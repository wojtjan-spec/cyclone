#include "pfgen.h"

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

void ParticleDrag::updateForce(Particle* particle, real duration) {
    Vector3 force;
    particle->getVelocity(&force);

    real dragCoeff = k1 + k2 * force.magnitude();
    dragCoeff = k1 * dragCoeff + k2 * dragCoeff * dragCoeff;

    force.normalize();
    force *= -dragCoeff;
    particle->addForce(force);
}

void ParticleSpring::updateForce(Particle* particle, real duration) {
    Vector3 force;
    particle->getPosition(&force);
    force -= other->getPosition();

    real magnitude = force.magnitude();
    magnitude = real_abs(magnitude - restLength);
    magnitude *= springConstant;

    force.normalize();
    force *= -magnitude;
    particle->addForce(force);
}
