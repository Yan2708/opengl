#ifndef CAMERA_H
#define CAMERA_H
#include "common.h"
class Camera
{

public:
    Camera(glm::vec3 position, float width, float height, bool orthographic, float fov, float far);
    ~Camera();

    bool orthographic;
    glm::vec3 position, target;
    float fov;
    
    void pointAt(glm::vec3 pos);
    
    glm::mat4 getView();
    glm::mat4 getProjection();
    glm::vec3 up();
    void move(std::map<int, bool> inputs, glm::vec2 mouseOffset, float delta);
private:
    float width, height, far, cameraSpeed, yaw, pitch, sensitivity;
    glm::vec3 camDir, camFront;
    void setCameraDirection();
    glm::vec3 right();
};
#endif