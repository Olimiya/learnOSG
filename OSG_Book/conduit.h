#include <osgViewer/Viewer>
#include <osg/Group>
#include <osg/Geode>
#include <osgParticle/Particle>
#include <osgParticle/PointPlacer>
#include <osgParticle/ParticleSystem>
#include <osgParticle/ParticleSystemUpdater>
#include <osgParticle/ModularEmitter>
#include <osgParticle/ModularProgram>
#include <osgParticle/RandomRateCounter>
#include <osgParticle/RadialShooter>
#include <osgParticle/AccelOperator>
#include <osgParticle/FluidFrictionOperator>

class  Conduit
{
public:
    Conduit(void);
    ~Conduit(void);
    osgParticle::ParticleSystem * CreateConduitScene(osg::Group* root);
    float m_fTheNum;
    float m_fTheSize;
    float m_fTheSpeech;
    osg::Node * CreateConduit(osg::Group * root);
    osg::Vec3 m_VecPosition;
};
