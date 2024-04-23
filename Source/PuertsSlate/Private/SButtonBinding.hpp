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
	static void $SAssignNew(TSharedPtr<SButton>& ExposeAs, FJsObject Arguments, FString Filename = "")
	{
		ExposeAs = $SNew(Arguments, Filename);
	}
	static TSharedPtr<SButton> $SNew(FJsObject Arguments, FString Filename = "")
	{
		auto ClickFunc = Arguments.Get< std::function<void()>>("OnClicked");
		FString  Text = FString(Arguments.Get<std::string>("Text").c_str());

		return MakeTDecl<SButton>("SButton", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs())
			<<= SButton::FArguments()
			.Text(FText::FromString(Text))
			.OnClicked_Lambda([ClickFunc]() {ClickFunc(); return FReply::Handled(); })
			;
	}
};

struct AutoRegisterWidget_SButton
{
	void DefineArguments()
	{
		FWidgetArguments Arg;
		Arg.Add("Text", "string");
		Arg.Add("IsFocusable", "boolean");
		Arg.Add("HAlign", _EHorizontalAlignment_);
		Arg.Add("VAlign", _EVerticalAlignment_);
		Arg.Add("OnClicked", "() => void");

		UTemplateBindingGenerator::AllWidget().Add("SButton", Arg);
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

