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

#include "stdhdrs.h"
#ifdef UNDER_CE
#include "omnithreadce.h"
#else
#include "omnithread.h"
#endif
#include "VNCOptions.h"
#include "VNCviewerApp.h"
#include "KeyMap.h"
#include <rdr/types.h>

#define SETTINGS_KEY_NAME "Software\\ORL\\VNCviewer\\Settings"
#define MAX_HOST_NAME_LEN 250

namespace rdr { class InStream; class FdInStream; class ZlibInStream; }

class ClientConnection  : public omni_thread
{
public:
	ClientConnection(VNCviewerApp *pApp);
	ClientConnection(VNCviewerApp *pApp, SOCKET sock);
	ClientConnection(VNCviewerApp *pApp, LPTSTR host, int port);
	ClientConnection(VNCviewerApp *pApp, LPTSTR configFile);
	virtual ~ClientConnection();
	void Run();
	void KillThread();

	// Exceptions 
	class UserCancelExc {};
	class AuthenticationExc {};
	class SocketExc {};
	class ProtocolExc {};
	class Fatal {};

private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	void DoBlit();
	VNCviewerApp *m_pApp;
	int m_port;
    TCHAR m_host[MAX_HOST_NAME_LEN];
	SOCKET m_sock;
	bool m_serverInitiated;
	HWND m_hwnd, m_hbands;

	void Init(VNCviewerApp *pApp);
	void CreateDisplay();
	void GetConnectDetails();
	void Connect();
	void SetSocketOptions();
	void Authenticate();
	void NegotiateProtocolVersion();
	void ReadServerInit();
	void SendClientInit();
	void CreateLocalFramebuffer();
	void SaveConnection();
	int  LoadConnection(char *fname);
	
	void SetupPixelFormat();
	void SetFormatAndEncodings();
	void SendSetPixelFormat(rfbPixelFormat newFormat);

	void SendIncrementalFramebufferUpdateRequest();
	void SendFullFramebufferUpdateRequest();
	void SendAppropriateFramebufferUpdateRequest();
	void SendFramebufferUpdateRequest(int x, int y, int w, int h, bool incremental);
	
	void ProcessPointerEvent(int x, int y, DWORD keyflags, UINT msg);
 	void SubProcessPointerEvent(int x, int y, DWORD keyflags);
  void ProcessMouseWheel(int delta);
	void SendPointerEvent(int x, int y, int buttonMask);
    void ProcessKeyEvent(int virtkey, DWORD keyData);
	void SendKeyEvent(CARD32 key, bool down);
	
	void ReadScreenUpdate();
	void Update(RECT *pRect);
	void SizeWindow();
	bool ScrollScreen(int dx, int dy);
	void UpdateScrollbars();
    
	void ReadRawRect(rfbFramebufferUpdateRectHeader *pfburh);
	void ReadCopyRect(rfbFramebufferUpdateRectHeader *pfburh);
    void ReadRRERect(rfbFramebufferUpdateRectHeader *pfburh);
	void ReadCoRRERect(rfbFramebufferUpdateRectHeader *pfburh);
	void ReadHextileRect(rfbFramebufferUpdateRectHeader *pfburh);
	void HandleHextileEncoding8(int x, int y, int w, int h);
	void HandleHextileEncoding16(int x, int y, int w, int h);
	void HandleHextileEncoding32(int x, int y, int w, int h);
	
	void ReadRBSRect(rfbFramebufferUpdateRectHeader *pfburh);
	BOOL DrawRBSRect8(int x, int y, int w, int h, CARD8 **pptr);
	BOOL DrawRBSRect16(int x, int y, int w, int h, CARD8 **pptr);
	BOOL DrawRBSRect32(int x, int y, int w, int h, CARD8 **pptr);

	// ClientConnectionFullScreen.cpp
	void SetFullScreenMode(bool enable);
	bool InFullScreenMode();
	void RealiseFullScreenMode();
	bool BumpScroll(int x, int y);

	// ClientConnectionClipboard.cpp
	void ProcessLocalClipboardChange();
	void UpdateLocalClipboard(char *buf, int len);
	void SendClientCutText(char *str, int len);
	void ReadServerCutText();

	void ReadBell();

	void ReadEnableExtension();
	void ReadExtensionData();
	
	void SendRFBMsg(CARD8 msgType, void* data, int length);
	void ReadExact(char *buf, int bytes);
	void ReadString(char *buf, int length);
	void WriteExact(char *buf, int bytes);

	// This is what controls the thread
	void * run_undetached(void* arg);
	bool m_bKillThread;

