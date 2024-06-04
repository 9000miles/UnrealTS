#pragma once
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"

#define SET_VARIABLE__SLATE_DEFAULT_SLOT(Name)\
$Arguments__SLATE_DEFAULT_SLOT::Set_##Name(Arguments, Isolate, JsObject, #Name, "")

namespace $Arguments__SLATE_DEFAULT_SLOT
{
#define SET_SLATE_SLOT(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "") {\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		if (!JsValue->IsFunction()) return;\
		v8::Local<v8::Function> Function = JsValue.As<v8::Function>();\
		FJsObject JsFunction = FJsObject(Context, Function);\
		Arguments._##Name.Widget = *JsFunction.Func<TSharedRef<SWidget>*>(nullptr);\
	};

	SET_SLATE_SLOT(Content);
	SET_SLATE_SLOT(ButtonContent);
	SET_SLATE_SLOT(MenuContent);
}


#define SET_VARIABLE__SLATE_NAMED_SLOT(Name)\
$Arguments__SLATE_NAMED_SLOT::Set_##Name(Arguments, Isolate, JsObject, #Name, "")

namespace $Arguments__SLATE_NAMED_SLOT
{
#define SET_SLATE_SLOT(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "") {\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		if (!JsValue->IsFunction()) return;\
		v8::Local<v8::Function> Function = JsValue.As<v8::Function>();\
		FJsObject JsFunction = FJsObject(Context, Function);\
		Arguments._##Name.Widget = *JsFunction.Func<TSharedRef<SWidget>*>(nullptr);\
	};

	SET_SLATE_SLOT(Content);
	SET_SLATE_SLOT(ButtonContent);
	SET_SLATE_SLOT(MenuContent);
	SET_SLATE_SLOT(HeaderContent);
	SET_SLATE_SLOT(BodyContent);
}
