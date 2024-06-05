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

UsingCppType(SBreadcrumbTrail);
UsingTSharedPtr(SBreadcrumbTrail);

namespace $SBreadcrumbTrail
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SBreadcrumbTrail::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT(FButtonStyle, ButtonStyle, );
		$SLATE_STYLE_ARGUMENT(FTextBlockStyle, TextStyle, );
		$SLATE_ATTRIBUTE(FMargin, ButtonContentPadding, );
		$SLATE_ATTRIBUTE(const FSlateBrush*, DelimiterImage, );
		$SLATE_ATTRIBUTE(bool, ShowLeadingDelimiter, );
		$SLATE_EVENT(FOnCrumbPushed, OnCrumbPushed, );
		$SLATE_EVENT(FOnCrumbPopped, OnCrumbPopped, );
		$SLATE_EVENT(FOnCrumbClicked, OnCrumbClicked, );
		$SLATE_ARGUMENT(bool, PersistentBreadcrumbs, );
		$SLATE_EVENT(FHasCrumbMenuContent, HasCrumbMenuContent, );
		$SLATE_EVENT(FGetCrumbMenuContent, GetCrumbMenuContent, );
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

		SBreadcrumbTrail::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SBreadcrumbTrail> Widget = MakeTDecl<SBreadcrumbTrail>("SBreadcrumbTrail", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SBreadcrumbTrail>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SBreadcrumbTrail>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SBreadcrumbTrail>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SBreadcrumbTrail>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SBreadcrumbTrail> Widget = MakeShared<SBreadcrumbTrail>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SBreadcrumbTrail>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SBreadcrumbTrail
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SBreadcrumbTrail");
		Args.Add<FButtonStyle>("ButtonStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FTextBlockStyle>("TextStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FMargin>("ButtonContentPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<const FSlateBrush*>("DelimiterImage", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("ShowLeadingDelimiter", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnCrumbPushed>("OnCrumbPushed", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnCrumbPopped>("OnCrumbPopped", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnCrumbClicked>("OnCrumbClicked", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("PersistentBreadcrumbs", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FHasCrumbMenuContent>("HasCrumbMenuContent", DTS::EArgType::SLATE_EVENT);
		Args.Add<FGetCrumbMenuContent>("GetCrumbMenuContent", DTS::EArgType::SLATE_EVENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SBreadcrumbTrail").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SBreadcrumbTrail.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SBreadcrumbTrail>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SBreadcrumbTrail>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SBreadcrumbTrail.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SBreadcrumbTrail>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SBreadcrumbTrail()
	{
		GenDTS();
		RegisterTSharedPtr(SBreadcrumbTrail);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SBreadcrumbTrail::$SNew},
			{"SAssignNew", $SBreadcrumbTrail::$SAssignNew},
			{"MakeShared", $SBreadcrumbTrail::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SBreadcrumbTrail";
		Def.TypeId = puerts::StaticTypeId<SBreadcrumbTrail>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SBreadcrumbTrail _AutoRegister_SBreadcrumbTrail;