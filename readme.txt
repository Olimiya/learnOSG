注意，该项目必须先行配置OSG环境变量，具体设置参见.pro中的设置。
即配置好：OSG_DIR、OSGEARTH_DIR、OSG_3RPARTY_DIR三个库。
配置osg环境参考官方文档。

关于各个文件夹的介绍：
1.earth文件夹：包含了.earth工程文件。在osgearth部分，主要是测试源码起的作用，这部分暂时仅需要最基础的.earth文件即可。
以后的参考来源为osgEarth官方的121个例子。
2.model文件夹：osg部分使用到的模型。其中qt工程拷到qt的build目录下，vs工程拷到OSG_VS/osg/目录下。
3.OSG_BOOK文件夹：《OSG程序设计》一书的全部源码，结合教材中的注释使用。
4.OSG_EARTH：学习OSG_EARTH部分，材料来源osgEarth官方applcation的源码。
5.OSG_VEDIO：学习OSG以及OSG_EARTH部分，材料来源为《osg72讲+osgEarth35讲》视频。
6.OSG_VS：VS下的OSG工程.
7.OSGQt_Romaing：osg+qt图形类库的实现，模拟了操控器漫游的功能。
8.至于share.cpp，其实就是不知道是啥就先把源码放在这里跑跑看。

有疑问的欢迎与本人讨论，本人qq：861921648.
作为本人学习的渐进过程，未来各部分源码会逐渐补充完善。
到了一定程度可能会讲解源码中的知识点，分享到博客上。算是先挖下一个坑吧。
