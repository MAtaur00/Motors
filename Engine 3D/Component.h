#pragma once
#include "pcg/pcg_basic.h"
#include "Globals.h"
class GameObject;

enum Object_Type
{
	None = -1,

	CompTransform = 0,
	CompMesh,
	CompTexture,
	CompCamera,
	CompBillboard,
	CompEmitter
};

class Component
{
public:
	Component(GameObject* parent, Object_Type type) : gameObject(parent), type(type) { uuid = pcg32_random(); }
	virtual ~Component() {}

	virtual void Inspector() {}

	virtual void Save(JSON_Object* parent) {}
public:
	GameObject* gameObject = nullptr;
	Object_Type type;

	unsigned int uuid = 0u;
};