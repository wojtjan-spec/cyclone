#include <cyclone/particle.h>
#include <vector>

using namespace cyclone;

/** 
 * A force generator can be asked to add a force to one or more paritcles.
 */
class ParticleForceGenerator {
    public:
        /**
         * Overload this in implementation of the interface to calculate 
         * and update the force applied to the given particle.
         */
        virtual void updateForce(Particle *particle, float duration) = 0;
};


class ParticleForceRegistry {
    protected:
        /**
         * Keeps track of force generator and particle it applies to.
         */
        struct ParticleForceRegistration { 
            Particle *particle;
            ParticleForceGenerator *fg;
        };
        typedef std::vector<ParticleForceRegistration> Registry;
        Registry registrations;
    
    public:
        // Registers the given force to apply to given particle.
        void add(Particle *particle, ParticleForceGenerator *fg);
        // Removes the given force and given particle from registry.
        void remove(Particle *particle, ParticleForceGenerator *fg);
        // Clears the registry. This only deletes records. It does not delete particles or generators.
        void clear();
        // Calls all the force generators to update the forces of their particles.
        void updateForces(real duration);
};

class ParticleGravity : public ParticleForceGenerator {
    Vector3 gravity;
    public:
        ParticleGravity(const Vector3 &gravity);
        virtual void updateForce(Particle *particle, real duration);
};

class ParticleDrag : public ParticleForceGenerator {
    real k1; // the velocity drag coefficient
    real k2; // the velocity squared drag coefficient
    public:
        ParticleDrag(real k1, real k2);
        virtual void updateForce(Particle *particle, real duration);
};

/**
* A force generator that applies a spring force.
*/
class ParticleSpring : public ParticleForceGenerator
{
    // The particle at the other end of the spring.
    Particle *other;
    // Holds the spring constant.
    real springConstant;
    // Holds the rest length of the spring.
    real restLength;

public:
    // Creates a new spring with the given parameters.
    ParticleSpring(Particle *other, real springConstant, real restLength);

    // Applies the spring force to the given particle.
    virtual void updateForce(Particle *particle, real duration);
};