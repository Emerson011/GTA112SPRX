int lastTick = 0;
bool IsTimerReady(int interval)
{
	if (lastTick + interval < GAMEPLAY::GET_GAME_TIMER()) {
		lastTick = GAMEPLAY::GET_GAME_TIMER();
		return true;
	}
	return false;
}
void playSound(char* sound)
{
	AUDIO::PLAY_SOUND_FRONTEND(-1, sound, "HUD_FRONTEND_DEFAULT_SOUNDSET");
}

float drawText(char * text, int font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center, bool rightAlign)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_DROPSHADOW(true,0,0,0,a);//the rgb and alpha is actually ignored...
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	
	if (rightAlign) {
		UI::SET_TEXT_RIGHT_JUSTIFY(rightAlign);//for some reason it has to be in here
		UI::SET_TEXT_WRAP(0.0f, x);
	}
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	GRAPHICS::_END_TEXT_COMPONENT();
	UI::_DRAW_TEXT(x, y);
}
void drawNotification(char* msg, bool method = false)
{
	if (method == false)
	{
		UI::_0x574EE85C("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(msg);
		UI::_SET_NOTIFICATION_MESSAGE("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", true, 4, "pro", "");
		UI::_DRAW_NOTIFICATION(false, true);
	}
	else
	{
		UI::_0xF42C43C7("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(msg);
		UI::_0x38F82261(3000, 1);
	}
}

float drawRectXY(float startX, float startY, float endX, float endY, int r, int g, int b, int a) {
	float centerX = (startX+endX)/2;
	float centerY = (startY+endY)/2;
	float width = endX-startX;
	float height = endY-startY;
	GRAPHICS::DRAW_RECT(centerX,centerY,width,height,r,g,b,a);
}
void exclusiveInputs() {
	// TODO: fix this so it doesn't let you open your phone
	unsigned char cArray[] = {10,6,7,8,9};
	for (int i = 0; i < sizeof(cArray); i++)
		UI::HIDE_HUD_COMPONENT_THIS_FRAME(cArray[i]);
	unsigned char bArray[] = {DPAD_UP,DPAD_DOWN,BUTTON_X,BUTTON_CIRCLE, 19,20,21,27,54,123,124,125,126,138,139,140,177,178,179,207};
	for (int i = 0; i < sizeof(bArray); i++)
		CONTROLS::DISABLE_CONTROL_ACTION(0,bArray[i]);
	for (int i = 80; i < 255; i++) {
		CONTROLS::DISABLE_CONTROL_ACTION(0,i);
		CONTROLS::SET_INPUT_EXCLUSIVE(2,i);
	}
	unsigned char iArray[] = {DPAD_UP,DPAD_DOWN,BUTTON_X,BUTTON_CIRCLE, 166,167,177,178,193,194,195,202,203,204,205};
	for (int i = 0; i < sizeof(iArray); i++)
		CONTROLS::SET_INPUT_EXCLUSIVE(2,iArray[i]);
}
char buttonsText[70][4];
void drawButtonTester() {
	for (int i = 0; i < 70; i++) {
		itoa(i,buttonsText[i],10);
		drawText(buttonsText[i],0,0.5,i*0.01,0.2,0.2,255,255,255,255,false,true);
		if (CONTROLS::IS_CONTROL_PRESSED(0, i)) {
			drawText("~g~*",0,0.501,i*0.01,0.2,0.2,255,255,255,255,false,false);
		}
	}
}


int CREATE_VEHICLE(int model, float x, float y, float z) {
	if (STREAMING::IS_MODEL_IN_CDIMAGE(model) && STREAMING::IS_MODEL_A_VEHICLE(model)) {
		STREAMING::REQUEST_MODEL(model);
		if (STREAMING::HAS_MODEL_LOADED(model) == true) {
			Vehicle veh = VEHICLE::CREATE_VEHICLE(model, x, y, z, ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID()), 1, 0);
			if(ENTITY::DOES_ENTITY_EXIST(veh)){
					VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(veh);
				return veh;
			}
		}
	}
	return 0;
}

void spawnVehicleOnMe(char *vehicle) {
	Vector3 c = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(),true);
	CREATE_VEHICLE(GAMEPLAY::GET_HASH_KEY(vehicle),c.x,c.y,c.z);
}
/*
int func_2133()//want this to return 1
{
    int iVar0;
    int iVar1;
    
    iVar0 = 0;
    iVar1 = 0;
    while (iVar1 <= 9)
    {
        if (Global(2398355).arr(iVar1,) != 0)
        {
            Global_1345789 = iVar1;
            iVar0 = 1;
            iVar1 = 10;
        }
        iVar1++;
    }
    return iVar0;
}*/

void outputTestGlobalVals() {
	//Global(2398355).imm(1).set(1);

	//void func_1099(var uParam0) maintransition
	//int curloadingid = Global(1344034).get<int>();
	//if (curloadingid == 4 || curloadingid == 26) {
	//	Global(1344034).set<int>(5);
	//}


	//Global_2398420 && Global_19455 != 0
}