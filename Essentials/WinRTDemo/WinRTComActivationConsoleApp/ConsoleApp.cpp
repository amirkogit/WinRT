#include "Precompiled.h"
#include <roapi.h>
#include <wrl.h>
#include "String.h"
#include <windows.globalization.h>

#pragma comment(lib, "runtimeobject")

using Microsoft::WRL::ComPtr;
using namespace ABI::Windows::Globalization;

int main()
{
    Check(RoInitialize(RO_INIT_MULTITHREADED));

    StringReference string(L"Windows.Globalization.Calendar");

    ComPtr<IInspectable> inspectable;

    Check(RoActivateInstance(string.Get(),
                             inspectable.GetAddressOf()));

    ComPtr<ICalendar> calendar;

    Check(inspectable.As(&calendar));

    int year = 0;

    Check(calendar->get_Year(&year));

    String month;

    Check(calendar->MonthAsFullString(month.GetAddressOf()));

    printf("%ls %d\n",
            Buffer(month),
            year);

}