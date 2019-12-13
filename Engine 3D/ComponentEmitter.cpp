#include "ComponentEmitter.h"
#include "Application.h"
#include "GameObject.h"
#include "ModuleParticleManager.h"
#include "Particle.h"
#include "ModuleTime.h"

ComponentEmitter::ComponentEmitter(GameObject* parent) : Component(parent, CompEmitter)
{
	parent->components.push_back(this);
	App->particle_manager->emitters.push_back(this);
}

ComponentEmitter::~ComponentEmitter()
{
}

void ComponentEmitter::Inspector()
{
}

void ComponentEmitter::Update()
{
	float time = timer.Read();

	if (ratio > 0.0f)
	{
		if (time >= ratio)
		{
			if (App->module_time->gameState == GameState::PLAYING)
			{
				int pos = App->particle_manager->GetLastParticle();
				App->particle_manager->particles[pos].SetActive(position, speed, rotation, size, life, &texture, color);
				particlesList.push_back(&App->particle_manager->particles[pos]);
			}
		}
	}
}

void ComponentEmitter::Save(JSON_Object * parent)
{
	json_object_set_number(parent, "Type", type);
	json_object_set_number(parent, "UUID", uuid);

	// Position
	//------------------------------------------------------------------------
	JSON_Value* pos = json_value_init_object();
	JSON_Object* positionObj = json_value_get_object(pos);

	json_object_set_value(parent, "Position", pos);

	json_object_set_number(positionObj, "X", position.x);
	json_object_set_number(positionObj, "Y", position.y);
	json_object_set_number(positionObj, "Z", position.z);

	// Speed
	//------------------------------------------------------------------------
	JSON_Value* sp = json_value_init_object();
	JSON_Object* positionObj = json_value_get_object(sp);

	json_object_set_value(parent, "Speed", sp);

	json_object_set_number(positionObj, "X", speed.x);
	json_object_set_number(positionObj, "Y", speed.y);
	json_object_set_number(positionObj, "Z", speed.z);

	// Rotation
	//------------------------------------------------------------------------
	JSON_Value* rot = json_value_init_object();
	JSON_Object* positionObj = json_value_get_object(rot);

	json_object_set_value(parent, "Rotation", rot);

	json_object_set_number(positionObj, "X", rotation.x);
	json_object_set_number(positionObj, "Y", rotation.y);

	// Size
	//------------------------------------------------------------------------
	JSON_Value* siz = json_value_init_object();
	JSON_Object* positionObj = json_value_get_object(siz);

	json_object_set_value(parent, "Size", siz);

	json_object_set_number(positionObj, "Value", size);

	// Texture Path
	//------------------------------------------------------------------------
	json_object_set_string(parent, "Path", texPath.c_str());

	// Color
	//------------------------------------------------------------------------
	JSON_Value* clr = json_value_init_object();
	JSON_Object* positionObj = json_value_get_object(clr);

	json_object_set_value(parent, "Color", clr);

	json_object_set_number(positionObj, "X", color.x);
	json_object_set_number(positionObj, "Y", color.y);
	json_object_set_number(positionObj, "Z", color.z);
	json_object_set_number(positionObj, "W", color.w);
}

void ComponentEmitter::Load(JSON_Object * parent)
{
}