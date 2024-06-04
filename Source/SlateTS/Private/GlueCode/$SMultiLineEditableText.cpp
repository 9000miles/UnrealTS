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

UsingCppType(SMultiLineEditableText);
UsingTSharedPtr(SMultiLineEditableText);

namespace $SMultiLineEditableText
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SMultiLineEditableText::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(Text);
		$SLATE_ATTRIBUTE(HintText);
		$SLATE_ATTRIBUTE(SearchText);
		$SLATE_ARGUMENT(Marshaller);
		$SLATE_ATTRIBUTE(WrapTextAt);
		$SLATE_ATTRIBUTE(AutoWrapText);
		$SLATE_ATTRIBUTE(WrappingPolicy);
		$SLATE_STYLE_ARGUMENT(TextStyle);
		$SLATE_ATTRIBUTE(Font);
		$SLATE_ATTRIBUTE(Margin);
		$SLATE_ATTRIBUTE(LineHeightPercentage);
		$SLATE_ATTRIBUTE(Justification);
		$SLATE_ATTRIBUTE(IsReadOnly);
		$SLATE_ARGUMENT(HScrollBar);
		$SLATE_ARGUMENT(VScrollBar);
		$SLATE_EVENT(OnIsTypedCharValid);
		$SLATE_EVENT(OnTextChanged);
		$SLATE_EVENT(OnTextCommitted);
		$SLATE_ATTRIBUTE(AllowMultiLine);
		$SLATE_ATTRIBUTE(SelectAllTextWhenFocused);
		$SLATE_ATTRIBUTE(SelectWordOnMouseDoubleClick);
		$SLATE_ATTRIBUTE(ClearTextSelectionOnFocusLoss);
		$SLATE_ATTRIBUTE(RevertTextOnEscape);
		$SLATE_ATTRIBUTE(ClearKeyboardFocusOnCommit);
		$SLATE_ATTRIBUTE(AllowContextMenu);
		$SLATE_EVENT(OnContextMenuOpening);
		$SLATE_EVENT(OnHScrollBarUserScrolled);
		$SLATE_EVENT(OnVScrollBarUserScrolled);
		$SLATE_EVENT(OnCursorMoved);
		$SLATE_EVENT(OnKeyCharHandler);
		$SLATE_EVENT(OnKeyDownHandler);
		$SLATE_EVENT(ContextMenuExtender);
		$SLATE_EVENT(CreateSlateTextLayout);
		$SLATE_ARGUMENT(ModiferKeyForNewLine);
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

		SMultiLineEditableText::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SMultiLineEditableText> Widget = MakeTDecl<SMultiLineEditableText>("SMultiLineEditableText", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SMultiLineEditableText>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SMultiLineEditableText>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SMultiLineEditableText>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SMultiLineEditableText>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SMultiLineEditableText> Widget = MakeShared<SMultiLineEditableText>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SMultiLineEditableText>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SMultiLineEditableText
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SMultiLineEditableText");
		Args.Add<FText>("Text", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("HintText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("SearchText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TSharedPtr< ITextLayoutMarshaller >>("Marshaller", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("WrapTextAt", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("AutoWrapText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<ETextWrappingPolicy>("WrappingPolicy", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FTextBlockStyle>("TextStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FSlateFontInfo>("Font", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FMargin>("Margin", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("LineHeightPercentage", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<ETextJustify::Type>("Justification", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("IsReadOnly", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TSharedPtr< SScrollBar >>("HScrollBar", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TSharedPtr< SScrollBar >>("VScrollBar", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnIsTypedCharValid>("OnIsTypedCharValid", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextChanged>("OnTextChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextCommitted>("OnTextCommitted", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("AllowMultiLine", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SelectAllTextWhenFocused", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SelectWordOnMouseDoubleClick", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("ClearTextSelectionOnFocusLoss", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("RevertTextOnEscape", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("ClearKeyboardFocusOnCommit", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("AllowContextMenu", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnContextMenuOpening>("OnContextMenuOpening", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnUserScrolled>("OnHScrollBarUserScrolled", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnUserScrolled>("OnVScrollBarUserScrolled", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnCursorMoved>("OnCursorMoved", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnKeyChar>("OnKeyCharHandler", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnKeyDown>("OnKeyDownHandler", DTS::EArgType::SLATE_EVENT);
		Args.Add<FMenuExtensionDelegate>("ContextMenuExtender", DTS::EArgType::SLATE_EVENT);
		Args.Add<FCreateSlateTextLayout>("CreateSlateTextLayout", DTS::EArgType::SLATE_EVENT);
		Args.Add<EModifierKey::Type>("ModiferKeyForNewLine", DTS::EArgType::SLATE_ARGUMENT);
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
		DTS::Class ClassDTS = DTS::Class().Name("SMultiLineEditableText").Super("SWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SMultiLineEditableText.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SMultiLineEditableText>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SMultiLineEditableText>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SMultiLineEditableText.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SMultiLineEditableText>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SMultiLineEditableText()
	{
		GenDTS();
		RegisterTSharedPtr(SMultiLineEditableText);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SMultiLineEditableText::$SNew},
			{"SAssignNew", $SMultiLineEditableText::$SAssignNew},
			{"MakeShared", $SMultiLineEditableText::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SMultiLineEditableText";
		Def.TypeId = puerts::StaticTypeId<SMultiLineEditableText>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SMultiLineEditableText _AutoRegister_SMultiLineEditableText;