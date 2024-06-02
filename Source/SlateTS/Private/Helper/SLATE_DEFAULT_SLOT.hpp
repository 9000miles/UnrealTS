#pragma once
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"

namespace WidgetArgument4
{
	template<typename TArgumentType> void Set_Content(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "") {
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);
		if (!bHas) return;

		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();
		if (!JsValue->IsFunction()) return;

		v8::Local<v8::Function> Function = JsValue.As<v8::Function>();
		FJsObject JsFunction = FJsObject(Context, Function);
		Arguments._Content.Widget = *JsFunction.Func<TSharedRef<SWidget>*>(nullptr);
	};
}
