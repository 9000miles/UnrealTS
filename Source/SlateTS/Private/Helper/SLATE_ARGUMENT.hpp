#pragma once
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"

#define SET_VARIABLE__SLATE_ARGUMENT(Name)\
$Arguments__SLATE_ARGUMENT::Set_##Name(Arguments, Isolate, JsObject, #Name, "")

/** ======================= SLATE_ARGUMENT ======================= **/
namespace $Arguments__SLATE_ARGUMENT
{
#define SET_SLATE_ARUMENT(Name, Type)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
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

	SET_SLATE_ARUMENT(Type, ESlateCheckBoxType::Type);//支持TOptional<ESlateCheckBoxType::Type>
	SET_SLATE_ARUMENT(TextShapingMethod, ETextShapingMethod);
	SET_SLATE_ARUMENT(TextFlowDirection, ETextFlowDirection);
	//SET_SLATE_ARUMENT(LineBreakPolicy, TSharedPtr<IBreakIterator>);
	SET_SLATE_ARUMENT(OverflowPolicy, ETextOverflowPolicy);
	SET_SLATE_ARUMENT(SimpleTextMode, bool);
	//SET_SLATE_ARUMENT(ButtonStyle, FButtonStyle*);
	SET_SLATE_ARUMENT(HAlign, EHorizontalAlignment);
	SET_SLATE_ARUMENT(VAlign, EVerticalAlignment);
	SET_SLATE_ARUMENT(ContentPadding, FMargin);
	SET_SLATE_ARUMENT(Padding, FMargin);
	SET_SLATE_ARUMENT(ClickMethod, EButtonClickMethod::Type);
	SET_SLATE_ARUMENT(TouchMethod, EButtonTouchMethod::Type);
	SET_SLATE_ARUMENT(PressMethod, EButtonPressMethod::Type);
	SET_SLATE_ARUMENT(IsFocusable, bool);
	SET_SLATE_ARUMENT(PressedSoundOverride, FSlateSound);
	SET_SLATE_ARUMENT(HoveredSoundOverride, FSlateSound);
	SET_SLATE_ARUMENT(UncheckedSoundOverride, FSlateSound);
	SET_SLATE_ARUMENT(CheckedSoundOverride, FSlateSound);
	SET_SLATE_ARUMENT(CheckBoxContentUsesAutoWidth, bool);
	SET_SLATE_ARUMENT(UncheckedImage, const FSlateBrush*);
	SET_SLATE_ARUMENT(UncheckedHoveredImage, const FSlateBrush*);
	SET_SLATE_ARUMENT(UncheckedPressedImage, const FSlateBrush*);
	SET_SLATE_ARUMENT(CheckedImage, const FSlateBrush*);
	SET_SLATE_ARUMENT(CheckedHoveredImage, const FSlateBrush*);
	SET_SLATE_ARUMENT(CheckedPressedImage, const FSlateBrush*);
	SET_SLATE_ARUMENT(UndeterminedImage, const FSlateBrush*);
	SET_SLATE_ARUMENT(UndeterminedHoveredImage, const FSlateBrush*);
	SET_SLATE_ARUMENT(UndeterminedPressedImage, const FSlateBrush*);
	SET_SLATE_ARUMENT(BackgroundImage, const FSlateBrush*);
	SET_SLATE_ARUMENT(BackgroundHoveredImage, const FSlateBrush*);
	SET_SLATE_ARUMENT(BackgroundPressedImage, const FSlateBrush*);
	SET_SLATE_ARUMENT(FlipForRightToLeftFlowDirection, bool);
	SET_SLATE_ARUMENT(HasDownArrow, bool);
	SET_SLATE_ARUMENT(Method, EPopupMethod);
	SET_SLATE_ARUMENT(CollapseMenuOnParentFocus, bool);
	SET_SLATE_ARUMENT(Placement, EMenuPlacement);
	SET_SLATE_ARUMENT(FitInWindow, bool);
	SET_SLATE_ARUMENT(ShouldDeferPaintingAfterWindowContent, bool);
	SET_SLATE_ARUMENT(UseApplicationMenuStack, bool);
	SET_SLATE_ARUMENT(IsCollapsedByParent, bool);
	SET_SLATE_ARUMENT(ApplyWidgetStyleToMenu, bool);
	SET_SLATE_ARUMENT(MenuContent, TSharedPtr<SWidget>);
}