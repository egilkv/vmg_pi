/******************************************************************************
 * $Id$
 *
 * Project:  OpenCPN
 * Purpose:  VMG plugin
 * Author:   Egil Kvaleberg
 *
 ***************************************************************************
 *   Copyright (C) 2019 by Egil Kvaleberg                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.             *
 ***************************************************************************
 */

#ifndef _VmgPI_H_
#define _VmgPI_H_

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include <wx/glcanvas.h>
#include "wx/wx.h"
#endif  // precompiled headers

#include "version.h"

#define MY_API_VERSION_MAJOR 1
#define MY_API_VERSION_MINOR 14

#include "ocpn_plugin.h"

#include "vmggui_impl.h"

class VmgDlgImpl;

//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------

#define VMG_TOOL_POSITION -1              // request default positioning of toolbar tool

class vmg_pi : public opencpn_plugin_114 {
   public:
    vmg_pi(void *ppimgr);

    // the required PlugIn methods
    int Init();
    bool DeInit();

    int GetAPIVersionMajor();
    int GetAPIVersionMinor();
    int GetPlugInVersionMajor();
    int GetPlugInVersionMinor();
    wxBitmap *GetPlugInBitmap();
    wxString GetCommonName();
    wxString GetShortDescription();
    wxString GetLongDescription();

    // the required override PlugIn Methods
    int GetToolbarToolCount();

    void OnToolbarToolCallback(int id);

    // optional plugin overrides
    void SetColorScheme(PI_ColorScheme cs);
    void SetNMEASentence(wxString &sentence);
    void SetPositionFixEx(PlugIn_Position_Fix_Ex &pfix);

    // other public methods
    void SetVmgDialogX(int x) { m_vmg_dialog_x = x; };
    void SetVmgDialogY(int x) { m_vmg_dialog_y = x; }

    void OnVmgDialogClose();

   private:
    wxWindow *m_parent_window;

    VmgDlgImpl *m_pVmgDialog;

    int m_vmg_dialog_x, m_vmg_dialog_y;
    int m_display_width, m_display_height;

    int m_leftclick_tool_id;
};

#endif
