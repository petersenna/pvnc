//
// Copyright (C) 2002-2003 RealVNC Ltd. All Rights Reserved.
//
//  Copyright (C) 1999 AT&T Laboratories Cambridge. All Rights Reserved.
//
//  This file is part of the VNC system.
//
//  The VNC system is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,
//  USA.
//
// If the source code for the VNC system is not available from the place 
// whence you received this file, check http://www.uk.research.att.com/vnc or contact
// the authors on vnc@uk.research.att.com for information on obtaining it.



#pragma once

#define LASTENCODING rfbEncodingZRLE

#define NOCURSOR 0
#define DOTCURSOR 1
#define NORMALCURSOR 2

class VNCOptions  
{
public:
	VNCOptions();
	VNCOptions& operator=(VNCOptions& s);
	virtual ~VNCOptions();
	
	// Save and load a set of options from a config file
	void Save(char *fname);
	void Load(char *fname);

	// process options
	bool	m_listening;
	int     m_listenPort;
	bool	m_connectionSpecified;
	bool	m_configSpecified;
	TCHAR   m_configFilename[_MAX_PATH];
	bool	m_restricted;

	// default connection options - can be set through Dialog
	bool	m_ViewOnly;
	bool	m_FullScreen;

        bool autoDetect;
	bool	m_Use8Bit;
	int	m_PreferredEncoding;

	bool	m_SwapMouse;
	bool    m_Emul3Buttons; 
 	int     m_Emul3Timeout;
 	int     m_Emul3Fuzz;
	bool	m_Shared;
	bool	m_DeiconifyOnBell;
	bool	m_DisableClipboard;
	int     m_localCursor;
	bool	m_scaling;
	int		m_scale_num, m_scale_den; // Numerator & denominator

	// Keyboard can be specified on command line as 8-digit hex
	TCHAR	m_kbdname[9];
	bool	m_kbdSpecified;

	// Connection options we don't do through the dialog
	// Which encodings do we allow?
	bool	m_UseEnc[LASTENCODING+1];

	TCHAR   m_host[256];
	int     m_port;

    // Logging
    int     m_logLevel;
    bool    m_logToFile, m_logToConsole;
    TCHAR   m_logFilename[_MAX_PATH];
    
	// for debugging purposes
	int m_delay;

#ifdef UNDER_CE
	// WinCE screen format for dialogs (Palm vs HPC)
	int	m_palmpc;
	// Use slow GDI rendering, but more accurate colours.
	int m_slowgdi;
#endif

	int DoDialog(bool running = false);
	void SetFromCommandLine(LPTSTR szCmdLine);


	static BOOL CALLBACK OptDlgProc(  HWND hwndDlg,  UINT uMsg, 
		WPARAM wParam, LPARAM lParam );

	// Register() makes this viewer the app invoked for .vnc files
	static void Register();

private:
    void ShowUsage(LPTSTR info = NULL);
	void FixScaling();

	// Just for temporary use
	bool m_running;

};