	// Utilities

	// These draw a solid rectangle of colour on the bitmap
	// They assume the bitmap is already selected into the DC, and the
	// DC is locked if necessary.
#ifndef UNDER_CE
	// Normally this is an inline call to a GDI method.
	inline void FillSolidRect(RECT *pRect, COLORREF color) {
		COLORREF oldbgcol = SetBkColor(m_hBitmapDC, color);
		// This is the call MFC uses for FillSolidRect. Who am I to argue?
		::ExtTextOut(m_hBitmapDC, 0, 0, ETO_OPAQUE, pRect, NULL, 0, NULL);			
	};
#else
	// Under WinCE this is a manual insert into a pixmap, 
	// and is a little too complicated for an inline.
	void FillSolidRect(RECT *pRect, COLORREF color);
#endif // UNDER_CE

	inline void FillSolidRect(int x, int y, int w, int h, COLORREF color) {
		RECT r;
		r.left = x;		r.right = x + w;
		r.top = y;		r.bottom = y + h;
		FillSolidRect(&r, color);
	};

    // how many other windows are owned by this process?
    unsigned int CountProcessOtherWindows();

    // Buffer for network operations
	void CheckBufferSize(int bufsize);
	char *m_netbuf;
	int m_netbufsize;
	omni_mutex m_bufferMutex, 
		m_bitmapdcMutex,  m_clipMutex,
          m_writeMutex, m_sockMutex;

	// Bitmap for local copy of screen, and DC for writing to it.
	HBITMAP m_hBitmap;
	HDC		m_hBitmapDC;
	HPALETTE m_hPalette;

#ifdef UNDER_CE
	// Under WinCE this points to the DIB pixels.
	BYTE* m_bits;
#endif
 
	// Keyboard mapper
	KeyMap m_keymap;

	// RFB settings
	VNCOptions m_opts;
	TCHAR *m_desktopName;
	unsigned char m_encPasswd[8];
	rfbServerInitMsg m_si;
	rfbPixelFormat m_myFormat, m_pendingFormat;
	// protocol version in use.
	int m_majorVersion, m_minorVersion;
	bool m_threadStarted, m_running;
	// mid-connection format change requested
	bool m_pendingFormatChange;
	// Display connection info;
	void ShowConnInfo();

	// Window may be scrollable - these control the scroll position
	int m_hScrollPos, m_hScrollMax, m_vScrollPos, m_vScrollMax;
	// The current window size
	int m_winwidth, m_winheight;
	// The size of the current client area
	int m_cliwidth, m_cliheight;
	// The size of a window needed to hold entire screen without scrollbars
	int m_fullwinwidth, m_fullwinheight;
	// The size of the CE CommandBar
	int m_barheight;

	// Dormant basically means minimized; updates will not be requested 
	// while dormant.
	void SetDormant(bool newstate);
	bool m_dormant;

	// The number of bytes required to hold at least one pixel.
	unsigned int m_minPixelBytes;
	// Next window in clipboard chain
	HWND m_hwndNextViewer; 
	bool m_initialClipboardSeen;		

	// Are we waiting on a timer for emulating three buttons?
	bool m_waitingOnEmulateTimer;
	// Or are we emulating the middle button now?
	bool m_emulatingMiddleButton;
	// Emulate 3 buttons mouse timer:
	UINT m_emulate3ButtonsTimer;
	// Buttons pressed, waiting for timer in emulating 3 buttons:
	DWORD m_emulateKeyFlags;
	int m_emulateButtonPressedX;
	int m_emulateButtonPressedY;

  int oldPointerX, oldPointerY, oldButtonMask;

  int kbitsPerSecond;

  rdr::FdInStream* fis;
  rdr::ZlibInStream* zis;
  void zrleDecode(int x, int y, int w, int h);
  void zrleDecode8(int x, int y, int w, int h, rdr::InStream* is,
                   rdr::ZlibInStream* zis, rdr::U8* buf);
  void zrleDecode16(int x, int y, int w, int h, rdr::InStream* is,
                    rdr::ZlibInStream* zis, rdr::U16* buf);
  void zrleDecode24A(int x, int y, int w, int h, rdr::InStream* is,
                     rdr::ZlibInStream* zis, rdr::U32* buf);
  void zrleDecode24B(int x, int y, int w, int h, rdr::InStream* is,
                     rdr::ZlibInStream* zis, rdr::U32* buf);
  void zrleDecode32(int x, int y, int w, int h, rdr::InStream* is,
                    rdr::ZlibInStream* zis, rdr::U32* buf);
};

