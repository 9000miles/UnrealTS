#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "PuertsSlateDefines.h"
#include "TemplateBindingGenerator.h"
#include "Widgets/Layout/SBorder.h"

UsingCppType(SBorder);
UsingTSharedPtr(SBorder);
UsingTSharedRef(SBorder);

struct SBorder_Extension
{
	SBorder_Extension() { }
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

		//return MakeTDecl<SBorder>("SBorder", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs())
		//	<<= SBorder::FArguments()
		//	;
	}
	static void CallFunction_Attribute(const TSharedPtr<STextBlock> Widget, FJsObject JsObject, const FString& FunctionName)
	{
		if (!Widget.IsValid()) return;
	}
};

struct AutoRegisterWidget_SBorder
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

	AutoRegisterWidget_SBorder()
	{
		RegisterArguments();

		puerts::DefineClass<SBorder>()
			.Extends<SCompoundWidget>()
			.Function("SNew", MakeFunction(&SBorder_Extension::$SNew))
			.Function("SAssignNew", MakeFunction(&SBorder_Extension::$SAssignNew))
			.Function("MakeShared", MakeFunction(&SBorder_Extension::$MakeShared))

			//.Method("SetContent", MakeFunction(&SBorder::SetContent))
			//.Method("GetContent", MakeFunction(&SBorder::GetContent))
			//.Method("GetBorderBackgroundColor", MakeFunction(&SBorder::GetBorderBackgroundColor))

			.Method("SetBorderBackgroundColor", MakeExtension(&SBorder_Extension::CallFunction_Attribute, FJsObject(), "SetBorderBackgroundColor"))
			.Method("SetDesiredSizeScale", MakeExtension(&SBorder_Extension::CallFunction_Attribute, FJsObject(), "SetDesiredSizeScale"))
			.Method("SetHAlign", MakeExtension(&SBorder_Extension::CallFunction_Attribute, FJsObject(), "SetHAlign"))
			.Method("SetVAlign", MakeExtension(&SBorder_Extension::CallFunction_Attribute, FJsObject(), "SetVAlign"))
			.Method("SetPadding", MakeExtension(&SBorder_Extension::CallFunction_Attribute, FJsObject(), "SetPadding"))
			.Method("SetShowEffectWhenDisabled", MakeExtension(&SBorder_Extension::CallFunction_Attribute, FJsObject(), "SetShowEffectWhenDisabled"))
			.Method("SetBorderImage", MakeExtension(&SBorder_Extension::CallFunction_Attribute, FJsObject(), "SetBorderImage"))

			.Register();

		RegisterTSharedPtr(SBorder);
	}
};

AutoRegisterWidget_SBorder _AutoRegisterWidget_SBorder;

