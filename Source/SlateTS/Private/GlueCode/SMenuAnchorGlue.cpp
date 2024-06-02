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

UsingCppType(SMenuAnchor);
UsingTSharedPtr(SMenuAnchor);

namespace $SMenuAnchor
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SMenuAnchor::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		//SET_VARIABLE__SLATE_DEFAULT_SLOT(Content);
		//SET_VARIABLE__SLATE_ARGUMENT(Padding);
		//SET_VARIABLE__SLATE_ARGUMENT(MenuContent);
		//SET_VARIABLE__SLATE_EVENT(OnGetMenuContent);
		//SET_VARIABLE__SLATE_EVENT(OnMenuOpenChanged);
		//SET_VARIABLE__SLATE_ATTRIBUTE(Placement);
		SET_VARIABLE__SLATE_ARGUMENT(FitInWindow);
		SET_VARIABLE__SLATE_ARGUMENT(Method);
		SET_VARIABLE__SLATE_ARGUMENT(ShouldDeferPaintingAfterWindowContent);
		SET_VARIABLE__SLATE_ARGUMENT(UseApplicationMenuStack);
		SET_VARIABLE__SLATE_ARGUMENT(IsCollapsedByParent);
		SET_VARIABLE__SLATE_ARGUMENT(ApplyWidgetStyleToMenu);
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

		SMenuAnchor::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SMenuAnchor> Widget = MakeTDecl<SMenuAnchor>("SMenuAnchor", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SMenuAnchor>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SMenuAnchor>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SMenuAnchor>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SMenuAnchor>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SMenuAnchor> Widget = MakeShared<SMenuAnchor>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SMenuAnchor>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SMenuAnchor
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments DTSArgs = DTS::DTSArguments("SMenuAnchor");
		DTSArgs.Add<DTS::FSlate_Default_Slot>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		DTSArgs.Add<FMargin>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		DTSArgs.Add<TSharedPtr<SWidget>>("MenuContent", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<FOnGetContent>("OnGetMenuContent", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<FOnIsOpenChanged>("OnMenuOpenChanged", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<EMenuPlacement>("Placement", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<bool>("FitInWindow", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<TOptional<EPopupMethod>>("Method", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<bool>("ShouldDeferPaintingAfterWindowContent", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<bool>("UseApplicationMenuStack", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<bool>("IsCollapsedByParent", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<bool>("ApplyWidgetStyleToMenu", DTS::EArgType::SLATE_ARGUMENT);
		return DTSArgs;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SMenuAnchor").Super("SPanel")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SMenuAnchor.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SMenuAnchor>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SMenuAnchor>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SMenuAnchor.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SMenuAnchor>>::value().Data()))
				]
			);

		GenClassDTS.Add(ClassDTS);
	}

	AutoRegister_SMenuAnchor()
	{
		GenDTS();
		RegisterTSharedPtr(SMenuAnchor);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SMenuAnchor::$SNew},
			{"SAssignNew", $SMenuAnchor::$SAssignNew},
			{"MakeShared", $SMenuAnchor::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SMenuAnchor";
		Def.TypeId = puerts::StaticTypeId<SMenuAnchor>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SPanel>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SMenuAnchor _AutoRegister_SMenuAnchor;