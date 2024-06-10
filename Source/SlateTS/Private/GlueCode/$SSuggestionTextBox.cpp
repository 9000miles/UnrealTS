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
#include "Widgets/Input/SSuggestionTextBox.h"

UsingCppType(SSuggestionTextBox);
UsingTSharedPtr(SSuggestionTextBox);

namespace $SSuggestionTextBox
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SSuggestionTextBox::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(FSlateColor, BackgroundColor, );
		$SLATE_ARGUMENT(const FSlateBrush*, BackgroundImage, );
		$SLATE_ATTRIBUTE(bool, ClearKeyboardFocusOnCommit, );
		//$SLATE_ARGUMENT(TSharedPtr<class IErrorReportingWidget>, ErrorReporting, );
		$SLATE_ATTRIBUTE(FSlateFontInfo, Font, );
		$SLATE_ATTRIBUTE(FSlateColor, ForegroundColor, );
		$SLATE_ATTRIBUTE(FText, HintText, );
		$SLATE_ATTRIBUTE(bool, IsCaretMovedWhenGainFocus, );
		$SLATE_ATTRIBUTE(float, MinDesiredWidth, float);
		//$SLATE_EVENT(FOnShowingHistory, OnShowingHistory, );
		//$SLATE_EVENT(FOnShowingSuggestions, OnShowingSuggestions, );
		//$SLATE_EVENT(FOnTextChanged, OnTextChanged, );
		//$SLATE_EVENT(FOnTextCommitted, OnTextCommitted, );
		$SLATE_ATTRIBUTE(bool, RevertTextOnEscape, );
		$SLATE_ATTRIBUTE(bool, SelectAllTextOnCommit, );
		$SLATE_ATTRIBUTE(bool, SelectAllTextWhenFocused, );
		$SLATE_STYLE_ARGUMENT(FEditableTextBoxStyle, TextStyle, FEditableTextBoxStyle);
		$SLATE_STYLE_ARGUMENT(FTextBlockStyle, SuggestionTextStyle, );
		$SLATE_ATTRIBUTE(float, SuggestionListMaxHeight, );
		$SLATE_ATTRIBUTE(FText, Text, );
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

		SSuggestionTextBox::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SSuggestionTextBox> Widget = MakeTDecl<SSuggestionTextBox>("SSuggestionTextBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SSuggestionTextBox>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SSuggestionTextBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SSuggestionTextBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SSuggestionTextBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SSuggestionTextBox> Widget = MakeShared<SSuggestionTextBox>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SSuggestionTextBox>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SSuggestionTextBox
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SSuggestionTextBox");
		Args.Add<FSlateColor>("BackgroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<const FSlateBrush*>("BackgroundImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ClearKeyboardFocusOnCommit", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TSharedPtr<class IErrorReportingWidget>>("ErrorReporting", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FSlateFontInfo>("Font", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("ForegroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("HintText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("IsCaretMovedWhenGainFocus", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("MinDesiredWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnShowingHistory>("OnShowingHistory", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnShowingSuggestions>("OnShowingSuggestions", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextChanged>("OnTextChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextCommitted>("OnTextCommitted", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("RevertTextOnEscape", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SelectAllTextOnCommit", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SelectAllTextWhenFocused", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FEditableTextBoxStyle>("TextStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FTextBlockStyle>("SuggestionTextStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<float>("SuggestionListMaxHeight", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("Text", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SSuggestionTextBox").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SSuggestionTextBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SSuggestionTextBox>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SSuggestionTextBox>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SSuggestionTextBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SSuggestionTextBox>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SSuggestionTextBox()
	{
		GenDTS();
		RegisterTSharedPtr(SSuggestionTextBox);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SSuggestionTextBox::$SNew},
			{"SAssignNew", $SSuggestionTextBox::$SAssignNew},
			{"MakeShared", $SSuggestionTextBox::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SSuggestionTextBox";
		Def.TypeId = puerts::StaticTypeId<SSuggestionTextBox>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SSuggestionTextBox _AutoRegister_SSuggestionTextBox;