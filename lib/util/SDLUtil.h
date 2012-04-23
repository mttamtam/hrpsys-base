#include "ThreadedObject.h"

class GLsceneBase;
class ThreadedObject;
class LogManagerBase;

class SDLwindow : public ThreadedObject
{
public:
    SDLwindow(GLsceneBase *i_scene, LogManagerBase *i_lm, 
              ThreadedObject *i_throbj=NULL);
    ~SDLwindow();
    bool init();
    bool processEvents();
    void draw();
    void swapBuffers();
    bool oneStep();
private:
    double sliderRatio(double x);
    GLsceneBase *scene;
    LogManagerBase *log;
    ThreadedObject *throbj;
    int width, height;
    double aspect;
    double pan, tilt, radius;
    bool isShiftPressed, isControlPressed;
    double xCenter, yCenter, zCenter;
    bool showingHelp, buttonPressedInSliderArea;
    std::vector<std::string> helpcommand, instructions;
};

