#include "frame_timer.hpp"
#include "view.hpp"
#include "scene.hpp"

int main()
{
    auto view = View{};
    view.addWidget<Scene>();

    auto frameTimer = FrameTimer{60};
    while (view.isAlive()) {
        view.processInput();

        auto framesPassed = frameTimer();
        if (framesPassed > 0) {
            view.draw();
        }
    }
}
