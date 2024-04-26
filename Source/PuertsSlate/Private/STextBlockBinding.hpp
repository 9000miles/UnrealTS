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
	static void $SAssignNew(TSharedPtr<STextBlock>& ExposeAs, FJsObject Arguments, FString Filename = "")
	{
		ExposeAs = $SNew(Arguments, Filename);
	}
	static TSharedPtr<STextBlock> $SNew(FJsObject Arguments, FString Filename = "")
	{
		STextBlock::FArguments _Arguments;

		SET_WIDGET_ARGUMENT_VARIABLE(Text);
		SET_WIDGET_ARGUMENT_VARIABLE(ColorAndOpacity);

		//const char* Arg_Name_Text = "Text";
		//if (Arguments.Has(Arg_Name_Text))
		//{
		//	FString TextString = FString(Arguments.Get<std::string>(Arg_Name_Text).c_str());
		//	_Arguments.Text(FText::FromString(TextString));
		//}

		//const char* Arg_Name_ColorAndOpacity = "ColorAndOpacity";
		//if (Arguments.Has(Arg_Name_ColorAndOpacity))
		//{
		//	FSlateColor ColorAndOpacity = Arguments.Get<FSlateColor>(Arg_Name_ColorAndOpacity);
		//	_Arguments.ColorAndOpacity(ColorAndOpacity);
		//}

		return MakeTDecl<STextBlock>("STextBlock", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= _Arguments;
	}
	static void SetText(const TSharedPtr<STextBlock> TextBlock, const FText Text)
	{
		if (!TextBlock.IsValid()) return;
		TextBlock->SetText(Text);
	}
};

struct AutoRegisterWidget_STextBlock
{
	void DefineArguments()
	{
		FWidgetArguments Arg;
		REGISTER_WIDGET_ARGUMENT_TYPE__Text();
		//Arg.Add("Text", "string | () => string");
		Arg.Add("ColorAndOpacity", "cpp.SlateColor");
		REGISTER_WIDGET_ARGUMENT_TYPE__Margin();
		//Arg.Add("Margin", "UE.Margin");
		Arg.Add("WrapTextAt", "number");
		Arg.Add("AutoWrapText", "boolean");
		Arg.Add("MinDesiredWidth", "number");

		UTemplateBindingGenerator::RegisterWidgetArgumentType("STextBlock", Arg);
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
			.Method("SetText", MakeExtension(&STextBlock_Extension::SetText))
			.Register();

		RegisterTSharedPtr(STextBlock);
	}
};

AutoRegisterWidget_STextBlock _AutoRegisterWidget_STextBlock;