// Some handy classes for temporary GDI object selection
// These select objects when constructed and automatically release them when destructed.
class ObjectSelector {
public:
	ObjectSelector(HDC hdc, HGDIOBJ hobj) { m_hdc = hdc; m_hOldObj = SelectObject(hdc, hobj); }
	~ObjectSelector() { m_hOldObj = SelectObject(m_hdc, m_hOldObj); }
	HGDIOBJ m_hOldObj;
	HDC m_hdc;
};

class PaletteSelector {
public:
	PaletteSelector(HDC hdc, HPALETTE hpal) { 
		m_hdc = hdc; 
		m_hOldPal = SelectPalette(hdc, hpal, FALSE); 
		RealizePalette(hdc);
	}
	~PaletteSelector() { 
		m_hOldPal = SelectPalette(m_hdc, m_hOldPal, FALSE); 
		RealizePalette(m_hdc);
	}
	HPALETTE m_hOldPal;
	HDC m_hdc;
};

class TempDC {
public:
	TempDC(HWND hwnd) { m_hdc = GetDC(hwnd); m_hwnd = hwnd; }
	~TempDC() { ReleaseDC(m_hwnd, m_hdc); }
	operator HDC() {return m_hdc;};
	HDC m_hdc;
	HWND m_hwnd;
};

// Colour decoding utility functions
// Define rs,rm, bs,bm, gs & gm before using, eg with the following:

#define SETUP_COLOR_SHORTCUTS \
	 CARD8 rs = m_myFormat.redShift;   CARD16 rm = m_myFormat.redMax;   \
     CARD8 gs = m_myFormat.greenShift; CARD16 gm = m_myFormat.greenMax; \
     CARD8 bs = m_myFormat.blueShift;  CARD16 bm = m_myFormat.blueMax;  \

// read a pixel from the given address, and return a color value
#define COLOR_FROM_PIXEL8_ADDRESS(p) (PALETTERGB( \
                (int) (((*(CARD8 *)p >> rs) & rm) * 255 / rm), \
                (int) (((*(CARD8 *)p >> gs) & gm) * 255 / gm), \
                (int) (((*(CARD8 *)p >> bs) & bm) * 255 / bm) ))

#define COLOR_FROM_PIXEL16_ADDRESS(p) (PALETTERGB( \
                (int) ((( *(CARD16 *)p >> rs) & rm) * 255 / rm), \
                (int) ((( *(CARD16 *)p >> gs) & gm) * 255 / gm), \
                (int) ((( *(CARD16 *)p >> bs) & bm) * 255 / bm) ))

#define COLOR_FROM_PIXEL32_ADDRESS(p) (PALETTERGB( \
                (int) ((( *(CARD32 *)p >> rs) & rm) * 255 / rm), \
                (int) ((( *(CARD32 *)p >> gs) & gm) * 255 / gm), \
                (int) ((( *(CARD32 *)p >> bs) & bm) * 255 / bm) ))

// The following may be faster if you already have a pixel value of the appropriate size
#define COLOR_FROM_PIXEL8(p) (PALETTERGB( \
                (int) (((p >> rs) & rm) * 255 / rm), \
                (int) (((p >> gs) & gm) * 255 / gm), \
                (int) (((p >> bs) & bm) * 255 / bm) ))

#define COLOR_FROM_PIXEL16(p) (PALETTERGB( \
                (int) ((( p >> rs) & rm) * 255 / rm), \
                (int) ((( p >> gs) & gm) * 255 / gm), \
                (int) ((( p >> bs) & bm) * 255 / bm) ))

#define COLOR_FROM_PIXEL32(p) (PALETTERGB( \
                (int) (((p >> rs) & rm) * 255 / rm), \
                (int) (((p >> gs) & gm) * 255 / gm), \
                (int) (((p >> bs) & bm) * 255 / bm) ))


#ifdef UNDER_CE
#define SETPIXEL(b,x,y,c) SetPixel((b),(x),(y),(c))
#else
#define SETPIXEL(b,x,y,c) SetPixelV((b),(x),(y),(c))
#endif

#define SETPIXELS(bpp, x, y, w, h)												\
	{																			\
		CARD##bpp *p = (CARD##bpp *) m_netbuf;									\
        register CARD##bpp pix;													\
		for (int k = y; k < y+h; k++) {											\
			for (int j = x; j < x+w; j++) {										\
                    pix = *p;													\
                    SETPIXEL(m_hBitmapDC, j,k, COLOR_FROM_PIXEL##bpp##(pix));	\
					p++;														\
			}																	\
		}																		\
	}

