#pragma once


#include "CoreMinimal.h"
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"
#include "Styling/SlateTypes.h"
//#include "SlateBinding.hpp"

#define SET_WIDGET_ARGUMENT_VARIABLE(Name);\
WidgetArgument3::Set_##Name(Arguments, JsObject, #Name)


#define SET_WIDGET_ARGUMENT_VARIABLE_A(Name);\
WidgetArgument4::Set_##Name(Arguments, Isolate, JsObject, #Name, "")

#define SET_WIDGET_ARGUMENT_VARIABLE_A_Type(Name, Type);\
WidgetArgument4::Set_##Name<Type>(Arguments, Info,JsObject, #Type)


namespace WidgetArgument4
{
	/**
	 * WidgetClass 用于判断同名属性，但是不同类型的处理，比如：Style
	 */
#define SET_SLATE_ATTRIBUTE(Name, Type)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		Arguments._##Name = WidgetAttribute4::MakeAttribute<Type>(Context, JsValue, WidgetClass);\
	}
	
	SET_SLATE_ATTRIBUTE(Text, FText);
	SET_SLATE_ATTRIBUTE(Font, FSlateFontInfo);
	SET_SLATE_ATTRIBUTE(StrikeBrush, const FSlateBrush*);
	SET_SLATE_ATTRIBUTE(ColorAndOpacity, FSlateColor);
	SET_SLATE_ATTRIBUTE(ShadowOffset, FVector2D);
	SET_SLATE_ATTRIBUTE(ShadowColorAndOpacity, FLinearColor);
	SET_SLATE_ATTRIBUTE(HighlightColor, FLinearColor);
	SET_SLATE_ATTRIBUTE(HighlightShape, const FSlateBrush*);
	SET_SLATE_ATTRIBUTE(HighlightText, FText);
	SET_SLATE_ATTRIBUTE(WrapTextAt, float);
	SET_SLATE_ATTRIBUTE(AutoWrapText, bool);
	SET_SLATE_ATTRIBUTE(WrappingPolicy, ETextWrappingPolicy);
	SET_SLATE_ATTRIBUTE(TransformPolicy, ETextTransformPolicy);
	SET_SLATE_ATTRIBUTE(Margin, FMargin);
	SET_SLATE_ATTRIBUTE(Padding, FMargin);
	SET_SLATE_ATTRIBUTE(LineHeightPercentage, float);
	SET_SLATE_ATTRIBUTE(Justification, ETextJustify::Type);
	SET_SLATE_ATTRIBUTE(MinDesiredWidth, float);
	SET_SLATE_ATTRIBUTE(DesiredSizeScale, FVector2D);
	SET_SLATE_ATTRIBUTE(ContentScale, FVector2D);
	SET_SLATE_ATTRIBUTE(ButtonColorAndOpacity, FSlateColor);
	SET_SLATE_ATTRIBUTE(ForegroundColor, FSlateColor);
	SET_SLATE_ATTRIBUTE(BorderBackgroundColor, FSlateColor);
	SET_SLATE_ATTRIBUTE(IsChecked, ECheckBoxState);

	/** ======================= SLATE_STYLE_ARGUMENT ======================= **/
#define SET_SLATE_STYLE_ARGUMENT(Name, Type)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
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
	SET_SLATE_STYLE_ARGUMENT(TextStyle, FTextBlockStyle);
	SET_SLATE_STYLE_ARGUMENT(Style, FCheckBoxStyle);


	/** ======================= SLATE_ARGUMENT ======================= **/
#define SET_SLATE_ARUMENT(Name, Type)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		if (puerts::converter::Converter<Type>::accept(Context, JsObject))\
		{\
			Type Ret = puerts::converter::Converter<Type>::toCpp(Context, JsObject);\
			Arguments._##Name = Ret;\
		}\
	}
	SET_SLATE_ARUMENT(Type, TOptional<ESlateCheckBoxType::Type>);
	SET_SLATE_ARUMENT(TextShapingMethod, ETextShapingMethod);
	SET_SLATE_ARUMENT(TextFlowDirection, ETextFlowDirection);
	//SET_SLATE_ARUMENT(LineBreakPolicy, TSharedPtr<IBreakIterator>);
	SET_SLATE_ARUMENT(OverflowPolicy, ETextOverflowPolicy);
	SET_SLATE_ARUMENT(SimpleTextMode, bool);
	SET_SLATE_ARUMENT(ButtonStyle, FButtonStyle*);
	SET_SLATE_ARUMENT(HAlign, EHorizontalAlignment);
	SET_SLATE_ARUMENT(VAlign, EVerticalAlignment);
	SET_SLATE_ARUMENT(ContentPadding, FMargin);
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

	/** ======================= SLATE_SIMPLE_DELEGATE_EVENT ======================= **/
