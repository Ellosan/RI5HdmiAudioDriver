// RPi5HdmiAudio.cpp
#include <ntddk.h>
#include <wdf.h>
#include <portcls.h>
#include "RPi5HdmiAudio.h"

extern "C"
NTSTATUS
DriverEntry(
    _In_ PDRIVER_OBJECT  DriverObject,
    _In_ PUNICODE_STRING RegistryPath
    )
{
    WDF_DRIVER_CONFIG config;
    WDF_DRIVER_CONFIG_INIT(&config, RPi5EvtDeviceAdd);

    return WdfDriverCreate(DriverObject,
                           RegistryPath,
                           WDF_NO_OBJECT_ATTRIBUTES,
                           &config,
                           WDF_NO_HANDLE);
}

NTSTATUS
RPi5EvtDeviceAdd(
    _In_    WDFDRIVER        Driver,
    _Inout_ PWDFDEVICE_INIT  DeviceInit
    )
{
    UNREFERENCED_PARAMETER(Driver);
    PCM_FILTER_DESCRIPTOR filterDesc = &g_RPi5FilterDescriptor;

    return PcAddAdapterDevice(DeviceInit,
                              &WdfDeviceInitSetIoType,
                              nullptr,
                              0,
                              filterDesc,
                              nullptr);
}

// Hardware initialization stub
NTSTATUS
RPi5HwInitialize(
    _In_  PDEVICE_OBJECT       DeviceObject,
    _In_  PCM_RESOURCE_LIST    ResourcesRaw,
    _In_  PCM_RESOURCE_LIST    ResourcesTranslated
    )
{
    // TODO: Parse and map MMIO resources
    // TODO: Program clocks, FIFO, PCM format registers
    UNREFERENCED_PARAMETER(DeviceObject);
    UNREFERENCED_PARAMETER(ResourcesRaw);
    UNREFERENCED_PARAMETER(ResourcesTranslated);
    return STATUS_SUCCESS;
}
