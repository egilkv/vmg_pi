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

#include <math.h>
#include "vmggui_impl.h"

VmgDlgImpl::VmgDlgImpl(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                                               const wxSize &size, long style)
    : VmgDlg(parent, id, title, pos, size, style) {}

void VmgDlgImpl::SetGPSMessage(wxString &msg) {
    if (m_tcGPS != NULL) m_tcGPS->AppendText(msg);
}

void VmgDlgImpl::SetSpeedEvent(float speed, float course) {
    wxString msg_speed;
    wxString msg_vmg;
    wxString msg_tack;
    if (!isnan(course) && !isnan(speed) && m_windSlider) {
	// course and speed are both valid

	int wind = m_windSlider->GetValue();
	float tack_deg = course - wind; // zero means heading directly into the wind
	float vmg = speed * cos(tack_deg * 3.1415926 / 180.0);
	const wchar_t* tack_dir = _T("P"); // Port tack (wind blowing from port side)
	if (tack_deg < 0) {
	    tack_deg = -tack_deg;
	    tack_dir = _T("S"); // Starboard tack

	    // make downwind tacks negative degrees (easier to understand?)
	    if (tack_deg > 90) tack_deg = tack_deg - 180.0;
	}

	msg_speed = wxString::Format("%.1f", speed);
	msg_vmg = wxString::Format("%.1f", vmg);
	msg_tack = wxString::Format("%.1f%lc %ls", tack_deg, 0x00b0, tack_dir);
    } else {
	msg_speed = wxString::Format("---");
	msg_vmg = wxString::Format("---");
	msg_tack = wxString::Format("---");
    }
    if (m_tcSpeed != NULL) m_tcSpeed->ChangeValue(msg_speed);
    if (m_tcVmg != NULL) m_tcVmg->ChangeValue(msg_vmg);
    if (m_tcTack != NULL) m_tcTack->ChangeValue(msg_tack);
}

