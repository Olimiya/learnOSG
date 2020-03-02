//#include <QDebug>
//#include <QMap>
//#include <osg/Referenced>
//#include <osg/ref_ptr>
//#include <osg/observer_ptr>
//#include <iostream>
//#include <vld.h>

//class A : public osg::Referenced
//{
//public:
//    A():a(new double[5])
//    {
//        a[0] = 1;
//        a[1] = 2;
//    }
//    A(const A &other)
//    {
//        a = new double[5];
//        for(int i = 0; i < 5; i++)
//            a[i] = other.a[i];
//    }
//    A& operator=(const A &other)
//    {
//        for(int i = 0; i < 5; i++)
//            a[i] = other.a[i];
//        return *this;
//    }
//    ~A()
//    {
//        delete []a;
//        qDebug() << "delete";
//    }
//    double *a;
//};

//class B
//{
//public:
//    osg::observer_ptr<A> a;
//};

//int main()
//{
//    osg::ref_ptr<A> b = new A;
//    B aa;
//    aa.a = b.get();
//    b = nullptr;
////    a.clear();

//    qDebug() << "main";
//}
