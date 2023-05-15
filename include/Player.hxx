#pragma once

#include "Vector3.hxx"
#include "framework.hxx"
#include "common/constants.hxx"

class Player
{
public:
    void ** vtable;
	Vector3 camera_origin; //0x0004
	Vector3 velocity; //0x0010
	Vector3 N00000230; //0x001C
	Vector3 position; //0x0028
	Vector3 view_angles; //0x0034
	float punch_angle_pitch; //0x0040
	float max_speed; //0x0044
	int32_t falling_time; //0x0048
	float hitbox_related1; //0x004C
	float height; //0x0050
	float speed_related1; //0x0054
	float height_wo_visual; //0x0058
	bool is_in_water; //0x005C
	bool is_on_ground; //0x005D
	bool is_on_ladder; //0x005E
	bool jump; //0x005F
	char pad_0060[1]; //0x0060
	bool is_crouching_no_effect; //0x0061
	bool N0000023C; //0x0062
	bool is_crouching; //0x0063
	bool N0000036A; //0x0064
	bool N00000368; //0x0065
	bool is_in_scope; //0x0066
	char pad_0067[1]; //0x0067
	int32_t last_jump_tick; //0x0068
	float N0000023F; //0x006C
	char pad_0070[4]; //0x0070
	int8_t move_forward_backward; //0x0074  default values [-1; 0; 1]
	int8_t move_left_right; //0x0075		default values [-1; 0; 1]
	uint8_t state; //0x0076
	uint8_t entity_type; //0x0077
	float N00000242; //0x0078
	char pad_007C[4]; //0x007C
	bool left; //0x0080
	bool right; //0x0081
	bool forward; //0x0082
	bool backward; //0x0083
	char pad_0084[104]; //0x0084
	int32_t health; //0x00EC
	int32_t armor; //0x00F0
	char pad_00F4[12]; //0x00F4
	bool is_dual_pistols_active; //0x0100
	char pad_0101[3]; //0x0101
	int32_t secondary_ammo[TOTAL_WEAPONS]; //0x0104
	int32_t primary_ammo[TOTAL_WEAPONS]; //0x0128
	int32_t weapon_action_delay[TOTAL_WEAPONS]; //0x014C
	int32_t shoots_made[TOTAL_WEAPONS]; //0x0170
	int32_t N00000269[TOTAL_WEAPONS]; //0x0194
	char pad_01B8[32]; //0x01B8
	int32_t deaths; //0x01D8
	int32_t frags; //0x01DC
	char pad_01E0[36]; //0x01E0
	bool attack; //0x0204
	char nickname[260]; //0x0205
	char pad_0309[3]; //0x0309
	int32_t team; //0x030C

    static Player* LocalPlayer();
	
	bool IsAlive();
};
