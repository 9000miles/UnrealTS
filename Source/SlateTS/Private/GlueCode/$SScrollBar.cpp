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

UsingCppType(SScrollBar);
UsingTSharedPtr(SScrollBar);

namespace $SScrollBar
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SScrollBar::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT(FScrollBarStyle, Style, FScrollBarStyle);
		$SLATE_EVENT(FOnUserScrolled, OnUserScrolled, );
		$SLATE_ARGUMENT(bool, AlwaysShowScrollbar, );
		$SLATE_ARGUMENT(bool, AlwaysShowScrollbarTrack, );
		$SLATE_ARGUMENT(bool, HideWhenNotInUse, );
		$SLATE_ARGUMENT(bool, PreventThrottling, );
		$SLATE_ARGUMENT(EOrientation, Orientation, );
		$SLATE_ARGUMENT(EFocusCause, DragFocusCause, );
		$SLATE_ATTRIBUTE(FVector2D, Thickness, );
		$SLATE_ATTRIBUTE(FMargin, Padding, );
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

		SScrollBar::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SScrollBar> Widget = MakeTDecl<SScrollBar>("SScrollBar", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SScrollBar>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SScrollBar>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SScrollBar>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SScrollBar>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SScrollBar> Widget = MakeShared<SScrollBar>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SScrollBar>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SScrollBar
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SScrollBar");
		Args.Add<FScrollBarStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FOnUserScrolled>("OnUserScrolled", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("AlwaysShowScrollbar", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("AlwaysShowScrollbarTrack", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("HideWhenNotInUse", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("PreventThrottling", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EOrientation>("Orientation", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<EFocusCause>("DragFocusCause", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FVector2D>("Thickness", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FMargin>("Padding", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SScrollBar").Super("SBorder")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SScrollBar.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SScrollBar>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SScrollBar>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SScrollBar.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SScrollBar>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SScrollBar()
	{
		GenDTS();
		RegisterTSharedPtr(SScrollBar);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SScrollBar::$SNew},
			{"SAssignNew", $SScrollBar::$SAssignNew},
			{"MakeShared", $SScrollBar::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SScrollBar";
		Def.TypeId = puerts::StaticTypeId<SScrollBar>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SBorder>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SScrollBar _AutoRegister_SScrollBar;