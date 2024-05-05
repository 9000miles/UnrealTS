#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "PuertsSlateDefines.h"
#include "TemplateBindingGenerator.h"
#include "Widgets/Text/STextBlock.h"
#include "WidgetArgumentHelper.hpp"

UsingCppType(STextBlock);
UsingTSharedPtr(STextBlock);

struct STextBlock_Extension
{
	STextBlock_Extension() { }
	static TSharedPtr<STextBlock> $MakeShared()
	{
		return ::MakeShared<STextBlock>();
	}
	static void $SAssignNew(TSharedPtr<STextBlock>& ExposeAs, FJsObject JsObject, FString Filename = "")
	{
		ExposeAs = $SNew(JsObject, Filename);
	}
	static TSharedPtr<STextBlock> $SNew(FJsObject JsObject, FString Filename = "")
	{
		STextBlock::FArguments Arguments;
		SET_WIDGET_ARGUMENT_VARIABLE(Text);
		SET_WIDGET_ARGUMENT_VARIABLE(TextStyle);
		SET_WIDGET_ARGUMENT_VARIABLE(Font);
		SET_WIDGET_ARGUMENT_VARIABLE(StrikeBrush);
		SET_WIDGET_ARGUMENT_VARIABLE(ColorAndOpacity);
		SET_WIDGET_ARGUMENT_VARIABLE(ShadowOffset);
		SET_WIDGET_ARGUMENT_VARIABLE(ShadowColorAndOpacity);
		SET_WIDGET_ARGUMENT_VARIABLE(HighlightColor);
		SET_WIDGET_ARGUMENT_VARIABLE(HighlightShape);
		SET_WIDGET_ARGUMENT_VARIABLE(HighlightText);
		SET_WIDGET_ARGUMENT_VARIABLE(WrapTextAt);
		SET_WIDGET_ARGUMENT_VARIABLE(AutoWrapText);
		SET_WIDGET_ARGUMENT_VARIABLE(WrappingPolicy);
		SET_WIDGET_ARGUMENT_VARIABLE(TransformPolicy);
		SET_WIDGET_ARGUMENT_VARIABLE(Margin);
		SET_WIDGET_ARGUMENT_VARIABLE(LineHeightPercentage);
		SET_WIDGET_ARGUMENT_VARIABLE(Justification);
		SET_WIDGET_ARGUMENT_VARIABLE(MinDesiredWidth);
		SET_WIDGET_ARGUMENT_VARIABLE(TextShapingMethod);
		SET_WIDGET_ARGUMENT_VARIABLE(TextFlowDirection);
		SET_WIDGET_ARGUMENT_VARIABLE(LineBreakPolicy);
		SET_WIDGET_ARGUMENT_VARIABLE(OverflowPolicy);
		SET_WIDGET_ARGUMENT_VARIABLE(SimpleTextMode);
		SET_WIDGET_ARGUMENT_VARIABLE(OnDoubleClicked);
		return MakeTDecl<STextBlock>("STextBlock", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
	}
	static void SetText(const TSharedPtr<STextBlock> TextBlock, const FText Text)
	{
		if (!TextBlock.IsValid()) return;
		TextBlock->SetText(Text);
	}
	static void CallFunction_Attribute(const TSharedPtr<STextBlock> Widget, FJsObject JsObject, const FString& FunctionName)
	{
		if (!Widget.IsValid()) return;

		//if (FunctionName == "SetText") {
		//	TAttribute<FText> Parameter = WidgetAttribute2::MakeAttribute<FText>(JsObject); Widget->SetText(Parameter);
		//}
		//else if (FunctionName == "SetWrapTextAt") {
		//	TAttribute<float> Parameter = WidgetAttribute2::MakeAttribute<float>(JsObject); Widget->SetWrapTextAt(Parameter);
		//}
		//else if (FunctionName == "SetColorAndOpacity") {
		//	TAttribute<FSlateColor> Parameter = WidgetAttribute2::MakeAttribute<FSlateColor>(JsObject); Widget->SetColorAndOpacity(Parameter);
		//}

		CALL_FUNCTION_SET__Attribute(FText, SetText);
		CALL_FUNCTION_SET__Attribute(FText, SetHighlightText);
		CALL_FUNCTION_SET__Attribute(FSlateFontInfo, SetFont);
		//CALL_SET_ATTRIBUTE_FUNCTION(const FSlateBrush*, SetStrikeBrush);
		CALL_FUNCTION_SET__Attribute(FSlateColor, SetColorAndOpacity);
		//CALL_SET_ATTRIBUTE_FUNCTION(const FTextBlockStyle*, SetTextStyle);
		//CALL_SET_ATTRIBUTE_FUNCTION(ETextShapingMethod, SetTextShapingMethod);
		//CALL_SET_ATTRIBUTE_FUNCTION(ETextFlowDirection, SetTextFlowDirection);
		CALL_FUNCTION_SET__Attribute(float, SetWrapTextAt);
		CALL_FUNCTION_SET__Attribute(bool, SetAutoWrapText);
		CALL_FUNCTION_SET__Attribute(ETextWrappingPolicy, SetWrappingPolicy);
		CALL_FUNCTION_SET__Attribute(ETextTransformPolicy, SetTransformPolicy);
		//CALL_SET_ATTRIBUTE_FUNCTION(ETextOverflowPolicy, SetOverflowPolicy);
		CALL_FUNCTION_SET__Attribute(FVector2D, SetShadowOffset);
		CALL_FUNCTION_SET__Attribute(FLinearColor, SetShadowColorAndOpacity);
		CALL_FUNCTION_SET__Attribute(FLinearColor, SetHighlightColor);
		CALL_FUNCTION_SET__Attribute(const FSlateBrush*, SetHighlightShape);
		CALL_FUNCTION_SET__Attribute(float, SetMinDesiredWidth);
		CALL_FUNCTION_SET__Attribute(float, SetLineHeightPercentage);
		CALL_FUNCTION_SET__Attribute(FMargin, SetMargin);
		CALL_FUNCTION_SET__Attribute(ETextJustify::Type, SetJustification);
	}
};

struct AutoRegisterWidget_STextBlock
{
	void RegisterArguments()
	{
		FWidgetArguments Arguments;
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
		UTemplateBindingGenerator::RegisterWidgetArgumentType("STextBlock", Arguments);
	}

