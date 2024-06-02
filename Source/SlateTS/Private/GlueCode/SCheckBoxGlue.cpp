#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "Defines.h"
#include "TypeInfo.hpp"
#include "UEDataBinding.hpp"
#include "Helper/WidgetHelper.hpp"
#include "Helper/WidgetAttribute.hpp"
#include "DTSHelper.h"
#include "PuertsEx.h"
#include "GlueCode/SlateCoreGlue.h"

#include "Widgets/Input/SCheckBox.h"
#include "DTSDefine.h"

UsingCppType(SCheckBox);
UsingTSharedPtr(SCheckBox);
UsingTSharedRef(SCheckBox);

namespace $SCheckBox
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SCheckBox::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		SET_WIDGET_ARGUMENT_VARIABLE(Content);
		SET_WIDGET_ARGUMENT_VARIABLE_WITH_TYPE(Style, FCheckBoxStyle);
		SET_WIDGET_ARGUMENT_VARIABLE(Type);
		SET_WIDGET_ARGUMENT_VARIABLE(OnCheckStateChanged);
		SET_WIDGET_ARGUMENT_VARIABLE(IsChecked);
		SET_WIDGET_ARGUMENT_VARIABLE(HAlign);
		SET_WIDGET_ARGUMENT_VARIABLE(CheckBoxContentUsesAutoWidth);
		SET_WIDGET_ARGUMENT_VARIABLE(ClickMethod);
		SET_WIDGET_ARGUMENT_VARIABLE(TouchMethod);
		SET_WIDGET_ARGUMENT_VARIABLE(PressMethod);
		SET_WIDGET_ARGUMENT_VARIABLE(ForegroundColor);
		SET_WIDGET_ARGUMENT_VARIABLE(BorderBackgroundColor);
		SET_WIDGET_ARGUMENT_VARIABLE(IsFocusable);
		SET_WIDGET_ARGUMENT_VARIABLE(OnGetMenuContent);
		SET_WIDGET_ARGUMENT_VARIABLE(CheckedSoundOverride);
		SET_WIDGET_ARGUMENT_VARIABLE(UncheckedSoundOverride);
		SET_WIDGET_ARGUMENT_VARIABLE(HoveredSoundOverride);
		SET_WIDGET_ARGUMENT_VARIABLE(UncheckedImage);
		SET_WIDGET_ARGUMENT_VARIABLE(UncheckedHoveredImage);
		SET_WIDGET_ARGUMENT_VARIABLE(UncheckedPressedImage);
		SET_WIDGET_ARGUMENT_VARIABLE(CheckedImage);
		SET_WIDGET_ARGUMENT_VARIABLE(CheckedHoveredImage);
		SET_WIDGET_ARGUMENT_VARIABLE(CheckedPressedImage);
		SET_WIDGET_ARGUMENT_VARIABLE(UndeterminedImage);
		SET_WIDGET_ARGUMENT_VARIABLE(UndeterminedHoveredImage);
		SET_WIDGET_ARGUMENT_VARIABLE(UndeterminedPressedImage);
		SET_WIDGET_ARGUMENT_VARIABLE(BackgroundImage);
		SET_WIDGET_ARGUMENT_VARIABLE(BackgroundHoveredImage);
		SET_WIDGET_ARGUMENT_VARIABLE(BackgroundPressedImage);
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

		SCheckBox::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SCheckBox> Widget = MakeTDecl<SCheckBox>("SCheckBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SCheckBox>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SCheckBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SCheckBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SCheckBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SCheckBox> Widget = MakeShared<SCheckBox>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SCheckBox>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }

	static void IsChecked(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		if (Info.Length() == 0)
		{
			auto Self = puerts::converter::Converter<SCheckBox*>::toCpp(Context, Info.Holder());
			if (!Self) { puerts::DataTransfer::ThrowException(Isolate, "Attempt to access a NULL self pointer"); return; }

			auto MethodResult = Self->IsChecked();
			auto V8Result = puerts::converter::Converter<bool>::toScript(Context, MethodResult);
			Info.GetReturnValue().Set(V8Result); return;
		}
		puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!");
	}
	static void GetCheckedState(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		if (Info.Length() == 0)
		{
			auto Self = puerts::converter::Converter<SCheckBox*>::toCpp(Context, Info.Holder());
			if (!Self) { puerts::DataTransfer::ThrowException(Isolate, "Attempt to access a NULL self pointer"); return; }

			auto MethodResult = Self->GetCheckedState();
			auto V8Result = puerts::converter::Converter<ECheckBoxState>::toScript(Context, MethodResult);
			Info.GetReturnValue().Set(V8Result); return;
		}
		puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!");
	}
	static void IsPressed(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		if (Info.Length() == 0)
		{
			auto Self = puerts::converter::Converter<SCheckBox*>::toCpp(Context, Info.Holder());
			if (!Self) { puerts::DataTransfer::ThrowException(Isolate, "Attempt to access a NULL self pointer"); return; }

			auto MethodResult = Self->IsPressed();
			auto V8Result = puerts::converter::Converter<bool>::toScript(Context, MethodResult);
			Info.GetReturnValue().Set(V8Result); return;
		}
		puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!");
	}
	static void ToggleCheckedState(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		if (Info.Length() == 0)
		{
			auto Self = puerts::converter::Converter<SCheckBox*>::toCpp(Context, Info.Holder());
			if (!Self) { puerts::DataTransfer::ThrowException(Isolate, "Attempt to access a NULL self pointer"); return; }

			Self->ToggleCheckedState();
		}
		puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!");
	}
	static void SetIsChecked(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		if (Info.Length() == 1)
		{
			auto Self = puerts::converter::Converter<SCheckBox*>::toCpp(Context, Info.Holder());
			if (!Self) { puerts::DataTransfer::ThrowException(Isolate, "Attempt to access a NULL self pointer"); return; }

			TAttribute<ECheckBoxState> Value = WidgetAttribute::MakeAttribute<ECheckBoxState>(Context, Info[0]);
			Self->SetIsChecked(Value);
		}
		puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!");
	}
	static void SetContent(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		if (Info.Length() == 1)
		{
			auto Self = puerts::converter::Converter<SCheckBox*>::toCpp(Context, Info.Holder());
			if (!Self) { puerts::DataTransfer::ThrowException(Isolate, "Attempt to access a NULL self pointer"); return; }

			TSharedRef<SWidget>* Value = puerts::converter::Converter<TSharedRef<SWidget>*>::toCpp(Context, Info[0]);
			Self->SetContent(*Value);
		}
		puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!");
	}
	static void SetStyle(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		if (Info.Length() == 1)
		{
			auto Self = puerts::converter::Converter<SCheckBox*>::toCpp(Context, Info.Holder());
			if (!Self) { puerts::DataTransfer::ThrowException(Isolate, "Attempt to access a NULL self pointer"); return; }

			FCheckBoxStyle* Value = puerts::converter::Converter<FCheckBoxStyle*>::toCpp(Context, Info[0]);
			Self->SetStyle(Value);
		}
		puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!");
	}
}

