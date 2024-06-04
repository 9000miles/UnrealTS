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

UsingCppType(SEditableText);
UsingTSharedPtr(SEditableText);

namespace $SEditableText
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SEditableText::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(Text);
		$SLATE_ATTRIBUTE(HintText);
		$SLATE_ATTRIBUTE(SearchText);
		$SLATE_STYLE_ARGUMENT(Style);
		$SLATE_ATTRIBUTE(Font);
		$SLATE_ATTRIBUTE(ColorAndOpacity);
		$SLATE_ATTRIBUTE(BackgroundImageSelected);
		$SLATE_ATTRIBUTE(BackgroundImageComposing);
		$SLATE_ATTRIBUTE(CaretImage);
		$SLATE_ATTRIBUTE(IsReadOnly);
		$SLATE_ATTRIBUTE(IsPassword);
		$SLATE_ATTRIBUTE(IsCaretMovedWhenGainFocus);
		$SLATE_ATTRIBUTE(SelectAllTextWhenFocused);
		$SLATE_ATTRIBUTE(SelectWordOnMouseDoubleClick);
		$SLATE_ATTRIBUTE(RevertTextOnEscape);
		$SLATE_ATTRIBUTE(ClearKeyboardFocusOnCommit);
		$SLATE_ATTRIBUTE(Justification);
		$SLATE_ATTRIBUTE(AllowContextMenu);
		$SLATE_EVENT(OnContextMenuOpening);
		$SLATE_EVENT(OnIsTypedCharValid);
		$SLATE_EVENT(OnTextChanged);
		$SLATE_EVENT(OnTextCommitted);
		$SLATE_ATTRIBUTE(MinDesiredWidth);
		$SLATE_ATTRIBUTE(SelectAllTextOnCommit);
		$SLATE_EVENT(OnKeyCharHandler);
		$SLATE_EVENT(OnKeyDownHandler);
		$SLATE_EVENT(ContextMenuExtender);
		$SLATE_ATTRIBUTE(VirtualKeyboardType);
		$SLATE_ARGUMENT(VirtualKeyboardOptions);
		$SLATE_ATTRIBUTE(VirtualKeyboardTrigger);
		$SLATE_ATTRIBUTE(VirtualKeyboardDismissAction);
		$SLATE_ARGUMENT(TextShapingMethod);
		$SLATE_ARGUMENT(TextFlowDirection);
		$SLATE_ARGUMENT(OverflowPolicy);
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

		SEditableText::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SEditableText> Widget = MakeTDecl<SEditableText>("SEditableText", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SEditableText>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SEditableText>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SEditableText>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SEditableText>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SEditableText> Widget = MakeShared<SEditableText>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SEditableText>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SEditableText
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SEditableText");
		Args.Add<FText>("Text", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("HintText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("SearchText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FEditableTextStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FSlateFontInfo>("Font", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("ColorAndOpacity", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<const FSlateBrush*>("BackgroundImageSelected", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<const FSlateBrush*>("BackgroundImageComposing", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<const FSlateBrush*>("CaretImage", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("IsReadOnly", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("IsPassword", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("IsCaretMovedWhenGainFocus", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SelectAllTextWhenFocused", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SelectWordOnMouseDoubleClick", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("RevertTextOnEscape", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("ClearKeyboardFocusOnCommit", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<ETextJustify::Type>("Justification", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("AllowContextMenu", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnContextMenuOpening>("OnContextMenuOpening", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnIsTypedCharValid>("OnIsTypedCharValid", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextChanged>("OnTextChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextCommitted>("OnTextCommitted", DTS::EArgType::SLATE_EVENT);
		Args.Add<float>("MinDesiredWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SelectAllTextOnCommit", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnKeyChar>("OnKeyCharHandler", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnKeyDown>("OnKeyDownHandler", DTS::EArgType::SLATE_EVENT);
		Args.Add<FMenuExtensionDelegate>("ContextMenuExtender", DTS::EArgType::SLATE_EVENT);
		Args.Add<EKeyboardType>("VirtualKeyboardType", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FVirtualKeyboardOptions>("VirtualKeyboardOptions", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EVirtualKeyboardTrigger>("VirtualKeyboardTrigger", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<EVirtualKeyboardDismissAction>("VirtualKeyboardDismissAction", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional<ETextShapingMethod>>("TextShapingMethod", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<ETextFlowDirection>>("TextFlowDirection", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<ETextOverflowPolicy>>("OverflowPolicy", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SEditableText").Super("SWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SEditableText.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SEditableText>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SEditableText>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SEditableText.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SEditableText>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SEditableText()
	{
		GenDTS();
		RegisterTSharedPtr(SEditableText);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SEditableText::$SNew},
			{"SAssignNew", $SEditableText::$SAssignNew},
			{"MakeShared", $SEditableText::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SEditableText";
		Def.TypeId = puerts::StaticTypeId<SEditableText>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SEditableText _AutoRegister_SEditableText;