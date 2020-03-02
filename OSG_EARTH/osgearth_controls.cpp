///* -*-c++-*- */
///* osgEarth - Geospatial SDK for OpenSceneGraph
//* Copyright 2019 Pelican Mapping
//* http://osgearth.org
//*
//* osgEarth is free software; you can redistribute it and/or modify
//* it under the terms of the GNU Lesser General Public License as published by
//* the Free Software Foundation; either version 2 of the License, or
//* (at your option) any later version.
//*
//* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//* IN THE SOFTWARE.
//*
//* You should have received a copy of the GNU Lesser General Public License
//* along with this program.  If not, see <http://www.gnu.org/licenses/>
//*/

//#include <typeinfo>

//#include <osg/Notify>
//#include <osgDB/ReadFile>
//#include <osgGA/GUIEventHandler>
//#include <osgViewer/Viewer>
//#include <osgEarth/Registry>
//#include <osgEarthUtil/EarthManipulator>
//#include <osgEarthUtil/Controls>
//#include <osgEarthUtil/ExampleResources>
//#include <osgEarthSymbology/Color>

//using namespace osgEarth::Symbology;
//using namespace osgEarth::Util::Controls;


//void createControls( ControlCanvas* );
//ImageControl* s_imageControl = 0L;


//int main(int argc, char** argv)
//{
//    osg::ArgumentParser arguments(&argc,argv);
//    osgViewer::Viewer viewer(arguments);

//    osg::Node* node = osgEarth::Util::MapNodeHelper().load(arguments, &viewer);
//    if (!node)
//    {
//        OE_WARN << "No earth file on the command line." << std::endl;
//        return -1;
//    }

//    osg::Group* root = new osg::Group();
//    root->addChild( node );

//    // create a surface to house the controls
//    ControlCanvas* cs = ControlCanvas::getOrCreate( &viewer );

//    viewer.setSceneData( root );
//    viewer.setCameraManipulator( new osgEarth::Util::EarthManipulator );

//    // create some controls.
//    createControls( cs );

//    return viewer.run();
//}

//struct MyClickHandler : public ControlEventHandler
//{
//    void onClick( Control* control, const osg::Vec2f& pos, int mouseButtonMask )
//    {
//        OE_NOTICE << "You clicked at (" << pos.x() << ", " << pos.y() << ") within the control."
//            << std::endl;
//    }
//};

//static LabelControl* s_sliderLabel;

//struct MySliderHandler : public ControlEventHandler
//{
//    void onValueChanged( Control* control, float value )
//    {
//        std::stringstream buf;
//        buf << (int)value;
//        std::string str;
//        str = buf.str();
//        s_sliderLabel->setText( str );
//    }
//};

//struct RotateImage : public ControlEventHandler
//{
//    void onValueChanged( Control* control, float value )
//    {
//        if (s_imageControl)
//            s_imageControl->setRotation( Angular(value) );
//    }
//};

//void
//createControls( ControlCanvas* cs )
//{
//    osgDB::Registry::instance()->getDataFilePathList().push_back("F:\\program\\learnOSG");

//    // a container centered on the screen, containing an image and a text label.
//    {
//        VBox* center = new VBox();
//        center->setBorderColor( 1, 1, 1, 1 );
//        center->setBackColor( .6,.5,.4,0.5 );
//        center->setPadding( 10 );
//        center->setHorizAlign( Control::ALIGN_CENTER );
//        center->setVertAlign( Control::ALIGN_CENTER );

//        // Add an image:
//        osg::ref_ptr<osg::Image> image = osgDB::readRefImageFile("/model/Images/blueFlowers.png");
//        if ( image.valid() )
//        {
//            s_imageControl = new ImageControl( image.get() );
//            s_imageControl->setHorizAlign( Control::ALIGN_CENTER );
//            s_imageControl->setFixSizeForRotation( true );
//            center->addControl( s_imageControl );
//            center->setHorizAlign( Control::ALIGN_CENTER );
//        }

//        // Add a text label:
//        HBox* father1 = new HBox();
//        father1->setChildVertAlign( Control::ALIGN_LEFT );
//        father1->setHorizFill( true );
//        father1->setMargin(0);
//        LabelControl* label1 = new LabelControl( "0" );
//        label1->setFont( osgEarth::Registry::instance()->getDefaultFont() );
//        label1->setFontSize( 10.0f );
//        label1->setHorizAlign( Control::ALIGN_LEFT );
//        label1->setMargin( 0 );
//        father1->addControl( label1 );

