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
#include "Widgets/Input/SComboButton.h"

UsingCppType(SComboButton);
UsingTSharedPtr(SComboButton);

namespace $SComboButton
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SComboButton::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		SET_VARIABLE__SLATE_STYLE_ARGUMENT(ComboButtonStyle);
		SET_VARIABLE__SLATE_STYLE_ARGUMENT(ButtonStyle);
		SET_VARIABLE__SLATE_NAMED_SLOT(ButtonContent);
		SET_VARIABLE__SLATE_NAMED_SLOT(MenuContent);
		SET_VARIABLE__SLATE_EVENT(OnGetMenuContent);
		SET_VARIABLE__SLATE_EVENT(OnMenuOpenChanged);
		SET_VARIABLE__SLATE_EVENT(OnComboBoxOpened);
		SET_VARIABLE__SLATE_ARGUMENT(IsFocusable);
		SET_VARIABLE__SLATE_ARGUMENT(HasDownArrow);
		SET_VARIABLE__SLATE_ATTRIBUTE(ForegroundColor);
		SET_VARIABLE__SLATE_ATTRIBUTE(ButtonColorAndOpacity);
		SET_VARIABLE__SLATE_ATTRIBUTE(ContentPadding);
		SET_VARIABLE__SLATE_ATTRIBUTE(MenuPlacement);
		SET_VARIABLE__SLATE_ARGUMENT(HAlign);
		SET_VARIABLE__SLATE_ARGUMENT(VAlign);
		SET_VARIABLE__SLATE_ARGUMENT(Method);
		SET_VARIABLE__SLATE_ARGUMENT(CollapseMenuOnParentFocus);
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

		SComboButton::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SComboButton> Widget = MakeTDecl<SComboButton>("SComboButton", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SComboButton>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SComboButton>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SComboButton>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SComboButton>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SComboButton> Widget = MakeShared<SComboButton>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SComboButton>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SComboButton
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments DTSArgs = DTS::DTSArguments("SComboButton");
		DTSArgs.Add<FComboButtonStyle>("ComboButtonStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		DTSArgs.Add<FButtonStyle>("ButtonStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		DTSArgs.Add<DTS::FSlate_Named_Slot>("ButtonContent", DTS::EArgType::SLATE_NAMED_SLOT);
		DTSArgs.Add<DTS::FSlate_Named_Slot>("MenuContent", DTS::EArgType::SLATE_NAMED_SLOT);
		DTSArgs.Add<FOnGetContent>("OnGetMenuContent", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<FOnIsOpenChanged>("OnMenuOpenChanged", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<FOnComboBoxOpened>("OnComboBoxOpened", DTS::EArgType::SLATE_EVENT);
		DTSArgs.Add<bool>("IsFocusable", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<bool>("HasDownArrow", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<FSlateColor>("ForegroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FSlateColor>("ButtonColorAndOpacity", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<FMargin>("ContentPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<EMenuPlacement>("MenuPlacement", DTS::EArgType::SLATE_ATTRIBUTE);
		DTSArgs.Add<EHorizontalAlignment>("HAlign", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<EVerticalAlignment>("VAlign", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<TOptional<EPopupMethod>>("Method", DTS::EArgType::SLATE_ARGUMENT);
		DTSArgs.Add<bool>("CollapseMenuOnParentFocus", DTS::EArgType::SLATE_ARGUMENT);
		return DTSArgs;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SComboButton").Super("SMenuAnchor")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SComboButton.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SComboButton>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SComboButton>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SComboButton.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SComboButton>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SComboButton()
	{
		GenDTS();
		RegisterTSharedPtr(SComboButton);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SComboButton::$SNew},
			{"SAssignNew", $SComboButton::$SAssignNew},
			{"MakeShared", $SComboButton::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SComboButton";
		Def.TypeId = puerts::StaticTypeId<SComboButton>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SMenuAnchor>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SComboButton _AutoRegister_SComboButton;