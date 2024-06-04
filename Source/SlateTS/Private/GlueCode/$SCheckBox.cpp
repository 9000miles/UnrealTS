#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "DTSDefine.h"
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
		$SLATE_DEFAULT_SLOT(Content);
		$SLATE_STYLE_ARGUMENT_WITH_TYPE(Style, FCheckBoxStyle);
		$SLATE_ARGUMENT(Type);
		$SLATE_EVENT(OnCheckStateChanged);
		$SLATE_ATTRIBUTE(IsChecked);
		$SLATE_ARGUMENT(HAlign);
		$SLATE_ARGUMENT(CheckBoxContentUsesAutoWidth);
		$SLATE_ATTRIBUTE(Padding);
		$SLATE_ARGUMENT(ClickMethod);
		$SLATE_ARGUMENT(TouchMethod);
		$SLATE_ARGUMENT(PressMethod);
		$SLATE_ATTRIBUTE(ForegroundColor);
		$SLATE_ATTRIBUTE(BorderBackgroundColor);
		$SLATE_ARGUMENT(IsFocusable);
		$SLATE_EVENT(OnGetMenuContent);
		$SLATE_ARGUMENT(CheckedSoundOverride);
		$SLATE_ARGUMENT(UncheckedSoundOverride);
		$SLATE_ARGUMENT(HoveredSoundOverride);
		$SLATE_ARGUMENT(UncheckedImage);
		$SLATE_ARGUMENT(UncheckedHoveredImage);
		$SLATE_ARGUMENT(UncheckedPressedImage);
		$SLATE_ARGUMENT(CheckedImage);
		$SLATE_ARGUMENT(CheckedHoveredImage);
		$SLATE_ARGUMENT(CheckedPressedImage);
		$SLATE_ARGUMENT(UndeterminedImage);
		$SLATE_ARGUMENT(UndeterminedHoveredImage);
		$SLATE_ARGUMENT(UndeterminedPressedImage);
		$SLATE_ARGUMENT(BackgroundImage);
		$SLATE_ARGUMENT(BackgroundHoveredImage);
		$SLATE_ARGUMENT(BackgroundPressedImage);
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
		DTS::DTSArguments Args = DTS::DTSArguments("SCheckBox");
		Args.Add<DTS::FSlate_Default_Slot>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		Args.Add<FCheckBoxStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<TOptional<ESlateCheckBoxType::Type>>("Type", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnCheckStateChanged>("OnCheckStateChanged", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<ECheckBoxState>("IsChecked", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<EHorizontalAlignment>("HAlign", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("CheckBoxContentUsesAutoWidth", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FMargin>("Padding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<EButtonClickMethod::Type>("ClickMethod", DTS::EArgType::SLATE_EVENT);
		Args.Add<EButtonTouchMethod::Type>("TouchMethod", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EButtonPressMethod::Type>("PressMethod", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FSlateColor>("ForegroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("BorderBackgroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("IsFocusable", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnGetContent>("OnGetMenuContent", DTS::EArgType::SLATE_EVENT);
		Args.Add<TOptional<FSlateSound>>("CheckedSoundOverride", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<FSlateSound>>("UncheckedSoundOverride", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<FSlateSound>>("HoveredSoundOverride", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("UncheckedImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("UncheckedHoveredImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("UncheckedPressedImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("CheckedImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("CheckedHoveredImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("CheckedPressedImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("UndeterminedImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("UndeterminedHoveredImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("UndeterminedPressedImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("BackgroundImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("BackgroundHoveredImage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<const FSlateBrush*>("BackgroundPressedImage", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
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

		DTS::FClassDTS::Add(ClassDTS);
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