struct AutoRegister_SCheckBox
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments DTSArgs = DTS::DTSArguments("SCheckBox");
		DTSArgs.Add<DTS::FSlate_Default_Slot>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		DTSArgs.Add<FCheckBoxStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		DTSArgs.Add<TOptional<ESlateCheckBoxType::Type>>("Type", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<FOnCheckStateChanged>("OnCheckStateChanged", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<ECheckBoxState>("IsChecked", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<EHorizontalAlignment>("HAlign", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<bool>("CheckBoxContentUsesAutoWidth", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<FMargin>("Padding", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<EButtonClickMethod::Type>("ClickMethod", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<EButtonTouchMethod::Type>("TouchMethod", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<EButtonPressMethod::Type>("PressMethod", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<FSlateColor>("ForegroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FSlateColor>("BorderBackgroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<bool>("IsFocusable", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<FOnGetContent>("OnGetMenuContent", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<TOptional<FSlateSound>>("CheckedSoundOverride", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<TOptional<FSlateSound>>("UncheckedSoundOverride", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<TOptional<FSlateSound>>("HoveredSoundOverride", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<const FSlateBrush*>("UncheckedImage", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<const FSlateBrush*>("UncheckedHoveredImage", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<const FSlateBrush*>("UncheckedPressedImage", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<const FSlateBrush*>("CheckedImage", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<const FSlateBrush*>("CheckedHoveredImage", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<const FSlateBrush*>("CheckedPressedImage", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<const FSlateBrush*>("UndeterminedImage", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<const FSlateBrush*>("UndeterminedHoveredImage", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<const FSlateBrush*>("UndeterminedPressedImage", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<const FSlateBrush*>("BackgroundImage", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<const FSlateBrush*>("BackgroundHoveredImage", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<const FSlateBrush*>("BackgroundPressedImage", DTS::EArgType::SLATE_ARGUMENT);
		return DTSArgs;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SCheckBox").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SCheckBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SCheckBox>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SCheckBox>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SCheckBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SCheckBox>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("IsChecked")
						.Return(DTS::Property().Type(TS_boolean))
				]
			);

		GenClassDTS.Add(ClassDTS);
	}

	AutoRegister_SCheckBox()
	{
		GenDTS();
		RegisterTSharedPtr(SCheckBox);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{"IsChecked", $SCheckBox::IsChecked},
			{"GetCheckedState", $SCheckBox::GetCheckedState},
			{"IsPressed", $SCheckBox::IsPressed},
			{"ToggleCheckedState", $SCheckBox::ToggleCheckedState},
			{"SetIsChecked", $SCheckBox::SetIsChecked},
			{"SetContent", $SCheckBox::SetContent},
			{"SetStyle", $SCheckBox::SetStyle},
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SCheckBox::$SNew},
			{"SAssignNew", $SCheckBox::$SAssignNew},
			{"MakeShared", $SCheckBox::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SCheckBox";
		Def.TypeId = puerts::StaticTypeId<SCheckBox>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SCheckBox _AutoRegister_SCheckBox;
