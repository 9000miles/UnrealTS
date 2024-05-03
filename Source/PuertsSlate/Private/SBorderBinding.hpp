#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "PuertsSlateDefines.h"
#include "TemplateBindingGenerator.h"
#include "Widgets/Layout/SBorder.h"

UsingCppType(SBorder);
UsingTSharedPtr(SBorder);

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
};

struct AutoRegisterWidget_SBorder
{
	void DefineArguments()
	{
		FWidgetArguments Arguments;
		Arguments.Add("HAlign", _EHorizontalAlignment_);
		Arguments.Add("VAlign", _EVerticalAlignment_);
		Arguments.Add("Padding", "UE.Margin");
		Arguments.Add("OnMouseButtonDown", "(Geometry: cpp.Geometry, MouseEvent: cpp.PointerEvent, InAssociation: cpp.MaterialParameterAssociation, InIndex: number) => void");

		UTemplateBindingGenerator::RegisterWidgetArgumentType("SBorder", Arguments);
	}

	AutoRegisterWidget_SBorder()
	{
		DefineArguments();

		puerts::DefineClass<SBorder>()
			.Extends<SCompoundWidget>()
			.Function("SNew", MakeFunction(&SBorder_Extension::$SNew))
			.Function("SAssignNew", MakeFunction(&SBorder_Extension::$SAssignNew))
			.Function("MakeShared", MakeFunction(&SBorder_Extension::$MakeShared))
			.Register();

		RegisterTSharedPtr(SBorder);
	}
};

AutoRegisterWidget_SBorder _AutoRegisterWidget_SBorder;

