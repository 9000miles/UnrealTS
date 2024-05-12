#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "Defines.h"
#include "TemplateBindingGenerator.h"
#include "Widgets/Input/SCheckBox.h"

UsingCppType(SCheckBox);
UsingTSharedPtr(SCheckBox);
UsingTSharedRef(SCheckBox);

class $SCheckBox :public SCheckBox
{
public:
	static TSharedPtr<SCheckBox> $MakeShared()
	{
		return ::MakeShared<SCheckBox>();
	}
	static void $SAssignNew(TSharedPtr<SCheckBox>& ExposeAs, FJsObject JsObject, FString Filename = "")
	{
		ExposeAs = $SNew(JsObject, Filename);
	}
	static TSharedPtr<SCheckBox> $SNew(FJsObject JsObject, FString Filename = "")
	{
		SCheckBox::FArguments Arguments;

		//SET_WIDGET_ARGUMENT_VARIABLE(Type);
		//SET_WIDGET_ARGUMENT_VARIABLE(OnCheckStateChanged);
		SET_WIDGET_ARGUMENT_VARIABLE(IsChecked);
		SET_WIDGET_ARGUMENT_VARIABLE(HAlign);
		SET_WIDGET_ARGUMENT_VARIABLE(CheckBoxContentUsesAutoWidth);
		SET_WIDGET_ARGUMENT_VARIABLE(Padding);
		SET_WIDGET_ARGUMENT_VARIABLE(ClickMethod);
		SET_WIDGET_ARGUMENT_VARIABLE(TouchMethod);
		SET_WIDGET_ARGUMENT_VARIABLE(PressMethod);
		SET_WIDGET_ARGUMENT_VARIABLE(ForegroundColor);
		SET_WIDGET_ARGUMENT_VARIABLE(BorderBackgroundColor);
		SET_WIDGET_ARGUMENT_VARIABLE(IsFocusable);
		SET_WIDGET_ARGUMENT_VARIABLE(CheckedSoundOverride);
		SET_WIDGET_ARGUMENT_VARIABLE(UncheckedSoundOverride);
		SET_WIDGET_ARGUMENT_VARIABLE(HoveredSoundOverride);
		SET_WIDGET_ARGUMENT_VARIABLE(UncheckedImage);
		SET_WIDGET_ARGUMENT_VARIABLE(UncheckedHoveredImage);
		SET_WIDGET_ARGUMENT_VARIABLE(UncheckedPressedImage);
		SET_WIDGET_ARGUMENT_VARIABLE(CheckedImage);
		SET_WIDGET_ARGUMENT_VARIABLE(CheckedHoveredImage);
		SET_WIDGET_ARGUMENT_VARIABLE(CheckedPressedImage);
		SET_WIDGET_ARGUMENT_VARIABLE(UndeterminedImage);
		SET_WIDGET_ARGUMENT_VARIABLE(UndeterminedHoveredImage);
		SET_WIDGET_ARGUMENT_VARIABLE(UndeterminedPressedImage);
		SET_WIDGET_ARGUMENT_VARIABLE(BackgroundImage);
		SET_WIDGET_ARGUMENT_VARIABLE(BackgroundHoveredImage);
		SET_WIDGET_ARGUMENT_VARIABLE(BackgroundPressedImage);

		return MakeTDecl<SCheckBox>("SCheckBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
	}

public:
	CALL_SET_ATTRIBUTE_FUNCTION(SetIsChecked, ECheckBoxState);
};
UsingCppType($SCheckBox);

struct AutoRegister_SCheckBox
{
	void RegisterArguments()
	{
		FArgumentsDTS Arguments;
		REGISTER_WIDGET_ARGUMENT_TYPE__Style(ESlateArgumentType::SLATE_STYLE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__Type(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__IsChecked(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__HAlign(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__CheckBoxContentUsesAutoWidth(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__Padding(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__ClickMethod(ESlateArgumentType::SLATE_EVENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnCheckStateChanged(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__TouchMethod(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__PressMethod(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__ForegroundColor(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__BorderBackgroundColor(ESlateArgumentType::SLATE_ATTRIBUTE);
		REGISTER_WIDGET_ARGUMENT_TYPE__IsFocusable(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__OnGetMenuContent(ESlateArgumentType::SLATE_EVENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__CheckedSoundOverride(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__UncheckedSoundOverride(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__HoveredSoundOverride(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__UncheckedImage(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__UncheckedHoveredImage(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__UncheckedPressedImage(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__CheckedImage(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__CheckedHoveredImage(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__CheckedPressedImage(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__UndeterminedImage(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__UndeterminedHoveredImage(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__UndeterminedPressedImage(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__BackgroundImage(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__BackgroundHoveredImage(ESlateArgumentType::SLATE_ARGUMENT);
		REGISTER_WIDGET_ARGUMENT_TYPE__BackgroundPressedImage(ESlateArgumentType::SLATE_ARGUMENT);

		UTemplateBindingGenerator::RegisterWidgetArgumentType("SCheckBox", Arguments);
	}

	AutoRegister_SCheckBox()
	{
		RegisterArguments();

		puerts::DefineClass<SCheckBox>()
			//.Extends<ParentClass>()
			.Function("SNew", MakeFunction(&$SCheckBox::$SNew))
			.Function("SAssignNew", MakeFunction(&$SCheckBox::$SAssignNew))
			.Function("MakeShared", MakeFunction(&$SCheckBox::$MakeShared))

			.Method("IsChecked", MakeFunction(&SCheckBox::IsChecked))
			.Method("GetCheckedState", MakeFunction(&SCheckBox::GetCheckedState))
			.Method("ToggleCheckedState", MakeFunction(&SCheckBox::ToggleCheckedState))
			.Method("SetIsChecked", MakeFunction(&$SCheckBox::$SetIsChecked))

			.Register();

		RegisterTSharedPtr(SCheckBox);
	}
};

AutoRegister_SCheckBox _AutoRegister_SCheckBox;