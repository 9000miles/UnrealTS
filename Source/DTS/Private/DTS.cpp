// Fill out your copyright notice in the Description page of Project Settings.
#include "DTS.h"
#include "DTSHelper.h"
#include "TemplateBindingGenerator.h"

#define LOCTEXT_NAMESPACE "FDTSModule"

void FDTSModule::StartupModule()
{
#if WITH_EDITOR
	UTemplateBindingGenerator::OnGen.BindRaw(this, &FDTSModule::GenDTS);
#endif
}

void FDTSModule::ShutdownModule()
{
}

void FDTSModule::GenDTS()
{
	GenClassDTS.GenDTS();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDTSModule, DTS);
