#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "Defines.h"
#include "TemplateBindingGenerator.h"
#include "Widgets/Text/STextBlock.h"
#include "WidgetArgumentHelper.hpp"
#include "TypeInfo.hpp"
#include "WidgetHelper.h"

UsingCppType(STextBlock);
UsingTSharedPtr(STextBlock);
UsingTSharedRef(STextBlock);

namespace $STextBlock
{
	static void $SNew(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		if (Info.Length() != 2)
		{
			puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!");
			return;
		}

		FString Filename;
		if (Info[1]->IsString())
		{
			Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[1])));
		}

		STextBlock::FArguments Arguments;
		SET_WIDGET_ARGUMENT_VARIABLE_A(Text);
		SET_WIDGET_ARGUMENT_VARIABLE_A(TextStyle);
		SET_WIDGET_ARGUMENT_VARIABLE_A(Font);
		SET_WIDGET_ARGUMENT_VARIABLE_A(StrikeBrush);
		SET_WIDGET_ARGUMENT_VARIABLE_A(ColorAndOpacity);
		SET_WIDGET_ARGUMENT_VARIABLE_A(ShadowOffset);
		SET_WIDGET_ARGUMENT_VARIABLE_A(ShadowColorAndOpacity);
		SET_WIDGET_ARGUMENT_VARIABLE_A(HighlightColor);
		SET_WIDGET_ARGUMENT_VARIABLE_A(HighlightShape);
		SET_WIDGET_ARGUMENT_VARIABLE_A(HighlightText);
		SET_WIDGET_ARGUMENT_VARIABLE_A(WrapTextAt);
		SET_WIDGET_ARGUMENT_VARIABLE_A(AutoWrapText);
		SET_WIDGET_ARGUMENT_VARIABLE_A(WrappingPolicy);
		SET_WIDGET_ARGUMENT_VARIABLE_A(TransformPolicy);
		SET_WIDGET_ARGUMENT_VARIABLE_A(Margin);
		SET_WIDGET_ARGUMENT_VARIABLE_A(LineHeightPercentage);
		SET_WIDGET_ARGUMENT_VARIABLE_A(Justification);
		SET_WIDGET_ARGUMENT_VARIABLE_A(MinDesiredWidth);
		SET_WIDGET_ARGUMENT_VARIABLE_A(TextShapingMethod);
		SET_WIDGET_ARGUMENT_VARIABLE_A(TextFlowDirection);
		SET_WIDGET_ARGUMENT_VARIABLE_A(LineBreakPolicy);
		SET_WIDGET_ARGUMENT_VARIABLE_A(OverflowPolicy);
		SET_WIDGET_ARGUMENT_VARIABLE_A(SimpleTextMode);
		SET_WIDGET_ARGUMENT_VARIABLE_A(OnDoubleClicked);
		TSharedPtr<STextBlock> Widget = MakeTDecl<STextBlock>("STextBlock", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		//auto V8Result = puerts::DataTransfer::GetPointerFast<TSharedPtr<STextBlock>>(Info.Holder());
		//Info.GetReturnValue().Set(V8Result);
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info) { TSharedPtr<STextBlock> Widget = MakeShared<STextBlock>(); }
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }

	static void GetText(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{

	}
}

struct AutoRegister_STextBlock
{
	void RegisterArguments(WidgetHelper::FArgumentsDTS& Arguments)
	{
		Arguments.Name = "STextBlock";
		REGISTER_WIDGET_ARGUMENT_TYPE__Text(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__TextStyle(ESlateArgumentType::SLATE_STYLE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__Font(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__StrikeBrush(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ColorAndOpacity(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ShadowOffset(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ShadowColorAndOpacity(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__HighlightColor(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__HighlightShape(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__HighlightText(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__WrapTextAt(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__AutoWrapText(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__WrappingPolicy(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__TransformPolicy(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__Margin(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__LineHeightPercentage(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__Justification(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__MinDesiredWidth(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__TextShapingMethod(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__TextFlowDirection(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__LineBreakPolicy(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OverflowPolicy(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__SimpleTextMode(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnDoubleClicked(ESlateArgumentType::SLATE_EVENT);
	}

	void GenDTS()
	{
		WidgetHelper::FClassDTS ClassDTS;
		ClassDTS.Name = "STextBlock";
		ClassDTS.Super = "SLeafWidget";
		RegisterArguments(ClassDTS.Arguments);

		WidgetHelper::FFunctionDTS Func_GetText;
		Func_GetText.Name = "GetText";
		Func_GetText.ReturnPara = { "", "string" };

		ClassDTS.Functions.Add(
			{
				"SNew",
				{
					{ "Arguments", "STextBlock.Arguments" },
					{ "Filename", TS_string }
				},
				{ "UE.TSharedPtr<cpp.STextBlock>" } ,
				true
			});

		ClassDTS.Functions.Add({
				"SAssignNew",
				{
					{ "WidgetRef", "UE.TSharedPtr<cpp.STextBlock>", true },
					{ "Arguments", "STextBlock.Arguments" },
					{ "Filename", TS_string }
				},
				{ "void" } ,
				true
			});

		ClassDTS.Functions.Add({
				"MakeShared",
				{
				},
				{ "UE.TSharedPtr<cpp.STextBlock>" } ,
				true
			});

		GenWidgetDTS.Add(ClassDTS);
	}

	AutoRegister_STextBlock()
	{
		GenDTS();
		RegisterTSharedPtr(STextBlock);


		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{"GetText", $STextBlock::GetText},
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $STextBlock::$SNew},
			{"SAssignNew", $STextBlock::$SAssignNew},
			{"MakeShared", $STextBlock::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "STextBlock";
		Def.SuperTypeId = puerts::StaticTypeId<SLeafWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_STextBlock _AutoRegister_STextBlock;