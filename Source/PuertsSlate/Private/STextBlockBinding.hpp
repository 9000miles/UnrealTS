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

		CALL_SET_ATTRIBUTE_FUNCTION(FText, SetText)
		else CALL_SET_ATTRIBUTE_FUNCTION(FText, SetHighlightText)
		else CALL_SET_ATTRIBUTE_FUNCTION(FSlateFontInfo, SetFont)
			//else CALL_SET_ATTRIBUTE_FUNCTION(const FSlateBrush*, SetStrikeBrush)
		else CALL_SET_ATTRIBUTE_FUNCTION(FSlateColor, SetColorAndOpacity)
			//else CALL_SET_ATTRIBUTE_FUNCTION(const FTextBlockStyle*, SetTextStyle)
			//else CALL_SET_ATTRIBUTE_FUNCTION(ETextShapingMethod, SetTextShapingMethod)
			//else CALL_SET_ATTRIBUTE_FUNCTION(ETextFlowDirection, SetTextFlowDirection)
		else CALL_SET_ATTRIBUTE_FUNCTION(float, SetWrapTextAt)
		else CALL_SET_ATTRIBUTE_FUNCTION(bool, SetAutoWrapText)
		else CALL_SET_ATTRIBUTE_FUNCTION(ETextWrappingPolicy, SetWrappingPolicy)
		else CALL_SET_ATTRIBUTE_FUNCTION(ETextTransformPolicy, SetTransformPolicy)
			//else CALL_SET_ATTRIBUTE_FUNCTION(ETextOverflowPolicy, SetOverflowPolicy)
		else CALL_SET_ATTRIBUTE_FUNCTION(FVector2D, SetShadowOffset)
		else CALL_SET_ATTRIBUTE_FUNCTION(FLinearColor, SetShadowColorAndOpacity)
		else CALL_SET_ATTRIBUTE_FUNCTION(FLinearColor, SetHighlightColor)
		else CALL_SET_ATTRIBUTE_FUNCTION(const FSlateBrush*, SetHighlightShape)
		else CALL_SET_ATTRIBUTE_FUNCTION(float, SetMinDesiredWidth)
		else CALL_SET_ATTRIBUTE_FUNCTION(float, SetLineHeightPercentage)
		else CALL_SET_ATTRIBUTE_FUNCTION(FMargin, SetMargin)
		else CALL_SET_ATTRIBUTE_FUNCTION(ETextJustify::Type, SetJustification)
	}
};

struct AutoRegisterWidget_STextBlock
{
	void DefineArguments()
	{
		FWidgetArguments Arguments;
		REGISTER_WIDGET_ARGUMENT_TYPE__Text();
		REGISTER_WIDGET_ARGUMENT_TYPE__TextStyle();
		REGISTER_WIDGET_ARGUMENT_TYPE__Font();
		REGISTER_WIDGET_ARGUMENT_TYPE__StrikeBrush();
		REGISTER_WIDGET_ARGUMENT_TYPE__ColorAndOpacity();
		REGISTER_WIDGET_ARGUMENT_TYPE__ShadowOffset();
		REGISTER_WIDGET_ARGUMENT_TYPE__ShadowColorAndOpacity();
		REGISTER_WIDGET_ARGUMENT_TYPE__HighlightColor();
		REGISTER_WIDGET_ARGUMENT_TYPE__HighlightShape();
		REGISTER_WIDGET_ARGUMENT_TYPE__HighlightText();
		REGISTER_WIDGET_ARGUMENT_TYPE__WrapTextAt();
		REGISTER_WIDGET_ARGUMENT_TYPE__AutoWrapText();
		REGISTER_WIDGET_ARGUMENT_TYPE__WrappingPolicy();
		REGISTER_WIDGET_ARGUMENT_TYPE__TransformPolicy();
		REGISTER_WIDGET_ARGUMENT_TYPE__Margin();
		REGISTER_WIDGET_ARGUMENT_TYPE__LineHeightPercentage();
		REGISTER_WIDGET_ARGUMENT_TYPE__Justification();
		REGISTER_WIDGET_ARGUMENT_TYPE__MinDesiredWidth();
		REGISTER_WIDGET_ARGUMENT_TYPE__TextShapingMethod();
		REGISTER_WIDGET_ARGUMENT_TYPE__TextFlowDirection();
		REGISTER_WIDGET_ARGUMENT_TYPE__LineBreakPolicy();
		REGISTER_WIDGET_ARGUMENT_TYPE__OverflowPolicy();
		REGISTER_WIDGET_ARGUMENT_TYPE__SimpleTextMode();
		REGISTER_WIDGET_ARGUMENT_TYPE__OnDoubleClicked();
		UTemplateBindingGenerator::RegisterWidgetArgumentType("STextBlock", Arguments);
	}

	AutoRegisterWidget_STextBlock()
	{
		DefineArguments();

		puerts::DefineClass<STextBlock>()
			.Extends<SLeafWidget>()
			.Function("SNew", MakeFunction(&STextBlock_Extension::$SNew))
			.Function("SAssignNew", MakeFunction(&STextBlock_Extension::$SAssignNew))
			.Function("MakeShared", MakeFunction(&STextBlock_Extension::$MakeShared))
			.Method("SetMargin", MakeFunction(&STextBlock::SetMargin))
			.Method("GetText", MakeFunction(&STextBlock::GetText))
			//不能直接传string，需要TAtrribute
			//.Method("SetText", MakeFunction(&STextBlock::SetText))
			//扩展函数self传递有问题
			//.Method("SetText", MakeExtension(&STextBlock_Extension::SetText))
			.Method("SetText", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetText"))
			.Method("SetColorAndOpacity", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetColorAndOpacity"))
			.Method("SetWrapTextAt", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetWrapTextAt"))
			.Method("SetAutoWrapText", MakeExtension(&STextBlock_Extension::CallFunction_Attribute, FJsObject(), "SetAutoWrapText"))
			.Register();

		RegisterTSharedPtr(STextBlock);
	}
};

AutoRegisterWidget_STextBlock _AutoRegisterWidget_STextBlock;