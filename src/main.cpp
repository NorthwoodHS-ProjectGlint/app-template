
#include <glint/glint.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

extern "C" void glattach(void* ctx) {

    glAttach(ctx);


}


extern "C" void app_setup() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

extern "C" int app_present() {
    glPresent();
    return glRunning();
}

extern "C" int app_cycle() {
    if (hidIsButtonPressed(GLFW_KEY_ESCAPE)) {
        return 2; // Pause to home screen
    }
    
    /*
    if (game_over) {
        return 1; // Exit application
    }
    */
    
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    return 0; // Continue running
}

extern "C" void app_shutdown() {

}