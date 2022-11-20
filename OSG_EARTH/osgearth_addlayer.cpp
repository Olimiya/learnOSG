//#include <osgEarth/MapNode>
//#include <osgEarth/ImageLayer>
//#include <osgEarth/ElevationLayer>
//#include <osgEarthDrivers/tms/TMSOptions>
//#include <osgEarthDrivers/gdal/GDALOptions>
//#include <osgEarthDrivers/agglite/AGGLiteOptions>
//#include <osgEarthFeatures/Session>
//#include <osgViewer/Viewer>
//#include <QString>
// using namespace osgEarth;
// using namespace osgEarth::Drivers;
// int main()
//{
//    auto viewer = osgViewer::Viewer();

//    // Create a Map and set it to Geocentric to display a globe
//    Map *map = new Map();

//    // Add an imagery layer (blue marble from a TMS source)
//    {
//        QString name = "t";
//        QString path =
//            "F:/program/SimPlanning/build-LJH-Desktop_Qt_5_12_1_MSVC2017_64bit-Debug/binV2/"
//            "example_data/terrain/nanbu-500/Bing Images/tms.xml";

//        TMSOptions tms;
//        tms.url() = path.toUtf8().data();
//        ImageLayer *layer = new osgEarth::ImageLayer(name.toUtf8().data(), tms);

//        //        tms.url() = "http://labs.metacarta.com/wms-c/Basic.py/1.0.0/satellite/";
//        //        ImageLayer *layer = new ImageLayer("NASA", tms);

//        map->addLayer(layer);
//    }

//    // Create a MapNode to render this map:
//    MapNode *mapNode = new MapNode(map);

//    viewer.setSceneData(mapNode);

//    viewer.getCamera()->setSmallFeatureCullingPixelSize(-1.0f);
//    return viewer.run();
//}
