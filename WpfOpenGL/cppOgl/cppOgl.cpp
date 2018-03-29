#include <Windows.h>
#include <gl\GL.h>
#include "glext.h"
#include "wglext.h"

#include <vector>

namespace
{
	class GLFunc
    {
    public:
        GLFunc()
        {
            glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
            glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
            glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
            glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
            glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
            glDetachShader = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
            glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
            glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
            glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)wglGetProcAddress("glGenFramebuffers");
            glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)wglGetProcAddress("glBindFramebuffer");
            glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)wglGetProcAddress("glGenRenderbuffers");
            glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)wglGetProcAddress("glBindRenderbuffer");
            glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glRenderbufferStorage");
            glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glFramebufferRenderbuffer");
            glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)wglGetProcAddress("glFramebufferTexture");
            glDrawBuffers = (PFNGLDRAWBUFFERSPROC)wglGetProcAddress("glDrawBuffers");
            glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatus");
            glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
            glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
            glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
            glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)wglGetProcAddress("glDeleteFramebuffers");
            glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)wglGetProcAddress("glDeleteRenderbuffers");
            glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
            glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
            glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
            glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
            glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
            glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
            glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress("glEnableVertexAttribArray");
            glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
            glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
            glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
            glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)wglGetProcAddress("glUniformMatrix2fv");
            glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)wglGetProcAddress("glUniformMatrix3fv");
            glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
            glUniform1f = (PFNGLUNIFORM1FPROC)wglGetProcAddress("glUniform1f");
            glUniform2f = (PFNGLUNIFORM2FPROC)wglGetProcAddress("glUniform2f");
            glUniform3f = (PFNGLUNIFORM3FPROC)wglGetProcAddress("glUniform3f");
            glUniform4f = (PFNGLUNIFORM4FPROC)wglGetProcAddress("glUniform4f");
            glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
            glUniform2i = (PFNGLUNIFORM2IPROC)wglGetProcAddress("glUniform2i");
            glUniform3i = (PFNGLUNIFORM3IPROC)wglGetProcAddress("glUniform3i");
            glUniform4i = (PFNGLUNIFORM4IPROC)wglGetProcAddress("glUniform4i");
            glActiveTexture = (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
            glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
            
        }

        PFNGLCREATEPROGRAMPROC glCreateProgram;
        PFNGLCREATESHADERPROC glCreateShader;
        PFNGLSHADERSOURCEPROC glShaderSource;
        PFNGLCOMPILESHADERPROC glCompileShader;
        PFNGLATTACHSHADERPROC glAttachShader;
        PFNGLDETACHSHADERPROC glDetachShader;
        PFNGLLINKPROGRAMPROC glLinkProgram;
        PFNGLUSEPROGRAMPROC glUseProgram;
        PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
        PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
        PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
        PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
        PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
        PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
        PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;
        PFNGLDRAWBUFFERSPROC glDrawBuffers;
        PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
        PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
        PFNGLBINDBUFFERPROC glBindBuffer;
        PFNGLBUFFERDATAPROC glBufferData;
        PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
        PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
        PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
        PFNGLGETSHADERIVPROC glGetShaderiv;
        PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
        PFNGLGETPROGRAMIVPROC glGetProgramiv;
        PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
        PFNGLGENBUFFERSPROC glGenBuffers;
        PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
        PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
        PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
        PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
        PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
        PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
        PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
        PFNGLUNIFORM1FPROC glUniform1f;
        PFNGLUNIFORM2FPROC glUniform2f;
        PFNGLUNIFORM3FPROC glUniform3f;
        PFNGLUNIFORM4FPROC glUniform4f;
        PFNGLUNIFORM1IPROC glUniform1i;
        PFNGLUNIFORM2IPROC glUniform2i;
        PFNGLUNIFORM3IPROC glUniform3i;
        PFNGLUNIFORM4IPROC glUniform4i;
        PFNGLACTIVETEXTUREPROC glActiveTexture;
        PFNGLDELETESHADERPROC glDeleteShader;
    };

    static HGLRC hglrc_;
    static GLFunc* gl_;

    unsigned int points_;
    unsigned int uvs_;
    unsigned int indexes_;
    unsigned int vao_;
    unsigned int calibrationTexture_;

    unsigned int vertexShader_;
    unsigned int fragmentShader_;
    unsigned int programID_;

    struct Vector3
    {
        Vector3(float x, float y, float z)
            :   x_(x), y_(y), z_(z)
        {
        }

        float x_;
        float y_;
        float z_;
    };

    struct Vector2
    {
        Vector2(float x, float y)
            : x_(x), y_(y)
        {
        }

        float x_;
        float y_;
    };

    struct Texture
    {

    };

    unsigned int CompileVertexShader(const std::string& sourceCode)
    {
        GLint result = GL_FALSE;
        GLuint vertexShaderID = gl_->glCreateShader(GL_VERTEX_SHADER);
        const char* src = sourceCode.c_str();
        gl_->glShaderSource(vertexShaderID, 1, &src, NULL);
        gl_->glCompileShader(vertexShaderID);

        gl_->glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
            int infoLogLength;
            gl_->glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
            std::vector<GLchar> error(infoLogLength);
            gl_->glGetShaderInfoLog(vertexShaderID, infoLogLength, &infoLogLength, &error[0]);
            std::string errStr(&error[0], error.size());
            OutputDebugString(errStr.c_str());
            return 0;
        }
        return vertexShaderID;
    }

    unsigned int CompileFragmentShader(const std::string& sourceCode)
    {
        GLint result = GL_FALSE;
        GLuint fragmentShaderID = gl_->glCreateShader(GL_FRAGMENT_SHADER);
        const char* src = sourceCode.c_str();
        gl_->glShaderSource(fragmentShaderID, 1, &src, NULL);
        gl_->glCompileShader(fragmentShaderID);

        gl_->glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
        if (result == GL_FALSE)
        {
            int infoLogLength;
            gl_->glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
            std::vector<GLchar> error(infoLogLength);
            gl_->glGetShaderInfoLog(fragmentShaderID, infoLogLength, &infoLogLength, &error[0]);
            std::string errStr(&error[0], error.size());
            OutputDebugString(errStr.c_str());
            return 0;
        }
        return fragmentShaderID;
    }

    unsigned int LinkShaderProgram(unsigned int vertexShader, unsigned int fragmentShader)
    {
        // attempt to link the program...
        GLint result = GL_FALSE;

        unsigned int programID = gl_->glCreateProgram();
        gl_->glAttachShader(programID, vertexShader);
        gl_->glAttachShader(programID, fragmentShader);

        gl_->glLinkProgram(programID);
        gl_->glGetProgramiv(programID, GL_LINK_STATUS, &result);
        if (result == GL_FALSE)
        {
            int InfoLogLength;
            gl_->glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &InfoLogLength);
            std::vector<GLchar> error(InfoLogLength);
            gl_->glGetProgramInfoLog(programID, InfoLogLength, &InfoLogLength, &error[0]);
            std::string errStr(&error[0], error.size());
            OutputDebugString(errStr.c_str());
            return 0;
        }

        gl_->glDetachShader(programID, vertexShader);
        gl_->glDetachShader(programID, fragmentShader);

        return programID;
    }

    void SetUniform(const std::string& name, unsigned int ID)
    {
        int location = gl_->glGetUniformLocation(programID_, name.c_str());
        if (location < 0)
            OutputDebugString("Unable to find uniform location :(");
        else
            gl_->glUniform1i(location, ID);
    }

}

