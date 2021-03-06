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

void ScriptCT05::InitializeScene() {
	if (Game_Flag_Query(90)) {
		Game_Flag_Reset(90);
		Setup_Scene_Information(-128.42f, -109.91f, 112.83f, 516);
	} else if (Game_Flag_Query(78)) {
		Setup_Scene_Information(192.35f, 43.09f, 128.97f, 768);
	} else {
		Setup_Scene_Information(-375.0f, -109.91f, 750.0f, 600);
	}
	if (Game_Flag_Query(94)) {
		Scene_Exit_Add_2D_Exit(0, 228, 205, 293, 300, 0);
	}
	Scene_Exit_Add_2D_Exit(1, 320, 458, 639, 479, 2);
	Scene_Exit_Add_2D_Exit(2, 380, 110, 542, 300, 0);
	Ambient_Sounds_Add_Looping_Sound(106, 15, -100, 1);
	Ambient_Sounds_Add_Looping_Sound(107, 15, 100, 1);
	Ambient_Sounds_Add_Looping_Sound(56, 13, -100, 1);
	Ambient_Sounds_Add_Sound(90, 5, 20, 8, 10, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(91, 5, 20, 8, 10, -100, 100, -101, -101, 0, 0);
	Ambient_Sounds_Add_Sound(205, 5, 30, 18, 30, -100, 100, -101, -101, 0, 0);
	if (Game_Flag_Query(94)) {
		Scene_Loop_Set_Default(2);
	} else {
		Scene_Loop_Set_Default(0);
	}
	if (Actor_Query_Goal_Number(53) == 1) {
		Overlay_Play("ct05over", 0, 1, 0, 0);
	}
}

void ScriptCT05::SceneLoaded() {
	Obstacle_Object("STAIR 1", true);
	Obstacle_Object("STAIR 2", true);
	Obstacle_Object("GRGDOOR", true);
	Obstacle_Object("GRGDOOR2", true);
	Obstacle_Object("TURBINE", true);
	Obstacle_Object("BARREL", true);
	Obstacle_Object("GRNDPIPE", true);
	Clickable_Object("TURBINE");
	Clickable_Object("LFTDOOR");
	Clickable_Object("BARREL");
	Clickable_Object("GRNDPIPE");
	Unclickable_Object("GDFRAME");
	Unclickable_Object("GDFRAME2");
	Unclickable_Object("WINFRAME1");
	Unclickable_Object("WINFRAME2");
	Unclickable_Object("STAIR 1");
	Unclickable_Object("STAIR 2");
	Unclickable_Object("LFTDOOR");
	Unclickable_Object("LFTDOORFRM");
}

bool ScriptCT05::MouseClick(int x, int y) {
	return false;
}

bool ScriptCT05::ClickedOn3DObject(const char *objectName, bool a2) {
	if (Object_Query_Click("STAIR1", objectName)) {
		Actor_Face_Object(0, objectName, true);
		return true;
	}
	if (Object_Query_Click("STAIR2", objectName)) {
		Actor_Face_Object(0, objectName, true);
		return true;
	}
	if (Object_Query_Click("GRGDOOR", objectName)) {
		Loop_Actor_Walk_To_Scene_Object(0, "GRGDOOR", 24, 1, false);
		Actor_Face_Object(0, objectName, true);
		Actor_Says(0, 8522, 12);
		return true;
	}
	if (Object_Query_Click("GRGDOOR2", objectName)) {
		Loop_Actor_Walk_To_Scene_Object(0, "GRGDOOR2", 24, 1, false);
		Actor_Face_Object(0, objectName, true);
		Actor_Says(0, 8522, 12);
		return true;
	}
	if (Object_Query_Click("TURBINE", objectName)) {
		Loop_Actor_Walk_To_Scene_Object(0, "TURBINE", 36, 1, false);
		Actor_Face_Object(0, objectName, true);
		Actor_Says(0, 8528, 12);
		return true;
	}
	if (Object_Query_Click("LFTDOOR", objectName)) {
		Actor_Face_Object(0, objectName, true);
		Actor_Says(0, 8522, 12);
		return true;
	}
	if (Object_Query_Click("BARREL", objectName)) {
		Loop_Actor_Walk_To_Scene_Object(0, "BARREL", 36, 1, false);
		Actor_Face_Object(0, objectName, true);
		Actor_Says(0, 8529, 12);
		return true;
	}
	if (Object_Query_Click("GRNDPIPE", objectName)) {
		Loop_Actor_Walk_To_Scene_Object(0, "GRNDPIPE", 24, 1, false);
		Actor_Face_Object(0, objectName, true);
		Actor_Says(0, 8528, 12);
		return true;
	}
	return false;
}

bool ScriptCT05::ClickedOnActor(int actorId) {
	return false;
}

bool ScriptCT05::ClickedOnItem(int itemId, bool a2) {
	return false;
}

bool ScriptCT05::ClickedOnExit(int exitId) {
	if (exitId == 0) {
		if (!Loop_Actor_Walk_To_XYZ(0, -128.42f, -109.91f, 112.83f, 0, 1, false, 0)) {
			Game_Flag_Set(76);
			if (Actor_Query_Goal_Number(53) == 1) {
				Overlay_Remove("ct05over");
			}
			Set_Enter(4, 24);
		}
		return true;
	}
	if (exitId == 1) {
		if (!Loop_Actor_Walk_To_XYZ(0, -308.18f, -109.91f, 674.77f, 0, 1, false, 0)) {
			Game_Flag_Set(75);
			if (Actor_Query_Goal_Number(53) == 1) {
				Overlay_Remove("ct05over");
				Actor_Set_Goal_Number(53, 5);
				Game_Flag_Set(409);
			}
			Set_Enter(5, 16);
		}
		return true;
	}
	if (exitId == 2) {
		if (!Loop_Actor_Walk_To_XYZ(0, 71.99f, -109.91f, 288.79f, 0, 1, false, 0)) {
			Footstep_Sound_Override_On(2);
			Actor_Face_Object(0, "STAIR 2", true);
			Loop_Actor_Travel_Stairs(0, 9, 1, 0);
			Actor_Set_At_XYZ(0, 99.73f, -19.91f, 134.97f, 256);
			Loop_Actor_Travel_Stairs(0, 5, 1, 0);
			Footstep_Sound_Override_Off();
			Game_Flag_Set(77);
			if (Actor_Query_Goal_Number(53) == 1) {
				Overlay_Remove("ct05over");
			}
			Set_Enter(29, 18);
		}
		return true;
	}
	return false;
}

bool ScriptCT05::ClickedOn2DRegion(int region) {
	return false;
}

void ScriptCT05::SceneFrameAdvanced(int frame) {
	if (frame == 7 || frame == 15 || frame == 29) {
		switch (Random_Query(0, 4)) {
		case 4:
			Sound_Play(40, Random_Query(25, 50), -70, -70, 50);
			break;
		case 3:
			Sound_Play(44, Random_Query(25, 50), -70, -70, 50);
			break;
		case 2:
			Sound_Play(43, Random_Query(25, 50), -70, -70, 50);
			break;
		case 1:
			Sound_Play(42, Random_Query(25, 50), -70, -70, 50);
			break;
		case 0:
			Sound_Play(41, Random_Query(25, 50), -70, -70, 50);
			break;
		}
	}
}

void ScriptCT05::ActorChangedGoal(int actorId, int newGoal, int oldGoal, bool currentSet) {
}

void ScriptCT05::PlayerWalkedIn() {
	if (Game_Flag_Query(74)) {
		Player_Loses_Control();
		Game_Flag_Reset(74);
		if (Player_Query_Combat_Mode()) {
			Loop_Actor_Walk_To_XYZ(0, -308.18f, -109.91f, 674.77f, 0, 0, true, 0);
		} else {
			Loop_Actor_Walk_To_XYZ(0, -308.18f, -109.91f, 674.77f, 0, 0, false, 0);
		}
		Player_Gains_Control();
	}
	if (Game_Flag_Query(78)) {
		Footstep_Sound_Override_On(2);
		Loop_Actor_Travel_Stairs(0, 7, 0, 0);
		Actor_Set_At_XYZ(0, 90.73f, -19.91f, 164.97f, 520);
		Loop_Actor_Travel_Stairs(0, 10, 0, 0);
		Game_Flag_Reset(78);
		Footstep_Sound_Override_Off();
		if (Actor_Query_Goal_Number(2) == 2 && Game_Flag_Query(145)) {
			Actor_Set_Goal_Number(2, 3);
		}
	}
}

void ScriptCT05::PlayerWalkedOut() {
	Ambient_Sounds_Remove_All_Non_Looping_Sounds(1);
	Ambient_Sounds_Remove_All_Looping_Sounds(1);
}

void ScriptCT05::DialogueQueueFlushed(int a1) {
}

} // End of namespace BladeRunner
