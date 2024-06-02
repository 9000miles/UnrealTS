#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "Defines.h"
#include "TypeInfo.hpp"
#include "UEDataBinding.hpp"
#include "Helper/WidgetHelper.hpp"
#include "DTSHelper.h"
#include "PuertsEx.h"

#include "Widgets/Input/SButton.h"

UsingCppType(SButton);
UsingTSharedPtr(SButton);

namespace $SButton
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SButton::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		SET_VARIABLE__SLATE_DEFAULT_SLOT(Content);
		SET_VARIABLE__SLATE_STYLE_ARGUMENT(ButtonStyle);
		SET_VARIABLE__SLATE_STYLE_ARGUMENT(TextStyle);
		SET_VARIABLE__SLATE_ARGUMENT(HAlign);
		SET_VARIABLE__SLATE_ARGUMENT(VAlign);
		SET_VARIABLE__SLATE_ATTRIBUTE(ContentPadding);
		SET_VARIABLE__SLATE_ATTRIBUTE(Text);
		SET_VARIABLE__SLATE_EVENT(OnClicked);
		SET_VARIABLE__SLATE_EVENT(OnPressed);
		SET_VARIABLE__SLATE_EVENT(OnReleased);
		SET_VARIABLE__SLATE_EVENT(OnHovered);
		SET_VARIABLE__SLATE_EVENT(OnUnhovered);
		SET_VARIABLE__SLATE_ARGUMENT(ClickMethod);
		SET_VARIABLE__SLATE_ARGUMENT(TouchMethod);
		SET_VARIABLE__SLATE_ARGUMENT(PressMethod);
		SET_VARIABLE__SLATE_ATTRIBUTE(DesiredSizeScale);
		SET_VARIABLE__SLATE_ATTRIBUTE(ContentScale);
		SET_VARIABLE__SLATE_ATTRIBUTE(ButtonColorAndOpacity);
		SET_VARIABLE__SLATE_ATTRIBUTE(ForegroundColor);
		SET_VARIABLE__SLATE_ARGUMENT(IsFocusable);
		SET_VARIABLE__SLATE_ARGUMENT(PressedSoundOverride);
		SET_VARIABLE__SLATE_ARGUMENT(HoveredSoundOverride);
		SET_VARIABLE__SLATE_ARGUMENT(TextShapingMethod);
		SET_VARIABLE__SLATE_ARGUMENT(TextFlowDirection);
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

		SButton::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SButton> Widget = MakeTDecl<SButton>("SButton", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SButton>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SButton>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SButton>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SButton>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SButton> Widget = MakeShared<SButton>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SButton>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SButton
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments DTSArgs = DTS::DTSArguments("SButton");
		DTSArgs.Add<DTS::FSlate_Default_Slot>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		DTSArgs.Add<FButtonStyle>("ButtonStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		DTSArgs.Add<FTextBlockStyle>("TextStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		DTSArgs.Add<EHorizontalAlignment>("HAlign", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<EVerticalAlignment>("VAlign", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<FMargin>("ContentPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FText>("Text", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FOnClicked>("OnClicked", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<FSimpleDelegate>("OnPressed", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<FSimpleDelegate>("OnReleased", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<FSimpleDelegate>("OnHovered", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<FSimpleDelegate>("OnUnhovered", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<EButtonClickMethod::Type>("ClickMethod", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<EButtonClickMethod::Type>("TouchMethod", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<EButtonClickMethod::Type>("PressMethod", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<FVector2D>("DesiredSizeScale", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FVector2D>("ContentScale", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FSlateColor>("ButtonColorAndOpacity", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FSlateColor>("ForegroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<bool>("IsFocusable", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<TOptional<FSlateSound>>("PressedSoundOverride", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<TOptional<FSlateSound>>("HoveredSoundOverride", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<TOptional<ETextShapingMethod>>("TextShapingMethod", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<TOptional<ETextFlowDirection>>("TextFlowDirection", DTS::EArgType::SLATE_ARGUMENT);
		return DTSArgs;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SButton").Super("SBorder")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SButton.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SButton>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SButton>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SButton.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SButton>>::value().Data()))
				]
			);

		GenClassDTS.Add(ClassDTS);
	}

	AutoRegister_SButton()
	{
		GenDTS();
		RegisterTSharedPtr(SButton);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SButton::$SNew},
			{"SAssignNew", $SButton::$SAssignNew},
			{"MakeShared", $SButton::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SButton";
		Def.TypeId = puerts::StaticTypeId<SButton>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SBorder>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SButton _AutoRegister_SButton;

