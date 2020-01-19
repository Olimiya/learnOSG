//
// OpenSceneGraph Quick Start Guide
// http://www.lulu.com/content/767629
// http://www.openscenegraph.com/osgwiki/pmwiki.php/Documentation/QuickStartGuide
//

// Texture Mapping Example, Texture mapped tree, blending, alpha test

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/StateSet>
#include <osg/StateAttribute>
#include <osg/Texture2D>
#include <osg/BlendFunc>
#include <osg/AlphaFunc>
#include <osg/Notify>
#include <string>

osg::ref_ptr<osg::Node> createGeodes()
{
    osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array;
    v->push_back( osg::Vec3( 0.f, 0.f, 0.f ) ); // 0
    v->push_back( osg::Vec3( 0.f, 0.f, 4.f ) );
    v->push_back( osg::Vec3( -1.f, 0.f, 0.f ) );
    v->push_back( osg::Vec3( 1.f, 0.f, 0.f ) ); //3
    v->push_back( osg::Vec3( 1.f, 0.f, 4.f ) );
    v->push_back( osg::Vec3( -1.f, 0.f, 4.f ) );
    v->push_back( osg::Vec3( 0.f, -1.f, 0.f ) ); //6
    v->push_back( osg::Vec3( 0.f, 1.f, 0.f ) );
    v->push_back( osg::Vec3( 0.f, 1.f, 4.f ) );
    v->push_back( osg::Vec3( 0.f, -1.f, 4.f ) ); //9

    osg::ref_ptr<osg::Vec2Array> tc = new osg::Vec2Array;
    tc->push_back( osg::Vec2( .5f, 0.f ) );
    tc->push_back( osg::Vec2( .5f, 1.f ) );
    tc->push_back( osg::Vec2( 0.f, 0.f ) );
    tc->push_back( osg::Vec2( 1.f, 0.f ) );
    tc->push_back( osg::Vec2( 1.f, 1.f ) );
    tc->push_back( osg::Vec2( 0.f, 1.f ) );
    tc->push_back( osg::Vec2( 0.f, 0.f ) );
    tc->push_back( osg::Vec2( 1.f, 0.f ) );
    tc->push_back( osg::Vec2( 1.f, 1.f ) );
    tc->push_back( osg::Vec2( 0.f, 1.f ) );

    osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array;
    c->push_back( osg::Vec4( 1.f, 1.f, 1.f, 1.f ) );

    osg::ref_ptr<osg::Group> grp = new osg::Group;
    {
        osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
        geom->setVertexArray( v.get() );
        geom->setTexCoordArray( 0, tc.get() );
        geom->setColorArray( c.get() );
        geom->setColorBinding( osg::Geometry::BIND_OVERALL );

        // -X panal
        GLushort indices[] = { 2, 0, 1, 5 };
        geom->addPrimitiveSet( new osg::DrawElementsUShort(
            osg::PrimitiveSet::QUADS, 4, indices ) );

        osg::ref_ptr<osg::Geode> geode = new osg::Geode;
        geode->addDrawable( geom.get() );
        grp->addChild( geode.get() );
    }
    {
        osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
        geom->setVertexArray( v.get() );
        geom->setTexCoordArray( 0, tc.get() );
        geom->setColorArray( c.get() );
        geom->setColorBinding( osg::Geometry::BIND_OVERALL );

        // +X panal
        GLushort indices[] = { 2, 3, 4, 5 };
        geom->addPrimitiveSet( new osg::DrawElementsUShort(
            osg::PrimitiveSet::QUADS, 4, indices ) );

        osg::ref_ptr<osg::Geode> geode = new osg::Geode;
        geode->addDrawable( geom.get() );
        grp->addChild( geode.get() );
    }
//    {
//        osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
//        geom->setVertexArray( v.get() );
//        geom->setTexCoordArray( 0, tc.get() );
//        geom->setColorArray( c.get() );
//        geom->setColorBinding( osg::Geometry::BIND_OVERALL );

//        GLushort indices[] = { 6, 0, 1, 9 };
//        geom->addPrimitiveSet( new osg::DrawElementsUShort(
//            osg::PrimitiveSet::QUADS, 4, indices ) );

//        osg::ref_ptr<osg::Geode> geode = new osg::Geode;
//        geode->addDrawable( geom.get() );
//        grp->addChild( geode.get() );
//    }
//    {
//        osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
//        geom->setVertexArray( v.get() );
//        geom->setTexCoordArray( 0, tc.get() );
//        geom->setColorArray( c.get() );
//        geom->setColorBinding( osg::Geometry::BIND_OVERALL );

//        GLushort indices[] = { 0, 7, 8, 1 };
//        geom->addPrimitiveSet( new osg::DrawElementsUShort(
//            osg::PrimitiveSet::QUADS, 4, indices ) );

//        osg::ref_ptr<osg::Geode> geode = new osg::Geode;
//        geode->addDrawable( geom.get() );
//        grp->addChild( geode.get() );
//    }

    return grp.get();
}

osg::ref_ptr<osg::Node> createSceneGraph()
{
    osg::ref_ptr<osg::Node> node = createGeodes();

    osg::StateSet* state = node->getOrCreateStateSet();
    state->setMode( GL_LIGHTING, osg::StateAttribute::OFF |
        osg::StateAttribute::PROTECTED );
    state->setRenderingHint( osg::StateSet::TRANSPARENT_BIN );

    // Load the texture image
    //   Image courtesy Virtual Terrain Project (http://vterrain.org/)
    std::string fileName( "test2.svg" );
    osg::ref_ptr<osg::Image> image = osgDB::readImageFile( fileName );
    if (!image.valid())
    {
        osg::notify( osg::FATAL ) << "Unable to load data file. Exiting." << std::endl;
        return NULL;
    }

    // Set the image in a Texture2D object
    osg::ref_ptr<osg::Texture2D> tex = new osg::Texture2D;
    tex->setImage( image.get() );
    // After creating the OpenGL texture object, release the
    //   internal ref_ptr<Image> (to delete the Image).
    tex->setUnRefImageDataAfterApply( true );
    state->setTextureAttributeAndModes( 0, tex.get() );

    // Turn on blending
    osg::BlendFunc* bf = new osg::BlendFunc(
        osg::BlendFunc::SRC_ALPHA, osg::BlendFunc::ONE_MINUS_SRC_ALPHA );
    state->setAttributeAndModes( bf );

    // Turn on alpha testing
    osg::AlphaFunc* af = new osg::AlphaFunc(
        osg::AlphaFunc::GREATER, 0.05f );
    state->setAttributeAndModes( af );


    return node.get();
}

int main()
{
    osgDB::Registry::instance()->getDataFilePathList().push_back("F:\\program\\learnOSG\\model");

    osgViewer::Viewer viewer;
    viewer.setSceneData(createSceneGraph());
    viewer.realize();
    viewer.run();
}
