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

#ifndef __VMGGUI_H__
#define __VMGGUI_H__

#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/button.h>
#include <wx/colour.h>
#include <wx/dialog.h>
#include <wx/font.h>
#include <wx/gdicmn.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
#include <wx/xrc/xmlres.h>

class VmgDlg : public wxDialog {
   private:
   protected:
    wxSlider* m_windSlider;
    wxTextCtrl* m_tcGPS;
    wxTextCtrl* m_tcSpeed;
    wxTextCtrl* m_tcVmg;
    wxTextCtrl* m_tcTack;

    wxTextAttr m_attr;
    wxString m_empty;

   public:
    VmgDlg(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("OPENCPN Debugger"),
                       const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(701, 370),
                       long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    ~VmgDlg();
};

#endif  //__VMGGUI_H__
