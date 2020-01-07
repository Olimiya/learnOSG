#include "conduit.h"

Conduit::Conduit(void) : m_fTheNum(800), m_fTheSize(0.2), m_fTheSpeech(100)
{
    m_VecPosition.set (15, 64, 3) ;
}

Conduit::~Conduit(void)
{
}

osgParticle::ParticleSystem * Conduit::CreateConduitScene(osg::Group* root)
{
    osgParticle::Particle ptemplate;

    ptemplate.setLifeTime(10);        // 3 seconds of life

    ptemplate.setSizeRange(osgParticle::rangef(0.1f, 0.1f));
    ptemplate.setAlphaRange(osgParticle::rangef(1.0f, 0.5f));
    ptemplate.setColorRange(osgParticle::rangev4(
                                osg::Vec4(0.7f, 1.0f, 1.0f, 1.5f),
                                osg::Vec4(0.8f, 0.8f, 1.0f, 0.0f)));

    ptemplate.setRadius(m_fTheSize);    // 5 cm wide particles
    ptemplate.setMass(0.05f);    // 50 g heavy


    osgParticle::ParticleSystem *ps = new osgParticle::ParticleSystem;
    ps->setDefaultAttributes("Images/smoke.rgb", false, false);


    ps->setDefaultParticleTemplate(ptemplate);


    osgParticle::ModularEmitter *emitter = new osgParticle::ModularEmitter;
    emitter->setParticleSystem(ps);

    osgParticle::RandomRateCounter *counter = new osgParticle::RandomRateCounter;
    counter->setRateRange(m_fTheNum, m_fTheNum);
    emitter->setCounter(counter);

    osgParticle::PointPlacer *placer = new osgParticle::PointPlacer;
    placer->setCenter(m_VecPosition);
    emitter->setPlacer(placer);


    osgParticle::RadialShooter *shooter = new osgParticle::RadialShooter;
    shooter->setInitialSpeedRange(m_fTheSpeech, 0);
    emitter->setShooter(shooter);


    root->addChild(emitter);


    osgParticle::ModularProgram *program = new osgParticle::ModularProgram;
    program->setParticleSystem(ps);

    osgParticle::AccelOperator *op1 = new osgParticle::AccelOperator;
    op1->setToGravity();
    program->addOperator(op1);

    osgParticle::FluidFrictionOperator *op3 = new osgParticle::FluidFrictionOperator;
    op3->setFluidToAir();
    program->addOperator(op3);


    root->addChild(program);


    osg::Geode *geode = new osg::Geode;
    geode->addDrawable(ps);


    root->addChild(geode);

    return ps;
}

osg::Node * Conduit::CreateConduit(osg::Group * root)
{
    osgParticle::ParticleSystem *ps2 = CreateConduitScene(root);
    osgParticle::ParticleSystemUpdater *psu = new osgParticle::ParticleSystemUpdater;

    psu->addParticleSystem(ps2);

    return psu ;
}
