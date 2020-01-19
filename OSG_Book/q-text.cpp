////By FreeSouth  ieysx@163.com  www.osgChina.org  2008 6 11

//#include <osgDB/ReadFile>
//#include <osgViewer/Viewer>

//#include <osg/Geode>
//#include <osg/Geometry>
//#include <osgText/Font>
//#include <osgText/Text>


//osg::ref_ptr<osg::Drawable> createBase()
//{
//    osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;

//    osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array;
//    geom->setVertexArray( v.get() );
//    v->push_back( osg::Vec3( -1.f, 0.f, -1.f ) );
//    v->push_back( osg::Vec3( 1.f, 0.f, -1.f ) );
//    v->push_back( osg::Vec3( 1.f, 0.f, 1.f ) );
//    v->push_back( osg::Vec3( -1.f, 0.f, 1.f ) );

//    osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array;
//    geom->setColorArray( c.get() );
//    geom->setColorBinding( osg::Geometry::BIND_PER_VERTEX );
//    c->push_back( osg::Vec4( 1.f, 0.f, 0.f, 1.f ) );
//    c->push_back( osg::Vec4( 0.f, 1.f, 0.f, 1.f ) );
//    c->push_back( osg::Vec4( 0.f, 0.f, 1.f, 1.f ) );
//    c->push_back( osg::Vec4( 1.f, 1.f, 1.f, 1.f ) );

//    osg::ref_ptr<osg::Vec3Array> n = new osg::Vec3Array;
//    geom->setNormalArray( n.get() );
//    geom->setNormalBinding( osg::Geometry::BIND_OVERALL );
//    n->push_back( osg::Vec3( 0.f, -1.f, 0.f ) );

//    geom->addPrimitiveSet(
//        new osg::DrawArrays( osg::PrimitiveSet::QUADS, 0, 4 ) );

//    return geom.get();
//}

//osg::ref_ptr<osg::Node> createSceneGraph()
//{
//    // Create the root (and only) node.
//    osg::ref_ptr<osg::Geode> geode = new osg::Geode;

//    geode->addDrawable( createBase().get() );

//    osg::ref_ptr<osgText::Font> font = osgText::readFontFile( "fonts/arial.ttf" );

//    osg::Vec4 white( 1.f, 1.f, 1.f, 1.f );

//    {
//        osg::ref_ptr<osgText::Text> text = new osgText::Text;
//        text->setFont( font.get() );
//        text->setColor( white );
//        text->setCharacterSize( .15f );
//        text->setPosition( osg::Vec3( 1.f, 0.f, 1.f ) );
//        text->setAxisAlignment( osgText::Text::SCREEN );
//        text->setText( "Top-right" );
//        geode->addDrawable( text.get() );
//    }
//    {
//        osg::ref_ptr<osgText::Text> text = new osgText::Text;
//        text->setFont( font.get() );
//        text->setColor( white );
//        text->setCharacterSize( .15f );
//        text->setPosition( osg::Vec3( -1.f, 0.f, 1.f ) );
//        text->setAxisAlignment( osgText::Text::SCREEN );
//        text->setText( "Top-left" );
//        geode->addDrawable( text.get() );
//    }
//    {
//        osg::ref_ptr<osgText::Text> text = new osgText::Text;
//        text->setFont( font.get() );
//        text->setFontResolution( 128, 128 );
//        text->setColor( white );
//        text->setCharacterSize( .4f );
//        text->setPosition( osg::Vec3( 0.f, 0.f, -1.04f ) );
//        text->setAxisAlignment( osgText::Text::XZ_PLANE );
//        text->setAlignment( osgText::Text::CENTER_TOP );
//        text->setText( "Hello OSG World" );
//        geode->addDrawable( text.get() );
//    }

//    return geode.get();
//}

//int main()
//{
//    osgViewer::Viewer viewer;
//    viewer.setSceneData(createSceneGraph());
//    viewer.realize();
//    viewer.run();
//}
