#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "Defines.h"
#include "TypeInfo.hpp"
#include "UEDataBinding.hpp"
#include "Helper/WidgetHelper.hpp"
#include "DTSHelper.h"
#include "DTSDefine.h"
#include "PuertsEx.h"

UsingCppType(SPanel);
UsingTSharedPtr(SPanel);

namespace $SPanel
{
	//static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SWidget::FArguments& Arguments)
	//{
	//	if (!Info[ArgumentsIndex]->IsObject()) return;

	//	v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
	//}

	//static void $SNew(const v8::FunctionCallbackInfo<v8::Value>& Info)
	//{
	//	v8::Isolate* Isolate = Info.GetIsolate();
	//	v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
	//	const uint8 InfoLength = Info.Length();
	//	if (InfoLength <= 1) { puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!"); return; }

	//	uint8 ExposeIndex = InfoLength == 3 ? 0 : -1;
	//	uint8 ArgumentsIndex = InfoLength == 3 ? 1 : 0;
	//	uint8 FilenameIndex = InfoLength == 3 ? 2 : 1;

	//	SPanel::FArguments Arguments;
	//	$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

	//	FString Filename;
	//	if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

	//	TSharedPtr<SPanel> Widget = MakeTDecl<SPanel>("SPanel", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
	//	if (InfoLength == 2)
	//	{
	//		auto V8Result = puerts::converter::Converter<TSharedPtr<SPanel>>::toScript(Context, Widget);
	//		Info.GetReturnValue().Set(V8Result); return;
	//	}

	//	if (InfoLength == 3)
	//	{
	//		auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
	//		if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
	//			puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SPanel>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
	//		{
	//			TSharedPtr<SPanel>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SPanel>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
	//			*Arg1 = Widget; return;
	//		}
	//	}
	//}
	//static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	//{
	//	v8::Isolate* Isolate = Info.GetIsolate();
	//	v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

	//	TSharedPtr<SPanel> Widget = MakeShared<SPanel>();
	//	auto V8Result = puerts::converter::Converter<TSharedPtr<SPanel>>::toScript(Context, Widget);
	//	Info.GetReturnValue().Set(V8Result);
	//}
	//static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SPanel
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments DTSArgs = DTS::DTSArguments("SPanel");
		return DTSArgs;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SPanel").Super("SWidget")
			.Arguments(RegisterArguments())
/*
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SPanel.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SPanel>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SPanel>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SPanel.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SPanel>>::value().Data()))
				]
			)*/;

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SPanel()
	{
		GenDTS();
		RegisterTSharedPtr(SPanel);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			//{"SNew", $SPanel::$SNew},
			//{"SAssignNew", $SPanel::$SAssignNew},
			//{"MakeShared", $SPanel::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SPanel";
		Def.TypeId = puerts::StaticTypeId<SPanel>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SPanel _AutoRegister_SPanel;