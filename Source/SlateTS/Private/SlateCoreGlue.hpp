#pragma once

#include "CoreMinimal.h"
#include "GlueCode/SlateCoreGlue.h"
#include "Framework/Text/ITextLayoutMarshaller.h"
#include "Styling/SlateTypes.h"
#include "Styling/ISlateStyle.h"
#include "UEDataBinding.hpp"
#include "Binding.hpp"
#include "Widgets/Notifications/SErrorText.h"
#include "TimeManagement/Public/CommonFrameRates.h"
#include "GameMenuBuilder/Public/GameMenuWidgetStyle.h"
#include "Widgets/Input/IVirtualKeyboardEntry.h"
#include "Layout/Visibility.h"
#include "Sound/SlateSound.h"
#include "Framework/Text/IRichTextMarkupParser.h"
#include "Framework/Text/ITextDecorator.h"
#include "Framework/Text/RichTextLayoutMarshaller.h"
#include "Curves/CurveFloat.h"
#include "Slate/SlateVectorArtData.h"
#include "Framework/Commands/InputChord.h"

UsingUStruct(FHyperlinkStyle);
UsingUStruct(FGameMenuStyle);
UsingUStruct(FFrameRate);
UsingUStruct(FEditableTextBoxStyle);
UsingUStruct(FVirtualKeyboardOptions);
UsingUStruct(FEditableTextStyle);
UsingUStruct(EVisibility);
UsingUStruct(FSlateSound);
UsingUStruct(FProgressBarStyle);
UsingUStruct(FScrollBoxStyle);
UsingUStruct(FScrollBorderStyle);
UsingUStruct(FScrollBarStyle);
UsingUStruct(FRuntimeFloatCurve);
UsingUStruct(FSliderStyle);
UsingUStruct(FInputChord);
UsingUStruct(FSplitterStyle);
UsingUStruct(FSearchBoxStyle);
struct AutoRegister_Struct
{
	AutoRegister_Struct()
	{
		//puerts::DefineClass<FHyperlinkStyle>()
		//	.Register();
		//puerts::DefineClass<FGameMenuStyle>()
		//	.Register();

	}
}__AutoRegister_Struct;

UsingCppType(ISlateStyle);
UsingCppType(IErrorReportingWidget);
UsingCppType(ITextLayoutMarshaller);
UsingCppType(IRichTextMarkupParser);
UsingCppType(ITextDecorator);
UsingCppType(FRichTextLayoutMarshaller);
UsingCppType(USlateVectorArtData);

UsingTSharedPtr(IErrorReportingWidget);
UsingTSharedPtr(FRichTextLayoutMarshaller);
struct AutoRegister_Class
{
	AutoRegister_Class()
	{
		puerts::DefineClass<ISlateStyle>()
			.Register();
		//puerts::DefineClass<IErrorReportingWidget>()
		//	.Register();

		puerts::DefineClass<ITextLayoutMarshaller>()
			.Register();
	}
}__AutoRegister_Class;

UsingTArrayWithName(FCommonFrameRateInfo, "FCommonFrameRateInfo");
struct AutoRegister_TArray
{
	AutoRegister_TArray()
	{
		//RegisterTArray(FCommonFrameRateInfo);

	}
}__AutoRegister_TArray;

struct AutoRegisterSlateCoreGlue
{
	AutoRegisterSlateCoreGlue()
	{
		//RegisterTOptional(ETextShapingMethod);


		//RegisterTSharedPtr(ITextLayoutMarshaller);

		puerts::DefineClass<FReply>()
			//.Function("Handled", MakeFunction(&FReply::Handled))
			//.Function("Unhandled", MakeFunction(&FReply::Unhandled))
			.Register();

		puerts::DefineClass<FSlateWidgetClassData>()
			.Method("GetWidgetType", MakeFunction(&FSlateWidgetClassData::GetWidgetType))
			.Register();

		puerts::DefineClass<FSlateControlledConstruction>()
			//.Function("StaticWidgetClass", MakeFunction(&FSlateControlledConstruction::StaticWidgetClass))
			//.Method("GetWidgetClass", MakeFunction(&FSlateControlledConstruction::GetWidgetClass))
			.Register();

		puerts::DefineClass<SWidget>()
			.Extends<FSlateControlledConstruction>()
			//.Function("StaticWidgetClass", MakeFunction(&SWidget::StaticWidgetClass))
			//.Method("GetWidgetClass", MakeFunction(&SWidget::GetWidgetClass))
			.Register();
		RegisterTSharedPtr(SWidget);
		RegisterTSharedRef(SWidget);

		puerts::DefineClass<SCompoundWidget>()
			.Extends<SWidget>()
			.Register();
		RegisterTSharedPtr(SCompoundWidget);
		RegisterTSharedRef(SCompoundWidget);

		puerts::DefineClass<SLeafWidget>()
			.Extends<SWidget>()
			.Register();
		RegisterTSharedPtr(SLeafWidget);
		RegisterTSharedRef(SLeafWidget);
	}
};

AutoRegisterSlateCoreGlue __AutoRegisterSlateCoreGlue__;
