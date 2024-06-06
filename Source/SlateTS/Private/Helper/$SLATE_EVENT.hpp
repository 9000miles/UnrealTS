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
#define DEFINE_FUNCTION_SLATE_EVENT__FOnCheckStateChanged(Name)\
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

		DEFINE_FUNCTION_SLATE_EVENT__FOnCheckStateChanged(OnCheckStateChanged);
		DEFINE_FUNCTION_SLATE_EVENT__FOnCheckStateChanged(OnToggleChanged);
		DEFINE_FUNCTION_SLATE_EVENT__FOnCheckStateChanged(OnTogglePitchChanged);
		DEFINE_FUNCTION_SLATE_EVENT__FOnCheckStateChanged(OnToggleRollChanged);
		DEFINE_FUNCTION_SLATE_EVENT__FOnCheckStateChanged(OnToggleYawChanged);
	}
}

namespace $SLATE_EVENT$
{
	namespace FOnGetContent
	{
#define DEFINE_FUNCTION_SLATE_EVENT__FOnGetContent(Name)\
	template<typename TArgumentType>\
	void Set_##Name(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		if (JsObject->IsFunction())\
		{\
			v8::Local<v8::Function> Function = JsObject.As<v8::Function>();\
			FJsObject JsObject = FJsObject(Context, Function);\
			Arguments._##Name.BindLambda([JsObject]() { return return *JsFunction.Func<TSharedRef<SWidget>*>(nullptr); });\
		}\
	}
		//template<typename TArgumentType> void Set_OnGetMenuContent(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName) {
		//	v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		//	const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);
		//	if (!bHas) return;

		//	v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();
		//	if (!JsValue->IsFunction()) return;

		//	v8::Local<v8::Function> Function = JsValue.As<v8::Function>();
		//	FJsObject JsFunction = FJsObject(Context, Function);
		//	Arguments._OnGetMenuContent.BindLambda([JsFunction]()
		//		{
		//			return *JsFunction.Func<TSharedRef<SWidget>*>(nullptr);
		//			//return JsFunction.Func_SWidgetRef(nullptr);
		//			//v8::Local<v8::Object> Object = JsFunction.GetJsObject();
		//			//auto MaybeRet = Object.As<v8::Function>()->Call(JsFunction.GetContext(), v8::Undefined(JsFunction.GetIsolate()), 0, nullptr);
		//			//if (!MaybeRet.IsEmpty())
		//			//	return *puerts::DataTransfer::GetPointerFast<TSharedRef<SWidget>>(MaybeRet.ToLocalChecked().As<v8::Object>());
		//			//return SNullWidget::NullWidget;
		//		});
		//};
		DEFINE_FUNCTION_SLATE_EVENT__FOnGetContent(OnDropdownOpened);
		DEFINE_FUNCTION_SLATE_EVENT__FOnGetContent(OnGetMenuContent);
	}
}

namespace $SLATE_EVENT$
{
	namespace FPointerEventHandler
	{
#define DEFINE_FUNCTION_SLATE_EVENT__FPointerEventHandler(Name)\
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
		DEFINE_FUNCTION_SLATE_EVENT__FPointerEventHandler(OnDoubleClicked);
		DEFINE_FUNCTION_SLATE_EVENT__FPointerEventHandler(OnMouseButtonDown);
		DEFINE_FUNCTION_SLATE_EVENT__FPointerEventHandler(OnMouseButtonUp);
		DEFINE_FUNCTION_SLATE_EVENT__FPointerEventHandler(OnMouseDoubleClick);
		DEFINE_FUNCTION_SLATE_EVENT__FPointerEventHandler(OnMouseMove);
	}
}

namespace $SLATE_EVENT$
{
	namespace FSimpleDelegate
	{
#define DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(Name)\
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

		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnBegin);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnBeginMouseCapture);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnBeginSliderMovement);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnControllerCaptureBegin);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnControllerCaptureEnd);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnDismissAllDialogs);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnEndMouseCapture);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnEndSliderMovement);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnEnter);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnEnterEditingMode);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnExitEditingMode);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnHovered);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnInteractivePickBegin);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnInteractivePickEnd);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnLeave);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnLoadCompleted);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnLoadError);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnLoadStarted);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnMouseCaptureBegin);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnMouseCaptureEnd);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnNavigate);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnPressed);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnReleased);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnSplitterFinishedResizing);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnTabDraggedOverDockArea);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnTabDrawerClosed);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnTabRelocated);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(OnUnhovered);
		DEFINE_FUNCTION_SLATE_EVENT__FSimpleDelegate(RequestToggleFullscreen);
	}
}

namespace $SLATE_EVENT$
{
	namespace FOnIsOpenChanged
	{
#define DEFINE_FUNCTION_SLATE_EVENT__FOnIsOpenChanged(Name)\
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
		DEFINE_FUNCTION_SLATE_EVENT__FOnIsOpenChanged(OnMenuOpenChanged);
	}
}

namespace $SLATE_EVENT$
{
	namespace FOnComboBoxOpened
	{
#define DEFINE_FUNCTION_SLATE_EVENT__FOnComboBoxOpened(Name)\
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

		DEFINE_FUNCTION_SLATE_EVENT__FOnComboBoxOpened(OnComboBoxOpened);
	}
}
namespace $SLATE_EVENT$
{
	namespace FOnClicked
	{
#define DEFINE_FUNCTION_SLATE_EVENT__FOnClicked(Name)\
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

		DEFINE_FUNCTION_SLATE_EVENT__FOnClicked(OnAddClicked);
		DEFINE_FUNCTION_SLATE_EVENT__FOnClicked(OnClicked);
		DEFINE_FUNCTION_SLATE_EVENT__FOnClicked(OnCloseClicked);
		DEFINE_FUNCTION_SLATE_EVENT__FOnClicked(OnExpansionClicked);
		DEFINE_FUNCTION_SLATE_EVENT__FOnClicked(OnRemoveClicked);
		DEFINE_FUNCTION_SLATE_EVENT__FOnClicked(OnSearchGlassClicked);
	}
}
namespace $SLATE_EVENT$
{
	namespace FOnBooleanValueChanged
	{
#define DEFINE_FUNCTION_SLATE_EVENT__FOnBooleanValueChanged(Name)\
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

		DEFINE_FUNCTION_SLATE_EVENT__FOnBooleanValueChanged(OnAreaExpansionChanged);
	}
}

namespace $SLATE_EVENT$
{
	namespace FCanCloseTab
	{
#define DEFINE_FUNCTION_SLATE_EVENT__FCanCloseTab(Name)\
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

		DEFINE_FUNCTION_SLATE_EVENT__FCanCloseTab(OnAreaExpansionChanged);
	}
}
