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
#include "Widgets/Input/SInputKeySelector.h"

UsingCppType(SInputKeySelector);
UsingTSharedPtr(SInputKeySelector);

namespace $SInputKeySelector
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SInputKeySelector::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(FInputChord, SelectedKey, );
		$SLATE_ATTRIBUTE(FSlateFontInfo, Font, );
		$SLATE_ATTRIBUTE(FMargin, Margin, );
		$SLATE_STYLE_ARGUMENT(FButtonStyle, ButtonStyle, );
		$SLATE_STYLE_ARGUMENT(FTextBlockStyle, TextStyle, FTextBlockStyle);
		$SLATE_ARGUMENT(FText, KeySelectionText, );
		$SLATE_ARGUMENT(FText, NoKeySpecifiedText, );
		$SLATE_ARGUMENT(bool, AllowModifierKeys, );
		$SLATE_ARGUMENT(bool, AllowGamepadKeys, );
		$SLATE_ARGUMENT(bool, EscapeCancelsSelection, );
		$SLATE_ARGUMENT(TArray<FKey>, EscapeKeys, );
		//$SLATE_EVENT(FOnKeySelected, OnKeySelected, );
		//$SLATE_EVENT(FOnIsSelectingKeyChanged, OnIsSelectingKeyChanged, );
		$SLATE_ARGUMENT(bool, IsFocusable, );
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

		SInputKeySelector::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SInputKeySelector> Widget = MakeTDecl<SInputKeySelector>("SInputKeySelector", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SInputKeySelector>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SInputKeySelector>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SInputKeySelector>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SInputKeySelector>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SInputKeySelector> Widget = MakeShared<SInputKeySelector>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SInputKeySelector>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SInputKeySelector
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SInputKeySelector");
		Args.Add<FInputChord>("SelectedKey", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateFontInfo>("Font", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FMargin>("Margin", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FButtonStyle>("ButtonStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FTextBlockStyle>("TextStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FText>("KeySelectionText", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FText>("NoKeySpecifiedText", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("AllowModifierKeys", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("AllowGamepadKeys", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("EscapeCancelsSelection", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TArray<FKey>>("EscapeKeys", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<SInputKeySelector::FOnKeySelected>("OnKeySelected", DTS::EArgType::SLATE_EVENT);
		Args.Add<SInputKeySelector::FOnIsSelectingKeyChanged>("OnIsSelectingKeyChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("IsFocusable", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SInputKeySelector").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SInputKeySelector.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SInputKeySelector>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SInputKeySelector>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SInputKeySelector.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SInputKeySelector>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SInputKeySelector()
	{
		GenDTS();
		RegisterTSharedPtr(SInputKeySelector);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SInputKeySelector::$SNew},
			{"SAssignNew", $SInputKeySelector::$SAssignNew},
			{"MakeShared", $SInputKeySelector::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SInputKeySelector";
		Def.TypeId = puerts::StaticTypeId<SInputKeySelector>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SInputKeySelector _AutoRegister_SInputKeySelector;