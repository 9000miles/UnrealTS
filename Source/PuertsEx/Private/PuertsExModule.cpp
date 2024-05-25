// Fill out your copyright notice in the Description page of Project Settings.

//#include "PuertsEx.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FPuertsExModule"

class FPuertsExModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override
	{

	}
	virtual void ShutdownModule() override
	{

	}
};

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPuertsExModule, PuertsEx);
