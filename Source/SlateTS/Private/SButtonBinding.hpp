#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "PuertsSlateDefines.h"
#include "TemplateBindingGenerator.h"
#include "Widgets/Input/SButton.h"

UsingCppType(SButton);
UsingTSharedPtr(SButton);

struct SButton_Extension
{
	SButton_Extension() { }
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

		SET_WIDGET_ARGUMENT_VARIABLE(Text);
		SET_WIDGET_ARGUMENT_VARIABLE(OnClicked);
		//WidgetArgument::Set_OnClicked1(Arguments, JsObject, "OnClicked");;
		//WidgetArgument::Set_OnClicked<SButton::FArguments >(Arguments, JsObject, "OnClicked");;
		//const char* VariableName = "OnClicked";
		//if (JsObject.Has(VariableName))
		//{
		//	auto ClickFunc = JsObject.Get<std::function<void()>>(VariableName);
		//	Arguments.OnClicked_Lambda([ClickFunc]() { ClickFunc(); return FReply::Handled(); });
		//};

		//WidgetArgument::Set_Text<STextBlock::FArguments>(Arguments, JsObject, "Text");
		//SET_WIDGET_ARGUMENT_VARIABLE(ColorAndOpacity);

		//const char* Arg_Name_Text = "Text";
		//if (JsObject.Has(Arg_Name_Text))
		//{
		//	FString TextString = FString(JsObject.Get<std::string>(Arg_Name_Text).c_str());
		//	Arguments.Text(FText::FromString(TextString));
		//}

		//const char* Arg_Name_ColorAndOpacity = "ColorAndOpacity";
		//if (JsObject.Has(Arg_Name_ColorAndOpacity))
		//{
		//	FSlateColor ColorAndOpacity = JsObject.Get<FSlateColor>(Arg_Name_ColorAndOpacity);
		//	Arguments.ColorAndOpacity(ColorAndOpacity);
		//}

		return MakeTDecl<SButton>("SButton", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;


		//auto ClickFunc = JsObject.Get< std::function<void()>>("OnClicked");
		//FString  Text = FString(JsObject.Get<std::string>("Text").c_str());

		//return MakeTDecl<SButton>("SButton", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs())
		//	<<= SButton::FArguments()
		//	.Text(FText::FromString(Text))
		//	.OnClicked_Lambda([ClickFunc]() {ClickFunc(); return FReply::Handled(); })
		//	;
	}
	static void CallFunction_Attribute(const TSharedPtr<SButton> Widget, FJsObject JsObject, const FString& FunctionName)
	{
		if (!Widget.IsValid()) return;

		CALL_FUNCTION_SET__Attribute(FMargin, SetContentPadding);
		CALL_FUNCTION_SET__Optional(FSlateSound, SetHoveredSound);
		CALL_FUNCTION_SET__Optional(FSlateSound, SetPressedSound);
		CALL_FUNCTION_SET__OnClicked(FOnClicked, SetOnClicked);
		CALL_FUNCTION_SET__SimpleDelegate(FSimpleDelegate, SetOnHovered);
		CALL_FUNCTION_SET__SimpleDelegate(FSimpleDelegate, SetOnUnhovered);
		//else CALL_FUNCTION_SET_Attribute(const FButtonStyle*, SetButtonStyle)
	}
};

struct AutoRegisterWidget_SButton
{
	void RegisterArguments()
	{
		FWidgetArguments Arguments;
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

	AutoRegisterWidget_SButton()
	{
		RegisterArguments();

		puerts::DefineClass<SButton>()
			.Extends<SBorder>()
			.Function("SNew", MakeFunction(&SButton_Extension::$SNew))
			.Function("SAssignNew", MakeFunction(&SButton_Extension::$SAssignNew))
			.Function("MakeShared", MakeFunction(&SButton_Extension::$MakeShared))

			//.Method("GetForegroundColor", MakeFunction(&SButton::GetForegroundColor))
			//.Method("GetDisabledForegroundColor", MakeFunction(&SButton::GetDisabledForegroundColor))
			.Method("IsPressed", MakeFunction(&SButton::IsPressed))

			.Method("SetContentPadding", MakeExtension(&SButton_Extension::CallFunction_Attribute, FJsObject(), "SetContentPadding"))
			.Method("SetHoveredSound", MakeExtension(&SButton_Extension::CallFunction_Attribute, FJsObject(), "SetHoveredSound"))
			.Method("SetPressedSound", MakeExtension(&SButton_Extension::CallFunction_Attribute, FJsObject(), "SetPressedSound"))
			.Method("SetOnClicked", MakeExtension(&SButton_Extension::CallFunction_Attribute, FJsObject(), "SetOnClicked"))
			.Method("SetOnHovered", MakeExtension(&SButton_Extension::CallFunction_Attribute, FJsObject(), "SetOnHovered"))
			.Method("SetOnUnhovered", MakeExtension(&SButton_Extension::CallFunction_Attribute, FJsObject(), "SetOnUnhovered"))
			.Method("SetButtonStyle", MakeExtension(&SButton_Extension::CallFunction_Attribute, FJsObject(), "SetButtonStyle"))
			.Method("SetClickMethod", MakeFunction(&SButton::SetClickMethod))
			.Method("SetTouchMethod", MakeFunction(&SButton::SetTouchMethod))
			.Method("SetPressMethod", MakeFunction(&SButton::SetPressMethod))

			.Register();

		RegisterTSharedPtr(SButton);
	}
};

AutoRegisterWidget_SButton _AutoRegisterWidget_SButton;

