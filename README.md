# WinRT
Sandbox for learning and testing Windows Runtime.

This repository demonstrates the following :
- Sample application based on:
	- IUnknown based COM interfaces
	- IInspectable based COM interfaces
	
- Windows runtime strings demo
	- Demonstrates on usage of HSTRING, HSTRING_BUFFER ...
	
- Windows Runtime COM Activation
	- Implement COM and Windows Runtime classes with modern C++
	- ConsoleApp demonstrates how to use windows runtime activation methods. It uses ICalendar from
	Windows.Globalization.Calendar
	
- Component:
	- This project illustrates how to build a windows runtime component by using MIDL compiler and 
	.idl (Interface Definition Language)
	
- CSharpApp
	- This C# project illustrates how to consume a windows runtime component developed in standard C++.
	
References: 
- Pluralsight course on "Essentials of Windows Runtime"
- MSDN