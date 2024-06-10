#pragma once
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"
#include "GameMenuWidgetStyle.h"
#include "Styling/SegmentedControlStyle.h"
#include "WidgetCarousel/Public/WidgetCarouselStyle.h"
#include "Styling/SlateTypes.h"

#define $SLATE_STYLE_ARGUMENT(Type, Name, Tag)\
$SLATE_STYLE_ARGUMENT$::Set_##Name##_##Tag(Arguments, Isolate, JsObject, #Name)

/** ======================= SLATE_STYLE_ARGUMENT ======================= **/
namespace $SLATE_STYLE_ARGUMENT$
{
#define DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(Type, Name, Tag)\
	template<typename TType = Type, typename TArgumentType>\
	void Set_##Name##_##Tag(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		if (puerts::converter::Converter<Type>::accept(Context, JsObject))\
		{\
			Type* Ret = puerts::converter::Converter<Type*>::toCpp(Context, JsObject);\
			Arguments._##Name = Ret;\
		}\
	}

	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FButtonStyle, ButtonStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FButtonStyle, UnderlineStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FCheckBoxStyle, Style, FCheckBoxStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FComboBoxStyle, ComboBoxStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FComboButtonStyle, ComboButtonStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FEditableTextBoxStyle, EditableTextBoxStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FEditableTextBoxStyle, Style, FEditableTextBoxStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FEditableTextBoxStyle, TextStyle, FEditableTextBoxStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FEditableTextStyle, Style, FEditableTextStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FExpandableAreaStyle, Style, FExpandableAreaStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FGameMenuStyle, MenuStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FHyperlinkStyle, Style, FHyperlinkStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FInlineEditableTextBlockStyle, Style, FInlineEditableTextBlockStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FProgressBarStyle, Style, FProgressBarStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FScrollBarStyle, ScrollBarStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FScrollBarStyle, Style, FScrollBarStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FScrollBorderStyle, Style, FScrollBorderStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FScrollBoxStyle, Style, FScrollBoxStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FSearchBoxStyle, Style, FSearchBoxStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FSegmentedControlStyle, Style, FSegmentedControlStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FSliderStyle, Style, FSliderStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FSpinBoxStyle, SpinBoxStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FSpinBoxStyle, Style, FSpinBoxStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FSplitterStyle, Style, FSplitterStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FTableRowStyle, Style, FTableRowStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FTableViewStyle, ListViewStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FTableViewStyle, TreeViewStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FTextBlockStyle, SuggestionTextStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FTextBlockStyle, TextStyle, FTextBlockStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FVolumeControlStyle, Style, FVolumeControlStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FWidgetCarouselNavigationBarStyle, NavigationBarStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FWidgetCarouselNavigationBarStyle, Style, FWidgetCarouselNavigationBarStyle);
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FWidgetCarouselNavigationButtonStyle, NavigationButtonStyle, );
	DEFINE_FUNCTION_SLATE_STYLE_ARGUMENT(FWindowStyle, Style, FWindowStyle)

}