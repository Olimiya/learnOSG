#-------------------------------------------------
#
# Project created by QtCreator 2020-01-03T15:33:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = learnOSG
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += \
                $$(OSG_3RPARTY_DIR)/include \
                $$(OSG_DIR)/include \
                $$(OSGEARTH_DIR)/include

CONFIG(debug, debug|release){
LIBS += \
    -L$$(OSG_3RPARTY_DIR)/lib \
        -lfreetyped -lgdal_i -lgeos_cd -lgeosd -lglut32d -ljpeg -llibcurl_imp -llibgeosd \
        -llibpng16_staticd -llibpng16d -logr -lproj_4_9_d -ltiffd -lzlibd -lzlibstaticd \
    -L$$(OSGEARTH_DIR)/lib \
        -losgEarthd -losgEarthAnnotationd -losgEarthFeaturesd -losgEarthQt5d -losgEarthSplatd -losgEarthSymbologyd -losgEarthUtild \
    -L$$(OSG_DIR)/lib \
        -lOpenThreadsd -losgd -lOsgAnimationd -losgDBd -losgFXd -losgGAd -losgManipulatord -losgParticled -losgPresentationd \
        -losgQt5d -losgShadowd -losgSimd -losgTerraind -losgTextd -losgUId -losgUtild -losgViewerd -losgVolumed -losgWidgetd
} else {
LIBS += \
    -L$$(OSG_3RPARTY_DIR)/lib \
        -lfreetype -lgdal_i -lgeos -lgeos_c -lglut32 -ljpeg -llibcurl_imp -llibgeos \
        -llibpng16 -llibpng16_static -logr -lproj_4_9 -ltiff -lzlib -lzlibstatic \
    -L$$(OSGEARTH_DIR)/lib \
        -losgEarth -losgEarthAnnotation -losgEarthFeatures -losgEarthQt5 -losgEarthSplat -losgEarthSymbology -losgEarthUtil \
    -L$$(OSG_DIR)/lib \
        -lOpenThreads -losg -lOsgAnimation -losgDB -losgFX -losgGA -losgManipulator -losgParticle -losgPresentation \
        -losgQt5 -losgShadow -losgSim -losgTerrain -losgText -losgUI -losgUtil -losgViewer -losgVolume -losgWidget
}

SOURCES += \
    OSG_Book/10-1showtext.cpp \
    OSG_Book/2-1helloworld.cpp \
    OSG_Book/2-2defaultstateset.cpp \
    OSG_Book/2-3defaultmanipulator.cpp \
    OSG_Book/2-5readcommandlines.cpp \
    OSG_Book/3-1loadmodel.cpp \
    OSG_Book/3-2hidemodel.cpp \
    OSG_Book/3-3addswtich.cpp \
    OSG_Book/3-4modeltransformation.cpp \
    OSG_Book/4-1drawquad.cpp \
    OSG_Book/4-2setlinewidth.cpp \
    OSG_Book/4-3osgshape.cpp \
    OSG_Book/5-1eventhandler.cpp \
    OSG_Book/5-2pick.cpp \
    OSG_Book/6-1definedmanipulator.cpp \
    OSG_Book/6-2animationbypath.cpp \
    OSG_Book/6-3pathromaing.cpp \
    OSG_Book/7-1callback.cpp \
    OSG_Book/7-2definedcallback.cpp \
    OSG_Book/7-3nodevisitor.cpp \
    OSG_Book/8-1defaultparticle.cpp \
    OSG_Book/8-2definedparticlesystem.cpp \
    OSG_Book/9-1simpleviewport-known.cpp \
    OSG_Book/9-2multipleviewport.cpp \
    OSG_Book/9-3compressmodel.cpp \
    OSG_Book/9-4importer.cpp \
    OSG_Book/conduit.cpp \
    main.cpp \
    share.cpp \
    OSG_Book/manipulator.cpp \
    OSGQt_Romaing/map_osg_baseviewer.cpp \
    OSGQt_Romaing/map_osg_viewcontroller.cpp \
    OSGQt_Romaing/osg_romaingwindow.cpp \
    OSGQt_Romaing/pickhandler.cpp \
    OSG_Vedio/blur.cpp \
    OSG_EARTH/osgearth_drawable.cpp \
    OSG_EARTH/osgearth_annotation.cpp \
    OSG_EARTH/osgearth_graticule.cpp \
    OSG_EARTH/osgearth_geodetic_graticule.cpp \
    OSG_Book/q-text.cpp \
    share2.cpp \
    OSG_Book/q-texture.cpp \
    OSG_EARTH/osgearth_imageoverlay.cpp \
    OSG_EARTH/osgearth_manipulator.cpp \
    OSG/createconcavepolygon.cpp \
    OSG_EARTH/osgearth_controls.cpp \
    OSG_EARTH/osgearth_pick.cpp \
    OSG_EARTH/osgearth_addlayer.cpp

HEADERS += \
    OSG_Book/conduit.h \
    OSG_Book/manipulator.h \
    OSGQt_Romaing/map_osg_baseviewer.h \
    OSGQt_Romaing/map_osg_viewcontroller.h \
    OSGQt_Romaing/osg_romaingwindow.h \
    OSGQt_Romaing/pickhandler.h \
    OSG_Vedio/common.h

FORMS += \
    OSGQt_Romaing/osg_romaingwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32-msvc* {
    QMAKE_CXXFLAGS *=  /wd"4100"
    contains (QMAKE_CXXFLAGS_WARN_ON, -w34100) : QMAKE_CXXFLAGS_WARN_ON -= -w34100
}
win32-msvc* {
    QMAKE_CXXFLAGS *=  /wd"4819"
}



