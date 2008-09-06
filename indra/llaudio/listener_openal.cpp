/**
 * @file audioengine_openal.cpp
 * @brief implementation of audio engine using OpenAL
 * support as a OpenAL 3D implementation
 *
 * Copyright (c) 2002-2007, Linden Research, Inc.
 *
 * Second Life Viewer Source Code
 * The source code in this file ("Source Code") is provided by Linden Lab
 * to you under the terms of the GNU General Public License, version 2.0
 * ("GPL"), unless you have obtained a separate licensing agreement
 * ("Other License"), formally executed by you and Linden Lab.  Terms of
 * the GPL can be found in doc/GPL-license.txt in this distribution, or
 * online at http://secondlife.com/developers/opensource/gplv2
 *
 * There are special exceptions to the terms and conditions of the GPL as
 * it is applied to this Source Code. View the full text of the exception
 * in the file doc/FLOSS-exception.txt in this software distribution, or
 * online at http://secondlife.com/developers/opensource/flossexception
 *
 * By copying, modifying or distributing this software, you acknowledge
 * that you have read and understood your obligations described above,
 * and agree to abide by those obligations.
 *
 * ALL LINDEN LAB SOURCE CODE IS PROVIDED "AS IS." LINDEN LAB MAKES NO
 * WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY,
 * COMPLETENESS OR PERFORMANCE.
 */

#include "linden_common.h"
#include "audioengine.h"


#include "listener_openal.h"

LLListener_OpenAL::LLListener_OpenAL(){
	init();
}

LLListener_OpenAL::~LLListener_OpenAL(){
}

void LLListener_OpenAL::translate(LLVector3 offset){
	LLListener::translate(offset);
	llinfos << "LLListener_OpenAL::translate() : " << offset << llendl;
}

void LLListener_OpenAL::setPosition(LLVector3 pos){
	LLListener::setPosition(pos);
	//llinfos << "LLListener_OpenAL::setPosition() : " << pos << llendl;
}

void LLListener_OpenAL::setVelocity(LLVector3 vel){
	LLListener::setVelocity(vel);
}

void LLListener_OpenAL::orient(LLVector3 up, LLVector3 at){
	LLListener::orient(up, at);
	//llinfos << "LLListener_OpenAL::orient() up: " << up << " at: " << at << llendl;
}

void LLListener_OpenAL::commitDeferredChanges(){
	ALfloat orientation[6];
	orientation[0] = mListenAt.mV[0];
	orientation[1] = mListenAt.mV[1];
	orientation[2] = mListenAt.mV[2];
	orientation[3] = mListenUp.mV[0];
	orientation[4] = mListenUp.mV[1];
	orientation[5] = mListenUp.mV[2];

	// Why is this backwards?
	ALfloat velocity[3];
	velocity[0] = -mVelocity.mV[0];
	velocity[1] = -mVelocity.mV[1];
	velocity[2] = -mVelocity.mV[2];

	alListenerfv(AL_ORIENTATION, orientation);
	alListenerfv(AL_POSITION, mPosition.mV);
	alListenerfv(AL_VELOCITY, velocity);
}

void LLListener_OpenAL::setDopplerFactor(F32 factor){
	// Effect is way too strong by default, scale it down here.
	// Scaling the speed of sound up causes crashes.
	factor *= 0.005f;
	//llinfos << "LLListener_OpenAL::setDopplerFactor() : " << factor << llendl;
	alDopplerFactor(factor);
}

F32 LLListener_OpenAL::getDopplerFactor(){
	ALfloat factor;
	factor = 0.0f;
	alDopplerFactor(factor);
	llinfos << "LLListener_OpenAL::getDopplerFactor() : " << factor << llendl;
	return factor;
}
