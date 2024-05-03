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
};

struct AutoRegisterWidget_SButton
{
	void DefineArguments()
	{
		FWidgetArguments Arguments;
		Arguments.Add("Text", "string");
		Arguments.Add("IsFocusable", "boolean");
		Arguments.Add("HAlign", _EHorizontalAlignment_);
		Arguments.Add("VAlign", _EVerticalAlignment_);
		Arguments.Add("OnClicked", "() => void");

		UTemplateBindingGenerator::RegisterWidgetArgumentType("SButton", Arguments);
	}

	AutoRegisterWidget_SButton()
	{
		DefineArguments();

		puerts::DefineClass<SButton>()
			.Extends<SBorder>()
			.Function("SNew", MakeFunction(&SButton_Extension::$SNew))
			.Function("SAssignNew", MakeFunction(&SButton_Extension::$SAssignNew))
			.Function("MakeShared", MakeFunction(&SButton_Extension::$MakeShared))
			.Register();

		RegisterTSharedPtr(SButton);
	}
};

AutoRegisterWidget_SButton _AutoRegisterWidget_SButton;

