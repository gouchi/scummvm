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

#ifndef GUI_DOWNLOADDIALOG_H
#define GUI_DOWNLOADDIALOG_H

#include "gui/dialog.h"
#include "common/str.h"
#include <backends/cloud/storage.h>

namespace GUI {

class CommandSender;
class EditTextWidget;
class StaticTextWidget;
class ButtonWidget;
class BrowserDialog;
class RemoteBrowserDialog;

class DownloadDialog : public Dialog {
	BrowserDialog *_browser;
	RemoteBrowserDialog *_remoteBrowser;

	StaticTextWidget *_messageText;
	ButtonWidget *_mainButton;
	ButtonWidget *_closeButton;

	bool _close;

	void updateButtons();
	void selectDirectories();

public:
	DownloadDialog(uint32 storageId);

	virtual void handleCommand(CommandSender *sender, uint32 cmd, uint32 data);
	virtual void handleTickle();
	virtual void reflowLayout();
};

} // End of namespace GUI

#endif
