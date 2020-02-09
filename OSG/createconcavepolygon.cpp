//#include <iostream>
//#include <Windows.h>

//#include <osgViewer/Viewer>
//#include <osgDB/ReadFile>

//#include <osgUtil/Tessellator>
//#include <osg/TriangleFunctor>

//using namespace std;
//using namespace osg;

//osg::ref_ptr<osg::Geometry> redPolygon;

////计算空间三角形的面积
//double CalTriangleArea(const osg::Vec3& a, const osg::Vec3& b, const osg::Vec3& c)
//{
//    double area = 0;

//    double side[3];//存储三条边的长度;

//    side[0] = sqrt(pow(a.x() - b.x(), 2) + pow(a.y() - b.y(), 2) + pow(a.z() - b.z(), 2));
//    side[1] = sqrt(pow(a.x() - c.x(), 2) + pow(a.y() - c.y(), 2) + pow(a.z() - c.z(), 2));
//    side[2] = sqrt(pow(c.x() - b.x(), 2) + pow(c.y() - b.y(), 2) + pow(c.z() - b.z(), 2));

//    //不能构成三角形;
//    if (side[0] + side[1] <= side[2] || side[0] + side[2] <= side[1] || side[1] + side[2] <= side[0]) return area;

//    //利用海伦公式。s=sqr(p*(p-a)(p-b)(p-c));
//    double p = (side[0] + side[1] + side[2]) / 2; //半周长;
//    area = sqrt(p*(p - side[0])*(p - side[1])*(p - side[2]));

//    return area;
//}

////三角面片访问器
//struct TriangleAreaFunctor
//{
//    TriangleAreaFunctor()
//    {
//        sumArea = new double(0.0);
//    }

//    ~TriangleAreaFunctor()
//    {
//        if (sumArea)
//        {
//            delete sumArea;
//            sumArea = nullptr;
//        }
//    }

//    void operator() (const osg::Vec3& v1, const osg::Vec3& v2, const osg::Vec3& v3) const
//    {
//        *sumArea = *sumArea + CalTriangleArea(v1, v2, v3);
//    }

//    double GetSumArea()
//    {
//        return *sumArea;
//    }

//protected:
//    double *sumArea = nullptr;
//};


////
//ref_ptr<Geode> createPolygon()
//{
//    const float wall[6][3] =
//    {
////        {0.0, 0.0, 0.0},
////        {0.0, 10.0, 0.0},
////        {10.0, 10.0, 0.0},
////        {10.0, 0.0, 0.0},

//        { -115.54f, 70.873f, -118.952f},
//        { -111.516f, 70.7189f, -71.8492f },
//        { -88.5345f, 70.8667f, -86.3565f },
//        { -64.9495f, 71.8231f, -53.6525f },
//        { -52.9755f, 69.028f, -129.093f },
//        { -89.2272f, 71.1478f, -105.434f }
//    };

//    //
//    ref_ptr<Geode> geode = new Geode();
//    redPolygon = new osg::Geometry;

//    //
//    osg::ref_ptr<osg::Vec3Array> redVex = new osg::Vec3Array;
//    redPolygon->setVertexArray(redVex);

//    for (int i = 0; i< 6; i++)
//    {
//        redVex->push_back(osg::Vec3(wall[i][0], wall[i][1], wall[i][2]));
//    }

//    redPolygon->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POLYGON, 0, 6));

//    //设置颜色数组
//    osg::ref_ptr<osg::Vec4Array> redColors = new osg::Vec4Array;
//    redColors->push_back(osg::Vec4(1.0, 0.0, 0.0, 0.5));
//    redPolygon->setColorArray(redColors);
//    redColors->setBinding(osg::Array::BIND_PER_PRIMITIVE_SET);

//    //如果需要透明，则加入这个
//    redPolygon->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
//    redPolygon->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);

//    //创建分格化对象(支持凹多边形)
//    osg::ref_ptr<osgUtil::Tessellator> tscx = new osgUtil::Tessellator;
//    //设置分格类型为几何体
//    tscx->setTessellationType(osgUtil::Tessellator::TESS_TYPE_GEOMETRY);
//    //设置只显示轮廓线为false。设置环绕规则，这里不太懂
//    tscx->setWindingType(osgUtil::Tessellator::TESS_WINDING_ODD);
//    //使用分格化
//    tscx->retessellatePolygons(*(redPolygon.get()));

//    geode->addDrawable(redPolygon);

//    return geode;
//}

//int main()
//{
//    //
//    ref_ptr<Group> root = new Group();
//    root->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);		//关闭默认光照
//    root->addChild(createPolygon());

//    //
//    osgViewer::Viewer viewer;
//    viewer.setSceneData(root);
////    viewer.setUpViewInWindow(100, 100, 800, 600);
//    viewer.run();

//    osg::TriangleFunctor<TriangleAreaFunctor> tf;
//    redPolygon->accept(tf);
//    cout << "面积：" << tf.GetSumArea() << endl;

//    return 0;
//}
