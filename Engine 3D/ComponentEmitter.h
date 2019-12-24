#pragma once
#include "Component.h"
#include "Timer.h"
#include "MathGeoLib/MathGeoLib.h"
#include <list>

class Particle;
class ResourceTexture;

class ComponentEmitter : public Component
{
public:
	ComponentEmitter(GameObject* parent);
	~ComponentEmitter();

	void Inspector();

	void Update();

	void Save(JSON_Object* parent);

	void Load(JSON_Object* parent);

public:
	Timer timer;

	float ratio = 0.f;

	float life = 0.0f;
	float speed = 1.0f;
	float rotation = 0.0f;
	float size = 1.0f;
	ResourceTexture* texture = nullptr;
	float4 color = float4::one;
	std::string texPath;
	float3 direction = float3::unitY;

	std::list<Particle*> particlesList;
};