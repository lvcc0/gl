#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

#include <glad/glad.h>
#include <stb_image/stb_image.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>

#include "shader.h"
#include "texture.h"

struct Vertex {
    glm::vec3 Position;
    glm::vec2 TexCoord;
    glm::vec3 Normal;

    // Constructor
    Vertex( glm::vec3 pos, glm::vec2 texCoord, glm::vec3 norm) :
        Position(pos), TexCoord(texCoord), Normal(norm) { /* empty */ }
};

class Model
{
public:
    glm::mat4 m_model_matrix = glm::mat4(1.0f);

    std::vector<Vertex> m_vertices;
    std::vector<unsigned int> m_indices;

    std::vector<std::shared_ptr<Texture>> m_textures;

    // Constructor
    Model(const std::string& objfile, const std::vector<std::shared_ptr<Texture>>& m_textures);
    
    // Draw model
    void Draw(std::shared_ptr<Shader> shader);

    // Moving in world space
    void translate(glm::vec3 vector);
    void scale(glm::vec3 vector);
    void rotate(float degrees, glm::vec3 vector);

private:
    unsigned int VAO, VBO, EBO;

    // works on obj file
    void loadModel(std::ifstream file);
    
    // Setup VAO, VBO, EBO
    void setupModel();
};

#endif