#define SET_SLATE_EVENT_SIMPLE_DELEGATE(Name,Type)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		if (Value->IsFunction())\
		{\
			v8::Local<v8::Function> Function = Value.As<v8::Function>();\
			FJsObject JsObject = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsObject]() { return JsObject.Action(nullptr); });\
		}\
	}

	SET_SLATE_EVENT_SIMPLE_DELEGATE(OnPressed, void);
	SET_SLATE_EVENT_SIMPLE_DELEGATE(OnReleased, void);
	SET_SLATE_EVENT_SIMPLE_DELEGATE(OnHovered, void);
	SET_SLATE_EVENT_SIMPLE_DELEGATE(OnUnhovered, void);

	template<typename TArgumentType>
	void Set_OnDoubleClicked(TArgumentType& Arguments, const v8::FunctionCallbackInfo<v8::Value>& Info, const char* VariableName, const char* WidgetClass = "")
	{
	}
	template<typename TArgumentType>
	void Set_OnClicked(TArgumentType& Arguments, const v8::FunctionCallbackInfo<v8::Value>& Info, const char* VariableName, const char* WidgetClass = "")
	{
	}

	/** ======================= SLATE_FPointerEventHandler_EVENT ======================= **/
#define SET_SLATE_EVENT_PointerEventHandler(Name, Type)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsObject = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsObject](const FGeometry& Geomety, const FPointerEvent& PointerEvent) { return JsObject.Func<Type>(nullptr, Geomety, PointerEvent); });\
		}\
	}
	SET_SLATE_EVENT_PointerEventHandler(OnDoubleClicked, FReply);

	/** ======================= SLATE_EVENT_FOnCheckStateChanged ======================= **/
#define SET_SLATE_EVENT_FOnCheckStateChanged(Name,Type)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsObject = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsObject](ECheckBoxState InNewState) { return JsObject.Action(nullptr, InNewState); });\
		}\
	}
	SET_SLATE_EVENT_FOnCheckStateChanged(OnCheckStateChanged, void);


	/** ======================= SLATE_EVENT_FOnGetContent ======================= **/
#define SET_SLATE_EVENT_FOnGetContent(Name,Type)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsObject = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsObject]() { return JsObject.Func<Type>(nullptr); });\
		}\
	}
	SET_SLATE_EVENT_FOnGetContent(OnGetMenuContent, TSharedRef<SWidget>);
}

namespace WidgetAttribute4
{
	template<typename TType>
	TAttribute<TType> MakeAttribute(v8::Local<v8::Context>& Context, v8::Local<v8::Value> Value, const char* WidgetClass = "") { return TAttribute<TType>(); }

	/** ======================= MakeAttribute ======================= **/
#define MAKE_ATTRIBUTE(Type)\
	template<> TAttribute<Type> MakeAttribute(v8::Local<v8::Context>& Context, v8::Local<v8::Value> Value, const char* WidgetClass)\
	{\
		if (Value->IsFunction())\
		{\
			v8::Local<v8::Function> Function = Value.As<v8::Function>();\
			FJsObject JsObject = FJsObject(Context, Function);\
			TAttribute<Type>::FGetter Getter;\
			Getter.BindLambda([JsObject]() { return JsObject.Func<Type>(nullptr); });\
			return TAttribute<Type>::Create(Getter);\
		}\
		if (puerts::converter::Converter<Type>::accept(Context, Value))\
		{\
			Type Ret = puerts::converter::Converter<Type>::toCpp(Context, Value);\
			return TAttribute<Type>(Ret);\
		}\
		return TAttribute<Type>();\
	}

	MAKE_ATTRIBUTE(FText);
	MAKE_ATTRIBUTE(float);
	MAKE_ATTRIBUTE(bool);
	MAKE_ATTRIBUTE(FSlateFontInfo);
	MAKE_ATTRIBUTE(FSlateBrush*);
	MAKE_ATTRIBUTE(FSlateColor);
	MAKE_ATTRIBUTE(FVector2D);
	MAKE_ATTRIBUTE(FLinearColor);
	MAKE_ATTRIBUTE(ETextWrappingPolicy);
	MAKE_ATTRIBUTE(ETextTransformPolicy);
	MAKE_ATTRIBUTE(FMargin);
	MAKE_ATTRIBUTE(ETextJustify::Type);
	MAKE_ATTRIBUTE(ECheckBoxState);
};
namespace WidgetOptional
{
	template<typename TType>
	TOptional<TType> MakeOptional(FJsObject& JsObject) { return TOptional<TType>(); }

	template<>	TOptional<FSlateSound> MakeOptional(FJsObject& JsObject) { return TOptional<FSlateSound>(); }
}

namespace WidgetDelegate
{
	FSimpleDelegate MakeSimpleDelegate(FJsObject& JsObject)
	{
		return FSimpleDelegate();
	}

	FOnClicked MakeOnClicked(FJsObject& JsObject)
	{
		return FOnClicked();
	}
}
