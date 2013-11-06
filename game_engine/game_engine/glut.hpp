#pragma once

#include <windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <gl\GLAux.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glaux.lib")
#pragma comment(lib, "glut32")

#include <map>




class Window {
    friend class Menu;
private:
    int id;
    static std::map<int, Window*> wins;

    static void displayFuncSelect() {
        wins[glutGetWindow()]->displayFunc();
    }

    static void reshapeFuncSelect(int width, int height) {
        wins[glutGetWindow()]->reshapeFunc(width, height);
    }

    static void keyboardFuncSelect(unsigned char key, int x, int y) {
        wins[glutGetWindow()]->keyboardFunc(key, x, y);
    }

    static void specialFuncSelect(int key, int x, int y) {
        wins[glutGetWindow()]->specialFunc(key, x, y);
    }

    static void mouseFuncSelect(int button, int state, int x, int y) {
        wins[glutGetWindow()]->mouseFunc(button, state, x, y);
    }

    static void motionFuncSelect(int x, int y) {
        wins[glutGetWindow()]->motionFunc(x, y);
    }

    static void passiveMotionFuncSelect(int x, int y) {
        wins[glutGetWindow()]->passiveMotionFunc(x, y);
    }



public:
    Window(const char* title = "", int width = 300, int height = 300, int x = -1, int y = -1) {
		
		InitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowSize(width, height);
        glutInitWindowPosition(x, y);
        id = glutCreateWindow(title);

        wins[id] = this;

        glutDisplayFunc(Window::displayFuncSelect);
        glutKeyboardFunc(Window::keyboardFuncSelect);
        glutSpecialFunc(Window::specialFuncSelect);
        glutMouseFunc(Window::mouseFuncSelect);
        glutReshapeFunc(Window::reshapeFuncSelect);
        glutMotionFunc(Window::motionFuncSelect);
        glutPassiveMotionFunc(Window::passiveMotionFuncSelect);
    }

    void setTitle(const char* title) {
        glutSetWindow(id);
        glutSetWindowTitle(title);
    }

    void reshape(int width, int height) {
        glutSetWindow(id);
        glutReshapeWindow(width, height);
    }

    void show() {
        glutSetWindow(id);
        glutShowWindow();
    }

    void hide() {
        glutSetWindow(id);
        glutHideWindow();
    }

    void iconify() {
        glutSetWindow(id);
        glutIconifyWindow();
    }

    void swapBuffers() {
        glutSetWindow(id);
        glutSwapBuffers();
    }

    void postRedisplay() {
        glutSetWindow(id);
        glutPostRedisplay();
    }

    void setCursor(int cursor) {
        glutSetWindow(id);
        glutSetCursor(cursor);
    }


    virtual void displayFunc() = 0;

    virtual void keyboardFunc(unsigned char key, int x, int y) {
        // disable events if not overridden
        glutSetWindow(id);
        glutKeyboardFunc(NULL);
    }

    virtual void specialFunc(int key, int x, int y) {
        // disable events if not overridden
        glutSetWindow(id);
        glutSpecialFunc(NULL);
    }

    virtual void mouseFunc(int button, int state, int x, int y) {
        // disable events if not overridden
        glutSetWindow(id);
        glutMouseFunc(NULL);
    }

    virtual void reshapeFunc(int width, int height) {
        // disable events if not overridden
        glutSetWindow(id);
        glutReshapeFunc(NULL);
    }

    virtual void motionFunc(int x, int y) {
        // disable events if not overridden
        glutSetWindow(id);
        glutMotionFunc(NULL);
    }

    virtual void passiveMotionFunc(int x, int y) {
        // disable events if not overridden
        glutSetWindow(id);
        glutPassiveMotionFunc(NULL);
    }

	void Init(int argc, char* argv[]) {
    glutInit(&argc, argv);
}

void InitDisplayMode(const unsigned int displayMode) {
    glutInitDisplayMode(displayMode);
}

void MainLoop() {
    glutMainLoop();
}


void IdleFunc(void(*callback)(void)) {
    glutIdleFunc(callback);
}


    ~Window() {
        glutDestroyWindow(id);
    }
};

class Menu {
private:
    int id;

    static std::map<int, Menu*> menus;

    static void menuFunSelect(int value) {
        menus[glutGetMenu()]->selected(value);
    }

public:
    Menu(Window& window) {
        glutSetWindow(window.id);
        id = glutCreateMenu(Menu::menuFunSelect);
        menus[id] = this;
    }

    void addEntry(const char* label, int value) {
        glutSetMenu(id);
        glutAddMenuEntry(label, value);
    }

    void attach(int button) {
        glutSetMenu(id);
        glutAttachMenu(button);
    }

    virtual void selected(int value) = 0;
};




