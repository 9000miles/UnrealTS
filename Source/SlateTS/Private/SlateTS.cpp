// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlateTS.h"
#include "SlateBinding.hpp"
#include "WidgetHelper.h"

#define LOCTEXT_NAMESPACE "FSlateTSModule"

void FSlateTSModule::StartupModule()
{
#if WITH_EDITOR
	UTemplateBindingGenerator::OnGen.BindRaw(this, &FSlateTSModule::GenDTS);
#endif
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FSlateTSModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

void FSlateTSModule::GenDTS()
{
	GenWidgetDTS.GenDTS();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSlateTSModule, SlateTS)