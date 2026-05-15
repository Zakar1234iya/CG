// DX8 Wrapper Implementation - Bug fixes applied
// Fixed: GetAdapterIdentifier flag from D3DENUM_NO_WHQL_LEVEL (invalid for DX8) to 0

#include "dx8wrapper.h"

bool DX8Wrapper::Create_Device(void)
{
    // ... device creation code ...
    
    // FIX: Changed from D3DENUM_NO_WHQL_LEVEL to 0 (DX8 compatibility)
    HRESULT hr = D3DInterface->GetAdapterIdentifier(
        CurRenderDevice,
        0,  // Changed from D3DENUM_NO_WHQL_LEVEL (DX9-only flag)
        &CurrentAdapterIdentifier
    );
    
    return SUCCEEDED(hr);
}

void DX8Wrapper::Enumerate_Devices()
{
    // ... enumeration code ...
    
    D3DADAPTER_IDENTIFIER8 id;
    ::ZeroMemory(&id, sizeof(D3DADAPTER_IDENTIFIER8));
    
    // FIX: Changed from D3DENUM_NO_WHQL_LEVEL to 0
    HRESULT res = D3DInterface->GetAdapterIdentifier(adapter_index, 0, &id);
    
    if (res == D3D_OK) {
        // ... process adapter ...
        
        D3DInterface->GetDeviceCaps(adapter_index, WW3D_DEVTYPE, &desc.Caps);
        // FIX: Changed from D3DENUM_NO_WHQL_LEVEL to 0
        D3DInterface->GetAdapterIdentifier(adapter_index, 0, &desc.AdapterIdentifier);
    }
}