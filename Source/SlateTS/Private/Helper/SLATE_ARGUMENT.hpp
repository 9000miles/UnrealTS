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
#define SET_SLATE_ARUMENT(Type, Name, Tag)\
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
	SET_SLATE_ARUMENT(ESlateCheckBoxType::Type, Type, );
	SET_SLATE_ARUMENT(ETextShapingMethod, TextShapingMethod, );
	SET_SLATE_ARUMENT(ETextFlowDirection, TextFlowDirection, );
	//SET_SLATE_ARUMENTineBreakPolicy, TSharedPtr<,(, IBreakIterator>);
	SET_SLATE_ARUMENT(ETextOverflowPolicy, OverflowPolicy, );
	SET_SLATE_ARUMENT(bool, SimpleTextMode, );
	//SET_SLATE_ARUMENTuttonStyle, ,(, FButtonStyle*);
	SET_SLATE_ARUMENT(EHorizontalAlignment, HAlign, );
	SET_SLATE_ARUMENT(EVerticalAlignment, VAlign, );
	SET_SLATE_ARUMENT(FMargin, ContentPadding, );
	SET_SLATE_ARUMENT(FMargin, Padding, );
	SET_SLATE_ARUMENT(EButtonClickMethod::Type, ClickMethod, );
	SET_SLATE_ARUMENT(EButtonTouchMethod::Type, TouchMethod, );
	SET_SLATE_ARUMENT(EButtonPressMethod::Type, PressMethod, );
	SET_SLATE_ARUMENT(bool, IsFocusable, );
	SET_SLATE_ARUMENT(FSlateSound, PressedSoundOverride, );
	SET_SLATE_ARUMENT(FSlateSound, HoveredSoundOverride, );
	SET_SLATE_ARUMENT(FSlateSound, UncheckedSoundOverride, );
	SET_SLATE_ARUMENT(FSlateSound, CheckedSoundOverride, );
	SET_SLATE_ARUMENT(bool, CheckBoxContentUsesAutoWidth, );
	SET_SLATE_ARUMENT(const FSlateBrush*, UncheckedImage, );
	SET_SLATE_ARUMENT(const FSlateBrush*, UncheckedHoveredImage, );
	SET_SLATE_ARUMENT(const FSlateBrush*, UncheckedPressedImage, );
	SET_SLATE_ARUMENT(const FSlateBrush*, CheckedImage, );
	SET_SLATE_ARUMENT(const FSlateBrush*, CheckedHoveredImage, );
	SET_SLATE_ARUMENT(const FSlateBrush*, CheckedPressedImage, );
	SET_SLATE_ARUMENT(const FSlateBrush*, UndeterminedImage, );
	SET_SLATE_ARUMENT(const FSlateBrush*, UndeterminedHoveredImage, );
	SET_SLATE_ARUMENT(const FSlateBrush*, UndeterminedPressedImage, );
	SET_SLATE_ARUMENT(const FSlateBrush*, BackgroundImage, );
	SET_SLATE_ARUMENT(const FSlateBrush*, BackgroundHoveredImage, );
	SET_SLATE_ARUMENT(const FSlateBrush*, BackgroundPressedImage, );
	SET_SLATE_ARUMENT(bool, FlipForRightToLeftFlowDirection, );
	SET_SLATE_ARUMENT(bool, HasDownArrow, );
	SET_SLATE_ARUMENT(EPopupMethod, Method, );
	SET_SLATE_ARUMENT(bool, CollapseMenuOnParentFocus, );
	SET_SLATE_ARUMENT(EMenuPlacement, Placement, );
	SET_SLATE_ARUMENT(bool, FitInWindow, );
	SET_SLATE_ARUMENT(bool, ShouldDeferPaintingAfterWindowContent, );
	SET_SLATE_ARUMENT(bool, UseApplicationMenuStack, );
	SET_SLATE_ARUMENT(bool, IsCollapsedByParent, );
	SET_SLATE_ARUMENT(bool, ApplyWidgetStyleToMenu, );
	SET_SLATE_ARUMENT(TSharedPtr<SWidget>, MenuContent, );
	SET_SLATE_ARUMENT(bool, InitiallyCollapsed, );
	SET_SLATE_ARUMENT(float, MinWidth, );
	SET_SLATE_ARUMENT(float, MaxHeight, );
	SET_SLATE_ARUMENT(bool, AllowAnimatedTransition, );
	SET_SLATE_ARUMENT(const FSlateBrush*, BodyBorderImage, );
}