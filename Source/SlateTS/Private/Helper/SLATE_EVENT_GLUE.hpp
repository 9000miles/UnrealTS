#pragma once
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"

#define $SLATE_EVENT(Name)\
$Arguments__SLATE_EVENT::Set_##Name(Arguments, Isolate, JsObject, #Name, "")

namespace $Arguments__SLATE_EVENT
{
#define SET_SLATE_EVENT_FOnCheckStateChanged(Name, RetType)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		if (JsValue->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction](ECheckBoxState InNewState) { JsFunction.Action(nullptr, InNewState); });\
		}\
	}
	SET_SLATE_EVENT_FOnCheckStateChanged(OnCheckStateChanged, void);


}

namespace $Arguments__SLATE_EVENT
{
#define SET_SLATE_EVENT_FOnGetContent(Name, RetType)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsObject = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsObject]() { return JsObject.Func<RetType>(nullptr); });\
		}\
	}
	template<typename TArgumentType> void Set_OnGetMenuContent(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "") {
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);
		if (!bHas) return;

		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();
		if (!JsValue->IsFunction()) return;

		v8::Local<v8::Function> Function = JsValue.As<v8::Function>();
		FJsObject JsFunction = FJsObject(Context, Function);
		Arguments._OnGetMenuContent.BindLambda([JsFunction]()
			{
				return *JsFunction.Func<TSharedRef<SWidget>*>(nullptr);
				//return JsFunction.Func_SWidgetRef(nullptr);
				//v8::Local<v8::Object> Object = JsFunction.GetJsObject();
				//auto MaybeRet = Object.As<v8::Function>()->Call(JsFunction.GetContext(), v8::Undefined(JsFunction.GetIsolate()), 0, nullptr);
				//if (!MaybeRet.IsEmpty())
				//	return *puerts::DataTransfer::GetPointerFast<TSharedRef<SWidget>>(MaybeRet.ToLocalChecked().As<v8::Object>());
				//return SNullWidget::NullWidget;
			});
	};
}

namespace $Arguments__SLATE_EVENT
{
#define SET_SLATE_EVENT_PointerEventHandler(Name, RetType)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		if (JsValue->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsValue.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction](const FGeometry& Geomety, const FPointerEvent& PointerEvent) { return *JsFunction.Func<RetType*>(nullptr, Geomety, PointerEvent); });\
		}\
	}
	SET_SLATE_EVENT_PointerEventHandler(OnDoubleClicked, FReply);
	SET_SLATE_EVENT_PointerEventHandler(OnMouseButtonDown, FReply);
	SET_SLATE_EVENT_PointerEventHandler(OnMouseButtonUp, FReply);
	SET_SLATE_EVENT_PointerEventHandler(OnMouseMove, FReply);
	SET_SLATE_EVENT_PointerEventHandler(OnMouseDoubleClick, FReply);
}

namespace $Arguments__SLATE_EVENT
{
#define SET_SLATE_EVENT_SIMPLE_DELEGATE(Name,Type)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		if (JsValue->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsValue.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction]() { return JsFunction.Action(nullptr); });\
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
}

namespace $Arguments__SLATE_EVENT
{
#define SET_SLATE_EVENT_FOnIsOpenChanged(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction](bool bIsOpenChanged) { return JsFunction.Action(nullptr, bIsOpenChanged); });\
		}\
	}
	SET_SLATE_EVENT_FOnIsOpenChanged(OnMenuOpenChanged);



}

namespace $Arguments__SLATE_EVENT
{
#define SET_SLATE_EVENT_FOnComboBoxOpened(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction]() { return JsFunction.Action(nullptr); });\
		}\
	}

	SET_SLATE_EVENT_FOnComboBoxOpened(OnComboBoxOpened);
}

namespace $Arguments__SLATE_EVENT
{
#define SET_SLATE_EVENT_FOnClicked(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction]() { return *JsFunction.Func<FReply*>(nullptr); });\
		}\
	}

	SET_SLATE_EVENT_FOnClicked(OnClicked);
}

namespace $Arguments__SLATE_EVENT
{
#define SET_SLATE_EVENT_FOnBooleanValueChanged(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName, const char* WidgetClass = "")\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction](bool V) { return JsFunction.Action(nullptr, V); });\
		}\
	}

	SET_SLATE_EVENT_FOnBooleanValueChanged(OnAreaExpansionChanged);
}