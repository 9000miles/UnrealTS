#pragma once
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"

#define $SLATE_ARGUMENT(Type, Name, Tag)\
$SLATE_ARGUMENT$::Set_##Name##_##Tag(Arguments, Isolate, JsObject, #Name)

/** ======================= SLATE_ARGUMENT ======================= **/
namespace $SLATE_ARGUMENT$
{
#define DEFINE_FUNCTION_SLATE_ARUMENT(Type, Name, Tag)\
	template<typename TArgumentType>\
	void Set_##Name##_##Tag(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		if (puerts::converter::Converter<Type>::accept(Context, JsValue))\
		{\
			Type Ret = puerts::converter::Converter<Type>::toCpp(Context, JsValue);\
			Arguments._##Name = Ret;\
		}\
	}

	//支持TOptional<ESlateCheckBoxType::, Type>
	DEFINE_FUNCTION_SLATE_ARUMENT(ESlateCheckBoxType::Type, Type, );
	DEFINE_FUNCTION_SLATE_ARUMENT(ETextShapingMethod, TextShapingMethod, );
	DEFINE_FUNCTION_SLATE_ARUMENT(ETextFlowDirection, TextFlowDirection, );
	//SET_SLATE_ARUMENTineBreakPolicy, TSharedPtr<,(, IBreakIterator>);
	DEFINE_FUNCTION_SLATE_ARUMENT(ETextOverflowPolicy, OverflowPolicy, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, SimpleTextMode, );
	//SET_SLATE_ARUMENTuttonStyle, ,(, FButtonStyle*);
	DEFINE_FUNCTION_SLATE_ARUMENT(EHorizontalAlignment, HAlign, );
	DEFINE_FUNCTION_SLATE_ARUMENT(EVerticalAlignment, VAlign, );
	DEFINE_FUNCTION_SLATE_ARUMENT(FMargin, ContentPadding, );
	DEFINE_FUNCTION_SLATE_ARUMENT(FMargin, Padding, );
	DEFINE_FUNCTION_SLATE_ARUMENT(EButtonClickMethod::Type, ClickMethod, );
	DEFINE_FUNCTION_SLATE_ARUMENT(EButtonTouchMethod::Type, TouchMethod, );
	DEFINE_FUNCTION_SLATE_ARUMENT(EButtonPressMethod::Type, PressMethod, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, IsFocusable, );
	DEFINE_FUNCTION_SLATE_ARUMENT(FSlateSound, PressedSoundOverride, );
	DEFINE_FUNCTION_SLATE_ARUMENT(FSlateSound, HoveredSoundOverride, );
	DEFINE_FUNCTION_SLATE_ARUMENT(FSlateSound, UncheckedSoundOverride, );
	DEFINE_FUNCTION_SLATE_ARUMENT(FSlateSound, CheckedSoundOverride, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, CheckBoxContentUsesAutoWidth, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, UncheckedImage, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, UncheckedHoveredImage, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, UncheckedPressedImage, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, CheckedImage, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, CheckedHoveredImage, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, CheckedPressedImage, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, UndeterminedImage, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, UndeterminedHoveredImage, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, UndeterminedPressedImage, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, BackgroundImage, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, BackgroundHoveredImage, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, BackgroundPressedImage, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, FlipForRightToLeftFlowDirection, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, HasDownArrow, );
	DEFINE_FUNCTION_SLATE_ARUMENT(EPopupMethod, Method, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, CollapseMenuOnParentFocus, );
	DEFINE_FUNCTION_SLATE_ARUMENT(EMenuPlacement, Placement, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, FitInWindow, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, ShouldDeferPaintingAfterWindowContent, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, UseApplicationMenuStack, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, IsCollapsedByParent, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, ApplyWidgetStyleToMenu, );
	DEFINE_FUNCTION_SLATE_ARUMENT(TSharedPtr<SWidget>, MenuContent, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, InitiallyCollapsed, );
	DEFINE_FUNCTION_SLATE_ARUMENT(float, MinWidth, );
	DEFINE_FUNCTION_SLATE_ARUMENT(float, MaxHeight, );
	DEFINE_FUNCTION_SLATE_ARUMENT(bool, AllowAnimatedTransition, );
	DEFINE_FUNCTION_SLATE_ARUMENT(const FSlateBrush*, BodyBorderImage, );
}