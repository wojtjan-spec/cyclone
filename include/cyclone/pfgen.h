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