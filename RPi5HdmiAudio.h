// RPi5HdmiAudio.h
#pragma once
#include <ntddk.h>
#include <wdf.h>
#include <portcls.h>

typedef struct _DEVICE_CONTEXT {
    PVOID HdmiMmio;
} DEVICE_CONTEXT, *PDEVICE_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(DEVICE_CONTEXT, GetDeviceContext)

// Forward declarations
EVT_WDF_DRIVER_DEVICE_ADD    RPi5EvtDeviceAdd;
NTSTATUS
RPi5HwInitialize(
    _In_  PDEVICE_OBJECT       DeviceObject,
    _In_  PCM_RESOURCE_LIST    ResourcesRaw,
    _In_  PCM_RESOURCE_LIST    ResourcesTranslated
    );
extern const PCFILTER_DESCRIPTOR g_RPi5FilterDescriptor;
