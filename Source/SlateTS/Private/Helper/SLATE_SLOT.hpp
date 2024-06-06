#pragma once
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"

#define $SLATE_DEFAULT_SLOT(Type, Name, Tag)\
$SLATE_DEFAULT_SLOT$::Set_##Name##_##Tag(Arguments, Isolate, JsObject, #Name, "")

namespace $SLATE_DEFAULT_SLOT$
{
#define DEFINE_FUNCTION_SLATE_DEFAULT_SLOT(Type, Name, Tag)\
	template<typename TArgumentType>\
	void Set_##Name##_##Tag(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "") {\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		if (!JsValue->IsFunction()) return;\
		v8::Local<v8::Function> Function = JsValue.As<v8::Function>();\
		FJsObject JsFunction = FJsObject(Context, Function);\
		Arguments._##Name.Widget = *JsFunction.Func<TSharedRef<SWidget>*>(nullptr);\
	};

	DEFINE_FUNCTION_SLATE_DEFAULT_SLOT(FArguments, Content, );
	DEFINE_FUNCTION_SLATE_DEFAULT_SLOT(FArguments, HeaderContent, );
	DEFINE_FUNCTION_SLATE_DEFAULT_SLOT(FArguments, PageContent, );
	//DEFINE_FUNCTION_SLATE_DEFAULT_SLOT(typename STableRow<ItemType>::FArguments, Content, )
}


#define $SLATE_NAMED_SLOT(Type, Name, Tag)\
$SLATE_NAMED_SLOT$::Set_##Name##_##Tag(Arguments, Isolate, JsObject, #Name, "")

namespace $SLATE_NAMED_SLOT$
{
#define DEFINE_FUNCTION_SLATE_NAMED_SLOT(Type, Name, Tag)\
	template<typename TArgumentType>\
	void Set_##Name##_##Tag(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "") {\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		if (!JsValue->IsFunction()) return;\
		v8::Local<v8::Function> Function = JsValue.As<v8::Function>();\
		FJsObject JsFunction = FJsObject(Context, Function);\
		Arguments._##Name.Widget = *JsFunction.Func<TSharedRef<SWidget>*>(nullptr);\
	};

	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, BodyContent, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, BottomSlot, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, ButtonContent, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, CollapsedButtonContent, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, Content, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, ExpandedButtonContent, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, ExpandedChildContent, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, HeaderContent, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, Label, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, MenuContent, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, SearchBoxPostSlot, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, SearchBoxPreSlot, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, TabWellContentLeft, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, TabWellContentRight, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, ThumbSlot, );
	DEFINE_FUNCTION_SLATE_NAMED_SLOT(FArguments, TopSlot, )
}
