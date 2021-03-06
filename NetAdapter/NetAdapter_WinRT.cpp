// - ------------------------------------------------------------------------------------------ - //
// NET ADAPTER -- A cross platform library for getting presentable Network Adapter information.
// By Mike Kasprzak -- http://www.toonormal.com http://www.sykhronics.com -- twitter @mikekasprzak
// http://code.google.com/p/net-adapter/
//
// This is free and unencumbered software released into the public domain.
// 
// Anyone is free to copy, modify, publish, use, compile, sell, or distribute this software, either
// in source code form or as a compiled binary, for any purpose, commercial or non-commercial, and
// by any means.
// 
// In jurisdictions that recognize copyright laws, the author or authors of this software dedicate
// any and all copyright interest in the software to the public domain. We make this dedication for
// the benefit of the public at large and to the detriment of our heirs and successors. We intend 
// this dedication to be an overt act of relinquishment in perpetuity of all present and future 
// rights to this software under copyright law.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
// BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 
// For more information, please refer to <http://unlicense.org/>
// - ------------------------------------------------------------------------------------------ - //
#if defined(WINAPI_FAMILY_APP) // WinRT //
// - ------------------------------------------------------------------------------------------ - //
// http://stackoverflow.com/questions/11961771/macro-to-recognize-winrt

// Subnet Mask on WinRT
// You can use HostName.IPInformation.PrefixLength.
// See http://msdn.microsoft.com/en-us/library/windows/apps/windows.networking.connectivity.ipinformation.prefixlength.aspx
// - ------------------------------------------------------------------------------------------ - //
#include "NetAdapter.h"
#include "NetAdapter_Internal.h"
// - ------------------------------------------------------------------------------------------ - //
pNetAdapterInfo* new_pNetAdapterInfo() {
	return 0;
}
// - ------------------------------------------------------------------------------------------ - //

// - ------------------------------------------------------------------------------------------ - //
const NetAdapterInfo* get_primary_pNetAdapterInfo( const pNetAdapterInfo* Adapters ) {
	if ( Adapters ) {
		size_t Index = 0;
		
		while ( Adapters[Index] != 0 ) {
			if ( strcmp( Adapters[Index]->DNS, "" ) != 0 )
				return Adapters[Index];
			
			Index++;
		};
		
		// None Found //
		return 0;
	}
	else {
		// Hey you goof! You gave me a null pointer! //
		return 0;
	}
}
// - ------------------------------------------------------------------------------------------ - //
#endif // defined(WINAPI_FAMILY_APP) //
// - ------------------------------------------------------------------------------------------ - //
