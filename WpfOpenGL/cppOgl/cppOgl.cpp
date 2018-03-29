#include <Windows.h>
#include <gl\GL.h>

namespace
{
	static HGLRC hglrc_;
}

extern "C" __declspec(dllexport) int OpenGLInit(void* hdc)
{
	HDC hDC = static_cast<HDC>(hdc);
	if (!hDC)
		return 1;

	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 0;
	pfd.cDepthBits = 0;
	pfd.iLayerType = PFD_MAIN_PLANE;

	int nPixelFormat = ChoosePixelFormat(hDC, &pfd);
	if (nPixelFormat == 0)
		return 2;

	if (!SetPixelFormat(hDC, nPixelFormat, &pfd))
		return 3;

	hglrc_ = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hglrc_);

	return 0;
}

extern "C" __declspec(dllexport) void OpenGLKill()
{
	wglDeleteContext(hglrc_);
}

extern "C" __declspec(dllexport) void OpenGLDraw(void* hdc, float rotation)
{
	HDC validHDC = static_cast<HDC>(hdc);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(rotation, 0, 0, 1.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0, 0);
	glVertex3f(-0.5f, -0.5f, -1.0f);
	glColor3f(0, 1.0f, 0);
	glVertex3f(0, 0.5f, -1.0f);
	glColor3f(0, 0, 1.0f);
	glVertex3f(0.5f, -0.5f, -1.0f);
	glEnd();

	SwapBuffers(validHDC);
}

extern "C" __declspec(dllexport) void OpenGLResize(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(width / static_cast<float>(height), -width / static_cast<float>(height), -1.0f, 1.0f, 0.1f, 100.0f);
}
