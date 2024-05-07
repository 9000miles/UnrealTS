#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "Defines.h"
#include "TemplateBindingGenerator.h"
#include "Widgets/Layout/SBorder.h"

UsingCppType(SBorder);
UsingTSharedPtr(SBorder);
UsingTSharedRef(SBorder);

class $SBorder :public SBorder
{
public:
	static TSharedPtr<SBorder> $MakeShared()
	{
		return ::MakeShared<SBorder>();
	}
	static void $SAssignNew(TSharedPtr<SBorder>& ExposeAs, FJsObject JsObject, FString Filename = "")
	{
		ExposeAs = $SNew(JsObject, Filename);
	}
	static TSharedPtr<SBorder> $SNew(FJsObject JsObject, FString Filename = "")
	{
		SBorder::FArguments Arguments;

		return MakeTDecl<SBorder>("SBorder", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
	}

public:
	CALL_SET_ATTRIBUTE_FUNCTION(SetBorderBackgroundColor, FSlateColor);
	CALL_SET_ATTRIBUTE_FUNCTION(SetDesiredSizeScale, FVector2D);
	CALL_SET_ATTRIBUTE_FUNCTION(SetPadding, FMargin);
	CALL_SET_ATTRIBUTE_FUNCTION(SetShowEffectWhenDisabled, bool);
	CALL_SET_ATTRIBUTE_FUNCTION(SetBorderImage,const FSlateBrush*);
	void $SetContent(TSharedPtr<SWidget> Content) { SetContent(Content.ToSharedRef()); }
};
UsingCppType($SBorder);

struct AutoRegister_SBorder
{
	void RegisterArguments()
	{
		FWidgetArguments Arguments;
		REGISTER_WIDGET_ARGUMENT_TYPE__HAlign(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__VAlign(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__Padding(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnMouseButtonDown(ESlateArgumentType::SLATE_EVENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnMouseButtonUp(ESlateArgumentType::SLATE_EVENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnMouseMove(ESlateArgumentType::SLATE_EVENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnMouseDoubleClick(ESlateArgumentType::SLATE_EVENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__BorderImage(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ContentScale(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__DesiredSizeScale(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ColorAndOpacity(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__BorderBackgroundColor(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ForegroundColor(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ShowEffectWhenDisabled(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__FlipForRightToLeftFlowDirection(ESlateArgumentType::SLATE_ARGUMENT);
		UTemplateBindingGenerator::RegisterWidgetArgumentType("SBorder", Arguments);
	}

	AutoRegister_SBorder()
	{
		RegisterArguments();

		puerts::DefineClass<SBorder>()
			.Extends<SCompoundWidget>()
			.Function("SNew", MakeFunction(&$SBorder::$SNew))
			.Function("SAssignNew", MakeFunction(&$SBorder::$SAssignNew))
			.Function("MakeShared", MakeFunction(&$SBorder::$MakeShared))

			//.Method("SetContent", MakeFunction(&SBorder::SetContent))
			.Method("GetContent", MakeFunction(&SBorder::GetContent))
			//.Method("GetBorderBackgroundColor", MakeFunction(&SBorder::GetBorderBackgroundColor))

			.Method("SetBorderBackgroundColor", MakeFunction(&$SBorder::$SetBorderBackgroundColor))
			.Method("SetDesiredSizeScale", MakeFunction(&$SBorder::$SetDesiredSizeScale))
			.Method("SetHAlign", MakeFunction(&SBorder::SetHAlign))
			.Method("SetVAlign", MakeFunction(&SBorder::SetVAlign))
			.Method("SetPadding", MakeFunction(&$SBorder::$SetPadding))
			.Method("SetShowEffectWhenDisabled", MakeFunction(&$SBorder::$SetShowEffectWhenDisabled))
			.Method("SetBorderImage", MakeFunction(&$SBorder::$SetBorderImage))

			.Register();

		RegisterTSharedPtr(SBorder);
	}
};

AutoRegister_SBorder _AutoRegister_SBorder;

