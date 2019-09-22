#include "ModuleIMGui.h"
#include "ModuleWindow.h"
#include "Application.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl2.h"
#include "imgui_internal.h"
#include "MathGeoLib/MathGeoLib.h"
using namespace ImGui;



ModuleIMGui::ModuleIMGui(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}


ModuleIMGui::~ModuleIMGui()
{
}

bool ModuleIMGui::Start()
{
	bool ret = true;

	

	return ret;
}

update_status ModuleIMGui::PreUpdate(float dt)
{
	update_status ret = UPDATE_CONTINUE;

	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplSDL2_NewFrame(App->window->window);
	NewFrame();

	if (BeginMainMenuBar())
	{
		if (BeginMenu("Menu"))
		{
			if (MenuItem("Show Demo Window"))
			{
				showDemo = !showDemo;
			}
			else if (MenuItem("MathGeoLib"))
			{
				showMath = !showMath;
			}
			else if (MenuItem("Exit"))
			{
				ret = UPDATE_STOP;
			}
			ImGui::EndMenu();
		}
		EndMainMenuBar();
	}
	if (showDemo)
		ShowDemoWindow(&showDemo);
	if (showMath)
	{
		if (ImGui::Begin("MathGeoLib", &showMath))
		{
			const char* listbox_items[] = { "Sphere", "Cylinder", "Capsule", "AABB", "OBB", "Frustum", "Plane", "Segment", "Ray", "Convex Hull", "Mesh", "Triangle" };
			ImGui::Text("Object 1");
			ImGui::ListBox("##Object1", &current_object1, listbox_items, IM_ARRAYSIZE(listbox_items), 4);
			ImGui::NewLine();
			ImGui::Text("Object 2");
			ImGui::ListBox("##Object2", &current_object2, listbox_items, IM_ARRAYSIZE(listbox_items), 4);
			
			ImGui::NewLine();
			ImGui::Text("Move the sliders to move the objects");
			ImGui::NewLine();
			ImGui::SliderFloat("Object 1", &posx1, 0.0f, 5.0f, "%.1f");
			ImGui::SliderFloat("Object 2", &posx2, 0.0f, 5.0f, "%.1f");
			

			ImGui::NewLine();
			
			bool colliding = false;
			switch (current_object1)
			{
			case Type_Sphere:
				Sphere sph1({ posx1, 0.0f, 0.0f }, 1.f);
				switch (current_object2)
				{
				case Type_Sphere:
					Sphere sph2({ posx2, 0.0f, 0.0f }, 1.f);
					colliding = sph1.Intersects(sph2);
					break;
				case Type_Cylinder:
					Cylinder cyl2({ posx2, 0.0f, -1.0f }, { posx2, 0.0f, 1.0f }, 1.f);
					break;
				case Type_Capsule:
					break;
				case Type_AABB:
					break;
				case Type_OBB:
					break;
				case Type_Frustum:
					break;
				case Type_Plane:
					break;
				case Type_Segment:
					break;
				case Type_Ray:
					break;
				case Type_Convex_Hull:
					break;
				case Type_Mesh:
					break;
				case Type_Triangle:
					break;
				default:
					break;
				}
				break;
			case Type_Cylinder:
				Cylinder cyl1({ posx1, 0.0f, -1.0f }, { posx1, 0.0f, 1.0f }, 1.f);
				switch (current_object2)
				{
				case Type_Sphere:
					break;
				case Type_Cylinder:
					break;
				case Type_Capsule:
					break;
				case Type_AABB:
					break;
				case Type_OBB:
					break;
				case Type_Frustum:
					break;
				case Type_Plane:
					break;
				case Type_Segment:
					break;
				case Type_Ray:
					break;
				case Type_Convex_Hull:
					break;
				case Type_Mesh:
					break;
				case Type_Triangle:
					break;
				default:
					break;
				}
				break;
			case Type_Capsule:
				switch (current_object2)
				{
				case Type_Sphere:
					break;
				case Type_Cylinder:
					break;
				case Type_Capsule:
					break;
				case Type_AABB:
					break;
				case Type_OBB:
					break;
				case Type_Frustum:
					break;
				case Type_Plane:
					break;
				case Type_Segment:
					break;
				case Type_Ray:
					break;
				case Type_Convex_Hull:
					break;
				case Type_Mesh:
					break;
				case Type_Triangle:
					break;
				default:
					break;
				}
				break;
			case Type_AABB:
				switch (current_object2)
				{
				case Type_Sphere:
					break;
				case Type_Cylinder:
					break;
				case Type_Capsule:
					break;
				case Type_AABB:
					break;
				case Type_OBB:
					break;
				case Type_Frustum:
					break;
				case Type_Plane:
					break;
				case Type_Segment:
					break;
				case Type_Ray:
					break;
				case Type_Convex_Hull:
					break;
				case Type_Mesh:
					break;
				case Type_Triangle:
					break;
				default:
					break;
				}
				break;
			case Type_OBB:
				switch (current_object2)
				{
				case Type_Sphere:
					break;
				case Type_Cylinder:
					break;
				case Type_Capsule:
					break;
				case Type_AABB:
					break;
				case Type_OBB:
					break;
				case Type_Frustum:
					break;
				case Type_Plane:
					break;
				case Type_Segment:
					break;
				case Type_Ray:
					break;
				case Type_Convex_Hull:
					break;
				case Type_Mesh:
					break;
				case Type_Triangle:
					break;
				default:
					break;
				}
				break;
			case Type_Frustum:
				switch (current_object2)
				{
				case Type_Sphere:
					break;
				case Type_Cylinder:
					break;
				case Type_Capsule:
					break;
				case Type_AABB:
					break;
				case Type_OBB:
					break;
				case Type_Frustum:
					break;
				case Type_Plane:
					break;
				case Type_Segment:
					break;
				case Type_Ray:
					break;
				case Type_Convex_Hull:
					break;
				case Type_Mesh:
					break;
				case Type_Triangle:
					break;
				default:
					break;
				}
				break;
			case Type_Plane:
				switch (current_object2)
				{
				case Type_Sphere:
					break;
				case Type_Cylinder:
					break;
				case Type_Capsule:
					break;
				case Type_AABB:
					break;
				case Type_OBB:
					break;
				case Type_Frustum:
					break;
				case Type_Plane:
					break;
				case Type_Segment:
					break;
				case Type_Ray:
					break;
				case Type_Convex_Hull:
					break;
				case Type_Mesh:
					break;
				case Type_Triangle:
					break;
				default:
					break;
				}
				break;
			case Type_Segment:
				switch (current_object2)
				{
				case Type_Sphere:
					break;
				case Type_Cylinder:
					break;
				case Type_Capsule:
					break;
				case Type_AABB:
					break;
				case Type_OBB:
					break;
				case Type_Frustum:
					break;
				case Type_Plane:
					break;
				case Type_Segment:
					break;
				case Type_Ray:
					break;
				case Type_Convex_Hull:
					break;
				case Type_Mesh:
					break;
				case Type_Triangle:
					break;
				default:
					break;
				}
				break;
			case Type_Ray:
				switch (current_object2)
				{
				case Type_Sphere:
					break;
				case Type_Cylinder:
					break;
				case Type_Capsule:
					break;
				case Type_AABB:
					break;
				case Type_OBB:
					break;
				case Type_Frustum:
					break;
				case Type_Plane:
					break;
				case Type_Segment:
					break;
				case Type_Ray:
					break;
				case Type_Convex_Hull:
					break;
				case Type_Mesh:
					break;
				case Type_Triangle:
					break;
				default:
					break;
				}
				break;
			case Type_Convex_Hull:
				switch (current_object2)
				{
				case Type_Sphere:
					break;
				case Type_Cylinder:
					break;
				case Type_Capsule:
					break;
				case Type_AABB:
					break;
				case Type_OBB:
					break;
				case Type_Frustum:
					break;
				case Type_Plane:
					break;
				case Type_Segment:
					break;
				case Type_Ray:
					break;
				case Type_Convex_Hull:
					break;
				case Type_Mesh:
					break;
				case Type_Triangle:
					break;
				default:
					break;
				}
				break;
			case Type_Mesh:
				switch (current_object2)
				{
				case Type_Sphere:
					break;
				case Type_Cylinder:
					break;
				case Type_Capsule:
					break;
				case Type_AABB:
					break;
				case Type_OBB:
					break;
				case Type_Frustum:
					break;
				case Type_Plane:
					break;
				case Type_Segment:
					break;
				case Type_Ray:
					break;
				case Type_Convex_Hull:
					break;
				case Type_Mesh:
					break;
				case Type_Triangle:
					break;
				default:
					break;
				}
				break;
			case Type_Triangle:
				switch (current_object2)
				{
				case Type_Sphere:
					break;
				case Type_Cylinder:
					break;
				case Type_Capsule:
					break;
				case Type_AABB:
					break;
				case Type_OBB:
					break;
				case Type_Frustum:
					break;
				case Type_Plane:
					break;
				case Type_Segment:
					break;
				case Type_Ray:
					break;
				case Type_Convex_Hull:
					break;
				case Type_Mesh:
					break;
				case Type_Triangle:
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}

			if (colliding)
			{
				ImGui::Text("The objects are colliding");
			}
			else
				ImGui::Text("The objects are not colliding");


		}
		ImGui::End();
	}




	return ret;
}

update_status ModuleIMGui::PostUpdate(float dt)
{
	Render();
	ImGui_ImplOpenGL2_RenderDrawData(GetDrawData());

	return update_status::UPDATE_CONTINUE;
}

bool ModuleIMGui::CleanUp()
{
	return true;
}

void ModuleIMGui::Draw()
{

}