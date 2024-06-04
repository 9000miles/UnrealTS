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

UsingCppType(SMultiLineEditableTextBox);
UsingTSharedPtr(SMultiLineEditableTextBox);

namespace $SMultiLineEditableTextBox
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SMultiLineEditableTextBox::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT(Style);
		$SLATE_STYLE_ARGUMENT_DEPRECATED(TextStyle, 5.2, "TextStyle is deprecated and will be ignored. Please use the TextStyle embedded in FEditableTextBoxStyle Style.");
		$SLATE_ARGUMENT(Marshaller);
		$SLATE_ATTRIBUTE(Text);
		$SLATE_ATTRIBUTE(HintText);
		$SLATE_ATTRIBUTE(SearchText);
		$SLATE_ATTRIBUTE(Font);
		$SLATE_ATTRIBUTE(ForegroundColor);
		$SLATE_ATTRIBUTE(ReadOnlyForegroundColor);
		$SLATE_ATTRIBUTE(FocusedForegroundColor);
		$SLATE_ATTRIBUTE(Justification);
		$SLATE_ATTRIBUTE(LineHeightPercentage);
		$SLATE_ATTRIBUTE(IsReadOnly);
		$SLATE_ATTRIBUTE(AllowMultiLine);
		$SLATE_ATTRIBUTE(IsCaretMovedWhenGainFocus);
		$SLATE_ATTRIBUTE(SelectAllTextWhenFocused);
		$SLATE_ATTRIBUTE(ClearTextSelectionOnFocusLoss);
		$SLATE_ATTRIBUTE(RevertTextOnEscape);
		$SLATE_ATTRIBUTE(ClearKeyboardFocusOnCommit);
		$SLATE_ATTRIBUTE(AllowContextMenu);
		$SLATE_ARGUMENT(AlwaysShowScrollbars);
		$SLATE_ARGUMENT(HScrollBar);
		$SLATE_ARGUMENT(VScrollBar);
		$SLATE_ATTRIBUTE(HScrollBarPadding);
		$SLATE_ATTRIBUTE(VScrollBarPadding);
		$SLATE_EVENT(OnContextMenuOpening);
		$SLATE_EVENT(OnIsTypedCharValid);
		$SLATE_EVENT(OnTextChanged);
		$SLATE_EVENT(OnTextCommitted);
		$SLATE_EVENT(OnVerifyTextChanged);
		$SLATE_EVENT(OnHScrollBarUserScrolled);
		$SLATE_EVENT(OnVScrollBarUserScrolled);
		$SLATE_EVENT(OnCursorMoved);
		$SLATE_EVENT(OnKeyCharHandler);
		$SLATE_EVENT(OnKeyDownHandler);
		$SLATE_EVENT(ContextMenuExtender);
		$SLATE_EVENT(CreateSlateTextLayout);
		$SLATE_ATTRIBUTE(WrapTextAt);
		$SLATE_ATTRIBUTE(AutoWrapText);
		$SLATE_ATTRIBUTE(WrappingPolicy);
		$SLATE_ATTRIBUTE(SelectAllTextOnCommit);
		$SLATE_ATTRIBUTE(SelectWordOnMouseDoubleClick);
		$SLATE_ATTRIBUTE(BackgroundColor);
		$SLATE_ATTRIBUTE(Padding);
		$SLATE_ATTRIBUTE(Margin);
		$SLATE_ARGUMENT(ErrorReporting);
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

		SMultiLineEditableTextBox::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SMultiLineEditableTextBox> Widget = MakeTDecl<SMultiLineEditableTextBox>("SMultiLineEditableTextBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SMultiLineEditableTextBox>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SMultiLineEditableTextBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SMultiLineEditableTextBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SMultiLineEditableTextBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SMultiLineEditableTextBox> Widget = MakeShared<SMultiLineEditableTextBox>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SMultiLineEditableTextBox>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SMultiLineEditableTextBox
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SMultiLineEditableTextBox");
		Args.Add<FEditableTextBoxStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FTextBlockStyle>("TextStyle, 5.2, "TextStyle is deprecated and will be ignored. Please use the TextStyle embedded in FEditableTextBoxStyle Style."", DTS::EArgType::SLATE_STYLE_ARGUMENT_DEPRECATED);
		Args.Add<TSharedPtr< ITextLayoutMarshaller >>("Marshaller", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FText>("Text", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("HintText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("SearchText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateFontInfo>("Font", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("ForegroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("ReadOnlyForegroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("FocusedForegroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<ETextJustify::Type>("Justification", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("LineHeightPercentage", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("IsReadOnly", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("AllowMultiLine", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("IsCaretMovedWhenGainFocus", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SelectAllTextWhenFocused", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("ClearTextSelectionOnFocusLoss", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("RevertTextOnEscape", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("ClearKeyboardFocusOnCommit", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("AllowContextMenu", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("AlwaysShowScrollbars", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TSharedPtr< SScrollBar >>("HScrollBar", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TSharedPtr< SScrollBar >>("VScrollBar", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FMargin>("HScrollBarPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FMargin>("VScrollBarPadding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnContextMenuOpening>("OnContextMenuOpening", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnIsTypedCharValid>("OnIsTypedCharValid", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextChanged>("OnTextChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextCommitted>("OnTextCommitted", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnVerifyTextChanged>("OnVerifyTextChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnUserScrolled>("OnHScrollBarUserScrolled", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnUserScrolled>("OnVScrollBarUserScrolled", DTS::EArgType::SLATE_EVENT);
		Args.Add<SMultiLineEditableText::FOnCursorMoved>("OnCursorMoved", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnKeyChar>("OnKeyCharHandler", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnKeyDown>("OnKeyDownHandler", DTS::EArgType::SLATE_EVENT);
		Args.Add<FMenuExtensionDelegate>("ContextMenuExtender", DTS::EArgType::SLATE_EVENT);
		Args.Add<FCreateSlateTextLayout>("CreateSlateTextLayout", DTS::EArgType::SLATE_EVENT);
		Args.Add<float>("WrapTextAt", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("AutoWrapText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<ETextWrappingPolicy>("WrappingPolicy", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SelectAllTextOnCommit", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("SelectWordOnMouseDoubleClick", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("BackgroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FMargin>("Padding", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FMargin>("Margin", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TSharedPtr<class IErrorReportingWidget>>("ErrorReporting", DTS::EArgType::SLATE_ARGUMENT);
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
		DTS::Class ClassDTS = DTS::Class().Name("SMultiLineEditableTextBox").Super("SBorder")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SMultiLineEditableTextBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SMultiLineEditableTextBox>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SMultiLineEditableTextBox>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SMultiLineEditableTextBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SMultiLineEditableTextBox>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SMultiLineEditableTextBox()
	{
		GenDTS();
		RegisterTSharedPtr(SMultiLineEditableTextBox);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SMultiLineEditableTextBox::$SNew},
			{"SAssignNew", $SMultiLineEditableTextBox::$SAssignNew},
			{"MakeShared", $SMultiLineEditableTextBox::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SMultiLineEditableTextBox";
		Def.TypeId = puerts::StaticTypeId<SMultiLineEditableTextBox>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SBorder>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SMultiLineEditableTextBox _AutoRegister_SMultiLineEditableTextBox;