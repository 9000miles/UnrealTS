#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "Defines.h"
#include "TemplateBindingGenerator.h"
#include "Widgets/Input/SButton.h"

UsingCppType(SButton);
UsingTSharedPtr(SButton);

class $SButton :public SButton
{
public:
	static TSharedPtr<SButton> $MakeShared()
	{
		return ::MakeShared<SButton>();
	}
	static void $SAssignNew(TSharedPtr<SButton>& ExposeAs, FJsObject JsObject, FString Filename = "")
	{
		ExposeAs = $SNew(JsObject, Filename);
	}
	static TSharedPtr<SButton> $SNew(FJsObject JsObject, FString Filename = "")
	{
		SButton::FArguments Arguments;

		SET_WIDGET_ARGUMENT_VARIABLE(ButtonStyle);
		SET_WIDGET_ARGUMENT_VARIABLE(TextStyle);
		SET_WIDGET_ARGUMENT_VARIABLE(HAlign);
		SET_WIDGET_ARGUMENT_VARIABLE(VAlign);
		SET_WIDGET_ARGUMENT_VARIABLE(ContentPadding);
		SET_WIDGET_ARGUMENT_VARIABLE(Text);
		SET_WIDGET_ARGUMENT_VARIABLE(OnClicked);
		SET_WIDGET_ARGUMENT_VARIABLE(OnPressed);
		SET_WIDGET_ARGUMENT_VARIABLE(OnReleased);
		SET_WIDGET_ARGUMENT_VARIABLE(OnHovered);
		SET_WIDGET_ARGUMENT_VARIABLE(OnUnhovered);
		SET_WIDGET_ARGUMENT_VARIABLE(ClickMethod);
		SET_WIDGET_ARGUMENT_VARIABLE(TouchMethod);
		SET_WIDGET_ARGUMENT_VARIABLE(PressMethod);
		SET_WIDGET_ARGUMENT_VARIABLE(DesiredSizeScale);
		SET_WIDGET_ARGUMENT_VARIABLE(ContentScale);
		SET_WIDGET_ARGUMENT_VARIABLE(ButtonColorAndOpacity);
		SET_WIDGET_ARGUMENT_VARIABLE(ForegroundColor);
		SET_WIDGET_ARGUMENT_VARIABLE(IsFocusable);
		SET_WIDGET_ARGUMENT_VARIABLE(PressedSoundOverride);
		SET_WIDGET_ARGUMENT_VARIABLE(HoveredSoundOverride);
		SET_WIDGET_ARGUMENT_VARIABLE(TextShapingMethod);
		SET_WIDGET_ARGUMENT_VARIABLE(TextFlowDirection);
		return MakeTDecl<SButton>("SButton", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
	}

public:
	CALL_SET_ATTRIBUTE_FUNCTION(SetContentPadding, FMargin);
	CALL_SET_OPTIONAL_FUNCTION(SetHoveredSound, FSlateSound);
	CALL_SET_OPTIONAL_FUNCTION(SetPressedSound, FSlateSound);
	CALL_SET_ON_CLICKED_FUNCTION(SetOnClicked);
	CALL_SET_SIMPLE_DELEGATE_FUNCTION(SetOnHovered);
	CALL_SET_SIMPLE_DELEGATE_FUNCTION(SetOnUnhovered);
};
UsingCppType($SButton);

struct AutoRegister_SButton
{
	void RegisterArguments()
	{
		FArgumentsDTS Arguments;
		REGISTER_WIDGET_ARGUMENT_TYPE__ButtonStyle(ESlateArgumentType::SLATE_STYLE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__TextStyle(ESlateArgumentType::SLATE_STYLE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__HAlign(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__VAlign(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__ContentPadding(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__Text(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnClicked(ESlateArgumentType::SLATE_EVENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnPressed(ESlateArgumentType::SLATE_EVENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnReleased(ESlateArgumentType::SLATE_EVENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnHovered(ESlateArgumentType::SLATE_EVENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__ClickMethod(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__TouchMethod(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__PressMethod(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__DesiredSizeScale(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ContentScale(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ButtonColorAndOpacity(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ForegroundColor(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__IsFocusable(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__PressedSoundOverride(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__HoveredSoundOverride(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__TextShapingMethod(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__TextFlowDirection(ESlateArgumentType::SLATE_ARGUMENT);
		UTemplateBindingGenerator::RegisterWidgetArgumentType("SButton", Arguments);
	}

	AutoRegister_SButton()
	{
		RegisterArguments();

		puerts::DefineClass<SButton>()
			.Extends<SBorder>()
			.Function("SNew", MakeFunction(&$SButton::$SNew))
			.Function("SAssignNew", MakeFunction(&$SButton::$SAssignNew))
			.Function("MakeShared", MakeFunction(&$SButton::$MakeShared))

			//.Method("GetForegroundColor", MakeFunction(&SButton::GetForegroundColor))
			//.Method("GetDisabledForegroundColor", MakeFunction(&SButton::GetDisabledForegroundColor))
			.Method("IsPressed", MakeFunction(&SButton::IsPressed))

			.Method("SetContentPadding", MakeFunction(&$SButton::$SetContentPadding))
			.Method("SetHoveredSound", MakeFunction(&$SButton::$SetHoveredSound))
			.Method("SetPressedSound", MakeFunction(&$SButton::$SetPressedSound))
			.Method("SetOnClicked", MakeFunction(&$SButton::$SetOnClicked))
			.Method("SetOnHovered", MakeFunction(&$SButton::$SetOnHovered))
			.Method("SetOnUnhovered", MakeFunction(&$SButton::$SetOnUnhovered))
			.Method("SetButtonStyle", MakeFunction(&$SButton::SetButtonStyle))
			.Method("SetClickMethod", MakeFunction(&SButton::SetClickMethod))
			.Method("SetTouchMethod", MakeFunction(&SButton::SetTouchMethod))
			.Method("SetPressMethod", MakeFunction(&SButton::SetPressMethod))

			.Register();

		RegisterTSharedPtr(SButton);
	}
};

AutoRegister_SButton _AutoRegister_SButton;

