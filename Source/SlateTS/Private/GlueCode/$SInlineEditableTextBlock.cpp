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

UsingCppType(SInlineEditableTextBlock);
UsingTSharedPtr(SInlineEditableTextBlock);

namespace $SInlineEditableTextBlock
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SInlineEditableTextBlock::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(FText, Text, );
		$SLATE_STYLE_ARGUMENT(FInlineEditableTextBlockStyle, Style, FInlineEditableTextBlockStyle);
		$SLATE_ATTRIBUTE(FSlateFontInfo, Font, );
		$SLATE_ATTRIBUTE(FSlateColor, ColorAndOpacity, );
		$SLATE_ATTRIBUTE(FVector2D, ShadowOffset, );
		$SLATE_ATTRIBUTE(FLinearColor, ShadowColorAndOpacity, );
		$SLATE_ATTRIBUTE(FText, HighlightText, );
		$SLATE_ATTRIBUTE(float, WrapTextAt, );
		$SLATE_ATTRIBUTE(ETextJustify::Type, Justification, );
		$SLATE_ARGUMENT(TSharedPtr<IBreakIterator>, LineBreakPolicy, );
		$SLATE_ATTRIBUTE(bool, IsReadOnly, );
		$SLATE_ARGUMENT(bool, MultiLine, );
		$SLATE_ARGUMENT(EModifierKey::Type, ModiferKeyForNewLine, );
		//$SLATE_EVENT(FOnBeginTextEdit, OnBeginTextEdit, );
		//$SLATE_EVENT(FOnTextCommitted, OnTextCommitted, );
		//$SLATE_EVENT(FSimpleDelegate, OnEnterEditingMode, );
		//$SLATE_EVENT(FSimpleDelegate, OnExitEditingMode, );
		//$SLATE_EVENT(FIsSelected, IsSelected, );
		//$SLATE_EVENT(FOnVerifyTextChanged, OnVerifyTextChanged, );
		$SLATE_ARGUMENT(TOptional<ETextOverflowPolicy>, OverflowPolicy, );
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

		SInlineEditableTextBlock::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SInlineEditableTextBlock> Widget = MakeTDecl<SInlineEditableTextBlock>("SInlineEditableTextBlock", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SInlineEditableTextBlock>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SInlineEditableTextBlock>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SInlineEditableTextBlock>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SInlineEditableTextBlock>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SInlineEditableTextBlock> Widget = MakeShared<SInlineEditableTextBlock>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SInlineEditableTextBlock>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SInlineEditableTextBlock
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SInlineEditableTextBlock");
		Args.Add<FText>("Text", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FInlineEditableTextBlockStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FSlateFontInfo>("Font", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("ColorAndOpacity", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FVector2D>("ShadowOffset", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FLinearColor>("ShadowColorAndOpacity", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("HighlightText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("WrapTextAt", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<ETextJustify::Type>("Justification", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TSharedPtr<IBreakIterator>>("LineBreakPolicy", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("IsReadOnly", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("MultiLine", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EModifierKey::Type>("ModiferKeyForNewLine", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnBeginTextEdit>("OnBeginTextEdit", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextCommitted>("OnTextCommitted", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnEnterEditingMode", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnExitEditingMode", DTS::EArgType::SLATE_EVENT);
		Args.Add<FIsSelected>("IsSelected", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnVerifyTextChanged>("OnVerifyTextChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<TOptional<ETextOverflowPolicy>>("OverflowPolicy", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SInlineEditableTextBlock").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SInlineEditableTextBlock.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SInlineEditableTextBlock>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SInlineEditableTextBlock>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SInlineEditableTextBlock.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SInlineEditableTextBlock>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SInlineEditableTextBlock()
	{
		GenDTS();
		RegisterTSharedPtr(SInlineEditableTextBlock);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SInlineEditableTextBlock::$SNew},
			{"SAssignNew", $SInlineEditableTextBlock::$SAssignNew},
			{"MakeShared", $SInlineEditableTextBlock::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SInlineEditableTextBlock";
		Def.TypeId = puerts::StaticTypeId<SInlineEditableTextBlock>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SInlineEditableTextBlock _AutoRegister_SInlineEditableTextBlock;