#include "saving_manager.h"

SavingManager::SavingManager(const std::string& Path)
{
	relDataPath = Path.substr(0, Path.find_last_of("/\\")); // saving data path
}

void SavingManager::save_cameraState(Camera& cam)
{
	std::string full_path = relDataPath + "/" + data_file;
	std::ofstream data(full_path, std::ios::binary);
	if (data.is_open()) {
		data << "camera" << "/" << "m_pos" << " " << cam.m_pos.x << " " << cam.m_pos.y << " " << cam.m_pos.z << std::endl;
		data << "camera" << "/" << "m_width" << " " << cam.m_width << std::endl;
		data << "camera" << "/" << "m_height" << " " << cam.m_height << std::endl;
	}
	data.close();
}


