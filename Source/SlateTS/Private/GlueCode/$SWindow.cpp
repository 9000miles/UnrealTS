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

UsingCppType(FOverlayPopupLayer);
UsingTSharedPtr(FOverlayPopupLayer);

namespace $FOverlayPopupLayer
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, FOverlayPopupLayer::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ARGUMENT(Type);
		$SLATE_STYLE_ARGUMENT(Style);
		$SLATE_ATTRIBUTE(Title);
		$SLATE_ARGUMENT(bDragAnywhere);
		$SLATE_ARGUMENT(AutoCenter);
		$SLATE_ARGUMENT(ScreenPosition);
		$SLATE_ARGUMENT(ClientSize);
		$SLATE_ARGUMENT(AdjustInitialSizeAndPositionForDPIScale);
		$SLATE_ARGUMENT(SupportsTransparency);
		$SLATE_ARGUMENT(InitialOpacity);
		$SLATE_ARGUMENT(IsInitiallyMaximized);
		$SLATE_ARGUMENT(IsInitiallyMinimized);
		$SLATE_ARGUMENT(SizingRule);
		$SLATE_ARGUMENT(IsPopupWindow);
		$SLATE_ARGUMENT(IsTopmostWindow);
		$SLATE_ARGUMENT(FocusWhenFirstShown);
		$SLATE_ARGUMENT(ActivationPolicy);
		$SLATE_ARGUMENT(UseOSWindowBorder);
		$SLATE_ARGUMENT(HasCloseButton);
		$SLATE_ARGUMENT(SupportsMaximize);
		$SLATE_ARGUMENT(SupportsMinimize);
		$SLATE_ARGUMENT(ShouldPreserveAspectRatio);
		$SLATE_ARGUMENT(MinWidth);
		$SLATE_ARGUMENT(MinHeight);
		$SLATE_ARGUMENT(MaxWidth);
		$SLATE_ARGUMENT(MaxHeight);
		$SLATE_ARGUMENT(CreateTitleBar);
		$SLATE_ARGUMENT(SaneWindowPlacement);
		$SLATE_ARGUMENT(LayoutBorder);
		$SLATE_ARGUMENT(UserResizeBorder);
		$SLATE_ARGUMENT(bManualManageDPI);
		$SLATE_DEFAULT_SLOT(Content);
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

		FOverlayPopupLayer::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<FOverlayPopupLayer> Widget = MakeTDecl<FOverlayPopupLayer>("FOverlayPopupLayer", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<FOverlayPopupLayer>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<FOverlayPopupLayer>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<FOverlayPopupLayer>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<FOverlayPopupLayer>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<FOverlayPopupLayer> Widget = MakeShared<FOverlayPopupLayer>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<FOverlayPopupLayer>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_FOverlayPopupLayer
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("FOverlayPopupLayer");
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
		DTS::Class ClassDTS = DTS::Class().Name("FOverlayPopupLayer").Super("FPopupLayer")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("FOverlayPopupLayer.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<FOverlayPopupLayer>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<FOverlayPopupLayer>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("FOverlayPopupLayer.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<FOverlayPopupLayer>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_FOverlayPopupLayer()
	{
		GenDTS();
		RegisterTSharedPtr(FOverlayPopupLayer);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $FOverlayPopupLayer::$SNew},
			{"SAssignNew", $FOverlayPopupLayer::$SAssignNew},
			{"MakeShared", $FOverlayPopupLayer::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "FOverlayPopupLayer";
		Def.TypeId = puerts::StaticTypeId<FOverlayPopupLayer>::get();
		Def.SuperTypeId = puerts::StaticTypeId<FPopupLayer>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_FOverlayPopupLayer _AutoRegister_FOverlayPopupLayer;