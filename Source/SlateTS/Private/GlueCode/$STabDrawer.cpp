#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "DTSDefine.h"
#include "TypeInfo.hpp"
#include "UEDataBinding.hpp"
#include "Helper/WidgetHelper.hpp"
#include "DTSHelper.h"
#include "DTSDefine.h"
#include "PuertsEx.h"

UsingCppType(STabDrawer);
UsingTSharedPtr(STabDrawer);

namespace $STabDrawer
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, STabDrawer::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_DEFAULT_SLOT(FArguments, Content, );
		$SLATE_ARGUMENT(float, MinDrawerSize, );
		$SLATE_ARGUMENT(float, MaxDrawerSize, );
		$SLATE_ARGUMENT(float, TargetDrawerSize, );
		$SLATE_EVENT(FOnDrawerTargetSizeChanged, OnTargetDrawerSizeChanged, );
		$SLATE_EVENT(FOnDrawerFocusLost, OnDrawerFocusLost, );
		$SLATE_EVENT(FOnDrawerClosed, OnDrawerClosed, );
		$SLATE_ARGUMENT(FVector2D, ShadowOffset, );
	}

	static void $SNew(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		const uint8 InfoLength = Info.Length();
		if (InfoLength <= 1) { puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!"); return; }

		uint8 ExposeIndex = InfoLength == 3 ? 0 : -1;
		uint8 ArgumentsIndex = InfoLength == 3 ? 1 : 0;
		uint8 FilenameIndex = InfoLength == 3 ? 2 : 1;

		STabDrawer::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<STabDrawer> Widget = MakeTDecl<STabDrawer>("STabDrawer", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<STabDrawer>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<STabDrawer>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<STabDrawer>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<STabDrawer>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<STabDrawer> Widget = MakeShared<STabDrawer>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<STabDrawer>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_STabDrawer
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("STabDrawer");
		Args.Add<FArguments>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		Args.Add<float>("MinDrawerSize", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("MaxDrawerSize", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("TargetDrawerSize", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnDrawerTargetSizeChanged>("OnTargetDrawerSizeChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnDrawerFocusLost>("OnDrawerFocusLost", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnDrawerClosed>("OnDrawerClosed", DTS::EArgType::SLATE_EVENT);
		Args.Add<FVector2D>("ShadowOffset", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("STabDrawer").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("STabDrawer.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<STabDrawer>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<STabDrawer>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("STabDrawer.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<STabDrawer>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_STabDrawer()
	{
		GenDTS();
		RegisterTSharedPtr(STabDrawer);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $STabDrawer::$SNew},
			{"SAssignNew", $STabDrawer::$SAssignNew},
			{"MakeShared", $STabDrawer::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "STabDrawer";
		Def.TypeId = puerts::StaticTypeId<STabDrawer>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_STabDrawer _AutoRegister_STabDrawer;