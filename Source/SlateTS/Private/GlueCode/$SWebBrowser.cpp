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
#include "WebBrowser/Public/SWebBrowser.h"

UsingCppType(SWebBrowser);
UsingTSharedPtr(SWebBrowser);

namespace $SWebBrowser
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SWebBrowser::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ARGUMENT(TSharedPtr<SWindow>, ParentWindow, );
		$SLATE_ARGUMENT(FString, InitialURL, );
		$SLATE_ARGUMENT(TOptional<FString>, ContentsToLoad, );
		$SLATE_ARGUMENT(bool, ShowControls, );
		$SLATE_ARGUMENT(bool, ShowAddressBar, );
		$SLATE_ARGUMENT(bool, ShowErrorMessage, );
		$SLATE_ARGUMENT(bool, SupportsTransparency, bool);
		$SLATE_ARGUMENT(bool, SupportsThumbMouseButtonNavigation, );
		$SLATE_ARGUMENT(bool, ShowInitialThrobber, );
		$SLATE_ARGUMENT(FColor, BackgroundColor, );
		$SLATE_ARGUMENT(int, BrowserFrameRate, );
		$SLATE_ARGUMENT(TOptional<EPopupMethod>, PopupMenuMethod, );
		$SLATE_ATTRIBUTE(FVector2D, ViewportSize, );
		//$SLATE_EVENT(FSimpleDelegate, OnLoadCompleted, );
		//$SLATE_EVENT(FSimpleDelegate, OnLoadError, );
		//$SLATE_EVENT(FSimpleDelegate, OnLoadStarted, );
		//$SLATE_EVENT(FOnTextChanged, OnTitleChanged, );
		//$SLATE_EVENT(FOnTextChanged, OnUrlChanged, );
		//$SLATE_EVENT(FOnBeforePopupDelegate, OnBeforePopup, );
		//$SLATE_EVENT(FOnCreateWindowDelegate, OnCreateWindow, );
		//$SLATE_EVENT(FOnCloseWindowDelegate, OnCloseWindow, );
		//$SLATE_EVENT(FOnBeforeBrowse, OnBeforeNavigation, );
		//$SLATE_EVENT(FOnLoadUrl, OnLoadUrl, );
		//$SLATE_EVENT(FOnShowDialog, OnShowDialog, );
		//$SLATE_EVENT(FSimpleDelegate, OnDismissAllDialogs, );
		//$SLATE_EVENT(FOnSuppressContextMenu, OnSuppressContextMenu, );
		//$SLATE_EVENT(FOnDragWindow, OnDragWindow, );
		//$SLATE_EVENT(FOnConsoleMessageDelegate, OnConsoleMessage, );
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

		SWebBrowser::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SWebBrowser> Widget = MakeTDecl<SWebBrowser>("SWebBrowser", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SWebBrowser>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SWebBrowser>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SWebBrowser>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SWebBrowser>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SWebBrowser> Widget = MakeShared<SWebBrowser>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SWebBrowser>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SWebBrowser
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SWebBrowser");
		Args.Add<TSharedPtr<SWindow>>("ParentWindow", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FString>("InitialURL", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<FString>>("ContentsToLoad", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ShowControls", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ShowAddressBar", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ShowErrorMessage", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("SupportsTransparency", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("SupportsThumbMouseButtonNavigation", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ShowInitialThrobber", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FColor>("BackgroundColor", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<int>("BrowserFrameRate", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<EPopupMethod>>("PopupMenuMethod", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FVector2D>("ViewportSize", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSimpleDelegate>("OnLoadCompleted", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnLoadError", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnLoadStarted", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextChanged>("OnTitleChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextChanged>("OnUrlChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnBeforePopupDelegate>("OnBeforePopup", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnCreateWindowDelegate>("OnCreateWindow", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnCloseWindowDelegate>("OnCloseWindow", DTS::EArgType::SLATE_EVENT);
		Args.Add<SWebBrowser::FOnBeforeBrowse>("OnBeforeNavigation", DTS::EArgType::SLATE_EVENT);
		Args.Add<SWebBrowser::FOnLoadUrl>("OnLoadUrl", DTS::EArgType::SLATE_EVENT);
		Args.Add<SWebBrowser::FOnShowDialog>("OnShowDialog", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnDismissAllDialogs", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnSuppressContextMenu>("OnSuppressContextMenu", DTS::EArgType::SLATE_EVENT);
		Args.Add<SWebBrowser::FOnDragWindow>("OnDragWindow", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnConsoleMessageDelegate>("OnConsoleMessage", DTS::EArgType::SLATE_EVENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SWebBrowser").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SWebBrowser.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SWebBrowser>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SWebBrowser>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SWebBrowser.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SWebBrowser>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SWebBrowser()
	{
		GenDTS();
		RegisterTSharedPtr(SWebBrowser);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SWebBrowser::$SNew},
			{"SAssignNew", $SWebBrowser::$SAssignNew},
			{"MakeShared", $SWebBrowser::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SWebBrowser";
		Def.TypeId = puerts::StaticTypeId<SWebBrowser>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SWebBrowser _AutoRegister_SWebBrowser;