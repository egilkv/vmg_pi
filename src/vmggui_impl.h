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

#ifndef _VmgGUI_IMPL_H_
#define _VmgGUI_IMPL_H_

#include "vmg_pi.h"
#include "vmggui.h"

class VmgDlgImpl : public VmgDlg {
   public:
    VmgDlgImpl(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = _("VMG"),
			   const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(300, 370),
                           long style = wxDEFAULT_DIALOG_STYLE);
    void SetGPSMessage(wxString &msg);
    void SetSpeedEvent(float speed, float course);
};

#endif
