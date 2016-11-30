#include "Precompiled.h"
#include <roapi.h>
#include <wrl.h>
#include "String.h"
#include <windows.globalization.h>

#pragma comment(lib, "runtimeobject")

using Microsoft::WRL::ComPtr;
using namespace ABI::Windows::Globalization;

template<typename Interface, unsigned Count>
ComPtr<Interface> ActivateInstance(wchar_t const (&name)[Count])
{
    StringReference const string(name);

    ComPtr<IActivationFactory> factory;

    Check(RoGetActivationFactory(string.Get(),
                                 __uuidof(factory),
                                 reinterpret_cast<void **>(factory.GetAddressOf())));

    ComPtr<IInspectable> inspectable;

    Check(factory->ActivateInstance(inspectable.GetAddressOf()));

    ComPtr<Interface> result;
    Check(inspectable.As(&result));

    return result;
}

int main()
{
    Check(RoInitialize(RO_INIT_MULTITHREADED));

    ComPtr<ICalendar> calendar = 
        ActivateInstance<ICalendar>(L"Windows.Globalization.Calendar");

    int year = 0;

    Check(calendar->get_Year(&year));

    String month;

    Check(calendar->MonthAsFullString(month.GetAddressOf()));

    printf("%ls %d\n",
            Buffer(month),
            year);

}