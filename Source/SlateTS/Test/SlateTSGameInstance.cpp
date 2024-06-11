// Fill out your copyright notice in the Description page of Project Settings.
#include "SlateTSGameInstance.h"
#include "Interfaces/IPluginManager.h"

void USlateTSGameInstance::Init()
{

}

void USlateTSGameInstance::Shutdown()
{
	Super::Shutdown();

	if (JsEnv.IsValid())
	{
		JsEnv.Reset();
		JsEnv = nullptr;
	}
}

void USlateTSGameInstance::CopyFiles()
{
	TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("Puerts"));
	if (!Plugin.IsValid()) return;

	const FString JavaScript = TEXT("JavaScript");
	const FString PuertsJavaScript = FPaths::Combine(Plugin->GetContentDir(), JavaScript);
	if (!FPaths::DirectoryExists(PuertsJavaScript)) return;

	const FString ProjectJavaScript = FPaths::Combine(FPaths::ProjectContentDir(), JavaScript);
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	PlatformFile.CopyDirectoryTree(*ProjectJavaScript, *PuertsJavaScript, true);

}


void USlateTSGameInstance::SetTestWidget(TSharedPtr<SWidget> Widget)
{
	TestWidget = Widget;
	AddToWidget();
}

TSharedPtr<STextBlock> USlateTSGameInstance::GetTextBlock()
{
	return MyTextBlock;
}

//void UTestPuertsSlateGameInstance::SetScriptClass(ChildClass* cc)
//{
//	cc->Tick(23.34f);
//}

void USlateTSGameInstance::OnStart()
{
	Super::OnStart();
	StartScript();

	AddToWidget();


}


void USlateTSGameInstance::AddToWidget()
{
	if (!TestWidget.IsValid())
	{
		MyTextBlock = SNew(STextBlock)
			.Text(NSLOCTEXT("UTestPuertsSlateGameInstance", "KKK", "MMMMMMMMMM"))
			;

		TestWidget = MyTextBlock;
	}

	this->GetGameViewportClient()->AddViewportWidgetContent(TestWidget.ToSharedRef());
}

void USlateTSGameInstance::StartScript()
{

#if WITH_EDITOR
	CopyFiles();
#endif

	//ScriptBridge = TStrongObjectPtr<UScriptBridge>(NewObject<UScriptBridge>(this, TEXT("ScriptBridge"), RF_MarkAsRootSet));
	//ScriptBridge->GameInstance = GetGameInstance();

	FString PuertsConfigIniPath = FPaths::SourceConfigDir().Append(TEXT("DefaultPuerts.ini"));
#if ENGINE_MAJOR_VERSION >= 5 && ENGINE_MINOR_VERSION > 0
	PuertsConfigIniPath = FConfigCacheIni::NormalizeConfigIniPath(PuertsConfigIniPath);
#endif
	const TCHAR* SectionName = TEXT("/Script/Puerts.PuertsSetting");
	int32 DebugPort = 8080;
	GConfig->GetInt(SectionName, TEXT("DebugPort"), DebugPort, PuertsConfigIniPath);

	JsEnv = MakeShared<puerts::FJsEnv>(std::make_unique<puerts::DefaultJSModuleLoader>(TEXT("JavaScript")), std::make_shared<puerts::FDefaultLogger>(), DebugPort);

#if !UE_BUILD_SHIPPING
	bool bDebugEnable = false;
	GConfig->GetBool(SectionName, TEXT("DebugEnable"), bDebugEnable, PuertsConfigIniPath);

	bool bWaitDebugger = false;
	GConfig->GetBool(SectionName, TEXT("WaitDebugger"), bWaitDebugger, PuertsConfigIniPath);
	if (bDebugEnable && bWaitDebugger)
	{
		JsEnv->WaitDebugger(2.0f);
	}
#endif

	TArray<TPair<FString, UObject*>> Arguments;
	//Arguments.Add(TPair<FString, UObject*>(TEXT("ScriptBridge"), ScriptBridge.Get()));
	Arguments.Add(TPair<FString, UObject*>(TEXT("GameInstance"), this));

	FString StartScript;
	GConfig->GetString(TEXT("/Script/Puerts.PuertsSetting"), TEXT("StartScript"), StartScript, PuertsConfigIniPath);
	check(!StartScript.IsEmpty());

#if WITH_EDITOR
	//RunDocumentGenerator();
#endif

	JsEnv->Start(StartScript, Arguments);
}


UsingUClass(USlateTSGameInstance);

struct AutoRegisterMyTest
{
	AutoRegisterMyTest()
	{
		puerts::DefineClass<USlateTSGameInstance>()
			//.Method("GetTextBlock", MakeFunction(&USlateTSGameInstance::GetTextBlock))
			//.Method("SetTestWidget", MakeFunction(&USlateTSGameInstance::SetTestWidget))
			//.Method("SetScriptClass", MakeFunction(&UTestPuertsSlateGameInstance::SetScriptClass))
			.Register();

	}
};

AutoRegisterMyTest __AutoRegisterMyTest__;
