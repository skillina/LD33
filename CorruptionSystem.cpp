#include <iostream>
#include <ctime>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "SOIL.h"
#include "skilLib.h"
#include "systems.h"
#include "components.h"
#include "messages.h"
#include <math.h>
#include "ld33.h"

CorruptionSystem::Corruption(){
	id = LD33_CORRUPTIONSYSTEM;
}

void WinLossSystem::update(float delta){
	if(winprogress == 5){
		winprogress = 0;
		notoriety = 0;
		messageSystems(new LoadSceneMessage("win"));
	}

	if(notoriety>5){
		winprogress = 0;
		notoriety = 0;
		messageSystems(new LoadSceneMessage("lose"));
	}
}