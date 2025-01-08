#include "particle.h"

void Particle::integrate(real duration) {
    assert(duration > 0.0);

    // Update linear position.
    position.addScaledVector(velocity, duration);

    // Find the acceleration from the force.
    Vector3 resultingAcc = acceleration;
    resultingAcc.addScaledVector(forceAccum, inverseMass);

    // Update linear veocity grom the acceleration.
    velocity.addScaledVector(resultingAcc, duration);

    // Imppose drag.
    velocity *= real_pow(damping, duration);

    // Clear the forces.
    clearAccumulator();
}

void Particle::clearAccumulator() {
    forceAccum.clear();
}

void Particle::addForce(const Vector3 &force) {
    forceAccum += force;
}