#pragma  once

#include "../../nclgl/OGLRenderer.h"
#include "../../nclgl/Camera.h"
#include "../../Frameworks/DataArray.h"

struct DrawData
{
	Mesh *objectMesh;
	Vector3 position;
};

class  Renderer : public  OGLRenderer {

public:
	Renderer(Window &parent);
	virtual ~Renderer(void);

	virtual void RenderScene();

	void UpdateTextureMatrix(float rotation);
	void ToggleDepth();
	//void ToggleRepeating();
	//void ToggleFiltering();

	void AddToPipeline(Mesh *mesh, Vector3 position);

	DataArray<DrawData> renderPipeline = DataArray<DrawData>();

private:
	bool filtering;
	bool repeating;
	bool usingDepth;
};