//Just a dummy visuals.cpp made for checking, (Just have a bar graph visualization)

#include "Visuals.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

Visualization::Visualization(int windowWidth, int windowHeight)
    : windowWidth(windowWidth), windowHeight(windowHeight), window(nullptr) {}

Visualization::~Visualization() {
    cleanup();
}

bool Visualization::initialize() {
    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW." << endl;
        return false;
    }

    window = glfwCreateWindow(windowWidth, windowHeight, "Audio Visualization", nullptr, nullptr);
    if (!window) {
        cerr << "Failed to create GLFW window." << endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        cerr << "Failed to initialize GLEW." << endl;
        return false;
    }

    // Set up perspective projection
    glMatrixMode(GL_PROJECTION);  // Switch to projection matrix
    glLoadIdentity();  // Reset projection matrix

    // Set the perspective (FOV, aspect ratio, near, far)
    gluPerspective(45.0f, (float)windowWidth / (float)windowHeight, 0.1f, 100.0f);  

    glMatrixMode(GL_MODELVIEW);  // Switch back to modelview matrix for drawing
    glEnable(GL_DEPTH_TEST); // Enable depth testing

    return true;
}

void Visualization::render(const vector<float>& fftMagnitudes) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);  // Rotate around Y-axis (0, 1, 0)

    size_t numBars = fftMagnitudes.size();
    float barWidth = 2.0f / numBars;

    for (size_t i = 0; i < numBars; ++i) {
        float magnitude = fftMagnitudes[i];
        float barHeight = magnitude * 0.8f;
        float barDepth = barWidth;

        float x = -1.0f + i * barWidth;
        float y = -1.0f;

        glBegin(GL_QUADS);

         // Front face (width x height)
        glVertex3f(x, y, 0.0f);                  // left bottom
        glVertex3f(x + barWidth, y, 0.0f);       // right bottom
        glVertex3f(x + barWidth, y + barHeight, 0.0f); // right top
        glVertex3f(x, y + barHeight, 0.0f);      // left top

        // Back face (same size, shifted in depth)
        glVertex3f(x, y, -barDepth);                  // left bottom
        glVertex3f(x + barWidth, y, -barDepth);       // right bottom
        glVertex3f(x + barWidth, y + barHeight, -barDepth); // right top
        glVertex3f(x, y + barHeight, -barDepth);      // left top

        // Connecting sides between front and back faces (4 faces)
        glVertex3f(x, y, 0.0f);                  // left bottom
        glVertex3f(x, y, -barDepth);             // left bottom back
        glVertex3f(x, y + barHeight, -barDepth); // left top back
        glVertex3f(x, y + barHeight, 0.0f);     // left top

        glVertex3f(x + barWidth, y, 0.0f);          // right bottom
        glVertex3f(x + barWidth, y, -barDepth);     // right bottom back
        glVertex3f(x + barWidth, y + barHeight, -barDepth); // right top back
        glVertex3f(x + barWidth, y + barHeight, 0.0f); // right top

        glVertex3f(x, y, 0.0f);                       // left bottom
        glVertex3f(x + barWidth, y, 0.0f);           // right bottom
        glVertex3f(x + barWidth, y, -barDepth);      // right bottom back
        glVertex3f(x, y, -barDepth);                 // left bottom back

        glVertex3f(x, y + barHeight, 0.0f);              // left top
        glVertex3f(x + barWidth, y + barHeight, 0.0f);   // right top
        glVertex3f(x + barWidth, y + barHeight, -barDepth); // right top back
        glVertex3f(x, y + barHeight, -barDepth);          // left top back

        glEnd();
    }

    rotationAngle += 0.1f;
    if (rotationAngle > 360) {
        rotationAngle -= 360;  // Keep the angle within 0-360 degrees
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool Visualization::shouldClose() {
    return glfwWindowShouldClose(window);
}

void Visualization::cleanup() {
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
}
