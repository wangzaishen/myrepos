// grab.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <gl/glut.h>
#include<stdlib.h>
#include<stdio.h>

GLint WIDTH = 400;
GLint HEIGHT = 400;



const GLint BMP_Header_length = 54;

void grab()
{
	FILE* pDummyFile;
	FILE* pWritingFile;
	GLubyte* pPixelData;
	GLubyte BMP_Header[BMP_Header_length];
	GLint i, j;
	GLint PixelDataLength;

	i = WIDTH * 3;
	while(i%4 != 0)
	{
		++i;
	}

	PixelDataLength = i * HEIGHT;

	pPixelData = (GLubyte*)malloc(PixelDataLength);
	if (pPixelData == 0)
	{
		exit(0);
	}

	fopen_s(&pDummyFile,"dummy.bmp", "rb");
	if (pDummyFile == 0)
	{
		exit(0);
	}

	fopen_s(&pWritingFile,"grab.bmp", "wb");
	if (pWritingFile == 0)
	{
		exit(0);
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	glReadPixels(0, 0, WIDTH, HEIGHT, GL_BGR_EXT, GL_UNSIGNED_BYTE, pPixelData);

	fread(BMP_Header, sizeof(BMP_Header), 1, pDummyFile);
	fwrite(BMP_Header, sizeof(BMP_Header), 1, pWritingFile);
	fseek(pWritingFile, 0x0012, SEEK_SET);

	i = WIDTH;
	j = HEIGHT;
	fwrite(&i, sizeof(i), 1, pWritingFile);
	fwrite(&j, sizeof(j), 1, pWritingFile);

	fseek(pWritingFile, 0, SEEK_END);
	fwrite(pPixelData, PixelDataLength, 1, pWritingFile);

	fclose(pDummyFile);
	fclose(pWritingFile);
	free(pPixelData);





}

GLint mx = 0;
GLint my = 0;
GLint disx = 0;
GLint disy = 0;

void display()
{ 
	GLfloat dx = (GLfloat)mx / (GLfloat)WIDTH;
	GLfloat dy = (GLfloat)my / (GLfloat)HEIGHT;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.0f + dx, 0.0f + dy);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(1.0f + dx, 0.0f + dy);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0.5f + dx, 1.0f + dy);
	glEnd();


	glPixelZoom(-0.5f, -0.5f);
	glRasterPos2i(1, 1);
	glCopyPixels(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT / 2, GL_COLOR);

	glutSwapBuffers();
	grab();

}



void myMouse(GLint button, GLint state, GLint x, GLint y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:

		if (state = GLUT_DOWN)
		{
			mx = x;
			mx = y;

		}
		if (state = GLUT_UP)
		{
			disx = x - mx;
			disy = y - my;

			mx = x;
			my = y;

			glutPostRedisplay();

		}

		break;

	}

}

int main(int argc, char* argv[])
{
	///grab();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);

	glutCreateWindow("show");
	glutDisplayFunc(&display);
	glutMouseFunc(&myMouse);

	glutMainLoop();
	
    std::cout << "Hello World!\n"; 

	return 0;
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
