#include <sstream>
#include <Windows.h>
#include <osg/Image>
#include <osg/Group>
#include <osg/Notify>
#include <osg/Geode>
#include <osg/Shape>
#include <osg/ShapeDrawable>

#include <osgDB/FileNameUtils>
#include <osgDB/FileUtils>
#include <osgDB/fstream>
#include <osgDB/Registry>
#include <osgDB/Input>
#include <osgDB/Output>
#include <iostream>

#ifdef _DEBUG
#pragma comment(lib, "osgd.lib")
#pragma comment(lib, "osgDBd.lib")
#pragma comment(lib, "osgViewerd.lib")
#pragma comment(lib, "OpenThreadsd.lib")
#pragma comment(lib, "osgGAd.lib")
#pragma comment(lib, "osgUtild.lib")
#else
#pragma comment(lib, "osg.lib")
#pragma comment(lib, "osgDB.lib")
#pragma comment(lib, "osgViewer.lib")
#pragma comment(lib, "OpenThreads.lib")
#pragma comment(lib, "osgGA.lib")
#pragma comment(lib, "osgUtil.lib")
#endif

using namespace osg;
using namespace osgDB;

class FSReaderWriter : public ReaderWriter
{
public:

	FSReaderWriter()
	{
		supportsExtension("mfs", "FreeSouth 's format");
	}

	virtual const char* className() const { return "FSReaderWriter"; }

	virtual ReadResult readNode(const std::string& file, const Options* opt) const
	{
		std::string ext = osgDB::getLowerCaseFileExtension(file);

		if (!acceptsExtension(ext)) return ReadResult::FILE_NOT_HANDLED;

		std::string fileName = osgDB::findDataFile(file, opt);
		if (fileName.empty()) return ReadResult::FILE_NOT_FOUND;

		osgDB::ifstream fin(fileName.c_str());
		if (fin)
		{
			return readNode(fin, opt);
		}
		return 0L;

	}

	virtual ReadResult readNode(std::istream& fin, const Options* options) const
	{
		Input fr;
		fr.attach(&fin);

		osg::ref_ptr<osg::Geode> gnode = new osg::Geode;
		osg::Vec3 center;
		float radius;

		while (!fr.eof())
		{
			if (fr.matchSequence("%f%f%f%f"))
			{
				fr.readSequence(center);
				fr.readSequence(radius);
				std::cout << "Center is :" << center.x() << "  " << center.y() << "  " << center.z() << "  " << std::endl;
				std::cout << "Radius is :" << radius << std::endl;
				gnode->addDrawable(new osg::ShapeDrawable(new osg::Sphere(center, radius)));
			}
			else
			{
				std::cout << "fr is NULL" << std::endl;
				++fr;
			}
		}

		return gnode;

	}

	virtual WriteResult writeNode(const Node& node, const std::string& fileName, const osgDB::ReaderWriter::Options* options) const
	{
		//std::string ext = getFileExtension(fileName);
		//if (!acceptsExtension(ext)) return WriteResult::FILE_NOT_HANDLED;
		//const osg::Geode::DrawableList& dl = node.asGeode()->getDrawableList();
		//osg::Vec3 vc;

		//osgDB::Output fout(fileName.c_str());
		//if (fout)
		//{
		//	for (osg::Geode::DrawableList::const_iterator iter = dl.begin(); iter != dl.end(); iter++)
		//	{
		//		vc = (dynamic_cast<osg::Sphere*>(iter->get()->getShape()))->getCenter();
		//		fout.setOptions(options);

		//		fout.imbue(std::locale::classic());
		//		fout << vc.x() << " " << vc.y() << " " << vc.z() << " " << (dynamic_cast<osg::Sphere*>(iter->get()->getShape()))->getRadius() << std::endl;
		//		//fout.writeObject(node);


		//	}
		//	fout.close();
		//	return WriteResult::FILE_SAVED;
		//}
		return WriteResult("Unable to open file for output");
	}


};

// now register with Registry to instantiate the above
// reader/writer.
REGISTER_OSGPLUGIN(mfs, FSReaderWriter)
