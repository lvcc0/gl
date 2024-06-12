#pragma once

#include <fstream>
#include <sstream>
#include <map>
#include <memory>
#include <iostream>
#include <vector>
#include <filesystem>

#include "camera.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

class SavingManager {
	std::string relDataPath; // full path to data directory
	const std::string data_file = "data.txt";
public:
	// Constructor
	SavingManager(const std::string& Path);

	void save_cameraState(Camera& cam);

	// No move or copy constructors allowed
	SavingManager(const SavingManager& obj) = delete;
	SavingManager(const SavingManager&& obj) = delete;

};