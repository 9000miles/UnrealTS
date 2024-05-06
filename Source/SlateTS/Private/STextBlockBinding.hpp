#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "Defines.h"
#include "TemplateBindingGenerator.h"
#include "Widgets/Text/STextBlock.h"
#include "WidgetArgumentHelper.hpp"

class $STextBlock;

UsingCppType(STextBlock);
UsingTSharedPtr(STextBlock);
UsingTSharedRef(STextBlock);

struct STextBlockHelper
{
	STextBlockHelper($STextBlock* InInstance) :Instance(InInstance) {  }

	int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const;
private:
	$STextBlock* Instance;
};
UsingCppType(STextBlockHelper);

class $STextBlock :public STextBlock
{
public:
	STextBlockHelper* Super;
private:
	FJsObject JsThis;

public:
	$STextBlock(const FJsObject& JsObject) : Super(new STextBlockHelper(this)), JsThis(JsObject) {  }
	void __bind__(FJsObject JsObject) { JsThis = JsObject; }

	int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
	{
		FJsObject FuncObj = JsThis.Get<FJsObject>("OnPaint");
		//return FuncObj.Func<int32, const FPaintArgs&, const FGeometry&, const FSlateRect&, FSlateWindowElementList&, int32, const FWidgetStyle&, bool>(&JsThis, Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
		return 22;
	}

public:
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

public:
	DEFINE_ATTRIBUTE_FUNCTION(SetText, FText);
	DEFINE_ATTRIBUTE_FUNCTION(SetHighlightText, FText);
	DEFINE_ATTRIBUTE_FUNCTION(SetFont, FSlateFontInfo);
	DEFINE_ATTRIBUTE_FUNCTION(SetColorAndOpacity, FSlateColor);
	DEFINE_ATTRIBUTE_FUNCTION(SetWrapTextAt, float);
	DEFINE_ATTRIBUTE_FUNCTION(SetAutoWrapText, bool);
	DEFINE_ATTRIBUTE_FUNCTION(SetWrappingPolicy, ETextWrappingPolicy);
	DEFINE_ATTRIBUTE_FUNCTION(SetTransformPolicy, ETextTransformPolicy);
	DEFINE_ATTRIBUTE_FUNCTION(SetShadowOffset, FVector2D);
	DEFINE_ATTRIBUTE_FUNCTION(SetShadowColorAndOpacity, FLinearColor);
	DEFINE_ATTRIBUTE_FUNCTION(SetHighlightColor, FLinearColor);
	DEFINE_ATTRIBUTE_FUNCTION(SetMinDesiredWidth, float);
	DEFINE_ATTRIBUTE_FUNCTION(SetLineHeightPercentage, float);
	DEFINE_ATTRIBUTE_FUNCTION(SetMargin, FMargin);
	DEFINE_ATTRIBUTE_FUNCTION(SetJustification, ETextJustify::Type);

};
UsingCppType($STextBlock);

int32 STextBlockHelper::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	return Instance->STextBlock::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
}

struct AutoRegister_STextBlock
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

	AutoRegister_STextBlock()
	{
		RegisterArguments();

		puerts::DefineClass<STextBlock>()
			//.Constructor<FJsObject>()//添加报错
			.Extends<SLeafWidget>()
			.Property("Super", MakeProperty(&$STextBlock::Super))
			.Method("__bind__", MakeFunction(&$STextBlock::__bind__))
			.Function("SNew", MakeFunction(&$STextBlock::$SNew))
			.Function("SAssignNew", MakeFunction(&$STextBlock::$SAssignNew))
			.Function("MakeShared", MakeFunction(&$STextBlock::$MakeShared))


			.Method("GetText", MakeFunction(&STextBlock::GetText))
			//不能直接传string，需要TAtrribute
			//.Method("SetText", MakeFunction(&STextBlock::SetText))
			//扩展函数self传递有问题
			//.Method("SetText", MakeExtension(&STextBlock_Extension::SetText))

			.Method("SetText", MakeFunction(&$STextBlock::$SetText))
			.Method("SetHighlightText", MakeFunction(&$STextBlock::$SetHighlightText))
			.Method("SetFont", MakeFunction(&$STextBlock::$SetFont))
			.Method("SetColorAndOpacity", MakeFunction(&$STextBlock::$SetColorAndOpacity))
			.Method("SetWrapTextAt", MakeFunction(&$STextBlock::$SetWrapTextAt))
			.Method("SetAutoWrapText", MakeFunction(&$STextBlock::$SetAutoWrapText))
			.Method("SetWrappingPolicy", MakeFunction(&$STextBlock::$SetWrappingPolicy))
			.Method("SetTransformPolicy", MakeFunction(&$STextBlock::$SetTransformPolicy))
			.Method("SetShadowOffset", MakeFunction(&$STextBlock::$SetShadowOffset))
			.Method("SetShadowColorAndOpacity", MakeFunction(&$STextBlock::$SetShadowColorAndOpacity))
			.Method("SetHighlightColor", MakeFunction(&$STextBlock::$SetHighlightColor))
			.Method("SetMinDesiredWidth", MakeFunction(&$STextBlock::$SetMinDesiredWidth))
			.Method("SetLineHeightPercentage", MakeFunction(&$STextBlock::$SetLineHeightPercentage))
			.Method("SetMargin", MakeFunction(&$STextBlock::$SetMargin))
			.Method("SetJustification", MakeFunction(&$STextBlock::$SetJustification))
			.Register();

		puerts::DefineClass<STextBlockHelper>()
			//.Method("OnPaint", MakeFunction(&STextBlockHelper::OnPaint))
			.Register();

		RegisterTSharedPtr(STextBlock);
	}
};

AutoRegister_STextBlock _AutoRegister_STextBlock;