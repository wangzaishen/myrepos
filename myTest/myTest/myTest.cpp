// myTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<gl/glut.h>

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>

int main(int argc, char **argv)
{
	osg::ref_ptr<osg::LightSource> ls = new osg::LightSource();
	osg::ref_ptr< osg::Light> lt = new osg::Light;
	lt->setLightNum(0);
	lt->setPosition(osg::Vec4(1.0, -1.0, -1.0, 0));
	lt->setAmbient(osg::Vec4(0.2, 0.2, 0.2, 1.0));
	lt->setDiffuse(osg::Vec4(1.0, 1.0, 1.0, 1.0));
	osgViewer::Viewer viewer;
	viewer.getCamera()->setClearColor(osg::Vec4(0, 1, 1, 1));
	viewer.setSceneData(osgDB::readNodeFile("glider.osg"));
	viewer.setUpViewInWindow(300, 100, 800, 600);
	viewer.setLight(lt);
	return	viewer.run();


}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
