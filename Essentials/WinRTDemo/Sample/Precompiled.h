/*
* Learning essentials of Windows Runtime
* References: MSDN, Pluralsight course
*
* Copyright (C) 2016  Amir Shrestha
* amirkomail@gmail.com
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
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#pragma once

#include <wrl.h>
#include <stdio.h>

#define ASSERT _ASSERTE

template<typename ...Args>
void Trace(wchar_t const * format, Args ... args)
{
    wchar_t buffer[200];
    swprintf_s(buffer, format, args ...);

    OutputDebugStringW(buffer);
}