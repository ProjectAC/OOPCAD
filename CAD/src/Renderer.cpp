#include "stdafx.h"

#include "../include/Renderer.h"
#include <GL/freeglut.h>

namespace ACCAD
{
    void Renderer::init(HWND hWnd)
    {
        PIXELFORMATDESCRIPTOR pfd;
        int iFormat;

        this->hWnd = hWnd;

        /* get the device context (DC) */
        hDC = GetDC(hWnd);

        /* set the pixel format for the DC */
        ZeroMemory(&pfd, sizeof(pfd));
        pfd.nSize = sizeof(pfd);
        pfd.nVersion = 1;
        pfd.dwFlags = PFD_DRAW_TO_WINDOW |
            PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
        pfd.iPixelType = PFD_TYPE_RGBA;
        pfd.cColorBits = 24;
        pfd.cDepthBits = 16;
        pfd.iLayerType = PFD_MAIN_PLANE;
        iFormat = ChoosePixelFormat(hDC, &pfd);
        SetPixelFormat(hDC, iFormat, &pfd);

        /* create and enable the render context (RC) */
        hRC = wglCreateContext(hDC);
        wglMakeCurrent(hDC, hRC);
    }

    void Renderer::flush()
    {
        glFlush();
        SwapBuffers(hDC);
    }

    void Renderer::render(const Vec2 &center, float theta, const Color &cborder, const Color &cinner, const std::vector<Vec2> &vertices, bool show)
    {
        glPushMatrix();

        glTranslatef(center.x, center.y, 0);
        glRotatef(theta / PI * 180, 0, 0, 1);
        
        if (cinner.a)
        {
            glColor4ub(cinner.r, cinner.g, cinner.b, cinner.a);
            glBegin(GL_POLYGON);
            for (auto &v : vertices)
                glVertex2f(v.x, v.y);
            glEnd();
        }

        glColor4ub(cborder.r, cborder.g, cborder.b, cborder.a);
        glBegin(GL_LINE_LOOP);
        for (auto &v : vertices)
            glVertex2f(v.x, v.y);
        glEnd();

        if (show)
        {
            glColor4ub(255, 0, 0, 255);
            for (auto &v : vertices)
            {
                glBegin(GL_POLYGON);
                glVertex2f(v.x + 0.1, v.y);
                glVertex2f(v.x, v.y + 0.1);
                glVertex2f(v.x - 0.1, v.y);
                glVertex2f(v.x, v.y - 0.1);
                glEnd();
            }
        }

        glPopMatrix();
    }
}