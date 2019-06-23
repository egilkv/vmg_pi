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

#include "vmggui.h"


VmgDlg::VmgDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                                       const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer* bSizer = new wxBoxSizer(wxVERTICAL);

    m_empty = wxString("---");

#if 0 // DEBUG window showing incoming NMEA stream
    m_tcGPS = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
    bSizer->Add(m_tcGPS, 1, wxALL | wxEXPAND, 5); // stretchable, border 5
#else
    m_tcGPS = NULL;
#endif

    wxStaticText *label0 =
	new wxStaticText(this, wxID_ANY, wxString(_T("Wind direction")), wxDefaultPosition, wxDefaultSize, 0, wxEmptyString);
    bSizer->Add(label0, 0, wxLEFT|wxUP|wxRIGHT, 5); // border 5 on most sides

    wxString msg = wxString::Format(_T("Wind direction"));
    m_windSlider = new wxSlider(this, wxID_ANY, 180, 0, 359, wxDefaultPosition, wxDefaultSize,
			     wxSL_HORIZONTAL | wxSL_MIN_MAX_LABELS | wxSL_VALUE_LABEL | wxSL_TICKS,
			     wxDefaultValidator,  msg);
    bSizer->Add(m_windSlider, 1, wxLEFT|wxDOWN|wxRIGHT | wxEXPAND, 5); // stretchable, border 5

    wxStaticText *label1 =
	new wxStaticText(this, wxID_ANY, wxString(_T("Velocity")), wxDefaultPosition, wxDefaultSize, 0, wxEmptyString);
    bSizer->Add(label1, 0, wxLEFT|wxUP|wxRIGHT, 5); // border 5 on most sides

    m_tcSpeed =
	new wxTextCtrl(this, wxID_ANY, m_empty, wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_CENTRE);
    m_tcSpeed->SetFont(wxFont( 24, wxDEFAULT, wxNORMAL, wxBOLD, FALSE, "", wxFONTENCODING_SYSTEM ));
    bSizer->Add(m_tcSpeed, 1, wxLEFT|wxDOWN|wxRIGHT | wxEXPAND, 5); // stretchable, border 5

    wxStaticText *label2 =
	new wxStaticText(this, wxID_ANY, wxString(_T("VMG")), wxDefaultPosition, wxDefaultSize, 0, wxEmptyString);
    bSizer->Add(label2, 0, wxLEFT|wxUP|wxRIGHT, 5); // border 5 on most sides

    m_tcVmg =
	new wxTextCtrl(this, wxID_ANY, m_empty, wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_CENTRE);
    m_tcVmg->SetFont(wxFont( 40, wxDEFAULT, wxNORMAL, wxBOLD, FALSE, "", wxFONTENCODING_SYSTEM ));
    bSizer->Add(m_tcVmg, 1, wxLEFT|wxDOWN|wxRIGHT | wxEXPAND, 5); // stretchable, border 5

    wxStaticText *label3 =
	new wxStaticText(this, wxID_ANY, wxString(_T("Apparent wind direction")), wxDefaultPosition, wxDefaultSize, 0, wxEmptyString);
    bSizer->Add(label3, 0, wxLEFT|wxUP|wxRIGHT, 5); // border 5 on most sides

    m_tcTack =
	new wxTextCtrl(this, wxID_ANY, m_empty, wxDefaultPosition, wxDefaultSize, wxTE_READONLY | wxTE_CENTRE);
    m_tcTack->SetFont(wxFont( 24, wxDEFAULT, wxNORMAL, wxBOLD, FALSE, "", wxFONTENCODING_SYSTEM ));
    bSizer->Add(m_tcTack, 1, wxLEFT|wxDOWN|wxRIGHT | wxEXPAND, 5); // stretchable, border 5

    this->SetSizer(bSizer);
    this->Layout();

    this->Centre(wxBOTH);
}

VmgDlg::~VmgDlg() {}
