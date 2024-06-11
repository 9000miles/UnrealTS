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
#include "Widgets/Text/SRichTextBlock.h"

UsingCppType(SRichTextBlock);
UsingTSharedPtr(SRichTextBlock);

namespace $SRichTextBlock
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SRichTextBlock::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(FText, Text, );
		$SLATE_ATTRIBUTE(FText, HighlightText, );
		$SLATE_ATTRIBUTE(float, WrapTextAt, );
		$SLATE_ATTRIBUTE(bool, AutoWrapText, );
		$SLATE_ATTRIBUTE(ETextWrappingPolicy, WrappingPolicy, );
		$SLATE_ATTRIBUTE(ETextTransformPolicy, TransformPolicy, );
		$SLATE_ARGUMENT(TSharedPtr<class FRichTextLayoutMarshaller>, Marshaller, TSharedPtr_FRichTextLayoutMarshaller);
		//$SLATE_EVENT(FCreateSlateTextLayout, CreateSlateTextLayout, );
		$SLATE_ARGUMENT(const ISlateStyle*, DecoratorStyleSet, );
		$SLATE_STYLE_ARGUMENT(FTextBlockStyle, TextStyle, FTextBlockStyle);
		$SLATE_ATTRIBUTE(FMargin, Margin, );
		$SLATE_ATTRIBUTE(float, LineHeightPercentage, );
		$SLATE_ATTRIBUTE(ETextJustify::Type, Justification, );
		$SLATE_ARGUMENT(TOptional<ETextShapingMethod>, TextShapingMethod, );
		$SLATE_ARGUMENT(TOptional<ETextFlowDirection>, TextFlowDirection, );
		//$SLATE_ARGUMENT(TArray< TSharedRef< class ITextDecorator > >, Decorators, );
		//$SLATE_ARGUMENT(TSharedPtr< class IRichTextMarkupParser >, Parser, );
		$SLATE_ARGUMENT(TOptional<ETextOverflowPolicy>, OverflowPolicy, );
		$SLATE_ATTRIBUTE(float, MinDesiredWidth, float);
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

		SRichTextBlock::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SRichTextBlock> Widget = MakeTDecl<SRichTextBlock>("SRichTextBlock", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SRichTextBlock>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SRichTextBlock>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SRichTextBlock>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SRichTextBlock>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SRichTextBlock> Widget = MakeShared<SRichTextBlock>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SRichTextBlock>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SRichTextBlock
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SRichTextBlock");
		Args.Add<FText>("Text", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("HighlightText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("WrapTextAt", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("AutoWrapText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<ETextWrappingPolicy>("WrappingPolicy", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<ETextTransformPolicy>("TransformPolicy", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TSharedPtr<class FRichTextLayoutMarshaller>>("Marshaller", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FCreateSlateTextLayout>("CreateSlateTextLayout", DTS::EArgType::SLATE_EVENT);
		Args.Add<const ISlateStyle*>("DecoratorStyleSet", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FTextBlockStyle>("TextStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FMargin>("Margin", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("LineHeightPercentage", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<ETextJustify::Type>("Justification", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional<ETextShapingMethod>>("TextShapingMethod", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<ETextFlowDirection>>("TextFlowDirection", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TArray< TSharedRef< class ITextDecorator > >>("Decorators", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TSharedPtr< class IRichTextMarkupParser >>("Parser", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<ETextOverflowPolicy>>("OverflowPolicy", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("MinDesiredWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SRichTextBlock").Super("SWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SRichTextBlock.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SRichTextBlock>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SRichTextBlock>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SRichTextBlock.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SRichTextBlock>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SRichTextBlock()
	{
		GenDTS();
		RegisterTSharedPtr(SRichTextBlock);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SRichTextBlock::$SNew},
			{"SAssignNew", $SRichTextBlock::$SAssignNew},
			{"MakeShared", $SRichTextBlock::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SRichTextBlock";
		Def.TypeId = puerts::StaticTypeId<SRichTextBlock>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SRichTextBlock _AutoRegister_SRichTextBlock;