extern "C" __declspec(dllexport) int OpenGLInit(void* hdc)
{
    // We need to create a context or get an existing one that fits the supplied context.
    // first check we have a valid device context
    if (!hdc)
        return 1;

    HDC hDC = static_cast<HDC>(hdc);
    if (!hDC)
        return 2;

    // we then need to get a valid DC...
    PIXELFORMATDESCRIPTOR pfd;
    memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 32;
    pfd.cStencilBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int nPixelFormat = ChoosePixelFormat(hDC, &pfd);

    if (nPixelFormat == 0)
        return 3;

    if (!SetPixelFormat(hDC, nPixelFormat, &pfd))
        return 4;

    HGLRC tempContext = wglCreateContext(hDC);
    wglMakeCurrent(hDC, tempContext);

    int attribs[] =
    {
        WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
        WGL_CONTEXT_MINOR_VERSION_ARB, 1,
        WGL_CONTEXT_FLAGS_ARB, 0,
        0
    };

    PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
    if (wglCreateContextAttribsARB)
    {
        hglrc_ = wglCreateContextAttribsARB(hDC, 0, attribs);
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(tempContext);
        if (!wglMakeCurrent(hDC, hglrc_))
            return 5;
    }

    // Initialise the functions..
    gl_ = new GLFunc();

    // Cache the geometry for a quad
    float v = 1.0f;

    std::vector<Vector3> quadPoints = std::initializer_list<Vector3>({
        Vector3(-v, -v, 0),
        Vector3(v, -v, 0),
        Vector3(v, v, 0),
        Vector3(-v, v, 0)
    });


    std::vector<Vector2> quadUVs = std::initializer_list<Vector2>({
        Vector2(0, 0),
        Vector2(1.0f, 0),
        Vector2(1.0f, 1.0f),
        Vector2(0, 1.0f)
    });

    std::vector<unsigned int> quadIndexes = std::initializer_list<unsigned int>({
        0, 1, 2, 2, 3, 0
    });

    gl_->glGenVertexArrays(1, &vao_);
    gl_->glBindVertexArray(vao_);

    // Cache the points...
    gl_->glGenBuffers(1, &points_);
    gl_->glBindBuffer(GL_ARRAY_BUFFER, points_);
    gl_->glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * quadPoints.size(), &quadPoints[0].x_, GL_STATIC_DRAW);
    gl_->glEnableVertexAttribArray(0);
    gl_->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // Cache the UVs...
    gl_->glGenBuffers(1, &uvs_);
    gl_->glBindBuffer(GL_ARRAY_BUFFER, uvs_);
    gl_->glBufferData(GL_ARRAY_BUFFER, sizeof(float) * quadUVs.size() * 2, &quadUVs[0].x_, GL_STATIC_DRAW);
    gl_->glEnableVertexAttribArray(1);
    gl_->glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    // Cache the indexes...
    gl_->glGenBuffers(1, &indexes_);
    gl_->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexes_);
    gl_->glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * quadIndexes.size(), &quadIndexes[0], GL_STATIC_DRAW);

    gl_->glBindBuffer(GL_ARRAY_BUFFER, NULL);
    gl_->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
    gl_->glBindVertexArray(NULL);
    
    // Load the texture...


    // Compile the shaders
    const char* fragmentSource = R"(
    #version 410 core

    uniform sampler2D quadTexture;
    in vec2 UV;
    out vec3 COLOUR;

    void main()
    {
        COLOUR = vec3(UV.st, 0);
    }
    )";

    const char* vertexSource = R"(
    #version 410 core

    in vec3 inP;
    in vec2 inUV;
    out vec2 UV;

    void main()
    {
	    gl_Position = vec4(inP, 1.0);
	    UV = inUV;
    }
    )";

    vertexShader_ = CompileVertexShader(vertexSource);
    fragmentShader_ = CompileFragmentShader(fragmentSource);
    programID_ = LinkShaderProgram(vertexShader_, fragmentShader_);

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

    gl_->glUseProgram(programID_);
    gl_->glBindVertexArray(vao_);
    gl_->glBindBuffer(GL_ARRAY_BUFFER, uvs_);
    gl_->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexes_);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    gl_->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
    gl_->glBindVertexArray(NULL);
    gl_->glUseProgram(NULL);

	SwapBuffers(validHDC);
}

extern "C" __declspec(dllexport) void OpenGLResize(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(width / static_cast<float>(height), -width / static_cast<float>(height), -1.0f, 1.0f, 0.1f, 100.0f);
}
