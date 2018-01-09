#pragma once

#include "VoxelMatrix.h"
#include "load\NvmFormat.h"
#include "application\utils\variable\datatype\Macros.h"
#include "application\utils\variable\datatype\Vector3.h"
#include "application\utils\variable\manager\VoxelManager.h"

#include "application\gfx\mesh\VoxelMesh.h"

#include <string>
#include <vector>

class VoxelModel
{
private:
	std::vector<VoxelMatrix*> m_matrixList;
public:
	VoxelModel();
	~VoxelModel();

	Vector3<GLfloat> getModelPos();
	Vector3<Sint32> getModelSize();
	std::vector<VoxelMatrix*>& getMatrixList();
	void createShadow();
	void render();
};
