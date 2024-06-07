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
#include "Widgets/SWindow.h"

UsingCppType(SWindow);
UsingTSharedPtr(SWindow);

namespace $SWindow
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SWindow::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ARGUMENT(EWindowType, Type, EWindowType);
		$SLATE_STYLE_ARGUMENT(FWindowStyle, Style, FWindowStyle);
		$SLATE_ATTRIBUTE(FText, Title, );
		$SLATE_ARGUMENT(bool, bDragAnywhere, );
		$SLATE_ARGUMENT(EAutoCenter, AutoCenter, );
		$SLATE_ARGUMENT(FVector2D, ScreenPosition, );
		$SLATE_ARGUMENT(FVector2D, ClientSize, );
		$SLATE_ARGUMENT(bool, AdjustInitialSizeAndPositionForDPIScale, );
		$SLATE_ARGUMENT(FWindowTransparency, SupportsTransparency, FWindowTransparency);
		$SLATE_ARGUMENT(float, InitialOpacity, );
		$SLATE_ARGUMENT(bool, IsInitiallyMaximized, );
		$SLATE_ARGUMENT(bool, IsInitiallyMinimized, );
		$SLATE_ARGUMENT(ESizingRule, SizingRule, );
		$SLATE_ARGUMENT(bool, IsPopupWindow, );
		$SLATE_ARGUMENT(bool, IsTopmostWindow, );
		$SLATE_ARGUMENT(bool, FocusWhenFirstShown, );
		$SLATE_ARGUMENT(EWindowActivationPolicy, ActivationPolicy, );
		$SLATE_ARGUMENT(bool, UseOSWindowBorder, );
		$SLATE_ARGUMENT(bool, HasCloseButton, );
		$SLATE_ARGUMENT(bool, SupportsMaximize, );
		$SLATE_ARGUMENT(bool, SupportsMinimize, );
		$SLATE_ARGUMENT(bool, ShouldPreserveAspectRatio, );
		$SLATE_ARGUMENT(TOptional<float>, MinWidth, );
		$SLATE_ARGUMENT(TOptional<float>, MinHeight, );
		$SLATE_ARGUMENT(TOptional<float>, MaxWidth, );
		$SLATE_ARGUMENT(TOptional<float>, MaxHeight, );
		$SLATE_ARGUMENT(bool, CreateTitleBar, );
		$SLATE_ARGUMENT(bool, SaneWindowPlacement, );
		$SLATE_ARGUMENT(FMargin, LayoutBorder, );
		$SLATE_ARGUMENT(FMargin, UserResizeBorder, );
		$SLATE_ARGUMENT(bool, bManualManageDPI, );
		$SLATE_DEFAULT_SLOT(FArguments, Content, );
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

		SWindow::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SWindow> Widget = MakeTDecl<SWindow>("SWindow", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SWindow>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SWindow>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SWindow>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SWindow>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SWindow> Widget = MakeShared<SWindow>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SWindow>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SWindow
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SWindow");
		Args.Add<EWindowType>("Type", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FWindowStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FText>("Title", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("bDragAnywhere", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EAutoCenter>("AutoCenter", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FVector2D>("ScreenPosition", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FVector2D>("ClientSize", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("AdjustInitialSizeAndPositionForDPIScale", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FWindowTransparency>("SupportsTransparency", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<float>("InitialOpacity", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("IsInitiallyMaximized", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("IsInitiallyMinimized", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<ESizingRule>("SizingRule", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("IsPopupWindow", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("IsTopmostWindow", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("FocusWhenFirstShown", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EWindowActivationPolicy>("ActivationPolicy", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("UseOSWindowBorder", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("HasCloseButton", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("SupportsMaximize", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("SupportsMinimize", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ShouldPreserveAspectRatio", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<float>>("MinWidth", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<float>>("MinHeight", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<float>>("MaxWidth", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TOptional<float>>("MaxHeight", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("CreateTitleBar", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("SaneWindowPlacement", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FMargin>("LayoutBorder", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FMargin>("UserResizeBorder", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("bManualManageDPI", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FArguments>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SWindow").Super("FPopupLayer")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SWindow.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SWindow>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SWindow>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SWindow.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SWindow>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SWindow()
	{
		GenDTS();
		RegisterTSharedPtr(SWindow);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SWindow::$SNew},
			{"SAssignNew", $SWindow::$SAssignNew},
			{"MakeShared", $SWindow::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SWindow";
		Def.TypeId = puerts::StaticTypeId<SWindow>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SWindow _AutoRegister_SWindow;