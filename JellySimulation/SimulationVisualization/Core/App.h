#pragma once

#include <DirectX/D11Renderer.h>

#include <ParticleSystem/ParticleSystem.h>

#include <Scene/Scene.h>
#include <Scene/SceneObject.h>

#include <memory>
#include <ctime> 

class App
{
public:
	App();

	void Update(float deltaTime);
	void Render(void* resource, bool isNewResource);

	void MoveSteeringCube(float dx, float dy);
	void MoveCamera(float dx, float dy);
	void Zoom(float dd);

	void UpdatePhysics();
	void UpdateVisualizationParameters(bool drawControlPoints, bool drawSteeringCube, bool drawShadedCube);

	void RestartSimulation(float pointMass, float stickiness, float massesElasticity, float steeringSpringsElasticity, float maxImbalance);

protected:

	void InitializeControlPoints();
	void UpdateMesh();

	float m_elasticityBetweenMasses;
	float m_elasticityOnSteeringSprings;
	float m_stickiness;
	float m_controlPointMass;
	float m_maxInitialImbalance;

	float m_simulationTimeStep;

	float m_lastFrameTime;
	float m_fullSimulationTime;
	float m_residualSimulationTime;

	Scene m_scene;
	std::shared_ptr<D11Renderer> m_renderer;

	SceneObject m_grid;
	SceneObject m_mesh;
	std::vector<SceneObject> m_controlPoints;
	std::vector<SceneObject> m_controlFrame;

	SceneObject m_renderControlPoints;
	SceneObject m_renderSteeringFrame;
	SceneObject m_renderShadedCube;
};
