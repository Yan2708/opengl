#include "camera.h"

Camera::Camera(glm::vec3 position, float width, float height, bool orthographic, float fov, float far):
position(position), width(width), height(height), orthographic(orthographic), fov(fov), far(far)
{
    target = glm::vec3(0);
    camFront = glm::vec3(0,0,-1);
    cameraSpeed = 8;
    yaw = -90;
    sensitivity = 0.3;
}

void Camera::pointAt(glm::vec3 pos)
{
    target = pos;
}

glm::mat4 Camera::getView()
{
    setCameraDirection();
    glm::vec3 upv = up();
    glm::vec3 rightv = right();
    glm::mat4 rotation = glm::mat4(1);
    rotation[0][0] = rightv.x;
    rotation[0][1] = upv.x;
    rotation[0][2] = camDir.x;
    rotation[1][0] = rightv.y;
    rotation[1][1] = upv.y;
    rotation[1][2] = camDir.y;
    rotation[2][0] = rightv.z;
    rotation[2][1] = upv.z;
    rotation[2][2] = camDir.z;
    glm::mat4 translation = glm::mat4(1);
    translation[3][0]=-position.x;
    translation[3][1]=-position.y;
    translation[3][2]=-position.z;
    return glm::lookAt(position, position+camFront, glm::vec3(0.0f,1.0f,0.0f));
    return rotation * translation;
}

glm::mat4 Camera::getProjection()
{    
    glm::mat4 projection;
    if(orthographic){
        float w2 = width/2, h2 = height/2;
        return glm::ortho(-w2,w2,-h2,h2,0.1f,far);
    }
    return glm::perspective(glm::radians(fov), width / height, 0.1f, 100.0f);
}

glm::vec3 Camera::up()
{
    return glm::cross(camDir, right());
}

void Camera::move(std::map<int, bool> inputs, glm::vec2 mouseOffset, float delta)
{
    float speed = delta * cameraSpeed;
    if(inputs[GLFW_KEY_W]) position += speed*camFront;
    if(inputs[GLFW_KEY_S]) position -= speed*camFront;
    if(inputs[GLFW_KEY_A]) position -= glm::normalize(glm::cross(camFront, up())) * speed;
    if(inputs[GLFW_KEY_D]) position += glm::normalize(glm::cross(camFront, up())) * speed;
    if(inputs[GLFW_KEY_SPACE]) position.y += speed;
    if(inputs[GLFW_KEY_LEFT_SHIFT]) position.y -= speed;
    
    
    yaw+=mouseOffset.x*sensitivity;
    pitch+=mouseOffset.y*sensitivity;
    if(pitch > 89.0f) pitch =  89.0f;
    if(pitch < -89.0f) pitch = -89.0f;
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));  
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    camFront = glm::normalize(direction);
}

void Camera::setCameraDirection()
{
    camDir = glm::normalize(position - camFront);
}

glm::vec3 Camera::right()
{
    glm::vec3 wup = glm::vec3(0.0f, 1.0f, 0.0f); 
    return glm::normalize(glm::cross(wup, camDir));
}
