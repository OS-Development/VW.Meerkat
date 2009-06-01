/** 
 * @file llprefschat.h
 * @brief Database preferences panel
 *
 * Copyright (c) 2003-2007, Linden Research, Inc.
 * 
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

#ifndef LLPREFSDB_H
#define LLPREFSDB_H

#include "llpanel.h"

class LLPanelDatabase : public LLPanel
{
public:
	LLPanelDatabase();
	virtual ~LLPanelDatabase() {};

	virtual BOOL postBuild();
	virtual void draw();
	virtual void refresh();

	void apply();
	void cancel();

	static void onClickChangeAvatar(void *userdata);
	static void onPickAvatar(const std::vector<std::string>& names,
                                 const std::vector<LLUUID>& ids,
                                 void* user_data);

protected:
	std::string mAvatarName;
	LLUUID   mAvatarKey;
	std::string mURL;
	std::string mUsername;
	std::string mPassword;
	std::string mSendPattern;
	std::string mPositivePattern;
	std::string mNegativePattern;
	std::string mDeniedPattern;

};


#endif // LL_PREFSDB_H
