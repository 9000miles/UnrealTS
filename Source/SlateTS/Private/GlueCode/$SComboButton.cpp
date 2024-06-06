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
#include "Widgets/Input/SComboButton.h"

UsingCppType(SComboButton);
UsingTSharedPtr(SComboButton);

namespace $SComboButton
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SComboButton::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT(FComboButtonStyle, ComboButtonStyle, );
		$SLATE_STYLE_ARGUMENT(FButtonStyle, ButtonStyle, );
		$SLATE_NAMED_SLOT(FArguments, ButtonContent, );
		$SLATE_NAMED_SLOT(FArguments, MenuContent, );
		//$SLATE_EVENT(FOnGetContent, OnGetMenuContent, );
		//$SLATE_EVENT(FOnIsOpenChanged, OnMenuOpenChanged, );
		//$SLATE_EVENT(FOnComboBoxOpened, OnComboBoxOpened, );
		$SLATE_ARGUMENT(bool, IsFocusable, );
		$SLATE_ARGUMENT(bool, HasDownArrow, );
		$SLATE_ATTRIBUTE(FSlateColor, ForegroundColor, );
		$SLATE_ATTRIBUTE(FSlateColor, ButtonColorAndOpacity, );
		$SLATE_ATTRIBUTE(FMargin, ContentPadding, );
		$SLATE_ATTRIBUTE(EMenuPlacement, MenuPlacement, );
		$SLATE_ARGUMENT(EHorizontalAlignment, HAlign, );
		$SLATE_ARGUMENT(EVerticalAlignment, VAlign, );
		$SLATE_ARGUMENT(TOptional<EPopupMethod>, Method, );
		$SLATE_ARGUMENT(bool, CollapseMenuOnParentFocus, );
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
		DTS::DTSArguments Args = DTS::DTSArguments("SComboButton");
		Args.Add<FComboButtonStyle>("ComboButtonStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FButtonStyle>("ButtonStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FArguments>("ButtonContent", DTS::EArgType::SLATE_NAMED_SLOT);
		Args.Add<FArguments>("MenuContent", DTS::EArgType::SLATE_NAMED_SLOT);
		Args.Add<FOnGetContent>("OnGetMenuContent", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnIsOpenChanged>("OnMenuOpenChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnComboBoxOpened>("OnComboBoxOpened", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("IsFocusable", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("HasDownArrow", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FSlateColor>("ForegroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("ButtonColorAndOpacity", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FMargin>("ContentPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<EMenuPlacement>("MenuPlacement", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<EHorizontalAlignment>("HAlign", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EVerticalAlignment>("VAlign", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<EPopupMethod>>("Method", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("CollapseMenuOnParentFocus", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
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