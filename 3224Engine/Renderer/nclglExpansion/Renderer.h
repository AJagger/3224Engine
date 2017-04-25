#pragma  once

#include "../../nclgl/OGLRenderer.h"
#include "../../nclgl/Camera.h"
#include "../../Frameworks/DataArray.h"

struct DrawData
{
	Mesh *objectMesh;
	GLuint texture;
	Vector3 position;
	int rotation;
};

class  Renderer : public  OGLRenderer {

public:
	Renderer(Window &parent);
	virtual ~Renderer(void);

	virtual void RenderScene();

	void UpdateTextureMatrix(float rotation);
	void ToggleDepth();
	void ToggleAlphaBlend();
	void ToggleBlendMode();

	void AddToPipeline(Mesh *mesh, GLuint texture, Vector3 position, int rotation);

	DataArray<DrawData> renderPipeline = DataArray<DrawData>();

private:
	bool filtering;
	bool repeating;
	bool usingDepth;
	bool usingAlpha;
	int blendMode;
};