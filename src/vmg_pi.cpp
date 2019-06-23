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
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif  // precompiled headers

#include "vmg_pi.h"

// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin *create_pi(void *ppimgr) { return new vmg_pi(ppimgr); }

extern "C" DECL_EXP void destroy_pi(opencpn_plugin *p) { delete p; }

//---------------------------------------------------------------------------------------------------------
//
//    Vmg PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

vmg_pi::vmg_pi(void *ppimgr) : opencpn_plugin_114(ppimgr) {
    // Create the PlugIn icons
    initialize_images();
}

int vmg_pi::Init() {
    AddLocaleCatalog(_T("opencpn-vmg_pi"));

    // Set some default private member parameters
    m_vmg_dialog_x = 0;
    m_vmg_dialog_y = 0;

    ::wxDisplaySize(&m_display_width, &m_display_height);

    //    Get a pointer to the opencpn display canvas, to use as a parent for the POI Manager dialog
    m_parent_window = GetOCPNCanvasWindow();

    //    This PlugIn needs a toolbar icon, so request its insertion
#ifdef VMG_USE_SVG
    m_leftclick_tool_id =
	InsertPlugInToolSVG(_T( "VMG" ), _svg_vmg, _svg_vmg_rollover, _svg_vmg_toggled,
			    wxITEM_CHECK, _("VMG"), _T( "" ), NULL, VMG_TOOL_POSITION, 0, this);
#else
    m_leftclick_tool_id = InsertPlugInTool(_T("VMG"), _img_vmg, _img_vmg, wxITEM_NORMAL, _("VMG"),
					   _T(""), NULL, VMG_TOOL_POSITION, 0, this);
#endif

    m_pVmgDialog = NULL;

    return (WANTS_TOOLBAR_CALLBACK | INSTALLS_TOOLBAR_TOOL | WANTS_NMEA_SENTENCES | WANTS_NMEA_EVENTS );
}

bool vmg_pi::DeInit() {
    // Record the dialog position
    if (m_pVmgDialog != NULL) {
	wxPoint p = m_pVmgDialog->GetPosition();
	SetVmgDialogX(p.x);
	SetVmgDialogY(p.y);

	m_pVmgDialog->Close();
	delete m_pVmgDialog;
	m_pVmgDialog = NULL;
    }
    return true;
}

int vmg_pi::GetAPIVersionMajor() { return MY_API_VERSION_MAJOR; }

int vmg_pi::GetAPIVersionMinor() { return MY_API_VERSION_MINOR; }

int vmg_pi::GetPlugInVersionMajor() { return PLUGIN_VERSION_MAJOR; }

int vmg_pi::GetPlugInVersionMinor() { return PLUGIN_VERSION_MINOR; }

wxBitmap *vmg_pi::GetPlugInBitmap() { return _img_vmg_pi; }

wxString vmg_pi::GetCommonName() { return _("VMG"); }

wxString vmg_pi::GetShortDescription() { return _("VMG plugin for OpenCPN"); }

wxString vmg_pi::GetLongDescription() {
    return _(
	"Velociyty Made Good for sail course optimization");
}

int vmg_pi::GetToolbarToolCount() { return 1; }

void vmg_pi::SetColorScheme(PI_ColorScheme cs) {
    if (NULL == m_pVmgDialog) return;

    DimeWindow(m_pVmgDialog);
}

void vmg_pi::OnToolbarToolCallback(int id) {
    if (m_pVmgDialog == NULL) {
	m_pVmgDialog = new VmgDlgImpl(m_parent_window);
	m_pVmgDialog->Move(wxPoint(m_vmg_dialog_x, m_vmg_dialog_y));
    }

    m_pVmgDialog->Show(!m_pVmgDialog->IsShown());
}

void vmg_pi::SetNMEASentence(wxString &sentence) {
    if (m_pVmgDialog) m_pVmgDialog->SetGPSMessage(sentence);
}

void vmg_pi::SetPositionFixEx(PlugIn_Position_Fix_Ex &pfix) {
    if (m_pVmgDialog != NULL) {
	m_pVmgDialog->SetSpeedEvent(pfix.Sog, pfix.Cog);

	// other useful info:
	// pfix.Lat, pfix.Lon
	// pfix.Hdt
	// time_t pfix.fixTime
    }
}
