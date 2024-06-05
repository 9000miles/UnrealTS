#pragma once
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"

#define $SLATE_STYLE_ARGUMENT(Type, Name, Tag)\
$SLATE_STYLE_ARGUMENT$::Set_##Name##_##Tag(Arguments, Isolate, JsObject, #Name)

/** ======================= SLATE_STYLE_ARGUMENT ======================= **/
namespace $SLATE_STYLE_ARGUMENT$
{
#define SET_SLATE_STYLE_ARGUMENT(Type, Name, Tag)\
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

	SET_SLATE_STYLE_ARGUMENT(FTextBlockStyle, TextStyle, );
	SET_SLATE_STYLE_ARGUMENT(FCheckBoxStyle, Style, FCheckBoxStyle);
	SET_SLATE_STYLE_ARGUMENT(FExpandableAreaStyle, Style, FExpandableAreaStyle);
	SET_SLATE_STYLE_ARGUMENT(FComboButtonStyle, ComboButtonStyle, );
	SET_SLATE_STYLE_ARGUMENT(FButtonStyle, ButtonStyle, );

}