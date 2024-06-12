#pragma once

#include <iostream>
#include <vector>
#include <map>

#include <stb_image/stb_image.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "resource_manager.h"
#include "post_processing.h"
#include "camera.h"
#include "lights.h"

#include "shader.h"
#include "model.h"
#include "texture.h"
#include "billboards.h"

class Scene
{
public:
    // Camera from the engine class (TODO: think of some more clever way of this later)
    std::shared_ptr<Camera> camera;

    // Constructor
    Scene();

    // Destructor
    ~Scene();

    // Gets called every frame in the engine class
    void update();

    // Some stuff to add to the scene
    std::shared_ptr<Shader> addShader(std::string name, const std::string& vertex_shader_rel_path, const std::string& fragment_shader_rel_path);
    std::shared_ptr<Texture> addTexture(std::string name, std::string type, const std::string& texture_rel_path);
    std::shared_ptr<Model> addModel(std::string name, const std::string& model_rel_path);
    std::shared_ptr<CylindricalBillboard> addCylBillboard(std::string name, glm::vec3 pos, glm::vec2 size, const std::string& texture_path);
    std::shared_ptr<SphericalBillboard> addSphBillboard(std::string name, glm::vec3 pos, glm::vec2 size, const std::string& texture_path);

    // Add lights to the scene
    std::shared_ptr<DirLight> addDirLight(DirLight dir_light);
    std::shared_ptr<PointLight> addPointLight(PointLight point_light);
    std::shared_ptr<SpotLight> addSpotLight(SpotLight spot_light);

private:
    // Vectors with scene lights
    std::vector<std::shared_ptr<DirLight>> dirLights;
    std::vector<std::shared_ptr<PointLight>> pointLights;
    std::vector<std::shared_ptr<SpotLight>> spotLights;

    std::shared_ptr<ResourceManager> resourceManager; // every scene has it's own resource manager (may change later)
    std::shared_ptr<Shader> defaultShader; // a default shader to draw stuff with (may get rid of this later (throw an error of some sort if no shaders were added (perhaps add setShader()?)))
};