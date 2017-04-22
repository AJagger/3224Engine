#include "Renderer.h"
#include "../../Frameworks/DataArray.cpp" //Temp fix to Linker Errors

Renderer::Renderer(Window &parent) : OGLRenderer(parent) {

	//currentShader = new Shader(SHADERDIR"MatrixVertex.glsl",
	//	SHADERDIR"basicFragment.glsl");

	//Need to change this to relative paths once I figure them out
	//currentShader = new Shader("C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Renderer\\Shaders\\MatrixVertex.glsl", "C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Renderer\\Shaders\\basicFragment.glsl");
	currentShader = new Shader("C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Renderer\\Shaders\\TexturedVertex.glsl", "C:\\Users\\Aidan\\Documents\\Visual Studio 2015\\Projects\\3224Engine\\3224Engine\\Renderer\\Shaders\\TexturedFragment.glsl");


	if (!currentShader->LinkProgram()) {
		return;
	}

	init = true;

	//projMatrix = Matrix4::Perspective(1.0f, 100.0f, (float)16 / (float)9, 45.0f);
	//projMatrix = Matrix4::Perspective(5.0f, 50.0f, (float)1.6 / (float)0.9, 45.0f);
	//projMatrix = Matrix4::Orthographic(800 / 2.0f, -800 / 2.0f, 600 / 2.0f, -600 / 2.0f, -1.0f, 1.0f);
	//projMatrix = Matrix4::Orthographic(-1, 1, 1, -1, 1, -1);
	//projMatrix = Matrix4::Orthographic(1, -1, 10, 0, 10, 0);
	projMatrix = Matrix4::Orthographic(-1, 100, 10, 0, 10, 0);

	filtering = true;
	usingDepth = false;
	repeating = false;

	ToggleDepth();
}

Renderer::~Renderer(void) {

}

void Renderer::RenderScene() {
	//glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST | GL_BLEND);

	glUseProgram(currentShader->GetProgram());

	UpdateShaderMatrices();

	glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "projMatrix"), 1, false, (float *)& projMatrix);
	glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "viewMatrix"), 1, false, (float *)& viewMatrix);

	glUniform1i(glGetUniformLocation(currentShader->GetProgram(), "diffuseTex"), 0);

	//Cycle through objects in renderPipeline and draw.
	DrawData *drawData = renderPipeline.TryToGetFirst();
	if (drawData != nullptr)
	{
		modelMatrix = Matrix4::Translation(drawData->position) * Matrix4::Rotation(0.0f, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(1.0f, 1.0f, 1.0f));

		glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "modelMatrix"), 1, false, (float *)& modelMatrix);

		//glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "modelMatrix"), 1, false, (float*)&modelMatrix);
		drawData->objectMesh->Draw();

		while (renderPipeline.IsNext())
		{
			drawData = renderPipeline.Next();
			if (drawData != nullptr)
			{
				//modelMatrix = Matrix4::Translation(drawData->position);
				//glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "modelMatrix"), 1, false, (float*)&modelMatrix);

				modelMatrix = Matrix4::Translation(drawData->position) * Matrix4::Rotation(0.0f, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(1.0f, 1.0f, 1.0f));

				glUniformMatrix4fv(glGetUniformLocation(currentShader->GetProgram(), "modelMatrix"), 1, false, (float *)& modelMatrix);

				drawData->objectMesh->Draw();
			}
		}
	}

	glUseProgram(0);

	SwapBuffers();

	//clear RenderPipeline
	renderPipeline.FreeAll();
}

void  Renderer::UpdateTextureMatrix(float  value) {
	Matrix4  pushPos = Matrix4::Translation(Vector3(0.5f, 0.5f, 0));
	Matrix4  popPos = Matrix4::Translation(Vector3(-0.5f, -0.5f, 0));
	Matrix4  rotation = Matrix4::Rotation(value, Vector3(0, 0, 1));
	textureMatrix = pushPos * rotation * popPos;

}

void Renderer::ToggleDepth()
{
	usingDepth = !usingDepth;
	usingDepth ? glEnable(GL_DEPTH_TEST) : glDisable(GL_DEPTH_TEST);
}

void Renderer::AddToPipeline(Mesh *mesh, Vector3 position)
{
	DrawData *data = renderPipeline.CreateNew();
	data->position = position;
	data->objectMesh = mesh;
}