//        LabelControl* label = new LabelControl( "1000km" );
//        label->setFont( osgEarth::Registry::instance()->getDefaultFont() );
//        label->setFontSize( 10.0f );
//        label->setHorizAlign( Control::ALIGN_CENTER );
//        label->setMargin( 0 );
//        father1->addControl( label );

//        LabelControl* label2 = new LabelControl( "2000km" );
//        label2->setFont( osgEarth::Registry::instance()->getDefaultFont() );
//        label2->setFontSize( 10.0f );
//        label2->setHorizAlign( Control::ALIGN_RIGHT );
//        label2->setMargin( 0 );
//        father1->addControl( label2 );

//        center->addControl(father1);

//        // Rotation slider
//        HBox* father = new HBox();
//        father->setChildSpacing(0);
//        father->setChildVertAlign( Control::ALIGN_LEFT );
//        father->setHorizFill( true );
//        father->setMargin(0);

//        HBox* rotateBox = new HBox();
//        rotateBox->setSize(400, 10);
//        rotateBox->setBackColor( Color::Blue );
//        rotateBox->setMargin(0);

//        HBox* rotateBox1 = new HBox();
//        rotateBox1->setSize(400, 10);
//        rotateBox1->setBackColor( Color::White );
//        rotateBox1->setMargin(0);

//        father->addChild(rotateBox);
//        father->addChild(rotateBox1);

//        {
////            rotateBox->addControl( new LabelControl("Rotate: ") );

////            HSliderControl* rotateSlider = new HSliderControl( -180.0, 180.0, 0.0 );
////            rotateSlider->addEventHandler( new RotateImage() );
////            rotateSlider->setHeight( 8.0f );
////            rotateSlider->setHorizFill( true );
////            rotateBox->addControl( rotateSlider );
//        }
//        center->addControl( father );

//        cs->addControl( center );
//    }

//    // a simple vbox with absolute positioning in the upper left with two text labels.
//    {
//        VBox* ul = new VBox();
//        ul->setPosition( 20, 20 );
//        ul->setPadding( 10 );
//        {
//            LabelControl* title = new LabelControl( "Upper left control", 22, osg::Vec4f(1,1,0,1) );
//            ul->addControl( title );

//            LabelControl* content = new LabelControl( "Here is some text in the upper left control" );
//            ul->addControl( content );

//            HBox* c2 = new HBox();
//            c2->setChildSpacing( 10 );
//            {
//                HSliderControl* slider = new HSliderControl( 0, 100 );
//                slider->setBackColor( .6,0,0,1 );
//                slider->setHeight( 25 );
//                slider->setWidth( 300 );
//                slider->addEventHandler( new MySliderHandler() );
//                c2->addControl( slider );

//                s_sliderLabel = new LabelControl();
//                s_sliderLabel->setVertAlign( Control::ALIGN_CENTER );
//                c2->addControl( s_sliderLabel );
//            }
//            ul->addControl( c2 );

//            HBox* c3 = new HBox();
//            c3->setHorizAlign( Control::ALIGN_CENTER );
//            c3->setChildSpacing( 10 );
//            {
//                HBox* c4 = new HBox();
//                c4->setChildSpacing( 5 );
//                {
//                    c4->addControl( new CheckBoxControl( true ) );
//                    c4->addControl( new LabelControl( "Checkbox 1" ) );
//                }
//                c3->addControl( c4 );

//                HBox* c5 = new HBox();
//                c5->setChildSpacing( 5 );
//                {
//                    c5->addControl( new CheckBoxControl( false ) );
//                    c5->addControl( new LabelControl( "Checkbox 2" ) );
//                }
//                c3->addControl( c5 );
//            }
//            ul->addControl( c3 );
//        }
//        cs->addControl( ul );

//        ul->addEventHandler( new MyClickHandler );
//    }

//    // a centered hbox container along the bottom on the screen.
//    {
//        HBox* bottom = new HBox();
//        bottom->setBackColor(0,0,0,0.5);
//        bottom->setMargin( 10 );
//        bottom->setChildSpacing( 145 );
//        bottom->setVertAlign( Control::ALIGN_BOTTOM );
//        bottom->setHorizAlign( Control::ALIGN_CENTER );

//        for( int i=0; i<4; ++i )
//        {
//            LabelControl* label = new LabelControl();
//            std::stringstream buf;
//            buf << "Label_" << i;
//            std::string str;
//            str = buf.str();
//            label->setText( str );
//            label->setMargin( 10 );
//            label->setBackColor( 1,1,1,0.4 );
//            bottom->addControl( label );

//            label->setActiveColor(1,.3,.3,1);
//            label->addEventHandler( new MyClickHandler );
//        }

//        cs->addControl( bottom );
//    }
//}
