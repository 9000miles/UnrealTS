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
#include "AppFramework/Public/Widgets/Colors/SColorPicker.h"

UsingCppType(SColorPicker);
UsingTSharedPtr(SColorPicker);

namespace $SColorPicker
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SColorPicker::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(FLinearColor, TargetColorAttribute, );
		$SLATE_ATTRIBUTE(TArray<FColor*>, TargetFColors, );
		$SLATE_ATTRIBUTE(TArray<FLinearColor*>, TargetLinearColors, );
		//$SLATE_ATTRIBUTE(TArray<FColorChannels>, TargetColorChannels, );//可能会被移除
		$SLATE_ATTRIBUTE(bool, UseAlpha, );
		$SLATE_ATTRIBUTE(bool, OnlyRefreshOnMouseUp, );
		$SLATE_ATTRIBUTE(bool, OnlyRefreshOnOk, );
		//$SLATE_EVENT(FOnLinearColorValueChanged, OnColorCommitted, );
		//$SLATE_EVENT(FOnLinearColorValueChanged, PreColorCommitted, );
		//$SLATE_EVENT(FOnColorPickerCancelled, OnColorPickerCancelled, );
		//$SLATE_EVENT(FOnWindowClosed, OnColorPickerWindowClosed, );
		//$SLATE_EVENT(FSimpleDelegate, OnInteractivePickBegin, );
		//$SLATE_EVENT(FSimpleDelegate, OnInteractivePickEnd, );
		$SLATE_ATTRIBUTE(TSharedPtr<SWindow>, ParentWindow, );
		$SLATE_ATTRIBUTE(float, DisplayGamma, );
		$SLATE_ARGUMENT(TOptional<bool>, sRGBOverride, );
		$SLATE_ARGUMENT(bool, DisplayInlineVersion, );
		$SLATE_ARGUMENT(bool, OverrideColorPickerCreation, );
		$SLATE_ARGUMENT(bool, ExpandAdvancedSection, );
		$SLATE_ATTRIBUTE(TSharedPtr<SWidget>, OptionalOwningDetailsView, );
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

		SColorPicker::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SColorPicker> Widget = MakeTDecl<SColorPicker>("SColorPicker", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SColorPicker>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SColorPicker>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SColorPicker>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SColorPicker>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SColorPicker> Widget = MakeShared<SColorPicker>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SColorPicker>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SColorPicker
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SColorPicker");
		Args.Add<FLinearColor>("TargetColorAttribute", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TArray<FColor*>>("TargetFColors", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TArray<FLinearColor*>>("TargetLinearColors", DTS::EArgType::SLATE_ATTRIBUTE);
		//Args.Add<TArray<FColorChannels>>("TargetColorChannels", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("UseAlpha", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("OnlyRefreshOnMouseUp", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("OnlyRefreshOnOk", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnLinearColorValueChanged>("OnColorCommitted", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnLinearColorValueChanged>("PreColorCommitted", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnColorPickerCancelled>("OnColorPickerCancelled", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnWindowClosed>("OnColorPickerWindowClosed", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnInteractivePickBegin", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnInteractivePickEnd", DTS::EArgType::SLATE_EVENT);
		Args.Add<TSharedPtr<SWindow>>("ParentWindow", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("DisplayGamma", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional<bool>>("sRGBOverride", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("DisplayInlineVersion", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("OverrideColorPickerCreation", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ExpandAdvancedSection", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<TSharedPtr<SWidget>>("OptionalOwningDetailsView", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SColorPicker").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SColorPicker.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SColorPicker>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SColorPicker>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SColorPicker.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SColorPicker>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SColorPicker()
	{
		GenDTS();
		RegisterTSharedPtr(SColorPicker);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SColorPicker::$SNew},
			{"SAssignNew", $SColorPicker::$SAssignNew},
			{"MakeShared", $SColorPicker::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SColorPicker";
		Def.TypeId = puerts::StaticTypeId<SColorPicker>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SColorPicker _AutoRegister_SColorPicker;