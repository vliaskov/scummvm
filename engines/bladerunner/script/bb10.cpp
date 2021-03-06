/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "bladerunner/script/script.h"

namespace BladeRunner {

void ScriptBB10::InitializeScene() {
	if (Game_Flag_Query(223)) {
		Setup_Scene_Information(255.29f, 90.24f, -103.0f, 830);
	} else if (Game_Flag_Query(220)) {
		Game_Flag_Reset(220);
		Setup_Scene_Information(151.67f, 66.84f, -313.06f, 0);
	} else {
		Setup_Scene_Information(199.67f, 67.4f, -169.06f, 628);
	}
	if (Global_Variable_Query(36) > 2) {
		Scene_Exit_Add_2D_Exit(0, 281, 0, 531, 115, 0);
	}
	Scene_Exit_Add_2D_Exit(1, 58, 91, 193, 401, 3);
	Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
	Ambient_Sounds_Add_Looping_Sound(382, 76, 0, 1);
	Ambient_Sounds_Add_Sound(443, 2, 180, 14, 16, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(444, 2, 180, 14, 16, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(445, 2, 180, 14, 16, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(446, 2, 180, 14, 16, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(303, 5, 50, 17, 27, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(304, 5, 50, 17, 27, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(305, 5, 50, 17, 27, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(306, 5, 50, 17, 27, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(307, 5, 50, 17, 27, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(308, 5, 50, 17, 27, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(309, 5, 50, 17, 27, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(310, 5, 50, 17, 27, -100, 100, -101, -101, 0, 0);
	if (!Game_Flag_Query(466)) {
		Scene_2D_Region_Add(0, 458, 99, 522, 133);
		Overlay_Play("BB10OVR1", 0, 1, 0, 0);
	}
	if (!Game_Flag_Query(467)) {
		Scene_2D_Region_Add(1, 459, 164, 522, 193);
		Overlay_Play("BB10OVR2", 0, 1, 0, 0);
	}
	if (!Game_Flag_Query(468)) {
		Scene_2D_Region_Add(2, 458, 194, 522, 223);
		Overlay_Play("BB10OVR3", 0, 1, 0, 0);
	}
	if (!Game_Flag_Query(469)) {
		Scene_2D_Region_Add(3, 458, 255, 522, 278);
		Overlay_Play("BB10OVR4", 0, 1, 0, 0);
	}
	if (!Game_Flag_Query(470)) {
		Scene_2D_Region_Add(4, 458, 316, 522, 335);
		Overlay_Play("BB10OVR5", 0, 1, 0, 0);
	}
}

void ScriptBB10::SceneLoaded() {
	Obstacle_Object("BARB NIGHT", true);
	Unclickable_Object("BARB NIGHT");
	Unobstacle_Object("Box-Floor Hole01", true);
	Unobstacle_Object("Box-Floor Hole02", true);
	Unobstacle_Object("Box-Floor Hole03", true);
}

bool ScriptBB10::MouseClick(int x, int y) {
	return false;
}

bool ScriptBB10::ClickedOn3DObject(const char *objectName, bool a2) {
	return false;
}

bool ScriptBB10::ClickedOnActor(int actorId) {
	return false;
}

bool ScriptBB10::ClickedOnItem(int itemId, bool a2) {
	return false;
}

bool ScriptBB10::ClickedOnExit(int exitId) {
	if (exitId == 0) {
		if (!Loop_Actor_Walk_To_XYZ(0, 225.58f, 67.2f, -102.1f, 0, 1, false, 0)) {
			Player_Set_Combat_Mode(false);
			Actor_Face_Heading(0, 274, false);
			Footstep_Sound_Override_On(2);
			Loop_Actor_Travel_Stairs(0, 2, 1, 0);
			Footstep_Sound_Override_Off();
			Footstep_Sound_Override_On(2);
			Loop_Actor_Travel_Ladder(0, 3, 1, 0);
			Footstep_Sound_Override_Off();
			Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
			Ambient_Sounds_Remove_All_Looping_Sounds(1);
			Game_Flag_Set(222);
			Set_Enter(26, 12);
		}
		return true;
	}
	if (exitId == 1) {
		if (!Loop_Actor_Walk_To_XYZ(0, 206.01f, 66.84f, -261.62f, 0, 1, false, 0) && !Loop_Actor_Walk_To_XYZ(0, 151.67f, 66.84f, -313.06f, 0, 1, false, 0)) {
			Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
			Ambient_Sounds_Remove_All_Looping_Sounds(1);
			Game_Flag_Reset(216);
			Game_Flag_Set(221);
			Set_Enter(24, 10);
		}
		return true;
	}
	return false;
}

bool ScriptBB10::ClickedOn2DRegion(int region) {
	if (!Loop_Actor_Walk_To_XYZ(0, 225.58f, 67.2f, -102.1f, 0, 1, false, 0)) {
		Actor_Face_Heading(0, 274, false);
		Sound_Play(Random_Query(289, 290), 40, 70, 70, 50);
		switch (region) {
		case 4:
			Overlay_Remove("BB10OVR5");
			Game_Flag_Set(470);
			Scene_2D_Region_Remove(4);
			break;
		case 3:
			Overlay_Remove("BB10OVR4");
			Game_Flag_Set(469);
			Scene_2D_Region_Remove(3);
			break;
		case 2:
			Overlay_Remove("BB10OVR3");
			Game_Flag_Set(468);
			Scene_2D_Region_Remove(2);
			break;
		case 1:
			Overlay_Remove("BB10OVR2");
			Game_Flag_Set(467);
			Scene_2D_Region_Remove(1);
			break;
		case 0:
			Overlay_Remove("BB10OVR1");
			Game_Flag_Set(466);
			Scene_2D_Region_Remove(0);
			break;
		default:
			break;
		}
		Global_Variable_Increment(36, 1);
		if (Global_Variable_Query(36) > 4) {
			Scene_Exit_Add_2D_Exit(0, 281, 0, 531, 115, 0);
		}
		return false;
	}
	return true;
}

void ScriptBB10::SceneFrameAdvanced(int frame) {
}

void ScriptBB10::ActorChangedGoal(int actorId, int newGoal, int oldGoal, bool currentSet) {
}

void ScriptBB10::PlayerWalkedIn() {
	if (Game_Flag_Query(216)) {
		Player_Loses_Control();
		Actor_Set_At_XYZ(0, 214.01f, 66.84f, -349.62f, 462);
		Loop_Actor_Walk_To_XYZ(0, 206.01f, 66.84f, -261.62f, 0, 0, false, 0);
		Player_Gains_Control();
		Game_Flag_Reset(216);
	} else if (Game_Flag_Query(223)) {
		Actor_Set_At_XYZ(0, 249.58f, 127.2f, -102.1f, 256);
		Footstep_Sound_Override_On(2);
		Loop_Actor_Travel_Ladder(0, 3, 0, 0);
		Footstep_Sound_Override_Off();
		Actor_Face_Heading(0, 768, false);
		Footstep_Sound_Override_On(2);
		Loop_Actor_Travel_Stairs(0, 3, 0, 0);
		Footstep_Sound_Override_Off();
		Game_Flag_Reset(223);
	}
}

void ScriptBB10::PlayerWalkedOut() {
}

void ScriptBB10::DialogueQueueFlushed(int a1) {
}

} // End of namespace BladeRunner
