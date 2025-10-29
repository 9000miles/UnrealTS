#pragma once

#include "CoreMinimal.h"
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
#include "Textures/SlateIcon.h"
#include "Rendering/RenderingCommon.h"
#include "Widgets/SWindow.h"

struct AutoRegister_Struct;
struct AutoRegister_Class;
struct AutoRegister_TArray;
struct AutoRegisterSlateCoreGlue;

UsingUStruct(FEditableTextBoxStyle);
UsingUStruct(FEditableTextStyle);
UsingUStruct(FFrameRate);
UsingUStruct(FGameMenuStyle);
UsingUStruct(FHyperlinkStyle);
UsingUStruct(FInputChord);
UsingUStruct(FProgressBarStyle);
UsingUStruct(FRuntimeFloatCurve);
UsingUStruct(FScrollBarStyle);
UsingUStruct(FScrollBorderStyle);
UsingUStruct(FScrollBoxStyle);
UsingUStruct(FSearchBoxStyle);
UsingUStruct(FSlateSound);
UsingUStruct(FSliderStyle);
UsingUStruct(FSplitterStyle);
UsingUStruct(FTextBlockStyle);
UsingUStruct(FVirtualKeyboardOptions);
UsingUStruct(FInlineEditableTextBlockStyle);
UsingUStruct(FComboBoxStyle);
UsingUStruct(FTimecode);
UsingUStruct(FVolumeControlStyle);
UsingUStruct(FWindowStyle);


UsingCppType(ISlateStyle);
UsingCppType(IErrorReportingWidget);
UsingCppType(ITextLayoutMarshaller);
UsingCppType(IRichTextMarkupParser);
UsingCppType(ITextDecorator);
UsingCppType(FRichTextLayoutMarshaller);
UsingCppType(USlateVectorArtData);
UsingCppType(EVisibility);
UsingCppType(FSlateIcon);
UsingCppType(ISlateViewport);
UsingCppType(FWindowTransparency);

UsingTSharedPtr(IErrorReportingWidget);
UsingTSharedPtr(FRichTextLayoutMarshaller);
UsingTSharedPtr(ITextLayoutMarshaller);
UsingTSharedPtr(FString);
UsingTSharedPtr(ISlateViewport);


UsingTArrayWithName(FCommonFrameRateInfo, "FCommonFrameRateInfo[]");
UsingTArrayWithName(FString, "FString[]");
