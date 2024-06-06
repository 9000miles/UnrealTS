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

UsingCppType(SGameMenuItemWidget);
UsingTSharedPtr(SGameMenuItemWidget);

namespace $SGameMenuItemWidget
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SGameMenuItemWidget::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT(FGameMenuStyle, MenuStyle, );
		$SLATE_ARGUMENT(TWeakObjectPtr<APlayerController>, PCOwner, );
		//$SLATE_EVENT(FOnClicked, OnClicked, );
		//$SLATE_EVENT(FOnArrowPressed, OnArrowPressed, );
		$SLATE_ATTRIBUTE(FText, Text, );
		$SLATE_ARGUMENT(bool, bIsMultichoice, );
		$SLATE_ATTRIBUTE(FText, OptionText, );
		$SLATE_ARGUMENT(TOptional<float>, InactiveTextAlpha, );
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

		SGameMenuItemWidget::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SGameMenuItemWidget> Widget = MakeTDecl<SGameMenuItemWidget>("SGameMenuItemWidget", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SGameMenuItemWidget>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SGameMenuItemWidget>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SGameMenuItemWidget>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SGameMenuItemWidget>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SGameMenuItemWidget> Widget = MakeShared<SGameMenuItemWidget>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SGameMenuItemWidget>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SGameMenuItemWidget
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SGameMenuItemWidget");
		Args.Add<FGameMenuStyle>("MenuStyle", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<TWeakObjectPtr<APlayerController>>("PCOwner", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnClicked>("OnClicked", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnArrowPressed>("OnArrowPressed", DTS::EArgType::SLATE_EVENT);
		Args.Add<FText>("Text", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("bIsMultichoice", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FText>("OptionText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional<float>>("InactiveTextAlpha", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SGameMenuItemWidget").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SGameMenuItemWidget.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SGameMenuItemWidget>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SGameMenuItemWidget>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SGameMenuItemWidget.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SGameMenuItemWidget>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SGameMenuItemWidget()
	{
		GenDTS();
		RegisterTSharedPtr(SGameMenuItemWidget);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SGameMenuItemWidget::$SNew},
			{"SAssignNew", $SGameMenuItemWidget::$SAssignNew},
			{"MakeShared", $SGameMenuItemWidget::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SGameMenuItemWidget";
		Def.TypeId = puerts::StaticTypeId<SGameMenuItemWidget>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SGameMenuItemWidget _AutoRegister_SGameMenuItemWidget;