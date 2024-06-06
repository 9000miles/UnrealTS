#pragma once
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"

#define $SLATE_EVENT(Type, Name, Tag)\
$SLATE_EVENT$::##Type##::Set_##Name(Arguments, Isolate, JsObject, #Name)

namespace $SLATE_EVENT$
{
	namespace FOnCheckStateChanged
	{
#define DEFINE_FUNCTION_SLATE_EVENT(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		if (JsValue->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction](ECheckBoxState V) { JsFunction.Action(nullptr, V); });\
		}\
	}

		DEFINE_FUNCTION_SLATE_EVENT(OnCheckStateChanged);
		DEFINE_FUNCTION_SLATE_EVENT(OnToggleChanged);
		DEFINE_FUNCTION_SLATE_EVENT(OnTogglePitchChanged);
		DEFINE_FUNCTION_SLATE_EVENT(OnToggleRollChanged);
		DEFINE_FUNCTION_SLATE_EVENT(OnToggleYawChanged);
	}
}

namespace $SLATE_EVENT$
{
	namespace FOnGetContent
	{
#define DEFINE_FUNCTION_SLATE_EVENT(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsObject = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsObject]() { return return *JsFunction.Func<RetType*>(nullptr); });\
		}\
	}
		template<typename TArgumentType> void Set_OnGetMenuContent(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName) {
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
		DEFINE_FUNCTION_SLATE_EVENT(OnDropdownOpened, TSharedRef<SWidget>);
		DEFINE_FUNCTION_SLATE_EVENT(OnGetMenuContent, TSharedRef<SWidget>);
	}
}

namespace $SLATE_EVENT$
{
	namespace FPointerEventHandler
	{
#define DEFINE_FUNCTION_SLATE_EVENT(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		if (JsValue->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsValue.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction](const FGeometry& V1, const FPointerEvent& V2) { return *JsFunction.Func<FReply*>(nullptr, V1, V2); });\
		}\
	}
		DEFINE_FUNCTION_SLATE_EVENT(OnDoubleClicked);
		DEFINE_FUNCTION_SLATE_EVENT(OnMouseButtonDown);
		DEFINE_FUNCTION_SLATE_EVENT(OnMouseButtonUp);
		DEFINE_FUNCTION_SLATE_EVENT(OnMouseDoubleClick);
		DEFINE_FUNCTION_SLATE_EVENT(OnMouseMove);
	}
}

namespace $SLATE_EVENT$
{
	namespace FSimpleDelegate
	{
#define DEFINE_FUNCTION_SLATE_EVENT(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
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

		DEFINE_FUNCTION_SLATE_EVENT(OnBegin);
		DEFINE_FUNCTION_SLATE_EVENT(OnBeginMouseCapture);
		DEFINE_FUNCTION_SLATE_EVENT(OnBeginSliderMovement);
		DEFINE_FUNCTION_SLATE_EVENT(OnControllerCaptureBegin);
		DEFINE_FUNCTION_SLATE_EVENT(OnControllerCaptureEnd);
		DEFINE_FUNCTION_SLATE_EVENT(OnDismissAllDialogs);
		DEFINE_FUNCTION_SLATE_EVENT(OnEndMouseCapture);
		DEFINE_FUNCTION_SLATE_EVENT(OnEndSliderMovement);
		DEFINE_FUNCTION_SLATE_EVENT(OnEnter);
		DEFINE_FUNCTION_SLATE_EVENT(OnEnterEditingMode);
		DEFINE_FUNCTION_SLATE_EVENT(OnExitEditingMode);
		DEFINE_FUNCTION_SLATE_EVENT(OnHovered);
		DEFINE_FUNCTION_SLATE_EVENT(OnInteractivePickBegin);
		DEFINE_FUNCTION_SLATE_EVENT(OnInteractivePickEnd);
		DEFINE_FUNCTION_SLATE_EVENT(OnLeave);
		DEFINE_FUNCTION_SLATE_EVENT(OnLoadCompleted);
		DEFINE_FUNCTION_SLATE_EVENT(OnLoadError);
		DEFINE_FUNCTION_SLATE_EVENT(OnLoadStarted);
		DEFINE_FUNCTION_SLATE_EVENT(OnMouseCaptureBegin);
		DEFINE_FUNCTION_SLATE_EVENT(OnMouseCaptureEnd);
		DEFINE_FUNCTION_SLATE_EVENT(OnNavigate);
		DEFINE_FUNCTION_SLATE_EVENT(OnPressed);
		DEFINE_FUNCTION_SLATE_EVENT(OnReleased);
		DEFINE_FUNCTION_SLATE_EVENT(OnSplitterFinishedResizing);
		DEFINE_FUNCTION_SLATE_EVENT(OnTabDraggedOverDockArea);
		DEFINE_FUNCTION_SLATE_EVENT(OnTabDrawerClosed);
		DEFINE_FUNCTION_SLATE_EVENT(OnTabRelocated);
		DEFINE_FUNCTION_SLATE_EVENT(OnUnhovered);
		DEFINE_FUNCTION_SLATE_EVENT(RequestToggleFullscreen);
	}
}

namespace $SLATE_EVENT$
{
	namespace FOnIsOpenChanged
	{
#define DEFINE_FUNCTION_SLATE_EVENT(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction](bool V) { return JsFunction.Action(nullptr, V); });\
		}\
	}
		DEFINE_FUNCTION_SLATE_EVENT(OnMenuOpenChanged);
	}
}

namespace $SLATE_EVENT$
{
	namespace FOnComboBoxOpened
	{
#define DEFINE_FUNCTION_SLATE_EVENT(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction]() { return JsFunction.Action(nullptr); });\
		}\
	}

		DEFINE_FUNCTION_SLATE_EVENT(OnComboBoxOpened);
	}
}
namespace $SLATE_EVENT$
{
	namespace FOnClicked
	{
#define DEFINE_FUNCTION_SLATE_EVENT(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction]() { return *JsFunction.Func<FReply*>(nullptr); });\
		}\
	}

		DEFINE_FUNCTION_SLATE_EVENT(OnAddClicked);
		DEFINE_FUNCTION_SLATE_EVENT(OnClicked);
		DEFINE_FUNCTION_SLATE_EVENT(OnCloseClicked);
		DEFINE_FUNCTION_SLATE_EVENT(OnExpansionClicked);
		DEFINE_FUNCTION_SLATE_EVENT(OnRemoveClicked);
		DEFINE_FUNCTION_SLATE_EVENT(OnSearchGlassClicked);
	}
}
namespace $SLATE_EVENT$
{
	namespace FOnBooleanValueChanged
	{
#define DEFINE_FUNCTION_SLATE_EVENT(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction](bool V) { return JsFunction.Action(nullptr, V); });\
		}\
	}

		DEFINE_FUNCTION_SLATE_EVENT(OnAreaExpansionChanged);
	}
}

namespace $SLATE_EVENT$
{
	namespace FCanCloseTab
	{
#define DEFINE_FUNCTION_SLATE_EVENT(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsFunction = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsFunction]() { return JsFunction.Func<bool>(nullptr); });\
		}\
	}

		DEFINE_FUNCTION_SLATE_EVENT(OnAreaExpansionChanged);
	}
}
