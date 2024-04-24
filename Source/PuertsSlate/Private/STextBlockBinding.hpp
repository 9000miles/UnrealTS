#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "PuertsSlateDefines.h"
#include "TemplateBindingGenerator.h"
#include "Widgets/Text/STextBlock.h"

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

		if (Arguments.Has("Text"))
		{
			FString Text = FString(Arguments.Get<std::string>("Text").c_str());
			_Arguments.Text(FText::FromString(Text));
		}

		if (Arguments.Has("ColorAndOpacity"))
		{
			FSlateColor ColorAndOpacity = Arguments.Get<FSlateColor>("ColorAndOpacity");
			_Arguments.ColorAndOpacity(ColorAndOpacity);
		}

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
		Arg.Add("Text", "string");
		Arg.Add("ColorAndOpacity", "cpp.SlateColor");
		Arg.Add("Margin", "UE.Margin");
		Arg.Add("WrapTextAt", "number");
		Arg.Add("AutoWrapText", "boolean");
		Arg.Add("MinDesiredWidth", "number");

		UTemplateBindingGenerator::AllWidget().Add("STextBlock", Arg);
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