	AutoRegisterWidget_STextBlock()
	{
		RegisterArguments();

		puerts::DefineClass<STextBlock>()
			.Extends<SLeafWidget>()
			.Function("SNew", MakeFunction(&STextBlock_Extension::$SNew))
			.Function("SAssignNew", MakeFunction(&STextBlock_Extension::$SAssignNew))
			.Function("MakeShared", MakeFunction(&STextBlock_Extension::$MakeShared))

			.Method("GetText", MakeFunction(&STextBlock::GetText))
			//不能直接传string，需要TAtrribute
			//.Method("SetText", MakeFunction(&STextBlock::SetText))
			//扩展函数self传递有问题
			//.Method("SetText", MakeExtension(&STextBlock_Extension::SetText))

			.Method("SetText", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetText"))
			.Method("SetHighlightText", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetHighlightText"))
			.Method("SetFont", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetFont"))
			.Method("SetColorAndOpacity", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetColorAndOpacity"))
			.Method("SetWrapTextAt", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetWrapTextAt"))
			.Method("SetAutoWrapText", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetAutoWrapText"))
			.Method("SetWrappingPolicy", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetWrappingPolicy"))
			.Method("SetTransformPolicy", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetTransformPolicy"))
			.Method("SetShadowOffset", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetShadowOffset"))
			.Method("SetShadowColorAndOpacity", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetShadowColorAndOpacity"))
			.Method("SetHighlightColor", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetHighlightColor"))
			.Method("SetMinDesiredWidth", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetMinDesiredWidth"))
			.Method("SetLineHeightPercentage", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetLineHeightPercentage"))
			.Method("SetMargin", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetMargin"))
			.Method("SetJustification", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetJustification"))

			.Register();

		RegisterTSharedPtr(STextBlock);
	}
};

AutoRegisterWidget_STextBlock _AutoRegisterWidget_STextBlock;