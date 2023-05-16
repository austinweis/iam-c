#include "camera.h"

Rectangle GetCameraBounds(Camera2D camera, unsigned int width, unsigned int height, int buffer)
{
    float w = width / camera.zoom;
    float h = height / camera.zoom;
    float x = camera.target.x - w / 2.0f;
    float y = camera.target.y - h / 2.0f;

    return (Rectangle){x-buffer, y-buffer, w+buffer, h+buffer};
}