#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "DTSDefine.h"
#include "TypeInfo.hpp"
#include "UEDataBinding.hpp"
#include "Helper/WidgetHelper.hpp"
#include "DTSHelper.h"
#include "DTSDefine.h"
#include "PuertsEx.h"

UsingCppType(SWebBrowserView);
UsingTSharedPtr(SWebBrowserView);

namespace $SWebBrowserView
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SWebBrowserView::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ARGUMENT(ParentWindow);
		$SLATE_ARGUMENT(InitialURL);
		$SLATE_ARGUMENT(ContentsToLoad);
		$SLATE_ARGUMENT(ShowErrorMessage);
		$SLATE_ARGUMENT(SupportsTransparency);
		$SLATE_ARGUMENT(InterceptLoadRequests);
		$SLATE_ARGUMENT(SupportsThumbMouseButtonNavigation);
		$SLATE_ARGUMENT(BackgroundColor);
		$SLATE_ARGUMENT(BrowserFrameRate);
		$SLATE_ARGUMENT(PopupMenuMethod);
		$SLATE_ARGUMENT(ContextSettings);
		$SLATE_ARGUMENT(AltRetryDomains);
		$SLATE_ATTRIBUTE(ViewportSize);
		$SLATE_EVENT(OnLoadCompleted);
		$SLATE_EVENT(OnLoadError);
		$SLATE_EVENT(OnLoadStarted);
		$SLATE_EVENT(OnTitleChanged);
		$SLATE_EVENT(OnUrlChanged);
		$SLATE_EVENT(OnBeforePopup);
		$SLATE_EVENT(OnCreateWindow);
		$SLATE_EVENT(OnCloseWindow);
		$SLATE_EVENT(OnBeforeNavigation);
		$SLATE_EVENT(OnLoadUrl);
		$SLATE_EVENT(OnShowDialog);
		$SLATE_EVENT(OnDismissAllDialogs);
		$SLATE_EVENT(OnSuppressContextMenu);
		$SLATE_EVENT(OnCreateToolTip);
		$SLATE_EVENT(OnDragWindow);
		$SLATE_EVENT(OnUnhandledKeyDown);
		$SLATE_EVENT(OnUnhandledKeyUp);
		$SLATE_EVENT(OnUnhandledKeyChar);
		$SLATE_EVENT(OnConsoleMessage);
	}

	static void $SNew(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		const uint8 InfoLength = Info.Length();
		if (InfoLength <= 1) { puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!"); return; }

		uint8 ExposeIndex = InfoLength == 3 ? 0 : -1;
		uint8 ArgumentsIndex = InfoLength == 3 ? 1 : 0;
		uint8 FilenameIndex = InfoLength == 3 ? 2 : 1;

		SWebBrowserView::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SWebBrowserView> Widget = MakeTDecl<SWebBrowserView>("SWebBrowserView", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SWebBrowserView>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SWebBrowserView>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SWebBrowserView>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SWebBrowserView>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SWebBrowserView> Widget = MakeShared<SWebBrowserView>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SWebBrowserView>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SWebBrowserView
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SWebBrowserView");
		Args.Add<TSharedPtr<SWindow>>("ParentWindow", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FString>("InitialURL", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<FString>>("ContentsToLoad", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ShowErrorMessage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("SupportsTransparency", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("InterceptLoadRequests", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("SupportsThumbMouseButtonNavigation", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FColor>("BackgroundColor", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<int>("BrowserFrameRate", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<EPopupMethod>>("PopupMenuMethod", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<FBrowserContextSettings>>("ContextSettings", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TArray<FString>>("AltRetryDomains", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FVector2D>("ViewportSize", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSimpleDelegate>("OnLoadCompleted", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnLoadError", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnLoadStarted", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextChanged>("OnTitleChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextChanged>("OnUrlChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnBeforePopupDelegate>("OnBeforePopup", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnCreateWindowDelegate>("OnCreateWindow", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnCloseWindowDelegate>("OnCloseWindow", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnBeforeBrowse>("OnBeforeNavigation", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnLoadUrl>("OnLoadUrl", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnShowDialog>("OnShowDialog", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnDismissAllDialogs", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnSuppressContextMenu>("OnSuppressContextMenu", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnCreateToolTip>("OnCreateToolTip", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnDragWindow>("OnDragWindow", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnUnhandledKeyDown>("OnUnhandledKeyDown", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnUnhandledKeyUp>("OnUnhandledKeyUp", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnUnhandledKeyChar>("OnUnhandledKeyChar", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnConsoleMessageDelegate>("OnConsoleMessage", DTS::EArgType::SLATE_EVENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SWebBrowserView").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SWebBrowserView.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SWebBrowserView>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SWebBrowserView>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SWebBrowserView.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SWebBrowserView>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SWebBrowserView()
	{
		GenDTS();
		RegisterTSharedPtr(SWebBrowserView);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SWebBrowserView::$SNew},
			{"SAssignNew", $SWebBrowserView::$SAssignNew},
			{"MakeShared", $SWebBrowserView::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SWebBrowserView";
		Def.TypeId = puerts::StaticTypeId<SWebBrowserView>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SWebBrowserView _AutoRegister_SWebBrowserView;